//name convention
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
typedef int Rational;
// template <typename T>
// struct Rational/
// {
// T t;
// };
// template <typename T>
// const Rational<T> operator*(const Rational<T> &lhs, const Rational<T> &rhs);
//Widget *pw; //pw=ptr to Widget
class Airplane;
Airplane *pa; //pa = ptr to Airplane
class GameCharacter;
GameCharacter *pgc;
std::vector<int> vec;
const std::vector<int>::iterator iter = vec.begin();
// *iter = 10;
// ++iter;
std::vector<int>::const_iterator clter = vec.begin();
// *clter = 10;
// ++clter;

//use const objects可以很明显的知道哪些object会被修改，哪些不会被修改

class TextBlock
{
  public:
    TextBlock(std::string t) : text(t) {}
    const char &operator[](std::size_t position) const { return text[position]; } //operator[]for const objects,不能修改类中的数据，所以加const
    char &operator[](std::size_t position) { return text[position]; }             //operator[] for non-const objects
  private:
    std::string text;
}; //如果把string改成char *就算const也是可以修改
class CTextBlock
{
  public:
    std::size_t length() const;

  private:
    char *pText;
    mutable std::size_t textLength; //mutable 关键字定义的变量无论在不在const里都能修改
    mutable bool lengthIsValid;
};
std::size_t CTextBlock::length() const
{
    if (!lengthIsValid)
    {
        textLength = std::strlen(pText); //error
        lengthIsValid = true;
    }
    return textLength; //都不能修改
}
//两个operator[]会显得非常duplicate
//having the non-const operator[] call the const version is a safe way to avoid code duplication, even though it requires a cast.
class TextBlock
{
  public:
    const char &operator[](std::size_t position) const
    {
        return text[position];
    }
    char &operator[](std::size_t position)
    {
        return const_cast<char &>(static_cast<const TextBlock &>(*this)[position]);
    }
    // cast away const on
    // op[]’s return type;
    // add const to *this’s type;
    // call const version of op[]
};

void print(const TextBlock &ctb)
{
    std::cout << ctb[0];
}
int main()
{
    TextBlock tb("Hello");
    std::cout << tb[0];
    tb[0] = 'x'; //能够修改是因为返回了char的reference
    const TextBlock ctb("World");
    std::cout << ctb[0];
    // ctb[0] = 'x';//error,const
    Rational a = 1, b = 2, c;
    //把判断的写在左边
    c = a * b;
    bool booler = a * b == c;
}
