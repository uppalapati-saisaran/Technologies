- A lightweight array-like containers of elements created using a "braced list" syntax.

- For example, { 1,2,3 } creates a sequences of integers, that has type std::initializer_list<int>.

- Useful as a replacement to passing a vector of objects to a function.

int sum(const std::initialier_list<int>& list) {
	int total = 0;
	for(auto& e : list) {
	total += e;
}

return total;
}

auto list = {1,2,3};
sum(list); // == 6
sum({1,2,3}); // == 6
sum({}); // == 0

*******************************************************************************************************************

https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/


- Initializer list used to initializing the data members of a class.
- The list of members to be initialized is indicated with constructor as a comma-separated list followed by a colon.

#include<iostream>
using namespace std;

class Point {
   private:
    int x;
    int y; 
   public:
    Point(int i=0,int j=0): x(i),y(j) {}
    /* The above use of initializer list is optional as The
    construtor can also be written as:
    Point(int i=0,int j=0)
    {
        x = i;
        y = j;
    }
    */
    int getX() const { return x; }
    int getY() const { return y; }
}; 

int main() 
{
    Point t1(10,15);
    cout << "x =" << t1.getX() << ". ";
    cout << "y =" << t1.getY();
    return 0;
}

1, For Initialization of Non-static const Data Members: 

- const data members must be initialized using initializer List.
- In the following example, "t" is a const data member of Test class and is initialized using Initializer List.
- Reason for initializing the const data member in the initialzer list is because no memory is allocated separately for const
  data member, it is folded in the symbol table due to which we need to initialize it in the initializer list.
- Also, it is a parameterized constructor and we don't need to call assignment operator which means we are avoiding one extra operation.

// C++ program to demostrate the use of 
// iniitailzer list to initialize the const
// data member

#include<iostream>
using namespace std;

class Test 
{
    const int t;
    public:
    // Initializer list must be used. 
    Test(int t):t(t) {} 
    int getT() { return t; }
}; 

int main() 
{
    Test t1(10);
    cout << t1.getT();
    return 0; 
}

2, For Initialization of Reference Members

// Initialize of Reference Members
#include<iostream>
using namespace std;

class Test 
{
    int &t;
    public:
        Test(int &t):t(t) {} // Initializer list must be unsigned
        int getT() { return t; }
};

int main() 
{
    int x = 20;
    Test t1(x);
    cout << t1.getT() << endl;
    x = 30;
    cout << t1.getT() << endl;
    return 0;
}

3, For initialization of member objects that do not have a default constructor 

// C++ program to initialize a member object without default
// constructor
#include<iostream>
using namespace std;

class A {
    int i;
public:
    A(int);
}; 

A::A(int arg)
{
    i = arg;
    cout << "A's constructor called. value of i:" << i << endl;
}

// Class B contains object of arg
class B {
    A a;
    public:
    B(int a);
}; 

B::B(int x):a(x)
{   // Initializer list must be used 
    cout << "B's Constructor called"; 
}

int main() 
{
    B obj(10);
    return 0;
}


4, For initialization of Base class members

- The parameterized constructor of the base class can only be called using the Initializer List.

#include<iostream>
using namespace std;

class A {
    int i;
public:
    A(int );
};

A::A(int arg) 
{
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}

// Class B is derived from A 
class B : A {
public:
 B(int );
};

B::B(int x):A(x) 
{  //Initializer list must be used 
  cout << "B's Constructor called";
}

int main() 
{
    B obj(10);
    return 0; 
}


5, When the Constructor's Parameter name is the same as Data member

- if the constructor's parameter name is the same as the data member name then the data member must be initialized
  either this pointer or initializer list. 
  
  #include<iostream>
using namespace std;

class A {
    int i;
    public:
    A(int);
    int getI() const { return i; }
};

A::A(int i) : i(i)
{
    
} // Either initializer list or this pointer must be used.

/* The above constructor can also be written as
A::A(int i) {
    this-> i = i;
}
*/

int main()
{
    A a(10);
    cout << a.getI();
    return 0; 
}

6, For performance Reasons

// With out initializer list 
include<iostream>
class MyClass {
    Type variable;
    public:
    MyClass(Type a) 
    {
        //Assume that type is an already
        //declared class and it has appropriate
        // constructors and operators
        variable = a; 
    }
}; 

// Compiler follows following steps to create an Object of type MyClass

1. Type's constructor is called first for "a".
2. Default construct "variable".
3, The assignment operator of "Type" is called inside of MyClass() constructor to assignment
   variable = a;
4, And the finally destructor of "Type" is called for "a" since it goes out of scope. 

// With initializer list 
class MyClass {
    Type variable;
    public:
    MyClass(Type a):variable(a) {
        
    }
};

1, Type's constructor is called first for "a."
2, Parameterized constructor of "Type" class is called to initialize: variable(a) : The arguments in the initializer
   list are used to copy constructor "variable" directly.
3, The destructor of "Type" is called for "a" since it goes out of scope.


// As we can see from this example if we use assignment inside constructor body there are three functon calls: constructor + destructor +
// one additional assignment operator call. And if we use intializer list there are only tow function calls: copy constructor + destructor call 

Parameter vs Uniform Initialization in C++ :

- It is better to use an initialization list with uniform iniitailzation {} rather than parameter initialization() to avoid the issue of narrowing
  conversions and unexcepted behaviour.
- It provides stricter type-checking during initialization and prevents potential narrowing converstions.


#include<iostream>
using namespace std; 
class Base 
{
    char x;
    public:
        Base(char a)
        : x{a}
        {
            
        }
        void print() { cout << static_cast<int>(x); }
};

int main() 
{
    Base b{ 300 }; // using uniform initialization with {}
    b.print();
    return 0;
}


https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/

********************************************************************************************************



