#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class ResponseGenerator {
public:
  string generateValidResponse(string challenge,string pattern);
  char generateResponseChar(char sign,char challengeChar,int factor);
  int correctChar(int charAsInt);
};
