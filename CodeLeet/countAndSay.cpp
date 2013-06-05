/*
Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Author: Wencan Luo
Language: C++
Date: 09/06/2012
*/

#include<iostream>
#include<string>
#include <sstream>
using namespace std;

class Solution {
public:
	string convertInt(int number)
	{
	   stringstream ss;//create a stringstream
	   ss << number;//add number to the stream
	   return ss.str();//return a string with the contents of the stream
	}

	string getNext(string s)
	{
		string res;
		char c;
		c = s[0];
		int count = 1;
		for(string::iterator it = s.begin() + 1; it < s.end(); it++)
		{
			if(*it == c)
			{
				count++;
			}
			else
			{
				res += convertInt(count);
				res += c;
				count = 1;
				c = *it;
			}
		}

		//add the last one
		res += convertInt(count);
		res += c;
		return res;
	}

    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string res;
		res = "1";
		for(int i=1;i<n;i++)
		{
			res = getNext(res);
		}
		
        return res;
    }
};

void main()
{
	Solution s;
	string res = s.countAndSay(5);

	cout << res <<endl;

	system("pause");
}