- New user-defined literals for standard library types, including new built-in literals for 
         * chrono
		 * basic_string.
		 
- These can be constexpr meaning they can be used at compile-time.

- Some uses for these literals include 
         * compile-time integer parsing
		 * binary literals
		 * imaginary number literals.
		 
using namespace std::chrono_literals;
auto day = 24h;
day.count(); // == 24
std::chrono::duration_cast<std::chrono::minutes>(day).count(); // ==1440

#include<iostream>
#include<chrono>
using namespace std; 
int main()
{
    using namespace std::chrono_literals;
    auto day = 24h;
    day.count(); // 24 
    cout << "Number of days : " << day.count() << endl; 
    cout << "Number of minutes : " << std::chrono::duration_cast<std::chrono::minutes>(day).count();  
    return 0;
}






