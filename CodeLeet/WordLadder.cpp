/*Word Ladder II
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Word Ladder I
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary


Your algorithm should run in O(n) complexity.
Author: Wencan Luo
Language: C++
Date: 06/05/2013
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

#define unordered_set set

class Solution {
public:
	

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> res;

		return res;
    }

	bool check(string s1, string s2){
		int n = s1.size();

		int count = 0;
		for(int i=0;i<n;i++){
			if(s1[i] != s2[i]){
				count++;
				if(count >= 2) return false;
			}
		}
		
		if( count == 0) return false;

		return true;
	}

	
	int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
		
		queue<string> Q;
		Q.push(start);

		while(!Q.empty()){
			ExtendQ(Q, dict);
		}

		return res;
    }
};

void main(){
	Solution s;
	
	string ss[]= {"hot","dot","dog","lot","log"};

	std::unordered_set<std::string> dict(ss, ss+sizeof(ss)/sizeof(ss[0]));

	vector<string> v = s.ReplaceOne("hit");
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}
	//cout << s.ladderLength("hit", "cog", dict);
	//system("pause");
}
