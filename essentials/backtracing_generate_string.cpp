#include <iostream>
using namespace std;

// create all arrays of size n with elements of set[]

long long arr[10000000]={0};
void gen(long long n,long long set[],long long szset,long long arr[],long long nn)
{

	if(n==0)
	{
		for(long long i=0;i<nn;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	for(long long i=0;i<szset;i++)
	{
		//cout<<"!";
		arr[n-1]=set[i];
		//cout<<arr[n-1];
		gen(n-1,set,szset,arr,nn);
	}
	
}

int main()
{
	long long set[]={1,2,3,4,5,6};
	long long szset=6;
	long long n=3;
	gen(n,set,szset,arr,n);
	return 0;
}
