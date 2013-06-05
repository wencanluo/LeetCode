/*
Pow(x, n)
Implement pow(x, n).


Author: Wencan Luo
Language: C++
Date: 09/03/2012
*/

#include<iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n==0) return 1;
        if(n==1) return x;
		if(n==-1) return 1./x;

		double res = pow(x,n/2);
		if(n%2 == 0)//x^n = x^(n/2) * x^(n/2)
		{
			return res*res;
		}
		else
		{
			return res*res*pow(x,n%2);
		}
    }
};

void main()
{
	Solution s;

	double res = s.pow(2, -3);
	cout << res << endl;

	system("pause");
}