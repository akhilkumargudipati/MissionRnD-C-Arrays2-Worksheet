/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int compare_string(char a[], char b[]);
# define n 10
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction C[n];
	int temp1, temp2,temp3=0,count=0;
	if (A == NULL || B == NULL)
		return NULL;
	for (temp1 = 0; temp1 < ALen; temp1++)
	{

		for (temp2 = 0; temp2 < BLen; temp2++)
		{
			int flag = 1;
			flag = compare_string(A[temp1].date, B[temp2].date);
			if (flag == 0)
			{
				C[temp3] = A[temp1];
				++count;
				temp3++;
				break;
			}

		}
	}
	if (count == 0)
		return NULL;
	else
	{
		return C;
	}
}
int compare_string(char a[], char b[])
{
	int c = 0;

	while (a[c] == b[c]) {
		if (a[c] == '\0' || b[c] == '\0')
			break;
		c++;
	}

	if (a[c] == '\0' && b[c] == '\0')
		return 0;
	else
		return -1;
}
