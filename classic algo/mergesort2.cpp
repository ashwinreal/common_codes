#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main()
{
    int a[20], i;
    cout<<"enter  the elements\n";
    for (i = 0; i < 6; i++)
    {
        cin>>a[i];
    }
    mergesort(a, 0, 5);
    cout<<"sorted array\n";
    for (i = 0; i < 6; i++)
    {
        cout<<a[i];
    }
  

}

/*
#include<iostream>
using namespace std;

void merge(int arr[],int start,int end)
{
	int mid=(start+end)/2;
	int c[100];
	int i,k;
	i=k=start;
	int j=mid+1;
	while(i<=mid&&j<=end)
	{
		if(arr[i]<arr[j])
		c[k++]=arr[i++];
		else
		c[k++]=arr[j++];
	}
	while(i<=mid){
		c[k++]=arr[i++];
	}
	while(j<=end)
	{
		c[k++]=arr[j++];
	}
	for(int p=start;p<=end;p++)
	arr[p]=c[p];
}
void mergesort(int arr[],int start,int end)
{
	if(start<end)
	{
		int mid =(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,end);
	}
}
int main()
{
	int arr[]={5,2,7,9,8,1,2,0,5,3,4,7};
	quicksort(arr,0,11);
	for(int i=0;i<=11;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}




*/
