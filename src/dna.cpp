#include "dna.h"

using namespace std;

/*bool DNA::startsWith(string prefix)
{
  if(!dna.empty() && dna.front().length() >= prefix.length()) 
    return (dna.front().compare(0, prefix.length(), prefix) == 0);
  else
    return false;
}

bool DNA::endsWith(string suffix)
{
  if(!dna.empty() && dna.back().length() >= suffix.length()) 
    return (dna.back().compare(dna.back().length() - suffix.length(), suffix.length(), suffix) == 0);
  else
    return false;
}*/

bool DNA::contains(string oligonucleotide)
{
  if(!dna.empty() && find(dna.begin(), dna.end(), oligonucleotide) != dna.end())
    return true;
  else
    return false;
}

void DNA::addOligonucleotideAtTheBeginning(string oligonucleotide)
{
  dna.push_front(oligonucleotide);
}

void DNA::addOligonucleotideAtTheEnd(string oligonucleotide)
{
  dna.push_back(oligonucleotide);
}