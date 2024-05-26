#include<iostream>
#include<boost/array.hpp>
#include<boost/asio.hpp> 
using namespace std;

using boost::asio::ip::tcp;

int main(int argc,char *argv[])
{
    try
    {
        if(argc!=2)
        {
            cerr << "Usage: client <host>" << std::endl;
            return 1; 
        }
        //All programs that use asio need to have at least one I/O execution context.
        boost::asio::io_context io_context;
        
        // To turn the server name that was specified as a parameter to the application, into a TCP endpoint.
        // To do this we use an ip::tcp::resolver object.
        tcp::resolver resolver(io_context);
        
        
        // resolver takes a hostname and service name and turns them into a list of endpoints.
        // resolve call using the name of server,specified in argv[1] and the name of the service,in this case "daytime"
        // The list of endpoints is returned using an object of type ip::tcp::resolver::results_type
        // This object is range, with begin() and end() member functions that may be used for iterating over the results.
        tcp::resolver::results_type endpoints = resolver.resolve(argv[1],"daytime");
        
        // create and connect to socket.
        // list of endpoints obtained above may contain both IPV4 and IPV6 endpoints,
           // so we need to try each of them until we find one that works.
        // This keeps the client program independent of a specific IP version.
        // The boost::asio::connect() function does this for us automatically.
        tcp::socket socket(io_context);
        boost::asio::connect(socket,endpoints);
        // The connection is open. All we need do now is read the response from the daytime service.
        
        for(;;)
        {
            // boost::array to hold received data.
            boost::array<char,128> buf;
            boost::system::error_code error;
            // boost::asio::buffer() function automatically determines the size of the 
               // array to help prevent buffer overruns.
            // Instead of a boost::array, we could have used a char[] or std::vector.
            size_t len = socket.read_some(boost::asio::buffer(buf),error); 
            
            // When the server closes the connection, 
            // the ip::tcp::socket::read_some() function will exit with boost::asio::error::eof error,
            // which is how we know to exit the loop. 
            if(error == boost::asio::error::eof)
                break;  // Connection closed cleanly by peer.
            else if(error)
                throw boost::system::system_error(error); // Some other error
            
            cout.write(buf.data(),len);
         }
    } catch(std::exception& e)
    {
        cerr << e.what() << std::endl; 
    }
}