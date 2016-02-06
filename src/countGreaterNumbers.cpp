/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
int compare_strings(char a[], char b[]);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int temp1, count = 0, flag, temp2,flag1;
	for (temp2 = 0; temp2 < len; temp2++)
	{
		flag1=compare_strings(Arr[temp2].date, Arr[temp2 + 1].date);
		if (flag1 == 0)
			return 0;
	}

	
	for (temp1 = 0; temp1 < len; temp1++)
	{
		flag = compare_strings(Arr[temp1].date, date);
		count++;
		if (flag == 0)
			break;
            
	}
	if (flag != 0)
		return NULL;
	if (count == len&&flag == 0)
		return 0;
	else if (flag==0)
	{
		return len - count;
	}
	
	
	
}
int compare_strings(char a[], char b[])
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
