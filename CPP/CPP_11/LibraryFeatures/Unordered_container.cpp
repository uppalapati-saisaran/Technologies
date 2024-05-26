
- Unordered containers maintain average constant-time complexity for 
      (01) search 
	  (02) insert
	  (03) remove 
	  
- In order to achieve constant-time complexity, sacrifies order for speed by hashing elements into buckets.

- Four unordered containers:
    (01) unordered_set (02) unordered_multiset (03) unordered_map (04) unordered_multimap
	
**********************************************************************************************
	
// C++ program to demostrate various function of unordered_set
#include<bits/stdc++.h>
using namespace std;

int main()
	{
		// declaring set for storing string data-type
		unordered_set<string> stringSet;
		
		// inserting various string, same string will be stored once in set
		stringSet.insert("code");
		stringSet.insert("in");
		stringSet.insert("C++");
		stringSet.insert("is");
		stringSet.insert("fast");
		
		string key="slow";
		
		// find returns end iterator if key is not found,
		// else it returns iterator to that key
		
		if(stringSet.find(key) == stringSet.end())
			cout << key << " not found" << endl << endl;
		else
			cout << "Found " << key << endl << endl;
		
		//now iterating over whole set and printing its content
		
		cout << "\nAll elements : ";
		unordered_set<string>::iterator itr;
		for(itr=stringSet.begin();itr!=stringSet.end();itr++)
			cout << (*itr) << endl;
    }
	
**********************************************************************************************

// C++ program to demostrate functionality of unordered_map
#include<iostream>
#include<unordered_map>
using namespace std;
int main() 
{
	//Declaring umap to be of <string,int>, they key will be of STRING type 
	//and mapped VALUE will be of int type
	unordered_map<string, int> umap;
	
	//inserting values by using [] operator
	umap["GeeksforGeeks"] = 10;
	umap["Pratice"] = 20;
	umap["Contributes"] = 30;
	
	// Traversing an unordered map
	for (auto x : umap)
		cout << x.first << " " << x.second << endl;
}

********************************************************************************************

https://www.geeksforgeeks.org/unordered_multimap-and-its-application/
// C++ program to demostrate various function of unordered_multimap
#include<bits/stdc++.h>
using namespace std;

//making typedef for short declaration
typedef unordered_multimap<string,int>::iterator unit;

//Utility function to print unordered_multimap
void printUmm(unordered_multimap<string, int> umm)
{
	//begin() returns iterator to first element of map
	unit it = umm.begin();
	for(; it != umm.end(); it++) {
		cout << "<" << it->first << ", " << it->second << "> ";
		cout << endl;
	}
}

int main() 
{
	//empty initialization
	unordered_multimap<string, int> umm1;
	
	//Initialization by initializer list
	unordered_multimap<string, int> umm2( 
	{ 
	{ "apple",1 }, {"ball",2},{"apple",10},{"cat,7},{"dog",9},{"cat",6},{"apple", 1}}); 
	
	//Initialization by assignment operation
	umm1 = umm2;
	printUmm(umm1);
	
	//empty returns true, if container is empty else it
	// returns false
	if(umm2.empty())
		cout << "unordered multimap 2 is empty\n";
	else
		cout << "unordered multimap 2 is not empty\n";
	
	//size returns total number of elements in container
	cout << "Size of unordered multimap 1 is " << umm1.size() << endl;
	
	string key = "apple";
	
	//find and return any pair, associated with key
	unit it = umm1.find(key);
	if(it!=umm1.end()) {
		cout << "\nkey " << key << " is there in unordered " << " multimap 1\n";
		cout << "\nnone of the value associated with " << key << " is " << it->second << endl;
	}
	else
		cout << "\nkey " << key << " is not there in unordered" << " multimap 1\n";
	
	// ocunt returns count of total number of pair associated with key
	int cnt = umm1.count(key)
	cout << "\ntotal values associated with " << key << " are " << cnt << "\n\n";
	
	printUmm(umm2);
	
	// one insertion by making pair explictly.
	umm2.insert(make_pair("dog",11)); 
	
	// insertion by initializer list
	umm2.insert({ {"alpha",12 }, {"beta", 33 } });
    cout << "\nAfter insertion of <alpha, 12> and <beta, "
	        "33>\n";
	printUmm(umm2);
	
	// erase deletes all pairs corresponding to key 
	umm2.erase("apple"); 
	cout << "\nAfter deletion of apple\n";
	printUmm(umm2);
	
	//clear deletes all pairs from container 
	umm1.clear();
	umm2.clear();
	
	if(umm2.empty())
		cout << "\nunordered multimap 2 is empty\n";
	else
		cout << "\nunordered multimap 2 is not empty\n";
}

**********************************************************************************************************************

https://www.geeksforgeeks.org/multiset-in-cpp-stl/
	
// CPP program to demostrate the implementation of multiset
#include<iostream>
#include<iterator>
#include<set>

using namespace std;

int main()
{
    // empty multiset container
    multiset<int, greater<int> > gquiz1;
    
    //insert eleemnts in random order
    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);
    
    // 50 will be added again to 
    // the multiset unlike set
    gquiz1.insert(50);
    gquiz1.insert(10);
    
    //printing multiset gquiz1
    multiset<int, greater<int> >::iterator itr;
    cout << "\nThe multiset gquiz1 is : \n";
    for(itr = gquiz1.begin();itr!=gquiz1.end();++itr) {
        cout << *itr << " ";
    }
    
    cout << endl;
    
    // assigning the elements from gquiz1 and gquiz2
    multiset<int> gquiz2(gquiz1.begin(),gquiz1.end());
    
    //print all elments of the multiset gquiz2
    cout << "\nThe multiset gquiz2 \n"
            "after assign from gquiz1 is : \n";
    for(itr = gquiz2.begin();itr!=gquiz2.end();++itr) {
        cout << *itr << " "; 
    }    
            
    // remove all elements up to element with value 30 in gquiz2
    cout << "\nquiz2 after removal \n"
            "of elements less than 30: \n";
    gquiz2.erase(gquiz2.begin(),gquiz2.find(30));
    for(itr = gquiz2.begin();itr!=gquiz2.end();++itr) {
        cout << *itr << " "; 
    }
   
    // remove all elements with value 50 in gquiz2
    int num;
    num = gquiz2.erase(50);
    cout << "\ngquiz2.erase(50) : \n";
    cout << num << " removed \n";
    for(itr = gquiz2.begin();itr != gquiz2.end(); ++itr) {
        cout << *itr << " "; 
    }
    
    cout << endl;
    
    //lower bound and upper bound for multiset gquiz1
    cout << "\ngquiz1.lower_bound(40) : \n"
         << *gquiz1.lower_bound(40) << endl;
    cout << "\ngquiz1.upper_bound(40) : \n"
         << *gquiz1.upper_bound(40) << endl; 
    
    //lower bound and upper bound for multiset gquiz2
    cout << "\ngquiz2.lower_bound(40) : \n"
         << *gquiz2.lower_bound(40) << endl;
    cout << "\ngquiz2.upper_bound(40) : \n"
         << *gquiz2.upper_bound(40) << endl; 
    
    return 0;
}	
	
*************************************************************************************************************************


	

