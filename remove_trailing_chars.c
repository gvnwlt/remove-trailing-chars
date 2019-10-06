#include <stdio.h> 
#include <unistd.h> 
#define MAX_CHAR 1000

int manipulate_line(char line[], int maxchar); 
void loading(); 

/* This program will remove any trailing tabs or blanks from 
	a line. Any blank lines will be deleted entirely. */ 


main()
{
	int i, program, char_count; 
	char input_line[MAX_CHAR];

	loading(); 
	printf("\n");
	while ((program = manipulate_line(input_line, MAX_CHAR)) > 0)
	{
		/* do something here */ 
		printf("Number of characters(including trailing spaces: %d\n", program); 
	}
	printf("\nDone!\n"); 

	return 0; 
}

/* takes input and manipulates it to remove trailing blanks and tabs. */ 
int manipulate_line(char line[], int maxchar)
{
	int i, j, bt, c; 

	bt = 2; 

	
	for (i = 0; i<maxchar && (c=getchar())!=EOF && c !='\n'; ++i) 
	{
		if (i < 1)
		{
			printf("Storing characters"); 
		}
		sleep(1); 
		printf("."); 
		fflush(stdout); 
		line[i] = c; 
	}
	++i; 
	line[i] = '\0';
	printf("\n"); 

	sleep(0.7);
	printf("Checking for uneccessary trailing characters...\n"); 
	if (line[i-bt] == ' ') 
	{			
		printf("Trailing characters found!\n");
		while (line[i-bt] == ' ')
		{
			sleep(1);
			if (bt > 2) 
			{
				printf("Another one!\n"); 
			}
			else 
			{
				printf("Prohibited trailing character found!\n");
			}
			++bt; 
		}
		line[i-bt] = '\0';
	}

	sleep(1);
	printf("Printing characters now...\n"); 
	j = 0; 
	while (line[j] != '\0')
	{
		sleep(1); 
		if (line[j] == '\n' || line[j] == '\0')
		{
			/* don't do shit */ 
			++j; 
		}
		else
		{
			printf("%c", line[j]); 
			fflush(stdout); 
			++j;
		}
		
	}
	printf("\n");

	if (c == EOF)
	{
		i = 0; 
	}

	return i; 
}

/* this is a little loading thing just to look cool */ 
void loading()
{
	int i;

	printf("WARNING!\n"); 
	sleep(1); 
	printf("This program seems to be very excited about everything...\n");
	sleep(1); 
	printf("Entering program ");
	for (i =5; i>=1; --i)
	{
		sleep(1);
		printf("%d ", i);
		fflush(stdout);  
	}
	printf(" Okay! Go ahead!\n"); 
}