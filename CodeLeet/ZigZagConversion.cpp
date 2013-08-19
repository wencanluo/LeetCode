/*ZigZag ConversionDec 6 '116109 / 17606
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Author: Wencan Luo
Language: C++
Date: 08/18/2013
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
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int n=s.size();
		string r = "";
		for(int i=0;i<nRows;i++){
			for(int j=i;j<n;j+=2*(nRows-1)){
				r += s[j];
				if(i!=0 && i!=(nRows-1) && (j + 2*nRows-2*i-2 < n)){
					r += s[j + 2*nRows-2*i-2];
				}
			}
		}

		return r;
    }
};

void main(){
	Solution s;

	cout << s.convert("PAYPALISHIRING", 3) << endl;

	system("pause");
}
