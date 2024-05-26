chrono 

- The chrono library contains a set of utility functions and types that deal with durations, clocks, and time points.

- One use case of this library is benchmarking code:

std::chrono::time_point<std::chrono::steady_clock> start,end;
start = std::chrono::steady_clock::now();
// some computations...
end = std::chrono::steady_clock::now();

std::chrono::duration<double> elapsed_seconds = end - start;
double t = elapsed_seconds.count(); // t number of seconds, represented as a 'double'


*********************************************************************************************

// C++ program to illustrate the utility
// function duration::count 
#include<iostream>
#include<chrono>
int main() 
{
    using namespace std::chrono;
    // std::chrono::milliseconds in an 
    // instantiation of std::chrono::duration: -1 second 
    milliseconds mil(1000);
    mil = mil * 60;
    
    std::cout << "duration (in periods): ";
    std::cout << mil.count() << " milliseconds.\n";
    
    std::cout << "duration (in seconds): ";
    std::cout << (mil.count() * milliseconds::period::num/milliseconds::period::den);
    std::cout << " seconds.\n"; 
    
    return 0; 
}

*********************************************************************************************










