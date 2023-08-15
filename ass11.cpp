#include<iostream>
#include<fstream>
#include<string>

class student{
	public:
		char name[10];
		char address[10];
		char division;
		int rno;
		int acceptRollno()
		{
			return(rno);
		}
		void acceptdetails()
		{
			cout<<"Enter the name: ";
			cin>>name;
			cout<<"Enter the rollno : ";
			cin>>rno;
			cout<<"Enter the division";
			cin>>division;
			cout<<"Enter the address: ";
			cin>>address;
		}
		void putData()
		{
			cout<<"\nName is : "<<name;
			cout<<"\nRoll no is: "<<rno;
			cout<<"\nDivision is: "<<division;
			cout<<"\nAddress is: "<<address;
		}
};
class operations{
	public:
	ifstream fin;
	ofstream fout;
	fstream fs;
	void add_record();
	void show();
	void delete(int );
	void search(int );
	void update(int );
};
void operations::add_record()
{
	student r;
	r.acceptdetails();
	fout.open("Data.txt",ios::ate |ios::app);
	fout.write((char*)&r,sizeof(r));
	fout.close();
}
void operations::show()
{
	fin.open
}
