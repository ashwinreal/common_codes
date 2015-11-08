#include<iostream>

using namespace std;
void swap(int arr[],int a,int b)
{
	int temp =arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
/*
void heapit(int arr[],int s)   // min heap indexes [0....n]
{
	for(int i=s/2-1;i>=0;i--)
	{
		int node=arr[i];
		int k=i;
		int j;
		bool heap=false;
		while(heap==false&&2*k+1<s)
		{
			j=2*k+1;
			if(j+1<s)
			if(arr[j]>arr[j+1])
			j=j+1;
			if(arr[j]<node)
			{
			arr[k]=arr[j];
			k=j;
		}else
		heap=true;
		}
		arr[k]=node;
	}
	
}
*/
//array indexing from [1....s]
void heapit(int arr[],int s) // create a maximum heap.... the parent is greater than children
{
	int i,j,k,node;
	bool heaped;
	for(int i=(s)/2;i>=1;i--)
	{
		k=i;
		
	    node=arr[i];
		heaped=false;
		while(heaped==false && 2*k<=s)
		{
			j=2*k;
			if(j+1<=s) // two sub nodes are present
			{
				if(arr[j+1]>arr[j]) // checking for larger of both
				j=j+1;
			}
			if(node<arr[j])
			{
			arr[k]=arr[j];
			k=j;
			}
			else
			heaped=true;
		}
		arr[k]=node;
	}
}
void del_max(int arr[],int &s)
{
	swap(arr,1,s);
	s=s-1;
	
	
}
void heap_sort(int arr[],int s)///sort arr[1...s]
{
	int ctr=1;
	int initial=s;
	while(ctr<=initial)
	{
		heapit(arr,s);
		cout<<arr[1];
		del_max(arr,s);
		heapit(arr,s);
		
		//cout<<arr[ctr];
		ctr++;
		
		
	}
}
int main()
{
//	int arr[]={-1,5,7,1,2,9,11,8,3}; /// indexing from 1 
int arr[]={-1,2,9,7,6,5,8}; /// indexing from 1 
	/*heapit(arr,1,6);
	for(int i=1;i<=6;i++)
	cout<<arr[i]<<" ";*/
	//cout<<arr[1];
	heap_sort(arr,6);
	
}
