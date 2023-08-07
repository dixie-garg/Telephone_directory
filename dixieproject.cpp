
#include <iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

using namespace std;


class directory
{
	int id ;
	string username,mobile_no;
	
	public:
void admin()
 	{ 
 	string name,password=" ";
	 char pass=' ';
 		cout<<"\n username: \t";
 		cin>>name;
 		cout<<"\n password: \t";
 		while(pass!=13)//ASCII value of enter key is 13 
		 {
 		 pass=getch();
 		 if(pass!=13)
 		 {
 		 	password+=pass;
 		 	cout<<"*";
		  }
 	}  
 	    if(name=="ADMIN" || password=="ADMIN123" )
 	    {
		
		system("cls");
 	    	cout<<"\n yeh logged in successfully";
 	    	manager();
		 }
		 else
		 {
		 	cout<<" \n invalid username or password \n";
		
		 }
	 }
	 
	 void EXIT()
	 {
	 	system("cls");
	 	cout<<"\n\n\n\n\n\t\t \t\t thankyou for using !";
	 	exit(0);
	 }
	 
	 void custom()
	 {
	 	int ch;
	 	system("cls");
	 		cout<<"\n 1.\t search \n 2.\t back \n 3.\t Exit";
	cout<<"\n enter your choice (1-3)";
	cin>>ch;
	switch(ch)
	{
	case 1:
	search();
		break;
	case 2:
	back();
 		break;
		
	case 3:
	EXIT();
		break;
	default:
		cout<<"enter valid input";
 	}
	 	
	 }
void back()
	{
	int choice;
	 	system("cls");
	cout<<"\t\t\t\t\tTELEPHONE DIRECTORY\t\t\t\t\t ";
	cout<<"\n 1.\t Admin \n 2.\t Customer \n 3.\t Exit";
	cout<<"\n enter your choice (1-3)";
	cin>>choice;
	switch(choice)
	{
	case 1:
	admin();
		break;
	case 2:
	 	custom();
		break;
	case 3:
		EXIT();
		break;
	default:
		cout<<"enter valid input";
 	}
 	}
    void manager()
    {
    	int c;
    		//system("cls");
	cout<<"\n 1.\t Add User \n 2.\t Delete User \n 3.\t view all users \n 4.\t back \n 5.\t Exit";
	cout<<"\n enter your choice (1-4)";
	cin>>c;
	
		switch(c)
	{
	case 1:
	 add();
		break;
	case 2:
	 	del();
		break;
	case 3:
		view_all();
	break;

	case 4:
		back();
		break;
	case 5:
		EXIT();
		break;
	default:
		cout<<"enter valid input";
 	break;
 }
}
		
void add()
{
	int i;
	cout<<"please enter your credentials:";
	cout<<"\n ID: \t";
	cin>>id;
	cout<<"\n NAME: \t";
	cin>>username;
	cout<<"\n PHONE NO.: \t";
	cin>>mobile_no;
	ofstream phone("record.txt",ios::app);
	if(check_digit(mobile_no)==true)
	{
		if(check_num(mobile_no)==true)
		{
		
	if(phone.is_open())
	{
		phone<<id<<"\t\t"<<username<<"\t\t"<<mobile_no<<endl;
		cout<<"contact saved";
	}

	else
	{
		cout<<"error in opening file.";
	}
}
	else
	cout<<"mobile no. should contain digits only";

}
else
{
cout<<"mobile no. must contain 10 digits";
}

phone.close();
}

bool check_digit(string x)
{
	if(x.length()==10)
	{
		return true;
	}
else
return false;
}
bool check_num(string x)
{
	int i;
	bool check=true;
	for(i=0;i<x.length();i++)
	{
		if(!(int(x[i])>=48 && int(x[i])<=57))
		
		{
		check=false;
		break;
    	}
	}
if(check==true)
return true;
if(check==false)
return false;	
}
 
void search()
{
	int choose;
	cout<<"press 1 to search by phone no. or press 2 to search by ID or press 3 to search by name  ";
	cin>>choose;
		switch(choose)
	{
	case 1:
	search_by_phone();
		break;
	case 2:
	 search_by_id();
		break;
	case 3:
	  search_by_name();
	  break;
	default:
		cout<<"enter valid input";
 	}
}
	search_by_phone()
	{ 
		bool a=false;
		ifstream isha("record.txt");
		string num;
		cout<<"enter your phone no.";
		cin>>num;
		
		while(isha>>id>>username>>mobile_no)
		{
		 	if( num==mobile_no)	
		 	{
		 		cout<<"\n \t\t\tID:\t"<<id<<"\n \t\t\t NAME:\t"<<username<<"\n \t\t\t MOBILE NO.:"<<mobile_no;
		 		a=true;
		 		break;
			}
		}
		 if(a==false)
			 cout<<"user dosen't exists with this number";
	 isha.close();
	}
	search_by_id()
	{ 
		bool a=false;
		ifstream isha("record.txt");
		int num;
		cout<<"enter your ID.";
		cin>>num;
		
		while(isha>>id>>username>>mobile_no)
		{
		 	if( num==id)	
		 	{
		 		system("cls");
		 		cout<<"\n \t\t\tID:\t"<<id<<"\n \t\t\t NAME:\t"<<username<<"\n \t\t\t MOBILE NO.:"<<mobile_no;
		 		a=true;
		 		break;
			 }
		}
			 if(a==false)
			 cout<<"user dosen't exists with this id";
		
	isha.close();
	}
		search_by_name()
	{ 
		bool a=false;
		ifstream isha("record.txt");
		string num;
		cout<<"enter your name";
		cin>>num;
		
		while(isha>>id>>username>>mobile_no)
		{
		 	if( num==username)	
		 	{
		 		cout<<"\n \t\t\tID:\t"<<id<<"\n \t\t\t NAME:\t"<<username<<"\n \t\t\t MOBILE NO.:"<<mobile_no;
		 		a=true;
		 		break;
			 }
		}
			  if(a==false)
			
			 cout<<"user dosen't exists with this name";
		
	isha.close();
	}

void del()
{
	int a,ch;
	cout<<"are you sure to delete the user.....\n\n press 1 to delete and 0 to exit";
	cin>>a;
	if(a==1)
	{	cout<<"press 1 to delete the user by id"<<endl<<"press 2 to delete the user by mobile no."<<endl<<"press 3 to delete the user by name.";
		cin>>ch;
			switch(ch)
	{
	case 1:
    	del_by_id();
		break;
	case 2:
	 	del_by_mob();
		break;
	case 3:
		del_by_name();
	default:
	cout<<"enter valid input";
	}
}
}
del_by_id()
{
	int ide,flag=0;
 cout<<"please tell your id";
 cin>>ide;
 	ifstream data("record.txt");
		ofstream n("temp.txt");
		while(data>>id>>username>>mobile_no)
		{		
 if(ide!=id)
 {
 	n<<endl;
 	n<<id<<"\t";
	n<<username<<"\t";
	n<<mobile_no;
 }

 else
 flag++;
}
 if(flag==0)
 {
 	cout<<"record not found";
 }
 else
 cout<<"user deleted successfully";

n.close();
data.close();
  remove("record.txt");
  rename("temp.txt", "record.txt");
}
del_by_mob()
{ 
string m;
int flag=0;
	 cout<<"please tell your mobile no.";
	 
 cin>>m	;
 	ifstream r("record.txt");
		ofstream t("temp.txt");
		while(r>>id>>username>>mobile_no)
		{		
 if(mobile_no!=m)
 {
 	t<<endl;
 	t<<id<<"\t";
	t<<username<<"\t";
	t<<mobile_no;
 }
 else
 flag++;
}
 if(flag==0)
 {
 	cout<<"record not found";
 }
 else
 cout<<"user deleted successfully";

t.close();
r.close();
  remove("record.txt");
  rename("temp.txt", "record.txt");	
}

del_by_name()
{
	int flag=0;
	string name;
 cout<<"please tell your name";
 cin>>name;
 	ifstream data("record.txt");
		ofstream n("temp.txt");
		while(data>>id>>username>>mobile_no)
		{		
 if(name!=username)
 {
 	n<<endl;
 	n<<id<<"\t";
	n<<username<<"\t";
	n<<mobile_no;
 }
 else
 flag++;
}
 if(flag==0)
 {
 	cout<<"record not found";
 }
 else if(flag>=1)
 cout<<"user deleted successfully";

n.close();
data.close();
  remove("record.txt");
  rename("temp.txt", "record.txt");
}

void view_all()
{
		system("cls");
		cout<<"\t\t\t SHOWING ALL DETAILS\t\t\t\n";
	string str;
	fstream data("record.txt",ios::in);
	while(getline(data,str))
	{
		
	cout<<str<<endl;
 }	
 data.close();
}
};

int main(int argc, char** argv) 
{
	directory d;
		int choice;


	cout<<"\t\t\t\t\tTELEPHONE DIRECTORY\t\t\t\t\t ";
	cout<<"\n 1.\t Admin \n 2.\t Customer \n 3.\t Exit";
	cout<<"\n enter your choice (1-3)";
	cin>>choice;
	switch(choice)
	{
	case 1:
	d.admin();
		break;
	case 2:
	d.custom();
		break;
	case 3:
		d.EXIT();
		break;
	default:
		cout<<"enter valid input";
 	}
}

