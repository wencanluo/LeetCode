/*
Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top

Author: Wencan Luo
Language: C++
Date: 09/01/2012
*/

#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(n < 3) return n;

		int res = 0;
		int a = 1;
		int b = 2;

		for(int i = 3; i <= n; i++)
		{
			res = a + b;
			a = b;
			b = res;
		}

		return res;
    }
};

void main()
{
	int n = 5;

	Solution s;
	int res = s.climbStairs(n);

	cout << res <<endl;

	system("pause");
}