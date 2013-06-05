/*
Divide Two Integers
Divide two integers without using multiplication, division and mod operator.

Author: Wencan Luo
Language: C++
Date: 09/03/2012
*/
#include<iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend1, int divisor1) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // sub
		long long dividend = dividend1;
		long long divisor = divisor1;

		if( divisor == 0) return -1;
		if( dividend == 0) return 0;

		//process the negetive
		bool flag = true;
		if( dividend > 0 && divisor < 0)
		{
			flag = false;
			divisor = - divisor;
		}
		if( dividend < 0 && divisor > 0)
		{
			flag = false;
			dividend = - dividend;
		}
		if( dividend < 0 && divisor < 0)
		{
			dividend = - dividend;
			divisor = - divisor;
		}

		int res = 0;
		
		while(dividend >= divisor)
		{
			long long t = divisor;
			long long k=1;
			while(t <= dividend)
			{
				t = t << 1;
				k <<=1;
			}
			dividend -= t>>1;
			res += k>>1;
		}

		if(!flag) return -res;
		return res;
    }

    int divide_sub(int dividend, int divisor) {//O(dividend/divisor)
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // sub
		int res = 0;
		while(dividend > 0)
		{
			dividend -= divisor;
			res++;
		}

		return res;
    }
};

void main()
{
	Solution s;
	int res = s.divide(-999511578,-2147483648);
	cout << res <<endl;
	system("pause");
}