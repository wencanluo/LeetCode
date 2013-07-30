/*Simplify Path Apr 4 '122569 / 10105
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Author: Wencan Luo
Language: C++
Date: 07/26/2013
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
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(path.size()<=1) return path;

		stack< string > P;

		path = path + "/";

		int k=1;
		for(int i=1;i<path.size();i++){
			if(path[i] == '/'){
				string sub = path.substr(k,i-k);
				k=i+1;
				if(sub == "") continue;

				if(sub.compare(".") == 0) continue;

				if(sub.compare("..") == 0){
					if(!P.empty()) P.pop();
					continue;
				}

				P.push(sub);
			}
		}

		if(P.empty()) return "/";

		string p = "";
		while(!P.empty()){
			p = "/" + P.top() + p;
			P.pop();
		}
		return p;
    }
};

void main(){
	Solution s;
	
	//cout << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << s.simplifyPath("/a/b/c") << endl;

	system("pause");
}
