#include "Group.h"	// Group Header

/*
	Name: Group
	Function:
		Constructor with no data
	Parameters:
		None
	Returns: A spanking new Group with no data
*/
Group::Group() {
	mID = 0;
}
/*
	Name: Group
	Function:
		Constructor with ID parameter
	Parameters:
		id (int)		ID of Group
	Returns: A spanking new Group with an ID
*/
Group::Group(int id) {
	mID = id;
}
/*
	Name: ~Group
	Function:
		Destructor
	Parameters:
		None
	Returns: Nothing
*/
Group::~Group() {
	for (int i = 0; i < mStudents.size(); i++) {
		Student* student = mStudents[i];
		delete student;
	}
	mStudents.clear();
}
/*
	Name: PushStudent
	Function:
		Adds Student to back of Group list
	Parameters:
		s (Student)			Student being added to Group
	Returns: Nothing
*/
void Group::PushStudent(Student* s) {
	mStudents.push_back(s);
}
/*
	Name: PopStudent
	Function:
		Removes Student from the front of the Group list
	Parameters:
		None
	Returns: (Student) The removed Student
*/
Student* Group::PopStudent() {
	Student* temp = mStudents[0];
	mStudents.erase(mStudents.begin());
	return temp;
}
/*
	Name: RemoveStudent
	Function:
		Removes Student from the Group list
	Parameters:
		s (Student)			Student being removed from the Group list
	Returns: (Student) The removed Student or null if wasn't on list
*/
Student* Group::RemoveStudent(Student* s) {
	for (int i = 0; i < mStudents.size(); i++) {
		if (mStudents[i] == s) {
			Student* temp = mStudents[i];
			mStudents.erase(mStudents.begin() + i);
			return temp;
		}
	}
	return nullptr;
}
/*
	Name: GetID
	Function:
		Get Group ID
	Parameters:
		None
	Returns: (int) The Group ID
*/
int Group::GetID() {
	return mID;
}
/*
	Name: GetID
	Function:
		Set Group ID
	Parameters:
		id (int)		ID of Group
	Returns: Nothing
*/
void Group::SetID(int id) {
	mID = id;
}
/*
	Name: GetList
	Function:
		Get Group List
	Parameters:
		None
	Returns: (std::vector<Student>) List in Group
*/
std::vector<Student*> Group::GetList() {
	return mStudents;
}
/*
	Name: SetList
	Function:
		Set Group List
	Parameters:
		list (std::vector<Student>)		List of Group
	Returns: Nothing
*/
void Group::SetList(std::vector<Student*> list) {
	mStudents = list;
}
/*
	Name: GetStudent
	Function:
		Get Student at location index
	Parameters:
		index (int)			Location of requested Student
	Returns: (Student) The Student at location index
*/
Student* Group::GetStudent(int index) {
	return mStudents[index];
}
/*
	Name: GetSize
	Function:
		Get size of Group list
	Parameters:
		None
	Returns: (int) Size of Group list
*/
int Group::GetSize() {
	return mStudents.size();
}
/*
	Name: [] (overload)
	Function:
		Get Student at location index
	Parameters:
		index (int)			Location of requested Student
	Returns: (Student) The Student at location index
*/
Student* Group::operator[](int index) {
	return mStudents[index];
}
/*
	Name: PrintGroup
	Function:
		Print Students in Group
	Parameters:
		None
	Returns: Nothing
*/
void Group::PrintGroup() {
	// Line Space
	std::cout << std::endl;

	// Print "Class" or "Group #"
	if (mID == 0) {
		std::cout << "***** Class *****" << std::endl;
	}
	else {
		std::cout << "***** Group " << mID << " *****" << std::endl;
	}

	// Print names
	for (int i = 0; i < mStudents.size(); i++) {
		mStudents[i]->PrintName(false);
	}

	// Line Space
	std::cout << std::endl;
}