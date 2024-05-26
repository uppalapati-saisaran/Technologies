Range-based for loops :

- Syntactic sugar for iterating over a container's elements.

  std::array<int, 5> a{1,2,3,4,5};
  for(int &x : a) x *=2;
  // a == {2,4,6,8,10}
  
- Note the difference when using int as opposed to int&:

  std::array<int,5> a {1,2,3,4,5};
  for(int x : a) x*=2;
  // a == {1,2,3,4,5}
  
  