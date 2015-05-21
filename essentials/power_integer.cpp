#include<iostream>
#include<string>
using namespace std;
 long long power2(long long n)
{
	return (1<<n);
}
long long power10(long long n)
{
	
	
		static long long arr[]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
		cout<<arr[n];
	
}
long long power(long long b,long long p)
{
	long long ans=1;
	if(b==2)
	ans=power2(p);
	else
	if(b==10&&p<=12)
	ans=power10(p);
	else
	for(long long i=0;i<p;i++)
	ans*=b;
	return ans;
}

int main()
{
	/*
	                   POEWR FUNCTION
	*/
	cout<<power(2,10);
}
