#ifndef _HELPER
#define _HELPER

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFromFile(std::string filepath);
bool startsWith(std::string text, std::string prefix);
bool endsWith(std::string text, std::string suffix);
int countDegreeOfCoverage(std::string text1, std::string text2);

#endif