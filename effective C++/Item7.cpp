//Item7 Declare destructors virtual in polymorphic base classes.
#include <string>
class TimeKeeper
{
  public:
    TimeKeeper();
    virtual ~TimeKeeper(); //必须要加virtual，否则是个灾难
};
class AtomicClass : public TimeKeeper
{
};
class WaterClock : public TimeKeeper
{
};
class WristWatch : public TimeKeeper
{
};
class Point
{
  public:
    Point(int xCoord, int yCoord);
    ~Point();

  private:
    int x, y;
};
// The implementation of virtual functions requires that objects carry
// information that can be used at runtime to determine which virtual
// functions should be invoked on the object. This information typically takes the form of a pointer called a vptr (“virtual table pointer”). The vptr points to an array of function pointers called a vtbl (“virtual table”); each class with virtual functions has an associated vtbl. When a virtual function is invoked on an object, the actual function called is determined by following the object’s vptr to a vtbl and then looking up the appropriate function pointer in the vtbl.
class SpecialString : public std::string
{
}; //bad idea!std::string has non-virtual destructor
class AWOV
{
  public:
    virtual ~AWOV() = 0;
};
AWOV::~AWOV() {}
// nor the STL container types are designed to be base classes at all
int main()
{
    TimeKeeper *getTimeKeeper();
    TimeKeeper *ptk = getTimeKeeper();
    delete ptk;
}
