#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
				void remove_SMR()
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
							while (!ofile.eof())
								{
									string rollno,marks[5],name;

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
												cout<<"        Record Delete Successfully"<<endl;
												cout<<"***********************************************"<<endl;
												cout<<endl<<endl;											
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
