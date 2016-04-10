# Singleton
Singleton.h is a generic class any C++ class can inherit from to specify that the class in question is only supposed to be instantiated once across an entire program. 

# Requirements 
None.

# Usage
Include "Singleton.h" in the file that would use it, then inherit your class from the Singleton, specifying the class in question as a template parameter. 

# Example

// #include "Singleton.h"

class Foo : Singleton<Foo> {
public:
	// use Foo as normal.
private:
	// Make Foo's constructor private to ensure it can only be instantiated by GetInstance()
	Foo();

	// When you're done with this instance of Foo, call DestroyInstance() to clean up the memory
}