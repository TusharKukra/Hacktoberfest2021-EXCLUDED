#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"

void displayAllParticipantsWithEvents(const struct Participant participants[], const int numberOfParticipants)
{
	int i, j;
	char dayOfWeek[4];
	char monthInMMM[4];
	for (i = 0; i < numberOfParticipants; i++)
	{
		printf("%s\n", participants[i].name);
		puts("----------------------------------------------");

		j = 0;
		do
		{
			convertDayToDayOfWeek(zeller(&participants[i].activities[j].date), dayOfWeek); // get day of the week value, store in dayOfWeek string
			convertMonthValueToMMM(participants[i].activities[j].date.month, monthInMMM);  // get month in MMM format, store in monthInMMM string

			if (participants[i].activities[j].activityType == 's')
			{
				printf("%5s %3s %3s %02d %5.1lf", "swim", dayOfWeek, monthInMMM, participants[i].activities[j].date.day, participants[i].activities[j].distance);
			}
			else if (participants[i].activities[j].activityType == 'r')
			{
				printf("%5s %3s %3s %02d %5.1lf", "run", dayOfWeek, monthInMMM, participants[i].activities[j].date.day, participants[i].activities[j].distance);
			}
			else if (participants[i].activities[j].activityType == 'b')
			{
				printf("%5s %3s %3s %02d %5.1lf", "bike", dayOfWeek, monthInMMM, participants[i].activities[j].date.day, participants[i].activities[j].distance);
			}

			dayOfWeek[0] = '\0'; //reset the value of dayOfWeek

			puts("");
		} while (participants[i].activities[j++].activityType != '\0');

	}
}

int findParticipant(const struct Participant participants[], const int count, const char name[MAX_ACTIVITY_NAME_LEN])
{
	int i;
	for (i = 0; i < count; i++)
	{
		int isFound = strcmp(participants[i].name, name);

		if (isFound == 0)
		{
			return i;
		}

		if (participants[i].name[0] == '\0')
		{
			return i;
		}
	}

	return -1;
};

double getTotalOfParticipant(const struct Participant participants[], const char name[], const char activityType)
{
	int i, t; double sum = 0;
	for (i = 0; i < NUM_ACTIVITY_NAMES; i++)
	{
		if (strcmp(participants[i].name, name) == 0)
		{
			for (t = 0; t < NUM_ACTIVITY_NAMES; t++)
			{
				if (participants[i].activities[t].activityType == activityType)
				{
					sum += participants[i].activities[t].distance;
				}
			}
		}
	}
	return sum;
}

void displayTotalDistance(const struct Participant participants[], const int numberOfParticipants, const char activityType[])
{
	struct toSortStruct sortedStruct[MAX_PARTICIPANTS];

	printf("     *** TOTAL %s ***\n", activityType);

	int i;
	for (i = 0; i < numberOfParticipants; i++)
	{
		strcpy(sortedStruct[i].name, participants[i].name);
		sortedStruct[i].valueToSort = getTotalOfParticipant(participants, participants[i].name, tolower(activityType[0]));
	}

	sortStruct(sortedStruct, numberOfParticipants);

	for (i = 0; i < numberOfParticipants; i++)
	{
		printf("%16s", sortedStruct[i].name);
		printf("%7.1lf\n", sortedStruct[i].valueToSort);
	}

	puts("");
}

double getBestOfParticipant(const struct Participant participants[], const char name[], const char activityType)
{
	int i, t; double top = 0;
	for (i = 0; i < NUM_ACTIVITY_NAMES; i++)
	{
		if (strcmp(participants[i].name, name) == 0)
		{
			for (t = 0; t < NUM_ACTIVITY_NAMES; t++)
			{
				if (participants[i].activities[t].activityType == activityType)
				{
					if (participants[i].activities[t].distance > top)
					{
						top = participants[i].activities[t].distance;
					}
				}
			}
		}
	}
	return top;
}

void displayBestDistance(const struct Participant participants[], const int numberOfParticipants, const char activityType[])
{
	struct toSortStruct sortedStruct[MAX_PARTICIPANTS];

	printf("     *** TOP %s ***\n", activityType);

	int i;
	for (i = 0; i < numberOfParticipants; i++)
	{
		strcpy(sortedStruct[i].name, participants[i].name);
		sortedStruct[i].valueToSort = getBestOfParticipant(participants, participants[i].name, tolower(activityType[0]));
	}

	sortStruct(sortedStruct, numberOfParticipants);

	for (i = 0; i < numberOfParticipants; i++)
	{
		printf("%16s", sortedStruct[i].name);
		printf("%7.1lf\n", sortedStruct[i].valueToSort);
	}

	puts("");
}
char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int maxActivities, char activity[])
{
	int i;
	for (i = 0; i < maxActivities; i++)
	{
		if (strcmp(activNames[i], activity) == 0)
			return activity[0];
	}
	return "";
}

void sortStruct(struct toSortStruct toSortStruct[], int size)
{
	int i, j;
	struct toSortStruct toSortStructTemp;
	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (toSortStruct[j].valueToSort < toSortStruct[j + 1].valueToSort)
			{
				toSortStructTemp = toSortStruct[j];
				toSortStruct[j] = toSortStruct[j + 1];
				toSortStruct[j + 1] = toSortStructTemp;
			}
		}
	}
}
