/*Reverse Words in a String Total Accepted: 45166 Total Submissions: 318154 My Submissions Question Solution 
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Author: Wencan Luo
Language: C++
Date: 12/06/2014
*/

#include<iostream>
using namespace std;


class Solution {
public:

    void reverse(string &s, int i, int j){
        int n = s.size();
        
        //reverse sentences
        for(int k=i;k<=(i+j)/2;k++){
            char t = s[k];
            s[k] = s[j-k+i];
            s[j-k+i] = t;
        }
    }
    
    void reverseWords(string &s) {
        int n = s.size();
        
        //clean the space
        int i=0,j=0;
        while(j<n && s[j] == ' ')j++;
        
        while(j<n){
            while(j<n && s[j] != ' '){
                s[i] = s[j];
                i++;
                j++;
            }
            
            s[i] = ' ';
            i++;
            
            while(j<n && s[j] == ' ')j++;
        }
        if(i==0){//all spaces
            s.clear();
            return;
        }

        s.erase(i-1, n-i+1);
        
        //cout << i << ":"<< s << ":" << endl;
        
        n = s.size();
        if(n==0) return;
         
        //reverse sentences
        reverse(s, 0, n-1);
        
        //reverse words
        //split by space
        i=0;
        while(i<n && s[i] == ' ')i++;
        
        int k=i+1;
        while(k<n){
            if(s[k] == ' '){
                reverse(s, i, k-1);
                i = k+1;
                
                while(i<n && s[i] == ' ')i++;
                k=i+1;
            }else{
                k++;
            }
        }
        
        //reverse the last one
        if(i<n) reverse(s, i, n-1);
    }
};

int main(){
    Solution s;
    
    string ss = "  abc  bacd";
    s.reverseWords(ss);

    cout << ":"<< ss << ":" << endl;
}