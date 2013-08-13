/*Implement strStr()Feb 18 '126159 / 19459
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

Author: Wencan Luo
Language: C++
Date: 08/12/2013
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
    char *strStr(char *haystack, char *needle) {//O(mn)
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strlen(haystack);
		int m = strlen(needle);
		if(m==0) return haystack;
		
		for(int i=0;i<=n-m;i++){
			bool found = true;
			for(int j=0;j<m;j++){
				if(haystack[i+j] != needle[j]){
					found = false; 
					break;
				}
			}
			if(found) return (haystack + i);
		}
		return NULL;
    }
};

void main(){
    Solution s;

	cout << s.strStr("abcd","bc");
    
	system("pause");
}
