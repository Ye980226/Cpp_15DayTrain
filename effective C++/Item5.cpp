//Know what functions C++ silently writes and calls
#include <string>
class Empty
{
  public:
    Empty() {}                 //default constructor
    Empty(const Empty &rhs) {} //copy constructor
    ~Empty() {}                //destructor --see below
    //for whether it's virtual
    Empty &operator=(const Empty &rhs) {} //copy assignment operator
};
template <typename T>
class NamedObject
{
  public:
    //default constructor不会生成
    //compilers will generate copy constructor and copy assignment
    NamedObject(const char *name, const T &value);
    NamedObject(const std::string &name, const T &value);

  private:
    std::string nameValue;
    T objectValue;
};
// Because a constructor is declared in NamedObject, compilers won’t generate a default constructor. This is important. It means that if you’ve carefully engineered a class to require constructor arguments,you don’t have to worry about compilers overriding your decision by blithely adding a constructor that takes no arguments.

void test()
{
    Empty e1;     //default constructor
                  //destructor
    Empty e2(e1); //copy constructor
    e2 = e1;      //copy assignment operator
    NamedObject<int> no1("Smallest Prime Number", 2);
    NamedObject<int> no2(no1);
}
