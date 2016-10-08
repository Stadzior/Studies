#include <chat.h>
#include <ChatRoomI.h>
#include <string>
#include <utility>
#include <ResponseGenerator.h>
#include <cstdlib>

using namespace std;
using namespace Chat;
using namespace Ice;

class ChatServerI : public ChatServer {
private:
  chatRoomList _rooms;
  ChatFactoryPrx _chatFactory;
  map<string,pair<bool,string> > _registeredUsers;  // username => isLoggedIn,challengePattern
  ChatRoomPrx getRoomByName(string roomName);
  bool userRegistered(string userName);
  bool isUserInRoom(string username,ChatRoomPrx room);

public:
  virtual void registerUser(const string& username, const string& challengePattern, const Current&);
  virtual void login(const UserPrx& user, const Current&);
  virtual void enterRoom(const UserPrx& user, const string& roomName, const Current&);
  virtual void exitRoom(const UserPrx& user, const string& roomName, const Current&);
  virtual void logout(const UserPrx& user, const Current&);
  virtual bool isLoggedIn(const UserPrx& user, const Current&);
  virtual chatRoomList getRooms(const Current&);
  virtual ChatRoomPrx findRoomByName(const string& roomName,const Current&);
  virtual UserPrx findUserByName(const string& username,const Current&);
  virtual void registerChatFactory(const ChatFactoryPrx& chatFactory, const Current&);
};
