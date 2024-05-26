
// Option 1: 

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
class Application 
{
    mutex m_mutex;
    bool m_bDataLoaded;
public:
    Application()
    {
        m_bDataLoaded = false;
    }
    void loadData()
    {
         //Make This thread sleep for 1 second
         this_thread::sleep_for(chrono::milliseconds(1000));
         cout << "Loading Data from XML" << endl;
         
         //Lock The Data structure
         lock_guard<mutex> guard(m_mutex);
         
         // Set the flag to true, means data is Loaded
         m_bDataLoaded = true;
    }
    
    void mainTask() 
    {
        cout << "Do Some Handshanking" << endl;
        
        // Acquire the lock
        m_mutex.lock();
        
        //Check if flag is set to true or not
        while(m_bDataLoaded != true)
        {
          //Release the lock
          m_mutex.unlock();
          //sleep for 100 milliseconds
          this_thread::sleep_for(chrono::milliseconds(100));
          // Acquire the lock
          m_mutex.lock();
        }
        // Release the lock
        m_mutex.unlock(); 
        
        //Doc processing on loaded data
        cout << "Do processing on loaded Data" << endl;
    }
};


int main() 
{
    Application app;
    thread thread_1(&Application::mainTask, &app);
    thread thread_2(&Application::loadData, &app);
    
    thread_2.join();
    thread_1.join();
    
    return 0;
}


************************************************************************************

// Option 2:

#include<condition_variable>
#include<functional>
#include<iostream>
#include<thread>
using namespace std;
class Application
{
   mutex m_mutex; 
   condition_variable m_condVar;
   bool m_bDataLoaded;
   public:
   Application()
   {
       m_bDataLoaded = false; 
   }
   bool isDataLoaded()
   {
       return m_bDataLoaded;
   }
   void mainTask() 
   {
       cout << "Do some Handshaking " << endl;
       //Acquire the lock
       unique_lock<mutex> mlock(m_mutex); 
       // Start waiting for the condition variable to get
       // signaled wait() will interanllly release the 
       // lock and make the thread to block 
       // As soon as condition variable get signaled,
       // resume the thread and again acquire the Lock.
       // Then check if condition is met or not
       // If condition is met thatn continue else again go in wait.
       m_condVar.wait(mlock,bind(&Application::isDataLoaded, this)); 
       cout << "Do Procssing On loaded Data" << endl; 
    }
    void loadData()
    {
        // Make this thread sleep for 1 second
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Loading Data from XML" << std::endl;
        
        //Lock the data structure
        lock_guard<mutex> guard(m_mutex);
        //set the flag to true, means data is loaded
        m_bDataLoaded = true;
        // Notify the condition variable
        m_condVar.notify_one();
   }

};
int main() 
{
    Application app;
    thread thread_1(&Application::mainTask, &app);
    thread thread_2(&Application::loadData, &app); 
    thread_2.join();
    thread_1.join(); 
    return 0;
}

https://thispointer.com//c11-multithreading-part-7-condition-variables-explained/


********************************************************************************************