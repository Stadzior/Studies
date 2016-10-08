#include <chat.h>
#include <string.h>
#include <ResponseGenerator.h>
using namespace Chat;
using namespace std;
using namespace Ice;

class UserI : public User {
private:
	chatRoomList _rooms;
	string _username;
	string _pattern;

public:
	virtual void sendMessage(const string& message,const ChatRoomPrx& room,const UserPrx& user, const Current&);
  virtual void sendPrivateMessage(const string& message,const UserPrx& user, const Current&);
	virtual void displayMessage(const string& message,const Current&);
	virtual string getName(const Current&);
	virtual void setName(const string& name,const Current&);
	virtual void setPattern(const string& pattern, const Current&);
	virtual void joinRoom(const ChatRoomPrx& room,const Current&);
	virtual void exitRoom(const ChatRoomPrx& room,const Current&);
	virtual chatRoomList getRooms(const Current&);
	virtual ChatRoomPrx findRoomByName(const string& roomName, const Current&);
  virtual string getResponseForChallenge(const string& challenge, const Current&);
};
