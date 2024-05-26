- invoke a callable object with parameters.

- Examples of callable objects are std::function or lambdas; objects that can be called similarly to a regular function.

  template<typename Callable>
  class Proxy {
	Callable c_;
	
  public:
	Proxy(Callable c) : c_{ std::move(c) } {}
	
	template<typename... Args>
	decltype(auto) operator()(Args&&... args) 
	{
	//...
	return std::invoke(c_,std::forward<Args>(args)...);
	}
  };
	
  const auto add = [](int x,int y) { return x+y; }
  Proxy p { add };
  p(1,2); // == 3
  
  