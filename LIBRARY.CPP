// @author: Ashutosh Bharti

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>

//***************************************************************
//                   MACRO FUNCTION USED IN PROJECT
//****************************************************************


#define DISPLAY(no, msg, ch, scol, ucol) \
	if(no==ch){\
		textattr(scol);\
		cout<<"\n\n\t";\
		cprintf(" %d. %s",no,msg);\
		textattr(ucol);\
	}\
	else\
		cout<<"\n\n\t "<<no<<". "<<msg;


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class date{

public:
	int dd;
	int mm;
	int yy;

	void datef()
	{dd=mm=yy=0;}

	void getdate();

	void displaydate()
	{cout<<dd<<"/"<<mm<<"/"<<yy<<"\n";}

};	 //class ends here

void date::getdate(){
	char tmp;
	cout<<"\n Enter date (dd/mm/yyyy):";
	cin>>dd>>tmp>>mm>>tmp>>yy;
	int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((yy%100!=0&&yy%4==0)||yy%400==0)
		mon[1]=29;
	if((dd>mon[mm-1])||(dd<1)||(mm>12)||(mm<1)||(yy<2000)){
		cout<<"\n You entered wrong date!!!\n";
		getdate();
	}
}




class book
{
	char bno[6];
	char bname[50];
	char aname[20];
	int  price;
  public:
	void create_book();

	void modify_book();

	void show_book()
	{
		cout<<"\n\n Book no.: "<<bno;
		cout<<"\n Book Name: ";
		puts(bname);
		cout<<" Author Name: ";
		puts(aname);
		cout<<" Price: Rs. "<<price<<endl;
	}

	char* retbno()
	{
		return bno;
	}

	void report()
	{
		cout.setf(ios::left);
		cout<<"    "<<setw(10)<<bno<<setw(25)<<bname<<" "<<setw(25)<<aname<<" "<<price<<endl;
		cout.unsetf(ios::left);
	}


};         //class ends here

void book::create_book()
{
	cout<<"\n\t\t||||| NEW BOOK ENTRY |||||";
	cout<<"\n\n Book no.: ";
	cout<<"\n\n Name of The Book: ";
	cout<<"\n\n Author's Name: ";
	cout<<"\n\n Price: Rs. ";

	int i;
	gotoxy(12,4);
	for(i=0;i<6;i++)
	{
		bno[i]=getch();
		if(bno[i]==9 && i!=0){
			gotoxy(20,6);
			break;
		}
		if(bno[i]!=127 && bno[i]!=8){
			if(i!=5 && bno[i]>47 && bno[i]<57)
				cout<<bno[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	bno[i]='\0';

	for(i=0;i<50;i++)
	{
		bname[i]=getch();
		if(bname[i]==9 && i!=0){
			gotoxy(17,8);
			break;
		}
		if(bname[i]!=127 && bname[i]!=8){
			if(i!=0 && i!=49 && (bname[i]=='.' || bname[i]==' ' || (bname[i]>47 && bname[i]<57) || (bname[i]>64 && bname[i]<91) || (bname[i]>96 && bname[i]<123)))
				cout<<bname[i];
			else if(i==0 && ((bname[i]>64 && bname[i]<91) || (bname[i]>96 && bname[i]<123)))
				cout<<bname[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	bname[i]='\0';

	for(i=0;i<20;i++)
	{
		aname[i]=getch();
		if(aname[i]==9 && i!=0){
			gotoxy(13,10);
			break;
		}
		if(aname[i]!=127 && aname[i]!=8){
			if(i!=0 && i!=19 && (aname[i]=='.'|| aname[i]==' ' || (aname[i]>47 && aname[i]<57) || (aname[i]>64 && aname[i]<91) || (aname[i]>96 && aname[i]<123)))
				cout<<aname[i];
			else if(i==0 && ((aname[i]>64 && aname[i]<91) || (aname[i]>96 && aname[i]<123)))
				cout<<aname[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	aname[i]='\0';

	char temp[5];
	for(i=0;i<5;i++)
	{
		temp[i]=getch();
		if(temp[i]==13 && i!=0){
			break;
		}
		if(temp[i]!=127 && temp[i]!=8){
			if(i!=4 && temp[i]>47 && temp[i]<57)
				cout<<temp[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	temp[i]='\0';
	price=atoi(temp);
	cout<<"\n\n\n\tBook Created...";
}

void book::modify_book()
{
	cout<<"\n Book no.: "<<bno;
	cout<<"\n Modify Book Name: ";
	cout<<"\n Modify Author's Name: ";
	cout<<"\n Modify Price of Book: Rs. ";
	int i;
	gotoxy(20,15);
	for(i=0;i<50;i++)
	{
		bname[i]=getch();
		if(bname[i]==9 && i!=0){
			gotoxy(24,16);
			break;
		}
		if(bname[i]!=127 && bname[i]!=8){
			if(i!=0 && i!=49 && (bname[i]=='.' || bname[i]==' ' || (bname[i]>47 && bname[i]<57) || (bname[i]>64 && bname[i]<91) || (bname[i]>96 && bname[i]<123)))
				cout<<bname[i];
			else if(i==0 && ((bname[i]>64 && bname[i]<91) || (bname[i]>96 && bname[i]<123)))
				cout<<bname[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	bname[i]='\0';

	for(i=0;i<20;i++)
	{
		aname[i]=getch();
		if(aname[i]==9 && i!=0){
			gotoxy(28,17);
			break;
		}
		if(aname[i]!=127 && aname[i]!=8){
			if(i!=0 && i!=19 && (aname[i]=='.'|| aname[i]==' ' || (aname[i]>47 && aname[i]<57) || (aname[i]>64 && aname[i]<91) || (aname[i]>96 && aname[i]<123)))
				cout<<aname[i];
			else if(i==0 && ((aname[i]>64 && aname[i]<91) || (aname[i]>96 && aname[i]<123)))
				cout<<aname[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	aname[i]='\0';

	char temp[5];
	for(i=0;i<5;i++)
	{
		temp[i]=getch();
		if(temp[i]==13 && i!=0){
			break;
		}
		if(temp[i]!=127 && temp[i]!=8){
			if(i!=4 && temp[i]>47 && temp[i]<57)
				cout<<temp[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	temp[i]='\0';
	price=atoi(temp);
}




class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
	date d;
public:
	void create_student();

	void modify_student();

	void show_student()
	{
		cout<<"\n\n Admission no.: "<<admno;
		cout<<"\n\n Student Name: ";
		puts(name);
		cout<<"\n No of Book issued: "<<token;
		if(token==1)
			cout<<"\n\n Book No: "<<stbno;
	}

	void get_date()
	{
		d.getdate();
	}

	void display_date()
	{
		cout<<" Issue Date: ";
		d.displaydate();
	}

	date retd()
	{
		return d;
	}

	char* retadmno()
	{
		return admno;
	}

	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void resetdate()
	{d.datef();}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{
		cout.setf(ios::left);
		cout<<"     "<<setw(12)<<admno<<setw(23)<<name<<" "<<setw(10)<<token<<" ";
		d.displaydate();
		cout.unsetf(ios::left);
		cout<<endl;
	}
};         //class ends here

void student::create_student()
{
	cout<<"\n\t\t||||| NEW STUDENT ENTRY ||||| ";
	cout<<"\n\n Admission no.: ";
	cout<<"\n\n Name of The Student: ";
	token=0;
	stbno[0]='\0';
	d.datef();
	int i;
	gotoxy(17,4);
	for(i=0;i<6;i++)
	{
		admno[i]=getch();
		if(admno[i]==9 && i!=0){
			gotoxy(23,6);
			break;
		}
		if(admno[i]!=127 && admno[i]!=8){
			if(i!=5 && admno[i]>47 && admno[i]<57)
				cout<<admno[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	admno[i]='\0';

	for(i=0;i<20;i++)
	{
		name[i]=getch();
		if(name[i]==13 && i!=0){
			break;
		}
		if(name[i]!=127 && name[i]!=8){
			if(i!=0 && i!=19 && (name[i]=='.'|| name[i]==' ' || (name[i]>47 && name[i]<57) || (name[i]>64 && name[i]<91) || (name[i]>96 && name[i]<123)))
				cout<<name[i];
			else if(i==0 && ((name[i]>64 && name[i]<91) || (name[i]>96 && name[i]<123)))
				cout<<name[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	name[i]='\0';

	cout<<"\n\n\tStudent Record Created...";
}

void student::modify_student()
{
	cout<<"\n\n Admission no.: "<<admno;
	cout<<"\n Student Name: ";
	puts(name);
	cout<<"\n\n Enter The New Details of Student: ";
	cout<<"\n\n Admission no.: "<<admno;
	cout<<"\n Modify Student Name: ";
	gotoxy(23,14);
	int i;
	for(i=0;i<20;i++)
	{
		name[i]=getch();
		if(name[i]==13 && i!=0){
			break;
		}
		if(name[i]!=127 && name[i]!=8){
			if(i!=0 && i!=19 && (name[i]=='.'|| name[i]==' ' || (name[i]>47 && name[i]<57) || (name[i]>64 && name[i]<91) || (name[i]>96 && name[i]<123)))
				cout<<name[i];
			else if(i==0 && ((name[i]>64 && name[i]<91) || (name[i]>96 && name[i]<123)))
				cout<<name[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	name[i]='\0';
}




class password
{
	char pass[5];
public:
	void create_pass(char ps[]);

	int checkpass(char ps[]);

};         //class ends here

void password::create_pass(char ps[])
{
	strcpy(pass,ps);
	for(int i=0;i<4;i++)
		pass[i]=pass[i]+i*i+1;
	cout<<"\n\n\n\tPassword Created...";
}

int password::checkpass(char ps[])
{
	char pas[5];
	strcpy(pas,pass);
	for(int i=0;i<4;i++)
		pas[i]=pas[i]-i*i-1;
	if(strcmp(pas,ps)!=0)
		return 0;
	else
		return 1;
}




//***************************************************************
//    	GLOBAL DECLARATION FOR STREM OBJECT, OBJECT
//****************************************************************

fstream fp,fp1;
book bk;
student st;


//***************************************************************
//    	FUNCTION TO WRITE IN FILE
//****************************************************************

void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		system("cls");
		textattr(29);
		clrscr();
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\n Do you want to add more record...(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void write_student()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		system("cls");
		textattr(67);
		clrscr();
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\n Do you want to add more record...(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}


//***************************************************************
//    	FUNCTION TO READ SPECIFIC RECORD FROM FILE
//****************************************************************


void display_spb()
{
	system("cls");
	textattr(30);
	clrscr();
	char no[6];
	int i,flag=0;
	cout<<"\n\t\t||||| BOOK DETAILS ||||| ";
	cout<<"\n\n\tPlease Enter The book No.: ";
	for(i=0;i<6;i++)
	{
		no[i]=getch();
		if(no[i]==13 && i!=0){
			break;
		}
		if(no[i]!=127 && no[i]!=8){
			if(i!=5 && no[i]>47 && no[i]<57)
				cout<<no[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	no[i]='\0';
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),no)==0)
		{
			bk.show_book();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist.";
	gotoxy(80,25);
	getch();
}

void display_sps()
{
	system("cls");
	textattr(106);
	clrscr();
	int i,flag=0;
	char no[6];
	cout<<"\n\t\t||||| STUDENT DETAILS ||||| ";
	cout<<"\n\n\tPlease Enter The Admission No.: ";
	for(i=0;i<6;i++)
	{
		no[i]=getch();
		if(no[i]==13 && i!=0){
			break;
		}
		if(no[i]!=127 && no[i]!=8){
			if(i!=5 && no[i]>47 && no[i]<57)
				cout<<no[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	no[i]='\0';
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),no)==0))
		{
			st.show_student();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\n Student does not exist.";
	gotoxy(80,25);
	getch();
}


//***************************************************************
//    	FUNCTION TO MODIFY RECORD OF FILE
//****************************************************************


void modify_book()
{
	char no[6];
	int found=0;
	system("cls");
	textattr(97);
	clrscr();
	cout<<"\n\n\t\t||||| MODIFY BOOK REOCORD ||||| ";
	cout<<"\n\n\tEnter The book no. of The book: ";
	int i;
	for(i=0;i<6;i++)
	{
		no[i]=getch();
		if(no[i]==13 && i!=0){
			break;
		}
		if(no[i]!=127 && no[i]!=8){
			if(i!=5 && no[i]>47 && no[i]<57)
				cout<<no[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	no[i]='\0';
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),no)==0)
		{
			bk.show_book();
			cout<<"\n Enter The New Details of book: "<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			cout<<"\n\n\t Record Updated...";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found.";
	gotoxy(80,25);
	getch();
}


void modify_student()
{
	char no[6];
	int found=0;
	system("cls");
	textattr(36);
	clrscr();
	cout<<"\n\n\t\t||||| MODIFY STUDENT RECORD ||||| ";
	cout<<"\n\n\tEnter The admission no. of the student: ";
	int i;
	for(i=0;i<6;i++)
	{
		no[i]=getch();
		if(no[i]==13 && i!=0){
			break;
		}
		if(no[i]!=127 && no[i]!=8){
			if(i!=5 && no[i]>47 && no[i]<57)
				cout<<no[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	no[i]='\0';
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),no)==0)
		{
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated...";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found.";
	gotoxy(80,25);
	getch();
}

//***************************************************************
//    	FUNCTION TO DELETE RECORD OF FILE
//****************************************************************


void delete_student()
{
	char no[6];
	int flag=0;
	system("cls");
	textattr(49);
	clrscr();
	cout<<"\n\n\n\t\t||||| DELETE STUDENT ||||| ";
	cout<<"\n\n Enter The admission no. of the Student You Want To Delete: ";
	int i;
	for(i=0;i<6;i++)
	{
		no[i]=getch();
		if(no[i]==13 && i!=0){
			break;
		}
		if(no[i]!=127 && no[i]!=8){
			if(i!=5 && no[i]>47 && no[i]<57)
				cout<<no[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	no[i]='\0';
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),no)!=0)
			fp2.write((char*)&st,sizeof(student));
		else
			flag=1;
	}
	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ...";
	else
		cout<<"\n\n Record not found.";
	gotoxy(80,25);
	getch();
}


void delete_book()
{
	system("cls");
	textattr(43);
	clrscr();
	char no[6];
	int i,flag=0;
	cout<<"\n\n\n\t\t||||| DELETE BOOK ||||| ";
	cout<<"\n\n Enter The Book no. of the Book You Want To Delete: ";
	for(i=0;i<6;i++)
	{
		no[i]=getch();
		if(no[i]==13 && i!=0){
			break;
		}
		if(no[i]!=127 && no[i]!=8){
			if(i!=5 && no[i]>47 && no[i]<57)
				cout<<no[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	no[i]='\0';
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),no)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
		else
			flag=1;
	}

	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ...";
	else
		cout<<"\n\n Record not found. ";
	gotoxy(80,25);
	getch();
}



//***************************************************************
//    	FUNCTION TO DISPLAY ALL STUDENTS LIST
//****************************************************************

void display_alls()
{
	system("cls");
	textattr(33);
	clrscr();
	fp.open("student.dat",ios::in);
	if(!fp)
	{
		cout<<" ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\t\t||||| STUDENT LIST |||||\n\n";
	cout<<"==================================================================\n";
	cout.setf(ios::left);
	cout<<setw(22)<<" Admission No."<<setw(15)<<"Name"<<setw(15)<<"Book Issued"<<"Issued Date\n";
	cout.unsetf(ios::left);
	cout<<"==================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	fp.close();
	gotoxy(80,25);
	getch();
}


//***************************************************************
//    	FUNCTION TO DISPLAY BOOKS LIST
//****************************************************************

void display_allb()
{
	system("cls");
	textattr(49);
	clrscr();
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<" ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\t\t||||| BOOK LIST |||||\n\n";
	cout<<"=========================================================================\n";
	cout.setf(ios::left);
	cout<<setw(17)<<" Book Number"<<setw(24)<<"Book Name"<<setw(24)<<"Author"<<"Price\n";
	cout.unsetf(ios::left);
	cout<<"=========================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
	fp.close();
	gotoxy(80,25);
	getch();
}





//***************************************************************
//    	FUNCTION TO CALCULATE DAYS
//****************************************************************

int calculate_day(date d1, date d2)
{
	int d,m,y;
	if(d1.dd>d2.dd)
	{
		d2.dd+=30;
		d2.mm-=1;
	}
	if(d1.mm>d2.mm)
	{
		d2.mm+=12;
		d2.yy-=1;
	}
	d=d2.dd-d1.dd;
	m=d2.mm-d1.mm;
	y=d2.yy-d1.yy;
	d=d+m*30+y*365;
	return d;
}


//***************************************************************
//    	FUNCTION TO ISSUE BOOK
//****************************************************************

void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
	system("cls");
	textattr(28);
	clrscr();
	cout<<"\n\n\t\t||||| BOOK ISSUE ||||| ";
	cout<<"\n\n\tEnter The student's admission no.: ";
	int i;
	for(i=0;i<6;i++)
	{
		sn[i]=getch();
		if(sn[i]==13 && i!=0){
			break;
		}
		if(sn[i]!=127 && sn[i]!=8){
			if(i!=5 && sn[i]>47 && sn[i]<57)
				cout<<sn[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	sn[i]='\0';
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
				cout<<"\n\n\tEnter the book no.: ";
				for(i=0;i<6;i++)
				{
					bn[i]=getch();
					if(bn[i]==13 && i!=0){
						break;
					}
					if(bn[i]!=127 && bn[i]!=8){
						if(i!=5 && bn[i]>47 && bn[i]<57)
							cout<<bn[i];
						else
							i--;
					}
					else{
						if(i==0)
							i--;
						else if(i!=0){
							cout<<"\b \b";
							i=i-2;
						}
					}
				}
				bn[i]='\0';
				st.get_date();
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						st.display_date();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book issued successfully.\n\nPlease Note: Submit within 15 days. Fine Rs.1 for each day after 15 days period.";
					}
				}
				if(flag==0)
					cout<<"\n\n\t Book no does not exist.";
			}
			else
				cout<<"\n\n Student have not returned the last book. ";

		}
	}
	if(found==0)
		cout<<"\n\n\t Student record not exist...";
	fp.close();
	fp1.close();
	gotoxy(80,25);
	getch();
}

//***************************************************************
//    	FUNCTION TO DEPOSIT BOOK
//****************************************************************

void book_deposit()
{
	char sn[6],bn[6];
	int found=0,flag=0,day,fine;
	date dp;
	system("cls");
	textattr(94);
	clrscr();
	cout<<"\n\n\t\t||||| BOOK DEPOSIT ||||| ";
	cout<<"\n\n\tEnter The students admission no.: ";
	int i;
	for(i=0;i<6;i++)
	{
		sn[i]=getch();
		if(sn[i]==13 && i!=0){
			break;
		}
		if(sn[i]!=127 && sn[i]!=8){
			if(i!=5 && sn[i]>47 && sn[i]<57)
				cout<<sn[i];
			else
				i--;
		}
		else{
			if(i==0)
				i--;
			else if(i!=0){
				cout<<"\b \b";
				i=i-2;
			}
		}
	}
	sn[i]='\0';
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==1)
			{
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),st.retstbno())==0)
					{
						dp.getdate();
						bk.show_book();
						st.display_date();
						cout<<" Deposit Date: ";
						dp.displaydate();
						flag=1;
						day=calculate_day(st.retd(),dp);
						cout<<"\n\n Book deposited in no. of days: "<<day;
						if(day>15)
						{
							fine=(day-15)*1;
							cout<<"\n\n Fine has to deposited Rs. "<<fine;
						}
						st.resettoken();
						st.resetdate();
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book deposited successfully.";
					}
				}
				if(flag==0)
					cout<<"\n\n\t Book no does not exist.";
			}
			else
				cout<<"\n\n\t No book is issued.. Please check!!";
		}
	}
	if(found==0)
		cout<<"\n\n\t Student record not exist...";
	fp.close();
	fp1.close();
	gotoxy(80,25);
	getch();
}




//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{       system("cls");
	textattr(18);
	clrscr();
	gotoxy(25,10);
	cout<<"LIBRARY MANAGEMENT SYSTEM\n";
	gotoxy(35,15);
	cout<<"\n\n\tMADE BY : ASHUTOSH BHARTI";
	cout<<"\n\n\tSCHOOL : KENDRIYA VIDYALAYA R.A.U. PUSA, SAMASTIPUR, BIHAR, INDIA\n";
	gotoxy(80,25);
	getch();
}




//***************************************************************
//    	ADMINISTRATOR AUTHORISATION FUNCTION
//****************************************************************

int admauth(int ch)
{
	password p;
	char ps[5];
	int i,flag=1;
	system("cls");
	textattr(66);
	clrscr();
	cout<<"\n\n\t\t||||| ADMINISTRATOR AUTHORISATION ||||| ";
	fp.open("password",ios::in|ios::out);
	switch(ch)
	{
		case 1:	cout<<"\n\n\t MODIFY PASSWORD ";

		case 2: cout<<"\n\n\t CHECKING PASSWORD ";
				cout<<"\n\n\tEnter 4 Digit Password.: ";
				for(i=0;i<4;i++)
				{
					ps[i]=getch();
					if(ps[i]!=127&&ps[i]!=8)
						cout<<"*";
					else{
						if(i==0)
							i--;
						else if(i!=0){
							cout<<"\b \b";
							i=i-2;
						}
					}
				}
				ps[i]='\0';
				fp.read((char*)&p,sizeof(p));
				flag=p.checkpass(ps);
				if((ch==2)||(flag==0))
					break;
		case 3:	cout<<"\n\n\t CREATE PASSWORD ";
				cout<<"\n\n\tEnter 4 Digit New Password.: ";
				for(i=0;i<4;i++)
				{
					ps[i]=getch();
					if(ps[i]!=127&&ps[i]!=8)
						cout<<"*";
					else{
						if(i==0)
							i--;
						else if(i!=0){
							cout<<"\b \b";
							i=i-2;
						}
					}
				}
				ps[i]='\0';
				p.create_pass(ps);
				fp.seekg(0);
				fp.write((char*)&p,sizeof(p));
				getch();
				break;
	}
	fp.close();
	return flag;
}





//***************************************************************
//    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
	fp.open("password",ios::in);
	if(!fp)
	{
		if(admauth(3)==1);
	}
	fp.close();

	if(admauth(2)==1)
	{
		int ch=1,kb=0;
		do
		{
			system("cls");
			textattr(83);
			clrscr();
			cout<<"\t\t\t||||| ADMINISTRATOR MENU |||||";
			DISPLAY(1,"CHANGE PASSWORD ",ch,33,83);
			DISPLAY(2,"CREATE STUDENT RECORD ",ch,33,83);
			DISPLAY(3,"DISPLAY ALL STUDENTS RECORD ",ch,33,83);
			DISPLAY(4,"DISPLAY SPECIFIC STUDENT RECORD ",ch,33,83);
			DISPLAY(5,"MODIFY STUDENT RECORD ",ch,33,83);
			DISPLAY(6,"DELETE STUDENT RECORD ",ch,33,83);
			DISPLAY(7,"CREATE BOOK ",ch,33,83);
			DISPLAY(8,"DISPLAY ALL BOOKS ",ch,33,83);
			DISPLAY(9,"DISPLAY SPECIFIC BOOK ",ch,33,83);
			DISPLAY(10,"MODIFY BOOK ",ch,33,83);
			DISPLAY(11,"DELETE BOOK ",ch,33,83);
			DISPLAY(12,"BACK TO MAIN MENU ",ch,33,83);
			gotoxy(80,25);
			kb=getch();
			if(kb==0){
				kb=getch();
				if(kb==72 && ch>1)
					ch--;
				else if(kb==80 && ch<12)
					ch++;
			}
			else if(kb==13){
				switch(ch)
				{
					case 1: if(admauth(1)==0){
							cout<<"\n\n\tEntered Password Wrong !!!!!\n";
							getch();
						}
						break;
					case 2:	write_student();break;
					case 3:	display_alls();break;
					case 4: display_sps();break;
					case 5: modify_student();break;
					case 6: delete_student();break;
					case 7:	write_book();break;
					case 8: display_allb();break;
					case 9: display_spb();break;
					case 10:modify_book();break;
					case 11:delete_book();break;
					case 12:return;
					default:cout<<"\a";
				}
			}
		}while(ch!=12 || kb!=13);
	}
	else
	{
		cout<<"\n\n\tEntered Password Wrong !!!!!";
		gotoxy(80,25);
		getch();
	}
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
	int ch=1,kb=0;
	intro();
	do
	{
		system("cls");
		textattr(33);
		clrscr();
		cout<<"\n\n\n\t\t||||| MAIN MENU |||||";
		DISPLAY(1,"BOOK ISSUE ",ch,106,33);
		DISPLAY(2,"BOOK DEPOSIT ",ch,106,33);
		DISPLAY(3,"ADMINISTRATOR MENU ",ch,106,33);
		DISPLAY(4,"EXIT ",ch,106,33);
		gotoxy(80,25);
		kb=getch();
		if(kb==0){
			kb=getch();
			if(kb==72 && ch>1)
				ch--;
			else if(kb==80 && ch<4)
				ch++;
		}
		else if(kb==13){
			switch(ch)
			{
				case 1: book_issue();
					break;
				case 2:	book_deposit();
					break;
				case 3:	admin_menu();
					break;
				case 4:	system("cls");
					exit(0);
				default:cout<<"\a";
			}
		}
	}while(ch!=4 || kb!=13);
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
