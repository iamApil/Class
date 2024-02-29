//file handling
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char data[100],idata[100];
	cout<<"enter a line "<<endl;
	cin.getline(data,100);
	ofstream outfile;
	outfile.open("myfile data");
    outfile<<data;
	outfile.close();
	ifstream infile;
	infile.open("myfile data");
	infile.getline(idata,100);
	cout<<"data in flie:"<<endl;
	cout<<idata;
	infile.close();
}

