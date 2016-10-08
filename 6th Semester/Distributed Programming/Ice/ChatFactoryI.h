#include <chat.h>
#include <Ice/Ice.h>
#include <ChatRoomI.h>

using namespace Chat;
using namespace Ice;
using namespace std;

class ChatFactoryI : public ChatFactory {
public:
  virtual ChatRoomPrx getNewChatRoom(const string& roomName, const Current&);
};
