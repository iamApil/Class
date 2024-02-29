/*exception handling ...try,throw,catch.
example**ptogram to demonstrate the concept of exception handling.*/
#include<iostream>
using namespace std;
int main()
{
	try
	{
		throw 20;
	}
	catch(int a)
	{
		cout<<"dont throw "<<a<<endl;
	}
}
