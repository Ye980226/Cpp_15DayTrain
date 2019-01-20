//Make sure that objects are initialized before they're used
// int x;
#include <iostream>
#include <string>
#include <list>
class Point
{
    int x, y;
};
Point p;
int x = 0;
const char *text = "A C-style string";
double d;
int main()
{
    std::cin >> d;
    return 0;
}

// For almost everything else, the responsibility for nitialization falls on constructors. The rule there is simple: make sure that all constructors initialize everything in the object.
class PhoneNumber
{
};
class ABEntry
{
  public:
    ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones);
    ABEntry();

  private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numTimesConsulted;
};
ABEntry::ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones) : theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0) {} //这
// 样子操作会更有效率
// {
//     theName = name;
//     theAddress = address;
//     thePhones = phones;
//     numTimesConsulted = 0;
// }
ABEntry::ABEntry() : theName(), theAddress(), thePhones(), numTimesConsulted(0) {}
// there’s only one more thing to worry about. That thing is — take a deep breath — the order of initialization of on-local static objects defined in different translation units.
class FileSystem
{
  public:
    std::size_t numDisks() const;
};

// extern FileSystem tfs;
FileSystem &tfs()
{
    static FileSystem fs;
    return fs;
}
class Directory
{
  public:
    Directory();
};
Directory::Directory()
{
    std::size_t disks = tfs().numDisks();
}
Directory &tempDir()
{
    static Directory td;
    return td;
}//用non-local static object做返回值可以避免顺序问题,但static在多线程里面会出问题