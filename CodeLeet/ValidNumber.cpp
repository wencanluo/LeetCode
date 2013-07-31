/*Valid Number Apr 2 '122736 / 14316
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

0:
	'': 0
	+/-: 8
	.: 9
	0-9: 1
1: 
	'': 7
	.: 3
	'e': 4
	0-9: 3
3:
	'': 7
	'e':4
	0-9: 3
4:
	0-9: 5
	+/-:6
5:
	'': 7
	0-9: 5	
6:
	'': 5
7:
	'': 7
8:
	0-9: 1
	.: 9
9:
	0-9: 3

Author: Wencan Luo
Language: C++
Date: 07/30/2013
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
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		//state machine based method
		int n = strlen(s);

		int state = 0;

		for(int i=0;i<n;i++){
			char c = s[i];
			switch(state){
			case 0://start
				switch(c){
				case ' ':break;
				case '-':
				case '+':state=8;break;
				case '0':state=1;break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':state=1;break;
				case '.':state=9;break;
				default:return false;
				}
				break;
			case 1://integer
				switch(c){
				case ' ':state=7;break;
				case '.':state=3;break;
				case 'e':state=4;break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':break;
				default:return false;
				}
				break;
			case 3://decimal
				switch(c){
				case ' ':state=7;break;
				case 'e':state=4;break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':break;
				default:return false;
				}
				break;
			case 4://e
				switch(c){
				case '+':
				case '-':state=6;break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':state=5;break;
				default:return false;
				}
				break;
			case 5:
				switch(c){
				case ' ': state=7;break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':break;
				default:return false;
				}
				break;
			case 6:
				switch(c){
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':state=5;break;
				default:return false;
				}
				break;
			case 7://end space
				switch(c){
					case ' ':break;
					default:return false;
				}
				break;
			case 8:
				switch(c){
				case '.':state=9;break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':state=1;break;
				default:return false;
				}
				break;
			case 9:
				switch(c){
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':state=3;break;
				default:return false;
				}
				break;
			default:
				break;
			}
		}

		switch(state){
		case 1:
		case 3:
		case 5:
		case 7:
			return true;
		default:
			return false;
		}

		return false;
    }
};

void main(){
	Solution s;
	cout << s.isNumber(".");
	cout << s.isNumber(".+");
	cout << s.isNumber(".0");
	cout << s.isNumber("1e0000");
	system("pause");
}
