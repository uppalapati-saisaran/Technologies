- The class template std::integer_sequence represents a compile-time sequence of integers.

- There are a few helpers built on top:
      
	  * std::make_integer_sequence<T,N> - creates a sequence of 0, ..., N - 1 with type T.
	  * std::index_sequence_for<T...> - converts a template parameter pack into an integer sequence.
	  
- Convert an array into a tuple:

  template<typename Array,std::size_t... I>
  decltype(auto) a2t_impl(const Array& a,std::integer_sequence<std::size_t,I...>) {
     return std::make_tuple(a[I]...);
  }
  
  template<typename T,std::size_t N, typename Indices = std::make_index_sequence<N>>
  decltype(auto) a2t(const std::array<T,N>& a) {
	  return a2t_impl(a,Indices());
  } 

/*********************************************************************************************/
  
#include<iostream>
#include<utility>
using namespace std;

template<typename T, T... Is>
void print_sequence(integer_sequence<T,Is...>)
{
    cout << "The sequence is: ";
    ((cout << Is << ' '),...);  // fold expression to print sequence
}

int main() 
{
    print_sequence(integer_sequence<int,1,2,3,4>{});
    return 0; 
}

Output :

The sequence is: 1 2 3 4

/*******************************************************************************************/


#include<iostream>
#include<utility>
using namespace std;

// Struct to calculate the size of an integer_sequence
template<typename T,T... Ints>
struct integer_sequence_size;


// Partical specialization for a integer_sequence with at 
// least one element 
template<typename T, T Head, T... Tail>
struct integer_sequence_size<T, Head, Tail...> {
    static constexpr size_t value = 1 + integer_sequence_size<T,Tail...>::value;
};

// Specialization for an empty integer_sequence 
template<typename T> struct integer_sequence_size<T> {
    static constexpr size_t value = 0;
};

int main() 
{
    // Define an integer_sequence
    using my_sequence = integer_sequence<int,0,1,2,3,4>;
    
    //Print the size of the integer_sequence using the custom struct.
    std::cout 
        << "Size of custom struct: "
        << integer_sequence_size<int,0,1,2,3,4>::value 
        << endl;
    // Output: Size: 5
    
    //Print the size of the integer_sequence using the empty struct.
    std::cout 
        << "Size of empty struct: "
        << integer_sequence_size<int>::value
        << endl; 
    return 0; 
}