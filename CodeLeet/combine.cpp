/*
Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


Author: Wencan Luo
Language: C++
Date: 09/02/2012
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;

		if(k == 1)
		{
			for(int i=1;i<=n;i++)
			{
				vector<int> tmp;
				tmp.push_back(i);
				res.push_back(tmp);
			}
			return res;
		}

		if(n < k) return res;

		if(n == k)
		{
			vector<int> tmp;

			for(int i=1;i<=n;i++)
			{
				tmp.push_back(i);
			}
			res.push_back(tmp);

			return res;
		}

		//s(n,k) = s[i] + s(n-i,k-1), i = [k, n]
		for(int i = k; i <= n; i++)
		{
			vector< vector<int> > res_i = combine(i-1, k-1);

			for( vector< vector<int> >::iterator it = res_i.begin(); it < res_i.end(); it++)
			{
				vector<int> tmp(it->begin(), it->end());
				tmp.push_back(i);
				res.push_back(tmp);
			}
		}

		return res;
    }
};

void main()
{
	Solution s;

	vector<vector<int> > res = s.combine(4,2);

	for(vector<vector<int> > ::iterator it = res.begin(); it < res.end(); it++)
	{
		for(vector<int>::iterator itj = it->begin(); itj < it->end(); itj++)
		{
			cout << *itj <<", ";
		}

		cout<<endl;
	}

	system("pause");
}