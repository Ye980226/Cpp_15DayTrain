#include <iostream>
#include <string>
using namespace std;
template <typename T, int N>
struct Buffer
{
    using value_type = T;
    constexpr int size()
    {
        return N;
    }
    T data[N];
};
Buffer<char, 1024> glob;
void fct()
{
    Buffer<int, 10> buf;
}

pair<int, double> p = {1, 5.2};
// auto p = make_pair(1, 5.2);
// pair p = {1, 5.2};C++17
template <typename T>
class Vector
{
  public:
    Vector(int);
    Vector(initializer_list<T>);
};
Vector<int> v1{1, 2, 3};
Vector<int> v2 = v1;
auto q = new Vector<int>{1, 2, 3};
Vector<int> v3(1);
Vector<string> vs1{"Hello", "World"};
Vector<string> vs{"Hello", "World"};
Vector<string> vs2{"Hello"s, "World"s};
Vector<string> vs3{"Hello"s, "World"};