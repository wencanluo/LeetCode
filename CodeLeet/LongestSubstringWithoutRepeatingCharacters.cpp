/*Longest Substring Without Repeating CharactersMay 16 '1110376 / 31404
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Author: Wencan Luo
Language: C++
Date: 08/19/2013
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
#include<stack>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n<=1) return n;
        
        queue<char> Q;
        map<char, int> M;
        
        int k = 0;
        Q.push(s[k]);
        M[s[k]] = 1;
        
        int maxCount = 1;
        int count = 1;
        
        k++;
        while(k < n){
            char c = s[k];
            if(M.find(c) == M.end() || M[c] == 0){
                M[c] = 1;
                Q.push(c);
                count++;
                maxCount = max(maxCount, count);
            }else{
                while(!Q.empty()){
                    char t = Q.front();
    				Q.pop();

					count--;
					M[t]--;
					if(t == c) break;
                }
				Q.push(c);
                count++;
				M[c]++;
            }
			k++;
        }

        return maxCount;
    }
};

void main(){
	Solution s;
	
	cout << s.lengthOfLongestSubstring("ababc") << endl;

	system("pause");
}
