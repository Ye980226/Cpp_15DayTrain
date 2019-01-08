#include <iostream>
using namespace std;
class Person
{
  public:
    Person(int age, int height, int weight)
    {
        cout << "nihao" << endl;
    }
    ~Person() {}
};
class Boy : public Person
{
  public:
    Boy(int height, int weight) : Person(30, height, weight) { cout << "nihao2" << endl; }
};

int main()
{
    Boy boy1 = Boy(20, 20);
    return 0;
}