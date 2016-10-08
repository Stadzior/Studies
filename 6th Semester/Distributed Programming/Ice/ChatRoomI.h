#include <chat.h>
#include <string.h>

using namespace std;
using namespace Chat;
using namespace Ice;

class ChatRoomI : public ChatRoom {
private:
	userList _users;
	string _roomName;

public:
	virtual void sendMessageToAll(const UserPrx& user, const string& message, const Current&);
	virtual string getName(const Current&);
	virtual void setName(const string& name,const Current&);
	virtual void enterRoom(const UserPrx& user, const Current&);
	virtual void exitRoom(const UserPrx& user, const Current&);
	virtual userList getUsers(const Current&);
	virtual UserPrx findUserByName(const string& username, const Current&);
};
