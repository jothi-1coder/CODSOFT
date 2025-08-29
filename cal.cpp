#include <iostream>
using namespace std;

int main() {
	double num1;
	double num2;
	cout<<"*** Basic Calculator ***"<<endl;
	cout<<"Enter the number :";
	cin>>num1;
	cout<<"Operation you want to do\n1.Enter 1 for addition\n2.Enter 2 for subraction\n3.Enter 3 for mulitiplication\n4.Enter 4 for division"<<endl;
	int choice;
	cout<<"Enter your choice:";
	cin>>choice;
	cout<<"Enter the number:";
	cin>>num2;
	switch(choice){
		case 1:
			double a;
			a=num1+num2;
			cout<<"The addition of two number:"<<a<<endl;
			break;
		case 2:
			double b;
			b=num1-num2;
			cout<<"The subraction of two number:"<<b<<endl;
			break;
		case 3:
			double c;
			c=num1*num2;
			cout<<"The mulitiplication of two number:"<<c<<endl;
			break;
		case 4:
			double d;
			d=num1/num2;
			cout<<"The division of two number:"<<d<<endl;
			break;
		default:
			cout<<"Invalied choice"<<endl;
			break;
		}
		
    return 0;
}
