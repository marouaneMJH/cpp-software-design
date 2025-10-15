#include "./../include/index.h"

#include <iostream>
#include <fstream>
#include <algorithm>

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

    void sortDic()
    {
        sort(_dic.end(), _dic.begin());
    }
    void sortReversDic()
    {
        sort(_dic.begin(), _dic.end(), [](string a, string b)
             { return a > b; });
    }
};

int main()
{
    // Dic dic = Dic();

    // dic.readFromFile("assets/test.txt");

    // dic.sortReversDic();
    // dic.readFromSTDIn();
    HList my[20];

    return 0;
}
