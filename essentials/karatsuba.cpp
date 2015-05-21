#include<iostream>
using namespace std;

long long power(long long b,long long p)
{
	long long ans=1;
	for(long long i=0;i<p;i++)
	ans*=b;
	return ans;
}
long long power10(long long n)
{
	
	
		static long long arr[]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
		return arr[n];
	
}

 long long no_of_digits( long long n)
{
	 long long temp=0;
	while(n>0)
	{
		temp++;
		n/=10;
	}
	return temp;
}
 long compute_a( long long num)
{
	return (num/power10(no_of_digits(num)/2));	
}
 long  long compute_b( long long num)
{
	return (num%power10(no_of_digits(num)/2));	
}
 long long mul( long long n, long long m)
{
	if(m>n)
	mul(m,n);
	if(n/10==0||m/10==0)
	return n*m;
	else
	{
		 long long t1=mul(compute_a(n),compute_a(m));
		 long long t2=mul(compute_b(n),compute_b(m));
		 long long t3=mul(compute_a(n)+compute_b(n),compute_a(m)+compute_b(m));
		return (mul(power10(no_of_digits(n)),t1 )
			     + mul(power10((no_of_digits(n))/2),(t3-t2-t1))
			     + (t2));
	}
	

}

int main()
{
	cout<<mul(120,10);
}
