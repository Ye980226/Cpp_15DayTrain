#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <complex>
using namespace std;
// template<typename T>
// class Vector2{
//     public:
//     using value_type=T;
//     Vector2(initializer_list<T>);
//     template <typename Iter>
//     Vector2(Iter b, Iter e)->Vector2<typename Iter::value_type>;
// };
// Vector2<int> v1{1, 2, 3, 4, 5};
// Vector2<int> v2(v1.begin(), v1.begin() + 2);
template <typename T>
class Vector
{
  public:
    Vector(int);
    Vector(initializer_list<T>);
};
template <typename Sequence, typename Value>
Value sum(const Sequence &s, Value v)
{
    for (auto x : s)
        v += x;
    return v;
}

void user(vector<int> &vi, list<double> &ld, vector<complex<double>> &vc)
{
    int x = sum(vi, 0);
    double d = sum(vi, 0.0);
    double dd = sum(ld, 0.0);
    auto z = sum(vc, complex<double>{0.0, 0.0});
}
template <typename T>
class Less_than
{
    const T val;

  public:
    Less_than(const T &v) : val{v} {}
    bool operator()(const T &x) const { return x < val; }
    //call operator
};
Less_than<int> lti{42};
Less_than<string> lts{"Backus"};
Less_than<string> lts2{"Naur"};
Less_than<string> lts3 = lts2;

void fct(int n, const string &s)
{
    bool b1 = lti(n); //true if n<42;
    bool b2 = lts(s); //true if s<"Backus"
}
//重载()的操作可以拿来计数
template <typename C, typename P>
int count(const C &c, P pred)
{
    int cnt = 0;
    for (const auto &x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}
void f(const vector<int> &vec, const list<string> &lst, int x, const string &s)
{
    cout << "number of values less than " << x << ": " << count(vec, Less_than<int>{x}) << '\n';
    cout << "number of values less than " << s << ": " << count(lst, Less_than<const string>{s}) << '\n';
}
//Lambda Expression
void f2(const vector<int> &vec, const list<string> &lst, int x, const string &s)
{
    cout << "number of values less than " << x << ": " << count(vec, [&](int a) { return a < x; }) << '\n';
    cout << "number of values less than " << s << ": " << count(lst, [&](const string &a) { return a < s; }) << '\n';
}
//The notation [&](int a){return a<x;} is called a lambda expression
//like Less_than<int>{x}
// The [&] is a
// capture list specifying that all local names used in the lambda body (such as
// x) will be accessed through references. Had we wanted to “capture” only x,
// we could have said so: [&x]. Had we wanted to give the generated object a
// copy of x, we could have said so: [=x]. Capture nothing is [ ], capture all
// local names used by reference is [&], and capture all local names used by
// value is [=].
template <typename C, typename Oper>
void for_all(C &c, Oper op)
{
    for (auto &x : c)
        op(x);
}
