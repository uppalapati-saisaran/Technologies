#include<future>
#include<iostream>
using namespace std;

void initializer(std::promise<int> * promoObj)
{
    cout << "Inside Thread" << endl; 
    promoObj->set_value(35); 
}

int main()
{
    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();
    thread th(initializer,&promiseObj); 
    cout << futureObj.get() << endl;
    th.join();
    return 0;
}

*********************************************************