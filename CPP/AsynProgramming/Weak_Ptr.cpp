#include<iostream>
#include<memory>
using namespace std;

int main() 
{
    shared_ptr<int> ptr = make_shared<int>(4);
    cout << "Reference count of ptr : " << ptr.use_count()  << endl;
    weak_ptr<int> weakPtr(ptr);
    cout << "Reference count of weak ptr : " << weakPtr.use_count()  << endl;
    shared_ptr<int> ptr_2 = weakPtr.lock();
    cout << "Reference count of ptr 2 : " << ptr_2.use_count()  << endl;
    ptr.reset(); 
    cout << "Reference count of ptr 2 : " << ptr_2.use_count()  << endl;
    cout << "Reference count of weak ptr : " << weakPtr.use_count()  << endl;
    cout << "Reference count of ptr : " << ptr.use_count()  << endl;
    if(weakPtr.expired() == false)
    {
        cout << "Not expired yet" << endl; 
    }
    return 0; 
}