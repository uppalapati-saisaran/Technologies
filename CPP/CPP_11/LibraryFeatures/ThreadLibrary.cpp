// thread example
#include<iostream>   // std::cout
#include<thread>     // std::thread

void foo()
{
  // do stuff
}

void bar(int x)
{
  // do stuff
}

int main()
{
	std::thread first(foo);  // spawn new thread that calls foo()
	std::thread second(bar,0); // spawn new thread that calls bar(0)
	
	std::cout << "main, foo and bar now execute concurrently...\n";
	
	// synchorize threads:
	first.join();      // pause until first finishes
	second.join();     // pauses until second finishes
	
	std::cout << "foo and bar completed.\n";
	
	return 0;
}

Output :

main, foo and bar now execute concurrently.
foo and bar completed.

*************************************************************************************

// constructing threads
#include<iostream>  // std::cout
#include<atomic>    // std::atomic
#include<thread>    // std::thread
#include<vector>    // std::vector

std::atomic<int> global_counter(0); 

void increase_global(int n) { for(int i=0;i<n; ++i) ++global_counter; }

void increase_reference(std::atomic<int>& variable, int n) { for(int i=0;i<n;++i) ++ variable; }

struct C : std::atomic<int> 
{
	C():std::atomic<int>(0) {}
	void increase_member(int n) { for(int i=0;i<n;i++) fetch_add(1); }
};

int main()
{
	std::vector<std::thread> threads;
	std::cout << "increase global counter with 10 threads...\n";
	for(int i=1;i<=10;++i)
		threads.push_back(std::thread(increase_global,1000));
    
	std::cout << "increase counter (foo) with 10 threads using reference...\n";
	std::atomic<int> foo(0);
	for(int i=1;i<=10;++i)
		threads.push_back(std::thread(increase_reference,std::ref(foo),1000));
	
	std::cout << "increase counter(bar) with 10 threads using member...\n";
	C bar;
	for(int i=1;i<=10;++i)
		threads.push_back(std::thread(&C::increase_member,std::ref(bar),1000));
	
	std::cout << "synchorizing all threads...\n";
	for(auto& th : threads) th.join();
	
	std::cout << "global_counter: " << global_counter << '\n';
	std::cout << "foo: " << foo << '\n';
	std::cout << "bar: " << bar << '\n';
	
	return 0;
}

Output :
increase global counter using 10 threads...
increase counter (foo) with 10 threads using reference...
increase counter (bar) with 10 threads using member...
synchronizing all threads...
global_counter: 10000
foo: 10000
bar: 10000

********************************************************************************************************

#include<iostream>   // std::cout
#include<thread>     // std::thread, std::this_thread::sleep_for
#include<chrono>     // std::chrono::seconds

void pause_thread(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

int main() 
{
  std::cout << "Spawning and detaching 3 threads...\n";
  std::thread(pause_thread,1).detach();
  // thread represented by the object from the calling thread, allowing them to execute independenly from each other. 
  std::thread(pause_thread,2).detach();
  std::thread(pause_thread,3).detach();
  std::cout << "Done spawning threads.\n";
  
  std::cout << "(the main thread will now pause for 5 seconds)\n";
  pause_thread(5);
  return 0;
}


Output :

Spawning and detaching 3 threads...
Done spawning threads.
(the main thread will now pause for 5 seconds)
pause of 1 seconds ended
pause of 2 seconds ended
pause of 3 seconds ended
pause of 5 seconds ended

**********************************************************************************************************

// thread::get_id / this_thread::get_id
#include<iostream>   // std::cout
#include<thread> // std::thread, std::thread::id, std::this_thread::get_id 

std::thread::id main_thread_id = std::this_thread::get_id();

void is_main_thread() {
	if(main_thread_id == std::this_thread::get_id()))
		std::cout << "This is the main thread.\n";
	else
		std::cout << "This is not the main thread.\n";
}

int main() 
{
	is_main_thread();
	std::thread th(is_main_thread);
	th.join();
}

Output:

This is the main thread.
Ths is not the main thread.


**********************************************************************************************************

// example of thread::joinable
#include<iostream>  // std::cout
#include<thread>   // std::thread
void mythread()
{
  // do stuff.
}
int main() 
{
	std::thread foo;
	std::thread bar(mythread);
	
	std::cout << "Joinable after construction: \n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << "\n";
	std::cout << "bar: " << bar.joinable() << "\n";
	// A thread object is joinable if it represents a thread of execution.
	// A thread object is not joinable in any of these cases: 
	1, if it was default-constructed.
	2, if it has been moved from (either constructing another thread object, or assigning to it).
	3, if either of its members join or detach has been called.
	
	if(foo.joinable()) foo.join();
	if(bar.joinable()) bar.join(); 
	
	std::cout << "Joinable after joining:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n';
	std::cout << "bar: " << bar.joinable() << '\n';

    return 0;
}

Output:
Joinable after construction
foo: false
bar: true
Joinable after  joining:
foo: false
bar: false

*******************************************************************************************************

native_handle: it returns a value used to access implementation-specific information associated to the thread.

*******************************************************************************************************

// example of thread::operator=
#include<iostream>    // std::cout
#include<thread>     // std::thread, std::this_thread::sleep_for
#include<chrono>     // std::chrono::seconds

void pause_thread(int n)
{
	std::this_thread:sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

int main() 
{
	std::thread threads[5];  // default constructed therads.
	
	std::cout << "Spawning 5 threads...\n";
	for(int i=0;i<5;i++)
		threads[i] = std::thread(pause_thread,i+1);   // move-assign threads
	
	std::cout << "Done spawning threads. Now waiting for them to join:\n";
	for(int i=0;i<5;i++)
		threads[i].join();
	
	std::cout << "All threads joined!\n";
	
	return 0;
}
	
Output :
	
Spawning 5 threads...
Done spawning threads. Now waiting for them to join:
pause of 1 seconds ended
pause of 2 seconds ended
pause of 3 seconds ended
pause of 4 seconds ended
pause of 5 seconds ended
All threads joined!

**************************************************************************************************

thread::swap :  Swaps the state of the object with that of x. 


**************************************************************************************************








