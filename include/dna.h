#ifndef _DNA
#define _DNA

#include<algorithm>
#include <deque>
#include <string>

class DNA 
{
  protected:
    std::deque<std::string> dna;
  public:
    //bool startsWith(std::string prefix);
    //bool endsWith(std::string suffix);
    bool contains(std::string oligonucleotide);
    void addOligonucleotideAtTheBeginning(std::string oligonucleotide);
    void addOligonucleotideAtTheEnd(std::string oligonucleotide);
};

#endif