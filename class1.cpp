#include<cmath>
double sqrt(double);
class Vector{
public:
    Vector(int s);
    double &operator[](int i);
    int size();
private:
  double *elem;
  int sz;
};
double sqrt(double d)
{
    //
}
Vector::Vector(int s):elem{new double[s]},sz{s}
{

}

double &Vector::operator[](int i ){
    return elem[i];
}
int Vector::size(){
    return sz;
}
double sqrt_sum(Vector &v)
{
    double sum = 0;
    for (int i = 0; i != v.size();++i)
        sum += std::sqrt(v[i]);
    return sum;
}
