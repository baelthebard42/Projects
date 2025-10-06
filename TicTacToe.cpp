#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
char XOXO[3][3], weaponPla, weaponComp;
int count1=0,count2=0, flag=0,horAdd,vertAdd;
HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);                                          
COORD Position;

void gotoxy(int x, int y){      //setting coordinates
    Position.X=x;
    Position.Y=y;
    SetConsoleCursorPosition(console, Position);
}

void drawLines(void){   //uses loop to draw the tic tac toe hash
for (int i=15; i<25; ++i){
    gotoxy(102,i);cout<<"|"; //vertical lines
    gotoxy(108,i);cout<<"|";
}
for (int i=96; i<115; ++i){
    gotoxy(i,18);cout<<"-"; //horizonal lines
    gotoxy(i,21);cout<<"-";
}
int point1=16, point2=99;
for (int i=0; i<3; ++i){
    gotoxy(96,point1); cout<<i; //prints the vertical and horizontal line numbers
    gotoxy(point2,14); cout<<i;
    point1=point1+3;
    point2=point2+6;
}
gotoxy(85,27);cout<<"(HORIZONAL LINE NUMBERS)"; 
gotoxy(118,14);cout<<"(VERTICAL LINE NUMBERS)";
}

int drawXOXO(void){ // Draws the X and O as per the address entered by the user
if (horAdd==0 && vertAdd==0){
    gotoxy(99,17);
}
else if(horAdd==0 && vertAdd==1){
    gotoxy(105,17);
}
else if(horAdd==0 && vertAdd==2){
    gotoxy(111, 17);
}
else if(horAdd==1 && vertAdd==0){
    gotoxy(99,19);
}
else if(horAdd==1 && vertAdd==1){
    gotoxy(105,19);
}
else if(horAdd==1 && vertAdd==2){
    gotoxy(111,19);
}
else if(horAdd==2 && vertAdd==0){
    gotoxy(99,22);
}
else if(horAdd==2 && vertAdd==1){
    gotoxy(105,22);
}
else if(horAdd==2 && vertAdd==2){
    gotoxy(111,22);
}
else{
    return 1;
}
cout<<XOXO[horAdd][vertAdd];
return 0;
}

int check(){ //checks and returns 1 if either side has won
   count1=0,count2=0;
   
    for (int i=0; i<3; ++i){ 
        for (int j=0; j<3; ++j){
            if (i!=j && XOXO[i][i]==XOXO[i][j] && XOXO[i][i]!='@'){ //checks condition for horizontal triads
                count1++;
                if (count1==2){
                  return 1;
                }
            }
             if (i!=j && XOXO[i][i]==XOXO[j][i] && XOXO[i][i]!='@'){ //checks condition for vertical triads
                count2++;
                 if (count2==2){
                    return 1;
                }
            }
        }
        count1=0,count2=0;
    }
     if(XOXO[1][1]!='@' && XOXO[1][1]==XOXO[2][2] && XOXO[1][1]==XOXO[0][0]){ //checks condition for criss cross triads
       
        return 1;
    }
    else if (XOXO[1][1]!='@' && XOXO[1][1]==XOXO[0][2] && XOXO[1][1]==XOXO[2][0]){
        
        return 1;
    }
    else{
        for (int i=0; i<3; ++i){ //checks if all spaces are filled or not. 
            for (int j=0; j<3; ++j){
                if (XOXO[i][j]=='@'){
                    flag++;
                }
            }
        }
        if (flag==0){
            gotoxy(100,30);cout<<"OUCH!! I'm afraid it's a draw.......";
            return 1;
        }
        return 0;
    }
}
void userPlay(void){
    label2: gotoxy(0,30);cout<<"Enter the vertical line number then horizonal line number: "<<endl;
cin>>vertAdd>>horAdd;
if (XOXO[horAdd][vertAdd]!='@'){
    cout<<endl<<"Sorry the spot is already ticked. Choose a different spot!: "<<endl;
    goto label2;
}
XOXO[horAdd][vertAdd]=weaponPla;
drawXOXO();
if (drawXOXO()==1){
    gotoxy(0,30);cout<<"Enter given options correctly !!";
    goto label2;
}
}

void compPlay(void){
    int count3=0,flag=0,k;
    do{
    srand(unsigned(time(NULL)));
    horAdd=rand()%3;
    vertAdd=rand()%3;
    }while(XOXO[horAdd][vertAdd]!='@');
   
XOXO[horAdd][vertAdd]=weaponComp;
drawXOXO();
}

int main(){
    gotoxy(95,5);cout<<"WELCOME TO TIC TAC TOE";
    drawLines();
    for (int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            XOXO[i][j]='@';
        }
    }
    label1: gotoxy(0,26);cout<<"Please choose your weapon (O or X): "<<endl;
cin>>weaponPla;
if (weaponPla=='X' || weaponPla=='x'){
    weaponComp='O';
}
else if(weaponPla=='o' || weaponPla=='O'){
    weaponComp='X';
}
else{
    gotoxy(0,27);cout<<"Please enter the options as X or O only! ";
    goto label1;
}
    while(true){
 userPlay(); 
 if (check()==1){
    gotoxy(100,30); cout<<"YOU WONN!!";
    break;
 }
 Sleep(2000);
 compPlay();  
 if (check()==1){
    gotoxy(100,30); cout<<"COMPUTER WONN!!!";
    break;
 }
    }  
    getch();
}