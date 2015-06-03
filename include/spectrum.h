#ifndef _SPECTRUM
#define _SPECTRUM

#include<algorithm>
#include <string>
#include <vector>

class Spectrum 
{
  protected:
    std::vector<std::string> list;
  public:
    std::string getNthElement(int n);
    bool contains(std::string oligonucleotide);
    void setSpectrum(std::vector<std::string> list);
    int getSize();
};

#endif