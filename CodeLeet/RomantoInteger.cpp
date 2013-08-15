/*Roman to IntegerJan 15 '123513 / 7381
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Author: Wencan Luo
Language: C++
Date: 08/14/2013
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

class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int sum = 0;
		int subsum = 0;

		int k = 0;
        for(int i=0;i<s.size();i++){
			switch(s[i]){
			case 'I':
				sum += 1;
				switch(k){
				case 1:
					subsum += 1;
					break;
				default:
					subsum = 1;
					break;
				}
				k = 1;
				break;
			case 'V':
				sum += 5;
				switch(k){
				case 1:
					sum -= 2*subsum;
					break;
				default:
					subsum = 0;
					break;
				}
				k = 1;
				break;
			case 'X':
				sum += 10;
				switch(k){
				case 1:
					sum -= 2*subsum;
					subsum = 0;
					break;
				case 2:
					subsum += 10;
					break;
				default:
					subsum = 10;
					break;
				}
				k = 2;
				break;
			case 'L':
				sum += 50;
				switch(k){
				case 2:
					sum -= 2*subsum;
					break;
				default:
					break;
				}
				k = 2;
				break;
			case 'C':
				sum += 100;
				switch(k){
				case 2:
					sum -= 2*subsum;
					subsum = 0;
					break;
				case 3:
					subsum += 100;
					break;
				default:
					subsum = 100;
					break;
				}
				k = 3;
				break;
			case 'D':
				sum += 500;
				switch(k){
				case 3:
					sum -= 2*subsum;
					break;
				default:
					subsum = 0;
					break;
				}
				k = 3;
				break;
			case 'M':
				sum += 1000;
				switch(k){
				case 3:
					sum -= 2*subsum;
					subsum = 0;
					break;
				default:
					break;
				}
				k = 4;
				break;
			default:
				return 0;
			}
		}

		return sum;
    }

	string intToRoman(int num){
		vector<int> a;
		int k = num;
		for(int i=0;i<4;i++){
			a.push_back(k%10);
			k/=10;
		}

		string r = "";
		char roman[4][3] = {"IV","XL","CD","M?"};

		for(int i=a.size()-1;i>=0;i--){
			int k = a[i];
			switch(k){
			case 0:
				break;
			case 1:
				r += roman[i][0];
				break;
			case 2:
				r += roman[i][0];
				r += roman[i][0];
				break;
			case 3:
				r += roman[i][0];
				r += roman[i][0];
				r += roman[i][0];
				break;
			case 4:
				r += roman[i][0];
				r += roman[i][1];
				break;
			case 5:
				r += roman[i][1];
				break;
			case 6:
				r += roman[i][1];
				r += roman[i][0];
				break;
			case 7:
				r += roman[i][1];
				r += roman[i][0];
				r += roman[i][0];
				break;
			case 8:
				r += roman[i][1];
				r += roman[i][0];
				r += roman[i][0];
				r += roman[i][0];
				break;
			case 9:
				r += roman[i][0];
				r += roman[i+1][0];
				break;
			default:
				break;
			}
		}

		return r;
	}

	string intToRoman_Dict(int num) {//n <= 3999
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int a[4];

		int k = num;
		for(int i=0;i<4;i++){
			a[i] = k%10;
			k/=10;
		}

		string r = "";

		if(a[3] != 0){
			switch(a[3]){
			case 1:
				r += "M";
				break;
			case 2:
				r += "MM";
				break;
			case 3:
				r += "MMM";
				break;
			default:
				break;
			}
		}

		switch(a[2]){
			case 0:
				break;
			case 1:
				r += "C";
				break;
			case 2:
				r += "CC";
				break;
			case 3:
				r += "CCC";
				break;
			case 4:
				r += "CD";
				break;
			case 5:
				r += "D";
				break;
			case 6:
				r += "DC";
				break;
			case 7:
				r += "DCC";
				break;
			case 8:
				r += "DCCC";
				break;
			case 9:
				r += "CM";
				break;
			default:
				break;
		}

		switch(a[1]){
			case 0:
				break;
			case 1:
				r += "X";
				break;
			case 2:
				r += "XX";
				break;
			case 3:
				r += "XXX";
				break;
			case 4:
				r += "XL";
				break;
			case 5:
				r += "L";
				break;
			case 6:
				r += "LX";
				break;
			case 7:
				r += "LXX";
				break;
			case 8:
				r += "LXXX";
				break;
			case 9:
				r += "XC";
				break;
			default:
				break;
		}

		switch(a[0]){
			case 0:
				break;
			case 1:
				r += "I";
				break;
			case 2:
				r += "II";
				break;
			case 3:
				r += "III";
				break;
			case 4:
				r += "IV";
				break;
			case 5:
				r += "V";
				break;
			case 6:
				r += "VI";
				break;
			case 7:
				r += "VII";
				break;
			case 8:
				r += "VIII";
				break;
			case 9:
				r += "IX";
				break;
			default:
				break;
		}

		return r;
    }
};

void main()
{
	Solution s;

	cout<< s.romanToInt("MCMXCVI") << endl;

	system("pause");
}

