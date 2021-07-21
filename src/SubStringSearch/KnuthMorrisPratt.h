//
// Created by temTeng on 2021/7/18.
//

#ifndef DATASTRUCTUREANDALGORITHMINCPP_KNUTHMORRISPRATT_H
#define DATASTRUCTUREANDALGORITHMINCPP_KNUTHMORRISPRATT_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class KnuthMorrisPratt {
public:

    static vector<int> knuthMorrisPratt(const string &text, const string &pattern);
    static vector<int> knuthMorrisPrattNaive(const string &text, const string &pattern);

    static vector<int> getNextTableNaive(const string &pattern);
    static vector<int> getNextTable(const string &pattern);

    static void showNextTableNaive(const string &pattern);

    static void showNextTable(const string &pattern, const string &message);
};


#endif //DATASTRUCTUREANDALGORITHMINCPP_KNUTHMORRISPRATT_H
