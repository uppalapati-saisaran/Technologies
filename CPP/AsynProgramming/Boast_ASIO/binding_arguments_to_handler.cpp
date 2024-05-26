#include<boost/asio.hpp>
#include<boost/bind/bind.hpp>
#include<iostream>
#include<thread> 
using namespace std; 
void print(const boost::system::error_code& /*e*/,boost::asio::steady_timer* t,int* count) 
{
    cout << "Print Thread id Start :" << this_thread::get_id() << endl; 
    if(*count < 5)
    {
        cout << *count << endl;
        ++(*count);
        t->expires_at(t->expiry() + boost::asio::chrono::seconds(1)); 
        t->async_wait(bind(print,boost::asio::placeholders::error,t,count));
    }
    cout << "Print Thread id  End :" << this_thread::get_id() << endl; 
}
int main() 
{
    boost::asio::io_context io;
    int count = 0;
    boost::asio::steady_timer t(io,boost::asio::chrono::seconds(1)); 
    cout << "Main Thread id Start : " << this_thread::get_id() << endl; 
    t.async_wait(bind(print,boost::asio::placeholders::error,&t,&count));
    cout << "Main Thread id End :" << this_thread::get_id() << endl; 
    io.run();
    return 0; 
}

Output: 

Main Thread id Start : 139979569346368
Main Thread id End :139979569346368
Print Thread id Start :139979569346368
0
Print Thread id  End :139979569346368
Print Thread id Start :139979569346368
1
Print Thread id  End :139979569346368
Print Thread id Start :139979569346368
2
Print Thread id  End :139979569346368
Print Thread id Start :139979569346368
3
Print Thread id  End :139979569346368
Print Thread id Start :139979569346368
4
Print Thread id  End :139979569346368
Print Thread id Start :139979569346368
Print Thread id  End :139979569346368