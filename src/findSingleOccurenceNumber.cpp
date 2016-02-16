/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>

int findSingleOccurenceNumber(int *A, int len)
{
	if (A == NULL || len < 1 || len % 3 == 2 || len % 3 == 0)
		return -1;
	int index = 0, result, temp1, temp2;
	for (temp1 = 0; temp1 < len; temp1++) {
		for (temp2 = 0; temp2 < len - 1; temp2++)
			if (A[temp1] == A[temp2] && temp1 != temp2)
				break;
		if (temp2 == len - 1)
			result = A[temp1];
	}
	return result;
}