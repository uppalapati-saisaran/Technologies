
https://www.boost.org/doc/libs/1_75_0/doc/html/boost_asio/example/cpp03/allocation/server.cpp 

#include<iostream>
#include<boost/asio.hpp>
#include<boost/enable_shared_from_this.hpp>
using namespace std;

using boost::asio::ip::tcp; 

class session : public boost::enable_shared_from_this<session>
{
  public:
    session(boost::asio::io_context& io_context) : socket_(io_context)
    {
        
    }
    tcp::socket& socket()
    {
        return socket_;
    }
    
    void start() 
    {
        socket_.async_read_some(boost::asoio::buffer(data_), make_custom_alloc_handler(handler_memory_,boost::bind(&session::handle_read,shared_from_this(),
        boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferrred));
    }
    
    
    
};


typedef boost::shared_ptr<session> session_ptr; 

class server 
{
    public:
    server(boost::asio::io_context& io_context,short port)
    : io_context_(io_context),
      acceptor_(io_context, tcp::endpoint(tcp::v4(),port)) 
    {
        session_ptr new_session(new session(io_context_));
        acceptor_.async_accept(new_session->socket(), 
                                boost::bind(&server::handle_accept,this,new_session,boost::asio::placeholders::error));
    }
    void handle_accept(session_ptr new_session,const boost::system::error_code& error)
    {
        if(!error)
        {
            new_session->start(); 
        }
        new_session.reset(new session(io_context_));
        acceptor_.async_accept(new_session->socket(), boost::bind(&server::handle_accept,this,new_session,boost::asio::placeholders::error));
    }
    private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_; 
};

int main(int argc,char *argv[])
{
    try
    {
        if(argc!=2)
        {
            cerr << "Usage: server <port>\n";
            return 1;
        }
        boost::asio::io_context io_ctx;
        
        server s(io_context,atoi(argv[1]));
        
        io_ctx.run(); 
    }
    catch(exception& e)
    {
        cerr << "Exception :" << e.what() << "\n"; 
    }
    return 0;
}

                                                                                                                                                     