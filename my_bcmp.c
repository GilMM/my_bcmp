#include "my_bcmp.h"

/* this function gets 2 pointers to a memory and compares their first "len" bytes.
if they are of the same value it returns 0.
if the first memory's value is bigger than second memory's value it returns 1.
if the first memory's value is smaller than second memory's value it returns -1. */
int my_bcmp(const void* b1, const void* b2, int len)
{
	char* b1CurCh;
	char* b2CurCh;
	int i;

	if (b1 == b2)
		return 0;

	b1CurCh = (char*)b1;
	b2CurCh = (char*)b2;

	/* check len bytes*/
	for (i = 0; i < len; i++)
	{
		if (*b1CurCh != *b2CurCh)
		{
			if (*b1CurCh > *b2CurCh)
			{
				return 1;
			}
			return -1;
		}
		b1CurCh++;
		b2CurCh++;
	}
	
	return 0;
}
/* the program gets from the user a string and 2 indexes to different locations of that string and another variable
for the number of bytes to comapre (len) and then calls the function that compares the first "len" bytes of the 2
sub-strings starting at the inputted indexes and prints the result to the output screen. */
int main()
{
	int strLen;
	int res, ind1, ind2, numBytes2Cmp;
	char str[STR_MAX_SIZE];
	char* b1;
	char* b2;
	printf("please enter 3 non-negative numbers (the index of the first string, "\
		"the index of the second string and the number of bytes to compare)\n");
	(void)scanf("%d%d%d\n", &numBytes2Cmp, &ind1, &ind2); /*  adding \n in order to remove the \n char from the input buffer (cleans the buffer).
	//getchar(); //  reads the \n char from the input buffer (cleans the buffer).*/
	fgets(str, STR_MAX_SIZE, stdin);
	/* check validity of the input*/
	strLen = (int)strlen(str);
	str[strLen - 1] = '\0'; /* removes the unwanted \n in case the user pressed [enter] */
	if (ind1 > strLen || ind1 < 0)
	{
		printf("the index of the first string must be bigger/equal than/to 0 and smaller than the string length\n");
		return 1;
	}
	if (ind2 > strLen || ind2 < 0)
	{
		printf("the index of the second string must be bigger/equal than/to 0 and smaller than the string length\n");
		return 1;
	}
	if (numBytes2Cmp > strLen || numBytes2Cmp < 0)
	{
		printf("the number of bytes to compare must be bigger/equal than/to 0 and smaller than the string length\n");
		return 1;
	}
	printf("the input number of bytes to compare is: %d, the index of the first string is: %d,"\
		" the index of the second string is: %d\n", numBytes2Cmp, ind1, ind2);
	b1 = str + ind1;
	b2 = str + ind2;
	res = my_bcmp(b1, b2, numBytes2Cmp);

	printf("%d bytes of the string \"%s\" starting at index %d are%sequal to the"\
		" %d bytes of the same string starting at index %d\n",
		numBytes2Cmp, str, ind1, res == 0 ? " " : " not ", numBytes2Cmp, ind2);
		
	return 0; /* error code 0 means no error*/
}

