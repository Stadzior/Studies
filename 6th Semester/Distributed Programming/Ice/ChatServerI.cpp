#include <ChatServerI.h>

void ChatServerI::registerUser(const string& username, const string& challengePattern, const Current&)
{
  if(!username.empty()){
    if(!userRegistered(username)){
  		_registeredUsers.insert(pair<string,pair<bool,string> >(username,make_pair(false,challengePattern)));
  		cout<<username<<" successfully registered."<<endl;
  	}
  	else{
  		cout<<username<<" has already been registered."<<endl;
      throw UserAlreadyRegistered();
  	}
  }
  else{
    throw EmptyUsername();
  }

}

bool ChatServerI::userRegistered(string username){
	return _registeredUsers.find(username) != _registeredUsers.end();
}

void ChatServerI::login(const UserPrx& user, const Current&)
{
	string username = user->getName();
  if(!username.empty() && userRegistered(username)){
    srand(time(0));
    string challenge = "00000";
    for(int i = 0;i<challenge.length();i++){
      challenge[i] = rand()%256;
    }
    //cout<<"Challenge: "<<challenge<<endl;
    string userPattern = _registeredUsers[username].second;

    ResponseGenerator* generator = new ResponseGenerator();
    string validResponse = generator->generateValidResponse(challenge,userPattern);
    string userResponse = user->getResponseForChallenge(challenge);
    bool authenticationSucceed = userResponse.compare(validResponse)==0;
    delete generator;

    // cout<<"Valid response: "<<validResponse<<endl;
    // cout<<"User response: "<<userResponse<<endl;

  	if(authenticationSucceed){
  		_registeredUsers[username].first = true;	//loggedIn = true
  		cout<<username<<" has logged in."<<endl;
  	}
  	else{
  		cout<<username<<" failed to login."<<endl;
      throw AuthenticationError();
  	}
  }
  else{
    if(username.empty()){
      throw EmptyUsername();
    }
    else{
      throw UserNotFound();
    }
  }

}

void ChatServerI::logout(const UserPrx& user, const Current&)
{
	chatRoomList enteredRooms = user->getRooms();
	chatRoomList::iterator room;
  for(room = enteredRooms.begin(); room != enteredRooms.end(); ++room) {
	(*room)->exitRoom(user);
	user->exitRoom(*room);
  }
	_registeredUsers[user->getName()].first = false;  //loggedIn = false
	cout<<user->getName()<<" has logged out."<<endl;
}

bool ChatServerI::isLoggedIn(const UserPrx& user, const Current&)
{
  string username = user->getName();
  bool userIsRegistered = false;
  try{
    userIsRegistered = userRegistered(username);
  } catch(EmptyUsername e){
    userIsRegistered = false;
  }
  if(!username.empty() && userIsRegistered){ //user has a name and is registered
    bool isLoggedIn = _registeredUsers[username].first;
    string pattern = _registeredUsers[username].second;
    return isLoggedIn;
  }
  else{
    return false;
  }

}

void ChatServerI::enterRoom(const UserPrx& user, const string& roomName, const Current&)
{
  string username = user->getName();
	cout<<username<<" want to enter room: "<<roomName<<endl;
  bool roomFound = true;
  ChatRoomPrx room;
  try{
	   room = getRoomByName(roomName);
  } catch (RoomNotFound e)
  {
    roomFound = false;
  }
	if(!roomFound){
      try{
      room = _chatFactory->getNewChatRoom(roomName);
      }
      catch(IceUtil::NullHandleException e){
        throw FactoryNotRegistered();
      }
      user->displayMessage("Room not found, new one created.");
  		_rooms.push_back(room);
	    cout<<username<<" created room "<<roomName<<endl;
	}
  if(isUserInRoom(username,room)){
    cout<<username<<" is already in room "<<roomName<<endl;
  }
  else{
  	room->enterRoom(user);
    user->joinRoom(room);
    cout<<username<<" entered room "<<roomName<<endl;
  }
}

void ChatServerI::exitRoom(const UserPrx& user, const string& roomName, const Current&)
{
  string username = user->getName();
	cout<<username<<" want to exit room: "<<roomName<<endl;
  bool roomFound = true;
  ChatRoomPrx room;
  try{
	   room = getRoomByName(roomName);
  } catch (RoomNotFound e)
  {
    roomFound = false;
  }
	if(!roomFound){
      user->displayMessage("Room not found. Can't exit from room that not exists.");
	}
  else{
    if(isUserInRoom(username,room)){
      room->exitRoom(user);
      user->exitRoom(room);
      cout<<username<<" exited from room "<<roomName<<endl;
    }
    else{
      cout<<username<<" is not in room "<<roomName<<endl;
    }
  }
}

bool ChatServerI::isUserInRoom(string username,ChatRoomPrx room){
  bool userFound = false;
  userList users = room->getUsers();
	for(int i = 0 ; i<users.size();i++){
		if(users[i]->getName() == username){
      userFound = true;
			break;
		}
	}
  return userFound;
}

ChatRoomPrx ChatServerI::getRoomByName(string roomName){
  ChatRoomPrx room;
  bool roomFound = false;
	for(int i = 0 ; i<_rooms.size();i++){
		if(_rooms[i]->getName() == roomName){
			room = _rooms[i];
      roomFound = true;
			break;
		}
	}
  if(!roomFound)
    throw RoomNotFound();

	return room;
}

ChatRoomPrx ChatServerI::findRoomByName(const string& roomName, const Current&){
	return getRoomByName(roomName);
}

UserPrx ChatServerI::findUserByName(const string& username, const Current&){
  UserPrx user;
  bool userFound = false;
	for(int i = 0;i<_rooms.size();i++){
    try{
      user = _rooms[i]->findUserByName(username);
      userFound = true;
      break;
    }
    catch(UserNotFound e){}
  }
  if(!userFound)
    throw UserNotFound();

  return user;
}

chatRoomList ChatServerI::getRooms(const Current&)
{
	return _rooms;
}

void ChatServerI::registerChatFactory(const ChatFactoryPrx& chatFactory, const Current&)
{
	_chatFactory = chatFactory;
	cout<<"ChatFactory registered."<<endl;
}
