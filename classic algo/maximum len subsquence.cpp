#include<iostream>

using namespace std;
int main()
{
	int arr[]={1,0,0,2,3,4,0,5,0,1,1};
	int size=11;
	int max=1;
	int len=1;
	int pos=0;
	len=1;
		for(int j=1;j<size;j++)
		{
		
		if(arr[j]>=arr[j-1])
		{
			//cout<<arr[j];
			len++;
			
			
		}else {//cout<<" "<<len<<" ";
			if(len>max)
			max=len;
			
			len=1;
		}
	}
	
	cout<<" "<<max;
}
