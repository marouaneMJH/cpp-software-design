#include "./../include/index.h"

int main()
{
//    StackLinked<int> stack = StackLinked<int>();
    StackVec<int> stackVec = StackVec<int>();
    //  StackDynamic<int> stackDynamic = StackDynamic<int>();

    for (int i = 0; i < STACK_INSERT_ELE_COUNT; i++)
    {
// stack.push(rand() % MAX_RAND_ELE);
        stackVec.push(rand() % MAX_RAND_ELE);

//         stackDynamic.push(rand() % MAX_RAND_ELE);
    }

    // try
    // {
    // }
    // catch (error_t errors)
    // {
    //     cout << "";
    // }

    return 0;
}
