#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

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
void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
		int pivot1=start+(rand()%(end-start+1));
		int pivot2=partition(arr,start,end,arr[pivot1],pivot1);
		quicksort(arr,start,pivot2-1);
		quicksort(arr,pivot2+1,end);
    }
	
	
	
}

int main()
{
	int n;
	int arr[]={1,1,2,10,7,7,1,3,2,5,8,4,10,11,0};
	quicksort(arr,0,14);
	//int p=partition(arr,0,6,arr[0],0);
	for(int i=0;i<15;i++)
	cout<<arr[i]<<" ";
//	cout<<endl<<p;
	return 0;
}



/*


#include<iostream>
using namespace std;

void swap (long long arr[],long long a ,long long b)
{
	long long temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
long long partition (long long arr[],long long start,long long end,long long pivot,long long pivotpos)//0 th ele as pivot
{
	swap(arr[start],arr[pivotpos]);
	long long ctr=start;
	for(long long i=start+1;i<=end;i++)
	{
		if(arr[i]  <  arr[start])
		{
			swap(arr,ctr+1,i);
			ctr++;
		}
	}
	swap(arr[start],arr[ctr]);
	return ctr;
}
void quicksort(long long arr[],long long start,long long end)
{
	
	if(start<end)
	{
		long long pivot=partition(arr,start,end,arr[start],start);
		
		quicksort(arr,start,pivot-1);
		
		quicksort(arr,pivot+1,end);
	}	
}


int main()
{
	long long arr[]={5 ,4, 3 ,2 ,7 ,8 ,9 ,0 ,1};
//	int j=partition(arr,0,8,arr[0],0);
//	cout<<j<<endl;
	quicksort(arr,0,8);
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}



*/


/*

#include<iostream>
using namespace std;
void swap(int arr[],int a,int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

int partition(int arr[],int start,int end,int pivot_pos)//pivot element is pivot_pos
{
	int pivot=arr[pivot_pos];
	swap(arr,start,pivot_pos);
	int i=start+1;
	int j=start+1;
	while(j<=end)
	{
		if(arr[j]<pivot){
		swap(arr,i,j);
		i++;}
		j++;
	}
	swap(arr,i-1,start);
	return i-1;
}
void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
	int p=partition(arr,start,end,start);
	quicksort(arr,start,p-1);
	quicksort(arr,p+1,end);
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






