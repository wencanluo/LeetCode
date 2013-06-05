/*Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3]

Author: Wencan Luo
Language: C++
Date: 09/02/2012
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	
	//use the number unlimited time
    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<vector< pair<int,int> > > s;
		s.resize(target+1);

		//get rid of duplicate ones
		sort(num.begin(), num.end());
		vector<int>::iterator qit = unique(num.begin(), num.end());
		num.resize(qit - num.begin());

		s[0].push_back(make_pair(0,0));
		for(int it = 0; it < num.size() && num[it] <= target; it++)
		{
			for(int i = 0; (num[it]+i)<= target; i++)
			{
				if(s[i].size() > 0)// s[i] is reachable
				{
					if(find(s[i+num[it]].begin(), s[i+num[it]].end(), make_pair(i,num[it])) == s[i+num[it]].end())
						s[i+num[it]].push_back(make_pair(i,num[it]));
				}
			}
		}

		//extract the res
		vector< vector< vector<int> > > rv;
		rv.resize(target + 1);
		for(int i = 1; i <= target; i++)
		{
			vector< pair<int,int> > p = s[i];

			for(vector< pair<int,int> >::iterator itp = p.begin(); itp < p.end(); itp ++)
			{
				if(itp-> first == 0)
				{
					vector<int> tmp;
					tmp.push_back(itp->second);
					if(find(rv[i].begin(), rv[i].end(), tmp) == rv[i].end())
						rv[i].push_back(tmp);
				}
				else
				{
					for(vector< vector<int> >::iterator itv = rv[itp->first].begin(); itv < rv[itp->first].end(); itv ++)
					{
						vector<int> tmp(itv->begin(), itv->end());
						tmp.push_back(itp->second);
						//sort(tmp.begin(), tmp.end());
						//if(find(rv[i].begin(), rv[i].end(), tmp) == rv[i].end())
						rv[i].push_back(tmp);		
					}
				}
			}
		}

		for(vector<vector<int> >::iterator it = rv[target].begin(); it < rv[target].end(); it++)
		{
			vector<int> tmp;

			for(vector<int>::iterator it2 = it->begin(); it2 < it->end(); it2++)
			{
				tmp.push_back(*it2);
			}
			
			sort(tmp.begin(), tmp.end());

			if(find(res.begin(), res.end(), tmp) == res.end())
				res.push_back(tmp);
		}

		return res;
    }

	//use the number only once
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<vector< pair<int,int> > > s;
		vector<vector< pair<int,int> > > s2;
		s.resize(target+1);
		s2.resize(target+1);

		sort(num.begin(), num.end());
		s[0].push_back(make_pair(0,0));
		for(int it = 0; it < num.size() && num[it] <= target; it++)
		{
			//copy s to s2 and update s2
			s2 = s;

			for(int i = 0; (num[it]+i)<= target; i++)
			{
				if(s[i].size() > 0)// s[i] is reachable
				{
					if(find(s2[i+num[it]].begin(), s2[i+num[it]].end(), make_pair(i,it)) == s2[i+num[it]].end())
						s2[i+num[it]].push_back(make_pair(i,it));//record the position of the number
				}
			}

			s = s2;
		}

		//extract the res
		vector< vector< vector<int> > > rv;
		rv.resize(target + 1);
		for(int i = 1; i <= target; i++)
		{
			vector< pair<int,int> > p = s[i];

			for(vector< pair<int,int> >::iterator itp = p.begin(); itp < p.end(); itp ++)
			{
				if(itp-> first == 0)
				{
					vector<int> tmp;
					tmp.push_back(itp->second);
					if(find(rv[i].begin(), rv[i].end(), tmp) == rv[i].end())
						rv[i].push_back(tmp);
				}
				else
				{
					for(vector< vector<int> >::iterator itv = rv[itp->first].begin(); itv < rv[itp->first].end(); itv ++)
					{
						if(find(itv->begin(), itv->end(), itp->second) == itv->end())//no duplicate, good one
						{
							vector<int> tmp(itv->begin(), itv->end());
							tmp.push_back(itp->second);
							sort(tmp.begin(), tmp.end());
							if(find(rv[i].begin(), rv[i].end(), tmp) == rv[i].end())
								rv[i].push_back(tmp);		
						}	
					}
				}
			}
		}

		for(vector<vector<int> >::iterator it = rv[target].begin(); it < rv[target].end(); it++)
		{
			vector<int> tmp;

			for(vector<int>::iterator it2 = it->begin(); it2 < it->end(); it2++)
			{
				tmp.push_back(num[*it2]);
			}
			
			sort(tmp.begin(), tmp.end());

			if(find(res.begin(), res.end(), tmp) == res.end())
				res.push_back(tmp);
		}

		return res;
    }
};

void main()
{
	int a[] = {8,7,4,3};
	//int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> candidates(a, a + sizeof(a)/sizeof(int));
	int target = 11;

	Solution s;
	vector<vector<int> > res = s.combinationSum(candidates, target);
	for(vector<vector<int> >::iterator it = res.begin(); it < res.end(); it++)
	{
		for(vector<int>::iterator it2 = it->begin(); it2 < it->end(); it2++)
		{
			cout << *it2 << ", ";
		}
		cout<<endl;
	}

	system("pause");
}