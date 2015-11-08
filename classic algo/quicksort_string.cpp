#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

void swap(string &arr,int i,int j)
{
	char temp;temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition(string &arr,int start,int end,char pivot,int pivpos)
{
	swap(arr,start,pivpos);
	int i=start+1;
	for(int j=i;j<=end;j++)
	{
		char c=arr[j];
		if(c<pivot)
		{
			swap(arr,j,i);
			i++;
		}
		
	}
	swap(arr,i-1,start);
	return i-1;
	
}
void quicksort(string &arr,int start,int end)
{
	if(start<end)
	{
		int pivot1=start+(rand()%(end-start+1));
		int pivot2=partition(arr,start,end,arr[start],start);
		quicksort(arr,start,pivot2-1);
		quicksort(arr,pivot2+1,end);
    }
	
	
	
}

int main()
{
	int n;
	string arr="dabce";
//	swap(arr,0,3);
	quicksort(arr,0,4);
	//int p=partition(arr,0,6,arr[0],0);
//	for(int i=0;i<15;i++)
	cout<<arr<<" ";
//	cout<<endl<<p;
	return 0;
}













