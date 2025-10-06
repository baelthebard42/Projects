#include<iostream>                                                                 
#include<windows.h>                                                                                                                      
#include<conio.h>    
#include<ctime>                                                                                         
using namespace std;                                                                       
HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);                                          
COORD Position;
void gotoxy(int x, int y){
    Position.X=x;
    Position.Y=y;
    SetConsoleCursorPosition(console, Position);
}
void ScoreBoard(int Comp, int User){
  gotoxy(100,12); cout<<"SCORE BOARD: ";
  gotoxy(99, 13); cout<<"Player's Score: "<<User<<endl;
  gotoxy(99,14); cout<<"Computer's Score: "<<Comp<<endl;
}
int main(){
    int CompScore=0, UserScore=0,k=1,a,b,z=31;
   gotoxy(90,0);cout<<"Welcome to Rock, Paper and Scissors with this laptop";
   gotoxy(100,25); cout<<"Choose your champion: ";
  gotoxy(106,26); cout<<"1. Rock";
  gotoxy(106,27); cout<<"2. Paper";                                                                       
  gotoxy(106,28); cout<<"3. Scissors";
   gotoxy(0,30); cout<<"Enter 1 for Rock and so on: "<<endl;
 label1:   while(1){
  
label: cout<<"Round "<<k<<":"<<" Enter your bet: "<<endl;
      cin>>a;
      srand( (unsigned)time( NULL ) );
      do{
      b=rand()%4;
      }while(b==0);
      
      if (a==1 && b==1){
        cout<<"You've chosen Rock and your opponent's chosen Rock too! Both get a point each!!"<<endl;
        CompScore++;
        UserScore++;
      }
      else if (a==1 && b==2){
        cout<<"You've chosen Rock and your opponent's chosen Paper! You got wrapped ahahaha!!"<<endl;
        CompScore++;
      }
      else if (a==1 && b==3){
        cout<<"You've chosen Rock and your opponent's chosen Scissors! You cracked the scissor ahahah !!"<<endl;
        UserScore++;
      }
      else if (a==2 && b==1){
        cout<<"You've chosen Paper and your opponent's chosen Rock! Laptop got wrapped ahahaha!!"<<endl;
        UserScore++;
      }
      else if (a==2 && b==2){
        cout<<"You've chosen Paper and your opponent's chosen Paper! Seems you both love peace!!"<<endl;
        UserScore++;
        CompScore++;
      }
      else if (a==2 && b==3){
        cout<<"You've chosen Paper and your opponent's chosen Scissors! YOU ARE DOOMED!!"<<endl;
        CompScore++;
      }
      else if (a==3 && b==1){
        cout<<"You've chosen Scissors and your opponent's chosen Rock! Get ready to be broken"<<endl;
        CompScore++;
      }
      else if (a==3 && b==2){
        cout<<"You've chosen Scissors and your opponent's chosen Paper! CUT THAT LITTLE SHIT"<<endl;
        UserScore++;
      }
      else if (a==3 && b==3){
        cout<<"You've chosen Scissors and your opponent's chosen Scissors! Kinda sus!!"<<endl;
        CompScore++;
        UserScore++;
      }
      else{
        cout<<"Enter options correctly dickhead!"<<endl;
        goto label;
      }
      ScoreBoard(CompScore,UserScore);
      z=z+3;
      gotoxy(0,z);
     if(CompScore==3 || UserScore==3){
      break;
     }

     k++;
     
    }
    if(UserScore>CompScore){
        cout<<"YOU WIN!!!";
                                                                                      
    }
    else if(CompScore>UserScore){
        cout<<"YOU LOSEEE!";
    }
    else{
        cout<<"It's a tie! You are going to fight agaiin!!"<<endl;
        CompScore=UserScore=0;
        k=1;
        goto label1;
        
    }
    getch();
   
}