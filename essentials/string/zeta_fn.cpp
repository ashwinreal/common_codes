#include <iostream>
using namespace std;

//z[i] is the len of largest substring starting at i and is also a prefix

int min(int a,int b)
{
	if(a<b)
	return a;
	return b;
	
}
long long z[100000]={0};
void zeta( char s[])  
{
	int i=1;
	int l,r;
	l=r=-1;
	while(s[i]!='\0'){
		int j,k;
		j=0;
		k=i;
		if(i>=l && i<=r)
		{
			j=min(i-l+z[i-l],r-l+1) -(i-l);
			k=i+j;
		}
		while(s[k]!='\0' && s[j]==s[k])
		{
			k++;
			j++;
		}
		z[i]=k-i;
		if(z[i]>0 && i+z[i]-1>r)
		{
			l=i;
			r=i+z[i]-1;
		}
		i++;	
	}
}
int main()
{
	char s[]="abrabracadabra";
	zeta(s);
	int i=0;
	while(s[i]!='\0')
	{cout<<z[i]<<" ";i++;}
	return 0;
}
