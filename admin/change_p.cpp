#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int mian()
{
	again_p:
	string static admin_p="admin",password;	
	cout<<"Enter Password: ";
	cin>>password;
	if(password==admin_p)
	{
		cout<<"ok";
		cout<<"Enter new Password";
		cin>>admin_p;
		cout<<"Password Successfully Change";
		cout<<endl<<"Enter again Password"<<endl;
		goto again_p;
	}
	else
	{
		cout<<"Worng Password";
		goto again_p;
	}
	getch();
	return 0;
	
}
