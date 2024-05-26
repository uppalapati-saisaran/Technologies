#include<iostream>
#include<memory>
using namespace std;
int main() 
{
    shared_ptr<int> p1(new int());
    shared_ptr<int> p2 = p1;
    cout << "Reference Count :" << p1.use_count() << endl;
    cout << "Reference Count :" << p2.use_count() << endl; 
    return 0; 
}

******************************************************************

#include<memory>
#include<iostream>
using namespace std;

class Message 
{
    public:
        void getText() const
        {
            cout << "Some Random Text!! \n"; 
        }
};

int main() 
{
    shared_ptr<Message> msgPtr = make_shared<Message>();
    // Derference the shared_ptr to call a function on the Message object
    (*msgPtr).getText();
	msgPtr->getText(); 
}

********************************************************************

#include<memory>
#include<iostream>
using namespace std;
class Message {
    
}; 
int main()
{
    shared_ptr<Message> ptr1 = make_shared<Message>();
    shared_ptr<Message> ptr2 = ptr1; // ptr2 now shares ownership with ptr 
    shared_ptr<Message> ptr3;
    if(ptr1 == ptr2)
    {
        cout << "ptr1 and ptr2 point to the same object." << endl;
    }
    if(ptr3 == nullptr)
        cout << "ptr3 is uninitialized and holds no object." <<  endl; 
    return 0;
}

**********************************************************************

#include<memory>
#include<iostream>
using namespace std;
class Message {
    
}; 
int main()
{
    shared_ptr<Message> ptr1 = make_shared<Message>();
    shared_ptr<Message> ptr2 = ptr1; // ptr2 now shares ownership with ptr 
    shared_ptr<Message> ptr3;
    if(ptr1 == ptr2)
    {
        cout << "ptr1 and ptr2 point to the same object." << endl;
    }
    if(ptr3 == nullptr)
        cout << "ptr3 is uninitialized and holds no object." <<  endl; 
        
    cout << "ptr1 reference count :" << ptr1.use_count() << endl;
    cout << "ptr2 reference count :" << ptr2.use_count() << endl;
    
    ptr1.reset(); 
    
    cout << "ptr1 reference count :" << ptr1.use_count() << endl;
    cout << "ptr2 reference count :" << ptr2.use_count() << endl;
    
    if(!ptr1)
    {
        cout << "ptr1 is null" << endl; 
    }
    
    
    return 0;
}

*****************************************************************************

#include<iostream>
#include<memory>
using namespace std;

struct Sample {
    Sample() {
        cout << "Sample Constructor\n";
    }
    ~Sample() {
        cout << "Sample Destructor\n"; 
    }
};

//Function that calls 'delete[]' on the received pointer
void deleter(Sample* x) {
    cout << "Custom DELETER FUNCTION CALLED" << endl;  
    delete[] x; 
}

int main() 
{
    // Creating a shared_ptr with custom deleter
    shared_ptr<Sample> p3(new Sample[12], deleter);
	or
	shared_ptr<Sample> p4(new Sample[12], [](Sample *x) {
			                               cout << "Lamba Function DELETE"
										   delete[] x 
	}); 
	
	
	
    return 0; 
}

*****************************************************************************