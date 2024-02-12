/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P2)
Full Name  : Dev Kshitij patel
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
	int treasureCount;
	int positionHistory[maxpLength];
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
	int i, j, n;
	int remainingMoves, remainingLives, nextMove = maxpLength + 1;
	int count = 0;

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

		if (gameInfo.moves < 3 || gameInfo.moves>(int)(0.75 * gameInfo.pLength))
		{
			printf("    Value must be between %d and %d\n", playerInfo.lives, (int)(0.75 * gameInfo.pLength));
		}
	} while (gameInfo.moves < 3 || gameInfo.moves >(int)(0.75 * gameInfo.pLength));

	//Displaying Output
	printf("\n");

	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",gameInfo.pLength);

	//For loop used for Bomb
	for (i = 0;i < gameInfo.pLength;i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &gameInfo.bomb[i], &gameInfo.bomb[i + 1], &gameInfo.bomb[i + 2], &gameInfo.bomb[i + 3], &gameInfo.bomb[i + 4]);
	}

	//Displaying Output
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");

	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",gameInfo.pLength);


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

	//Displaying Output
	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");


	//Giving Values
	remainingMoves = gameInfo.moves;
	remainingLives = playerInfo.lives;
	playerInfo.treasureCount = 0;
	char presentPosition[maxpLength];
	char objectPosition[maxpLength];
	int x, y, m;

	//for loop for positionHistory
	for (x = 0;x < gameInfo.pLength;x++)
	{
		playerInfo.positionHistory[x] = 0;
	}

	//for loop for objectPosition
	for (y = 0;y < gameInfo.pLength;y++)
	{
		objectPosition[y] = '-';
	}

	//for loop for presentPosititon
	for (m = 0;m < gameInfo.pLength;m++)
	{
		presentPosition[m] = ' ';
	}

	//do-while loop
	do {
		//printing the first line
		for (m = 0;m < gameInfo.pLength;m++)
		{
			if (presentPosition[m] == 'V')
			{
				count++;
			}
		}
		if (count == 0)
		{
			printf("\n");
		}
		else
		{
			printf("  ");
			for (m = 0;m < gameInfo.pLength;m++)
			{
				if (presentPosition[m] == 'V')
				{
					printf("%c\n", presentPosition[m]);
					break;
				}
				else
				{
					printf("%c", presentPosition[m]);
				}
			}
		}

		//for loop used to dissapear previous position
		for (m = 0;m < gameInfo.pLength;m++)
		{
			presentPosition[m] = ' ';
		}

		//printing the seconf line
		printf("  ");
		for (y = 0;y < gameInfo.pLength;y++)
		{
			printf("%c", objectPosition[y]);
		}
		printf("\n");

		//printing the third line
		printf("  ");
		for (n = 1;n <= gameInfo.pLength;n++)
		{
			//to check whether it is multiple of 10 or not
			if (n % 10 == 0)
			{
				printf("%d", (int)n / 10);
			}
			else
			{
				printf("|");
			}
		}
		printf("\n");

		//printing the fourth line
		printf("  ");
		for (n = 0;n < gameInfo.pLength;n += 10)
		{
			printf("1234567890");
		}
		printf("\n");

		//Displaying Output
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remainingLives, playerInfo.treasureCount, remainingMoves);
		printf("+---------------------------------------------------+\n");

		//what if lives are zero, quit
		if (remainingLives == 0)
		{
			break;
		}

		//what if moves are zero, quit
		if (remainingMoves == 0)
		{
			break;
		}

		//do-while loop for asking for next move
		do {
			printf("Next Move [1-20]: ");
			scanf("%d", &nextMove);

			if (nextMove<1 || nextMove>gameInfo.pLength)
			{
				printf("  Out of Range!!!\n");
			}
		} while (nextMove<1 || nextMove>gameInfo.pLength);
		printf("\n");

		if (playerInfo.positionHistory[nextMove - 1] == 1)
		{
			printf("===============> Dope! You've been here before!\n\n");
			presentPosition[nextMove - 1] = 'V';
			remainingMoves++;
		}

		else if (gameInfo.bomb[nextMove - 1] == 1 && gameInfo.treasure[nextMove - 1] == 1)
		{
			printf("===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
			presentPosition[nextMove - 1] = 'V';
			remainingLives--;
			playerInfo.treasureCount++;
			objectPosition[nextMove - 1] = '&';
		}

		else if (gameInfo.bomb[nextMove - 1] == 1)
		{
			printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
			presentPosition[nextMove - 1] = 'V';
			remainingLives--;
			objectPosition[nextMove - 1] = '!';
		}

		else if (gameInfo.treasure[nextMove - 1] == 1)
		{
			printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			presentPosition[nextMove - 1] = 'V';
			playerInfo.treasureCount++;
			objectPosition[nextMove - 1] = '$';
		}

		else
		{
			printf("===============> [.] ...Nothing found here... [.]\n\n");
			presentPosition[nextMove - 1] = 'V';
			objectPosition[nextMove - 1] = '.';
		}

		playerInfo.positionHistory[nextMove - 1] = 1;

		remainingMoves--;
		if (remainingLives == 0)
		{
			printf("No more LIVES remaining!\n\n");
		}
		if (remainingMoves == 0)
		{
			printf("No more MOVES remaining!\n\n");
		}
	} while (remainingMoves >= 0 && remainingLives >= 0);

	//Displaying Output
	printf("\n##################");
	printf("\n#   Game over!   #");
	printf("\n##################");
	printf("\n\nYou should play again and try to beat your score!\n");


	return 0;
}