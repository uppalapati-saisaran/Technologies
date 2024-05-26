- std::make_shared is the recommended way to create instances of std::shared_ptr s due to the following reasons: 

(01) Avoid having to use the new operator.
(02) Prevents code repetition when specifying the underlying type the pointer shall hold.
(03) It provides exception-safety. Suppose we were calling a function foo like so:

	foo(std::shared_ptr<T>{new T{}}, function_that_throws(), std::shared_ptr<T>{new T{}});
	
- With std::make_shared,we are given exception-safety:

	foo(std::make_shared<T>{},function_that_throw(),std::make_shared<T>());
	       - Prevents having to do two allocations. 
		   - When calling std::shared_ptr{new T{}}, we have to allocate memory for T, then in the shared pointer 
		     we have to allocate memory for the control block within the pointer. 
			 
*****************************************************************************************************************

//make_shared example
#include<iostream>
#include<memory> 

int main() {
	
	std::shared_ptr<int> foo = std::make_shared<int>(10);
	// same as:
	std::shared_ptr<int> foo2 (new int(10));
	
	auto bar = std::make_shared<int>(20);
	
	auto baz = std::make_shared<std::pair<int,int>> (30,40);
	
	std::cout << "*foo: " << *foo << '\n';
	std::cout << "*bar: " << *bar << '\n';
	std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n';
	
	return 0;
}

*******************************************************************************************************************		 

https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170
// shared_ptr-examples.cpp 
// The following examples assume these declarations:
#include<algorithm>
#include<iostream>
#include<memory>
#include<string>
#include<vector>

struct MediaAsset 
{
	virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
	std::wstring artist;
	std::wstring title;
	Song(const std::wstring& artist_,const std::wstring& title_):
	     artist { artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
	std::wstring date;
	std::wstring locaion;
	std::wstring subject;
	Photo(const std::wstring& date_,const std::wstring& location_,const std::wstring subject_):
	date { date_ }, location { location_ }, subject { subject_ } {}
};

using namespace std;

int main() 
{

	//Use make_shared function when possible.
	auto sp1 = make_shared<Song>(L"The Beatles",L"Im Happy Just to Dance With You");
	
	//OK, but slightly less efficient
	// Note: Using new expression as constructor argument
	// creates no named variable for other code to access
	shared_ptr<Song> sp2(new Song(L"Lady Gaga",L"Just Dance"));
	
	//When initialization must be separate from declaration, e.g, class members,
	// initialize with nullptr to make your programming intent explicit.
	shared_ptr<Song> sp5(nullptr);
	// Equivalent to: shared_ptr<Song> sp5;
	
	sp5 = make_shared<Song>(L"Elton John",L"I'm Still Standing");
	
	//Initialize with copy constructor. Increment ref count.
	auto sp3(sp2);
	
	//Initialize via assignment. Increments ref count.
	auto sp4 = sp2;
	
	//Initialize with nullptr. sp7 is empty.
	shared_ptr<Song> sp7(nullptr);
	
	//Initialize with another shared_ptr. sp1 and sp2
	// swap pointers as well as ref counts.
	sp1.swap(sp2);
	
	vector<shared_ptr<Song>> v {
		make_shared<Song>(L"Bob Dylan",L"The Times They Are a Changing"),
		make_shared<Song>(L"Aretha Franklin",L"Bridge Over Troubled Water"),
		make_shared<Song>(L"Thalia",L"Entre E1 Mar Ya Una Estrella")
	};
	
	vector<shared_ptr<Song>> v2;
	remove_copy_if(v.begin,v.end(),back_inserter(v2),[] (shared_ptr<Song> s)
	{
		return s->artist.compare(L"Bob Dylan") == 0; 
	});
	
	for(const auto& s : v2)
	{
		wcout << s->artist << L":" << s->title << endl;
	}
     
	vector<shared_ptr<MediaAsset>> assets {
		make_shared<Song>(L"Himesh Reshammiya",L"Tera Surroor"),
		make_shared<Song>(L"Penaz Masani",L"Tu Dil De De"),
		make_shared<Photo>(L"2011-04-06:,L"Redmount, WA",L"Soccer field at Microsoft.")
		
	
	vector<shared_ptr<MediaAsset>> photos;
	
	copy_if(assets.begin(),assets.end(),back_inserter(photos),[](shared_ptr<MediaAsset> p -> bool
	{
		// Use dynamic_pointer_cast to test whether
		// element is a shared_ptr<Photo>.
		shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
		return temp.get() != nullptr;
	});
	
	for(const auto& p : photos)
	{
		// We know that the photos vector contains only
		// shared_ptr<Photo> objects, so use static_cast
		wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl; 
	}
	
	https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170

	
	void use_shared_ptr_by_value(shared_ptr<int> sp);
	
	void use_shared_ptr_by_reference(shared_ptr<int>& sp);
	void use_shared_ptr_by_const_reference(const shared_ptr<int>& sp);
	
	void use_raw_pointer(int *);
	void use_reference(int& r);
	
	void test() {
		auto sp = make_shared<int>(5);
		
		//Pass the shared_ptr by value.
		//This invokes the copy constructor, increments the reference count, and makes the callee an owner.
		use_shared_ptr_by_value(sp);
		
		//Pass the shared_ptr by reference or const reference.
		//In this case, the reference count isn't incremented.
		use_shared_ptr_by_reference(sp);
		use_shared_ptr_by_const_reference(sp);
		
		//Pass the underlying pointer or a reference to the underlying object.
		use_raw_pointer(sp.get());
		use_reference(*sp);
		
		//Pass the shared_ptr by value
		// This invokes the move constructor, which doesn't increment the reference count
		// but in fact transfers ownership to the callee
		use_shared_ptr_by_value(move(sp)); 
	}
	
	
	//Initialize two separate raw pointers.
	//Note that they contain the same values.
	auto song1 = new Song(L"Village People",L"YMCA");
	auto song2 = new Song(L"Village People",L"YMCA");
	
	//Create two unrelated shared_ptrs
	shared_ptr<Song> p1(song1);
	shared_ptr<Song> p2(song2);
	
	
	//Unrelated shared_ptrs are never equal
	wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
	wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;
	
	//Related shared_ptr instances are always equal.
	shared_ptr<Song> p2(p2);
	wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
}

