#include "./../include/index.h"


int main()
{
    Dic dic = Dic();

    dic.readFromFile("assets/test.txt");

    dic.sortReversDic();

    cout << *dic.findDic("\\exit");

    return 0;
}
