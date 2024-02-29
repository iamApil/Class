//exception handling
#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"enter any two number :";
	cin>>a>>b;
	if(b==0)
	{
	try{
		throw 0;
	}
	catch (int b)
	{
		cout<<"the value of b is zero so the result is infinity"<<endl;
	}
}
	c=a/b;
	cout<<"result"<<c;
}
