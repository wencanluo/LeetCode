/*Palindrome NumberJan 4 '127090 / 17746
Determine whether an integer is a palindrome. Do this without extra space.

Author: Wencan Luo
Language: C++
Date: 08/17/2013
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
	int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long xx = x;
    	if(x < 0) xx = -xx;

        long y = 0;
		while(xx){
			y = y*10 + xx%10;
			xx/=10;
		}
		if(x < 0) return -y;
		return y;
    }

    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(x < 0) return false;
		int y = reverse(x);
		return x==y;
    }

	bool isPalindrome2(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(x < 0) return false;
		int y = reverse(x);

		while(x){
			if(x%10 != y%10) return false;
			x /= 10;
			y /= 10;
		}

		return true;
    }
};

void main(){
	Solution s;

	cout << s.isPalindrome(-2147447412) << endl;

	system("pause");
}
