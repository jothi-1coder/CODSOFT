#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (){
    int randnum;
    int guessnum;
    int tries;
    srand(time(NULL));
    randnum=rand() % 100 + 1;
    cout<<"$$$$$*** WELCOME TO NUMBER GUSSING GAME ***$$$$$"<<endl;
    
    do{
        cout<<"Enter your guessed number from 1-100:";
        cin>>guessnum;
        if(guessnum > randnum){
            cout<<"Your Guess is too High Keep on guessing"<<endl;
        }
        else if(guessnum < randnum){
            cout<<"Your Guess is too Low Keep on guessing"<<endl;
        }
        else{
            cout<<"Your Guess is correct!"<<endl;
        }
    }while(guessnum!=randnum);

    return 0;
}
