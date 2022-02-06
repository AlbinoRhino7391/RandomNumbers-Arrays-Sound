// RandomNumbers,Arrays,Sound-P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//Creator Information:
/*
Name: Eric Phelps
Professor: Juan Rodriguez
Date Completed: 20220204
Project Name: Random Numbers,Arrays,Sound P1
*/

/*
Goal:
Create an array of Rebels
create an array of Locations
Add user input to guess a location (1-64)
Add sound for the end of the game
*/


#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<Windows.h>



using namespace std;


int main()
{
		srand(static_cast<unsigned int>(time(0)));			//Random Number Generator,seeds
		
		// String Variables
		string rebels[10] = { "Kyle", "Sarah", "John", "O'brien", "Miles", "Kate", "Nancy", "Grace", "Carl", "Dani" };
		string locations[10] = { "Jungle", "river", "skyscraper", "metro", "subway", "phone booth", "construction site", "beach", "street", "Bodega" };

		int EnemyLocation = rand() % 64 + 1;				//Random number between 1 and 64, this is where a rebel is located

		int GridMax = 64;									//Sets roof at 64
		int GridMin = 1;									//Sets floor at 1

		int PilotPredictions = 1;							//user input prediction starts count at 1
		int AIPredictions = 1;								//Random AI prediction starts count at 1

		int PilotGuess;										//user input, try to guess where the rebel is located.
		int ScanLocation = rand() % 64 + 1;					//Random number between 1 and 64, this is the AIprediction location

		bool AIspotsEnemy = false;							//bool to determine if the AI spotted the enemy.
		bool PilotSpotsEnemy = false;						//bool to determine if the user spotted the enemy.

		

		//**Opening Narrative**//
		cout << "\n\t\t\t\t\t Welcome to Skynet.\n\n";
		cout << "As our search for John Conner and the resistance has continued,We are testing the newest in A.I UAV. The 'HK-Aerial'.\n\n";
		cout << "\n\t\t\t\t HK-Aerial Software Initalizing...\n\n";
		cout << "\t\tThis new software stragetically places an enemy randomly within an 8x8 Grid.\n";
		cout << "\t\t\tAllowing 1 of 64 random locations to be selected within the grid\n\n";
		cout << "\t\tNow for the test, who can locate these rebels faster, You or the machine?\n\n";


		//User Interaction loop
		do
		{
			cout << "\n\t\t\t\t\tTesting will now commence";
			cout << "\nPilot, please guess the enemy location between Grid 1 - 64: ";
			cin >> PilotGuess;
			cout << "\nPilot, your guess was: " << PilotGuess << "\n";

			//If user guess was too high...
			if (PilotGuess > EnemyLocation)
			{
				cout << "\nPilot, The enemy location is not in Grid # " << PilotGuess << " your guess was to high.\n\n";
				GridMax = PilotGuess;
				PilotPredictions++;
			}

			//If user guess was too low...
			if (PilotGuess < EnemyLocation)
			{
				cout << "\nPilot, The enemy location is not in Grid # " << PilotGuess << " your guess was to low.\n\n";
				GridMin = PilotGuess;
				PilotPredictions++;
			}

			//If Human guessed correctly...
			else if (PilotGuess == EnemyLocation)
			{
				PlaySound(L"GameCannonFire.wav", NULL, SND_FILENAME | SND_SYNC);
				cout << "\nEnemy was located in Grid # " << EnemyLocation << " \n\nCongratulations, Pilot, you guessed correctly.\n\n";
				PilotSpotsEnemy = true;
			}

		} while (!PilotSpotsEnemy);

		system("pause");


		//Create the search loop from the AI.
		do
		{
			cout << "\n\n\nHK-Aerial, Initializing Scans.\n\n";
			cout << "\n'HK-Aerial' Sending out Scan # " << AIPredictions << "\n";


			if (ScanLocation > EnemyLocation)
			{
				cout << "\nThe enemy location is not in Grid # " << ScanLocation << " number too high.\n";
				GridMax = ScanLocation;
				ScanLocation = ((GridMax - GridMin) / 2) + GridMin;
				AIPredictions++;
			}
			else if (ScanLocation < EnemyLocation)
			{
				cout << "\nThe enemy location is not in Grid # " << ScanLocation << " number too low.\n";
				GridMin = ScanLocation;
				ScanLocation = ((GridMax - GridMin) / 2) + GridMin;
				AIPredictions++;
			}
			if (ScanLocation == EnemyLocation)
			{
				PlaySound(L"GameCannonFire.wav", NULL, SND_FILENAME | SND_SYNC);
				cout << "\nThe enemy was located in Grid #" << EnemyLocation << "\n";
				cout << "\nEnemy Location Spotted. Only took 'HK-Aerial " << AIPredictions << " search attempts.\n";
				AIspotsEnemy = true;
			}

		} while (EnemyLocation != ScanLocation);

		system("pause");

		//Game Summary 
		cout << "\nIt took you " << PilotPredictions << " search attempts.\n";
		cout << "\nIt only took the new AI " << AIPredictions << " search attempts.\n";
		cout << "\n\t\tAs you can see, the machines are the way of the future.\n";
		cout << "\n\t\t They no longer need the assistance of humans.\n";
		PlaySound(L"SchoolBell.wav", NULL, SND_FILENAME | SND_SYNC);
		cout << "\n\t\t This concludes our research for today.";

		system("pause");

		return(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file