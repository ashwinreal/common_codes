#include<iostream>
using namespace std;
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void permute_rec(int arr[],int size,int k)
{
	if(k==size)
	{
	for(int i=0;i<size;i++)
	cout<<arr[i];
	cout<<endl;
	}
	else
	{
		for(int j=k;j<size;j++)
		{
			swap(arr,j,k);
			permute_rec(arr,size,k+1);
			swap(arr,k,j);
		}
	}
}

int main()
{
	int arr[]={2,1,3};
	permute_rec(arr,3,0);
}
