#include<iostream>
#include<algorithm>
using namespace std;

int binsrch(int a[],int high,int low,int ele) // sorted in ascending
{
	int val=0;
	
	 while(high>=low)
	 {
	 	int mid=(high+low)/2;
	 	if(a[mid]==ele)
	 	{
	 		 return 1;
	 	}
	 	else if(a[mid]>ele)
	 	high=mid-1;
	 	else
	 	low=mid+1;
	 	
	 	
	 	
	 }	return 0;
	 
	 
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	
	int arr[100];
	for(int i=0;i<5 ;i++)
	cin>>arr[i];
	cout<<binsrch(arr,4,0,3);
	
}
