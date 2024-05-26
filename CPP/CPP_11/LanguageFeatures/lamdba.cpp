- A lamba is an unnamed function object capable of capturing variables in scope.

- It features: a capture list; an optional set of parameters with an optional trailing return type; and a body.

- Examples of capture lists:

 [] - captures nothing
 [=] - capture local objects (local varaibles, parameters) in scope by value.
 [&] - capture local objects (local variables, parameters) in scope by reference.
 [this] - capture this by reference
 [a, &b] - capture objects a by value, b by reference.
 
- 
   int x = 1;
   auto f1 = [&x] { x = 2; }; // Ok: x is a reference and modifies the original
   
   auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value.
   // vs.
   auto f3 = [x]() mutable { x = 2; }; // Ok: the lamdba can perform any operations on the captured value.
   
   
   