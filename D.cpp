#include<iostream>
#include<cstring>
using namespace std;

void promptNumber(){
	int a[10000]={0},i=0,j=0,len,small=INT32_MAX,large=INT32_MIN,sum=0,tem;
	float avg;
	string str;
	do{
		cin >> str;
		if(str[0]>='0' && str[0]<='9'){
			for(i=0;i<str.length();i++){
				tem = str[i]-'0';
				a[j] = a[j]*10+tem;
			}
			j++;
		}
	}while(str[0]>='0' && str[0]<='9');
	if(str=="quit"){
		len=j;
		if(j==0){
			cout << "No Numbers Entered" << endl;
		}
		else{
			cout << large << " " << small << endl;
			for(i=0;i<len;i++){
				if(a[i]>large)
					large=a[i];
				if(a[i]<small)
					small=a[i];
				sum+=a[i];
			}
			avg=sum/len;
			cout << "Elements of the Array :" << endl;
			for(i=0;i<len;i++)
				cout << a[i] << " ";
			cout << endl;
			cout << "Total number of elements in array :" << len << endl;
			cout << "Sum of all elements: " << sum << endl;
			cout << "Average of all elements: " << avg << endl;
			cout << "Largest: " << large << "   " << "Smallest: " << small << endl;
		}
	}
	else{
		cout << "Quit instruction not recieved!!" << endl;
		cout << "Try again next time" << endl;
	}
}

int main(){
	promptNumber();
	return 0;
}