#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
long long m=1000000000+7;
long long power(long long x,long long y)
{
    long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2)%m;
    if (y%2 == 0)
        return (temp*temp)%m;
    else
        return (x*((temp*temp)%m))%m;
}


using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	//cin.tie(0);
	long long t;
	cin>>t;
	long long a[100000];
	while(t--)
	{
		long long n;
		cin>>n;
		
		cout<<power(2,m-1-(n-1))<<endl;
		
	}	
	
	return 0;
}
