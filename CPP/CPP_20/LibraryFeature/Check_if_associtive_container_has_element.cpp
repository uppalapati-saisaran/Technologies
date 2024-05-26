Check if associative container has element 

- Associative containers such as sets and maps have a contains member function, which can be used
  instead of the "find and check end of iterator" idiom.
  
  std::map<int,char> map {{1,'a'},{2,'b'}};
  map.contains(2); // true
  map.contains(123); // false
  
  std::set<int> set {1,2,3};
  set.contains(2) 
  
  
  