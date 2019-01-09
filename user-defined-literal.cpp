#include <ccomplex>
#include <iostream>
using namespace std;
constexpr complex<double> operator""i(long double arg)
{
    return {0, arg};
}
int main()
{
    complex<double> a = 1.i;
    complex<double> z = 2.7182818 + 6.283185i;

    cout << z;
}