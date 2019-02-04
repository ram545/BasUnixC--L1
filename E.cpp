#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

void getData(){
	string str,fname,lname,email;
	cout << "Enter the file name: " << endl;
	getline(cin,str);
	fstream file(str,ios::in | ios::out | ios::trunc);
	if(file){
		cout << "Enter your first name" << endl;
		getline(cin,fname);
		cout << "Enter your last name" << endl;
		getline(cin,lname);
		cout << "Enter your email id" << endl; 
		getline(cin,email);
		file << fname << "," << lname << "," << email << endl;
		file.close();
	}
	else{
		cout << "File not created successfully" << endl;
		cout << "Try again next time" << endl;
	}	
}

int main(){
	getData();
	return 0;
}