#include<iostream>
using namespace std;

void k_rot(int arr[],int size,int k)
{
	int moves=0;
	int temp,temp2;
	int i=0;
	temp2=arr[0];
	while(moves!=size)
	{
		if(i+k<size)
		{
			temp=arr[i+k];
			arr[i+k]=temp2;
			temp2=temp;
			i=i+k;
			moves++;
		}
		else
		{
			temp=arr[i+k-size];
			arr[i+k-size]=temp2;
			temp2=temp;
			i=i+k-size;
			moves++;
		}
	}
}
void k_rot_rec(int arr[],int n,int change,int value,int k,int moves)
{
	if(moves<n)
	{
	
	int temp=arr[change];
	arr[change]=value;
	value=temp;
	moves++;
	if(change+k<n)
	{
	
	change=change+k;
	k_rot_rec(arr,n, change,value, k,moves);}
	else{
	
	change=change+k-n;
	k_rot_rec(arr,n, change,value, k,moves);}
}
}
int main()
{
	int arr[]={1,2,3,4,5};
	k_rot_rec(arr,5,4,arr[0],4,0);
	for(int i=0;i<5;i++)
	cout<<arr[i];
}
