##include<iostream>
#include<thread>
#include<algorithm>
#include<vector>
using namespace std; 
class WorkerThreadFunctor
{
    public:
        void operator()()
        {
            cout << "Worker Thread" << this_thread::get_id() << endl;
        }
};

int main() 
{
    //Create a vector of Thread
    vector<thread> threadList;
    
    // Add 10 thread objects in vector
    for(int i=0;i<10;i++)
    {
        threadList.push_back(std::thread(WorkerThreadFunctor() ) ); 
    }
    
    cout << "Wait for all the worker thread to finish" << endl;
    
    for(auto& th: threadList) 
    {
        th.join();
    }
    
    cout << "Existing from Main Thread" << endl;
    return 0; 
}

https://thispointer.com/c11-multithreading-part-2-joining-and-detaching-threads/

****************************************************************************************

#include<iostream>
#include<thread>
using namespace std;
class ThreadRAII
{
    std::thread & m_thread;
    public:
    ThreadRAII(thread & threadObj) : m_thread(threadObj)
    {
        
    }
    ~ThreadRAII()
    {
        //Check if thread is joinable then 
        //detach the thread
        if(m_thread.joinable())
        {
            m_thread.detach();
        }
    }
}; 

void thread_function()
{
    for(int i = 0;i < 5; i++)
    {
        cout << "thread_function Executing" << endl;
    }
}

int main() 
{
    thread threadObj(thread_function);
    
    //If we comment this Line, the program will crash
    ThreadRAII wrapperObj(threadObj);
    return 0;
}

******************************************************************************************