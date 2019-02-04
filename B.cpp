#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

void doCapitalize(){
	string str;
	fstream fin("input.dat",ios::in);
	fstream fout("output.dat",ios::out);
	if(fin&&fout){
		while(fin){
			getline(fin,str);
			if(str.length()>0){
				if(str[0]>='a'&&str[0]<='z'){
					str[0]-=32;
				}
				fout << str << endl;
			}
		}
	}
	else{
		cout << "Unable to open file" << endl;
		cout << "Try again next time" << endl;
	}
}

int main(){
	doCapitalize();
	return 0;
}