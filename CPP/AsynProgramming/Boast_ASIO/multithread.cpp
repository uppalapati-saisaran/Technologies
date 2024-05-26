#include<iostream>
#include<boost/asio.hpp> 
#include<boost/bind/bind.hpp>
#include<boost/thread/thread.hpp>
#include<syncstream>
#include<chrono>
using namespace std;
// A class running two timers in parallel
class printer 
{
    public:
    // In addition to initialing a pair of boost::asio::steady_timer members
    /* the constructor initializes the strand_ member, 
    an object of type boost::asio::strand<boost::asio::io_context::executtor_type>.*/
    /*  strand class template is an executor adapter
        that guarantess that, for those handlers that are dispacthing through it
        an executing handler will be allowed to complete before the next one is started.
        This is guaranteed irrepective of the number of threads that are calling io_context.run()
        Ofcourse, the handlers may still execute concurrently with other handlers that were not
        dispatched through an strand or were dispacthed through a different strand object */
    printer(boost::asio::io_context& io) : 
          strand_(boost::asio::make_strand(io)),
          timer1_(io,boost::asio::chrono::seconds(1)),
          timer2_(io,boost::asio::chrono::seconds(1)),
          count_(0)
    {
        timer1_.async_wait(boost::asio::bind_executor(strand_,bind(&printer::print1, this)));
        timer2_.async_wait(boost::asio::bind_executor(strand_,bind(&printer::print2, this)));
    }
    ~ printer()
    {
        std::cout << "Final count is" << count_ << std::endl; 
    }
    /** In a multithreaded program, the handlers for asynchronous operations should be synchronised
     *  if they access shared resources
     */
     void print1()
     {
         if(count_ < 10) 
         {
             cout << "Timer 1: " << count_ << endl;
             ++count_;
             timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));
             timer1_.async_wait(boost::asio::bind_executor(strand_,bind(&printer::print1,this)));
         }
     }
     
     void print2()
     {
         //cout << "Thread Id of print2 :" << this_thread::get_id() << endl; 
         if(count_ < 10) 
         {
             cout << "Timer 2: " << count_ << endl;
             ++count_;
             timer2_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));
             timer2_.async_wait(boost::asio::bind_executor(strand_,bind(&printer::print2,this)));
         }
     }
  private:
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer timer1_;
    boost::asio::steady_timer timer2_;
    int count_;
}; 
int main() 
{
    boost::asio::io_context io;
    printer p(io);
    // The main function now causes io_context::run() to be called from two threads.
    // the main thread and one additional thread.
    // This is accompolished using an boost::thread object.
    // Just as it would with a class from a single thread, concurrent class to io_context::run() 
       // will continue to execute while there is work left to do.
    // The background thread will not exit until all synchronous operations have completed.
    thread t(boost::bind(&boost::asio::io_context::run, &io));
    io.run();
    t.join();
    return 0; 
}