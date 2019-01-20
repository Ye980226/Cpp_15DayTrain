//Item6 Explicitly disallow the use of compiler-generated functions you do not want
// class HomeForSale
// {
//   private:
// HomeForSale(const HomeForSale &);
// HomeForSale &operator=(const HomeForSale &); //declarations only 而且是private
// };
class Uncopyable
{
  protected:
    Uncopyable() {}
    ~Uncopyable() {}

  private:
    Uncopyable(const Uncopyable &);
    Uncopyable &operator=(const Uncopyable &);
};
class HomeForSale:private Uncopyable{
    
};
void test()
{
    // HomeForSale h1;
    // HomeForSale h2;
    // HomeForSale h3(h1); //因为每一幢房子都是unique的，所以copy操作应该被禁止
    // h1 = h2;            //同上,copy 操作被禁止
}
