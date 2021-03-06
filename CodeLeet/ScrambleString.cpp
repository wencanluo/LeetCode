/*Scramble String Apr 30 '122078 / 6609
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Author: Wencan Luo
Language: C++
Date: 07/18/2013
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
	bool CheckSubString(string s1, string s2){
		if(s1.size() != s2.size()) return false;
		if(s1==s2) return true;

		map<char, int> A, B;
		
		for(int i=0;i<s1.size();i++){
			char t = s1[i];
			if(A.find(t) != A.end()){
				A[t]++;
			}else{
				A[t]=1;
			}
		}

		for(int i=0;i<s2.size();i++){
			char t = s2[i];
			if(B.find(t) != B.end()){
				B[t]++;
			}else{
				B[t]=1;
			}
		}

		for(map<char, int>::iterator it = A.begin(); it != A.end(); it++){
			if( B.find(it->first) == B.end()) return false;

			if(it->second != B[it->first]) return false;
		}

		return true;
	}

    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() functionW
		if(s1.size() != s2.size()) return false;

		if(s1==s2) return true;
		if(!CheckSubString(s1, s2)) return false;

		//find possible split
		int n=s1.size();

		for(int i=1;i<n;i++){
			//cout << s1.substr(0,i) << "," << s2.substr(n-i,i) << endl;
			if( CheckSubString(s1.substr(0,i), s2.substr(n-i,i))){//switched the root
				if(isScramble(s1.substr(0,i), s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i), s2.substr(0,n-i))) return true; 
			}

			if( CheckSubString(s1.substr(0,i), s2.substr(0,i))){//switched the others
				if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,n-i), s2.substr(i,n-i))) return true; 
			}
		}

		return false;
    }
};

void main(){
	Solution s;

	string a = "ab";
	//cout << a.substr(0,1) << endl;

	cout << s.isScramble("abc","acb");

	system("pause");
}
