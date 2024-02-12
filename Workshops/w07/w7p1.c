/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
Full Name  : Dev Kshitij Patel
Student ID#: 142979228
Email      : dkpatel59@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//Macro-Directive
#define z 5//z refers to the multiple which is used in the code to check if the pLength is the multiple of 5 or not
#define maxpLength 70
#define minpLength 10
#define minlives 1
#define maxlives 10

//Defining the Structure named as player
struct player {
	char charater;
	int lives;

};

//Defining the Structure named as game
struct game {
	int pLength;
	int moves;
	int bomb[maxpLength];
	int treasure[maxpLength];
};

int main()
{

	struct player playerInfo; //variable of player structure is playerInfo
	struct game gameInfo; //variable of game structure is gameInfo
	int i,j,n;

	//Displaying Output
	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	//User input for the character that represent the player
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerInfo.charater);

	//Do-While loop for Number of Lives
	do {
		printf("Set the number of lives: ");
		scanf("%d%*c", &playerInfo.lives);

		if (playerInfo.lives < minlives || playerInfo.lives>maxlives)
		{
			printf("     Must be between 1 and 10!\n");
		}

	} while (playerInfo.lives < minlives || playerInfo.lives>maxlives);

	//Displaying Output
	printf("Player configuration set-up is complete\n\n");

	printf("GAME Configuration\n");
	printf("------------------\n");

	//Do-While loop for Path Length
	do {
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d%*c", &gameInfo.pLength);

		if ((gameInfo.pLength < minpLength || gameInfo.pLength>maxpLength) || (gameInfo.pLength % z != 0))
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	} while ((gameInfo.pLength < minpLength || gameInfo.pLength>maxpLength) || (gameInfo.pLength % z != 0));

	//Do-While loop for the Number of Moves
	do {
		printf("Set the limit for number of moves allowed: ");
		scanf("%d%*c", &gameInfo.moves);

		if (gameInfo.moves < 3 || gameInfo.moves> (int)(0.75*gameInfo.pLength))
		{
			printf("    Value must be between %d and %d\n",playerInfo.lives, (int)(0.75 * gameInfo.pLength));
		}
	} while (gameInfo.moves < 3 || gameInfo.moves > (int)(0.75 * gameInfo.pLength));

	//Displaying Output
	printf("\n");

	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	//For loop used for Bomb
	for (i = 0;i < gameInfo.pLength;i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1,i+5);
		scanf("%d %d %d %d %d", &gameInfo.bomb[i], &gameInfo.bomb[i+1], &gameInfo.bomb[i+2], &gameInfo.bomb[i+3], &gameInfo.bomb[i+4]);
	}
	
	//Displaying Output
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");

	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	
	//For loop used for Treasure
	for (i = 0;i < gameInfo.pLength;i += 5)
	{
	      printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
	      scanf("%d %d %d %d %d", &gameInfo.treasure[i], &gameInfo.treasure[i + 1], &gameInfo.treasure[i + 2], &gameInfo.treasure[i + 3], &gameInfo.treasure[i + 4]);
	}

	//Displaying Output
	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");

	printf("Player:\n");
	printf("   Symbol     : %c\n", playerInfo.charater);
	printf("   Lives      : %d\n", playerInfo.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", gameInfo.pLength);

	printf("   Bombs      : ");

	for (j = 0;j < gameInfo.pLength;j++)
	{
		printf("%d", gameInfo.bomb[j]);
	}

	printf("\n");
	
	printf("   Treasure   : ");
	
	for (n = 0;n < gameInfo.pLength;n++)
	{
		printf("%d", gameInfo.treasure[n]);
	}
	
	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n\n");

	return 0;
}