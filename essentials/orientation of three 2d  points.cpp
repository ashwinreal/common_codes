#include<iostream>
using namespace std;

struct point
{
	int x;
	int y;
};

int orientation(point p1,point p2,point p3) // 1 for clockwise , 2 for anti - clock , 0 for collinear
{
	int val = (p3.x-p2.x)*(p2.y-p1.y)  -  (p3.y-p2.y)*(p2.x-p1.x);
	if(val==0)
	return 0;
	else if (val>0) 
	return 2 ;
	else 
	return 1;
	
} 
int main()
{
	std::ios_base::sync_with_stdio(false);
	point p1,p2,p3;
	p1.x=0;
	p1.y=0;
	p2.x=5;
	p2.y=5;
	p2.x=0;
	p2.y=7;
	cout<<orientation(p1,p2,p3);
}
