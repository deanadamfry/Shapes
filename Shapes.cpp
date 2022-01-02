// =======================================================
// Shapes - Week 8
// Dean Fry, November 2021
// =======================================================

// Libraries
#include <iostream>
#include <string>
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
	float m_Radius = 0;

	float getArea() {
		return pi * (m_Radius * m_Radius);
	}
	float getCircumference() {
		return 2 * pi * m_Radius;
	}
};

class Square {
public:
	float m_SideLength = 0;

	float getArea() {
		return m_SideLength * m_SideLength;
	}
	float getPerimeter() {
		return 4 * m_SideLength;
	}
};

class Character {
public:
	float m_HP = 100;           // Health Points
	float m_SPD = 10;           // Speed
	float m_STA = 10;           // Stamina
	float m_STR = 10;           // Strength
	int m_XP = 0;               // Experience Points
	string m_Name = "Stranger"; // Name of Character
	string m_Weapon = "None";   // Character Weapon
	bool m_Armed = true;        // Character Armed?
	bool m_IsAlive = true;      // Character Alive?

	void checkIsAlive() {
		if (m_HP < 1)
		{
			m_IsAlive = false;
		}
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
		// Clear Screen
		system("cls");

		// Shapes Menu
		cout << "\n\n ====== Shapes ====== \n\n";
		cout << " Please Select a Program to run: \n";
		cout << " 1: Circle \n";
		cout << " 2: Square \n";
		cout << " 3: Main Menu \n";
		cout << " 4: Exit Program \n";
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

		Circle circleSmall, circleMedium, circleLarge; // Circle Objects
		Square squareSmall, squareMedium, squareLarge; // Square Objects

		switch (playerChoice)
		{
		case 1:
		{
			circleSmall.m_Radius = 2;
			cout << "\n Small Circle";
			cout << "\n Area: " << circleSmall.getArea();
			cout << "\n Circumference: " << circleSmall.getCircumference();
			cout << "\n";
			
			circleMedium.m_Radius = 5;
			cout << "\n Medium Circle";
			cout << "\n Area: " << circleMedium.getArea();
			cout << "\n Circumference: " << circleMedium.getCircumference();
			cout << "\n";

			circleLarge.m_Radius = 10;
			cout << "\n Large Circle";
			cout << "\n Area: " << circleLarge.getArea();
			cout << "\n Circumference: " << circleLarge.getCircumference();
			cout << "\n";
		}
		break;
		case 2:
		{
			squareSmall.m_SideLength = 2;
			cout << "\n Small Square";
			cout << "\n Area: " << squareSmall.getArea();
			cout << "\n Perimeter: " << squareSmall.getPerimeter();
			cout << "\n";

			squareMedium.m_SideLength = 5;
			cout << "\n Medium Square";
			cout << "\n Area: " << squareMedium.getArea();
			cout << "\n Perimeter: " << squareMedium.getPerimeter();
			cout << "\n";

			squareLarge.m_SideLength = 10;
			cout << "\n Large Square";
			cout << "\n Area: " << squareLarge.getArea();
			cout << "\n Perimeter: " << squareLarge.getPerimeter();
			cout << "\n";
		}
		break;
		case 3:
		{
			// Leave blank, returns to Main Menu
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
		break;
	case 2:
	{
		// Clear Screen
		system("cls");

		// Random Number Seed Generator
		srand(static_cast<unsigned int>(time(0)));

		// Character Objects
		Character pc, npcs[3];

		// Prompt Player for PC name
		cout << "\n Please enter your Character's name: ";
		cout << "\n : ";
		cin >> pc.m_Name;

		// Prompt Player for PC weapon
		cout << "\n Please enter your Character's weapon: ";
		cout << "\n : ";
		cin >> pc.m_Weapon;

		// Set PC stats
		pc.m_HP = 100;
		pc.m_SPD = 10;
		pc.m_STA = 10;
		pc.m_STR = 10;
		pc.m_Armed = true;
		pc.m_IsAlive = true;

		// Create NPCS with random stats
		for (int i = 0; i < sizeof(npcs) / sizeof(npcs[0]); i++)
		{
			npcs[i].m_Name = "NPC_" + to_string(i + 1);
			npcs[i].m_HP = rand() % 100;
			npcs[i].m_SPD = rand() % 10 + 1;
			npcs[i].m_STA = rand() % 10 + 1;
			npcs[i].m_STR = rand() % 10 + 1;
			npcs[i].m_XP = rand() % 10 + 1;
			npcs[i].m_Armed = rand() % 2;
			if (npcs[i].m_Armed == true)
			{
				npcs[i].m_Weapon = "Shortsword";
			}
			npcs[i].checkIsAlive();
		}

		// Clear Screen
		system("cls");

		// Display PC stats
		cout << "\n Player Character Stats";
		cout << "\n Name: " << pc.m_Name;
		cout << "\n Weapon: " << pc.m_Weapon;
		cout << "\n HP: " << pc.m_HP;
		cout << "\n Speed: " << pc.m_SPD;
		cout << "\n Stamina: " << pc.m_STA;
		cout << "\n Strength: " << pc.m_STR;
		cout << "\n XP: " << pc.m_XP;
		if (pc.m_Armed == true)
		{
			cout << "\n Armed?: Yes";
		}
		else { cout << "\n Armed?: No"; }
		if (pc.m_IsAlive == true)
		{
			cout << "\n Alive?: Yes";
		}
		else { cout << "\n Alive?: No"; }
		cout << "\n";

		// Display NPC stats
		for (int i = 0; i < sizeof(npcs) / sizeof(npcs[0]); i++)
		{
			cout << "\n Current NPC Stats";
			cout << "\n Name: " << npcs[i].m_Name;
			cout << "\n Weapon: " << npcs[i].m_Weapon;
			cout << "\n HP: " << npcs[i].m_HP;
			cout << "\n Speed: " << npcs[i].m_SPD;
			cout << "\n Stamina: " << npcs[i].m_STA;
			cout << "\n Strength: " << npcs[i].m_STR;
			cout << "\n XP: " << npcs[i].m_XP;
			if (npcs[i].m_Armed == true)
			{
				cout << "\n Armed?: Yes";
			}
			else { cout << "\n Armed?: No"; }
			if (npcs[i].m_IsAlive == true)
			{
				cout << "\n Alive?: Yes";
			}
			else { cout << "\n Alive?: No"; }
			cout << "\n";
		}
	}
		break;
	case 3:
	{
		// Clear Screen
		system("cls");

		cout << "\n Option Unavailable";
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