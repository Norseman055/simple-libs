# Manager
Manager.h is a generic class any C++ class can inherit from to specify that the class in question is meant to be a manager that contains a list of objects arranged in a PCS Tree relationship. (Parent-Child-Sibling)

# Requirements 
- PCSTree
The "PCSTree" library in the Manager folder must be added to your solution. Include "PCSTree.h" and "PCSNode.h" in your solution, and link to the PCSTree library. (PCSTreeDebug.lib is made to work with Edit and Continue mode in Visual Studio, whereas PCSTreeRelease.lib has been optimized to run as quickly as possible)

# Usage
1. Include "Manager.h" and "NodeLink.h" in the file that would use it, then inherit your class from the Manager, specifying the class you wish to have stored in the list as a template parameter. 
2. Include "NodeLink.h" and the class you wish to manage in a separate "Node" class, specifying the class you wish to have stored in the list as a template parameter. This Link class holds a reference to the managed object and will be stored in the Manager.
3. Make sure your project includes the folder that holds "Manager.h", "NodeLink.h", and "Singleton.h". "Singleton.h" is currently part of Manager.h so it can be handled as a singleton manager, but it would not be too difficult to remove the inheritance in "Manager.h". Feel free to do so as necessary.

# Example

// Foo.h

class Foo : Manager<Bar> {
	// Foo is a manager of Bar objects, use GetInstance() to get reference to Foo
}

// BarLink.h

class BarLink : NodeLink<Bar> {
	// BarLink holds a Bar* and can be retrieved with getData()
}

// Bar.h

class Bar {
	int data;
}

// Example.cpp

Foo* foo = GetInstance();	// foo is now the singleton manager of Bar objects
Bar* bar = new Bar;		// make a Bar object
BarLink* barLink = new BarLink(bar);	// attach a bar object to the BarLink
foo->Add(barLink);		// foo now has a single Bar object, wrapped in a BarLink
foo->Remove(barLink);	// foo has now removed the BarLink object the list of managed objects and deallocated both BarLink and the wrapped-up Bar object.