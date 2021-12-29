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
	float m_Radius = 0;

	float getArea() {
		float circleArea = pi * (m_Radius * m_Radius);
		return circleArea;
	}
	float getCircumference() {
		float circleCircumference = 2 * pi * m_Radius;
		return circleCircumference;
	}
};

class Square {
public:
	float m_SideLength = 0;

	float getArea() {
		float squareArea = m_SideLength * m_SideLength;
		return squareArea;
	}
	float getPerimeter() {
		float squarePerimeter = 4 * m_SideLength;
		return squarePerimeter;
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
	bool m_Armed = true;        // Character Armed?
	bool m_IsAlive = true;      // Character Alive?

	void checkIsAlive() {
		// Workshop does not use this function
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
		Character pc, npc_Steve, npc_Jessica, npc_Keith; // Character Objects

		// Player Character Stats
		pc.m_HP = 100;
		pc.m_SPD = 5;
		pc.m_STA = 5;
		pc.m_STR = 5;
		pc.m_XP = 0;
		pc.m_Name = "Dean The Hero";
		pc.m_Weapon = "Steel Longsword";
		pc.m_Armed = true;
		pc.m_IsAlive = true;

		// Display Player Character Stats
		cout << "\n Name: " << pc.m_Name;
		cout << "\n Weapon: " << pc.m_Weapon;
		cout << "\n HP: " << pc.m_HP;
		cout << "\n Speed: " << pc.m_SPD;
		cout << "\n Stamina: " << pc.m_STA;
		cout << "\n Strength: " << pc.m_STR;
		cout << "\n XP: " << pc.m_XP;
		cout << "\n Armed?: " << pc.m_Armed;
		cout << "\n Alive?: " << pc.m_IsAlive;
		cout << "\n";

		// Non-Playable Character Steve Stats
		npc_Steve.m_HP = 0;
		npc_Steve.m_SPD = 1;
		npc_Steve.m_STA = 1;
		npc_Steve.m_STR = 1;
		npc_Steve.m_XP = 100;
		npc_Steve.m_Name = "Steve The Merchant";
		npc_Steve.m_Weapon = "None";
		npc_Steve.m_Armed = false;
		npc_Steve.m_IsAlive = false;

		// Display NPC Steve Stats
		cout << "\n Name: " << npc_Steve.m_Name;
		cout << "\n Weapon: " << npc_Steve.m_Weapon;
		cout << "\n HP: " << npc_Steve.m_HP;
		cout << "\n Speed: " << npc_Steve.m_SPD;
		cout << "\n Stamina: " << npc_Steve.m_STA;
		cout << "\n Strength: " << npc_Steve.m_STR;
		cout << "\n XP: " << npc_Steve.m_XP;
		cout << "\n Armed?: " << npc_Steve.m_Armed;
		cout << "\n Alive?: " << npc_Steve.m_IsAlive;
		cout << "\n";

		// Non-Playable Character Jessica Stats
		npc_Jessica.m_HP = 50;
		npc_Jessica.m_SPD = 3;
		npc_Jessica.m_STA = 4;
		npc_Jessica.m_STR = 3;
		npc_Jessica.m_XP = 50;
		npc_Jessica.m_Name = "Jessica The Farmgirl";
		npc_Jessica.m_Weapon = "None";
		npc_Jessica.m_Armed = false;
		npc_Jessica.m_IsAlive = true;

		// Display NPC Jessica Stats
		cout << "\n Name: " << npc_Jessica.m_Name;
		cout << "\n Weapon: " << npc_Jessica.m_Weapon;
		cout << "\n HP: " << npc_Jessica.m_HP;
		cout << "\n Speed: " << npc_Jessica.m_SPD;
		cout << "\n Stamina: " << npc_Jessica.m_STA;
		cout << "\n Strength: " << npc_Jessica.m_STR;
		cout << "\n XP: " << npc_Jessica.m_XP;
		cout << "\n Armed?: " << npc_Jessica.m_Armed;
		cout << "\n Alive?: " << npc_Jessica.m_IsAlive;
		cout << "\n";

		// Non-Playable Character Keith Stats
		npc_Keith.m_HP = 0;
		npc_Keith.m_SPD = 5;
		npc_Keith.m_STA = 5;
		npc_Keith.m_STR = 5;
		npc_Keith.m_XP = 500;
		npc_Keith.m_Name = "Keith The Thief";
		npc_Keith.m_Weapon = "Iron Dagger";
		npc_Keith.m_Armed = true;
		npc_Keith.m_IsAlive = false;

		// Display NPC Keith Stats
		cout << "\n Name: " << npc_Keith.m_Name;
		cout << "\n Weapon: " << npc_Keith.m_Weapon;
		cout << "\n HP: " << npc_Keith.m_HP;
		cout << "\n Speed: " << npc_Keith.m_SPD;
		cout << "\n Stamina: " << npc_Keith.m_STA;
		cout << "\n Strength: " << npc_Keith.m_STR;
		cout << "\n XP: " << npc_Keith.m_XP;
		cout << "\n Armed?: " << npc_Keith.m_Armed;
		cout << "\n Alive?: " << npc_Keith.m_IsAlive;
		cout << "\n";
	}
		break;
	case 3:
	{
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