/*Regular Expression MatchingJan 8 '126668 / 25265
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true

Author: Wencan Luo
Language: C++
Date: 08/20/2013
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

class Solution {
public:
    bool isMatchRec(const char *s, int m, const char *p, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0 && n==0) return true;
        if(m==0){
			for(int i=0;i<n;i++){
				if(p[i] != '*' && p[i+1] != '*') return false;
			}
			return true;
		}

		if(n==0){
			for(int i=0;i<m;i++){
				if(s[i] != '*' && s[i+1] != '*') return false;
			}
			return true;
		}
		if(s[0] == '*') return false;
		if(p[0] == '*') return false;

		if(s[m-1] == '*'){
			if(s[m-2] == '*') return isMatchRec(s, m-1, p, n);

			if(p[n-1] == '*'){
				if(p[n-2] == '*') return isMatchRec(s, m, p, n-1);
				
				if(s[m-2] == '.' || p[n-2] == '.' || p[n-2] == s[m-2]){
					return isMatchRec(s, m-1, p, n-1) || isMatchRec(s, m-1, p, n) || isMatchRec(s, m, p, n-1);
				}else{
					return isMatchRec(s, m-2, p, n-2);
				}
			}else if(p[n-1] == '.'){
				return isMatchRec(s, m, p, n-1);
			}else{
				if(s[m-2] == '.' || p[n-2] == s[m-1]){
					 return isMatchRec(s, m, p, n-1) || isMatchRec(s, m-2, p, n);
				}else{
					return isMatchRec(s, m-2, p, n);
				}
			}
		}else if(s[m-1] == '.'){
			if(p[n-1] == '*'){
				if(n > 1 && p[n-2] == '*') return isMatchRec(s, m, p, n-1);
				return isMatchRec(s, m, p, n-1);
			}else if(p[n-1] == '.'){
				return isMatchRec(s, m-1, p, n-1);
			}else{
				return isMatchRec(s, m-1, p, n-1);
			}
		}else{
			if(p[n-1] == '*'){
				if(p[n-2] == '*') return isMatchRec(s, m, p, n-1);
				if(p[n-2] == '.' || p[n-2] == s[m-1]){
					return isMatchRec(s, m-1, p, n) || isMatchRec(s, m, p, n-2);
				}else{
					return isMatchRec(s, m, p, n-2);
				}
			}else if(p[n-1] == '.'){
				return isMatchRec(s, m-1, p, n-1);
			}else{
				if(s[m-1] != p[n-1]) return false;
				return isMatchRec(s, m-1, p, n-1);
			}
		}
		return false;
    }
    
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int m = strlen(s);
        int n = strlen(p);
        return isMatchRec(s, m, p, n);
    }
};

void main(){
	Solution s;

	//cout << s.isMatch(".*", "1") << endl;
	//cout << s.isMatch("123", "123") << endl;
	//cout << s.isMatch("123.", "123") << endl;
	//cout << s.isMatch(".*", "123") << endl;
	//cout << s.isMatch("123", "124") << endl;
	cout << s.isMatch("aa", "a*") << endl;

	system("pause");
}
