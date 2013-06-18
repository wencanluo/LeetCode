/*Valid Palindrome  Jan 133606 / 11291
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome

Your algorithm should run in O(n) complexity.
Author: Wencan Luo
Language: C++
Date: 06/17/2013
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

class Solution {
public:

	bool CheckAlphanumeric(char &c){
		if( c >= '0' && c <= '9' ) return true;
		if( c >= 'a' && c <= 'z' ) return true;
		if( c >= 'A' && c <= 'Z' ) {
			c = c - 'A' + 'a';
			return true;
		}

		return false;
	}

    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		int n=s.size();
		if(n == 0) return true;

		int i=0,j=n-1;

		while(i < j ){
			if(!CheckAlphanumeric(s[i])){
				i++;
				continue;
			}

			if(!CheckAlphanumeric(s[j])){
				j--;
				continue;
			}

			if(s[i] != s[j]){
				return false;
			}else{
				i++;
				j--;
			}
		}

		return true;    
    }
};

void main(){
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal: Panama");
	
	//system("pause");
}
