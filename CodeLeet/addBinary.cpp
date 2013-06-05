/*
Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Author: Wencan Luo
Language: C++
Date: 08/30/2012
*/
#include<iostream>
using namespace std;

#include<string>

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string res;

		string::reverse_iterator it1, it2;

		bool flag = false;
		for(it1=a.rbegin(), it2=b.rbegin();it1<a.rend() && it2 < b.rend();it1++, it2++)
		{
			if(flag)
			{
				 if(*it1 == '1' && *it2 == '1')
				 {
					 res.push_back('1');
				 }
				 else if(*it1 == '1' && *it2 == '0')
				 {
					 res.push_back('0');
				 }
				 else if(*it1 == '0' && *it2 == '1')
				 {
					 res.push_back('0');
				 }
				 else
				 {
					 res.push_back('1');
					 flag = false;
				 }
			}
			else
			{
				if(*it1 == '1' && *it2 == '1')
				 {
					 res.push_back('0');
					 flag = true;
				 }
				 else if(*it1 == '1' && *it2 == '0')
				 {
					 res.push_back('1');
				 }
				 else if(*it1 == '0' && *it2 == '1')
				 {
					 res.push_back('1');
				 }
				 else
				 {
					 res.push_back('0');
				 }
			}
		}

		for(;it1<a.rend();it1++)
		{
			if(flag)
			{
				if(*it1 == '1')
				{
					res.push_back('0');
					
				}
				else
				{
					res.push_back('1');
					flag = false;
				}
			}
			else
			{
				res.push_back(*it1);
			}
		}

		for(;it2 < b.rend();it2++)
		{
			if(flag)
			{
				if(*it2 == '1')
				{
					res.push_back('0');
					
				}
				else
				{
					res.push_back('1');
					flag = false;
				}
			}
			else
			{
				res.push_back(*it2);
			}
		}

		if(flag)
		{
			res.push_back('1');
		}

		//reverse

		string f_res;
		string::reverse_iterator rit;
		for ( rit=res.rbegin() ; rit < res.rend(); rit++ )
			f_res.push_back(*rit);

        return f_res;
    }
};

void main()
{
	string a = "11";
	string b = "1";

	Solution s;
	string c = s.addBinary(a,b);

	cout << c << endl;

	system("pause");
}