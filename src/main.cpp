#include "./../include/index.h"

int main()
{
    vector<string> expressions = {"2+3", "[2+x]{}", "19*{[(x-y)*2]/[2 + [5 + 6 * (y)]*10-17*(8*y-10)]}"};
    // vector<string> expressions = {"()"};

    for (string expression : expressions)
    {
        cout
            << expression << " : " << (MathExpress::isValidMathExpression(expression) ? "valid" : "unvalid") << endl;
    }
    return 0;
}
