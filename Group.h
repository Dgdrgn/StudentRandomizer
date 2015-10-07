#pragma once

#include "Student.h"	// Student Header
#include <vector>		// Vector Header

class Group {
public:
	/* Members */
	// Constructors and Destructor
	Group();									// Default Constructor
	Group(int id);								// Constructor with ID parameters
	Group(Group* g);							// Copy Constructor
	~Group();									// Default Destructor

	// Insert and Remove Students
	void PushStudent(Student* s);				// Insert Student to back of Group
	Student* PopStudent();						// Remove Student in front of Group
	Student* RemoveStudent(Student* s);			// Remove Student s from Group
	Student* RemoveStudent(int i);				// Remove ith Student from Group
	void ClearGroup();							// Remove all Students from Group

	// Accessors and Mutators
	int GetID();								// Get Group ID
	void SetID(int id);							// Set Group ID
	std::vector<Student*> GetList();			// Get Group list
	void SetList(std::vector<Student*> list);	// Set Group list
	Student* GetStudent(int index);				// Get Student from location index in Group list
	int GetSize();								// Get size of Group list

	// Overloaded Operators
	Student* operator[](int index);				// Get Student from location index in Group list

	// Other Functions
	void PrintGroup();							// Print Students in Group

private:
	/* Properties */
	std::vector<Student*> mStudents;			// List of Students in Group
	int mID;									// ID of Group
};