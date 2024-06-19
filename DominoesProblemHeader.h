#include <fstream>
#include <list>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

#ifndef DOMINOES_PROBLEM_HEADER_H
#define DOMINOES_PROBLEM_HEADER_H

//Displays the Data
void averageCaseFullRun(std::string starterFile,std::string unsortedFile);
void worstCaseFullRun(std::string starterFile,std::string unsortedFile);
void convolutedFullRun(std::string starterFile,std::string unsortedFile);
//Does not display data, Used for timing without displaying
void averageCaseNoDisplayRun(std::string starterFile,std::string unsortedFile);
void worstCaseNoDisplayRun(std::string starterFile,std::string unsortedFile);
void convolutedNoDisplayRun(std::string starterFile,std::string unsortedFile);

bool isComplete(int , const std::list<std::string>& );
void displayDominoesLine(const std::list<std::string>& );

class AverageCaseDominoes
{
public:
    AverageCaseDominoes(const std::string&, const std::string&);
    std::string addLeftDominoAverageCase();
    std::string addRightDominoAverageCase();
    int getSize() const;
    std::list<std::string> getDominoesLine();
private:
    std::unordered_map<std::string,std::list<std::string>> unsortedKeyDominoUnorderedMap;
    std::unordered_set<std::string> usedDominoesUnorderedSet;
    std::pair<std::string,std::string> leftMostDomino;
    std::pair<std::string,std::string> rightMostDomino;
    std::list<std::string> dominoesLine;
    int amountOfElements = 0;
};

class WorstCaseDominoes
{
public:
    WorstCaseDominoes(const std::string&,const std::string&);
    std::string addLeftDominoWorstCase();
    std::string addRightDominoWorstCase();
    std::list<std::string> getDominoesLine();
    int getSize() const;
private:
    std::map<std::string,std::list<std::string>> unsortedKeyDominoMap;
    std::set<std::string> usedDominoesSet;
    std::pair<std::string,std::string> leftMostDomino;
    std::pair<std::string,std::string> rightMostDomino;
    std::list<std::string> dominoesLine;
    int amountOfElements = 0;
};

class ConvolutedDominoes
{
public:
    ConvolutedDominoes(const std::string&,const std::string&);
    std::list<std::string> getDominoesLine();
private:
    std::pair<std::string,std::string> startingDomino;
    std::list<std::pair<std::string,std::string>> ListA;
    std::list<std::pair<std::string,int>> ListP;
    std::list<std::string> dominoesLine;
    int amountOfElements;
};

#endif