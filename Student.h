#pragma once

#include <iostream> // Input and Output Stream Header
#include <string>	// String Header

class Student {
public:
	/* Members */
	// Constructors and Destructor
	Student();									// Default Constructor
	Student(std::string fN, std::string lN);	// Constructor with Name Parameters
	~Student();									// Default Destructor

	// Accessors and Mutators
	std::string GetFirstName();					// Get Student's First Name
	std::string GetLastName();					// Get Student's Last Name
	void SetFirstName(std::string fN);			// Set Student's First Name
	void SetLastName(std::string lN);			// Set Student's Last Name

	// Overloaded Operators
	bool operator==(Student s);					// Compares if two students are equal
	bool operator>(Student s);					// Compares if Student is greater than Student s
	bool operator<(Student s);					// Compares if Student is less than Student s
	bool operator>=(Student s);					// Compares if Student is greater than or equal to Student s
	bool operator<=(Student s);					// Compares if Student is less than or equal to Student s

	// Other Functions
	void PrintName(bool last);					// Prints Student's Name

private:
	/* Properties */
	std::string mFirstName;						// First Name of Student
	std::string mLastName;						// Last Name of Student
};