#include<iostream>
#include<conio.h>
using namespace std;
void student_R()
{
		string ss,nam,address,reg,cellno;
		int rollno;
		getline(cin,ss);
		cout<<"Enter Student name        : ";
		getline(cin,nam);
		cout<<"Enter Student Cell no     : ";
		getline(cin,cellno);
		cout<<"Enter House Address       : ";
		getline(cin,address);
		cout<<"Enter CNIC no as a reg no : ";
		getline(cin,reg);
		cout<<"Enter Roll No             : ";
		cin>>rollno;
		cout<<endl<<endl;
		cout<<"\t Record save successfully\n";
		cout<<endl;
		cout<<"Name            : "<<nam<<endl;
		cout<<"Cell no         : "<<cellno<<endl;
		cout<<"Address         : "<<address<<endl;
		cout<<"Registration no : "<<reg<<endl;
		cout<<"Roll no         : "<<rollno<<endl;
	
}
int main()
{
	int record;
	cout<<"How many Record you Want to Enter: ";
	cin>>record;
	cout<<endl;
	for(int i=1;i<=record;i++)
	{
		cout<<endl;
		cout<<"*****************************************";
		cout<<endl;
		cout<<"\t Enter "<<i<<" Student Record \n\n";
		student_R();
		
	}
	
	getch();
	return 0;
}
