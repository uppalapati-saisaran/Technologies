- C++ 14 introduces the [[deprecated]] attribute to indicate that
  a unit ( function, class, etc) is discouraged and likely yield
  compilation warnings. 
  
- If a reason is provide, it will be included in the warnings.

  [[depreciated]]
  void old_method();
  
  [[depreciated("Use new_method instead")]]
  void legacy_method();
  
  