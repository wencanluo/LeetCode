/*
First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
c) Replace a character

Author: Wencan Luo
Language: C++
Date: 11/06/2012
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {//O(3n), Whenever there is an exchange, the number of correct order will increase at 1, therefore, the max number of exchange will be most n;
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n==0) return 1; //always check the boundary

		int k;
		int i = 0;
		while(i < n)
		{
			if(A[i] > 0 && A[i] <= n)//Check whether it is negative or out of range
			{
				if( A[i] != i+1 && A[A[i]-1] != A[i])//if they are the same, do NOT need to exchange
				{
					//change A[i] to A[A[i]-1]
					int t = A[A[i]-1];
					A[A[i]-1] = A[i];
					A[i] = t;
					continue;
				}
			}
			i++;
		}

		for(k=0;k<n;k++)
		{
			if(A[k] != k+1) break;
		}

        return k+1;
    }
};

void main()
{
	Solution s;
	int A[] = {0};
	int d = s.firstMissingPositive(A, sizeof(A)/sizeof(A[0]));

	cout << d << endl;
	system("pause");
}