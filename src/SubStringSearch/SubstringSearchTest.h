//
// Created by temTeng on 2021/7/18.
//

#ifndef DATASTRUCTUREANDALGORITHMINCPP_SUBSTRINGSEARCHTEST_H
#define DATASTRUCTUREANDALGORITHMINCPP_SUBSTRINGSEARCHTEST_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class SubstringSearchTest {
public:
    enum SubstringSearchAlgorithms {
        BruteForce,
        KnuthMorrisPratt,
        KnuthMorrisPrattNaive,
    };

    static void SubstringSearchTest::test(const string &text, const string &pattern);

    static void
    showSubstrings(vector<int> substringPositions, const string &text, const string &pattern, const string &message);

    static vector<int>
    getSubstringPositionsFromBFAlgorithm(SubstringSearchAlgorithms algorithm, const string &text,
                                         const string &pattern);

    static void main();
};


#endif //DATASTRUCTUREANDALGORITHMINCPP_SUBSTRINGSEARCHTEST_H
