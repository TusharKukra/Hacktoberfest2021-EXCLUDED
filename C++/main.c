
#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
int main()
{
	struct Participant participants[MAX_PARTICIPANTS] = { { 0 } };
	int participantCount;
	FILE* fp = NULL;
	fp = fopen(FILE_NAME, "r");
	char activities[][MAX_ACTIVITY_NAME_LEN + 1] = { "run", "bike", "swim" };

	if (fp != NULL)
	{
		printf("Read %d participants \n\n", participantCount = readActivityFile(fp, participants, activities));

		fclose(fp);
	}

	int flag = 0;

	do
	{
		switch (menu())
		{
		case 0:
			//exit the program
			puts("Goodbye");
			flag = 1;
			break;

		case 1:
			//list all participants and events
			displayAllParticipantsWithEvents(participants, participantCount);
			break;

		case 2:
			//list total run distances
			displayTotalDistance(participants, participantCount, "RUNS");
			break;

		case 3:
			//list total swim distances
			displayTotalDistance(participants, participantCount, "SWIMS");
			break;

		case 4:
			//list total bike distances
			displayTotalDistance(participants, participantCount, "BIKES");
			break;

		case 5:
			//list best run distances
			displayBestDistance(participants, participantCount, "RUNS");
			break;

		case 6:
			//list best swim distances
			displayBestDistance(participants, participantCount, "SWIMS");
			break;

		case 7:
			//list best bike distances
			displayBestDistance(participants, participantCount, "BIKES");
			break;

		default:
			break;
		}

	} while (!flag);
}
