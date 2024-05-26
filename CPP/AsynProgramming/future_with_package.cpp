
// Creating std::packaged_task<> object
#include<future>
#include<iostream>
using namespace std;
// Fetch some data from DB
string getDataFromDB(string token)
{
    // Do some stuff to fetch the data 
    string data = "Data fetched from DB by Filter ::" + token;
    return data;
}
int main() 
{
    //create a packaged_task<> that encapsulated the callback i.e. function
    packaged_task<string(string)> task(getDataFromDB); 
    
    //Fetch the associated future<> from package_task<>
    future<string> result = task.get_future();
    
    //Pass the package_task to thread to run asynchronously
    thread th(move(task),"Arg");
    
    //Join the thread. Its block and returns when thread is finished
    th.join(); 
    
    //Fetch the result of packaged_task<> i.e, value returned by getDataFromBD
    string data = result.get();
    
    cout << data << endl;
    
    return 0;
}


https://thispointer.com/c11-multithreading-part-10-packaged_task-example-and-tutorial/

// Creating packaged_task with Lambda Function 


#include<future>
#include<iostream>
using namespace std;
int main() 
{
    //create a packaged_task<> that encapsulated a lamdba function
    packaged_task<string (string)> task([](std::string token) {
        //Do some stuff to fetch the data
        string data = "Data From " + token;
        return data;
    });
    
    //Fetch the associated future<> from packaged_task<>
    future<string> result = task.get_future();
    
    //Pass the packaged_task to thread to run asynchronously
    thread th(move(task),"Arg");
    
    //Join the thread. Its blocking and returns when thread is finished.
    th.join();
    
    //Fetch the result of packaged_task<> i.e., value returned by getDataFromDB
    string data = result.get();
    
    cout << data << endl;
    
    return 0; 
} 

// Creating packaged_task with function object  

#include<future>
#include<iostream>
#include<string>
using namespace std; 
/*
 * Function object to Fetch Data from DB 
 */

struct DBDataFetcher
{
   string operator()(string token)
   {
      // Do some stuff to fetch the Data
      string data = "Data From " + token;
      return data;
   }
}; 


using namespace std;
int main() 
{
    //create a packaged_task<> that encapsulated a function object
    packaged_task<string (string)> task(move(DBDataFetcher()));
    
    //Fetch the associated future<> from packaged_task<>
    future<string> result = task.get_future();
    
    //pass the packaged_task to thread to run asynchronously
    thread th(move(task),"Arg"); 
    
    //join the thread. Its blocking and returns when thread is finished.
    th.join();
    
    //Fetch the result of packaged_task<> i.e value returned by getDataFromDB
    string data = result.get();
    
    cout << data << endl;
}