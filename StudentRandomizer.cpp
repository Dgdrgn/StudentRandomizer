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
void ParseFile(std::string file, Group &sC) {
	// Clear Group
	sC.~Group();

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
			sC.PushStudent(new Student(fName, lName));
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
			sC.PushStudent(new Student(fName, lName));
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
	
	Group studentClass;					// Class

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
			std::cout << "\t 3 - Change User Name" << std::endl;
			std::cout << "\t 4 - Change Class Name" << std::endl;
			std::cout << "\t 5 - Change Class List" << std::endl;
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
			studentClass.PrintGroup();
			break;
		case 2:
			break;
		case 3:
			std::cout << "If you are a new Master of Knowledge, please introduce yourself. "
				<< "If you are not, please re-introduce yourself: ";
			std::getline(std::cin, userName);
			break;
		case 4:
			std::cout << userName << ", please tell me the name of the class you are working with: ";
			std::getline(std::cin, className);
			break;
		case 5:
			ChangeClassList(className, validClassList, classList);
			ParseFile(classList, studentClass);
			break;
		case 0:
			exitProgram = true;
			break;
		default:
			std::cout << "Please enter a valid option." << std::endl << std::endl;
			break;
		}

		// Reset Variables
		validOptionInputType = false;
	}

	return 0;	// End of Program

}