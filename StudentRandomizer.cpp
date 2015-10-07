/*

	Name: Jesus Garcia
	Email: jesusega@usc.edu
	Website: http://jesus1103.weebly.com
	
	************************************************* Student Randomizer *************************************************
	About: Randomly generates students. Mainly used to choose students for participation or to assign groups to students.
	Needed: A list with the student's names.
	Outputs: Student name(s) or students assigned in a group.

*/

#include "Student.h"	// Student Header
#include "Group.h"		// Group Header
#include <fstream>		// File Stream Header
#include <sstream>		// String Stream Header
#include <ctime>		// Time Header
#include <random>		// Random Header

/*
	Name: PickStudents
	Function:
		Selects students at random
	Parameters:
		sC (Group*)		Group that contains the class
		rG (Group*)		Students that were selected at random
	Returns: Nothing
*/
void PickStudents(Group* sC, Group* rG) {
	int numOfRandomStudents = 0;			// Number of Students that will be randomly picked
	Group* sCCopy = new Group(sC);			// Copy of student class Group

	// Clear current random Group
	rG->ClearGroup();

	// Request how many Students should be picked
	std::cout << "Please let me know many students you would like picked at random: ";
	std::cin >> numOfRandomStudents;
	std::cin.ignore();

	// Pick students at random and store in return Group
	for (int i = 0; i < numOfRandomStudents; i++) {
		// Remove random Student from class copy and store in the back of the return Group
		rG->PushStudent(sCCopy->RemoveStudent(rand() % sCCopy->GetSize()));
	}
}

/*
	Name: AssignGroups
	Function:
		Assigns Students into random number of Groups
	Parameters:
		sC (Group*)					Group that contains the class
		aG (std::vector<Group*>)	List of random Groups
	Returns: Nothing
*/
void AssignGroups(Group* sC, std::vector<Group*>& aG) {
	int numOfGroups = 0;					// Number of Groups
	bool groupsCreated = false;				// Boolean that checks if Groups were created
	Group* sCCopy = new Group(sC);			// Copy of student class Group

	// Clear current Groups
	for (int i = 0; i < aG.size(); i++) {
		aG[i]->ClearGroup();
		delete aG[i];
	}
	aG.clear();


	// Request how many Students should be picked
	std::cout << "Please let me know many groups you would like: ";
	std::cin >> numOfGroups;
	std::cin.ignore();

	// Pick students at random and store in return Group
	while (sCCopy->GetSize() > 0) {
		for (int i = 0; i < numOfGroups; i++) {
			std::cout << aG.size() << std::endl;
			if (!groupsCreated) {
				aG.push_back(new Group(i+1));
			}
			if (sCCopy->GetSize() > 0) {
				// Remove random Student from class copy and store in the back of the return Group
				aG[i]->PushStudent(sCCopy->RemoveStudent(rand() % sCCopy->GetSize()));
			}
		}
		
		// Groups have been created
		if(!groupsCreated) {
			groupsCreated = true;
		}
	}
}

/*
	Name: ChangeClassList
	Function: 
		Asks the user to input a class list file name without the .txt.
		Will repeat ask if the input is invalid.
	Parameters:
		cN	(std::string)	Class Name
		vCL	(bool)			Valid Class List Checker
		cL	(std::string)	Class List
	Returns: Nothing
*/
void ChangeClassList(std::string cN, bool& vCL, std::string& cL) {
	// Ask for Class List
	std::cout << "Please feed me the information of the students in your " << cN << " class "
		<< "(please do not include the extension of the text file): ";

	// Check is Class List is valid and request Class List again if not valid
	while (!vCL) {
		std::getline(std::cin, cL);
		if (cL.find(".txt") == std::string::npos) {
			vCL = true;
			cL += ".txt";
		}
		else {
			std::cout << "Please feed me a file without the file extension: ";
		}
	}

	// Reset Variables
	vCL = false;
}
/*
	Name: ParseFile
	Function:
		Reads a file of students and stores it in a Group
	Parameters:
		file	(std::string)	Name of file being parsed
		sC		(Group)			Group of Students
	Returns: Nothing
*/
void ParseFile(std::string file, Group* sC) {
	// Clear Group
	sC->ClearGroup();

	// Open file
	std::ifstream classFile;
	classFile.open(file);

	// Store line
	std::string line = "";

	// Extract line from file
	while (!classFile.eof()) {
		std::getline(classFile, line);
		// Check format of file
		if (line.find(",") == std::string::npos) {
			/* Format is firstName lastName */
			// Split String
			std::stringstream word(line);
			std::string lName = "";
			std::string fName = "";
			std::getline(word, fName, ' ');
			std::getline(word, lName , ' ');

			// Store new Student in Student Class
			sC->PushStudent(new Student(fName, lName));
		}
		else {
			
			/* Format is lastName, firstName */
			// Split String
			std::stringstream word(line);
			std::string lName = "";
			std::string fName = "";
			std::getline(word, lName, ',');
			std::getline(word, fName, ' '); // Garbage space after ','
			std::getline(word, fName, ' ');

			// Store new Student in Student Class
			sC->PushStudent(new Student(fName, lName));
		}
	}

	// Close file
	classFile.close();
}

int main() {

	/* Variables Used */
	std::string userName = "";			// Name of user
	std::string className = "";			// Name of the class
	std::string classList = "";			// File that contains list of students
	
	Group* studentClass = new Group(0);	// Class
	Group* randomGroup = new Group(-1);	// Random Group
	std::vector<Group*> assignedGroups;	// Vector of Assigned Groups

	bool validClassList = false;		// Valid class list check
	bool validOptionInputType = false;	// Valid Main Menu option input check
	bool exitProgram = false;			// Exit Program check

	int menuOption = -1;				// Option selected in Main Menu
	int numberOfRandomStudents;			// Number of randomly-picked Students
	int numberOfGroups;					// Number of Groups students will be randomly placed in

	// Seed Random
	srand(time(NULL));

	/* Ask for input */
	// Ask for User Name
	std::cout << "Welcome Master of Knowledge. Please introduce yourself: ";
	std::getline(std::cin, userName);

	// Ask for Class Name
	std::cout << "Hello " << userName << ". Please tell me the name of the class you are working with: ";
	std::getline(std::cin, className);

	// Ask for Class List
	ChangeClassList(className, validClassList, classList);
	ParseFile(classList, studentClass);

	// Print Current Class
	studentClass->PrintGroup();
	
	/* Menu */
	while (!exitProgram) {
		while (!validOptionInputType) {
			// Ask for option
			std::cout << std::endl;
			std::cout << "***** Main Menu *****" << std::endl;
			std::cout << "Current Class: " << className << std::endl;
			std::cout << "Current List: " << classList << std::endl;
			std::cout << userName << ", please select an option by number." << std::endl;
			std::cout << "\t 1 - Generate Random Students" << std::endl;
			std::cout << "\t 2 - Generate Random Groups" << std::endl;
			std::cout << "\t 3 - Print Current Random Students" << std::endl;
			std::cout << "\t 4 - Print Current Groups" << std::endl;
			std::cout << "\t 5 - Print Current Class" << std::endl;
			std::cout << "\t 6 - Change User Name" << std::endl;
			std::cout << "\t 7 - Change Class Name" << std::endl;
			std::cout << "\t 8 - Change Class List" << std::endl;
			std::cout << "\t 0 - Exit Program" << std::endl;
			std::cout << "Input: ";

			// Check if input is a number
			try {
				std::cin >> menuOption;
				std::cin.ignore();
				validOptionInputType = true;
			}
			catch (...) {
				std::cout << "Please enter a valid option." << std::endl << std::endl;
				validOptionInputType = false;
			}
		}
		
		// Switch for Main Menu
		switch (menuOption) {
		case 1:
			/* Pick Random Students */
			PickStudents(studentClass, randomGroup);
			randomGroup->PrintGroup();
			break;
		case 2:
			/* Assign Random Groups */
			AssignGroups(studentClass, assignedGroups);
			for (int i = 0; i < assignedGroups.size(); i++) {
				assignedGroups[i]->PrintGroup();
			}
			break;
		case 3:
			/* Print Current Random Students */
			if (randomGroup->GetSize() == 0) {
				std::cout << std::endl << "Random students have not been selected yet." << std::endl;
			}
			else {
				randomGroup->PrintGroup();
			}
			break;
		case 4:
			/* Print Current Groups */
			if (assignedGroups.size() == 0) {
				std::cout << std::endl << "Random groups have not been selected yet." << std::endl;
			}
			else {
				for (int i = 0; i < assignedGroups.size(); i++) {
					assignedGroups[i]->PrintGroup();
				}
			}
			break;
		case 5:
			/* Print Current Class */
			studentClass->PrintGroup();
			break;
		case 6:
			/* Change User Name */
			std::cout << "If you are a new Master of Knowledge, please introduce yourself. "
				<< "If you are not, please re-introduce yourself: ";
			std::getline(std::cin, userName);
			break;
		case 7:
			/* Change Class Name */
			std::cout << userName << ", please tell me the name of the class you are working with: ";
			std::getline(std::cin, className);
			break;
		case 8:
			/* Change Class List File */
			ChangeClassList(className, validClassList, classList);
			ParseFile(classList, studentClass);
			break;
		case 0:
			/* Exit Program */
			exitProgram = true;
			break;
		default:
			/* Invalid Input */
			std::cout << "Please enter a valid option." << std::endl << std::endl;
			break;
		}

		// Reset Variables
		validOptionInputType = false;
	}

	// Deallocate dynamic memory
	delete randomGroup;

	return 0;	// End of Program

}