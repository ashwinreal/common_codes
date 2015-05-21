#include<iostream>
//                           Minimum Steps to 1

/*
 On a positive integer, you can perform any one of the following 3 steps. 1.) Subtract 1 from it. ( n = n - 1 )  , 
 																		  2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )  ,
																		  3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  )
Now the question is, given a positive integer n, find the minimum number of steps that takes n to 1
 eg: 1.)For n = 1 , output: 0       2.) For n = 4 , output: 2  ( 4  /2 = 2  /2 = 1 )    3.) 
  For n = 7 , output: 3  (  7  -1 = 6   /3 = 2   /2 = 1 )

*/
using namespace std;
const int maxlen = 100;
int min(int a, int b)
{
	if(a>b)
	return b;
	else
	return a;
}
int main()
{
	int n;
	int arr[maxlen+1];
	arr[0]=-1;
	arr[1]=0;
	for(int i=2;i<=100;i++)
	{
		arr[i]=1+arr[i-1];
		if(i%2 == 0)
		arr[i]= min(arr[i],1+arr[i/2]) ;
		if(i%3 == 0)
		arr[i]= min(arr[i],1+arr[i/3]) ;
	}
	
	cout<<arr[7];
	
	
}
