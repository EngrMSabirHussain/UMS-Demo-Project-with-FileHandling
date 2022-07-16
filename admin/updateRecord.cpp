#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
				void update_record()
					{
						fstream ofile, dfile;
						ofile.open("studentMarks.text", ios::in);
						dfile.open("temp.text", ios::out);
							if (!ofile.is_open()&& !dfile.is_open())
								{
									cout << "File not Find";	
								}
							string search;
   							cout << "Enter Student Roll no: ";
   							cin >> search;
   							bool flag=0;
   							int l=1,i=1;
							while (!ofile.eof())
								{
									string rollno,marks[5],name;
										//	l++;
          							//if(l%7==0)
          							i++; 
											getline(ofile,rollno);   					
											getline(ofile,name);
											getline(ofile,marks[0]);
	  										getline(ofile,marks[1]);
											getline(ofile,marks[2]);
											getline(ofile,marks[3]);
											getline(ofile,marks[4]);
									if (rollno == search)
										{
											flag = 1;
											cout<<"\n\n\t old Record Find\n"<<endl;
											cout<<"Roll no         : "<<rollno<<endl;
											cout<<"Student Name    : "<<name<<endl;
											cout<<"Physics Marks   : "<<marks[0]<<endl;
											cout<<"Calculus Marks  : "<<marks[1]<<endl;
											cout<<"ITC Marks       : "<<marks[2]<<endl;
											cout<<"English Marks   : "<<marks[3]<<endl;
											cout<<"PF Marks        : "<<marks[4]<<endl;	
											cout<<endl<<endl;
											cout<<"***********************************************"<<endl;
											cout<<"                 Update Record"<<endl;
											cout<<"***********************************************"<<endl;
											cout<<endl<<endl;
											
											
											cout<<"Enter Student Roll no  : ";
											cin>>rollno;
											cin.ignore();									    
											cout<<"Enter Student Name     : ";
											getline(cin,name);
											cout<<endl;		
											Again:
											cout<<"Marks obtained From Physics Out of '100'  = ";
											cin>>marks[0];
											cout<<"Marks obtained From Calculus Out of '100' = ";
											cin>>marks[1];
											cout<<"Marks obtained From ITC Out of '100'      = ";
											cin>>marks[2];
											cout<<"Marks obtained From English Out of '100'  = ";
											cin>>marks[3];
											cout<<"Marks obtained From PF Out of '100'       = ";
											cin>>marks[4];		
										dfile<<rollno<<endl<<name<<endl<<marks[0]<<endl<<marks[1]<<endl<<marks[2]<<endl<<marks[3]<<endl<<marks[4]<<endl;
										}
									else
										{
										dfile<<rollno<<endl<<name<<endl<<marks[0]<<endl<<marks[1]<<endl<<marks[2]<<endl<<marks[3]<<endl<<marks[4]<<endl;
										}
								}
							if (flag == 0)
								{
									cout << "Record not Exist" << endl;
								}
						ofile.close();
						dfile.close();
						remove("studentMarks.text");
						rename("temp.text", "studentMarks.text");
						}
int main()
{
	update_record();
	getch();
	return 0;
}
