#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;
 string grade(string);

void admin(void);
// Admin 1st operation
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
	 					// file output start
					ofstream std;
						std.open("studentRecord.text",ios::app);
						std<<reg<<endl;
						std<<nam<<endl;
		  				std<<rollno<<endl;
		 				std<<cellno<<endl;
						std<<address<<endl;
					std.close();
						// file output end	
					cout<<endl<<endl;
					cout<<"\t Record save successfully\n";
					cout<<endl;
					cout<<"Name            : "<<nam<<endl;
					cout<<"Cell no         : "<<cellno<<endl;
					cout<<"Address         : "<<address<<endl;
					cout<<"Registration no : "<<reg<<endl;
					cout<<"Roll no         : "<<rollno<<endl;
	
				}
// Admin 2nd operation				
				void Display_ASR()
				{
									//Display_ASR();
			
					cout<<"\t\t============================================\n";
					cout<<"\t\t             All Student Record\n";
					cout<<"\t\t============================================\n";
					cout<<endl<<endl;
	
					cout<<endl<<endl;
				
					ifstream ASR;
					ASR.open("studentRecord.text");
					string name,cell,addr,reg,roll;
					if(!ASR)
					cout<<"File not find";
	 					  	getline(ASR,reg);
							getline(ASR,name);
							getline(ASR,roll);
	    					getline(ASR,cell);
							getline(ASR,addr);
					int i=1;
					while(!ASR.eof())
							{
		
								cout<<"\tSTUDENT no# "<<i<<endl<<endl;
								cout<<"\tStudent ID   : "<<reg<<endl;
								cout<<"\tStudent Name : "<<name<<endl;
								cout<<"\tRoll no      : "<<roll<<endl;
								cout<<"\tcell no      : "<<cell<<endl;
								cout<<"\tAddress      : "<<addr<<endl;
								i++;
								cout<<endl<<endl;
								getline(ASR,reg);
								getline(ASR,name);
								getline(ASR,roll);
	  							getline(ASR,cell);
								getline(ASR,addr);
		
							}
					ASR.close();
				
				}
// Admin 3rd operation
				void Search_R()
				{
					   	string line;
  						string search;
  						int nrf=0; //not record find
   						cout << "Enter Registration no: ";
   						cin >> search;
   
    					ifstream ssr ("studentRecord.text");
    					string name,cell,addr,reg,roll;
    					int l=1,i=1;
    				if(ssr.is_open())
     					{
       						 while(!ssr.eof())
       							{                   
        							getline (ssr,line);
        	  						l++;
          							if(l%5==0)
          							i++;  
       	 							if(search == line )
         								{
         									nrf++;
							 				cout<<endl<<endl;
											reg=line;
											getline(ssr,name);
											getline(ssr,roll);
	  										getline(ssr,cell);
											getline(ssr,addr);
        									cout<<"\tSTUDENT no# "<<i<<endl<<endl;
											cout<<"\tStudent ID   : "<<reg<<endl;
											cout<<"\tStudent Name : "<<name<<endl;
											cout<<"\tRoll no      : "<<roll<<endl;
											cout<<"\tcell no      : "<<cell<<endl;
											cout<<"\tAddress      : "<<addr<<endl;					
         								}
        						}
        				ssr.close();
        				if(nrf==0)
       					 cout<<" Sorry Record not Exist ";
    
     					}
     				else
         			cout << "File error\n";				
				}
// Admin 4th operation
				void update_record()
					{
						fstream ofile, dfile;
						ofile.open("studentRecord.text", ios::in);
						dfile.open("temp.text", ios::out);
							if (!ofile.is_open()&& !dfile.is_open())
								{
									cout << "File not Find";	
								}
							string search;
   							cout << "Enter Registration no: ";
   							cin >> search;
   							bool flag=0;
   							string name,cell,addr,reg,roll;
   										getline(ofile,reg);
										getline(ofile,name);
										getline(ofile,roll);
	  									getline(ofile,cell);
										getline(ofile,addr);
							while (!ofile.eof())
								{
									
    					

									if (reg == search)
										{
											flag = 1;
											cout<<"\n\n\t old Record Find\n"<<endl;
											cout<<"\tStudent ID   : "<<reg<<endl;
											cout<<"\tStudent Name : "<<name<<endl;
											cout<<"\tRoll no      : "<<roll<<endl;
											cout<<"\tcell no      : "<<cell<<endl;
											cout<<"\tAddress      : "<<addr<<endl;
											cout<<endl<<endl;
											cout<<"***********************************************"<<endl;
											cout<<"                 Update Record"<<endl;
											cout<<"***********************************************"<<endl;
											cout<<endl<<endl;
											
											cin.ignore();
											cout<<"Enter Student name        : ";
											getline(cin,name);	    
											cout<<"Enter Student Cell no     : ";
											getline(cin,cell);		
											cout<<"Enter House Address       : ";
											getline(cin,addr);		    
											cout<<"Enter CNIC no as a reg no : ";
											getline(cin,reg);		    
											cout<<"Enter Roll No             : ";
											getline(cin,roll);		
										dfile<<reg<<endl<<name<<endl<<roll<<endl<<cell<<endl<<addr<<endl;
										}
									else
										{
										dfile<<reg<<endl<<name<<endl<<roll<<endl<<cell<<endl<<addr<<endl;
										}
										getline(ofile,reg);
										getline(ofile,name);
										getline(ofile,roll);
	  									getline(ofile,cell);
										getline(ofile,addr);
								}
							if (flag == 0)
								{
									cout << "Record not Exist" << endl;
								}
						ofile.close();
						dfile.close();
						remove("studentRecord.text");
						rename("temp.text", "studentRecord.text");
						}
//Admin 5th operation Remove Record
					void remove_record()
						{
							fstream ofile, dfile;
							ofile.open("studentRecord.text", ios::in);
							dfile.open("temp.text", ios::out);
								if (!ofile.is_open()&& !dfile.is_open())
									{
										cout << "File not Find";	
									}
										string search;
   										cout << "Enter Registration no: ";
   										cin >> search;
   										bool flag=0;
   											string name,cell,addr,reg,roll;
    					
											getline(ofile,reg);
											getline(ofile,name);
											getline(ofile,roll);
	  										getline(ofile,cell);
											getline(ofile,addr);
								while (!ofile.eof())
									{
									
										if (reg == search)
											{
												flag = 1;
												cout<<"\n\n\t old Record Find\n"<<endl;
												cout<<"\tStudent ID   : "<<reg<<endl;
												cout<<"\tStudent Name : "<<name<<endl;
												cout<<"\tRoll no      : "<<roll<<endl;
												cout<<"\tcell no      : "<<cell<<endl;
												cout<<"\tAddress      : "<<addr<<endl;
												cout<<endl<<endl;
												cout<<"***********************************************"<<endl;
												cout<<"        Record Delete Successfully"<<endl;
												cout<<"***********************************************"<<endl;
												cout<<endl<<endl;	
											}
										else
											{
												dfile<<reg<<endl<<name<<endl<<roll<<endl<<cell<<endl<<addr<<endl;
											}
											getline(ofile,reg);
											getline(ofile,name);
											getline(ofile,roll);
	  										getline(ofile,cell);
											getline(ofile,addr);
									}
						if (flag == 0)
							{
								cout << "Record not Exist" << endl;
							}
						ofile.close();
						dfile.close();
					remove("studentRecord.text");
					rename("temp.text", "studentRecord.text");
					}

void Porfessor(void);
// Professor 1st function Student marks
				void student_M()
				{
					string ss,name;
					int rollno,marks[5];
					getline(cin,ss);
					cout<<"Enter Student Roll no  : ";
					cin>>rollno;
					getline(cin,ss);	    
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
					for(int i=0; i<=4; i++)
						{
							if(marks[i]>100)
								{
									cout<<"\n The marks you enter greter than 100 So, Re- Enter the Marks"<<endl;
										goto Again;
								}
						}
	 					// file output start
					ofstream StdM;
						StdM.open("studentMarks.text",ios::app);
						StdM<<rollno<<endl;
						StdM<<name<<endl;
						for(int i=0;i<=4;i++)
						{
							StdM<<marks[i]<<endl;
						}
					StdM.close();
						// file output end	
					cout<<endl<<endl;
					cout<<"\t Student Marks Record save successfully\n";
					cout<<endl;
					cout<<"Roll no         : "<<rollno<<endl;
					cout<<"Student Name    : "<<name<<endl;
					cout<<"Physics Marks   : "<<marks[0]<<endl;
					cout<<"Calculus Marks  : "<<marks[1]<<endl;
					cout<<"ITC Marks       : "<<marks[2]<<endl;
					cout<<"English Marks   : "<<marks[3]<<endl;
					cout<<"PF Marks        : "<<marks[4]<<endl;
	
				}

//professor 2nd operation all class result
				void Class_R()
				{
									//Class_R();
			
					cout<<"\t\t============================================\n";
					cout<<"\t\t             Class Marks Records\n";
					cout<<"\t\t============================================\n";
					cout<<endl<<endl;
	
					cout<<endl<<endl;
				
					ifstream CMR;
					CMR.open("studentMarks.text");
					string rollno,marks[5],name;
					if(!CMR)
					cout<<"File not find";
	 					  	getline(CMR,rollno);
							getline(CMR,name);
							getline(CMR,marks[0]);
	    					getline(CMR,marks[1]);
							getline(CMR,marks[2]);
							getline(CMR,marks[3]);
							getline(CMR,marks[4]);
					int i=1;
					while(!CMR.eof())
							{
								cout<<endl;
								cout<<endl;
		
								cout<<"\tSTUDENT no# "<<i<<endl<<endl;
								cout<<"Roll no         : "<<rollno<<endl;
								cout<<"Student Name    : "<<name<<endl;
								cout<<"Physics Marks   : "<<marks[0]<<endl;
								cout<<"Calculus Marks  : "<<marks[1]<<endl;
								cout<<"ITC Marks       : "<<marks[2]<<endl;
								cout<<"English Marks   : "<<marks[3]<<endl;
								cout<<"PF Marks        : "<<marks[4]<<endl;
	
								i++;
									getline(CMR,rollno);
							getline(CMR,name);
							getline(CMR,marks[0]);
	    					getline(CMR,marks[1]);
							getline(CMR,marks[2]);
							getline(CMR,marks[3]);
							getline(CMR,marks[4]);
							}
					CMR.close();
				
				}
//Professor 3rd operation Search spcific student marks
				void Search_SMR()
				{
					   	string line;
  						string search;
  						int nrf=0; //not record find
   						cout << "Enter Student Roll no: ";
   						cin >> search;
   
    					ifstream  SMR;
						SMR.open("studentMarks.text");
					string rollno,marks[5],name;
    					int l=1,i=1;
    				if(SMR.is_open())
     					{
       						 while(!SMR.eof())
       							{                   
        							getline (SMR,line);
        	  						l++;
          							if(l%7==0)
          							i++;  
       	 							if(search == line )
         								{
         									nrf++;
							 				cout<<endl<<endl;
											rollno=line;
											getline(SMR,name);
											getline(SMR,marks[0]);
	  										getline(SMR,marks[1]);
											getline(SMR,marks[2]);
											getline(SMR,marks[3]);
											getline(SMR,marks[4]);
											
        									cout<<"\tSTUDENT no# "<<i<<endl<<endl;
											cout<<"Roll no         : "<<rollno<<endl;
											cout<<"Student Name    : "<<name<<endl;
											cout<<"Physics Marks   : "<<marks[0]<<endl;
											cout<<"Calculus Marks  : "<<marks[1]<<endl;
											cout<<"ITC Marks       : "<<marks[2]<<endl;
											cout<<"English Marks   : "<<marks[3]<<endl;
											cout<<"PF Marks        : "<<marks[4]<<endl;					
         								}
        						}
        				SMR.close();
        				if(nrf==0)
       					 cout<<" Sorry Record not Exist ";
    
     					}
     				else
         			cout << "File error\n";				
				}
//professor 4th operation update students marks
				void update_SMR()
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
   								string rollno,marks[5],name;
									 
											getline(ofile,rollno);   					
											getline(ofile,name);
											getline(ofile,marks[0]);
	  										getline(ofile,marks[1]);
											getline(ofile,marks[2]);
											getline(ofile,marks[3]);
											getline(ofile,marks[4]);
							while (!ofile.eof())
								{
								
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
										
											getline(ofile,rollno);   					
											getline(ofile,name);
											getline(ofile,marks[0]);
	  										getline(ofile,marks[1]);
											getline(ofile,marks[2]);
											getline(ofile,marks[3]);
											getline(ofile,marks[4]);
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
//professor 5th operation remove record
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
   							string rollno,marks[5],name;

											getline(ofile,rollno);   					
											getline(ofile,name);
											getline(ofile,marks[0]);
	  										getline(ofile,marks[1]);
											getline(ofile,marks[2]);
											getline(ofile,marks[3]);
											getline(ofile,marks[4]);
							while (!ofile.eof())
								{
									
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
										
										getline(ofile,rollno);   					
											getline(ofile,name);
											getline(ofile,marks[0]);
	  										getline(ofile,marks[1]);
											getline(ofile,marks[2]);
											getline(ofile,marks[3]);
											getline(ofile,marks[4]);
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


void student(void);	
int main()
{
	int choice; 
    logout:
    	system("cls");
	cout<<"\t\t===========================================\n";
	cout<<"\t\t        University Managment System\n";
	cout<<"\t\t===========================================";
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t             Superior Gold Campus ";
	cout<<endl<<endl;
	cout<<"\t *********************************************"<<endl;
	cout<<"\t *                                           *"<<endl;
	cout<<"\t *               Group Details               *"<<endl;
	cout<<"\t *                                           *"<<endl;
	cout<<"\t *********************************************"<<endl;
	cout<<"\t *                    *                      *"<<endl;
	cout<<"\t *      Name          *      Roll NO.        *"<<endl;
	cout<<"\t *                    *                      *"<<endl;
	cout<<"\t *********************************************"<<endl;
	cout<<"\t * Sabir Hussain      * BCSM-F19-262         *"<<endl;
	cout<<"\t * Shaheer Ahmad      * BCSM-F19-118         *"<<endl;
	cout<<"\t * Hussnain  Imran    * BCSM-F19-252         *"<<endl;
	cout<<"\t * M. Mather Tahir    * BCSM-F19-231         *"<<endl;
	cout<<"\t *********************************************"<<endl;
	cout<<endl<<endl;
	cout<<"Login Frist with any status(1-3)"<<endl;
	cout<<" 1- Admin"<<endl;
	cout<<" 2- Professor"<<endl;
	cout<<" 3- Student"<<endl;
	cout<<" 4- Exit"<<endl;
	start:
		
	// login status & password
	cout<<endl<<"Login Status  : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			admin();
			goto logout;
			break;
		case 2:
			Porfessor();
			goto logout;
			break;
		case 3:
			student();
			goto logout;
			break;
		case 4:
			break;
		default:
			{
				cout<<"Worng Choice Enter Again \n";
				goto start;	
			}					
	}
	
	cout<<endl;
	system("pause");
	return 0;
}
//Admin Block

void admin(void)
{
	again_p:
		string p="admin";
	string static admin_p=p,password;
	
	cout<<"Enter Password: ";
	cin>>password;
	if(password==admin_p)
	{
	 	cls:
		system("cls");
		
		cout<<"\t=================================\n";
		cout<<"\t\tWellcom Admin \n";
		cout<<"\t=================================";
		Main_menu:
		cout<<endl<<endl;
	
		cout<<" \tMain Menu"<<endl;
		cout<<" 1- Create New Student Record"<<endl;
		cout<<" 2- Display All Students Record"<<endl;
		cout<<" 3- Search Record"<<endl;
		cout<<" 4- Modify Student Record"<<endl;
		cout<<" 5- Delete Student Record"<<endl;
		cout<<" 6- Change Password"<<endl;
		cout<<" 7- Clear Output Screen"<<endl;
		cout<<" 8- Logout your Account"<<endl;
		int choice;
		cout<<endl<<"Enter Your Choice: ";
		cin>>choice;
		if(choice==1)
			{
				//student_R();
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             New Student Record\n";
				cout<<"\t\t============================================\n";
				int record;
				cout<<endl;
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
					cout<<endl<<endl;
					goto Main_menu;
			}	
		else if(choice==2)
			{
				//display all student record
				Display_ASR();

				goto Main_menu;
			
			
			}
		else if(choice==3)
			{
				//search_R();
				int record;
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Search Student Record\n";
				cout<<"\t\t============================================\n";
				cout<<endl;
				cout<<"How many Record you Want to Search : ";
				cin>>record;
				cout<<endl;
				for(int i=1;i<=record;i++)
					{
						cout<<endl;
						cout<<endl;
						Search_R();
		
					}
					cout<<endl<<endl;
					goto Main_menu;
			}
		else if(choice==4)
			{
				//Modify_SR();
				cout<<endl<<endl;
				cout<<"\t\t======================================================\n";
				cout<<"\t\t             Modify/Update Student Record\n";
				cout<<"\t\t======================================================\n";
				cout<<endl;
				update_record();
				goto Main_menu;
		
			}
		else if(choice==5)
			{
				//Delete_SR();
				cout<<endl<<endl;
				cout<<"\t\t======================================================\n";
				cout<<"\t\t             Delete Student Record\n";
				cout<<"\t\t======================================================\n";
				cout<<endl;
				remove_record();
				goto Main_menu;
				
	
			}
		else if(choice==6)
			{
				//chang_passord;
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Change Admin Password\n";
				cout<<"\t\t============================================\n";
				cout<<endl;
					cout<<"Enter Previous Password  : ";
					cin>>password;
					if(password==admin_p)
							{
								cout<<"Enter new Password       : ";
								cin>>password;
								admin_p=password;
								cout<<"\n\tPassword Successfully Change"<<endl<<endl;
								cout<<endl<<"Enter New Password for Login"<<endl;
								goto again_p;
							}
					else
						{
							cout<<"Worng Password";
							goto Main_menu;
						}
			}
			
		else if(choice==7)
			{
				//Clear Output Screen
				goto cls;
			}
			
			else if(choice==8)
			{
				//program exit
				
				goto Exit;
			}
	}
	else
		{
			cout<<"worng Password enter right one\n"<<endl;
			goto again_p;
		
		}
	Exit:
		cout<<" ";
	}
	
	//Professor Block

void Porfessor(void)
{
	again_p:
		string p="pro123";
	string static pro_p=p,password;
	
	cout<<"Enter Password: ";
	cin>>password;
	if(password==pro_p)
	{
	 	cls:
		system("cls");
		cout<<"\t=================================\n";
		cout<<"\t\tWellcom PROFESSOR \n";
		cout<<"\t=================================";
		Main_menu:
		cout<<endl<<endl;
		cout<<" \tMain Menu"<<endl;
		cout<<" 1- Enter Student Marks"<<endl;
		cout<<" 2- Check All Class Result"<<endl;
		cout<<" 3- Search Student Record"<<endl;
		cout<<" 4- Modify Student Marks Record"<<endl;
		cout<<" 5- Delete Student Record"<<endl;
		cout<<" 6- Change Password"<<endl;
		cout<<" 7- Clear Output Screen"<<endl;
		cout<<" 8- Logout your Account"<<endl;
		int choice;
		cout<<endl<<"Enter Your Choice: ";
		cin>>choice;
		if(choice==1)
			{
				//student_M();
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Student Marks Record\n";
				cout<<"\t\t============================================\n";
				int record;
				cout<<endl;
				cout<<"How many Record you Want to Enter: ";
				cin>>record;
				cout<<endl;
				for(int i=1;i<=record;i++)
					{
						cout<<endl;
						cout<<"*****************************************";
						cout<<endl;
						cout<<"\t Enter "<<i<<" Student Record \n\n";
						student_M();
		
					}
					cout<<endl<<endl;
					goto Main_menu;				
				
			}	
		else if(choice==2)
			{
				//Class_R();
				Class_R();
				goto Main_menu;
			}
		else if(choice==3)
			{
				//search_SR();
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Search Student Marks Record\n";
				cout<<"\t\t============================================\n";
				cout<<endl;
				Search_SMR();
				goto Main_menu;
			}
			else if(choice==4)
			{
				//Modity_SMR();
				cout<<endl<<endl;
				cout<<"\t\t==========================================================\n";
				cout<<"\t\t             Modify/Update Student Marks Record\n";
				cout<<"\t\t==========================================================\n";
				cout<<endl;
				update_SMR();
				goto Main_menu;
			}
		else if(choice==5)
			{
				//Delete_SR();
				cout<<endl<<endl;
				cout<<"\t\t======================================================\n";
				cout<<"\t\t             Delete Student Record\n";
				cout<<"\t\t======================================================\n";
				cout<<endl;
				remove_SMR();
				goto Main_menu;
			}
		else if(choice==6)
			{
				//chang_passord;
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Change Professor Password\n";
				cout<<"\t\t============================================\n";
				cout<<endl;
					cout<<"Enter Previous Password  : ";
					cin>>password;
					if(password==pro_p)
							{
								cout<<"Enter new Password       : ";
								cin>>password;
								pro_p=password;
								cout<<"\n\tPassword Successfully Change"<<endl<<endl;
								cout<<endl<<"Enter New Password for Login"<<endl;
								goto again_p;
							}
					else
						{
							cout<<"Worng Password";
							goto Main_menu;
						}
			}
			
		else if(choice==7)
			{
				//Clear Output Screen
				goto cls;
			}
		else if(choice==8)
			{
				//program exit
				goto Exit;
			}
	}
	else
		{
			cout<<"worng Password enter right one\n"<<endl;
			goto again_p;
		
		}
	Exit:
		cout<<" ";
	}
	
// Grade function 
	string grade(int no)
	{
		string g;
		if(no>=90)
		g="A";
		else if(no<90&&no>=85)
		g="A-";
		else if(no<85&&no>=80)
		g="B+";
		else if(no<80&&no>=75)
		g="B";
		else if(no<75&&no>=70)
		g="B-";
		else if(no<70&&no>=65)
		g="C+";
		else if(no<65&&no>=60)
		g="C";
		else if(no<60&&no>=55)
		g="C-";
		else if(no<55&&no>=50)
		g="D";
		else if(no<50)
		g="Fail";
		return g;
		
	}
	
//Student Block

void student(void)
{
		cout<<"\t=================================\n";
		cout<<"\t\tWellcom Student \n";
		cout<<"\t=================================";
	again_p:
		string p="stu123";
	string static std_p=p,password;
	cout<<endl;
	cout<<"Student ID    : BCSM-F19-262 "<<endl;
	cout<<"Enter Password: ";
	cin>>password;
	if(password==std_p)
	{
	 	cls:
		system("cls");
		cout<<"\t=================================\n";
		cout<<"\t\tWellcom Sabir Hussain \n";
		cout<<"\t=================================";
		Main_menu:
		cout<<endl<<endl;
		cout<<" \tMain Menu"<<endl;
		cout<<" 1- check Admission Details"<<endl;
		cout<<" 2- Check  Marks Details"<<endl;
		cout<<" 3- Change Password"<<endl;
		cout<<" 4- Clear Output Screen"<<endl;
		cout<<" 5- Logout your Account"<<endl;
		int choice;
		cout<<endl<<"Enter Your Choice: ";
		cin>>choice;
		if(choice==1)
			{
				//addmission details;
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t            Your Admission Details\n";
				cout<<"\t\t============================================\n";
					cout<<endl<<endl;
					   	string line,search="3520267352091";
  						int nrf=0; //not record find   
    					ifstream ssr ("studentRecord.text");
    					string name,cell,addr,reg,roll;
    					int l=1,i=1;
    				if(ssr.is_open())
     					{
       						 while(!ssr.eof())
       							{                   
        							getline (ssr,line);
        	  						l++;
          							if(l%5==0)
          							i++;  
       	 							if(search == line )
         								{
         									nrf++;
							 				cout<<endl<<endl;
											reg=line;
											getline(ssr,name);
											getline(ssr,roll);
	  										getline(ssr,cell);
											getline(ssr,addr);
        									cout<<"\tSTUDENT no# "<<i<<endl<<endl;
											cout<<"\tStudent ID   : "<<reg<<endl;
											cout<<"\tStudent Name : "<<name<<endl;
											cout<<"\tRoll no      : "<<roll<<endl;
											cout<<"\tcell no      : "<<cell<<endl;
											cout<<"\tAddress      : "<<addr<<endl;					
         								}
        						}
        				ssr.close();
        				if(nrf==0)
       					 cout<<" Sorry Record not Exist ";
    
     					}
     				else
         			cout << "File error\n";
					 goto Main_menu;					
				}
					
								
					
		else if(choice==2)
			{
				//student marks details
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Marks Details\n";
				cout<<"\t\t============================================\n";
				cout<<endl;
									void Search_SMR();
				{
					   	string line;
  						int nrf=0; //not record find   
    					ifstream  SMR;
						SMR.open("studentMarks.text");
					string rollno,name;
					int marks[5];
					int sum=0;
    				if(SMR.is_open())
    	
     					{
       						 while(!SMR.eof())
       							{                   
        							getline (SMR,line); 
       	 							if( line == "262")
         								{
         									nrf++;
							 				cout<<endl<<endl;
											rollno=line;
											getline(SMR,name);
											cin.ignore();
											for(int i=0;i<=4;i++)
											{
												SMR>>marks[i];
												sum+=marks[i];
											}
											
											
        												cout<<endl;
											cout<<"\t Roll no         | "<<rollno<<endl;
											cout<<"\t Student Name    | "<<name<<endl;
											cout<<"\t==========================================================\n\n";
											cout<<"\t    Subject       |   Marks   |    Percentage % |  Grade  "<<endl<<endl;
											cout<<"\t==========================================================\n";

											cout<<"\t Applied Physics  |     "<<marks[0]<<"    |       "<<marks[0]<<"%       |   "<<grade(marks[0])<<endl;
		
											cout<<"\t Calculus Math    |     "<<marks[1]<<"    |       "<<marks[1]<<"%       |   "<<grade(marks[1])<<endl;
											cout<<"\t ITC              |     "<<marks[2]<<"    |       "<<marks[2]<<"%       |   "<<grade(marks[2])<<endl;
											cout<<"\t English          |     "<<marks[3]<<"    |       "<<marks[3]<<"%       |   "<<grade(marks[3])<<endl;
											cout<<"\t Programmin Funda.|     "<<marks[4]<<"    |       "<<marks[4]<<"%       |   "<<grade(marks[4])<<endl;	
											cout<<"\t==========================================================\n";
											cout<<"\t          Total   |     "<<sum<<"   | Percentage ="<< (sum/5)<<"% | Grade = "<<grade(sum/5)<<endl;	
											cout<<"\t==========================================================\n";			
         								}
        						}
        				SMR.close();
        				if(nrf==0)
       					 cout<<" Sorry Record not Exist ";
    
     					}
     				else
         			cout << "File error\n";				
				}
			
				goto Main_menu;
			}
		else if(choice==3)
			{
				//chang_passord;
				cout<<endl<<endl;
				cout<<"\t\t============================================\n";
				cout<<"\t\t             Change Student Password\n";
				cout<<"\t\t============================================\n";
				cout<<endl;
					cout<<"Enter Previous Password  : ";
					cin>>password;
					if(password==std_p)
							{
								cout<<"Enter new Password       : ";
								cin>>password;
								std_p=password;
								cout<<"\n\tPassword Successfully Change"<<endl<<endl;
								cout<<endl<<"Enter New Password for Login"<<endl;
								goto again_p;
							}
					else
						{
							cout<<"Worng Password";
							goto Main_menu;
						}
			}
			
		else if(choice==4)
			{
				//Clear Output Screen
			
				goto cls;
			}
		else if(choice==5)
			{
				//program exit
				goto Exit;
			}
	}
	else
		{
			cout<<"worng Password enter right one\n"<<endl;
			goto again_p;
		
		}
	Exit:
		cout<<" ";
	}
