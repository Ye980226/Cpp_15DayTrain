#include <stdexcept>
#include <iostream>
#include <list>
#include <string>
using namespace std;
template <typename T>

class Vector
{
  private:
    T *elem;
    int sz;

  public:
    explicit Vector(int s);
    ~Vector() { delete[] elem; }
    T &operator[](int i);
    const T &operator[](int i) const;
    int size() const;
};
template <typename T>
Vector<T>::Vector(int s)
{

    elem = new T[s];
    sz = s;
}
template <typename T>
const T &Vector<T>::operator[](int i) const
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}
void write(const Vector<string> &vs)
{
    for (int i = 0; i != vs.size(); ++i)
        cout << vs[i] << '\n';
}

int main()
{
    Vector<char> vc(200);
    Vector<string> vs(17);
    Vector<list<int>> vli(45);
}