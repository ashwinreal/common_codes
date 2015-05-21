//lazy caterer problem

// f(n) = n + f(n-1)


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
	long t,n,ans,i;
	cin>>t;
	while(t--)
	{
	
		cin>>n;
		for( i=0;;i++)
		{
			if(n<=(i*i + i + 2)/2)
			break;
		}
	
		ans=i;
		
		
		cout<<ans<<endl;
		
	}
	
}
