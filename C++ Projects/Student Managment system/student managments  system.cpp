#include<iostream>
#include<string>
using namespace std;
struct student{
	string stname;
	string strollno;
	string stclass;
};
void add_student(student students[],int student_count,int max_students){
	if(student_count < max_students){
	
	
	cout<<"Enter Student's name :";
	cin>>students[student_count].stname;
	cout<<"Enter Student Roll no :";
	cin>>students[student_count].strollno;
	cout<<"Enter Student class :";
	cin>>students[student_count].stclass;
	
	student_count++;
	cout<<"Student added successfully"<<endl;
}
else
{
	cout<<"Student list is full. Cannot add more students."<<endl;
}

}
void display_student(student students[],int student_count)
{
	if(student_count ==0)
	{
		cout<<"No student to display....."<<endl;
		
	}
	else
	{
		cout<<"----STUDENT DETAILS-----"<<endl;
		for(int i=0;i<student_count;i++)
		{
			cout<<"Student No "<<i+1<<":"<<endl;
			cout<<"Student Name :"<<students[i].stname <<endl;
			cout<<"Student Roll No :"<<students[i].strollno<<endl;
			cout<<"Student Class :"<<students[i].stclass<<endl;
			cout<<"--------------------------------";
		}
	}
}
void showmenu(student students[],int student_count,int max_students)
{
	int choice;
	while(true)
	{
		cout<<"-----Student Managment System------"<<endl;
		cout<<"1. Add student "<<endl;
		cout<<"2. display student "<<endl;
		cout<<"3. Exit "<<endl;
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				add_student(students,student_count ,max_students);
				break;
			case 2:
			display_student(students,student_count);
			break;
			case 3:	
			cout<<"Exiting program";
			return;
			default:
				cout<<"Invalid choice... Please try again."<<endl;
		}
	}
}
int main()
{
	int max_students = 5;
	student students[max_students];
	int student_count=0;
	showmenu(students,student_count,max_students);
	
}
