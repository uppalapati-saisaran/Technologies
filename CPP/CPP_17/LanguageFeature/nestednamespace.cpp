Nested namespaces:

- Using the namespace resolution operator to create nested namespace definitions.

  namespace A {
	namespace B {
	  namespace C {
		int i;
	}
	}
	}
	
- The code above can be written like this:

   namespace A::B::C {
   int i;
   }
   
   
	