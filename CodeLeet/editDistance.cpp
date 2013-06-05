/*
Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Author: Wencan Luo
Language: C++
Date: 09/11/2012
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {//m*n, non-recursive
		int n1 = word1.size();
		int n2 = word2.size();
		
		if(n1==0) return n2;
		if(n2==0) return n1;

		vector< vector<int> > s;
		s.resize(n1+1);
		//cout << s.size() <<endl;
		for(int i=0;i<s.size();i++)
		{
			s[i].resize(n2+1,0);
		}

		for(int i=0;i<=n1;i++)
		{
			s[i][0] = i;
		}

		for(int j=0;j<=n2;j++)
		{
			s[0][j] = j;
		}

		for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=n2;j++)
			{
				if(word1[i-1] == word2[j-1])//match
				{
					s[i][j] = s[i-1][j-1];			
				}
				else
				{
					s[i][j] = 1 + min(s[i-1][j-1],min(s[i-1][j],s[i][j-1]));
				}
			}
		}

		return s[n1][n2];
	}

    int minDistance2(string word1, string word2) {//n^2, recursive
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(word1.size() == 0) return word2.size();
		if(word2.size() == 0) return word1.size();

		int d = 0;
		
		int n1 = word1.size();
		int n2 = word2.size();
		int d1,d2,d3;

		if(word1[n1-1] == word2[n2-1])
		{
			d1 = minDistance(word1.substr(0,n1-1), word2.substr(0,n2-1));
		}
		else
		{
			d1 = minDistance(word1.substr(0,n1-1), word2.substr(0,n2-1)) +1;  //sub
		}
		
		d2 = minDistance(word1.substr(0,n1-1), word2) + 1;//insert
		d3 = minDistance(word1, word2.substr(0,n2-1)) + 1;//delete

		d = min(d1,d2);
		d = min(d,d3);
		return d;
    }
};

void main()
{
	Solution s;
	//int d = s.minDistance("abcdefghiii", "abcdefghiii");
	//int d = s.minDistance("abcd", "abcde");
	int d = s.minDistance("prosperity", "properties");

	cout << d << endl;
	system("pause");
}