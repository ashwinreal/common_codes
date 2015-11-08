#include <iostream>
using namespace std;

void hanoi(int n,char *s,char *a,char *d)
{
	if(n==1)
	{
		cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
		return ;
	}
	hanoi(n-1,s,d,a);
	cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
	hanoi(n-1,a,s,d);
}


int main()
{
	int n;
	cin>>n;
	char s[]="source";
	char a[]="auxillary";
	char d[]="dest.";
	hanoi(n,s,a,d);
	return 0;
}
