#include<boost/asio.hpp>
#include<cstdlib>
#include<iostream> 
#include<utility>
using namespace std;

using boost::asio::ip::tcp; 

class server
{
public: 
    server(boost::asio::io_context& io_context, short port)
         : acceptor_(io_context,tcp::endpoint(tcp::v4(),port)) 
        {
            do_accept();   
        }
private:
    void do_accept()
    {
        acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket)  
            {
                if(!ec) 
                {
                    //make_shared<session>(std::move(socket))->start();
                }
                do_accept(); 
            }); 
    };
    tcp::acceptor acceptor_; 
}; 
int main(int argc,char* argv[])
{
    try 
    {
        if(argc!=2)
        {
            cerr << "Usage: server <port>\n";
            return 1;
        }
        boost::asio::io_context io_con;
        server s(io_con,atoi(argv[1])); 
    }
    catch(exception& e) 
    {
        cerr << "Exception: " << e.what() << "\n"; 
    }
}