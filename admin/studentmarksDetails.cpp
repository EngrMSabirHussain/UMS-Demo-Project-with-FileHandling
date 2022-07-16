#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
		   string line;
  						string search="262";
  						int nrf=0; //not record find  
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
					
