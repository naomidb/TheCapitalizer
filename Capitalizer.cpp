//This program allows the user to capitalize a string in different ways.

#include <iostream>
#include <string>
using namespace std;


//Class
class CharConverter
{
private:
	string word;

public:
	string uppercase(string);
	string properWords(string);
};


//Member functions
string CharConverter::uppercase(string capitalize)
{
	for (int count = 0; count < capitalize.length(); count++)
		capitalize[count] = toupper(capitalize[count]);

	return capitalize;
}

string CharConverter::properWords(string titleCase)
{
	titleCase[0] = toupper(titleCase[0]);

	for (int count = 1; count < (titleCase.length() - 1); count++)
	{
		if (titleCase[count] == ' ')
			titleCase[count + 1] = toupper(titleCase[count + 1]);
	}

	return titleCase;
}

int main()
{
	CharConverter funWithStrings;
	char choice;
	int selection;
	string userInteraction;

	cout << "This program allows you to capitalize strings!" << endl;
	cout << "Would you like to use the program? Enter y for yes or n for no: ";
	cin >> choice;

	while (choice == 'y' || choice == 'Y')
	{
		cout << "Choose from the menu below:" << endl;
		cout << "1. Capitalize everything." << endl;
		cout << "2. Use initial caps only." << endl;
		cout << "0. Quit program." << endl;
		cin >> selection;
		cin.ignore();

		if (selection < 0 || selection > 2)
			cout << "Invalid selection." << endl;
		else if (selection == 1) {
			cout << "Enter a string: ";
			getline(cin, userInteraction);

			cout << "With the wave of my wand, " << userInteraction << " becomes " << funWithStrings.uppercase(userInteraction) << "!" << endl;

			cout << "Would you like to try again? Enter y for yes or n for no: ";
			cin >> choice;
		}
		else if (selection == 2) {
			cout << "Enter a string: ";
			getline(cin, userInteraction);

			cout << "With the wave of my wand, " << userInteraction << " becomes " << funWithStrings.properWords(userInteraction) << "!" << endl;

			cout << "Would you like to try again? Enter y for yes or n for no: ";
			cin >> choice;
		}
		else if (selection == 0) {
			choice = 'n';
		}
	}

	cout << "Goodbye.\n";

	return 0;

}