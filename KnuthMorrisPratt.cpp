//
// Created by temTeng on 2021/7/18.
//

#include "KnuthMorrisPratt.h"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::for_each;

vector<int> KnuthMorrisPratt::knuthMorrisPratt(const string &text, const string &pattern) {
    vector<int> substringPositions = vector<int>();

    int textIndex = 0;
    int patternIndex = 0;

    vector<int> nextTable = getNextTable(pattern);
    while (textIndex < text.length()) {
        if (text[textIndex] == pattern[patternIndex]) {
            textIndex++;
            patternIndex++;
            if (patternIndex == pattern.length()) {//找到字串
                //记录位置
                substringPositions.push_back(textIndex - patternIndex);
                //开始下一步搜索
                patternIndex = nextTable[pattern.length()];//next数组最后一个不可能是-1
            }
        } else {
            //不相等则回溯
            patternIndex = nextTable[patternIndex];
            if (patternIndex < 0) {//如果失配位置next数组为-1
                textIndex++;
                patternIndex++;
            }
        }
    }

    //返回记录下来的各个子串的位置
    return substringPositions;


}

vector<int> KnuthMorrisPratt::getNextTableNaive(const string &pattern) {
    vector<int> nextTable = vector<int>(pattern.length());

    //init
    nextTable[0] = 0;
    nextTable[1] = 0;

    int patternIndex = 1;
    int candidateIndex = 0;

    while (patternIndex < pattern.length() - 1) {
        if (pattern[patternIndex] == pattern[candidateIndex]) {

            patternIndex++;
            candidateIndex++;
            nextTable[patternIndex] = candidateIndex;
        } else {
            candidateIndex = nextTable[candidateIndex];
            if (candidateIndex == 0) {
                patternIndex++;
            }
        }
    }
    return nextTable;
}

void KnuthMorrisPratt::showNextTableNaive(const string &pattern) {
    vector<int> nextTable = getNextTableNaive(pattern);

    for (char i : pattern) {
        printf("%c\t", i);
    }
    printf("\n");
    for (int backtrackInteger : nextTable) {
        printf("%d\t", backtrackInteger);
    }
    printf("\n");
}

vector<int> KnuthMorrisPratt::knuthMorrisPrattNaive(const string &text, const string &pattern) {
    vector<int> substringPositions = vector<int>();


    int textIndex = 0;
    int patternIndex = 0;
    vector<int> nextTable = getNextTableNaive(pattern);
    while (textIndex < text.length()) {
        if (text[textIndex] == pattern[patternIndex]) {
            textIndex++;
            patternIndex++;
            if (patternIndex == pattern.length()) {//找到字串
                //记录位置
                substringPositions.push_back(textIndex - patternIndex);
                //开始下一步搜索
                textIndex = textIndex - patternIndex + 1;
                patternIndex = 0;
            }
        } else {
            //不相等则回溯
            patternIndex = nextTable[patternIndex];
            if (0 == patternIndex) {
                textIndex++;
            }
        }
    }
    return substringPositions;
}

vector<int> KnuthMorrisPratt::getNextTable(const string &pattern) {
    vector<int> nextTable = vector<int>(pattern.length() + 1);

    //init
    nextTable[0] = -1;

    int currentPositionIndex = 1;
    int candidateIndex = 0;

    while (currentPositionIndex < pattern.length()) {
        if (pattern[currentPositionIndex] == pattern[candidateIndex]) {
            nextTable[currentPositionIndex] = nextTable[candidateIndex];
        } else {
            nextTable[currentPositionIndex] = candidateIndex;
            while (candidateIndex >= 0
                   && pattern[currentPositionIndex] != pattern[candidateIndex]) {
                //循环，直到 pattern[currentPositionIndex] == pattern[candidateIndex]), 此时找到最长公共前后缀
                candidateIndex = nextTable[candidateIndex];
            }
        }
        currentPositionIndex++;
        candidateIndex++;
    }
    //最后一个数字
    nextTable[currentPositionIndex] = candidateIndex;
    return nextTable;
}

void KnuthMorrisPratt::showNextTable(const string &pattern, const string &message) {
    cout << endl << message << endl;

    vector<int> nextTable = getNextTable(pattern);

    for (char i : pattern) {
        printf("%c\t", i);
    }
    printf("\n");
    for (int backtrackInteger : nextTable) {
        printf("%d\t", backtrackInteger);
    }
    printf("\n");
}
