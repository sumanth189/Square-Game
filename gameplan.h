#include<iostream>
using namespace std;

void display(int a[],int n);
void reset(int a[],int n);

void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(i%5==0)
			cout<<endl;
		cout<<a[i]<<"\t";
	}
}
void reset(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=0;
	}
}
