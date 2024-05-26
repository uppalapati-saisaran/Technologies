- make_unique is the recommanded way to create instances of std::unique_str s due to the following reasons:

1, Avoid having to use the new operator.
2, Prevents code repetition when specifying the underlying type the pointer shall hold.
3, Most importantly, it provides exception-safetly. Suppose we were calling a function foo like so:

	foo(std::unique_ptr<T>{new T{}}, function_that_throw(), std::unique_ptr<T>{new T{}});
	
- The compiler is free to call new T{}, then function_that_throws(), and so on...
- Since we have allocated data on the heap in the first constructor of a T, we have introduced a leak here. With std::make_unique, we are given exception-safetly. 

   foo(make_unique<T>(), function_that_throw(),std::make_unique<T>());
   
   
*****************************************************************************************************************************

// C++ code to implement std::make_unique
#include <iostream>
#include <memory>
using namespace std;

class Geeks 
{
    public:
        Geeks() { cout << "Object Created" << endl; }  // constructor
        ~Geeks() { cout << "Object Destroyed" << endl; } // destructor
};

void f()
{
    //creating unique ptr Object
    unique_ptr<Geeks> o = make_unique<Geeks>();
}

int main()
{
    f();
    return 0; 
}

********************************************************************************************************************************
   
 //C++ code to implement std::make_unique()
#include<iostream>
#include<memory>
using namespace std;

class Geeks 
{
  public:
    int d;
    //Constructor
    Geeks(int x)
    {
        this->d = x;
        cout << "Object Created\n";
    }
    //destructor
    ~Geeks() { cout << "Object Created\n"; }
};

void f() 
{
    //creating unique ptr Object
    unique_ptr<Geeks> o = make_unique<Geeks>(10);
    cout << o->d << endl;
}

int main()
{
    f();
    return 0;
}

***************************************************************************************************************************************

#include<iostream>
#include<memory>
using namespace std;
struct vec3
{
   int x,y,z;
   //Following constructor is no longer need since C++20.
   vec3(int x=0,int y=0,int z=0) noexcept : x(x),y(y),z(z) {}
   
   friend ostream& operator<<(ostream& os,const vec3& v)
   {
       return os << "{ x =" << v.x << " , y=" << v.y << ", z=" << v.z << " }"; 
   }
}; 

//Output Fibonacci numbers to an output iterator
template<typename OutputIt>
OutputIt fibonacci(OutputIt first, OutputIt last)
{
    for(int a = 0,b =1; first != last; ++first)
    {
        *first = b;
        b += exchange(a,b);
    }
    return first; 
}

int main()
{
    //Use the default constructor
    unique_ptr<vec3> v1 = make_unique<vec3>();
    cout << *v1 << '\n';
    
    //Use the constructor that matches these arguments.
    unique_ptr<vec3> v2 = make_unique<vec3>(0,1,2); 
    cout << *v2 << '\n'; 
    
    //Create a unique_ptr to an array of 5 elements.
    unique_ptr<vec3[]> v3 = make_unique<vec3[]>(5); 
    for(std::size_t i = 0;i < 5; i++)
    {
        cout << v3[i] << '\n'; 
    }
    
    //Create a unique_ptr to an uninitialized array of 10 integers.
    // then populate it will fibonacci numbers.
    unique_ptr<int[]> ii = make_unique_for_overwrite<int[]>(10); 
    fibonacci(ii.get(),ii.get()+10); 
    for(std::size_t i = 0;i<10; i++)
    {
        cout << ii[i] << '\n';
    }
    return 0;
}


***************************************************************************************************************************************************
