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
    int size() const;

  private:
    int sz;
    double *elem;
};
int Vector::size() const
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
class
    Container
{
  public:
    virtual double &operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

void use(Container &c)
{
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\n';
}
class Vector_container : public Container
{
  public:
    Vector_container(int s) : v(s) {}
    ~Vector_container() {}
    double &operator[](int i) override { return v[i]; }
    int size() const override { return v.size(); }

  private:
    Vector v = Vector(20);
};
class List_container : public Container
{
  public:
    List_container() {}
    List_container(initializer_list<double> il) : ld(il) {}
    ~List_container() {}
    double &operator[](int i) override;
    int size() const override { return ld.size(); }

  private:
    vector<double> ld;
};
double &List_container::operator[](int i)
{
    for (auto &x : ld)
    {
        if (i == 0)
            return x;
        --i;
    }
    throw out_of_range{"List container"};
}
void h()
{
    List_container ls = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(ls);
}
int main()
{
    h();
}
// 可以用explicit完成显式的声明，让隐式转换存在
void test(complex z1)
{
    complex z2{z1}; // copy initialization
    complex z3;
    z3 = z2; // copy assignment
    // ...
}
