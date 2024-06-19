#include "DominoesProblemHeader.h"

AverageCaseDominoes::AverageCaseDominoes(const std::string& startDominoFilePath, const std::string& dominoesFilePath){

    std::string domino;
    std::string firstDomino;
    std::string secondDomino;
    std::ifstream startingDominoFile {startDominoFilePath};
    std::getline(startingDominoFile,domino, ':');
    firstDomino = domino;
    std::getline(startingDominoFile,domino, ':');
    secondDomino = domino;
    secondDomino.erase(std::remove(secondDomino.begin(), secondDomino.end(), '\n'), secondDomino.end());
    leftMostDomino = {firstDomino,secondDomino};
    rightMostDomino = {firstDomino,secondDomino};
    dominoesLine.push_back(firstDomino + ':' + secondDomino);
    usedDominoesUnorderedSet.emplace(rightMostDomino.first + ':' + rightMostDomino.second);
    usedDominoesUnorderedSet.emplace(rightMostDomino.second + ':' + rightMostDomino.first);
    std::ifstream unsortedDominoesFile {dominoesFilePath};

    while (std::getline(unsortedDominoesFile,domino, ':'))
    {
        amountOfElements += 1;
        firstDomino = domino;
        std::getline(unsortedDominoesFile,domino, '\n');
        secondDomino = domino;
        unsortedKeyDominoUnorderedMap[firstDomino].push_back(secondDomino);
        unsortedKeyDominoUnorderedMap[secondDomino].push_back(firstDomino);
        std::swap(firstDomino,secondDomino);
        unsortedKeyDominoUnorderedMap[firstDomino].push_back(secondDomino);
        unsortedKeyDominoUnorderedMap[secondDomino].push_back(firstDomino);
    }}

std::string AverageCaseDominoes::addRightDominoAverageCase(){

    auto domino = unsortedKeyDominoUnorderedMap.find(rightMostDomino.second);
    auto dominoIndex = domino->second.front();
    if (usedDominoesUnorderedSet.find((domino->first + ':' + dominoIndex)) != usedDominoesUnorderedSet.end()
        || usedDominoesUnorderedSet.find((dominoIndex + ':' + domino->first)) != usedDominoesUnorderedSet.end())
    {
        dominoIndex = domino->second.back();
        rightMostDomino = {rightMostDomino.second, dominoIndex};
        dominoesLine.push_back((rightMostDomino.first + ':' + rightMostDomino.second));
        usedDominoesUnorderedSet.emplace(rightMostDomino.first + ':' + rightMostDomino.second);
        usedDominoesUnorderedSet.emplace(rightMostDomino.second + ':' + rightMostDomino.first);
    }
    else
    {
        rightMostDomino = {rightMostDomino.second, dominoIndex};
        dominoesLine.push_back((rightMostDomino.first + ':' + rightMostDomino.second));
        usedDominoesUnorderedSet.emplace(rightMostDomino.first + ':' + rightMostDomino.second);
        usedDominoesUnorderedSet.emplace(rightMostDomino.second + ':' + rightMostDomino.first);
    }
    return (rightMostDomino.first + ':' + rightMostDomino.second);
}

std::string AverageCaseDominoes::addLeftDominoAverageCase(){

    auto domino = unsortedKeyDominoUnorderedMap.find(leftMostDomino.first);
    auto dominoIndex = domino->second.front();
    if (usedDominoesUnorderedSet.find((domino->first + ':' + dominoIndex)) != usedDominoesUnorderedSet.end()
        || usedDominoesUnorderedSet.find((dominoIndex + ':' + domino->first)) != usedDominoesUnorderedSet.end())
    {
        dominoIndex = domino->second.back();
        leftMostDomino = {dominoIndex, leftMostDomino.first};
        dominoesLine.push_front( leftMostDomino.first + ':' + leftMostDomino.second);
        usedDominoesUnorderedSet.emplace(leftMostDomino.second + ':' + leftMostDomino.first);
        usedDominoesUnorderedSet.emplace(leftMostDomino.first + ':' + leftMostDomino.second);
    }
    else
    {
        leftMostDomino = {dominoIndex, leftMostDomino.first};
        dominoesLine.push_front((leftMostDomino.first + ':' + leftMostDomino.second));
        usedDominoesUnorderedSet.emplace(leftMostDomino.second + ':' + leftMostDomino.first);
        usedDominoesUnorderedSet.emplace(leftMostDomino.first + ':' + leftMostDomino.second);
    }

    return (leftMostDomino.first + ':' + leftMostDomino.second);
}

int AverageCaseDominoes::getSize() const {
    return amountOfElements;
}

std::list<std::string> AverageCaseDominoes::getDominoesLine() {
    return dominoesLine;
}

WorstCaseDominoes::WorstCaseDominoes(const std::string& startDominoFilePath, const std::string& dominoesFilePath){

    std::string domino;
    std::string firstDomino;
    std::string secondDomino;
    std::ifstream startingDominoFile {startDominoFilePath};
    std::getline(startingDominoFile,domino, ':');
    firstDomino = domino;
    std::getline(startingDominoFile,domino, ':');
    secondDomino = domino;
    secondDomino.erase(std::remove(secondDomino.begin(), secondDomino.end(), '\n'), secondDomino.end());
    leftMostDomino = {firstDomino,secondDomino};
    rightMostDomino = {firstDomino,secondDomino};
    dominoesLine.push_back(firstDomino + ':' + secondDomino);
    usedDominoesSet.emplace(rightMostDomino.first + ':' + rightMostDomino.second);
    usedDominoesSet.emplace(rightMostDomino.second + ':' + rightMostDomino.first);
    std::ifstream unsortedDominoesFile {dominoesFilePath};

    while (std::getline(unsortedDominoesFile,domino, ':'))
    {
        amountOfElements += 1;
        firstDomino = domino;
        std::getline(unsortedDominoesFile,domino, '\n');
        secondDomino = domino;
        unsortedKeyDominoMap[firstDomino].push_back(secondDomino);
        unsortedKeyDominoMap[secondDomino].push_back(firstDomino);
        std::swap(firstDomino,secondDomino);
        unsortedKeyDominoMap[firstDomino].push_back(secondDomino);
        unsortedKeyDominoMap[secondDomino].push_back(firstDomino);
    }}

std::string WorstCaseDominoes::addRightDominoWorstCase(){

    auto domino = unsortedKeyDominoMap.find(rightMostDomino.second);
    auto dominoIndex = domino->second.front();
    if (usedDominoesSet.find((domino->first + ':' + dominoIndex)) != usedDominoesSet.end()
        || usedDominoesSet.find((dominoIndex + ':' + domino->first)) != usedDominoesSet.end())
    {
        dominoIndex = domino->second.back();
        rightMostDomino = {rightMostDomino.second, dominoIndex};
        dominoesLine.push_back((rightMostDomino.first + ':' + rightMostDomino.second));
        usedDominoesSet.emplace(rightMostDomino.first + ':' + rightMostDomino.second);
        usedDominoesSet.emplace(rightMostDomino.second + ':' + rightMostDomino.first);
    }
    else
    {
        rightMostDomino = {rightMostDomino.second, dominoIndex};
        dominoesLine.push_back((rightMostDomino.first + ':' + rightMostDomino.second));
        usedDominoesSet.emplace(rightMostDomino.first + ':' + rightMostDomino.second);
        usedDominoesSet.emplace(rightMostDomino.second + ':' + rightMostDomino.first);
    }
    return (rightMostDomino.first + ':' + rightMostDomino.second);
}

std::string WorstCaseDominoes::addLeftDominoWorstCase(){

    auto domino = unsortedKeyDominoMap.find(leftMostDomino.first);
    auto dominoIndex = domino->second.front();
    if (usedDominoesSet.find((domino->first + ':' + dominoIndex)) != usedDominoesSet.end()
        || usedDominoesSet.find((dominoIndex + ':' + domino->first)) != usedDominoesSet.end())
    {
        dominoIndex = domino->second.back();
        leftMostDomino = {dominoIndex, leftMostDomino.first};
        dominoesLine.push_front( leftMostDomino.first + ':' + leftMostDomino.second);
        usedDominoesSet.emplace(leftMostDomino.second + ':' + leftMostDomino.first);
        usedDominoesSet.emplace(leftMostDomino.first+ ':' + leftMostDomino.second);
    }
    else
    {
        leftMostDomino = {dominoIndex, leftMostDomino.first};
        dominoesLine.push_front((leftMostDomino.first + ':' + leftMostDomino.second));
        usedDominoesSet.emplace(leftMostDomino.second + ':' + leftMostDomino.first);
        usedDominoesSet.emplace(leftMostDomino.first+ ':' + leftMostDomino.second);
    }

    return (leftMostDomino.first + ':' + leftMostDomino.second);
}

int WorstCaseDominoes::getSize() const {
    return amountOfElements;
}

std::list<std::string> WorstCaseDominoes::getDominoesLine() {
    return dominoesLine;
}

ConvolutedDominoes::ConvolutedDominoes(const std::string& startDominoFilePath, const std::string& dominoesFilePath)
{
    std::string domino;
    std::string firstDomino;
    std::string secondDomino;
    std::ifstream startingDominoFile {startDominoFilePath};
    std::getline(startingDominoFile,domino, ':');
    firstDomino = domino;
    std::getline(startingDominoFile,domino, ':');
    secondDomino = domino;
    secondDomino.erase(std::remove(secondDomino.begin(), secondDomino.end(), '\n'), secondDomino.end());
    startingDomino = {firstDomino,secondDomino};
    ListP.emplace_back(startingDomino.second,0);
    std::ifstream unsortedDominoesFile {dominoesFilePath};
    amountOfElements = 0;

    while (std::getline(unsortedDominoesFile,domino, ':'))
    {
        amountOfElements += 1;
        firstDomino = domino;
        std::getline(unsortedDominoesFile,domino, '\n');
        secondDomino = domino;
        ListA.emplace_back(firstDomino,secondDomino);

    }


    for (int distance = 1; distance < amountOfElements; distance *= 2) {

        std::list<std::pair<std::string,std::string>> ListB(ListA);
        std::list<std::pair<std::string,std::string>> ListC;

        ListA.sort([](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        ListB.sort([](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        ListP.sort([](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        auto itB = ListB.begin();
        auto itA = ListA.begin();
        auto itP = ListP.begin();

        while (itB != ListB.end()) {

            if (itA != ListA.end() && itB->first == itA->second) {
                ListC.emplace_back(itA->first, itB->second);
                ++itA;
                ++itB;
            }
            else if (itP != ListP.end() && itB->first == itP->first) {
                ListP.emplace_front(itB->second, itP->second + distance);
                ++itB;
                ++itP;
            }
            else if (itA != ListA.end() && itB->first > itA->second) {
                ++itA;
            }
            else if (itP != ListP.end() && itB->first > itP->first) {
                ++itP;
            }
        }
        ListA = ListC;
    }

    ListP.sort([](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::string previousP;
    for(const auto& p : ListP){
        if (dominoesLine.empty()){
            dominoesLine.push_back(startingDomino.first + ':' + p.first);
        }
        else{
        dominoesLine.push_back(previousP + ':' + p.first);
        }
        previousP = p.first;
    }

}

std::list<std::string> ConvolutedDominoes::getDominoesLine() {
    return dominoesLine;
}

bool isComplete(int fileSize, const std::list<std::string>& dominoes){
    if ((fileSize) == dominoes.size()-1) return true;
    return false;
}

void displayDominoesLine(const std::list<std::string>& dominoes){
    for (const auto& i : dominoes)
    {
        std::cout << i << " ";
    }
}

void averageCaseFullRun(std::string starterFile,std::string unsortedFile){
    AverageCaseDominoes AverageCaseDomino(starterFile,unsortedFile);
    while (!isComplete(AverageCaseDomino.getSize(), AverageCaseDomino.getDominoesLine())) {
        if (!isComplete(AverageCaseDomino.getSize(), AverageCaseDomino.getDominoesLine())) {
            std::string nextLeftDomino = AverageCaseDomino.addLeftDominoAverageCase();
        }
        if (!isComplete(AverageCaseDomino.getSize(), AverageCaseDomino.getDominoesLine())) {
            std::string nextRightDomino = AverageCaseDomino.addRightDominoAverageCase();
        }
    }
    displayDominoesLine(AverageCaseDomino.getDominoesLine()); // Comment line to remove displaying
}

void worstCaseFullRun(std::string starterFile,std::string unsortedFile){
    WorstCaseDominoes WorstCaseDomino(starterFile, unsortedFile);
    while (!isComplete(WorstCaseDomino.getSize(), WorstCaseDomino.getDominoesLine())) {
        if (!isComplete(WorstCaseDomino.getSize(), WorstCaseDomino.getDominoesLine())) {
            std::string nextLeftDomino = WorstCaseDomino.addLeftDominoWorstCase();
        }
        if (!isComplete(WorstCaseDomino.getSize(), WorstCaseDomino.getDominoesLine())) {
            std::string nextRightDomino = WorstCaseDomino.addRightDominoWorstCase();
        }
    }
    displayDominoesLine(WorstCaseDomino.getDominoesLine());
}

void convolutedFullRun(std::string starterFile,std::string unsortedFile){
    ConvolutedDominoes ConvolutedDominoes(starterFile, unsortedFile);
    displayDominoesLine(ConvolutedDominoes.getDominoesLine());
}

void averageCaseNoDisplayRun(std::string starterFile,std::string unsortedFile) {
    AverageCaseDominoes AverageCaseDomino(starterFile, unsortedFile);
    while (!isComplete(AverageCaseDomino.getSize(), AverageCaseDomino.getDominoesLine())) {
        if (!isComplete(AverageCaseDomino.getSize(), AverageCaseDomino.getDominoesLine())) {
            std::string nextLeftDomino = AverageCaseDomino.addLeftDominoAverageCase();
        }
        if (!isComplete(AverageCaseDomino.getSize(), AverageCaseDomino.getDominoesLine())) {
            std::string nextRightDomino = AverageCaseDomino.addRightDominoAverageCase();
        }
    }
}

void worstCaseNoDisplayRun(std::string starterFile, std::string unsortedFile) {
    WorstCaseDominoes WorstCaseDomino(starterFile, unsortedFile);
    while (!isComplete(WorstCaseDomino.getSize(), WorstCaseDomino.getDominoesLine())) {
        if (!isComplete(WorstCaseDomino.getSize(), WorstCaseDomino.getDominoesLine())) {
            std::string nextLeftDomino = WorstCaseDomino.addLeftDominoWorstCase();
        }
        if (!isComplete(WorstCaseDomino.getSize(), WorstCaseDomino.getDominoesLine())) {
            std::string nextRightDomino = WorstCaseDomino.addRightDominoWorstCase();
        }
    }
}

void convolutedNoDisplayRun(std::string starterFile, std::string unsortedFile) {
    ConvolutedDominoes ConvolutedDominoes(starterFile, unsortedFile);
}

