#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

using namespace std;

class items { //constructor for the item class
private:
	string itemName;
	int itemPrice;
	int itemCreativity;
	int itemActivity;
	int itemComplexity;
public:
	items(string n, int p, int c, int a, int comp) :itemName(n)
		, itemPrice(p)
		, itemCreativity(c)
		, itemActivity(a)
		, itemComplexity(comp)
	{}

	string getItemName() {
		return itemName;
	}

	int getItemPrice() {
		return itemPrice;
	}

	int getItemCreativity() {
		return itemCreativity;
	}

	int getItemActivity() {
		return itemActivity;
	}

	int getItemComplexity() {
		return itemComplexity;
	}
};

class employees { //constructor for employee class
private:
	string empName;
	string empUsername;
	string empPassword;
	int empTotalSales;
public:
	employees(string n, string u, string pw, int tSales) :empName(n)
		, empUsername(u)
		, empPassword(pw)
		, empTotalSales(tSales)
	{}

	string getEmpName() {
		return empName;
	}

	string getEmpUsername() {
		return empUsername;
	}

	string getEmpPassword() {
		return empPassword;
	}

	int getEmpTotalSales() {
		return empTotalSales;
	}

	void setEmpTotalSales(int s) {
		empTotalSales = s;
	}
};


/*
void userLoggedIn() {
while( true ) {
cout << "What would you like to do?" << endl;
cout << "1. Restock" << endl;
cout << "2. Make a sale" << endl;
cout << "3. Check inventory" << endl;
cout << "4. Exit" << endl;
int loggedInInput;
cin >> loggedInInput;
if ( loggedInInput == 1 ) {
//takes in input for creativity/activity/complexity
//creates item
//pushes on to vectorOfItems
int creativity;
int activity;
int complexity;
string name;
// make name all lowercase
int price;
vectorOfItems.push_back(item(name, price, creativity, activity, complexity));
}
else if ( loggedInInput == 2 ) {
//takes in input of item name
//removes first found item from vectorOfItems
//add to sale count of employee -> increments value of count for employee
// again this would be better in main function because we can keep track of employee with a variable equal to the username
string purchaseName;
// make all lowercase
for (int i = 0; i < vectorOfItems.size(); i++) {
if (purchaseName == vectorOfItems[i].getItemName) {
vectorOfEmployees[currentEmployee].totalSales++;
//deletes item in vector
vectorOfItems.erase(vectorOfItems.begin() + i);
}
}
}
else if ( loggedInInput == 3 ) {
//loops through vectorOfItems and prints each itemName and itemPrice
cout << "Current in stock: " << endl;
for (int i = 0; i < vectorOfItems.size(); i++) {
cout << "Item: " <<vectorOfItems[i].getItemName << " Price: " << vectorOfItems[i].getItemPrice << endl;
}
}
else if ( loggedInInput == 4 ) {
break;
}
} // end of while loop for user logged in
}
*/

bool isNumber(string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if(!isdigit(str.at(i))) {
			return false;
		} 
	}
	return true;
}

int main() {
	vector<items> vectorOfItems; //creates the vector of items
	vector<employees> vectorOfEmployees; //creates the vector of employees

	int currentEmployee;

	//initial prompt for user to select employee or customer
	cout << "Welcome to the shop! Are you an employee or customer?" << endl;
	cout << "1. Employee" << endl;
	cout << "2. Customer" << endl;
	string userInput = "";
	int firstInput = 0;
	bool hello = true;

	while (firstInput != 1 && firstInput != 2) { //input validation for the first menu choice
		bool isNum = true;
		cout << endl;
		cin >> userInput;
		//the following for loop checks to see if the user inputed a number
		for (size_t i = 0; i < userInput.length(); i++) {
			if (!isdigit(userInput.at(i))) {
				isNum = false;
			}
		}
		//if the input is a number, convert the string to an int which will dictate where the code continues
		if (isNum) {
			firstInput = atoi(userInput.c_str());
		}
		if (firstInput == 1) { //entry points for the employee login
			if (hello) { //only prints the "Hello Employee!" statement once so as to not sound redundant
				cout << "Hello Employee! Please login or register for an account." << endl;
				hello = false;
			}
			cout << "1. Login" << endl;
			cout << "2. Register" << endl;
			cout << "3. Exit" << endl;
			int secondInput = 0;
			string secondUserInput = "";
			while (secondInput != 1 && secondInput != 2 && secondInput != 3) {
				bool isNum2 = true;
				cout << endl;
				cin >> secondUserInput;
				for (size_t i = 0; i < secondUserInput.length(); i++) {
					if (!isdigit(secondUserInput.at(i))) {
						isNum2 = false;
					}
				}
				if (isNum2) {
					secondInput = atoi(secondUserInput.c_str());
				}
				if (secondInput == 1) {
					string username;
					string password;
					cout << "Username: ";
					cin >> username;
					cout << "Password: ";
					cin >> password;

					bool isAuthenticated = false;
					//Iterate through vector and compare username/password -> write a method to return true/false
					for (size_t i = 0; i < vectorOfEmployees.size(); i++) {
						if (username == vectorOfEmployees[i].getEmpUsername() && password == vectorOfEmployees[i].getEmpPassword()) {
							currentEmployee = i;
							isAuthenticated = true;
							break;
						}
					}
					if (isAuthenticated) {
						//write function for logged in prompts for employees
						//userLoggedIn(); <---__******


						//might put code directly in here because it would be easier to append to vector, check username for sales... etc
						bool loginFirstTime = true;
						string userLoggedInInput = "";
						int loggedInInput = 0;
						bool isNum3 = true;
							while (loggedInInput != 1 && loggedInInput != 2 && loggedInInput != 3 && loggedInInput != 4) {
								if (loginFirstTime) {
									cout << endl << "Login successful." << endl;
								}
								loginFirstTime = false;
								cout << "What would you like to do?" << endl;
								cout << "1. Restock" << endl;
								cout << "2. Make a sale" << endl;
								cout << "3. Check inventory" << endl;
								cout << "4. Logout" << endl;
								cout << endl;
								cin >> userLoggedInInput;
								for (size_t i = 0; i < userLoggedInInput.length(); i++) {
									if (!isdigit(userLoggedInInput.at(i))) {
										isNum3 = false;
									}
								}
								if (isNum3) {
									loggedInInput = atoi(userLoggedInInput.c_str());
								}
								if (loggedInInput == 1) { //PETER's CODE
									//takes in input for creativity/activity/complexity
									//creates item
									//pushes on to vectorOfItems

									//VALUES ARE TEMPORARY
									int creativity = 0;
									int activity = 0;
									int complexity = 0;
									string creativityStr = "";
									string activityStr = "";
									string complexityStr = "";
									string name = "";
									string n = "";
									// make name all lowercase
									int price = 0;
									string priceStr = "";
									cout << "What is the name of item you'd like to restock?" << endl;
									cin >> n;
									size_t counter = 0;
									char c;
									while (counter < n.length()) //converts all characters in string to lowercase
									{
										c = n[counter];
										if (isupper(c))
										{
											n[counter] = tolower(c);
										}
										counter++;
									}
									name = n;
									counter = 0;
									size_t counter2 = 0;
									string restockchoiceStr = "";
									int restockchoice = 0;
									bool alreadychecked = false;
									bool usingprevious = false;
									vector<items> vectorOfCheckedItems;
									while (counter < vectorOfItems.size()) // checks to see if an item with the same name has already been added to the inventory, and prompts user if they would like to use these stats
									{
										while (counter2 < vectorOfCheckedItems.size()) // checks to see if the item is the same as what has previously been offered
										{
											if ((vectorOfCheckedItems[counter2].getItemName() == vectorOfItems[counter].getItemName()) && (vectorOfCheckedItems[counter2].getItemPrice() == vectorOfItems[counter].getItemPrice()) && (vectorOfCheckedItems[counter2].getItemCreativity() == vectorOfItems[counter].getItemCreativity()) && (vectorOfCheckedItems[counter2].getItemActivity() == vectorOfItems[counter].getItemActivity()) && (vectorOfCheckedItems[counter2].getItemComplexity() == vectorOfItems[counter].getItemComplexity()))
											{
												alreadychecked = true;
											}
											counter2++;
										}
										if ((vectorOfItems[counter].getItemName() == name) && !alreadychecked)
										{
											cout << name << " has been found in our inventory with a price of " << vectorOfItems[counter].getItemPrice() << ", " << vectorOfItems[counter].getItemCreativity() << " Creativity, " << vectorOfItems[counter].getItemActivity() << " Activity, and " << vectorOfItems[counter].getItemComplexity() << " complexity. Would you like to use these statistics?" << endl;
											cout << "1. Yes" << endl;
											cout << "2. No" << endl;
											cin >> restockchoiceStr;
											if (isNumber(restockchoiceStr)) { //input validation for the restockchoice variable
												restockchoice = atoi(restockchoiceStr.c_str());
											}
											while (!isNumber(restockchoiceStr) || restockchoice != 1 && restockchoice != 2) {
												cout << "Not a valid choice. Please enter 1 for Yes and 2 for No." << endl;
												cin >> restockchoiceStr;
												if (isNumber(restockchoiceStr)) {
													restockchoice = atoi(restockchoiceStr.c_str());
												}
											}
											//if the user wants to use same data from the previous item, create a duplicate
											//and push it into the inventory
											if (restockchoice == 1)
											{
												price = vectorOfItems[counter].getItemPrice();
												creativity = vectorOfItems[counter].getItemCreativity();
												activity = vectorOfItems[counter].getItemActivity();
												complexity = vectorOfItems[counter].getItemComplexity();
												usingprevious = true;
												break;
											}
											//otherwise create a item and push it into the inventory
											else if (restockchoice == 2)
											{
												vectorOfCheckedItems.push_back(vectorOfItems[counter]);
											}
										}

										counter++;
									}
									if (!usingprevious)
									{
										cout << "What is the selling price for this item?" << endl;
										cout << "$";
										cin >> priceStr;
										if (isNumber(priceStr)) { //input validation for the price variable
											price = atoi(priceStr.c_str());
										}
										while (!isNumber(priceStr)) {
											cout << "Not a valid choice. Please enter a valid price." << endl;
											cin >> priceStr;
											if (isNumber(priceStr)) {
												price = atoi(priceStr.c_str());
											}
										}
										cout << "What is the creativity value associated with the item? (Scale of 1-5)" << endl;
										cin >> creativityStr;
										if (isNumber(creativityStr)) { //input validation for the creativity variable
											creativity = atoi(creativityStr.c_str());
										}
										while (!isNumber(creativityStr) || creativity < 1 || creativity > 5) {
											cout << "Not a valid choice. Please enter an integer value between 1 and 5 inclusive." << endl;
											cin >> creativityStr;
											if (isNumber(creativityStr)) {
												creativity = atoi(creativityStr.c_str());
											}
										}
										cout << "What is the activity value associated with the item? (Scale of 1-5)" << endl;
										cin >> activityStr;
										if (isNumber(activityStr)) { //input validation for the activity variable
											activity = atoi(activityStr.c_str());
										}
										while (!isNumber(activityStr) || activity < 1 || activity > 5) {
											cout << "Not a valid choice. Please enter an integer value between 1 and 5 inclusive." << endl;
											cin >> activityStr;
											if (isNumber(activityStr)) {
												activity = atoi(activityStr.c_str());
											}
										}
										cout << "What is the complexity value associated with the item? (Scale of 1-5)" << endl;
										cin >> complexityStr;
										if (isNumber(complexityStr)) { //input validation for the complexity variable
											complexity = atoi(complexityStr.c_str());
										}
										while (!isNumber(complexityStr) || complexity < 1 || complexity > 5) {
											cout << "Not a valid choice. Please enter an integer value between 1 and 5 inclusive." << endl;
											cin >> complexityStr;
											if (isNumber(complexityStr)) {
												complexity = atoi(complexityStr.c_str());
											}
										}
									}

									vectorOfItems.push_back(items(name, price, creativity, activity, complexity));
									cout << name << " successfully restocked!" << endl;
									loggedInInput = 0; //need this so the loop continues until it exits
								}

								else if (loggedInInput == 2) {
									//takes in input of item name
									//removes first found item from vectorOfItems
									//add to sale count of employee -> increments value of count for employee
									// again this would be better in main function because we can keep track of employee with a variable equal to the username
									string purchaseName;
									cout << "What would you like to sell?" << endl;
									cin >> purchaseName;
									bool success = false;
									// make all lowercase

									for (size_t i = 0; i < vectorOfItems.size(); i++) {
										if (purchaseName == vectorOfItems[i].getItemName()) {
											vectorOfEmployees[currentEmployee].setEmpTotalSales((vectorOfEmployees[currentEmployee].getEmpTotalSales()) + 1); //need to  modify this to change it to be price + totalSales eventually
											//deletes item in vector
											vectorOfItems.erase(vectorOfItems.begin() + i);
											cout << "Successful Transaction" << endl;
											bool success = true;
										}
									}

									if (!success) {
										cout << "Failed to sell item!" << endl;
									}
									loggedInInput = 0;
								}

								else if (loggedInInput == 3) {
									//loops through vectorOfItems and prints each itemName and itemPrice
									cout << "Current in stock: " << endl;
									for (size_t i = 0; i < vectorOfItems.size(); i++) {
										cout << "Item: " << vectorOfItems[i].getItemName() << " Price: " << vectorOfItems[i].getItemPrice() << endl;
									}
									loggedInInput = 0;
								}

								else if (loggedInInput == 4) {
									cout << "Logout successful." << endl;
									secondInput = 0;							
								}
								else {
									cout << "Error. Not a valid choice. Please try again." << endl;
								}
							} //end of Employee options loop
						//} // end of while loop for user logged in GIVING PROBLEMS RN
					}
					else { //if (!isAuthenticated)
						secondInput = 0;
						hello = true;
						cout << endl << "Login Unsuccesful. Invalid username or password. Please try again." << endl;
					}
				}

				else if (secondInput == 2) {
					string name;
					string username;
					string password;
					cout << "Please enter the following information to register for a new account." << endl;
					cout << "Name: ";
					cin >> name;
					cout << "Username: ";
					cin >> username;
					cout << "Password: ";
					cin >> password;

					//validate for uniqueness of account
					//will return true of false value which will be used in this conditional
					bool isUnique = true;
					for (size_t i = 0; i < vectorOfEmployees.size(); i++) {
						if (username == vectorOfEmployees[i].getEmpUsername()) {
							isUnique = false;
							break;
						}
					}

					if (isUnique) {
						int sales = 0;
						vectorOfEmployees.push_back(employees(name, username, password, sales));
						cout << "Thank you for registering, " << name << "! Please log in with your new credentials." << endl << endl;
						secondInput = 0;
					}
					else {
						//prints and loop will run again
						cout << "Username already taken!" << endl << endl;
						secondInput = 0;
					}
				}

				else if (secondInput == 3) {
					firstInput = 0;
					cout << "Welcome to the shop! Are you an employee or customer?" << endl;
					cout << "1. Employee" << endl;
					cout << "2. Customer" << endl;
					hello = true;
					break;
				}
				else {
					cerr << "Error, not a valid choice. Please enter either 1 to login, 2 to register, or 3 to go back." << endl;
				}
				cout << "1. Login" << endl;
				cout << "2. Register" << endl;
				cout << "3. Exit" << endl;
			} // closing bracket for top while loop
		} //closing bracket for if employee
		else if (firstInput == 2) {

		}//closing bracket for if customer
		else {
			cerr << "Error, not a valid choice. Please enter either 1 for employee or 2 for customer" << endl;
		}
	} //closing bracket for the outermost while loop which checks for user validation
	return 0;
}
