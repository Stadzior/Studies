#include <Ice/Ice.h>
#include "chat.h"
#include <string.h>
#include <math.h>
#include <UserI.h>

using namespace std;
using namespace Chat;
using namespace Ice;

string inputTextLine(){
	char inputMessage[100];
	cin.getline(inputMessage,sizeof(inputMessage));
	cin.getline(inputMessage,sizeof(inputMessage));
	string message(inputMessage);
	return message;
}

int showChoice(string viewName)
{
	string stringCheck;
	int check;
	bool valid;
	do
	{
		if(viewName == "initial")
		{
			cout<<"Choose action:"<<endl;
			cout<<"1.Login"<<endl;
			cout<<"2.Register"<<endl;
			cout<<"3.Input creditendials"<<endl;
			cin>>check;
			valid = check == 1 || check == 2 || check == 3;
		}
		else{
			if(viewName == "menu")
			{
				cout << "Select operation:" << endl;
				cout << "1. Show rooms list" << endl;
				cout << "2. Enter/Add room" << endl;
				cout << "3. Exit room" << endl;
				cout << "4. Send message" << endl;
				cout << "5. Send private message" << endl;
				cout << "6. Logout" << endl;
				cin>>check;
				valid = check == 1 || check == 2 || check == 3 || check == 4 || check == 5 || check == 6;
			}
		}
		if(!valid) cout<<"Choose from displayed options only!"<<endl;

	} while(!valid);

	return check;
}

string gatherUsername(){
	string username;
	cout<<"Username:"<<endl;
	cin>>username;
	return username;
}

string gatherPattern(){
	bool valid = false;
	string pattern;
	do{
		cout<<"Challenge pattern:"<<endl;
		cin>>pattern;
		valid = pattern.length() == 2 && (pattern[0] == '+' || pattern[0] == '-') && floor(pattern[1]) == pattern[1];
		if(!valid) cout<<"Challenge pattern must match the following mask:\n [+ or -][0-9] i.e. +5 , -4 etc."<<endl;
	}while(!valid);

	return pattern;
}

class MyUser : virtual public Application {
private:
	ChatServerPrx chatServerPrx;
	UserPrx userPrx;
public:
	virtual int run(int, char*[]);
};

int MyUser::run(int argc, char* argv[]) {

	CommunicatorPtr ic = communicator();
	ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("UserAdapter", "default");
	adapter->activate();

	ObjectPrx base = ic->stringToProxy("Server:default -p 10000");
	chatServerPrx = ChatServerPrx::checkedCast(base);
	if (!chatServerPrx)
		throw "Invalid server proxy";

	ObjectPtr object = new UserI;
	userPrx = UserPrx::uncheckedCast(adapter->add(object, ic->stringToIdentity("User")));

	int choice;
	string username;
	string pattern;
  do{
		try{
			if(!chatServerPrx->isLoggedIn(userPrx)){
				choice = showChoice("initial");

				switch(choice){
					case 1:
					{
						chatServerPrx->login(userPrx);
						cout<<"Login succeed, your response was valid."<<endl;
						break;
					}
					case 2:
					{
						chatServerPrx->registerUser(username,pattern);
						cout<<"You have been registered, now you can log in."<<endl;
						break;
					}
					case 3:
					{
						username = gatherUsername();
						userPrx->setName(username);

						pattern = gatherPattern();
						userPrx->setPattern(pattern);
						break;
					}
				}
			}
			else{
				choice = showChoice("menu");
				switch (choice){
					case 1:
					{
						chatRoomList allRooms = chatServerPrx->getRooms();
						chatRoomList joinedRooms = userPrx->getRooms();
						cout<<"Available rooms:"<<endl;
						for(int i = 0 ; i<allRooms.size();i++){
							cout<<allRooms[i]->getName()<<endl;
						}
						cout<<"Currently joined rooms: "<<endl;
						for(int i = 0 ; i<joinedRooms.size();i++){
							cout<<joinedRooms[i]->getName()<<endl;
						}
						break;
					}
					case 2:
					{
						cout<<"Type in room name: "<<endl;
						string roomName;
						cin>>roomName;
						chatServerPrx->enterRoom(userPrx,roomName);
						break;
					}
					case 3:
					{
						cout<<"Type in room name: "<<endl;
						string roomName;
						cin>>roomName;
						chatServerPrx->exitRoom(userPrx,roomName);
						break;
					}
					case 4:
					{
						cout<<"Type in room name:";
						string roomName;
						cin>>roomName;
						cout<<"Type in message:";

						string message = inputTextLine();
						userPrx->sendMessage(message,userPrx->findRoomByName(roomName),userPrx);
						break;
					}
					case 5:
					{
						cout<<"Type in username:";
						string username;
						cin>>username;
						cout<<"Type in message:";

						string message = inputTextLine();

						UserPrx addressee = chatServerPrx->findUserByName(username);
						userPrx->sendPrivateMessage(message,addressee);
						break;
					}
					case 6:
					{
						chatServerPrx->logout(userPrx);
						break;
					}
				}
			}
		}
		catch(FactoryNotRegistered e){
			cout<<"There is no factory on the server which could provide room creation, contact the administrator."<<endl;
		}
		catch(UserAlreadyRegistered e){
			cout<<"User with the same name is already registered."<<endl;
		}
		catch(UserNotFound e){
			cout<<"User does not exists or is unaccessible."<<endl;
		}
		catch(RoomNotFound e){
			cout<<"You don't entered that room or it does not exists."<<endl;
		}
		catch(AuthenticationError e){
			cout<<"Login failed, your response is invalid."<<endl;
		}
		catch(EmptyUsername e){
			cout<<"You forgot to type in your creditentials."<<endl;
		}
	} while(1);

	ic->waitForShutdown();
	return 0;
}

int main(int argc, char* argv[]) {
    MyUser app;
    return app.main(argc, argv);
}
