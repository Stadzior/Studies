#include <ResponseGenerator.h>

char ResponseGenerator::generateResponseChar(char sign,char challengeChar,int factor){

  int responseChar;
  if(sign == '+'){
    responseChar = challengeChar + factor;
  }
  else{
    if(sign == '-'){
      responseChar = challengeChar - factor;
    }
  }

  responseChar = correctChar(responseChar);

return (char)responseChar;

}

int ResponseGenerator::correctChar(int charAsInt){
  if(charAsInt<0){
    charAsInt = 255 + charAsInt;
  }
  else{
    if(charAsInt>255){
      charAsInt = charAsInt - 255;
    }
  }
  return charAsInt;
}

string ResponseGenerator::generateValidResponse(string challenge,string userPattern){

  string response = challenge;

  for(int i = 0;i<challenge.length();i++){
    response[i] = generateResponseChar(userPattern[0],challenge[i],userPattern[1] - '0');
  }

  return response;
}
