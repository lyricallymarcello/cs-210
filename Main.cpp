#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// Function Prototypes
void mainMenu();
string userPrompt();
void displayHistogram();

int main() {

	// Calls Main Menu to Start Program
	mainMenu();

	return 0;
}

void mainMenu() {
	// Declaration of Variables
	int userChoice = -1; // Initialize userChoice to Allow Loop to Start
	string userWord;

	// Header of Menu
	cout << "Corner Grocer App\n" << endl;

	// While Loop to Display Menu and Obtain User Input Until User Chooses to Exit
	while (userChoice != 4) {
		// Outputs the Main Menu
		cout << "1: Display List of All Items Purchased" << endl;
		cout << "2: Display the Frequency of a Specific Item" << endl;
		cout << "3: Display a Histogram of the Items Purchased" << endl;
		cout << "4: Exit Program\n" << endl;
		cout << "Please enter a number to make a selection: ";
		// Stores User Selection into userChoice Variable
		cin >> userChoice;

		// If User Enters String Clears Input and Allows User to Try Again
		while (!userChoice) {
			cout << "Please enter a valid selection" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> userChoice;
		}

		// Switch Statement to Execute the User's Selected Choice
		switch (userChoice) {
		// Executes if User Selects Option 1
		case 1:
			cout << "\nYou have selected to Diplay the List of All Items Purchased" << endl;
			cout << endl;
			// Calls Item Frequency Function from Python Code
			CallProcedure("ItemFrequency");
			break;
		// Executes if User Selects Option 2
		case 2:
			// Prompt User for Item to Search for
			cout << "\nYou have selected to Search for a Specific Item" << endl;
			cout << endl;
			userWord = userPrompt();
			userWord[0] = toupper(userWord[0]); // Capitalizes First Character of User Input
			// Calls Specific Item Frequency and Passes User Input as a Parameter
			callIntFunc("SpecificItemFrequency", userWord);
			break;
		// Exectures if User Selects Option 3
		case 3:
			cout << "\nYou have selected to Display a Histogram" << endl;
			cout << endl;
			// Calls Function to Write to File called frequency.dat
			CallProcedure("CreateHistogramFile");
			// Reads from File Created and Displays Histogram
			displayHistogram();
			break;
		// Executes if User Does not Enter a Valid Option
		case 4:
			cout << "\nYou have chosen to terminate the program. Goodbye." << endl;
			break;

		// Executes if User does not Select one of the Available Options
		default:
			cout << "\nThat is not a valid selection." << endl;
			// Clears Bad Input
			cin.clear();
			cin.ignore();
			break;
		}

	}

} 

string userPrompt() {
	// Declare String Variable to Search For
	string wordToFind;
	// Prompt User for Input and Store in Variable wordToFind
	cout << "Enter the Item You Would Like to Search For: ";
	cin >> wordToFind;

	return wordToFind;
}

void displayHistogram() {
	// Declare Variable for File Data
	string fileData;
	int histNum;

	// Input File Stream
	ifstream inFS;
	// Open the "frequency.dat" file
	inFS.open("frequency.dat");

	// Loop to Read Through File and Print Each Line to Make Histogram
	while (inFS.good()) {
		inFS >> fileData >> histNum;
		// Stops Reading File Once End of File is Reached
		if (inFS.eof()) {
			break;
		}
		// Prints the Histrogram
		cout << fileData << string(histNum, '*') << endl;
	}
	cout << endl;

	// Closes File When Finished
	inFS.close();
}