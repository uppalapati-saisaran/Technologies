- std::begin and std::end free functions were added to return begin and end iterators of a container generically.

- These functions also work with raw arrays which do not have begin and end member funtions.

	#include<iostream>
	#include<vector>
	#include<algorithm>
	using namespace std;
	  template<typename T>
	  int CountTwos(const T& container) {
		return std::count_if(std::begin(container),std::end(container),[](int item) {
			return item == 2;
			}); 
	   }
	int main()
	{
	   std::vector<int> vec={2,2,43,435,4543,534};
	   int arr[8] = {2,43,45,435,32,32,32,32};
	   auto a = CountTwos(vec); // 2
	   auto b = CountTwos(arr); // 1
	   cout << "Element 2 found " << a << " times in the vector" << endl;
	   cout << "Element 2 found " << b << " times in the array" << endl; 
	}  
   
   