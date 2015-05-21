#include<iostream>

using namespace std;

int count_split_inversions(int arr[],int start,int end)
{
	int arr1[100],arr2[100],len1,len2,ctr,i;
	len1=len2=ctr=0;
	for(i=start;i<=(start+end)/2;i++)
	{
	len1++;
	arr1[i]=arr[i];
	}
	int j=0;
	for(;i<=end;i++)
	{
	len2++;
	arr2[j++]=arr[i];
	}
	//cout<<len1<<endl<<len2<<endl;
	i=j=0;
	/*for(int k=0;k<len1;k++)
	cout<<arr1[k];
	cout<<endl;
	for(int k=0;k<len2;k++)
	cout<<arr2[k];
	cout<<endl;*/
	while(i<len1 && j<len2)
	{
		if(arr1[i]>arr2[j])
		{
		ctr=ctr+(len1-i);
		j++;
		}
		else
		i++;
	}
	
	return ctr;
	
}
int count_inversions(int arr[],int start,int end)
{
	if(end-start<3)
	{
		int ctr=0;
		for(int i=start;i<=end;i++)
		for(int j=i+1;j<=end;j++)
		if(arr[i]>arr[j])
		ctr++;
		
		return ctr;
	} 
	else
	{
		int a=count_inversions(arr, start ,(start+end)/2);
		int b=count_inversions(arr, ((start+end)/2)+1, end);
		int c=count_split_inversions(arr,start,end);
		return a+b+c;
	}
}
int main()
{
	int arr[]={1,3,5,7,2,4,6,8,9};
	cout<<count_inversions(arr,0,7);
}
