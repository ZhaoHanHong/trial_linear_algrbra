# Package for Matricies and Polynoimals

1.Notes

I extremely appreciate this opportunity of coding a program for polynomials and matricies after the LA midterm(bushi). I believe that I have learnt a few lessons from it:

(1) When using functions with templates, we should always use one `.h` file instead of a `.h` and a `.cpp` file. This law originally comes from [为什么C++一般将模板实现放在头文件中](https://www.cnblogs.com/zpcdbky/p/16329886.html) (in homework 3-alist). My real experience also prove the law, and violating it would lead to a lot of errors. Another thing that worth mentioning is that we must first declare the class and function before implementing it, and the declaration should have a template sign `<>`. Here is an example: (note the `<>` sign)
```cpp
template<typename T>
class Matrix;

template <typename T>
std::ostream &operator<<(std::ostream &out,const Matrix<T> &matrix);

template <typename T>
class Matrix{
    //...
    public:
        std::ostream &operator<<<>(std::ostream &out,const Matrix<T> &matrix);
};

template <typename T>
std::ostream &Matrix<T>::operator<<(std::ostream &out,const Matrix<T> &matrix){
    //...
}
```

(2)Whenever I write a class, I should first inplement the 2 consturctors(copy and move) and the 2 assignments(copy and move), regardless of whether I would use them or not supposingly.

(3) Always use `const`, whenever possible! I am truely tortured by the frequent errors, and a simple `const` always fix everything. Among the `const`'s, those after functions are the most significantly useful ones. They denote that the function can be passed in rvalues. To the opposite, if you don't put the `const` here, the compiler would complain when you feed in things like `f(g(...))` or `std::cout<<f(...)`.

(4) Never forget the return value when implement an function!


2.Poly

`class Poly` is a class with following functions:
```cpp
//constructors
Poly();
Poly(int n);
Poly(Poly &&other);
Poly(const Poly &other);
Poly(const std::string &name);
//assignments 
Poly &operator= (Poly &&other);
Poly &operator= (const Poly &other);
void CopyFromString(const std::string &name);
Poly &operator= (const std::string &name);
const int operator[](int index)const; 
void SetCoeff(int index,int val_);
friend std::ostream &operator<<(std::ostream &out,const Poly & poly);
friend Poly operator *(const Poly &a,const Poly &b);
friend Poly operator +(const Poly &a,const Poly &b);
friend Poly operator *(int c,const Poly &a);
friend bool operator==(const Poly &a,const Poly &b);
```
We only support polynomials with integer coefficients.

The assignment from string allows you to type `"1,1"`for $x+1$, but the coefficients 0 has to be typed,too. For another example, $x^2-1$ can be typed as `"1,0,-1"`. If you want to access an specific entry of the polynomial, you can use bracket `[]` to finish the goal; however, due to trials and failures, I decided to not reload `[]` for writing, instead writing a setter function.

The reloaded operators allow you to call `a+b,a*b,c*a`where `a,b` are polynomials and `c` is an integer. We assure that after each operation, the polynomial would change to minimal degree, so $x+1+(-x+1)$ will return $2$ instead of $0x+2$. Moreover, you can use `std::cout` to output an polynomial.

3. Matrix

Our matrix enables basic properties of the matrix:

The determinant: we use the recursive way of calculating det, which is an $O(n!)$ algorithm. However, since our entries may be polynomials which are hard to perform devisions, the elementary row operation method may not be easy to apply.