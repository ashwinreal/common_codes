#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long *p,*temp;
	
//primes between m and n

int primes_below_n(long long n,long long m)
{
	
	for(long long i=0;i<=n-m;)
	{
		*(temp+i)=0;
		i++;
		
		
	}
	temp=p;
	long long a=sqrt(n+1);
	for(long long i=2;i<=a;i++)
	{
	long long t=ceil(double(m)/i)*i;
	//int t=(m/i)
	if(t==i)
	t+=t;
	for(long long j=t;j<=n;j=j+i)
	{
	
		long long y=j-m;
//		if(y<0)
//		cout<<y<<" "<<j;/
//		if(y>100000)
//		cout<<y<<" "<<j;
		*(temp + y)=1;
	}}
	temp=p;
	
	for(long long j=0;j<=n-m;j++)
	if(*(temp + j)==0)
	//cout<<j+m<<"\n";
	if(j+m!=1)
	printf("%lld\n",j+m);
}



int main()
{
	p=new long long [1000000];
	temp=p;
	long long t,m,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&m);
		scanf("%lld",&n);
	
	primes_below_n(n,m);
	printf("\n");
}
}
