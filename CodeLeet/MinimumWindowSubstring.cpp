/*Minimum Window Substring Apr 15 '123228 / 13734
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Author: Wencan Luo
Language: C++
Date: 07/26/2013
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

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(T.size()==0) return "";
        int i=0,j=0;
		
		//initial the two maps
		map<char, int> A;
		map<char, int> B;
		int n=T.size();
		for(int k=0;k<n;k++){
			if(A.find(T[k]) == A.end()){
				A[T[k]] = 1;
				B[T[k]] = 0;
			}else{
				A[T[k]]++;
			}
		}

		int m = S.size();
		int minI=0, minJ=m;

		int count = 0;

		while(j<m){
			while(j<m){
				//move j
				char c=S[j];
				if(A.find(c) != A.end()){
					B[c]++;
					if(B[c] <= A[c]) count++;

					if(count == n) break;
				}
				j++;
			}
			if(count != n) break;

			//move i
			while(i<m){
				char c=S[i];
				if(A.find(c) != A.end()){
					B[c]--;
					if(B[c] < A[c]){
						count--;

						if(j-i < minJ - minI){
							minI = i;
							minJ = j;
						}

						i++;
						break;
					}
				}
				i++;
			}
			j++;
		}

		if(minJ != m){
			return S.substr(minI, minJ-minI+1);
		}
		return "";
    }
};

void main(){
	Solution s;
	
	cout << s.minWindow("ADOBECODEBANC", "BANC");

	system("pause");
}
