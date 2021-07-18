//
// Created by temTeng on 2021/7/18.
//

#include "BruteForceSubstringSearch.h"

vector<int> BruteForceSubstringSearch::bruteForce(const string &text, const string &pattern) {
    vector<int> substringPositions = vector<int>();

    int textIndex = 0;
    int patternIndex = 0;
    while (textIndex < text.length()) {
        if (text[textIndex] == pattern[patternIndex]) {
            textIndex++;
            patternIndex++;
            if(patternIndex==pattern.length()){//找到字串
                //记录位置
                substringPositions.push_back(textIndex-patternIndex);
                //开始下一步搜索
                textIndex = textIndex - patternIndex + 1;
                patternIndex = 0;
            }
        } else {
            //不相等则回溯
            textIndex = textIndex - patternIndex + 1;
            patternIndex = 0;
        }
    }
    return substringPositions;
}
