#include<iostream>

using namespace std;
void constructor(int arr[],int weight[],int n)
{
	for(int i=0;i<n;i++)
	arr[i]=i;
	for(int i=0;i<n;i++)
	weight[i]=1;
}
int root(int arr[],int a)
{
	int i=a;
	while(arr[i]!=i)
	{
		arr[i]=arr[arr[i]];    // path compression
		i=arr[i];
	}
	return i;
}
void unite(int arr[],int weight[],int n,int a,int b) //union/connect a to  b
{
	int r1=root(arr,a);
	int r2=root(arr,b);
	if(weight[r1]<weight[r2])
	{
	arr[r1]=r2;
	weight[r2]+=weight[r1];}
	else
	{
	
	arr[r2]=r1;
	weight[r1]+=weight[r2];
	}
	
}

int find(int arr[],int weight[],int n,int a,int b)//find if a connected to b
{
	int r1=root(arr,a);
	int r2=root(arr,b);
	if(r1==r2)
	return 1;
	else
	return 0;
}

int main()
{
	int arr[100],weight[100];
	// ith index of arr contains it parent index
	//initially all elements are their own parents
	
	//weight contains the ht of each tree with arr as parent
	//initially all weights are 1
	int n,a,b;
	cin>>n;
	constructor(arr,weight,n);
	while(1)
	{
		int c;
		cout<<"enter the choice\n";
		cin>>c;
		switch(c)
		{
			case 1:
				
				cin>>a>>b;
				unite(arr,weight,n,a, b) ;
				break;
			case 2:
				
				cin>>a>>b;
				cout<<find(arr,weight,n,a, b) ;
				break;
				case 3:
					cin>>a;
					cout<<root(arr,a);
		}
	}
	
	
	return 0;
}
