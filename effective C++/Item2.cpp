//多用const，尽量避免使用define
//用const,enum代替define定义一个常量
#define MAX 10
#define f(a, b) (a > b ? a : b)
template <typename T>
inline const T f_1(T a, T b)
{
    return a > b ? a : b
}
class SomeClass
{
  private:
    enum
    {
        Variable1 = 5,
        Variable2 = 6
    };
    int X[Variable1];
};
int main()
{
    const int Max = 10; //而且用大写加小写的命名方式
    int const *const pm = &Max;
    int const *pm2 = &Max;
    // int * const pm3 = &Max;//invaild because Max can't be revised 指针本身不被修改，但是指向的地址可以被修改，但是Max声明的时候表明是const所以Max不能被修改，所以内容其实是不能被修改的，所以是非法的。
    //定义一个define的function用inline和template，这样子有define的效率，函数也非常的显而易见。
    //如果一定要在预编译里用enum定义一个常量，比如数组不能传入变量。
    
    return 0;
}