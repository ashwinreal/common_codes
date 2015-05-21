/*
		find all subsets except {} of a given subset

*/

#include<iostream>
#include<string>
using namespace std;
long power(long b,long p)
{
	long ans=1;
	for(long i=0;i<p;i++)
	ans*=b;
	return ans;
}
int main()
{
	std::ios_base::sync_with_stdio (false);
	int n,set[20];
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>set[i];
	}
	for(long i=1;i<=power(2,n)-1;i++)
	{
		long ctr=0;
		for(long j=i;j>=1;j=j/2)
		{
			if(j%2==1)
			cout<<set[ctr]<<" ";
			
			ctr++;
			
		}
		cout<<endl;
	}
	
	
	
}
