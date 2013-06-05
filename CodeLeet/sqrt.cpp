/*Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.

See other fast solution:
//http://www.lomont.org/Math/Papers/2003/InvSqrt.pdf
//For sqrt1,sqrt2,and sqrt3 all Credit goes to http://ilab.usc.edu/wiki/index.php/Fast_Square_Root

Author: Wencan Luo
Language: C++
Date: 09/02/2012
*/

#include<iostream>
using namespace std;

class Solution {
public:
	int sqrt(int n) {//Newton's Method, f(x) = x^2 - n, f'(x) = 2x, x' = x - f(x)/f('x)
		if(n == 0) return 0;
		float x = n/2.;
		float x0 = 0;

		while(x != x0)
		{
			x0 = x;
			x = x0/2.+n/(2.*x0);
		}

		int res = (int)x;
		if(res*res > n) return res-1;
		return res;
	}

	int sqrt_log(int x) {//O(log n), binary search
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(x < 0) return -1;
		if(x == 0) return 0;
		int res;

		long long begin = 0;
		long long end = x;
		long long mid = -1;

		while(begin < end)
		{
			mid = (begin+end)/2; //be sure that it will be overflow
			if(mid*mid == x)
			{
				return mid;
			}
			else if(mid*mid < x)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		
		//search
		for(int i=end-1; i <= begin; i++)
		{
			if(i*i > x)
			{
				return i-1;
			}
		}


		return (begin+end)/2;
    }

    int sqrt_sqrtn(int x) {//O(sqrt(n)), linear search
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(x < 0) return -1;

		//0 <= sqrt(x) <= x/2
		long long i; //to avoid overflow
		for(i=0; i*i<=x; i++){}
		
		return i-1;
    }
};

void main()
{
	Solution s;

	int i=2147395599;
	//for(int i=0;i<100;i++)
	{
		int res = s.sqrt_log(i);
		cout << i << "\t" << res <<endl;
	}

	system("pause");
}