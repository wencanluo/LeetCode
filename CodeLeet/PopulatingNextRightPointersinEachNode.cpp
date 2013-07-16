/*Distinct Subsequences Oct 19 '123576 / 10296
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Author: Wencan Luo
Language: C++
Date: 07/05/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>

#include<map>
//#include<unordered_set>

#include<queue>
#include<set>

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	
		vector< vector<int> > A; //M*N
		int m = S.length();
		int n = T.length();

		if(m==0 || n==0) return 0;

		A.resize(m+1);
		for(int i=0;i<A.size();i++){
			A[i].resize(n+1);
		}

		for(int j=0;j<=n;j++){
			A[0][j] = 0;
		}

		for(int i=0;i<=m;i++){//A[0][0] = 1
			A[i][0] = 1;
		}

		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(S[i-1] == T[j-1]){
					A[i][j] = A[i-1][j-1] + A[i-1][j];
				}else{
					A[i][j] = A[i-1][j];
				}
				
			}
		}

        return A[m][n];
    }
};

void main(){
	Solution s;	
	cout << s.numDistinct("rabbbit", "rabbit");
	//cout << s.numDistinct("ABCDE", "ACE");
	//cout << s.numDistinct("BAAACD", "BACD");
	//cout << s.numDistinct("BAAA", "BAAAC");
	system("pause");
}
