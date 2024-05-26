- C++ 11 introduces a new reference termed the rvalue reference.

- An rvalue reference to T, which is a non-template type parameter (such as int, or a user-defined type),is created with the syntax T&&.

- Rvalue references only bind to rvalues.

- Type deduction with lvalues and rvalues:

  int x = 0; //'x' is an lvalue of type 'int'
  int& x1 = x; // 'x1' is an lvalue of type 'int&'
  int&& xr = x; // compiler error - 'x' is an lvalue
  int&& xr2 = 0; // 'xr2' is an lvalue of type 'int&&' -- binds to the rvalue temporary, '0'
  
  void f(int& x) {}
  void f(int&& x) {}
  
  f(x); // calls f(int&)
  f(x1); // calls f(int&)
  f(3); // calls f(int&&)
  f(std::move(x)); // calls f(int&&)
  
  f(xr2);  // calls f(int&)
  f(std::move(xr2)); // calls f(int&& x) 
  
  
************************************************************************************************************************************************

#include<iostream>
using namespace std;
int main()
{
    // int &x = 666;  // -- Error 
    const int &x = 666; // OK 
    
    string s1 = "Hello";
    string s2 = " World";
    string&& s_rref = s1 + s2;  // the result of s1 + s2 is an rvalue
    s_rref += ", my friend";  // I can change the temporary string!
    cout << s_rref << '\n'; 
    return 0;
}

*************************************************************************************************************************************************
  
  
* Rule of Three :  This rule states that if your class defines one or more of the following methods it should probably explicitly define all three:

  destructor
  copy constructor
  copy assignment operator 
  
* Rule of Five : Two additional member function 

  move constructor - to construct new objects by stealing data from temporaries.
  move assignment - to replace existing objects by stealing data from tempories.
  
  
 **************************************************************************************************************************************************
 
 #include<cstddef>
#include<algorithm>
using namespace std;
class Holder 
{
    public:
    Holder(int size)  // constructor
    {
        m_data = new int[size];
        m_size = size;
    }
    ~Holder()
    {
        delete[] m_data;
    }
    Holder(const Holder& other)
    {
        m_data = new int[other.m_size];
        copy(other.m_data,other.m_data + other.m_size,m_data);  // (2) 
        m_size = other.m_size; 
    }
    Holder& operator=(const Holder& other)
    {
        if(this == &other) 
            return *this;
        
        delete[] m_data;
        m_data = new int[other.m_size];
        copy(other.m_data,other.m_data+other.m_size,m_data); 
        m_size = other.m_size;
        return *this;
    }
    
    Holder(Holder&& other)    // rvalue reference in input
    {
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data = nullptr;
        other.m_size = 0; 
    }
    
    Holder& operator=(Holder&& other)
    {
        if(this == &other)
            *this;
        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data = nullptr; 
        other.m_size = 0;
        return *this;
    }

    private:
        int* m_data;
        size_t m_size; 
}; 

int main()
{
    Holder h1(10000); // regular constructor 
    Holder h2 = h1; // copy constructor
    Holder h3(h1); // copy constructor (alternate syntax)
    return 0; 
}

*********************************************************************************************************************************

RAII (Resource Acquistion Is Initialization)  : -  where you wrap a class around a resource (file, socket, database connection, allocated memory, ...).
The resource is initialized in the class constructor and cleaned up in the class destructor. 
This way you are sure to avoid resource leaks. 

*********************************************************************************************************************************


* Perfect forwarding : This techinque allows you to move your data across multiple templates and non-template functions without wrong type
                       conversions (i.e., perfectly) . 
					   
***********************************************************************************************************************************

  