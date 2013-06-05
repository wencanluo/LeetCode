/*
Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.


Author: Wencan Luo
Language: C++
Date: 09/08/2012
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	 bool isletter(char c)
	 {
		 if(c >= '1' && c <= '9') return true;
		 return false;
	 }

	 bool isletter(char c1, char c2)
	 {
		if( (c1 == '1' && (c2 >= '0' && c2 <= '9')) || (c1 == '2' && (c2 >= '0' && c2 <= '6'))) //two
		{
			return true;
		}
	
		return false;
	 }

	 int numDecodings(string s) {//O(n), path number for dag graph
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int res = 0;
		if(s.size() == 0) return 0;

		vector< pair<int, int> > dag; //pair for a, pa
		dag.resize(s.size(),make_pair(0,0));

		for(int i = 0; i < s.size(); i++)
		{
			if(i == 0)
			{
				if(isletter(s[i]))
				{
					dag[i].first = 1;
					dag[i].second = 0;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				if(isletter(s[i]))
				{
					dag[i].first = 1;
				}
				else
				{
					dag[i].first = 0;
				}

				if(isletter(s[i-1],s[i]))
				{
					dag[i].second = 1;
				}
				else
				{
					dag[i].second = 0;
				}
			}
		}


		//go through the dag graph
		for(int i=0;i<dag.size();i++)
		{
			if(dag[i].first == 1)
			{
				if(i-1 >=0)
				{
					if(dag[i-1].first != 0 && dag[i-1].second != 0)
					{
						dag[i].first = dag[i-1].first + dag[i-1].second;
					}
					else if(dag[i-1].first != 0)
					{
						dag[i].first = dag[i-1].first;
					}
					else if(dag[i-1].second != 0)
					{
						dag[i].first = dag[i-1].second;
					}
					else
					{
						dag[i].first = 0;
					}
				}				
			}

			if(dag[i].second == 1)
			{
				if(i-2 >= 0)
				{
					if(dag[i-2].first != 0 && dag[i-2].second != 0)
					{
						dag[i].second = dag[i-2].first + dag[i-2].second;
					}
					else if(dag[i-2].first != 0)
					{
						dag[i].second = dag[i-2].first;
					}
					else if(dag[i-2].second != 0)
					{
						dag[i].second = dag[i-2].second;
					}
					else
					{
						dag[i].second = 0;
					}
				}
			}
		}

		res = dag[dag.size()-1].first + dag[dag.size()-1].second;
		return res;
    }

	// comparison, not case sensitive.
	struct StringCompare
	{
		bool operator() (string first, string second)
		{
		  unsigned int i=0;
		  while ( (i<first.length()) && (i<second.length()) )
		  {
			if (first[i]<second[i]) return true;
			else if (first[i]>second[i]) return false;
			++i;
		  }
		  if (first.length()<second.length()) return true;
		  else 
			  return false;
		}
	}stringcompare;

	struct StringEqual
	{
		bool operator() (string first, string second)
		{
		  unsigned int i=0;
		  if (first.length() != second.length()) return false;
		  while ( (i<first.length()) && (i<second.length()) )
		  {
			if (first[i] != second[i]) return false;
			++i;
		  }

		  return true;
		}
	}stringequal;

	//change a string num into character, '26' -> 'z', '1' -> 'a'
	string num2str(string s)
	{
		int num = s[0] - '0';
		for(string::iterator it = s.begin()+1; it < s.end(); it++)
		{
			num = num*10 + *it - '0';
		}
		string t;
		t.push_back('a' + num - 1);
		return t;
	}

	vector<string> unionstring(vector<string> s1, vector<string> s2)
	{
		vector<string> res;
		if(s1.size() >= 1 && s2.size() >= 1)
		{
			for(vector<string>::iterator it1 = s1.begin(); it1 < s1.end(); it1++)
			{
				for(vector<string>::iterator it2 = s2.begin(); it2 < s2.end(); it2++)
				{
					string s = *it1;
					s += *it2;
					res.push_back(s);
				}
			}
		}
		return res;
	}

	vector<string> numDecording_dup(string s)
	{
		vector<string> res;
		int n = s.size();
		if(n == 0) return res;
		if(n == 1)
		{
			if(s[0] >= '1' && s[0] <= '9')
			{
				res.push_back(num2str(s)); //1-9
			}
		}
		else if(n == 2)
		{
			if( (s[0] == '1' && (s[1] >= '1' && s[1] <= '9')) || (s[0] == '2' && (s[1] >= '1' && s[1] <= '6'))) //two
			{
				string t;
				t = num2str(s.substr(0,1));
				t += num2str(s.substr(1,1));
				res.push_back(t);
				res.push_back(num2str(s));
			}
			else if((s[0] == '1' ||s[0] == '2') && s[1] == '0' ) //one
			{
				res.push_back(num2str(s));	
			}
			else
			{
				vector<string> s1 = numDecording_dup(s.substr(0,1));
				vector<string> s2 = numDecording_dup(s.substr(1,1));
				if(s1.size() == 1 && s2.size() == 1)
				{
					string t;
					t = num2str(s.substr(0,1));
					t += num2str(s.substr(1,1));
					res.push_back(t);
				}
			}
		}
		else//size >= 3
		{
			vector<string> s1 = numDecording_dup(s.substr(0,1));
			if(s1.size() == 1)
			{
				vector<string> s2 = numDecording_dup(s.substr(1,n-1));
				vector<string> s3 = unionstring(s1, s2);
				for(vector<string>::iterator it = s3.begin(); it < s3.end(); it++)
				{
					res.push_back(*it);
				}
			}

			vector<string> s4 = numDecording_dup(s.substr(0,2));
			if(s4.size() >= 1)
			{
				vector<string> s5 = numDecording_dup(s.substr(2,n-2));
				vector<string> s6 = unionstring(s4, s5);
				for(vector<string>::iterator it = s6.begin(); it < s6.end(); it++)
				{
					res.push_back(*it);
				}
			}
		}
		return res;
	}

    int numDecodings1(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> vs = numDecording_dup(s);
		sort(vs.begin(), vs.end(),stringcompare);
		vector<string>::iterator it = unique(vs.begin(), vs.end(),stringequal);
		vs.resize(it - vs.begin());
		return vs.size();
    }
};

void main()
{
	Solution s;
	int res = s.numDecodings("62163");
	//int res = s.numDecodings("1212");

	cout << res << endl;

	system("pause");
}