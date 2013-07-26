/*Restore IP Addresses Aug 8 '123007 / 11548
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Author: Wencan Luo
Language: C++
Date: 07/17/2013
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
	bool checkIP(string ip){
		static string MaxIP = "255";
		switch(ip.size()){
			case 0:
				return false;
			case 1:
				return true;
			case 2:
				if(ip[0] == '0') return false;
				return true;
			case 3:
				if(ip[0] == '0') return false;
				
				for(int i=0; i<3; i++){
					if(ip[i] > MaxIP[i]) {
						return false;
					}else if(ip[i] < MaxIP[i]){
						return true;
					}
				}

				return true;
			default:
				return false;
		}

		return true;
	}

	vector<string> restoreIpAddressesHalf(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> res;
		int n = s.size();

		for(int i=1;i<n;i++){
			//cout << s.substr(0,i) << " " << s.substr(i,n-i) << endl;
			if(checkIP(s.substr(0,i)) & checkIP(s.substr(i,n-i))){
				res.push_back(s.substr(0,i) + "." + s.substr(i,n-i));
			}
		}
		return res;
    }

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
		vector<string> res;
		if(n<4 || n > 12) return res;

		for(int i=0;i<n;i++){
			vector<string> left = restoreIpAddressesHalf(s.substr(0,i));
			if(left.size() == 0) continue;

			vector<string> right = restoreIpAddressesHalf(s.substr(i,n-i));
			if(right.size() == 0) continue;

			for(int j=0;j<left.size();j++){
				for(int k=0;k<right.size();k++){
					res.push_back(left[j] + "." + right[k]);
				}
			}
		}

		return res;
    }
};

void main(){
	Solution s;
	
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;
	//b.right = &c;
	
	//cout << s.checkIP("172");
	//cout << s.restoreIpAddressesHalf("17216").size();
	//cout << s.restoreIpAddressesHalf("2541").size();
	vector<string> v = s.restoreIpAddresses("172162541");
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}
	system("pause");
}
