#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <math.h> 
#include <fstream>
using namespace std;
void gotoxy (int x, int y){
	static HANDLE h=NULL;
	if (!h){
		h=GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c={x,y};
	SetConsoleCursorPosition(h,c);
}
class Node{
	public:
	friend class Courses;
	friend class Student;
	int StudentNumber;
	char Studentfname[20];
	char Studentlname[30];
	char StudentMajor[20];
	Node *next;
};
class NodeCourse{
	public:
	friend class Courses;
	friend class Student;
	int CourseCode;
	int CourseUnit;
	string CourseName;
	char coursetype;
	int TCourseCode;
	int TCourseUnit;
	string TCourseName;
	int PCourseCode;
	int PCourseUnit;
	string PCourseName;
	string coursedescribe;
	NodeCourse *next;
};

class link{
	friend class Courses;
	friend class Student;
	public:
	int StCourseCode;
	int StudentNumber;
	float Studentscores;
	link *next;
};
class Student{
	Node *first;
	Node *last;
	link*head;
	link *tail;
	NodeCourse *firstcourse;
	NodeCourse *lastcourse;
	
	public:
	Student(){
		first=last=NULL;
		head=tail=NULL;
		firstcourse=lastcourse=NULL;
	}
	~Student(){
		Node *curSt=first;
		Node *temp;
		while(curSt){
			temp=curSt;
			curSt=curSt->next;
			delete temp;
		}
		link *curSt2=head;
		link *temp2;
		while(curSt2){
			temp2=curSt2;
			curSt2=curSt2->next;
			delete temp2;
		}
		NodeCourse *curcourse=firstcourse;
		NodeCourse *tempcourse;
		while(curcourse){
			tempcourse=curcourse;
			curcourse=curcourse->next;
			delete tempcourse;
		}
	}
	void InputStudent();
	void InputCourse();
	void InpuStCourse();
	void Inputscore();
	void AddStudent();
	void DeleteStudent();
	void SeekStudent();
	void SetCourse(int stno);
	void RegistareCourse();
	void DeleteStudentCourse();
	void SetScore();
	void Print();
	void StudentAndScores();
	void StudentAndCourses();
};
class Courses{
	public:
	char type;
	char result;
	char coursetype;
	NodeCourse *first;
	NodeCourse *last;
	Courses(){
		first=last=NULL;
	}
	~Courses(){
		NodeCourse *curCour=first;
		NodeCourse *temp;
		while(curCour){
			temp=curCour;
			curCour=curCour->next;
			delete temp;
		}
	}
	void InputCourse();
	void Inputdes();
	void AddCourses();
	void DeleteCourse();
	void SeekCourse();
	void Print();
	void descriptioncourse();
};
class Menu{
	public:
	void FirstMenu();
	void StudentsMenu();
	void CourseMenu();
	void RegistrationMenu();
	void ReportMenu();
	void Exit();
	void Choice();
};
int main(){
	while(true){
		Menu menu;
		menu.FirstMenu();
		Student student;
		student.InputStudent();
		student.InputCourse();
		student.InpuStCourse();
		student.Inputscore();
		Courses courses;
		courses.InputCourse();
		courses.Inputdes();
		int input;
		menu.Choice();
		cin >> input;
		while(input==1){
			int key;
			system("cls");
			menu.StudentsMenu();
			menu.Choice();
			cin >> key;
			system("cls");
			if(key==1){
				student.AddStudent();
			}
			else if(key==2){
				student.DeleteStudent();
			}
			else if(key==3){
				while(true){
					student.SeekStudent();
					cout<<"\n\npress ""b"" to back previous menu or press others to search again"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==4){
				break;
			}	
		}
		while(input==2){
			system("cls");
			menu.CourseMenu();
			menu.Choice();
			int key;
			cin >> key;
			system("cls");
			if(key==1){
				cout<< "Enter the type of the course (t for Theoretical and p for Practical course)"<<endl;
				cin >> courses.type;
				courses.AddCourses();	
			}
			else if(key==2){
				courses.descriptioncourse()	;
			}
			else if(key==3){
				while(true){
					courses.DeleteCourse();
					if(courses.result=='a'){
						cout<<"\n\nThe course was DELETED"<< endl;
					}
					cout<<"\n\npress ""b"" to back previous menu or other key to try again"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==4){
				while(true){
					cout<< "Enter the type of the course (t for Theoretical and p for Practical course)"<<endl;
					cin >> courses.type;
					courses.SeekCourse();
					cout<<"\n\npress ""b"" to back previous menu or press others to search again"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==5){
				break;
			}
		}
		while(input==3){
			system("cls");
			menu.RegistrationMenu();
			menu.Choice();
			int key;
			cin>> key;
			system("cls");
			if(key==1){
				student.RegistareCourse();
			}
			else if(key==2){
				student.SetScore();
			}
			else if(key==3){
				student.DeleteStudentCourse();
			}
			else if(key==4){
				break;
			}	
		}
		while(input==4){
			system("cls");
			menu.ReportMenu();
			menu.Choice();
			int key;
			cin >> key;
			system("cls");
			if(key==1){
				while(true){
					student.Print();
					cout<<"\n\npress ""b"" to back previous menu"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==2){
				while(true){
					courses.Print();
					cout<<"\n\npress ""b"" to back previous menu"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==3){
				while(true){
					student.StudentAndScores();
					cout<<"\n\npress ""b"" to back previous menu"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==4){
				while(true){
					student.StudentAndCourses();
					cout<<"\n\npress ""b"" to back previous menu"<<endl;
					char back;
					cin >> back;
					if(back=='b'){
						break;
					}
				}
			}
			else if(key==5){
				break;
			}
		}
		if(input==5){
			system("cls");
			menu.Exit();
			break;
		}
	}
	return 0;
}


void Menu::FirstMenu(){
		gotoxy(2,1);
		cout<<"********************** MENU *************************";
		gotoxy(2,2);
		cout<<"* 1) Students                                       *";
		gotoxy(2,3);
		cout<<"* 2) Courses                                        *";
		gotoxy(2,4);
		cout<<"* 3) Course Registration                            *";
		gotoxy(2,5);
		cout<<"* 4) Reports                                        *";
		gotoxy(2,6);
		cout<<"* 5) Exit                                           *";
		gotoxy(2,7);
		cout<<"*****************************************************";
	}
void Menu::StudentsMenu(){
		gotoxy(2,1);
		cout<<"********************* Students **********************";
		gotoxy(2,2);
		cout<<"* 1) Add a Student                                  *";
		gotoxy(2,3);
		cout<<"* 2) Remove a Student                               *";
		gotoxy(2,4);
		cout<<"* 3) Search a Student                               *";
		gotoxy(2,5);
		cout<<"* 4) Back                                           *";
		gotoxy(2,6);
		cout<<"*****************************************************";
	}
void Menu::CourseMenu(){
		gotoxy(2,1);
		cout<<"********************* Courses ***********************";
		gotoxy(2,2);
		cout<<"* 1) Add a course                                   *";
		gotoxy(2,3);
		cout<<"* 2) Add description of the course                  *";
		gotoxy(2,4);
		cout<<"* 3) Remove a course                                *";
		gotoxy(2,5);
		cout<<"* 4) Search a course                                *";
		gotoxy(2,6);
		cout<<"* 5) Back                                           *";
		gotoxy(2,7);
		cout<<"*****************************************************";
	}
void Menu::RegistrationMenu(){
		gotoxy(2,1);
		cout<<"******************* Registration ********************";
		gotoxy(2,2);
		cout<<"* 1) Registare a course                             *";
		gotoxy(2,3);
		cout<<"* 2) Registare a score                              *";
		gotoxy(2,4);
		cout<<"* 3) remove a course                                *";
		gotoxy(2,5);
		cout<<"* 4) Back                                           *";
		gotoxy(2,6);
		cout<<"*****************************************************";
	}
void Menu::ReportMenu(){
		gotoxy(2,1);
		cout<<"********************** Reports **********************";
		gotoxy(2,2);
		cout<<"* 1) Students list                                  *";
		gotoxy(2,3);
		cout<<"* 2) Courses list                                   *";
		gotoxy(2,4);
		cout<<"* 3) Registared students with their scores          *";
		gotoxy(2,5);
		cout<<"* 4) Registared students with their courses         *";
		gotoxy(2,6);
		cout<<"* 5) Back                                           *";
		gotoxy(2,7);
		cout<<"*****************************************************";
	}
void Menu::Exit(){
		gotoxy(2,2);
		cout<<"********************** Exit **********************";
	}
void Menu::Choice(){
		gotoxy(5,9);
		cout<<"Enter your choice : ";
	}
void Student::InputStudent(){
		fstream file("student.txt",ios::in | ios::out | ios::app);
		while(!file.eof()){
			Node *inputstudent=new Node;
			inputstudent->next=NULL;
			file>> inputstudent->StudentNumber >> inputstudent->Studentfname >> inputstudent->Studentlname >> inputstudent->StudentMajor;
			if(first==NULL){
				first=last=inputstudent;
			}
			else{
				last->next=inputstudent;
				last=inputstudent;
			}
		}
		file.close();
	}
void Student::InputCourse(){
		fstream file("course.txt",ios::in | ios::out | ios::app);
		char type;
		while(!file.eof()){
			NodeCourse *inputcourse=new NodeCourse;
			inputcourse->next=NULL;
			file >> type >> inputcourse->CourseCode >> inputcourse->CourseName >> inputcourse->CourseUnit;
			if(type=='t'){
				inputcourse->TCourseName=inputcourse->CourseName;
				inputcourse->TCourseCode=inputcourse->CourseCode;
				inputcourse->TCourseUnit=inputcourse->CourseUnit;
			}
			else if(type=='p'){
				inputcourse->PCourseName=inputcourse->CourseName;
				inputcourse->PCourseCode=inputcourse->CourseCode;
				inputcourse->PCourseUnit=inputcourse->CourseUnit;
			}
			if(firstcourse==NULL){
				firstcourse=lastcourse=inputcourse;
			}
			else{
				lastcourse->next=inputcourse;
				lastcourse=inputcourse;
			}
		}
		file.close();
	}
void Student::InpuStCourse(){
	fstream file("studentcourses.txt",ios::in | ios::out | ios::app);
	while(!file.eof()){
		link *inputstcourse=new link;
		inputstcourse->next=NULL;
		file >> inputstcourse->StudentNumber >> inputstcourse->StCourseCode;
		if(head==NULL){
			head=tail=inputstcourse;
		}
		else{
			tail->next=inputstcourse;
			tail=inputstcourse;
		}
	}
	file.close();
	}
void Student::Inputscore(){
	fstream file("student-score.txt",ios::in | ios::out | ios::app);
	link *infoscore=head;
	int StudentNumber;
	int StCourseCode;
	float Studentscores;
	while(!file.eof()){
		file >> StudentNumber >> StCourseCode >> Studentscores;
		while(infoscore!=NULL){
			if(StudentNumber==infoscore->StudentNumber && StCourseCode==infoscore->StCourseCode){
				infoscore->Studentscores=Studentscores;
				break;
			}
			else{
				infoscore=infoscore->next;
			}
		}	
	}
	file.close();
	}
void Student::AddStudent(){
		Node *newstudent=new Node;
		if(!newstudent){
			cout << "Allocation";
			getch();
		}
		newstudent->next=NULL;
		Node *exist=first;
		while(exist!=NULL){
			exist=first;
			cout << "Enter The Student Number"<<endl;
			cin >> newstudent->StudentNumber;
			while(exist!=NULL){
				if(newstudent->StudentNumber==exist->StudentNumber){
					cout<< newstudent->StudentNumber <<" is existed, please try again"<<endl;
					break;
				}
				else{
					exist=exist->next;
				}
			}
		}
		cout << "Enter The Student's first name"<<endl;
		cin >> newstudent->Studentfname;
		cout << "Enter The Student's last name"<<endl;
		cin >> newstudent->Studentlname;
		cout << "Enter The Student's major "<<endl;
		cin >> newstudent->StudentMajor;
		if(first==NULL){
			first=last=newstudent;
		}
		else{
			last->next=newstudent;
			last=newstudent;
		}
		fstream file("student.txt", ios::out|ios::app);
		if(file.is_open()){
			file<< newstudent->StudentNumber << " "<< newstudent->Studentfname <<" "<< newstudent->Studentlname <<" "<< newstudent->StudentMajor<< endl;
			file.close();
		}
		else{
			cout<<"ERROR"<<endl;
		}	
	}
void Student::DeleteStudent(){
		int StNo;
		Node *curst=first;
		Node *nextst=first;
		cout<< "Enter the student number to DELETE"<< endl;
		cin >> StNo;
		while(nextst){
			if(StNo==nextst->StudentNumber){
				if(nextst==first){
					first=first->next;
					delete nextst;
					cout<<"This student number Deleted";
					break;
				}
				else{
					curst->next=nextst->next;
					delete nextst;
					cout<<"This student number Deleted";
					break;
				}
			}
			else{
				curst=nextst;
				nextst=nextst->next;
				if(nextst==NULL){
					cout <<"This student number doesNOT exist."<< endl;
				}
			}
		}
		Node *newfile=first;
		fstream file("student.txt", ios::out);
		while(newfile!=NULL){
			if(file.is_open()){
				file << newfile->StudentNumber << " "<< newfile->Studentfname <<" "<< newfile->Studentlname <<" "<< newfile->StudentMajor<<endl;
			}
			else{
				cout<<"ERROR"<<endl;
			}
			newfile=newfile->next;
		}
		file.close();
	}
void Student::SeekStudent(){
		int StNo;
		Node *seekst=first;
		cout<< "\nEnter the student number that your are looking for"<< endl;
		cin >> StNo;
		while(true){
			if(StNo==seekst->StudentNumber){
			cout << "Student Number : "<< seekst->StudentNumber<<endl;
			cout << "Student Name : "<< seekst->Studentfname << " " << seekst->Studentlname<< endl;
			cout << "Student Major : "<< seekst->StudentMajor <<endl;
			}
			seekst=seekst->next;
			if(seekst==NULL){
				cout<<"Finish"<<endl;
				break;
			}			
		}	
	}
void Student::SetCourse(int stno){
		link *newStCourses=new link;
		if(!newStCourses){
			cout << "Allocation";
			getch();
		}
		newStCourses->next=NULL;
		int courseNo;
		NodeCourse *tempCourse=firstcourse;
		cout << "Enter the course code"<<endl;
		cin>> courseNo;
		while(true){
			if(courseNo==tempCourse->CourseCode){
				newStCourses->StudentNumber=stno;
				newStCourses->StCourseCode=courseNo;
				if(head==NULL){
					head=tail=newStCourses;
				}
				else{
					tail->next=newStCourses;
					tail=newStCourses;
				}
				fstream file("studentcourses.txt", ios::out|ios::app);
				if(file.is_open()){
					file<< newStCourses->StudentNumber << " "<< newStCourses->StCourseCode <<endl;
					file.close();
					break;
				}
				else{
					cout<<"ERROR"<<endl;
				}	
			}
			else{
				tempCourse=tempCourse->next;
				if(tempCourse==NULL){
					cout<<"The course code is WRONG"<<endl;
				}
			}
		}	
	}
void Student::RegistareCourse(){
		int StNo;
		Node *tempSt=first;
		cout<<"Enter the student number"<<endl;
		cin>> StNo;
		while(true){
			if(StNo==tempSt->StudentNumber){
				cout<< "To set a Theoretical course press ""t"" or press ""p"" to set a Practical course"<<endl;
				char coursetype;
				cin>> coursetype;
				Student::SetCourse(StNo);
				break;
			}
			else{
				tempSt=tempSt->next;
				if(tempSt==NULL){
					cout<<"The student number is WRONG"<<endl;
					break;
				}
			}
		}		
	}
void Student::DeleteStudentCourse(){
		int courseNo;
		int StNo;
		cout<<"Enter the student number"<<endl;
		cin >> StNo;
		cout<< "Enter the course to DELETE"<< endl;
		cin >> courseNo;
		link *curstcourse=head;
		link *nextstcourse=head;
		while(true){
			if(StNo==nextstcourse->StudentNumber){
				if(courseNo==nextstcourse->StCourseCode){
					if(nextstcourse==head){
						head=head->next;
						delete nextstcourse;
						cout<< "Course "<<courseNo<<" was removed for "<<StNo<<" student number."<<endl;
						break;
				}
					else{
						curstcourse->next=nextstcourse->next;
						delete nextstcourse;
						cout<< "Course "<<courseNo<<" was removed for "<<StNo<<" student number"<<endl;
						break;
					}
				}	
			}
			else{
				curstcourse=nextstcourse;
				nextstcourse=nextstcourse->next;
				if(nextstcourse==NULL){
					cout <<"This course or this student number doesNOT exist."<< endl;
				}
			}
		}
		link *newfile=head;
		fstream file("studentcourses.txt", ios::out);
		while(newfile!=NULL){
			if(file.is_open()){
				file << newfile->StudentNumber << " "<< newfile->StCourseCode<<endl;
			}
			else{
				cout<<"ERROR"<<endl;
			}
			newfile=newfile->next;
		}
		file.close(); 
	}

void Student::SetScore(){
		int courseNo;
		int StNo;
		int score;
		cout<<"Enter the student number"<<endl;
		cin >> StNo;
		cout<< "Enter the course code "<< endl;
		cin >> courseNo;
		cout <<"Enter the score"<<endl;
		cin >> score;
		link *temp=head;
		while(true){
			if(StNo==temp->StudentNumber && courseNo==temp->StCourseCode){
				temp->Studentscores=score;
				cout<< score <<"was set for "<<StNo<<" student and "<< courseNo <<" course code"<<endl;
				break;
			}
			temp=temp->next;
			if(temp==NULL){
				cout<<"This course or this student number doesNOT exist."<< endl;
				break;
			}
		}
		fstream file("student-score.txt", ios::out|ios::app);
		if(file.is_open()){
			file<< temp->StudentNumber << " "<< temp->StCourseCode <<" "<< temp->Studentscores <<endl;
			file.close();
		}
		else{
			cout<<"ERROR"<<endl;
		}	
	}
void Student::Print(){
		int r=2;
		Node *print=first;
		gotoxy(1,1);
		cout << "Student Number";
		gotoxy(19,1);
		cout << "Student Name";
		gotoxy(41,1);
		cout << "Student Major";
		while(print!=NULL){
			gotoxy(2,r);
			cout << print->StudentNumber;
			gotoxy(18,r);
			cout <<print->Studentfname << " " << print->Studentlname;
			gotoxy(40,r);
			cout << print->StudentMajor;
			print=print->next;
			if(print->next==NULL){
				break;
			}
			r++;
		}
	}	
void Student::StudentAndScores(){
		int courseNo;
		int r=4;
		link *temp=head;
		cout <<"Enter the course code"<<endl;
		cin >> courseNo;
		gotoxy(2,3);
		cout<<"course code";
		gotoxy(16,3);
		cout<< "Student Number";
		gotoxy(35,3);
		cout<< "Student score";
		while(temp!=NULL){
			if(courseNo==temp->StCourseCode){
				gotoxy(2,r);
				cout<<courseNo;
				gotoxy(17,r);
				cout<< temp->StudentNumber;
				gotoxy(36,r);
				cout<< temp->Studentscores;
				temp=temp->next;
				r++;
			}
			else{
				temp=temp->next;
				if(temp->next==NULL){
					gotoxy(2,r+2);
					cout<<"Nothing found"<<endl;
				break;
			}
			}
			if(temp->next==NULL){
				break;
			}
		}
	}
void Student::StudentAndCourses(){
		int r=2;
		link *temp=head;
		NodeCourse *tempcourse=firstcourse;
		gotoxy(2,1);
		cout<< "Course Code";
		gotoxy(17,1);
		cout<< "Student Number";
		while(true){
			while(true){
				if(temp->StCourseCode==tempcourse->CourseCode){
					gotoxy(2,r);
					cout<< temp->StCourseCode;
					gotoxy(17,r);
					cout<< temp->StudentNumber;
					temp=temp->next;
					r++;
				}
				else{
					break;
				}
			}
			tempcourse=tempcourse->next;
			if(tempcourse->next==NULL){
				break;
			}
		}
	}
void Courses::InputCourse(){
		fstream file("course.txt",ios::in | ios::out | ios::app);
		while(!file.eof()){
			NodeCourse *inputcourse=new NodeCourse;
			inputcourse->next=NULL;
			file >> inputcourse->coursetype >> inputcourse->CourseCode >> inputcourse->CourseName >> inputcourse->CourseUnit;
			if(inputcourse->coursetype=='t'){
				inputcourse->TCourseName=inputcourse->CourseName;
				inputcourse->TCourseCode=inputcourse->CourseCode;
				inputcourse->TCourseUnit=inputcourse->CourseUnit;
			}
			else if(inputcourse->coursetype=='p'){
				inputcourse->PCourseName=inputcourse->CourseName;
				inputcourse->PCourseCode=inputcourse->CourseCode;
				inputcourse->PCourseUnit=inputcourse->CourseUnit;
			}
			if(first==NULL){
				first=last=inputcourse;
			}
			else{
				last->next=inputcourse;
				last=inputcourse;
			}
		}
		file.close();
	}
void Courses::Inputdes(){
		int courseno;
		string couredes;
		fstream file("course-describe.txt", ios::in | ios::out | ios::app);
		NodeCourse *existdes=first;
		while(!file.eof()){	
			existdes=first;
			file >> courseno;
			getline(file,couredes);
			while(existdes!=NULL){
				if(existdes->CourseCode==courseno){
					existdes->coursedescribe=couredes;
					break;
				}
				else{
					existdes=existdes->next;
				}
			}
		}
		file.close();
	}
void Courses::AddCourses(){
		NodeCourse *newcourse=new NodeCourse;
		if(!newcourse){
			cout << "Allocation";
			getch();
		}
		newcourse->next=NULL;
		NodeCourse *exist=first;
		while(exist!=NULL){
			exist=first;
			cout << "Enter Name of the Course"<<endl;
			cin >>newcourse->CourseName;
			while(exist!=NULL){
				if(newcourse->CourseName==exist->CourseName){
					cout<< newcourse->CourseName <<" is existed, please try again"<<endl;
					break;
				}
				else{
					exist=exist->next;
				}
			}
		}
		exist=first;
		while(exist!=NULL){
			exist=first;
			cout << "Enter The Course Code"<<endl;
			cin >> newcourse->CourseCode;
			while(exist!=NULL){
				if(newcourse->CourseCode==exist->CourseCode){
					cout<< newcourse->CourseCode <<" is existed, please try again"<<endl;
					break;
				}
				else{
					exist=exist->next;
				}
			}
		}
		cout << "Enter The Course Unit"<<endl;
		cin >> newcourse->CourseUnit;
		if(type=='t'){
			newcourse->coursetype='t';
			newcourse->TCourseName=newcourse->CourseName;
			newcourse->TCourseCode=newcourse->CourseCode;
			newcourse->TCourseUnit=newcourse->CourseUnit;
		}
		else if(type=='p'){
			newcourse->coursetype='p';
			newcourse->PCourseName=newcourse->CourseName;
			newcourse->PCourseCode=newcourse->CourseCode;
			newcourse->PCourseUnit=newcourse->CourseUnit;
		}
		if(first==NULL){
			first=last=newcourse;
		}
		else{
			last->next=newcourse;
			last=newcourse;
		}
		fstream file("course.txt", ios::out|ios::app);
		if(file.is_open()){
			file<< newcourse->coursetype <<" "<< newcourse->CourseCode << " "<< newcourse->CourseName <<" "<< newcourse->CourseUnit<<endl; 
			file.close();
		}
		else{
			cout<<"ERROR"<<endl;
		}
	}
void Courses::DeleteCourse(){
		int courseNo;
		NodeCourse *curcourse=first;
		NodeCourse *nextcourse=first;
		cout<< "Enter the course code to DELETE"<< endl;
		cin >> courseNo;
		while(nextcourse){
			if(courseNo==nextcourse->CourseCode){
				if(nextcourse==first){
					first=first->next;
					delete nextcourse;
					result='a';
					break;
				}
				else{
					curcourse->next=nextcourse->next;
					delete nextcourse;
					result='a';
					break;
				}
			}
			else{
				curcourse=nextcourse;
				nextcourse=nextcourse->next;
				if(nextcourse==NULL){
					cout <<"This course code doesNOT exist."<< endl;
					result='f';
				}
			}
		}
		NodeCourse *newfile=first;
		fstream file("course.txt", ios::out);
		while(newfile!=NULL){
			if(file.is_open()){
				file << newfile->coursetype <<" "<< newfile->CourseCode << " "<< newfile->CourseName <<" "<< newfile->CourseUnit <<endl;
			}
			else{
				cout<<"ERROR"<<endl;
			}
			newfile=newfile->next;
		}
		file.close();
	}
void Courses::SeekCourse(){
		int courseNo;
		NodeCourse *seekcourse=first;
		cout<< "Enter the course code that your are looking for"<< endl;
		cin >> courseNo;
		if(seekcourse==NULL){
			cout<<"\nPlease add courses first."<<endl;
		}
		while(seekcourse!=NULL){
			if(courseNo==seekcourse->CourseCode){
				cout << "Course Name : "<< seekcourse->CourseName <<endl;
				cout << "Course Unit : "<< seekcourse->CourseUnit << endl;
				cout << "Course Code : "<< seekcourse->CourseCode <<endl;
				if(type=='t' && courseNo==seekcourse->TCourseCode){
					cout << "Description of theoretical course : "<< seekcourse->coursedescribe<<endl;
				}
				else if(type=='p' && courseNo==seekcourse->PCourseCode){
					cout << "Description of Practical course "<< seekcourse->coursedescribe<<endl;
				}
			}
			seekcourse=seekcourse->next;
			if(seekcourse==NULL){
				cout<<"\nFinish"<<endl;
				break;
			}
		}
	}
void Courses::Print(){
		int r=2;
		NodeCourse *print=first;
		gotoxy(2,1);
		cout <<"Course Type";
		gotoxy(20,1);
		cout << "Course Name";
		gotoxy(40,1);
		cout << "Course Unit";
		gotoxy(58,1);
		cout << "Course Code";
		gotoxy(70,1);
		cout << "course describe";
		while(print!=NULL){
			if(print->CourseCode==print->TCourseCode){
				gotoxy(0,r);
				cout <<r-1<<"  Theoretical";
			}
			if(print->CourseCode==print->PCourseCode){
				gotoxy(0,r);
				cout <<r-1<<"  Practical";
			}
			gotoxy(20,r);
			cout <<print->CourseName;
			gotoxy(40,r);
			cout << print->CourseUnit;
			gotoxy(59,r);
			cout << print->CourseCode;
			gotoxy(70,r);
			cout << print->coursedescribe;
			print=print->next;
			if(print->next==NULL){
				break;
			}
			r++;
		}
	}
void Courses::descriptioncourse(){
		string describe;
		int courseNo;
		NodeCourse *describecourse=first;
		cout<< "Enter the course number"<<endl;
		cin >> courseNo;
		while(describecourse!=NULL){
			if(courseNo==describecourse->CourseCode){
				cout<< "Enter the course description"<<endl;
				cin.ignore();
				getline(cin , describecourse->coursedescribe);
				fstream file("course-describe.txt", ios::out|ios::app);
				if(file.is_open()){
					file << describecourse->CourseCode <<" "<< describecourse->coursedescribe <<endl;
					file.close();
					break;
				}
				else{
					cout<<"ERROR"<<endl;
				}
			}
			else{
				describecourse=describecourse->next;
				if(describecourse==NULL){
					cout<< "There is No such a course number in Courses"<< endl;
				}
			}
		}	
	}
