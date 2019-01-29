#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

template <typename T>
T compare(T &p1, T &p2)
{
    return p1 > p2 ? p1 : p2;
}
template <>
const char *compare(const char *&p1, const char *&p2)
{
    if (strcmp(p1, p2) > 0)
    {
        return p1;
    }
    return p2;
}
template <>
char *compare(char *&p1, char *&p2)
{
    if (strcmp(p1, p2) > 0)
    {
        return p1;
    }
    return p2;
}
// 2.定义一个Person类，封装人的信息（比如：姓名，身份证），需要通过文件读写函数实现多个人的信息写入与读出（提示：读写的时候才用持久化存储技术）
class Person
{
  public:
    Person() {}
    Person(char *n1, char *IdCard)
    {
        name = new char[strlen(n1) + 1];
        IDCard = new char[strlen(IdCard) + 1];
        strcpy(name, n1);
        strcpy(IDCard, IdCard);
        if (strlen(IDCard) != 18)

        {
            cerr << "你输入的身份证号有误";
        }
    }
    void write(const char *const filename);
    void read(const char *const filename);

  public:
    char *name;
    char *IDCard;
};
void Person::write(const char *const filename)
{
    ofstream fin(filename, ios::out);
    fin << "name:   " << name << "   IDCard   " << IDCard << endl;
}
void Person::read(const char *const filename)
{
    string s;
    ifstream fin(filename, ios::in);
    while (getline(fin, s))
        cout << s;
}

// 3.使用重装运算符［］实现数组操作，比如：s ["小小"] = 1000。
class Array
{
  public:
    Array() {}
    int &operator[](const char *k)
    {
        this->key = new char[strlen(k) + 1];
        strcpy(this->key, k);
        cout << key;
        return value;
    }
    int &operator=(int value)
    {
        this->value = value;
        return this->value;
    }

  public:
    char *key;
    int value = 0;
};

// 4.使用重载运算符 ++完成时钟的自加
struct TimeStamp
{
    int days;
    int hours;
    int minutes;
    int seconds;
};
class Clock
{
  public:
    void operator++()
    {
        seconds++;
        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60)
        {
            minutes = 0;
            hours++;
        }
        if (hours == 24)
        {
            hours = 0;
            days++;
        }
    }
    TimeStamp getTimeStamp()
    {
        return {days, hours, minutes, seconds};
    }

  private:
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
};
void write(fstream &ioFile, Person &p, const char *const filename, int length)
{
    ioFile.write((char *)&p, length);
}
void read(const char *const filename, int length)
{
    vector<Person> v1;
    Person p;
    fstream ioFile;
    ioFile.open(filename, ios::in);
    ioFile.read((char *)&p, length);
    while (!ioFile.eof())
    {
        v1.push_back(p);
        ioFile.read((char *)&p, length);
    }
    ioFile.close();
    for (vector<Person>::iterator vt = v1.begin(); vt != v1.end(); vt++)
    {
        cout << "name:  " << vt->name << "   IDCard:   " << vt->IDCard << endl;
    }
}

void test()
{
    const char *p1 = "123";
    const char *p2 = "234";
    cout << compare<const char *>(p1, p2) << endl;

    Person pe1("leon", "123456789012345678");
    Person pe2("leon", "123456789012345678");
    Person pe3("leon", "123456789012345678");
    Person pe4("leon", "123456789012345678");
    Person pe5("leon", "123456789012345678");
    Person pe6("leon", "123456789012345678");
    Person pe7("leon", "123456789012345678");
    Person pe8("leon", "123456789012345678");
    Person pe9("leon", "123456789012345678");
    Person pe10("leon", "123456789012345678");
    int length = sizeof(pe1);
    // Person pe2;
    const char *const filename = "test.txt";

    fstream ioFile;
    ioFile.open(filename, ios::out);
    write(ioFile, pe1, filename, length);
    write(ioFile, pe2, filename, length);
    write(ioFile, pe3, filename, length);
    write(ioFile, pe4, filename, length);
    write(ioFile, pe5, filename, length);
    write(ioFile, pe6, filename, length);
    write(ioFile, pe7, filename, length);
    write(ioFile, pe8, filename, length);
    write(ioFile, pe9, filename, length);
    write(ioFile, pe10, filename, length);
    ioFile.close();
    read(filename, length);

    Array a1;
    a1["小小"] = 1000;
    cout << endl
         << a1.key << ":" << a1.value << endl;
    Clock c1;
    int i = 10000;
    while (i > 0)
    {
        i--;
        ++c1;
    }
    TimeStamp t1 = c1.getTimeStamp();
    cout << "days: " << t1.days << endl
         << "hours: " << t1.hours << endl
         << "minutes: " << t1.minutes << endl
         << "seconds: " << t1.seconds << endl;
}
int main()
{
    test();
    return 0;
}