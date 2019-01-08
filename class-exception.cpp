#include <stdexcept>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
#define RANGE_CHECK true
class Vector
{
  public:
    Vector(int s);
    double &operator[](int i);
    int size();

  private:
    int sz;
    double *elem;
};
int Vector::size()
{
    return sz;
}
Vector::Vector(int s) : elem{new double[s]}, sz{s}
{
}

void test()
{
    try
    {
        Vector v(-27);
    }
    catch (std::length_error)
    {
        //
    }
    catch (std::bad_alloc)
    {
        //
    }
}
double &Vector::operator[](int i)
{
    if (RANGE_CHECK && (i < 0 || size()) <= i)
        return elem[i];
}
void f(const char *p)
{
    assert(p != nullptr);
}
static_assert(4 <= sizeof(int), "integers are too small");
int sum(const vector<int> &v)
{
    int s = 0;
    for (const int i : v)
        s += i;
    return s;
}
int main()
{
    vector<int> fib = {1, 2, 3, 5, 8, 13, 21};
    int x = sum(fib);
    cout << x;

    // system("pause");
    return 0;
}
//引用就少掉了copy这一个环节
//越发觉得现代的c++就是python