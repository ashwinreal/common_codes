#include<iostream>

using namespace std;

int main()
{
	int arr[101];
	arr[1]=1;
	 arr[2]=2;
	long long ways=0;
	for(int i=3;i<=100;i++)
	{
		arr[i]=(arr[i-1]%1000000009 + arr[i-2]%1000000009)%1000000009; 
		
		//arr[i]=(1+arr[i-1])+(1+arr[i-2]);
	}
	cout<<arr[5];
}
