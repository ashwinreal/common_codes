#include<iostream>

using namespace std;

void insertion_sort(long long arr[],long long size)
{
	
	for(long long i=1;i<size;i++)
	{
		long long key=arr[i];
		long long j=i-1;
		
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
		
	}
}

int main()
{
	
	long long arr[]={5 ,4, 3 ,2 ,7 ,8 ,9 ,0 ,1};
	insertion_sort(arr,9);
	
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;	
}
