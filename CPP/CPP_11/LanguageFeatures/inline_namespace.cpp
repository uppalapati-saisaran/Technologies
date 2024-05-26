Inline namespaces

- All members of an inline namespace are treated as if they were part
  of its parent namespace, allowing specializatin of functions and 
  easing the processs of versioning.
 
 - This is a transitive property, if A contains B, which in turn 
   contains C and both B and C are inline namespaces, C's members can
   be used as if they were on A.
   
   namespace Program {
     namespace Version1 {
		int getVersion() { return 1; }
		bool isFirstVersion() { return true; }
	 }
	 inline namespace Version2 {
		int getVersion() { return 2; }
	 }
   }
   
   int version {Program::getVersion()}; // Uses getVersion() from Version2
   int oldVersion {Program::Version1::getVersion()}; // Uses getVersion() from version1
   int firstVersion { Program::isFirstVerson()}; // Does not compile when Version2 is added.
   
   
  