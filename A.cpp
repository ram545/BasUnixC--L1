#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
using namespace std;

int showMenu(){
	int choice;
	cout << "1.Employee Registration" << endl;
	cout << "2.Employee Search and Display" << endl;
	cout << "3.Exit" << endl;
	cin >> choice;
	cin.ignore(250,'\n');
	if(choice<1 && choice>3){
		cout << "Please Enter a valid choice" << endl;
		return showMenu();
	}
	return choice;
}

void doRegister(){
	int age;
	string temp;
	fstream fd("customerdetails.txt",ios::out | ios::app);
	if(fd){
		cout << "Enter your name" << endl;
		getline(cin,temp);
		fd << temp << ",";
		cout << "Enter your contact number" << endl;
		getline(cin,temp);
		fd << temp << ",";
		cout << "Enter your address" << endl;
		getline(cin,temp);
		fd << temp << ",";
		cout << "Enter your email id" << endl;
		getline(cin,temp);
		fd << temp << ",";
		cout << "Enter your age" << endl;
		cin >> age;
		cin.ignore(250,'\n');
		fd << age << ",";
		cout << "Enter your sex: male/female" << endl;
		getline(cin,temp);
		fd << temp << endl;
		fd.close();
		}
	else{
		cout << "Unable to open file" << endl;
		cout << "Try again next time" << endl;
	}
}

void display(string token){
	char *temp,record[token.length()+1];
	strcpy(record,token.c_str());
	temp = strtok(record,",");
	cout << "Name: " << temp << endl;
	temp = strtok(NULL,",");
	cout << "Contact Number: " << temp << endl;
	temp = strtok(NULL,",");
	cout << "Address: " << temp << endl;
	temp = strtok(NULL,",");
	cout << "Email Id: " << temp << endl;
	temp = strtok(NULL,",");
	cout << "Age: " << temp << endl;
	temp = strtok(NULL,",");
	cout << "Sex: " << temp << endl;
}

void doSearch(string name){
	int i;
	string str;
	bool flag;
	fstream fd("customerdetails.txt",ios::in);
	while(fd){
		getline(fd,str);
		flag=true;
		for(i=0;i<name.length() && str[i]!=',';i++){
			if(str[i]!=name[i]){
				flag=false;
				break;
			}
		}
		if(flag)
			break;
	}
	if(!flag)
		cout << "No Records Found" << endl;
	else
		display(str);
}

int main(){
	int choice;
	string str;
	do{
		choice=showMenu();
		switch (choice){
			case 1:	doRegister(); break;
 			case 2: cout << "Enter your name for search:" << endl;
 					getline(cin,str);
 					doSearch(str); 
 					break;
			default: cout << "Execution Successful" << endl;
					 break;
		};
	}while(choice!=3);	
	return 0;
}
