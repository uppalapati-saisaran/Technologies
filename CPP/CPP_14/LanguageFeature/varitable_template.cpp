- C++ 14 allows variables to be templated:

  template<class T>
  constexpr T pi = T(3.1415926535897932385);
  template<class T>
  constexpr T e = T(2.7182818245904);
 
*****************************************************************************


 // c++ program to illustrate the use of variable template
#include<iostream>
using namespace std;

//declaring the variable template
template<class T>
constexpr T e = T(2.718281828459045);

int main()
{
    cout << "Integer Type of e: " <<  e<int> << endl;
    cout << "Float Type of e:" << e<float> << endl;
    return 0;
}

2
2.71

******************************************************************************

// C++ program to illustrate the use of static data member template
#include<iostream>
using namespace std;

class limits {
public:
    //static data member template declaration
    template<typename T> static const T min; 
};

// definition
template<typename T> const T limits::min = T(10.24);

int main() 
{
    cout << limits::min<int> << endl;
    cout << limits::min<float>;
    
    return 0;
}

10
10.24

******************************************************************************

#include<iostream>
using namespace std;
template<class... Types>
struct Tuple {};

int main()
{
    Tuple<> t0;  // Types contains no arguments.
    Tuple<int> t1; // Types contains one argument: int 
    Tuple<int,float> t2; // Types contains two arguments: int and float
    //Tuple<0> t3; // error: 0 is not  a type 
    
    return 0;
}

********************************************************************************