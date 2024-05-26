
Attributes: 

- Attributes provide a universal syntax over __attribute__(...), __declspec, etc.

  // 'noreturn' attribute indicates 'f' doesn't return.
  [[ no return ]] void f() {
  throw "error";
  }
  

  