#include <iostream>

#include <vector>
using namespace std;

class Solution
{
public:
	void *memcpy(void *dst, const void *src, size_t n)
	{
		char* new_dst = (char*) dst;
		char* new_src = (char*) src;
   
		if(dst == NULL || src == NULL) return NULL;

		for(int i=0;i<n;i++)
		{
			new_dst[i] = new_src[i];
		}

		return (void*)new_dst;
	}


	void swap(char a[], int i, int j)
	{
		 char t = a[i];
		 a[i] = a[j];
		 a[j] = t;
	}

	void reverse(char a[], int n)
	{
		 for(int i=0;i<n/2;i++)
		 {
			 swap(a,i,n-i-1);
		 }
	}

	int add_one_digit(char *c, int oldcarry)//add caroldcarryry to *c, return the new carry. //oldcarry can only be 0 or 1
	{
		  int carry = 0;
		  if(*c < '9' || (*c == '9' && oldcarry == 0) )
		  {
			 *c = *c + oldcarry;       
		  }
		  else
		  {
			 *c = '0';
			 carry = 1;
		  }
      
		  return carry;
	}

	void add_one(char a[], int n)//n is the length of the string
	{
		 if(n<=0) return;

		 //reverse the string
		 reverse(a,n);
 
		 //add one
		 int carry = 0;
     
		 for(int i=0;i<n;i++)
		 {
			  if(i==0)//last digit
			  {
				   carry  = add_one_digit(&a[i], 1);
			  }
			  else
			  {
				   carry = add_one_digit(&a[i], carry);         
			  }
		 }
 
		 //reverse back
		 if(0 == carry) //no carry
		 {
			reverse(a,n);
		 }
		 else
		 {
			a[n] = '1';
			reverse(a,n+1);
		 }
	}

#define Max 10

	struct stack
	{
		 int data[Max]; //define Max to meet your own requirement
		 int top;
	};

	void initial(struct stack *s); //set the top = 0;

	struct stack s; //global
	void push(int n)
	{
	   if(s.top == Max) return; //full
	   s.data[s.top] = n;
	   s.top++;
	}

	int pop(void)
	{ 
	   if(s.top == 0) return -1; //empty
	   s.top--;
	   return s.data[s.top];
	}

	int top_of_stack(void)
	{
	   if(s.top == 0) return -1; //empty
	   return s.data[s.top-1];
	}
};

void main()
{
	char a[100] = "1999";
	char b[100];

	Solution s;
	s.add_one(a,4);
	cout << a <<endl;

	//s.memcpy(b,a,4);
	//cout << b << endl;

	system("pause");
}