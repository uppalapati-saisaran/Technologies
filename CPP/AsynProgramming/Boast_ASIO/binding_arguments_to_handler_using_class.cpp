#include<boost/asio.hpp>
#include<boost/bind/bind.hpp>
#include<iostream>
using namespace std;
class printer
{
    public:
    printer(boost::asio::io_context& io) : timer_(io,boost::asio::chrono::seconds(1)),count_(0) 
    {
        timer_.async_wait(boost::bind(&printer::print,this)); 
    }
    ~printer()
    {
        cout << "Final count is " << count_ << endl;
    }
    void print()
    {
        if(count_ < 5)
        {
            cout << count_ << endl;
            ++count_;
            timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
            timer_.async_wait(bind(&printer::print,this)); 
         }
    }
    private:
        boost::asio::steady_timer timer_;
        int count_;
    
};

int main() 
{
    boost::asio::io_context io;
    printer p(io);
    io.run();
    
    return 0; 
}

Output: 

0
1
2
3
4
Final count is 5

