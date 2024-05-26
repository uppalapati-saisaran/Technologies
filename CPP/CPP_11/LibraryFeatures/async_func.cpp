- std::async runs the given function either 
       * asynchronously
	   * lazily-evaluated 

- then returns a std::future which holds the result of that function call. 

- The first parameter is the policy which can be:

 1, std::launch::async | std::launch::deferred - it is up to the implementation whether to perform asynchronous execution or lazy evaluation.
 2, std::launch::async - Run the callable object on a new thread.
 3, std::launch::deferred - Perform lazy evaluation on the current thread.
 
 int foo() {
	 /* Do something here, then return the result. */
	 return 1000;
 }
 
 auto handle = std::async(std::launch::async,foo); // create an async task.
 auto result = handle.get(); //wait for the result
 
 ****************************************************************************************************************
 
#include<iostream>
#include<vector>
#include<numeric>
#include<future>
using namespace std;

std::mutex m; 

struct X
{
    void foo(int i,const string& str)
    {
        std::lock_guard<std::mutex> lk(m);
        cout << str << ' ' << i << '\n' << endl; 
    }
    void bar(const string& str)
    {
        std::lock_guard<std::mutex> lk(m);
        cout << str << '\n'; 
    }
	int operator()(int i)
	{
		std::lock_guard<std::mutex> lk(m);
		std::cout << i << '\n';
		return i + 10; 
	}
};

template<typename RandomIt>
int parallel_sum(RandomIt beg,RandomIt end) 
{
    auto len = end-beg;
    if(len < 1000) 
        return accumulate(beg, end, 0);
    
    RandomIt mid = beg + len/2;
    auto handle = async(launch::async,parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg,mid);
    return sum + handle.get();
}

int main() 
{
    vector<int> v(1000,1);
    std::cout << "The sum is " << parallel_sum(v.begin(),v.end()) << '\n'; 
    
    X x;
    // calls (&x)->foo(42,"Hello") with default policy:
    // may print "Hello 42" concurrently or defer execution. 
    auto a1 = std::async(&X::foo,&x,42,"Hello");
    // calls x.bar("world!") with deferred policy
    // prints "world!" when a2.get() or a2.wait is called
    auto a2 = std::async(std::launch::deferred,&X::bar,x,"world!");
	// Calls X()(43); with async policy
	// print "43" concurrently
	auto a3= std::async(std::launch::async,X(),43);
    a2.wait();       // print "world1"
	std::cout << a3.get() << '\n';  // prints "53"
} // if a1 is not done a this point, destructor of a1 prints "Hello 42" here. 

*****************************************************************************************************************
 
 