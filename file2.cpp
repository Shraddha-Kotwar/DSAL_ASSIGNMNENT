#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
	public:
		int rno;
		char name[20];
		char division;
		char address[30];
		int acceptRollno()
		{
			return(rno);
		}
		void acceptdetails()
		{
			cout<<"\nEnter the roll no: ";
			cin>>rno;
			cout<<"\nEnter the name: ";
			cin>>name;
			cout<<"\nEnter the division: ";
			cin>>division;
			cout<<"\nEnter the address: ";
			cin>>address;
		}
		void putData()
		{
			cout<<"Roll no is "<<rno;
			cout<<"\nName is "<<name;
			cout<<"\nDivision is "<<division;
			cout<<"\n Address is "<<address;
		}
};
class operations
{
	ifstream fin;
	ofstream fout;
	fstream fs;
	public:
		void add_record();
		void show();
		void search(int );
		int DelRecord(int );
		void edit(int );
};
void  operations::add_record()
{
	student r;
	r.acceptdetails();
	fout.open("Data.txt",ios::ate|ios::app);
	fout.write((char*)&r,sizeof(r));
	fout.close();
}
void operations::show()
{
	student r;
	fin.open("Data.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&r,sizeof(r)))
	{
		r.putData();
	}
	fin.close();
}
void operations::search(int rno)
{
	student r;
	int flag=0;
	fin.open("Data.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&r,sizeof(r)))
	{
		if(r.acceptRollno()==rno)
		{
			flag=1;
			break;
		}
	}
	fin.close();
	if(flag==1)
	{
		cout<<"Record Found";
		r.putData();
	}else{
		cout<<"Record does not exist";
	}
}
int operations::DelRecord(int rno)
{
	student r;
	int flag=0;
	fin.open("Data.txt");
	fout.open("Temp.txt",ios::ate|ios::app);
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&r,sizeof(r)))
	{
		if(r.acceptRollno()==rno)
		{
			flag=1;
			break;
		}else{
			fout.write((char*)&r,sizeof(r));
		}
	}
	fin.close();
	fout.close();
	remove("Data.txt");
	rename("Temp.txt","Data.txt");
	return(flag);
}
void operations::edit(int rno)
{
	student r;
	int flag=0;
	fs.open("Data.txt");
	fs.seekg(0,ios::beg);
	while(fs.read((char*)&r,sizeof(r)))
	{
		if(r.acceptRollno()==rno)
		{
			flag=1;
			cout<<"Enter new Details ";
			r.acceptdetails();
			fs.seekp((int)fs.tellg()-sizeof(r),ios::beg);
			fs.write((char*)&r,sizeof(r));
		}
	}
	fs.close();
	if(flag==1)
	{
		cout<<"\n Records Updated ";
	}
	else{
		cout<<"\nRecords does not exist ";
	}
}

int main()
{
	operations f;
	student r;
	int ch,i,n;
	int flag=0;
	do{
		cout<<"n---------Menu----------";
		cout<<"\n1.Build a record table";
		cout<<"\n2.Display the record";
		cout<<"\n3.Insert a new record ";
		cout<<"\n4.Delete  a new record ";
		cout<<"\n5.Search for record ";
		cout<<"\n6.Update";
		cout<<"\n7.Quit";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(flag==0)
				{
					cout<<"\nEnter the no of records";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						f.add_record();
					}
					flag=1;
				}
				break;
			case 2:
				f.show();
				break;
			case 3:
				f.add_record();
				break;
			case 4:
				cout<<"Enter the roll no to be deleted ";
				cin>>n;
				i=f.DelRecord(n);
				if(i==1)
				{
					cout<<"Record Deleted ";
				}
				else{
					cout<<"Record not found ";
				}
				break;
			case 5:
				cout<<"\nEnter the Record to be search ";
				cin>>n;
				f.search(n);
				break;
				
			case 6:
				cout<<"Enter record to be updated ";
				cin>>n;
				f.edit(n);
				break;
			case 7:
				break;
				
			default:cout<<"Invalid Choice ";
		}
	}while(ch!=7);
}
