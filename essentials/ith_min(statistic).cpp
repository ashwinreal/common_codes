#include<iostream>
										// O(n) time algorithm for ith minimum element
using namespace std;

void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

/*int partition(int arr[],int start,int end,int pivot,int pivot_pos)
{
	int i=start+1;
	swap(arr,pivot_pos,start);
	for(int j=i;j<=end;j++)
	if(arr[j]<pivot)
	{
		swap(arr,i,j);
		i++;
	}
	swap(arr,i-1,start);
	return i-1;
}
*/
int partition(int arr[],int start,int end,int pivot,int pivpos)
{
	swap(arr,start,pivpos);
	int i=start+1;
	for(int j=i;j<=end;j++)
	{
		if(arr[j]<pivot)
		{
			swap(arr,j,i);
			i++;
		}
		
	}
	swap(arr,i-1,start);
	return i-1;
	
}
void ith_order_statistic(int arr[],int start,int end,int ith)
{
	if(start<=end)
	{
		int j=partition(arr,start,end,arr[start],start );
		//cout<<"__"<<j<<ith<<start<<end<<endl;
		if(j==ith)
		{
		//cout<<"hello";
		cout<< arr[ith];
	}
		else
		if(ith<j)
		ith_order_statistic(arr,start,j-1, ith);
		else if(ith>j)
		ith_order_statistic(arr, j+1, end , ith);
	}
}

int main()
{
	int arr[]={12,6,1,2,10,7,3,5,8,4,11,0};
	for(int i=0;i<12;i++)
	ith_order_statistic(arr, 0, 11 ,i);
}
