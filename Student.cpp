#include "Student.h"	// Student Header

/*
	Name: Student
	Function:
		Constructor with no data
	Parameters:
		None
	Returns: A spanking new Student with no data
*/
Student::Student() {

}
/*
	Name: Student
	Function:
		Constructor with a first and last name
	Parameters:
		fN (std::string)	First Name
		lN (std::string)	Last Name
	Returns: A spanking new Student with a first and last name
*/
Student::Student(std::string fN, std::string lN) {
	mFirstName = fN;
	mLastName = lN;
}
/*
	Name: ~Student
	Function:
		Destructor
	Parameters:
		None
	Returns: Nothing
*/
Student::~Student() {

}
/*
	Name: GetFirstName
	Function:
		Gets the first name of a Student
	Parameters:
		None
	Returns: (std::string) The first name of a student
*/
std::string Student::GetFirstName() {
	return mFirstName;
}
/*
	Name: GetLastName
	Function:
		Gets the last name of a Student
	Parameters:
		None
	Returns: (std::string) The last name of a student
*/
std::string Student::GetLastName() {
	return mLastName;
}
/*
	Name: SetFirstName
	Function:
		Sets the first name of a Student
	Parameters:
		fN (std::string)	First Name
	Returns: Nothing
*/
void Student::SetFirstName(std::string fN) {
	mFirstName = fN;
}
/*
	Name: SetLastName
	Function:
		Sets the last name of a Student
	Parameters:
		lN (std::string)	Last Name
	Returns: Nothing
*/
void Student::SetLastName(std::string lN) {
	mLastName = lN;
}
/*
	Name: PrintName
	Function:
		Prints the name of a Student
	Parameters:
		last (bool)			Determines whether to print last name first
	Returns: Nothing
*/
void Student::PrintName(bool last) {
	if (last) {
		std::cout << mLastName << ", " << mFirstName << std::endl;
	}
	else {
		std::cout << mFirstName << " " << mLastName << std::endl;
	}
}
/*
	Name: == (overload)
	Function:
		Checks if Student is equal to Student s
	Parameters:
		s (Student)			Other Student being compared
	Returns: (bool) true if Student is equal to Student s
*/
bool Student::operator==(Student s) {
	return (mFirstName == s.GetFirstName() && mLastName == s.GetLastName());
}
/*
	Name: > (overload)
	Function:
		Checks if Student is greater than Student s
	Parameters:
		s (Student)			Other Student being compared
	Returns: (bool) true if Student is greater than Student s
*/
bool Student::operator>(Student s) {
	if (mLastName == s.GetLastName()) {
		return (mFirstName > s.GetFirstName());
	}
	return (mLastName > s.GetLastName());
}
/*
	Name: < (overload)
	Function:
		Checks if Student is less than Student s
	Parameters:
		s (Student)			Other Student being compared
	Returns: (bool) true if Student is less than Student s
*/
bool Student::operator<(Student s) {
	if (mLastName == s.GetLastName()) {
		return (mFirstName < s.GetFirstName());
	}
	return (mLastName < s.GetLastName());
}
/*
	Name: >= (overload)
	Function:
		Checks if Student is greater than or equal to Student s
	Parameters:
		s (Student)			Other Student being compared
	Returns: (bool) true if Student is greater than or equal to Student s
*/
bool Student::operator>=(Student s) {
	if (mLastName == s.GetLastName()) {
		return (mFirstName >= s.GetFirstName());
	}
	return (mLastName >= s.GetLastName());
}
/*
	Name: <= (overload)
	Function:
		Checks if Student is less than or equal to Student s
	Parameters:
		s (Student)			Other Student being compared
	Returns: (bool) true if Student is less than or equal to Student s
*/
bool Student::operator<=(Student s) {
	if (mLastName == s.GetLastName()) {
		return (mFirstName <= s.GetFirstName());
	}
	return (mLastName <= s.GetLastName());
}