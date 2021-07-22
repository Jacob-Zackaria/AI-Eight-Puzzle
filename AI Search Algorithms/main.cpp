
// user defined classes
#include "SolveMethod.h"

/*
* Program Start.
* 
*/

// Function prototypes
void Menu();
int GetInput(int* a);
void FillEasy(int* a);
void FillMedium(int* a);
void FillHard(int* a);
void FillUser(int* a);

int main()
{
	// Input array. { Initialize to zero }
	int a[9] = { 0 };

	// fill input array.
	while (GetInput(a) != 5)
	{
		// Get solving method input
		switch (SolveMethod::GetInput())
		{
		case 1:SolveMethod::BreadthFirstSearch(a); 
			break;
		case 2:SolveMethod::DepthFirstSearch(a);
			break;
		case 3:SolveMethod::IteartiveSearch(a);
			break;
		case 4:SolveMethod::UniformCostSearch(a);
			break;
		case 5:SolveMethod::BestFirstSearch(a);
			break;
		case 6:SolveMethod::AStar1(a);
			break;
		case 7:SolveMethod::AStar2(a);
			break;
		case 8:SolveMethod::AStar3(a);
			break;
		default: // Go back to main menu
			break;
		}
	}

	// reuturn success.
	return (0);
}


int GetInput(int* a)
{
	// input menu options.
	int option = 0;	

	do {
		system("CLS");
		// display menu
		Menu();
		RETURN_NOT_USED(scanf_s("%d", &option));

		switch (option)
		{
		case 1:
			FillEasy(a); // Fill easy level
			break;
		case 2:
			FillMedium(a); // Fill medium level 
			break;
		case 3:
			FillHard(a); // Fill hard level
			break;
		case 4:
			FillUser(a); // FIll by user
			break;
		case 5: // Exit program
			break;
		default:
			printf("\n\n WRONG INPUT\n");
			system("pause");
			break;
		}
	} while (option < 0 || option > 5);

	return (option);
}

// Fill easy level
void FillEasy(int* a)
{
	a[0] = 1; a[1] = 3;	a[2] = 4;
	a[3] = 8; a[4] = 6;	a[5] = 2;
	a[6] = 7; a[7] = 0;	a[8] = 5;
}

// Fill medium level
void FillMedium(int* a)
{
	a[0] = 2; a[1] = 8;	a[2] = 1;
	a[3] = 0; a[4] = 4;	a[5] = 3;
	a[6] = 7; a[7] = 6;	a[8] = 5;
}

// Fill hard level
void FillHard(int* a)
{
	a[0] = 5; a[1] = 6;	a[2] = 7;
	a[3] = 4; a[4] = 0;	a[5] = 8;
	a[6] = 3; a[7] = 2;	a[8] = 1;
}

// User fill
void FillUser(int* a)
{
	for (int i = 0; i < 9; i++)
	{
		printf("\n a[%d] = ", i);
		RETURN_NOT_USED(scanf_s("%d", a + i));
	}
}

// Menu to display
void Menu()
{
	printf("\t\t EIGHT PUZZLE\n");
	printf("\n 1) EASY");
	printf("\n 2) MEDIUM");
	printf("\n 3) HARD");
	printf("\n 4) USER INPUT");
	printf("\n 5) EXIT");
	printf("\n\n >> ");
}