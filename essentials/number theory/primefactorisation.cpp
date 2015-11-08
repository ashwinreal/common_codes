#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
long long arr[200000000];
// minprime computes the minimal prime number that divides i
long long minprime[10000001]={0};

void minprimefn(long long n)
{
	for(long long i=2;i<=n;i++)
	{
		if(minprime[i]==0)     // if i i prime
		{
			for(long long j=i*i;j<=n;j=j+i)
			{
				minprime[j]=i;
			}
		}
	}
	for(long long i=2;i<=n;i++)
	if(minprime[i]==0)
	{
		minprime[i]=i;
	}
	
}
long long primefactor[100000];  //stores prime factorisation 12 = 3 2 2 
long long sz=0;
void factorise(long long n)
{
	while(n!=1)
	{
		primefactor[sz++]=minprime[n];
		n=n/minprime[n];
	}
}


int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	minprimefn(10000000);
	
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		factorise(n);
		for(long long i=0;i<sz;i++)
		cout<<primefactor[i]<<" ";
		cout<<endl;
		sz=0;
	}
	
	return 0;
}
