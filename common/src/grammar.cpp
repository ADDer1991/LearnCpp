#include <iostream>
#include "grammar.h"

using namespace std;

grammar::grammar(): y(1) //const成员可以在初始化形参列表中初始化，不能在构造函数内部初始化
{
}

grammar::~grammar()
{
}

void grammar::test()
{
    cout << "x = " << x << ", y = " << y << endl;
    return;
}