#include <UserI.h>

void UserI::sendMessage(const string& message,const ChatRoomPrx& room,const UserPrx& user, const Current&)
{
	room->sendMessageToAll(user,message);
}

void UserI::sendPrivateMessage(const string& message,const UserPrx& user, const Current&)
{
	string formattedMessage = "Private message from ";
	formattedMessage.append(_username);
	formattedMessage.append(": ");
	formattedMessage.append(message);
	user->displayMessage(formattedMessage);
}

ChatRoomPrx UserI::findRoomByName(const string& roomName, const Current&){
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

void UserI::displayMessage(const string& message, const Current&)
{
    cout<<message<<endl;
}

chatRoomList UserI::getRooms(const Current&)
{
	return _rooms;
}

string UserI::getName(const Current&)
{
	return _username;
}

void UserI::setName(const string& name,const Current&)
{
	_username = name;
}

void UserI::setPattern(const string& pattern,const Current&)
{
	_pattern = pattern;
}

void UserI::joinRoom(const ChatRoomPrx& room,const Current&)
{
  _rooms.push_back(room);
}

void UserI::exitRoom(const ChatRoomPrx& room,const Current&)
{
	for(unsigned int i = 0; i < _rooms.size(); i++){

		if(_rooms[i]->getName() == room->getName()) {
			_rooms.erase(_rooms.begin()+i);
			break;
		}
	}
}

string UserI::getResponseForChallenge(const string& challenge, const Current&)
{
	ResponseGenerator* generator = new ResponseGenerator();
	string response = generator->generateValidResponse(challenge,_pattern);
	delete generator;
  return response;
}
