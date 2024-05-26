- Type-safe enums that solve a variety of problems with C-style enums including :

  1, implicit conversions
  2, inability to specify the underlying type
  3, scope pollution
  
 //Specify underlying type as 'unsigned int'
 enum class Color : unsigned int { Red = 0xff0000, Green = 0xff00, Blue = 0xff };
 // 'Red'/'Green' in 'Alert' don't conflict with 'Color'
 enum class Alert : bool { Red, Green};
 Color c = Color::Red;
 
 
 