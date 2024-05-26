Folding expressions:

- A fold expression performs a fold of a template parameter pack over a binary operator.

1, An expression of the form (... op e) or (e op ...), where op is a fold-operator and e is an unexpanded parameter pack, are called unary folds.

2, An expression of the form (e1 op ... op e2), where op are fold operations, is called a binary fold. 
   Either e1 or e2 is an unexpanded parameter pack, but not both.
   
   template<typename... Args>
   bool logicalAnd(Args... args) {
	// Binary folding.
	reutrn (true && ... && args);
	
   bool b = true;
   bool& b2 = b; 
   logicalAnd(b,b2,true); // == true

   template<typename... Args>
   auto sum(Args... args) {
	// Unary folding.
	return (... + args);
	}
	sum(1.0,2.0f,3); // == 6. 0 
	
	
	
   
