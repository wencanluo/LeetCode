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
		if(n==0) return 1;

		int k = 0;

		while(k<n){
			while(A[k] != k+1 && (A[k] > 0 && A[k] <= n) && A[A[k]-1] != A[k] ){
				//switch A[A[k]-1], A[k]
				int t = A[A[k]-1];
				A[A[k]-1] = A[k];
				A[k] = t;
			}

			k++;
		}

		for(k=0;k<n;k++){
			if(A[k] != k+1) break;
		}
		return k+1;
    }
};

void main()
{
	Solution s;
	int A[] = {4,1,2,2};
	int d = s.firstMissingPositive(A, sizeof(A)/sizeof(A[0]));

	cout << d << endl;
	system("pause");
}