#include<ctime>
#include<iostream>
#include<string>
#include<boost/asio.hpp>
using namespace std;
using boost::asio::ip::tcp;

// define the function make_daytime_string()
// to create the string to be sent back to the client.
// This function will be used in all our daytime server applications.
std::string make_daytime_string() 
{
    using namespace std; // for time_t, time and ctime
    time_t now = time(0);
    return ctime(&now); 
}

int main() 
{
     try 
     {
         boost::asio::io_context io_context;
         // ip::tcp::acceptor object needs to be created to listen for new connections.
         // It is intialized to listen on TCP port 13, for IP version 4. 
         tcp::acceptor acceptor(io_context,tcp::endpoint(tcp::v4(),13));
     
         for(;;)
         {
             tcp::socket socket(io_context);
             acceptor.accept(socket);
             
             string message = make_daytime_string();
             boost::system::error_code ignored_error;
             boost::asio::write(socket,boost::asio::buffer(message),ignored_error);
         }
      }
      
      catch(exception& e)
      {
          cerr << e.what() << endl;
      }
      return 0; 
}