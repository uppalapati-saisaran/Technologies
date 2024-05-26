#include<memory>
using namespace std; 
int main()
{
    unique_ptr<int> ptrObj(nullptr);
    // Later in the code
    ptrObj.reset(new int());  // Now managing a new int object 
    
}

********************************************************************

#include<iostream>
#include<memory>
using namespace std; 
int main() 
{
    unique_ptr<int> intPtr(new int(4));
    
    //Assigning value to the managed integer
    *intPtr = 42;
    
    //Dereferencing to print the value
    cout << *intPtr << endl; 
    
    // To obtain the raw pointer for some operations
    // Especially with APIs that require raw pointers, unique_ptr provides a get() method
    
    int *rawIntPtr = intPtr.get(); // Acquires the raw pointer
    // Remember: don't use rawIntPtr for memory management. 
}

***********************************************************************

#include<memory>
#include<string>
#include<iostream>
using namespace std; 
class Tweet{
private:    
     string text; // The content of the Tweet
     int viewCount; // Number of times the tweet has been viewed.
     int likeCount; // Number of likes on the tweet.
public:
    // Constructor to initialize the tweet object with text, view count,
    // and like count 
    Tweet(const string &txt, int views, int likes)
    : text(txt), viewCount(views), likeCount(likes)
    {
        cout << "**** Tweet::Constructor ****\n";
    }
    
    //Display function to print the details of the Tweet
    void display() const
    {
        cout << "Tweet :" << text << "\n";
        cout << "Views :" << viewCount << "\n";
        cout << "Likes :" << likeCount << "\n";
    }
    
    ~Tweet()
    {
        cout << "****  Tweet::Destructor ***\n"; 
    }
    
}; 
int main() 
{
    //Wrapping the raw pointer with a unique_ptr
    // unique_ptr now exclusively manages the Tweet
    unique_ptr<Tweet> tweetPtr(new Tweet("Good Morning", 2000, 31));
    tweetPtr->display();
    return 0; 
}

**********************************************************************************

#include<iostream>
#include<memory>
using namespace std; 
int main() 
{
    // ptr is managing a new int with value 11
    unique_ptr<int> ptr(new int(11));
    
    //Move ptr to another unique_ptr
    unique_ptr<int> anotherPtr = move(ptr);
    
    // ptr is now empty, and anotherPtr manages the resource
    if(!ptr) 
    {
        cout << "ptr is now nullptr" << endl; 
    }
    
    if(anotherPtr)
    {
        cout << "anotherPtr points to memory with value: " << *anotherPtr << endl; 
    }
 }
 
***********************************************************************************

#include<iostream>
#include<memory>
using namespace std; 
int main() 
{
    // ptr is managing a new int with value 11
    unique_ptr<int> ptr(new int(11));
    
    //Resetting the uniquePtr 
    ptr.reset(); 
    
    // AFter reset, ptr no longer owns the previous int
    if(!ptr) 
    {
        cout << "ptr has been reset and is now nullptr" << endl; 
    }
    
    return 0;
 }
 
**********************************************************************************

#include<iostream>
#include<memory>
using namespace std;
unique_ptr<int> GetData1(int value)
{
    unique_ptr<int> ptr = make_unique<int>(value);
    // unique_ptr is moved from here
    return ptr;
}

unique_ptr<int> GetData2(int value)
{
    return make_unique<int>(value); 
}

int main()
{
    unique_ptr<int> uniquePtr1 = GetData1(42);
    unique_ptr<int> uniquePtr2 = GetData2(42); 
    
    return 0; 
}

*********************************************************************************


#include<iostream>
#include<memory>
using namespace std; 
int main() 
{
    auto arr = unique_ptr<int[]>(new int[6]{67,78,16,26,98,63});
    
    //Use the unique pointer array 
    for(int i = 0; i< 6; ++i) 
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}


*********************************************************************************

