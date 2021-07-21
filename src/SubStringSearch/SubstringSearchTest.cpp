//
// Created by temTeng on 2021/7/18.
//

#include "SubstringSearchTest.h"

#include <iostream>
#include <algorithm>

#include "BruteForceSubstringSearch.h"
#include "KnuthMorrisPratt.h"

using std::cout;
using std::endl;
using std::for_each;

void SubstringSearchTest::showSubstrings(vector<int> substringPositions, const string &text, const string &pattern,
                                         const string &message) {

    cout << endl << message << endl;
    cout << "text:\n" << text << endl;
    cout << "match:" << endl;

    for_each(substringPositions.begin(), substringPositions.end(),
             [text, pattern](int substringPosition) -> void {
                 for (int i = 0; i < text.length(); ++i) {
                     if (substringPosition <= i && i < substringPosition + pattern.length()) {
                         printf("_");
                     } else {
                         printf("%c", text[i]);
                     }
                 }
                 cout << endl;
             });
}

vector<int>
SubstringSearchTest::getSubstringPositionsFromBFAlgorithm(SubstringSearchTest::SubstringSearchAlgorithms algorithm,
                                                          const string &text, const string &pattern) {
    switch (algorithm) {
        case SubstringSearchAlgorithms::BruteForce:
            return BruteForceSubstringSearch::bruteForce(text, pattern);

        case SubstringSearchAlgorithms::KnuthMorrisPratt:
            return KnuthMorrisPratt::knuthMorrisPratt(text, pattern);

        case SubstringSearchAlgorithms::KnuthMorrisPrattNaive:
            return KnuthMorrisPratt::knuthMorrisPrattNaive(text, pattern);

        default:
            return vector<int>();
    }
}

void SubstringSearchTest::test(const string &text, const string &pattern) {

}

void SubstringSearchTest::main() {
    string text = "Hello World! Hi every one. My name is Richard. What is your name?";
    string pattern = "name";

    //BruteForce
    vector<int> substringPositions = getSubstringPositionsFromBFAlgorithm(
            SubstringSearchAlgorithms::BruteForce,
            text,
            pattern);
    showSubstrings(substringPositions, text, pattern, "Brute Force Algorithm Result:");

    //Naive KMP
    substringPositions = getSubstringPositionsFromBFAlgorithm(
            SubstringSearchAlgorithms::KnuthMorrisPrattNaive,
            text,
            pattern);
    showSubstrings(substringPositions, text, pattern, "Naive-Knuth-Morris-Pratt Algorithm Result:");

    //Mature KMP
    substringPositions = getSubstringPositionsFromBFAlgorithm(
            SubstringSearchAlgorithms::KnuthMorrisPratt,
            text,
            pattern);
    showSubstrings(substringPositions, text, pattern, "Mature Knuth-Morris-Pratt Algorithm Result:");

    pattern = "ABCDABDXXXX";
    KnuthMorrisPratt::showNextTableNaive(pattern);

    pattern = "PARTICIPATE IN PARACHUTE";
    KnuthMorrisPratt::showNextTableNaive(pattern);

    KnuthMorrisPratt::showNextTable(pattern, "mature next table:");

    pattern = "ABACABABA";
    KnuthMorrisPratt::showNextTable(pattern, "mature next table:");
}
