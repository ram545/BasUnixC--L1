#include<iostream>
#include<cstring>
using namespace std;


void doCombinations(string str,int l,int r){
	int i;
	char temp;
	if(l==r)
		cout << str << endl;
	else{
		for(i=l;i<=r;i++){
			temp=str[i];
			str[i]=str[l];
			str[l]=temp;
			doCombinations(str,l+1,r);
			temp=str[i];
			str[i]=str[l];
			str[l]=temp;
		}
	}
}



int main(int argc,char** argv){
	string str;
	if(argc>1){
		str=argv[1];
		doCombinations(str,0,str.length()-1);
	}
	else
		cout << "Expected command line input" << endl;
}