#include "helper.h"

using namespace std;

vector<string> readFromFile(string filepath)
{
  vector<string> oligonucleotides;
  string line;
  
  ifstream inputFile(filepath.c_str());
  if (inputFile.is_open())
  {
    while(getline(inputFile, line))
    {
      oligonucleotides.push_back(line);
    }
    inputFile.close();
  }
  else cout << "File not found." << endl;
  
  return oligonucleotides;
}

bool startsWith(string text, string prefix)
{
  if(text.length() >= prefix.length() && text.compare(0, prefix.length(), prefix) == 0)
    return true;
  else
    return false;
}

bool endsWith(string text, string suffix)
{
  if(text.length() >= suffix.length() && text.compare(text.length() - suffix.length(), suffix.length(), suffix) == 0)
    return true;
  else
    return false;
}

int countDegreeOfCoverage(string text1, string text2)
{
  unsigned degree = 0;
  
  if(text1.length() != text2.length())
    return -1;
  else
  {
    for(unsigned i = 0; i < text1.length(); i++)
    {
      degree = 0;
      
      if(text1.compare(i, text1.length() - i, text2, 0, text1.length() - i) == 0)
	return text1.length() - i;
    }
  }
  
  return degree;
}