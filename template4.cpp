#include <string>
using namespace std;
template <class T> //在模板定义语法class和template完全一样
constexpr T viscosity = 0.4;
//Aliases
// using size_t = unsigned int;
template <typename C>
using Value_type = typename C::value_type; //the type of C's elements

template <typename Container>
void algo(Container &c)
{
    Vector<Value_type<Container>> vec;
}
template <typename Key, typename Value>
class Map
{
};
template <typename Value>
using String_map = Map<string, Value>;
String_map<int> m;

//compile-time if C++17暂时不了解
//模板的concepts,使用requires Arithmetic关键字是C++20的内容暂时不了解
template <typename T, typename... Tail>
void print(T head, Tail... tail)
{
    // what we do for each argument, e.g.,
    cout << head << ' ';
    print(tail...);
}
//The typename ... indicates that Tail is a sequence of types.
// template <typename T, typename... Tail>
// void print2(T head, Tail... tail)
// {
//     cout << head << ' ';
//     if constexpr (sizeof...(tail) > 0)
//         print(tail...);
// }
