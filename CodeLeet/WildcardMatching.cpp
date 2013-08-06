/*Wildcard MatchingMar 16 '126416 / 25360
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false

Author: Wencan Luo
Language: C++
Date: 08/04/2013
*/

#include<iostream>
using namespace std;
#include<climits>

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
    bool isMatchRec(const char *s, int m, const char *p, int n){
        if(m==0 && n==0) return true;
        if(m==0){
            for(int i=0;i<n;i++){
                if(p[i] != '*') return false;
            }
            return true;  
        }
        if(n==0){
            for(int i=0;i<m;i++){
                if(s[i] != '*') return false;
            }
            return true;
        } 
        
        if(s[m-1] == '*'){
            if(p[n-1] == '*'){
                return isMatchRec(s, m-1, p, n-1) || isMatchRec(s, m, p, n-1) || isMatchRec(s, m-1, p, n);
            }else if(p[n-1] == '?'){
                return isMatchRec(s, m-1, p, n-1) || isMatchRec(s, m, p, n-1);
            }else{
                return isMatchRec(s, m-1, p, n-1) || isMatchRec(s, m, p, n-1);
            }
        }else if(s[m-1] == '?'){
            if(p[n-1] == '*'){
                return isMatchRec(s, m-1, p, n-1) || isMatchRec(s, m, p, n-1) || isMatchRec(s, m-1, p, n);
            }else if(p[n-1] == '?'){
                return isMatchRec(s, m-1, p, n-1);
            }else{    			
                return isMatchRec(s, m-1, p, n-1);
            }
        }else{//letter
            if(p[n-1] == '*'){
                 return isMatchRec(s, m-1, p, n-1) || isMatchRec(s, m, p, n-1) || isMatchRec(s, m-1, p, n);
            }else if(p[n-1] == '?'){
                return isMatchRec(s, m-1, p, n-1);
            }else{
				if(s[m-1] == p[n-1]) return isMatchRec(s, m-1, p, n-1);
				return false;
            }
        }
    }
    
	bool isMatch(const char *s, const char *p) {//O(m+n)
	}

    bool isMatch_Omn(const char *s, const char *p) {//O(m*n) Time, O(n) Space
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = strlen(s);
        int n = strlen(p);
        
		vector<bool>  A;
		vector<bool>  B;
		vector<bool>  C;
		A.resize(n+1, false);
		B.resize(n+1, false);
		C.resize(m+1, false);

		A[0] = true;
		for(int j=0;j<n;j++){
			if(p[j] != '*') break;
			A[j+1] = true;
        }

        for(int i=0;i<m;i++){
            if(s[i] != '*') break;
			C[i+1] = true;
        }
   
		for(int i=0;i<m;i++){
			B[0] = C[i];

			for(int j=0;j<n;j++){
				B[j+1] = false;
				if(s[i] == '*'){
					if(p[j] == '*'){
						B[j+1] = A[j] || B[j] || A[j+1];
					}else{
						B[j+1] = A[j] || B[j];
					}
				}else{
					if(p[j] == '*'){
						B[j+1] = A[j] || B[j] || A[j+1];
					}else if(s[i] == '?' || p[j] == '?' || s[i] == p[j]){
						B[j+1] = A[j];
					}
				}
			}
			A = B;
		}
        
        return A[n];
    }

	bool isMatch_O2Space(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = strlen(s);
        int n = strlen(p);
        
		vector< vector<bool> > A;
		A.resize(m+1);

		for(int i=0;i<A.size();i++){
			A[i].resize(n+1,false);
		}

		A[0][0] = true;
		for(int i=0;i<m;i++){
			if(s[i] != '*') break;
			A[i+1][0] = true;
        }

        for(int j=0;j<n;j++){
            if(p[j] != '*') break;
			A[0][j+1] = true;
        }
   
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(s[i] == '*'){
					if(p[j] == '*'){
						A[i+1][j+1] = A[i][j] || A[i+1][j] || A[i][j+1];
					}else{
						A[i+1][j+1] = A[i][j] || A[i+1][j];
					}
				}else{
					if(p[j] == '*'){
						A[i+1][j+1] = A[i][j] || A[i+1][j] || A[i][j+1];
					}else if(s[i] == '?' || p[j] == '?' || s[i] == p[j]){
						A[i+1][j+1] = A[i][j];
					}
				}
			}
		}
        
        return A[m][n];
    }
};

void main(){
	Solution s;

	cout << s.isMatch("","*") << endl;
	cout << s.isMatch("a","b") << endl;
	cout << s.isMatch("a*","*a") << endl;
	cout << s.isMatch("***","*") << endl;
    
	system("pause");
}
