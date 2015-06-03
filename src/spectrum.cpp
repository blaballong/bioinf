#include "spectrum.h"

using namespace std;

string Spectrum::getNthElement(int n)
{
  if(!list.empty())
    return list[n];
  else
    return NULL;
}

bool Spectrum::contains(string oligonucleotide)
{
  if(!list.empty() && find(list.begin(), list.end(), oligonucleotide) != list.end())
    return true;
  else
    return false;
}

void Spectrum::setSpectrum(vector<string> list)
{
  this->list.insert(this->list.end(), list.begin(), list.end());
}

int Spectrum::getSize()
{
  return this->list.size();
}
