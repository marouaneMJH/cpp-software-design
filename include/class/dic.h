#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;


class Dic
{

private:
    vector<string> _dic;

    void _print(ostream &os)
    {
        for (vector<string>::iterator it = _dic.begin(); it != _dic.end(); ++it)
        {
            os << *it << " ";
        }
    }

public:
    // Load vector data from stdin
    void readFromSTDIn()
    {
        string userInput;

        while (true)
        {
            cin >> userInput;

            if (userInput == "\\exit")
                break;
            _dic.push_back(userInput);
        }
    }

    friend ostream &operator<<(ostream &os, Dic &dic)
    {
        dic._print(os);
        return os;
    }

    // Load vector data from file
    // make sure the path should be the from the make runing position
    void readFromFile(string inFilePath)
    {

        ifstream inFile(inFilePath);

        if (!inFile.is_open())
        {
            cout << "Error with opening \"" << inFilePath << "\"" << endl;
            return;
        }
        std::string word;
        while (inFile >> word)
            _dic.push_back(word);
        inFile.close();
    }

    // Sort by default order
    void sortDic()
    {
        sort(_dic.end(), _dic.begin());
    }

    // Search to find exact word
    vector<string>::iterator findDic(const string &word)
    {
        return find(_dic.begin(), _dic.end(), word);
    }

    // Sort by reversed order
    void sortReversDic()
    {
        sort(_dic.begin(), _dic.end(), [](string a, string b)
             { return a > b; });
    }
};
