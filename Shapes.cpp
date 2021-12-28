// =======================================================
// Shapes - Week 8
// Dean Fry, November 2021
// =======================================================

// Libraries
#include <iostream>
using namespace std;

// =======================================================
// Function Declaration
void mainMenu();
void startScreen();
void exitScreen();

// =======================================================
// Classes
class Circle {
private:
	float pi = 3.141593;
public:
	float m_radius = 0;

	float getArea() {
		float circleArea = pi * (m_radius * m_radius);
		return circleArea;
	}
	float getCircumference() {
		float circleCircumference = 2 * pi * m_radius;
		return circleCircumference;
	}
};

class Square {
public:
	float m_SideLength = 0;

	float getArea() {

	}
	float getPerimeter() {

	}
};

class Character {
public:
	float m_HP = 100;           // Health Points
	float m_SPD = 1;            // Speed
	float m_STA = 1;            // Stamina
	float m_STR = 1;            // Strength
	int m_XP = 0;               // Experience Points
	string m_Name = "Hero";     // Name of Character
	string m_Weapon = "Sword";  // Character Weapon
	bool m_Armed = true;
	bool m_IsAlive = true;

	void checkIsAlive() {

	}
};


// =======================================================
// Global Variables
bool gameOver = false;
// =======================================================

int main()
{
	startScreen();

	// Main Game Loop
	while (!gameOver)
	{
		mainMenu();
	}

	exitScreen();

	return 0;
}

// =======================================================
// Functions

void mainMenu()
{
	int playerChoice = 0;

	cout << "\n\n ====== Main Menu ====== \n\n";
	cout << " Please Select a Program to run: \n";
	cout << " 1: Shapes \n";
	cout << " 2: Characters \n";
	cout << " 3: Extra Work \n";
	cout << " 4: Exit Program \n";
	cout << "\n  : ";

	cin >> playerChoice; // User Input

	// Input Validation
	while (playerChoice < 1 || playerChoice > 4)
	{
		if (cin.fail()) // Non-Number entered
		{
			cin.clear();
			char c;
			cin >> c;
		}

		cout << "\n Error: Invalid Character";
		cout << "\n  : ";
		cin >> playerChoice;
	}

	switch (playerChoice)
	{
	case 1:
	{
		cout << "\n\n ====== Shapes ====== \n\n";
		cout << " Please Select a Program to run: \n";
		cout << " 1: Circle Area \n";
		cout << " 2: Circle Circumference \n";
		cout << " 3: Square Area \n";
		cout << " 4: Square Perimeter \n";
		cout << " 5: Main Menu \n";
		cout << " 6: Exit Program \n";
		cout << "\n : ";

		cin >> playerChoice; // User Input

		// Input Validation
		while (playerChoice < 1 || playerChoice > 6)
		{
			if (cin.fail()) // Non-Number entered
			{
				cin.clear();
				char c;
				cin >> c;
			}

			cout << "\n Error: Invalid Character";
			cout << "\n  : ";
			cin >> playerChoice;
		}

		Circle circle; // Circle Object
		Square square; // Square Object

		switch (playerChoice)
		{
		case 1:
		{
			cout << "\n Please input radius:";
			cout << "\n : ";
			cin >> circle.m_radius;
			cout << " : " << circle.getArea(); 
		}
		break;
		case 2:
		{
			cout << "\n Please input radius:";
			cout << "\n : ";
			cin >> circle.m_radius;
			cout << " : " << circle.getCircumference();
		}
		break;
		case 3:
		{
			cout << "Option Unavailable";
		}
		break;
		case 4:
		{
			cout << "Option Unavailable";
		}
		break;
		case 5:
		{
			
		}
		break;
		case 6:
		{
			gameOver = true;
		}
		break;
		default:
			break;
		}
	}
		break;
	case 2:
	{
		cout << "Option Unavailable";
	}
		break;
	case 3:
	{
		cout << "Option Unavailable";
	}
		break;
	case 4:
	{
		gameOver = true;
	}
		break;
	default:
		break;
	}
}

void startScreen()
{
	cout << "========================================= \n";
	cout << "====== Shapes - Week 8 \n";
	cout << "====== Dean Fry, November 2021 \n";
	cout << "========================================= \n";
	cout << "\n ====== Welcome Player 1 ======\n";
}

void exitScreen()
{
	cout << "========================================= \n";
	cout << "========= Thank you for playing ========= \n";
	cout << "================ Goodbye ================ \n";
	cout << "========================================= \n\n\n";
}

// =======================================================