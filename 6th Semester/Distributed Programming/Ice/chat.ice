module Chat {

exception UserNotFound {};
exception AuthenticationError {};
exception EmptyUsername {};
exception RoomNotFound {};
exception UserAlreadyRegistered {};
exception FactoryNotRegistered {};
interface ChatRoom;
interface ChatFactory;
interface User;

sequence<ChatRoom*> chatRoomList;
sequence<User*> userList;

interface User {
	void sendMessage(string message, ChatRoom* room, User* who);
  void sendPrivateMessage(string message, User* who);
	void displayMessage(string message);
	string getName();
	void setName(string name);
	void setPattern(string pattern);
	void joinRoom(ChatRoom* room);
	void exitRoom(ChatRoom* room);
	chatRoomList getRooms();
	ChatRoom* findRoomByName(string roomName) throws RoomNotFound;
  string getResponseForChallenge(string challenge);
};

interface ChatServer {
  void registerUser(string username, string challengePattern) throws EmptyUsername,UserAlreadyRegistered;
  void login(User* u) throws UserNotFound, AuthenticationError, EmptyUsername;
  void enterRoom(User* u, string room) throws FactoryNotRegistered;
	void exitRoom(User* u, string room);
  void logout(User* u);
  bool isLoggedIn(User* u);
  chatRoomList getRooms();
	ChatRoom* findRoomByName(string roomName) throws RoomNotFound;
	User* findUserByName(string username) throws UserNotFound;
  void registerChatFactory(ChatFactory* cf);
};


interface ChatRoom {
	void sendMessageToAll(User* who, string message);
  string getName();
	void setName(string name);
  void enterRoom(User* u);
	void exitRoom(User* u);
  userList getUsers();
	User* findUserByName(string username) throws UserNotFound;
};

interface ChatFactory {
  ChatRoom* getNewChatRoom(string roomName);
};

};
