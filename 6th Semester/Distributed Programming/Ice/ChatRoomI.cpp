#include <ChatRoomI.h>

void ChatRoomI::sendMessageToAll(const UserPrx& user, const string& message, const Current&)
{
  string formattedMessage = "Message from ";
	formattedMessage.append(user->getName());
  formattedMessage.append(" in room ");
  formattedMessage.append(_roomName);
	formattedMessage.append(": ");
	formattedMessage.append(message);

	userList::iterator addressee;
  for(addressee = _users.begin(); addressee != _users.end(); ++addressee) {
	if((*addressee)->getName().compare(user->getName())!=0){
		(*addressee)->displayMessage(formattedMessage);
	}
  }

	user->displayMessage(formattedMessage);
}
string ChatRoomI::getName(const Current&)
{
	return _roomName;
}

void ChatRoomI::setName(const string& name,const Current&)
{
	_roomName = name;
}

void ChatRoomI::enterRoom(const UserPrx& user, const Current&)
{
  _users.push_back(user);
	cout<<user->getName()<<" has joined room "<<_roomName<<endl;
}

void ChatRoomI::exitRoom(const UserPrx& user, const Current&)
{
  for(unsigned int i = 0; i < _users.size(); i++ ) {
    if(_users[i]->getName().compare(user->getName()) == 0) {
      _users.erase(_users.begin()+i);
      break;
    }
  }
	cout<<user->getName()<<" has left room "<<_roomName<<endl;
}

userList ChatRoomI::getUsers(const Current&)
{
	return _users;
}

UserPrx ChatRoomI::findUserByName(const string& username,const Current&)
{
  UserPrx user;
  bool userFound = false;
  for(int i = 0 ; i<_users.size();i++){
    if(_users[i]->getName() == username){
      user = _users[i];
      userFound = true;
      break;
    }
  }
  if(!userFound)
    throw UserNotFound();

	return user;
}
