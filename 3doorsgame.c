/******************************************************************************

Online C Compiler.
Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
int randomize(int maxVal)
{

	return (rand() % (int)(maxVal)) + 1;
}

int main()
{
	int seed = time(NULL);
	srand(seed);
	int doorNumber, i, doorwith_car, door_chosen;
	printf("Enter Number of Doors\n");
	scanf("%d", &doorNumber);
	int doors[doorNumber], goat_counter;
	char a;
	doorwith_car = randomize(doorNumber);
	door_chosen = randomize(doorNumber);
	printf("Chosen door is: %d, and there is a door with a car behind\n", door_chosen);
	for (i = 0, goat_counter = 0; i < doorNumber; i++)
	{
		if (i != (doorwith_car - 1) && i != (door_chosen - 1))
		{
			if (goat_counter == (doorNumber - 2))
				break;
			printf("We had a goat behind the door %d\n", (i + 1));
			goat_counter++;

		}
	}
	printf("Now the question is do you want to change the door or not?(Y/y or N/n)\n");
	scanf(" %c", &a);
	if (a == 'N' || a == 'n')
	{
		if (door_chosen == doorwith_car)
			printf("Congrats! You have won a car!!!\n");
		else
			printf("Sorry, maybe next time\n");
	}
	else if (a == 'y' || a == 'Y')
	{
		if (door_chosen != doorwith_car)
			printf("Congrats! You have won a car!!!\n");
		else
			printf("Sorry, maybe next time\n");
	}
	return 0;
}
