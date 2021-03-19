// test.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string username,password;
bool deletebook = false;
bool addbook = false;
bool searchbook = false;
bool updatebook = false;
bool isAdmin = false;
void adminmenu();
void login(string admin,string passtrue);
void searchbooks();
void updatebooks();
void addbooks();
void deletebooks();
void getData (string id,string discription,string authorname,string name);
void readData();
void readDataByAuthor();
void readDataByName();
void updateData ();
void deleteData ();
void purchaseBook(string id);
void deleteDataById (string id);
void main()
{
		int choice = -1;
		cout<<"\n\tThis application lets you to \n\tview and search any details you want to \n\tknow about books available in this bookshop"<<endl;
		cout<<"\n\t*************** you are welcome **************** ";
  do{
		
		cout<<"\n\n\tplease select the options below\n\n\t1.Admin login\n\t2.Customer\n\t0.exit";
		cout<<"\n\n\tyour option is : ";
		cin>>choice;
		isAdmin = false;
	   switch (choice){
	   case 1 :
		   system("cls");
		   cout<<"\n\n\tenter user name : ";
		   cin>>username;
		   cout<<"\n\tenter password : ";
		   cin>>password;
		   login(username,password);
		   break;
	   case 2 :
		   searchbooks();
		   break;
	
	 
	   }

   } while(choice!=0);
  
 
}
	//LOGIN FUNCTION
void login(string admin,string passtrue) {
	
	string user,pass;
	int j=0;
	ifstream file;
	file.open("Login.txt");
	
	while(!file.eof())
	{
		
		if (j==0) {
			file >> user;
		} else {
			file >> pass;
			
		}
		j++;
	}
	file.close();
		
	if(user==admin && pass==passtrue){
			system("cls");
			cout<<"\n\tLoged in Succeessfuly";
			isAdmin = true;
			adminmenu();
	}
	else {
		system("cls");
		cout<<"\n\n\tLogin failed plz try again!";
		
	}
}
//ADMIN'S MENU
	void adminmenu() {
		
	int choice = -1;
	do {
		
		cout<<"\n\n\t********** Admin's menu is ***********";
		cout<<"\n\n\t1.Add books\n\n\t2.Delete books\n\n\t3.Search books\n\n\t4.Update books information\n\n\t0.Exit";
		cout<<"\n\n\tyour option is : ";
		cin>>choice;
		switch (choice) {
		case 1 :
			addbook =true;
			addbooks();
			break;
		case 2 :
			deleteData ();
			break;
		case 3 :
			searchbook = true;
			searchbooks();
			break;
		case 4 :
			updateData ();
			break;
		case 0 :
			break;
		 
		}
		
	
	}while(choice!=0);
   
}
//SEARCH FUNCTION
void searchbooks() {

int choice =-1;

	system("cls");
	do {
	//system("cls");
	cout<<"\tSEARCH BOOKS ";
	cout<<"\n\t============";
	cout<<"\n\n\t1.search book by ID  : ";
	cout<<"\n\n\t2.search book by Author name  : ";
	cout<<"\n\n\t3.search by book name  :";
	cout<<"\n\n\t4.press 0 to exit ";
	cout<<"\n\n\tplease enter your selection here  :";
	cin>>choice;

	system("cls");
	switch(choice)  {
		system("cls");
	case 1:
		readData();
		break;
	case 2:
		readDataByAuthor();
		break;
	case 3:
		readDataByName();
		break;
	case 4:
		break;
		}
	
	}while(choice!=0);
}

//ADD BOOKS FUNCTION
void addbooks() {

	

	system("cls");
	
	
	string id,name,authorname,discription;
	cout<<"enter book ID  : ";
	cin>>id;
	cout<<"\nenter book name : ";
	cin.ignore();
	getline(cin,name);
	cout<<"enter book author name : ";
	getline(cin,authorname);
	cout<<"enter book discription :";
	getline(cin,discription);

	getData(id,discription,authorname,name);
	
	
}



//UPDATE BOOKS FUNVTION
void updatebooks() {

int choice =-1;

	system("cls");
	do {
	
	cout<<"\n\n\t1.search book by ID  : ";
	cout<<"\n\n\t2.search book by Author name  : ";
	cout<<"\n\n\t3.search by book name  :";
	cout<<"\n\n\t4.press 0 to exit ";
	cout<<"\n\n\tplease enter your selection here  :";
	cin>>choice;

	switch(choice)  {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
		}
	
	}while(choice!=0);
}

void getData (string id,string discription,string authorname,string name) {
	ofstream file;
	file.open("temp.txt", ios::out | ios::app);
	string inputData ;
	inputData.append(id);
	inputData.append(" ");
	inputData.append(name);
	inputData.append(" ");
	inputData.append(authorname);
	inputData.append(" ");
	inputData.append(discription);
	inputData.append(" , ");
	file << inputData;
    file.close();
	

}

void readData () {
	ifstream file;
	string id,name,author,description;
	bool found = false;
	bool show = false;
	string inputID;
	file.open("temp.txt");
	cout<<"Enter Book ID :";
	cin>>inputID;
	int i = 0;
	while(!file.eof()) {
		string result;
		file >> result;
		
		if (result == ",") {
			i = 0;
			found = false;
			
		} else {

			if (i ==0) {

				if (inputID == result) {
					found = true;
					show = true;
					id = result;
				}
				
			} else if (i==1) {
				if (found){
					name = result;
				}
				
			} else if (i ==2) {
				if (found) {
					author = result;
				} 
				
			} else  {
				if (found) {
					description.append(result);
					description.append(" ");
				}
				
			}
			i++;
		}

	}
	 file.close();
	if (show)
	{
		system("cls");
		cout<<"\n\n\tID name : "<<id<<endl;
		cout<<"\n\n\tBook name : "<<name<<endl;
		cout<<"\n\n\tAuthor name : "<<author<<endl;
		cout<<"\n\n\tBook discription : "<<description<<endl;
		if (!isAdmin) {
			purchaseBook(id);
		}
	} else {
		cout<<"\n\n\tnot found";
	



}

}
void readDataByName () {
	ifstream file;
	string id,tempid,name,author,description;
	bool found = false;
	bool show = false;
	string inputID;
	file.open("temp.txt");
	cout<<"\tSEARCH BOOKS ";
	cout<<"\n\t============";
	cout<<"\n\n\tPlease enter the book's name : ";
	cin>>inputID;
	int i = 0;
	while(!file.eof()) {
		string result;
		file >> result;
		if (result == ",") {
			
			i = 0;
			found = false;
			
		} else {
			if (i ==0) {
				tempid = result;
				
			} else if (i==1) {
				if (inputID == result) {
					id = tempid;
					name = result;
					found = true;
					show = true;
				}
				
			} else if (i ==2) {
				if (found) {
					author = result;
				}
				
			} else  {
				if (found) {
					description.append(result);
					description.append(" ");
				}
				
			}
			i++;
		}
		
	}
	 file.close();
	if (show)
	{
		system("cls");
		cout<<"\n\n\tID name : "<<id<<endl;
		cout<<"\n\n\tBook name : "<<name<<endl;
		cout<<"\n\n\tAuthor name : "<<author<<endl;
		cout<<"\n\n\tBook discription : "<<description<<endl;
		if (!isAdmin) {
			purchaseBook(id);
		}

	} else {
		cout<<"\n\n\tnot found";
	}



}

void readDataByAuthor () {
	ifstream file;
	string id,tempid,name,tempname,author,description;
	bool found = false;
	bool show = false;
	string inputID;
	file.open("temp.txt");
	cout<<"\tSEARCH BOOKS ";
	cout<<"\n\t============";
	cout<<"\n\n\tPlease enter the book's author name : ";
	cin>>inputID;
	int i = 0;
	while(!file.eof()) {
		string result;
		file >> result;
		if (result == ",") {
			found = false;
			i = 0;
			
		} else {
			if (i ==0) {
				tempid = result;
			} else if (i==1) {
				tempname = result;
			} else if (i ==2) {
				if (inputID == result) {
					id = tempid;
					name = tempname;
					author = result;
					found = true;
					show = true;
				}
				
			} else  {
				if (found) {
					description.append(result);
					description.append(" ");
				}
				
			}
			i++;
		}
		
	}
	 file.close();
	if (show)
	{
		system("cls");
		cout<<"\n\n\tID name : "<<id<<endl;
		cout<<"\n\n\tBook name : "<<name<<endl;
		cout<<"\n\n\tAuthor name : "<<author<<endl;
		cout<<"\n\n\tBook discription : "<<description<<endl;
		if (!isAdmin) {
			purchaseBook(id);
		}
	} else {
		cout<<"\n\n\tnot found";
	}



}
void updateData () {
	ifstream file;
	
	system("cls");
	
	string id,name,authorname,discription;
	cout<<"enter book ID  : ";
	cin>>id;
	cout<<"\nenter book name : ";
	cin.ignore();
	getline(cin,name);
	cout<<"enter book author name : ";
	getline(cin,authorname);
	cout<<"enter book discription :";
	getline(cin,discription);
	bool found = false;
	file.open("temp.txt");
	string fileStr;
	int i = 0;
	while(!file.eof()) {
		string result;
		file >> result;
		if (result == ",") {
			
				fileStr.append(" ");
				fileStr.append(result);
				fileStr.append(" ");
			
			i = 0;
			found = false;
		} else {
			if (i == 0) {
				if (id == result) {
					found = true;
				}
				if (found) {
					fileStr.append(id);
					fileStr.append(" ");
				}
			}  else if (i==1) {
				if (found) {
					fileStr.append(name);
					fileStr.append(" ");
				}
			} else if (i ==2) {
				if (found) {
					fileStr.append(authorname);
					fileStr.append(" ");
				}
			} else if (i >=3)  {
				if (found) {
					fileStr.append(discription);
					fileStr.append(" ");
				}
			}
			
				if (!found){
					fileStr.append(result);
					fileStr.append(" ");
				}
				i++;
		}
		
	}
	 file.close();

	ofstream ofile;
	ofile.open("temp.txt");
	ofile << "";
	ofile << fileStr;
    ofile.close();

}
void deleteData () {
	ifstream file;
	
	system("cls");
	string id;
	cout<<"enter book ID  : ";
	cin>>id;

	bool found = false;
	file.open("temp.txt");
	string fileStr;
	int i = 0;
	while(!file.eof()) {
		string result;
		file >> result;
		if (result == ",") {
			if (found) {
				fileStr.append("");
			} else {
				fileStr.append(" ");
				fileStr.append(result);
				fileStr.append(" ");
			}
			i = 0;
			found = false;
		} else {
			if (i == 0) {
				if (id == result) {
					found = true;
				}
				
			}  
			if (!found){
				fileStr.append(result);
				fileStr.append(" ");
			}
			i++;
		}
		
	}
	 file.close();

	ofstream ofile;
	ofile.open("temp.txt");
	ofile << "";
	ofile << fileStr;
    ofile.close();

}
//SEARCH FUNCTION
void purchaseBook(string id) {

int choice =-1;

	
	do {
	cout<<"\tDo you want to Purchase this book? ";
	cout<<"\n\t============";
	cout<<"\n\n\t1.Yes  : ";
	cout<<"\n\n\t2.No  : ";
	cout<<"\n\n\t0.press 0 to exit ";
	cout<<"\n\n\tplease enter your selection here  :";
	cin>>choice;

	
	switch(choice)  {
		
	case 1:
		deleteDataById(id);
		choice = 0;
		break;
	case 2:
		choice = 0;
		break;
	case 3:
		break;
		}
	
	}while(choice!=0);
}
void deleteDataById (string id) {
	ifstream file;
	bool found = false;
	file.open("temp.txt");
	string fileStr;
	int i = 0;
	while(!file.eof()) {
		string result;
		file >> result;
		if (result == ",") {
			if (found) {
				fileStr.append("");
			} else {
				fileStr.append(" ");
				fileStr.append(result);
				fileStr.append(" ");
			}
			i = 0;
			found = false;
		} else {
			if (i == 0) {
				if (id == result) {
					found = true;
					cout<<"\n\n\tBook has been purchased Successfully!";
				}
				
			}  
			if (!found){
				fileStr.append(result);
				fileStr.append(" ");
			}
			i++;
		}
			
		
	}
	 file.close();

	ofstream ofile;
	ofile.open("temp.txt");
	ofile << "";
	ofile << fileStr;
    ofile.close();

	

}