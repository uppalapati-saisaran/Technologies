Designated initializers :

- C-style designated initializer syntax.

- Any member fields that are not explicitly listed in the  designated initializer list are default initialized. 

struct A {
	int x;
	int y;
	int z=123;
	};
	A a{.x = 1,.z = 2};  // a.x == 1, a.y == 0, a.z == 2
	
	