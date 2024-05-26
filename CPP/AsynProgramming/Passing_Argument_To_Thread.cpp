#include<iostream>
#include<string>
#include<thread>
using namespace std;
void threadCallback(int x,string str)
{
    cout << "Passed Number = " << x << endl;
    cout << "Passed String = " << str << endl;
}

int main()
{
    int x = 10;
    string str = "Sample String";
    thread threadObj(threadCallback,x,str);
    threadObj.join();
    return 0; 
}

*********************************************************************


// How not to pass arguments to threads in C++11
// reference 
#include<iostream>
#include<thread> 
using namespace std;

void newThreadCallback(int *p)
{
    cout << "Inside Thread : "" : p = " << *p << endl;
    chrono::milliseconds dura( 1000 );
    this_thread::sleep_for ( dura );
    *p = 19;
}


void startNewThread()
{
    int i = 10;
    cout << "Inside Main Thread : "" : i = " << i << endl;
    thread t(newThreadCallback,&i);
    t.detach();
    cout << "Inside Main Thread : "" : i = " << i << endl;
}


int main() 
{
    startNewThread();
    chrono::milliseconds dura( 2000 );
    this_thread::sleep_for( dura );
    return 0;
}

Inside Main Thread :  : i = 10
Inside Main Thread :  : i = 10
Inside Thread :  : p = 0

**********************************************************************

// How not to pass arguments to threads in C++11
// pointer

#include<iostream>
#include<thread>
using namespace std;
void newThreadCallback(int *p)
{
    cout << "Inside Thread : "" : p = " << *p << endl;
    chrono::milliseconds dura ( 1000 );
    this_thread::sleep_for( dura );
    *p = 19;
}

void startNewThread() 
{
    int *p = new int();
    *p = 10;
    cout << "Inside Main Thread : "" : *p = " << *p << endl;
    thread t(newThreadCallback,p);
    t.detach();
    delete p;
    p = NULL;
}

int main() 
{
    startNewThread();
    chrono::milliseconds dura ( 2000 );
    this_thread::sleep_for( dura );
    return 0;
}

Output: 

Inside Main Thread :  : *p = 10
Inside Thread :  : p = 1685523532

*************************************************************************

#include<iostream>
#include<thread>
using namespace std;
void threadCallback(int const &x)
{
    int & y = const_cast<int &>(x); 
    y++;
    cout << "Inside Thread x = " << x << endl;
}

int main()
{
    int x = 9;
    cout << "In Main Thread : Before Thread Start x = " << x << endl;
    thread threadObj(threadCallback,x);
    threadObj.join();
    cout << "In main Thread : After Thread Joins x = " << x << endl;
    return 0; 
}

***************************************************************************

#include<iostream>
#include<thread>
using namespace std;
void threadCallback(int const &x)
{
    int & y = const_cast<int &>(x); 
    y++;
    cout << "Inside Thread x = " << x << endl;
}

int main()
{
    int x = 9;
    cout << "In Main Thread : Before Thread Start x = " << x << endl;
    thread threadObj(threadCallback,ref(x));
    threadObj.join();
    cout << "In main Thread : After Thread Joins x = " << x << endl;
    return 0; 
}

******************************************************************************

#include<iostream>
#include<thread>
using namespace std; 
class DummyClass {
public:
DummyClass() 
{}
DummyClass(const DummyClass & obj)
{ }
void sampleMemberFunction(int x)
{
    cout << "Inside sampleMemberFunction " << x << endl; 
}
};
int main()
{
    DummyClass dummyObj;
    int x = 10;
    thread threadObj(&DummyClass::sampleMemberFunction,&dummyObj,x);
    threadObj.join();
    return 0;
}

********************************************************************************