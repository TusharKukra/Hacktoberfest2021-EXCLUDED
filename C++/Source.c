#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
#define MIN 1
#define MAX 10
#define MACRO 3

{
	const double NET_MIN = 500;
	const double NET_MAX = 400000;
	const double MINI_COST = 100.0;
	const int MINI_PR = 1;
	const int MAX_PR = 3;
	double netincome, sum = 0;
	int items, i, j;
	int wish[] = { 0,1,2 };

	int flag = 0;
	double cost[MAX];
	int priority[MAX];
	char finance[MAX];
	printf("+ -------------------------- + \n");
	printf("+    Wish List Forecaster    + \n");
	printf("+ -------------------------- + \n");
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &netincome);
		if (netincome < NET_MIN)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		if (netincome > NET_MAX)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}

	} while (netincome > NET_MAX || netincome < NET_MIN);

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &items);
		if (items > MAX || items < MIN)

		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

	} while (items > MAX || items < MIN);

	for (i = 0; i < items; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] < MINI_COST)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}

		} while (cost[i] < MINI_COST);
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i] < MINI_PR || priority[i] > MAX_PR)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}

		} while (priority[i] < MINI_PR || priority[i] > MAX_PR);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%*c%c", &finance[i]);
			if ((finance[i] != 'n' && finance[i] != 'y'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

		} while (finance[i] != 'n' && finance[i] != 'y');
		sum += cost[i];
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < items; i++)
	{
		printf("%3d%7d%9c%15.2lf\n", i + 1, priority[i], finance[i], cost[i]);
	}
	printf("---- -------- -------- -----------\n");
	printf("%23c%11.2lf\n\n", '$', sum);
	printf("Best of luck in all your future endeavours!\n");
	
		do
		{
			printf("How do you want to forecast your wish list?\n");
			printf(" 1. All items (no filter)");
			printf(" 2. By priority");
			printf(" 0. Quit/Exit");
			printf("Selection: %d", &wish[3]);
			if (j < 0 || j > 3)
			{
				printf("ERROR: Invalid menu selection.");
				flag = 1;
			}
			if (j == 1)
			{
				printf("====================================================");
				printf("Filter:  All items");
				flag == 0;
			}
		} while (flag);

	

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}
