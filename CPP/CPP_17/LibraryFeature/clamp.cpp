- Clamp given value between a lower and upper bound.

  std::clamp(42,-1,1);   // ==1
  std::clamp(-42,-1,1);  // == -1
  std::clamp(0,-1,1);  // == 0
  
  // std::clamp also accepts a custom comparator
  std::clamp(0,-1,1,std::less<>{});  // ==0 
  
  