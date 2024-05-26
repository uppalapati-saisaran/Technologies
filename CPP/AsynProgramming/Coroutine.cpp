* Coroutine can be used to build useful high-level abstractions such as those provided by the cppcoro library.

* Coroutine is a generalisation of a function that allows the function to be suspended and then later resumed.

* Coroutines generalise the operation of a function by separing out some of the steps performed
  in the call and Return operations into three extra operations: Suspend, Resume and Destory.
  
* Suspend : - without destroying the activation frame. 
            - Any objects in scope at the point of suspension remain alive after the coroutin is suspended.
			- Coroutine can only be suspended from within the corotuine itself at well-defined suspend-points.
* Opposed to Suspend is Destroy. 

**************************************************************************************************************

                                         Function 
										 
**************************************************************************************************************


* What is activiation frame? 

- Block of memory that holds the current state of a particular invocation of a funtion.
- This state includes the values of any parameters that were passed to it and the values of any local variables.
- "Normal Function", the activation from also includes 
    (01) the return-address - the address of the instruction to transfer execution to upon returning from the function.
	(02) The address of the activation frame for the invocation of the calling function. 
- When an activiation from is allocated on this stack data structure it is oftne called a "stackframe"
- The stack data-structure is so common that most CPU architectures have a dedicated register for holding a pointer
  to the top of the stack. 
- To allocate space for a new activation frame, you just increment this register by the frame-size. 
  To free space for an activiation frame, you just decrement this register by the frame-size. 
  
* Call Operation 

- Depending on the calling convention of the function, the caller and callee may coordinate on who saves these register
  values, but you can still think of them as being performed as part of the call operation.
- The caller also stores the value of any parameters passed to the called function into the new activiation frame 
  where they can be accessed by the function.
- Finally, the caller writes the address of the resumption-point to the caller to the new activation frame and 
  transfers execution to the start of the called function. 
  
* Return Operation 

- The function first stores the return value where the caller can access it. This could either be in the caller's
  activation frame or the function's activiation frame. 

- Then the function destroys the activiation frame by : 
  (01) Destroying any local variables in scope at the return-point.
  (02) Destroying any parameter objects.
  (03) Freeing memory used by the activationn-frame.
  
- Any finally, it resumes execution of the caller by:
  (01) Restoring the activiation frame of the caller by setting the stack register to point to the activivation frame
       of the caller and restoring any registers that might have been clobbered by the function.
  (02) Jumping to the resume-point of the caller that was stored during the 'call operation'
  

*********************************************************************************************************************

                                        Coroutines

*********************************************************************************************************************

Activation frames :

- Since coroutines can be suspended without destroying the activiation frame, we can no longer guarantee that activiation
  from lifetimes will be strictly nested.
- This means that activation frames cannot in general be allocated using a stack data-structure and so may need to be
  stored on the heap instead.
- There are some provisions in the C++ coroutines TS to allow the memory for the coroutine frame to be allocated 
  from the activiation frame of the caller if the compiler can prove that the lifetime of the coroutine is indeed
  strictly nested within the lifetime of the caller. 
- With coroutines there are some parts of the activiation frame that need to be preserved across coroutine suspension 
  and there are some parts that only need to be kept around while the coroutine is executing. 
  Example : the lifetime of a variable with a scope that does not span any coroutine suspend-points can potentially
  be stored on the stack.
- you can logically think of the activation frame of a coroutine as being comprised of two parts: the coroutine frame and the stack frame
- The coroutine frame holds part of the coroutine's activiation frame that persists while the coroutine is suspended
  and the stack frame part only exists while the coroutine is executing and is freed when the coroutine suspends and transfers execution back to the caller/resumer.
  
The 'Suspend' operation 

 - There are certain points within the body of a coroutine that are designed as suspended-points.
 - In the C++ Coroutines TS, these suspended points are idenfitifed by usages of the co_await or co_yield keywords.
 
 - When a coroutine hits one of these suspend-points it first prepares the coroutine for resumption by:
   (01) Ensuring any values held in registers are written to the coroutine frame.
   (02) Writing a value to the coroutine frame that indicates which suspend-point the coroutine is being suspended at. 
        - This allows a subsequent Resume operation to know where to resume execution of the coroutine or so a subsequent destory 
		  to know what values were in-scope and need to be destroyed.
		   
- Once the coroutine has been prepared for resumption, the coroutine is consider 'suspended'.

- This ability to execute logic after the coroutine enters the suspended state allows the coroutine to be scheduled for resumuption
  without the need for synchronization that would otherwise be required.
- If the coroutine was scheduled for resumption prior to entering the suspended state due to the potential for suspension
  and resumption of the coroutine to race.


  
        
 
  