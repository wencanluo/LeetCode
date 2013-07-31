/*Text JustificationApr 3 '122281 / 11590
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]


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
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;

		if(L<=0){
			res.push_back("");
			return res;
		}

		int k = 0;
		int nL = 0;
		for(int i=0;i<words.size();i++){
			nL += words[i].size() + 1;

			if(nL > L+1){
				//get the blank count
				int n = i - k; //word size
				if(n==0){//doesn't support
					vector<string> res;
					return res;
				}else if(n==1){
					string t = words[k];
					string sp = "";
					for(int j=0;j<L-t.size();j++){
						sp += " ";
					}
					t += sp;

					res.push_back(t);
				}else{
					nL -= words[i].size() + 1;//character size

					int nSpace = L - nL+ n; //total space
					int nOneWord = nSpace/(n-1);
					int nOneWordLeft = nSpace%(n-1);

					//pack the previous ones
					string sp = "";
					for(int j=0; j<nOneWord;j++){
						sp += " ";
					}

					string t = "";
					for(int j=k;j<i-1;j++){
						t += words[j]+sp;

						if(j-k < nOneWordLeft){
							t += " ";
						}
					}
					t += words[i-1];

					res.push_back(t);
				}
				//last one

				k = i;
				nL = 0;
				i--;//repeat the last one
			}

			if(i == words.size() - 1){//the rest ones
				string t = "";
				for(int j=k;j<i;j++){
					t += words[j]+" ";
				}
				t += words[i];

				string sp = "";
				for(int j=0;j<L-t.size();j++){
					sp += " ";
				}
				t += sp;
				res.push_back(t);
			}
		}

		return res;
    }
};

void main(){
	Solution s;
	char *a[7] = {"This", "is", "an", "example", "of", "text", "justification."};

	vector<string> va;
	for(int i=0;i<7;i++){
		va.push_back(a[i]);
	}
	
	vector<string> res = s.fullJustify(va, 16);
	for(int i=0;i<res.size();i++){
		cout << res[i] << "#" << endl;
	}

	system("pause");
}
