[[likely]] and [[unlikely]] attributes:

- Provides a hint to the optimizer that the labelled statement has a high probability of being executed.

  swich(n) {
  case 1:
   // ...
   break;
  [[likely]] case 2:  // n == 2 is considered to be arbitrarily more
  // ...              // likely than any other value of n.
  break;
  }
  
- If one of the likely/unlikely attributes appears after the right parenthesis of an if-statement, it indicates that the 
  branch is likely/unlikely to have its substatement(body) executed.
  
  int random = get_random_number_between_x_and_y(0,3);
  if(random > 0) [[ likely ]] {
  // body if if statement
 // ..
 }
 
- It can also be applied to the substatement (body) of an iteration statement. 

  while(unlikey_truthy_condition) [[unlikely]] {
  // body of while statement
  // ...
  }
  