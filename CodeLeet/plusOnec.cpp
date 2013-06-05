/*
Plus One
Given a number represented as an array of digits, plus one to the number.

Author: Wencan Luo
Language: C++
Date: 09/03/2012
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;

		int flag = 0;

		//add the last one
		for(vector<int>::reverse_iterator it = digits.rbegin(); it < digits.rend(); it++)
		{
			int sum = 0;
			if(it == digits.rbegin())
			{
				sum = *it + 1;
			}
			else
			{
				sum = *it + flag;
			}
			
			if(sum >= 10)
			{
				sum -= 10;
				flag = 1;
			}
			else
			{
				flag = 0;
			}

			res.push_back(sum);
		}

		//add flag
		if(flag == 1)
		{
			res.push_back(1);
		}

		//reverse
		vector<int> r;
		for(vector<int>::reverse_iterator it = res.rbegin(); it < res.rend(); it++)
		{
			r.push_back(*it);
		}
		res = r;
		return res;
    }
};


void main()
{
	int a[] = {8, 9, 9, 9};
	vector<int> num(a, a + sizeof(a)/sizeof(int));

	Solution s;
	vector<int> sum = s.plusOne(num);

	vector<int>::iterator iter;

	for(iter=sum.begin();iter<sum.end();iter++)
	{
		cout << *iter << ",";
	}
	cout << endl;

	system("pause");

}