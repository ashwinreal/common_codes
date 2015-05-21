#include<iostream>
using namespace std;
void bbl_sort(long long a[],long n)
{
	for(int i =0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(a[j]<a[i])
	{
		long long temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
int main()
{
	
	long long arr[]={5 ,4, 3 ,2 ,7 ,8 ,9 ,0 ,1};
	bbl_sort(arr,9);
	
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;	
}
