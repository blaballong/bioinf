#include "algorithm.h"

using namespace std;

Spectrum spectrum;
DNA solution;
int **matrix;

void init(string filepath)
{
  spectrum.setSpectrum(readFromFile(filepath));
}

void run()
{
  //TODO nazwa pliku ma być podawana jako parametr wywołania programu
  init("data/9.200-40");
  generateMatrix();
  assignWeights();
}

bool hasSuccessors(int node)
{
  for(int i = 0; i < spectrum.getSize(); i++)
    if(matrix[node][i] != 0)
      return true;
    
  return false;
}

int getBestSuccessor(int nodeId)
{
  return 0;
}

void generateInitialSolution()
{
  int currentNode = getStartingNode();
  solution.addOligonucleotideAtTheEnd(spectrum.getNthElement(currentNode));
  
  while(hasSuccessors(currentNode))
  {
    currentNode = getBestSuccessor(currentNode);
    solution.addOligonucleotideAtTheEnd(spectrum.getNthElement(currentNode));
  }
}

int getStartingNode()
{
  //looking for a node without predecessors
  vector<int> nodes;
  int numberOfPredecessors;
  
  for(int i = 0; i < spectrum.getSize(); i++)
  {
    numberOfPredecessors = 0;
    for(int j = 0; j < spectrum.getSize() && numberOfPredecessors == 0; j++)
      if(matrix[j][i] != 0)
	numberOfPredecessors++;
      
    nodes.push_back(numberOfPredecessors); //element index in vector equals to element index in spectrum
  }
  
  vector<int>::iterator minValue = min_element(begin(nodes), end(nodes));
  int minElementsCount = 0;
  for (vector<int>::iterator it = nodes.begin(); it != nodes.end(); it++)
    if(*it == *minValue)
      minElementsCount++;
    
  int elementNumber = rand() % (int)(minElementsCount + 1);
  
  int counter = 0;
  for (vector<int>::iterator it = nodes.begin(); it != nodes.end(); it++)
    if(*it == *minValue)
    {
      counter++;
      if(counter == elementNumber)
	return distance(begin(nodes), it);
    }
  
  return -1;
}

int evaluateNode(int row, int column)
{
  int degreeOfCoverage = matrix[row][column];
  
  int numberOfSuccessors = 0;
  for(int i = 0; i < spectrum.getSize(); i++)
    if(matrix[row][i] != 0)
      numberOfSuccessors++;
    
  bool usedInSolution = solution.contains(spectrum.getNthElement(row));
  
  //TODO ustalić wagi poszczególnych składowych oceny węzła
  return 0;
}

void generateMatrix()
{
  int n = spectrum.getSize();
  
  matrix = new int*[n];

  for(int i = 0; i < n; i++)
    matrix[i] = new int[n];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      matrix[i][j] = 0;
}

void assignWeights()
{
  int n = spectrum.getSize();
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(i != j)
	matrix[i][j] = countDegreeOfCoverage(spectrum.getNthElement(i), spectrum.getNthElement(j));
}