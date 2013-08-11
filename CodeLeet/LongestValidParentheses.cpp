/*Longest Valid Parentheses Mar 1 '124946 / 17933
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Author: Wencan Luo
Language: C++
Date: 08/09/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
		if(s.size()<2) return 0;
        int n = s.size();
        
        vector<vector<int>> M;
        M.resize(2*n+1);

		vector<int> D;
		D.resize(n+1, 0);

		//Compute the direction
		for(int i=0;i<n-1;i++){
			if(s[i+1] == '('){
				D[i+1] = 1; //up
			}else{
				D[i+1] = 0; //down
			}
		}
		D[n] = 0;
		D[0] = (s[0] == '(') ? 1 : 0;

		M[n].push_back(-1);
		int count = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                count--;
            }else{
                count++;
            }
			M[count + n].push_back(i);
        }

		int maxL = 0;
		for(int i=0;i<2*n+1;i++){
			if(M[i].size() < 2) continue;

			bool good = false;
			int begin = -1;
			int end = -1;
			int L = 0;

			for(int j=0;j<M[i].size();j++){
				int k = M[i][j];
				if(!good){
					if(D[k+1] > 0) {
						good = true;
						begin = k;
					}
				}else{
					if(D[k+1] == 0 || j == M[i].size() - 1){
						good = false;
						end = k;
						
						//compute 
						L = end - begin;						
						if(maxL < L){
							maxL = L;
						}
					}
				}
			}
		}

		return maxL;
	}

    int longestValidParentheses_On2(string s) {//On2
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()<2) return 0;
        int n = s.size();
        
        vector<int> M;
        M.resize(n, 0);
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                count--;
            }else{
                count++;
            }
            M[i] = count;
        }
        
        int max = 0;
		int i=0;
        while(i<n){
			while(i<n && s[i] == ')') {
				i++;
				continue;
			}

            int end = -1;
            int start = 0;
            if(i == 0){
                start = 0;
            }else{
                start = M[i-1];
            }
            
            for(int j=i;j<n;j++){
                if(M[j]-start < 0) break;
                if(M[j]-start == 0) end = j;
            }
            
            if(end != -1){
                int length = end - i + 1;
                max = length > max ? length : max;
				i = end+1;
            }

			i++;
        }
        
        return max;
    }
};

void main(){
    Solution s;
    
	cout << s.longestValidParentheses("((())") << endl;
	//cout << s.longestValidParentheses(")())))") << endl;

	system("pause");
}
