#include<iostream>
#include<string>
using namespace std;
string substr(string s ,long i,long j)
{
	string s1="";
	for(long t=i;t<=j;t++)
	{
		char a=s[t];
		s1=s1 + a;
	}
	return s1;
}

int main()
{
	/*
	find substring from pos i to j
	
	*/
}
