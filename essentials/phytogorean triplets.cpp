#include<iostream>
#include<cmath>
using namespace std;

//                       All pythogorean triplets ( a^2 + b^2 = c^2 )  ... for  c<=n

long gcd(long a, long b)
{
	if(a<b)
	gcd(b,a);
	if(a%b == 0)
	return b;
	else
	{
		if(a%b < (b/2))
		gcd(b,a%b);
		else
		gcd(b,b-(a%b));
	}
	
}

//calcultes rest of the triplets a,b,c are primitive triplets
void rest_of_triplets(int a,int b,int c,int d)
{
	int k=2;
	while(k*c<=d)
	{
		cout<<k*a<<" "<<k*b<<" "<<k*c<<endl;
		k++;
	}
}





//   calculates all the primitives triplets
void primintive_triplets(int d)
{
	int m,n,a,b,c;
	for(m=2;m<d;m++)
	for(n=1;((m*m + n*n)<=d);n++)
	{
		if(gcd(m,n)==1 && (m-n)%2==1)
	{
		a=m*m - n*n;//
		b=2*m*n;    //        Primitive triplets 
		c=m*m + n*n;//
		cout<<a<<" "<<b<<" "<<c<<endl;//
		rest_of_triplets(a,b,c,d);
	}
		
	}
}

int main()
{
	int c,a,b;
	primintive_triplets(100);

	
	
}
