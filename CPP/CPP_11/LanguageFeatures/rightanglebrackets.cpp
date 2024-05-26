Right angle brackets:

- C++ 11 is now able to infer when a series of right angle brackets
  is used as an operator or as a closing statement of typedef,
  without having to add whitespace.
  
  typedef std::map<int, std::map<int, std::map <int,int> > > cpp98LongTypedef;
  typedef std::map<int, std::map<int, std::map <int,int>>> cpp11LongTypedefl 
  
  
  