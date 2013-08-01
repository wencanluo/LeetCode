/*Length of Last WordMar 27 '123781 / 9150
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example, 
Given s = "Hello World",
return 5.

Author: Wencan Luo
Language: C++
Date: 08/01/2013
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

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s==NULL) return 0;
        if(*s == '\0') return 0;
        
        int k=0;
        
        int i=0;
        while(s[i] != '\0'){
            
            if(s[i] == ' ' && (s[i+1] != ' ' && s[i+1] != '\0') ){//word starts
                k = 0;
            }else if(s[i] != ' '){//word continue
                k++;
            }
            
            i++;
        }
        
        return k;
    }
};

void main(){
    Solution s;
	
	cout << s.lengthOfLastWord("") << endl;
	cout << s.lengthOfLastWord("   ") << endl;
	cout << s.lengthOfLastWord("a   aab") << endl;
	cout << s.lengthOfLastWord("a   bbb ") << endl;

	system("pause");
}
