#include <Ice/Ice.h>
#include <chat.h>
#include <ChatServerI.h>

using namespace std;
using namespace Ice;

class Server : virtual public Application {
private:
	ChatServerPrx chatServerPrx;

public:
	virtual int run(int, char*[]);
};

int Server::run(int, char*[]) {

  CommunicatorPtr ic = communicator();
	ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("ServerAdapter", "default -p 10000");
	adapter->activate();

  ObjectPtr object = new ChatServerI;
  chatServerPrx = ChatServerPrx::uncheckedCast(adapter->add(object, ic->stringToIdentity("Server")));
	ic->waitForShutdown();

  return 0;
}


int main(int argc, char* argv[]) {
    Server app;
    return app.main(argc, argv);
}
