#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

long long gcd,x,y;
void extended(long long a,long long b)
{
	if(a<b)
	extended(b,a);
	if(b==0)
	{
		gcd=a;
		x=1;
		y=0;
		return;
	}
	extended(b,a%b);
	long long temp=x;
	x=y;
	y=temp-(a/b)*y;

}

int main()
{
	long long a,b;
	cin>>a>>b;
	extended(a,b);
	cout<< gcd << " "<< x << " "<< y;
	return 0;
}
