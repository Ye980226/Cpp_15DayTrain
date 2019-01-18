#include <iostream>
using namespace std;
template <typename... T>
int sum(T... v)
{
    //right folder
    // return (v + ... + 0); //pack fold expression is a C++17 extension
    //left folder
    return (0 + ... + v);
}
template <typename... T>
void print(T &&... args)
{
    (cout << ... << args) << '\n';
}
int main()
{
    int x = sum(1, 2, 3, 4, 5);
    int y = sum('a', 2.4, x);
    cout << x << "nihao" << y;
    // system("pause");
    return 0;
}