#pragma once

#include "./stack/stack-dynamic.h"

#include <string>
#include <vector>

// todo: find better solution to save symbols instead  of global variables
const vector<char> openSymbols = {'{', '(', '['};
const vector<char> closeSymbols = {'}',
                                   ')',
                                   ']'};

using namespace std;

class MathExpress
{
private:
    // Check if symbolChar is open symbol
    static bool _isOpenSymbol(char symbolChar)
    {

        // Check if the symbol is exist inside open symbols
        for (char symbol : openSymbols)

            if (symbol == symbolChar)
                return true;

        return false;
    }

    // Check if symbolChar is close symbol
    static bool _isCloseSymbol(char symbolChar)
    {

        // Check if the symbol is exist inside close symbols
        for (char symbol : closeSymbols)
            if (symbol == symbolChar)
                return true;

        return false;
    }

    // Check if symbolChar is open or close symbol
    static bool _isSymbol(char symbolChar)
    {
        return _isCloseSymbol(symbolChar) || _isOpenSymbol(symbolChar);
    }

public:
    // Validate math expression syntax
    static bool isValidMathExpression(string strExpression);
};

bool MathExpress::isValidMathExpression(string strExpression)
{
    // const vector<char> openSymbols = {'{', '(', '['};
    // const vector<char> closeSymbols = {'}', ')', ']'};

    // A stack for symbols
    StackDynamic symbolStack = StackDynamic<char>();

    // for each character of the expression make sure to proccess it
    for (char currentChar : strExpression)
    {

        // Continue if the character is nor symbol (close or open symbol)
        if (!_isSymbol(currentChar))
            continue;

        // If the stack empty add any symbols
        // Check the symbols is a open symbols add it, cuz we need close symbol to cancel the open symbol.
        if (symbolStack.empty() || _isOpenSymbol(currentChar))
        {
            symbolStack.push(currentChar);
            continue;
        }

        //  From now on, all the symbols are closed ones.

        // No need to continues processing if the head is close it means the expression is unvalid.
        // Check the head of the stack if it close, the head should be always open symbol.
        if (_isCloseSymbol(symbolStack.getHead()))
            return false;

        // Cancel the open symbol
        symbolStack.pop();
    }

    return symbolStack.empty();
}