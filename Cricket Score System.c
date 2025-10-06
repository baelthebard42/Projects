#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>


char file[100];
void batswap(int *a, int *b){
    int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
typedef struct datas{
    int bruns; // runs conceded by bowler
    int bballs; // balls thrown by bowler
    int runs; // runs scored by batsman
    int fours;
    int sixes;
    int wick;
    int balls; // balls faced by the batsman
} data;
typedef struct teams{
    char tname[100];
    char name[100];
    int run;
    int wickets;
    data p;
   }t;

  
    int main(){
//HANDLE hz = GetStdHandle ( STD_OUTPUT_HANDLE );
  //WORD wOldColorAttrs;
  //CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
  
  /*
   * First save the current color information
   */
  //GetConsoleScreenBufferInfo(hz, &csbiInfo);
  //wOldColorAttrs = csbiInfo.wAttributes; 
  
  /*
   * Set the new color information
   */
 //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    int s=0,d,e,f,h,a,b,x=0,m=1,j,over=0,ball=0,n=0,nq;
    FILE *ptr;
    char g[25], k[25],l[10],fl[1];
    t *q;
t *r;
q=(struct teams*)malloc(5*sizeof(struct teams));
r=(struct teams*)malloc(5*sizeof(struct teams));
q[0].wickets=0,r[0].wickets=0,q[0].run=0,r[0].run=0;
// initializing all parameters to 0
 for (int c=0; c<5; ++c){
   
     (q+c)->p.runs=0;
     (q+c)->p.fours=0;
     (q+c)->p.sixes=0;
     (q+c)->p.wick=0;
     (q+c)->p.balls=0;
     (q+c)->p.bruns=0;
     (q+c)->p.bballs=0;
     (r+c)->p.runs=0;
     (r+c)->p.fours=0;
     (r+c)->p.sixes=0;
     (r+c)->p.wick=0;
     (r+c)->p.balls=0;
     (r+c)->p.bruns=0;
     (r+c)->p.bballs=0;
 }
 
    printf ("\n\n\n\n");
      
    printf ("                                                             Welcome to Cricket Scoreboard System                \n\n\n\n\n\n\n\n");
     printf ("                        Choose your option (1-4):\n\n\n\n");
     printf("\n\n\n\n");
    printf ("                                                                  1. Record a live match\n\n                                                                  2. Access previous match records\n\n                                                                  3. A random cricket fact to make your day\n\n                                                                  4. Exit ");
    
   label666: printf("\n");
    printf("\n");
    fflush(stdin);
    scanf("%d",&nq);
   if (nq==1){
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    printf ("                                                       ***** Welcome to our Cricket Score Recording System *****                 \n\n\n\n\n\n");
 //SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf("\nEnter the first name of the team that won the toss: \n");
    getchar();

   scanf("%s",g);
   printf ("\n");
 label20: printf("What did they choose?: (Enter 1 for batting, 2 for bowling): \n");
    fflush(stdin);
    scanf("%d",&h);

    if (h!=1 && h!=2){
        printf ("\n Error!! Enter the option correctly.\n");
        goto label20;
    }
    
    
// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf ("\nEnter the first name of the other team: \n");
    getchar();
         fflush(stdin);
    scanf("%s",k);

    if(h==1)
    {
        strcpy(q[0].tname,g);
        strcpy(r[0].tname,k);
    }
    if(h==2)
    {
        strcpy(r[0].tname,g);
        strcpy(q[0].tname,k);
    }
   
    printf ("\n\n");
   //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf ("                                                         Enter the information for team batting first : \n");
    printf ("\n");
    for (int i=0; i<5; ++i){
        printf("Enter the name of player%d: ",i+1);
        getchar();
             fflush(stdin);
        scanf("%s",(q+i)->name);
        
    
       }
       printf("\n\n\n");
      //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf ("                                                         Enter the information for team bowling first : \n");
      printf("\n");
    for (int t=0; t<5; t++){ 
        printf("Enter the name of player%d: ",t+1);
        getchar();
        fflush(stdin);
        scanf("%s",(r+t)->name);
        
         }

         
         printf("\n\n\n");
        //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf ("                                                                Batting team with code number: \n\n");
    for (int a=0; a<5; ++a){
        printf("                                                                 %s : %d \n",(q+a)->name,  s);
        s=s+1;
    }
    s=0;
   //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf ("\n\n\n");
    printf ("                                                                Bowling team with code number: \n\n");
    for (int b=0; b<5; ++b){
        printf("                                                                 %s : %d \n",(r+b)->name, s);
        s=s+1;
    }
   //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    printf ("\nNote: Code number is a unique number assigned to each player to avoid confusion between players of same name as well as to simplify the data entering process. Note each player's code number and enter when asked. \n\n");
    printf("\n\n\n");
   

    printf ("All set to goo!! \n");
    
   
    printf("                                                        ***** Start of the first innings *****\n");
    printf ("\n\n");
   //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    label1: printf ("Enter the code number for batsman on the strike end: \n");
    scanf("%d",&d);
    printf ("Enter the code number for batsman on the runner's end: \n");
    scanf("%d",&e);
    if (d>4 || e>4 ) {
        printf("Error! Enter the right code number.\n");
        goto label1;}
        if(d==e){
            printf("Error! Baka! Can same person be on strike and running end at same time ?  Enter again! ");
            goto label1;
        }
   //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    printf ("                                                            Time to begin the game! \n\n");
    if (h==1){
        printf ("                                                       Team %s won the toss and chose to bat first.\n",g);
    }
    else {
        printf ("                                                       Team %s won the toss and chose to bowl first. \n",g);

    }
    printf ("\n\n");
    printf ("Tutorial: \n1. Enter the options asked carefully. \n2. Wait for the umpire's decision and input accordingly. \n3. Be careful with the code numbers. \n Good luck using our product! \n ");
    printf ("\n\n");
        printf("Enter anything to continue: \n");
        scanf("%d",&h);
        printf ("\n\n");
       //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf ("                                                             %s and %s are the opening batsmen. \n \n",(q+d)->name,(q+e)->name);
    // Start of the five overs game.
    
    for ( m=1; m<=5; ++m){
         
        printf("\n                                                          Over %d: \n\n",m);
        label2: printf("Enter the code number for the bowler: \n");
        fflush(stdin);
    scanf("%d",&f);
    if (f>4){
        printf("Error! Enter the right code number.\n");
        goto label2;
        
    }
    label69: if(x==4){
        if (ball==6){
            over++;
        }
        break;
    }
printf ("\n\n");
//SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf("                                                             %s will bowl over%d\n",(r+f)->name,m);
   //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
            for (  j=1; j<=6; ++j){
                printf ("\n\n\n");
           label3: printf("Ball %d: \n",j);
           label4: printf("Is it a legal delivery? (Enter Y or N): \n");
           fflush(stdin);
            scanf("%c",&l[0]);
            
            if (l[0]=='Y' || l[0]=='y'){
            (r+f)->p.bballs++;
                ball++;
                if(ball==6)
        {
            ball=0;
        }
               label5: printf("Is it run or wicket?: (Enter R or W):\n ");
               fflush(stdin);
                scanf("%c",l+1);
                
                    if (l[1]== 'R' || l[1]== 'r'){
                    label6: printf ("Is it a boundary?: (Y/N)\n");
                    fflush(stdin);
                        scanf("%c",l+2);
                        
                        if (l[2]=='Y' || l[2]=='y'){
    label7:    printf ("Enter 4 if four and 6 if six: \n");
                            fflush(stdin);
                            scanf("%d",&s);
                            
                            if (s==4){
                               q[0].run=q[0].run+4;
                               (q+d)->p.runs=(q+d)->p.runs+4;
                               (q+d)->p.fours=(q+d)->p.fours+1;
                                (q+d)->p.balls= (q+d)->p.balls+1;
                                (r+f)->p.bruns=(r+f)->p.bruns+4;
                            }
                             else if (s==6) {
                               q[0].run=q[0].run+6;
                               (q+d)->p.runs=(q+d)->p.runs+6;
                              (q+d)->p.sixes=(q+d)->p.sixes+1;
                               (q+d)->p.balls= (q+d)->p.balls+1;
                               (r+f)->p.bruns=(r+f)->p.bruns+6;
                            }
                            else {
                                printf ("Error! Enter the given options correctly \n");
                                goto label7;
                            }
                        }
                        else if (l[2]=='n'|| l[2]=='N'){
                            printf ("Enter the runs ran: \n");
                            fflush (stdin);
                            scanf("%d",&s);
                            
                            q[0].run=q[0].run+s;
                            (q+d)->p.runs= (q+d)->p.runs+s;
                             (q+d)->p.balls= (q+d)->p.balls+1;
                             (r+f)->p.bruns=(r+f)->p.bruns+s;
                            //swapping the batsman if 1 or 3 or 5 runs are taken
                            if (s%2 !=0){
                          batswap(&d,&e);
                            }
                            
                        }
                        else {
                            printf("Error! Enter the options correctly. \n");
                            goto label6;
                        }
                    }
                     if (l[1]=='w' || l[1]=='W'){
                        printf ("\nEnter: \n1. B if bowled. \n2. C if caught. \n3. R if runout.\n");
                        fflush(stdin);
                        scanf ("%c",l+3);

                        
                        if (l[3]=='b' || l[3]=='B'){
                            printf ("\nWhat a beauty! %s totally blew off the stumps\n",(r+f)->name);
                            (r+f)->p.wick=(r+f)->p.wick+1;
                            q[0].wickets=q[0].wickets+1;
                            (q+d)->p.balls= (q+d)->p.balls+1;
                                   if(q[0].wickets==4){
                                printf ("\n\nOh no! It's an all out. Pretty sad they didn't last the five overs\n");
                                x=4;
                                goto label69;
                                
                                
                            }
                        
                        }
                        else if (l[3]=='c' || l[3]=='C'){
                            printf ("\nFinally a breakthrough!! What a catch!\n");
                            (q+d)->p.balls= (q+d)->p.balls+1;
                             (r+f)->p.wick=(r+f)->p.wick+1;
                            q[0].wickets=q[0].wickets+1;
                             if(q[0].wickets==4){
                                x=4;
                                printf ("\nOh no! It's an all out. Pretty sad they didn't last the five overs\n");
                                goto label69;
                                
                            }
                            
                            
                        }
                        else if (l[3]=='R' || l[3]=='r'){
                            printf ("\nUnlucky...very unlucky to get run out at a stage like this. \n");
                            printf ("\nEnter the code of the batsman that got out: \n");
                            scanf("%d",&h);
                            if (h==e){
                              batswap (&d,&e);
                            }
                            q[0].wickets=q[0].wickets+1;
                            if(q[0].wickets==4){
                                x=4;
                                printf ("\nOh no! It's an all out. Pretty sad they didn't last the five overs\n");
                                goto label69;
                                
                            }
                         
                             
                         }
                         printf ("\n\n");
                         printf ("Pretty sad to see %s going back to pavilion. Hoping for a comeback in next match. ",(q+d)->name);
                         printf ("\n\n");
                 label8: printf ("Enter the code number for new batsman:\n");
                         fflush(stdin);
                         scanf("%d",&a);
                         
                         if (a==d || a>4){
                             printf ("\nError! Try entering the data again.\n");
                             goto label8;
                         }
                         
                         printf ("\nEnter the code number of the player on strike: \n");
                         fflush(stdin);
                         scanf("%d",&b);
                         
                         if (b==a){
                             d=a; //d is the striker's value. If the new batsman and the one on strike are same, value of e will be unchanged while value of d is changed to code of new batsman.
                         }
                         else {
                             d=b;
                             e=a;

                         }
                         
                         
                        }
                    }
                
                    
                else if (l[0]=='n'|| l[0]=='N'){
              label9: printf("\nEnter the type of illegal delivery: \n1. N for noball. \n2. W for wide. \n3. D for dead ball. ");
                     fflush(stdin);
                    scanf("%c",l+4);
                    
                    s=0;
                    if (l[4]== 'n' || l[4]=='N'){
                        printf("\nEnter the runs scored in no ball: \n");
                        fflush(stdin);
                        scanf("%d",&s);
                        
                        if (s==4){
                            (q+d)->p.fours=(q+d)->p.fours+1;
                        }
                        else if (s==6){
                          (q+d)->p.sixes=(q+d)->p.sixes+1;
                        }
                        (q+d)->p.runs=(q+d)->p.runs+s;
                        (q+d)->p.balls=(q+d)->p.balls+1;
                        if (s%2 !=0){
                            batswap(&d,&e);
                        }
                        q[0].run=q[0].run+1+s;
                        (r+f)->p.bruns=(r+f)->p.bruns+s+1;
                        s=0;
                        printf ("\nIt's a freehit! Dude should hit the ball as far as possible..So exciting!! \n");
                        printf ("\nEnter the runs scored in freehit: \n");
                        scanf("%d",&s);
                        q[0].run=q[0].run+s;
                        (q+d)->p.balls=(q+d)->p.balls+1;
                        (q+d)->p.runs=(q+d)->p.runs+s;
                        (r+f)->p.bruns=(r+f)->p.bruns+s;
                        if (s==4){
                            (q+d)->p.fours=(q+d)->p.fours+1;
                        }
                        else if (s==6){
                          (q+d)->p.sixes=(q+d)->p.sixes+1;
                        }
                         if (s%2 !=0){
                            batswap(&d,&e);
                        }
                        printf ("\nIs it an illegal delivery again? (Y/N): \n");
                        fflush(stdin);
                        scanf("%c",l+5);
                        if (l[5]=='Y' || l[5]=='y'){
                            goto label9;
                        }
                     

                        
                    }
                
                
             else if (l[4]=='w' || l[4]=='W'){
                        q[0].run=q[0].run+1;
                        printf ("\nOh no! He needs to stay on the line. Gotta bowl that again. \n");
                        printf ("\n\n");
                        (r+f)->p.bruns=(r+f)->p.bruns+1;
                        goto label3;
                     }
             else if (l[4]=='d' || l[4]=='D'){
                 printf("\nIt doesn't seems like a professional bowler. Bowl that ball again.\n ");
                        goto label3;
                     }
            }
             else {
                printf ("\nError! Enter correct options!: \n");
                printf ("\n\n");
                goto label4;
             }
            
            
         
        
        printf ("\n\n");
       //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
        printf ("                                                               Team score:");
        printf ("                                                          %d/%d\n",q[0].run,q[0].wickets);
        printf("                                                       %s: %d(%d)\n",(q+d)->name,(q+d)->p.runs,(q+d)->p.balls);
        printf("                                                       %s: %d(%d)\n",(q+e)->name,(q+e)->p.runs,(q+e)->p.balls);
        //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        printf ("                                                      Bowler: %s : %d - %d\n",(r+f)->name,(r+f)->p.wick,(r+f)->p.bruns);
        printf ("\n\n");
        
          
            }
   //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf ("                                                                  End of over%d. \n",m);
    float rr;
        rr=(float)q[0].run/(float)m;
        printf("                                                               Runrate: %.2f\n",rr);
        batswap (&d,&e);
        over++;
    }
    // End of first Inning
   //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf("\n\n\n                                                          ******* End of first inning ******* \n\n\n");
    printf ("\n                                                              %s's batsmen and their strike rate: ",q[0].tname);
    printf ("\n\n\n\n");
    for(int a=0;a<=4;a++){
        if ((q+a)->p.balls != 0){
    printf("%s : %d(%d)\n",(q+a)->name,(q+a)->p.runs,(q+a)->p.balls);
    printf ("       Strike rate: %.2f\n",((float)((q+a)->p.runs)/(float)((q+a)->p.balls))*100);
    printf ("       Fours: %d\n",(q+a)->p.fours);
    printf ("       Sixes: %d\n",(q+a)->p.sixes);
    printf("\n\n");
        }
        }
        printf ("\nDid not bat: ");
        for(a=0;a<=4;a++){
        if ((q+a)->p.balls == 0){
    printf("%s,",(q+a)->name);
    
        }
        }
       //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        printf ("\n\n");
    printf ("                                                               %s's bowlers and their economy: \n",r[0].tname);
        for (a=0; a<=4;a++){
            if ((r+a)->p.bballs>0){
                printf ("       %s: %d - %d\n",(r+a)->name,(r+a)->p.wick,(r+a)->p.bruns);
                printf("        Economy: %.2f",(((float)((r+a)->p.bruns))/(float)((r+a)->p.bballs))*6);
                printf ("\n\n");
            }
        }

   //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf ("\n\n");
    printf("                                                                                Total runs : %d/%d\n",q[0].run,q[0].wickets);
    printf("                                                                              Overs played= %d.%d\n",over,ball);
    
    printf("                                                                        Target for Team %s: %d in 5 overs.\n",r[0].tname,q[0].run+1);
    
    
    float runrate =(float)q[0].run/(float)(m+6/10*ball);
    float required_runrate= (float)(q[0].run+1)/5.0;
    printf("                                                                                    Runrate=%.2f",runrate);
    printf("                                                                            Require runrate=%.2f",required_runrate);



printf ("\n\n\n\n\n");
//beginning of second innings
//SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
printf ("                                                                               ***** Start of the second innings *****\n\n");
    label21: printf ("Enter the code number for batsman on the strike end: \n");
    scanf("%d",&d);
    printf ("Enter the code number for batsman on the runner's end: \n");
    scanf("%d",&e);
    if (d>4 || e>4 ) {
        printf("Error! Enter the right code number.\n");
        goto label21;}
        if(d==e){
            printf("\nError! Baka! Can same person be on strike and running end at same time ?  Enter again! \n");
            goto label21;
        }
   //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    printf ("                                                                                   Time to begin the game! \n\n");
  
    
    printf ("\n\n");
        printf("Enter anything to continue: \n");
        scanf("%d",&h);
        printf ("\n\n");
       //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf ("                                                                                              %s and %s are the opening batsmen. \n \n",(r+d)->name,(r+e)->name);
   //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    // Start of the five overs game.
    over=0;
    for ( m=1; m<=5; ++m){
        printf ("\n");
        printf("\n                                                                                          Over %d: \n\n",m);
        label23: printf("Enter the code number for the bowler: \n");
        fflush(stdin);
    scanf("%d",&f);
    if (f>4){
        printf("Error! Enter the right code number.\n");
        goto label23;
        
    }
    x=0,ball=0;
    label42: if(x==4){
        if (ball==6){
            over++;
        }
        break;
    }
printf ("\n\n");
    printf("                                                                                             %s will bowl over%d\n",(q+f)->name,m);
            for (  j=1; j<=6; ++j){
                printf ("\n\n\n");
                
           label33: printf("Ball %d: \n",j);
           label34: printf("Is it a legal delivery? (Enter Y or N): \n");

           fflush(stdin);
            scanf("%c",&l[0]);
            
            if (l[0]=='Y' || l[0]=='y'){
                n=n+1;
               (q+f)->p.bballs=(q+f)->p.bballs+1;
                ball++;
                if(ball==6)
        {
            ball=0;
        }
               label35: printf("Is it run or wicket?: (Enter R or W):\n ");
               fflush(stdin);
                scanf("%c",l+1);
                
                    if (l[1]== 'R' || l[1]== 'r'){
                       
                    label36: printf ("Is it a boundary?: (Y/N)\n");
                    fflush(stdin);
                        scanf("%c",l+2);
                        
                        if (l[2]=='Y' || l[2]=='y'){
    label37:    printf ("Enter 4 if four and 6 if six: \n");
                            fflush(stdin);
                            scanf("%d",&s);
                            
                            if (s==4){
                               r[0].run=r[0].run+4;
                               (r+d)->p.runs=(r+d)->p.runs+4;
                               (r+d)->p.fours=(r+d)->p.fours+1;
                                (r+d)->p.balls= (r+d)->p.balls+1;
                                (q+f)->p.bruns=(q+f)->p.bruns+4;
                                if (r[0].run>q[0].run){
                                   //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                            printf ("\n\n                               Required target achieved!! What a beautiful display of batting!!\n");
                            x=4;
                            goto label42;
                        }
                            }
                             else if (s==6) {
                               r[0].run=r[0].run+6;
                               (r+d)->p.runs=(r+d)->p.runs+6;
                              (r+d)->p.sixes=(r+d)->p.sixes+1;
                               (r+d)->p.balls= (r+d)->p.balls+1;
                               (q+f)->p.bruns=(q+f)->p.bruns+6;
                               if (r[0].run>q[0].run){
                               //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                            printf ("\n\n                                Required target achieved!! What a beautiful display of batting!!\n");
                            x=4;
                            goto label42;
                        }
                            }
                            else {
                                printf ("Error! Enter the given options correctly \n");
                                goto label37;
                            }
                        }
                        else if (l[2]=='n'|| l[2]=='N'){
                            printf ("Enter the runs ran: \n");
                            fflush (stdin);
                            scanf("%d",&s);
                            
                            r[0].run=r[0].run+s;
                            (r+d)->p.runs= (r+d)->p.runs+s;
                             (r+d)->p.balls= (r+d)->p.balls+1;
                             (q+f)->p.bruns=(q+f)->p.bruns+s;
                             if (r[0].run>q[0].run){
                               //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                            printf ("\n\n                                 Required target achieved!! What a beautiful display of batting!!\n");
                            x=4;
                            goto label42;
                        }
                            //swapping the batsman if 1 or 3 or 5 runs are taken
                            if (s%2 !=0){
                          batswap(&d,&e);
                            }
                            
                        }
                         
                        else {
                            printf("Error! Enter the options correctly. \n");
                            goto label36;
                        }
                    }
                     if (l[1]=='w' || l[1]=='W'){
                        printf ("\nEnter: \n1. B if bowled. \n2. C if caught. \n3. R if runout.\n");
                        fflush(stdin);
                        scanf ("%c",l+3);

                        
                        if (l[3]=='b' || l[3]=='B'){
                            printf ("\nWhat a beauty! %s totally blew off the stumps\n",(r+f)->name);
                            (q+f)->p.wick=(q+f)->p.wick+1;
                            r[0].wickets=r[0].wickets+1;
                            (r+d)->p.balls= (r+d)->p.balls+1;
                                   if(r[0].wickets==4){
                                printf ("\n\nOh no! It's an all out. Pretty sad they didn't last the five overs\n");
                                x=4;
                                goto label42;
                                
                                
                            }
                        
                        }
                        else if (l[3]=='c' || l[3]=='C'){
                            printf ("\nFinally a breakthrough!! What a catch!\n");
                            (r+d)->p.balls= (r+d)->p.balls+1;
                             (q+f)->p.wick=(q+f)->p.wick+1;
                            r[0].wickets=r[0].wickets+1;
                             if(r[0].wickets==4){
                                x=4;
                                printf ("\nOh no! It's an all out. Pretty sad they didn't last the five overs\n");
                                goto label42;
                                
                            }
                            
                            
                        }
                        else if (l[3]=='R' || l[3]=='r'){
                            printf ("\nUnlucky...very unlucky to get run out at a stage like this. \n");
                            printf ("\nEnter the code of the batsman that got out: \n");
                            scanf("%d",&h);
                            if (h==e){
                              batswap (&d,&e);
                            }
                            r[0].wickets=r[0].wickets+1;
                            if(r[0].wickets==4){
                                x=4;
                                printf ("\nOh no! It's an all out. Pretty sad they didn't last the five overs\n");
                                goto label42;
                                
                            }
                         
                             
                         }
                         printf ("\n\n");
                         printf ("Pretty sad to see %s going back to pavilion. Hoping for a comeback in next match. ",(r+d)->name);
                         printf ("\n\n");
                 label38: printf ("Enter the code number for new batsman:\n");
                         fflush(stdin);
                         scanf("%d",&a);
                         
                         if (a==d || a>4){
                             printf ("Error! Try entering the data again.\n");
                             goto label38;
                         }
                         
                         printf ("\nEnter the code number of the player on strike: \n");
                         fflush(stdin);
                         scanf("%d",&b);
                         
                         if (b==a){
                             d=a; //d is the striker's value. If the new batsman and the one on strike are same, value of e will be unchanged while value of d is changed to code of new batsman.
                         }
                         else {
                             d=b;
                             e=a;

                         }
                         
                         
                        }
                    }
                
                    
                else if (l[0]=='n'|| l[0]=='N'){
              label39: printf("Enter the type of illegal delivery: \n1. N for noball. \n2. W for wide. \n3. D for dead ball. ");
                     fflush(stdin);
                    scanf("%c",l+4);
                    
                    s=0;
                    if (l[4]== 'n' || l[4]=='N'){
                        printf("Enter the runs scored in no ball: \n");
                        fflush(stdin);
                        scanf("%d",&s);
                        
                        if (s==4){
                            (r+d)->p.fours=(r+d)->p.fours+1;
                        }
                        else if (s==6){
                          (r+d)->p.sixes=(r+d)->p.sixes+1;
                        }
                        (r+d)->p.runs=(r+d)->p.runs+s;
                        (r+d)->p.balls=(r+d)->p.balls+1;
                        if (s%2 !=0){
                            batswap(&d,&e);
                        }
                        r[0].run=r[0].run+1+s;
                        (q+f)->p.bruns=(q+f)->p.bruns+s+1;
                        s=0;
                        printf ("\nIt's a freehit! Dude should hit the ball as far as possible..So exciting!! \n");
                        printf ("\nEnter the runs scored in freehit: \n");
                        scanf("%d",&s);
                        r[0].run=r[0].run+s;
                        (r+d)->p.balls=(r+d)->p.balls+1;
                        (r+d)->p.runs=(r+d)->p.runs+s;
                        (q+f)->p.bruns=(q+f)->p.bruns+s;
                        if (s==4){
                            (r+d)->p.fours=(r+d)->p.fours+1;
                        }
                        else if (s==6){
                          (r+d)->p.sixes=(r+d)->p.sixes+1;
                        }
                         if (s%2 !=0){
                            batswap(&d,&e);
                        }
                        printf ("\n\nIs it an illegal delivery again? (Y/N): \n\n");
                        fflush(stdin);
                        scanf("%c",l+5);
                        if (l[5]=='Y' || l[5]=='y'){
                            goto label39;
                        }
                     

                        
                    }
                
                
             else if (l[4]=='w' || l[4]=='W'){
                        r[0].run=r[0].run+1;
                        printf ("\nOh no! He needs to stay on the line. Gotta bowl that again. \n");
                        printf ("\n\n");
                        (q+f)->p.bruns=(q+f)->p.bruns+1;
                        goto label33;
                     }
             else if (l[4]=='d' || l[4]=='D'){
                 printf("\nIt doesn't seems like a professional bowler. Bowl that ball again.\n ");
                        goto label33;
                     }
            }
             else {
                printf ("\nError! Enter correct options!: \n");
                printf ("\n\n");
                goto label34;
             }
            
            
         
        
        printf ("\n\n");
       //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        printf ("                                                                   Team score:");
        printf ("                                                              %d/%d\n",r[0].run,r[0].wickets);
        printf("                                                                    %s: %d(%d)\n",(r+d)->name,(r+d)->p.runs,(r+d)->p.balls);
        printf("                                                                    %s: %d(%d)\n",(r+e)->name,(r+e)->p.runs,(r+e)->p.balls);
       //// SetConsoleTextAttribute ( hz, FOREGROUND_RED | FOREGROUND_INTENSITY );
        printf ("                                                                   Bowler: %s : %d - %d\n",(q+f)->name,(q+f)->p.wick,(q+f)->p.bruns);
       //// SetConsoleTextAttribute ( hz, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        printf ("\n                                                                 To win: %d in %d balls: \n",q[0].run+1-r[0].run,30-n);
        printf ("\n\n");
        
          
            }
   //// SetConsoleTextAttribute ( hz, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf ("                                                                       End of over%d. \n",m);
    float rr;
        rr=(float)r[0].run/(float)m;
        printf("                                                                    Runrate: %.2f\n",rr);
        printf("\n                                                                  Required runrate: %.2f",(float)(q[0].run+1-r[0].run)/(float)(5-m));
        batswap (&d,&e);
        over++;
    }
    // End of second Inning
    printf("\n\n\n                                                        ******* End of second inning ******* \n\n\n");
    printf ("                                                              %s's batsmen and their strike rate ",r[0].tname);
    printf("\n\n\n\n");
    for(int a=0;a<=4;a++){
        if ((r+a)->p.balls != 0){
    printf("%s : %d(%d)\n",(r+a)->name,(r+a)->p.runs,(r+a)->p.balls);
    printf ("Strike rate: %.2f\n",((float)((r+a)->p.runs)/(float)((r+a)->p.balls))*100);
    printf ("Fours: %d\n",(r+a)->p.fours);
    printf ("Sixes: %d\n",(r+a)->p.sixes);
    printf("\n\n");
        }
        }
        printf ("\nDid not bat: ");
        for(a=0;a<=4;a++){
        if ((r+a)->p.balls ==0){
    printf("%s,",(r+a)->name);
    
        }
        }
        printf ("\n");
        printf ("                                               %s's bowlers and their economy: \n",q[0].tname);
        printf("\n\n\n\n");
        for (a=0; a<=4;a++){
            if ((q+a)->p.bballs>0){
                printf ("%s: %d - %d\n",(q+a)->name,(q+a)->p.wick,(q+a)->p.bruns);
                printf("Economy: %.2f",(((float)((q+a)->p.bruns))/(float)((q+a)->p.bballs))*6);
                printf ("\n\n");
            }
        }

    
    printf ("\n\n");
    printf("Total runs : %d/%d\n",r[0].run,r[0].wickets);
    printf("Overs played= %d.%d\n",over,ball);

    printf("\n\n\n\n\n\n");
    printf("                                                       ********** Match Result **********");
    printf("\n\n\n\n");
    if (q[0].run>r[0].run){
        printf ("Congratulations!! What a marvelous display of bowling from %s\n\n\n",q[0].tname);
        printf("                                                  %s won by %d runs\n\n\n",q[0].tname,q[0].run-r[0].run);

    }
    else if(r[0].run>q[0].run){
        
        printf("                                                  %s won by %d wicket\n\n\n",r[0].tname,4-r[0].wickets);
        printf ("       Congratulations!! What a marvelous display of batting from %s\n\n\n",r[0].tname);
    }
    else{
        
        printf("        Damn! What a thriller! It's a tie!! Wonder who draws the blood if they fight again.\n");
    }
    printf ("\n\n");
    printf ("                                                       Do you want to save this match? (Y/N) :\n");
    fflush(stdin);
    scanf("%c",&fl[0]);
    
    if (fl[0]=='Y' || fl[0]=='y'){
        printf ("\n\nEnter the name of the file: \n");
        fflush(stdin);
        gets(file);
     ptr= fopen(file,"w");
     if (ptr!=NULL){
         //fprintf(ptr,"%s %s ",bat,bowl);
        // fprintf(ptr,"%d,%d,%d,%d ",q[0].run,q[0].wickets,r[0].run,r[0].wickets);
         //for (int i=0; i<5; ++i){
             //fprintf(ptr,"%s %d %d %d %d %d %d %d ",(q+i)->name,(q+i)->p.runs,(q+i)->p.balls,(q+i)->p.fours,(q+i)->p.sixes,(q+i)->p.wick,(q+i)->p.bruns,(q+i)->p.bballs);
         //}
         //for (int i=0; i<5; ++i){
             //fprintf(ptr,"%s %d %d %d %d %d %d %d ",(r+i)->name,(r+i)->p.runs,(r+i)->p.balls,(r+i)->p.fours,(r+i)->p.sixes,(r+i)->p.wick,(r+i)->p.bruns,(r+i)->p.bballs);
            for (int zn=0;zn<4;zn++){
           fwrite(&q[zn],sizeof(struct teams),1,ptr);    
            }
            for (int zn=0;zn<4;zn++){
           fwrite(&q[zn].p,sizeof(struct teams),1,ptr);    
            }
            for (int zn=0;zn<4;zn++){
           fwrite(&r[zn],sizeof(struct teams),1,ptr);    
            }
            for (int zn=0;zn<4;zn++){
           fwrite(&r[zn].p,sizeof(struct teams),1,ptr);    
            }
         printf("\n\n");
         printf ("Match sucessfully saved! \n\nVisit our 'Access Previous Match Records' section in menu to access the match's records. \n\n Thank you for using our product! We hope you keep coming back!! ");
         fclose(ptr);
         
     }
         
     }

    }
    
    
   

    
else if (nq==2){
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    printf("                                            ***** Welcome to our Cricket Score Accessing System *****                 ");
    printf("\n\n\n\n\n\n\n\n");
    printf("Enter the name of the file you want to access: \n\n");
    fflush(stdin);
    gets(file);
    ptr=fopen(file,"r");
    
        // fscanf(ptr,"%d,%d,%d,%d ",q[0].run,q[0].wickets,r[0].run,r[0].wickets);
        // for (int i=0; i<5; ++i){
            // fscanf(ptr,"%s %d %d %d %d %d %d %d ",(q+i)->name,(q+i)->p.runs,(q+i)->p.balls,(q+i)->p.fours,(q+i)->p.sixes,(q+i)->p.wick,(q+i)->p.bruns,(q+i)->p.bballs);
            // fread ((q+i)->name,sizeof((q+i)->name),1,ptr);
            // fread ((q+i)->p.runs,sizeof((q+i)->p.runs),1,ptr);
        // }
        // for (int i=0; i<5; ++i){
         //    fscanf(ptr,"%s %d %d %d %d %d %d %d ",(r+i)->name,(r+i)->p.runs,(r+i)->p.balls,(r+i)->p.fours,(r+i)->p.sixes,(r+i)->p.wick,(r+i)->p.bruns,(r+i)->p.bballs);
         //}
         for (int zn=0;zn<4;zn++){
           fread(&q[zn],sizeof(struct teams),1,ptr);    
            }
         for (int zn=0;zn<4;zn++){
           fread(&q[zn].p,sizeof(struct teams),1,ptr);    
            }
            for (int zn=0;zn<4;zn++){
           fread(&r[zn],sizeof(struct teams),1,ptr);    
            }
            
            for (int zn=0;zn<4;zn++){
           fread(&r[zn].p,sizeof(struct teams),1,ptr);    
            }
           
        
         printf ("\n                                                %s's batsmen and their strike rate: ",q[0].tname);
    printf ("\n\n\n\n");
    for(int a=0;a<=4;a++){
        if ((q+a)->p.balls != 0){
    printf("%s : %d(%d)\n",(q+a)->name,(q+a)->p.runs,(q+a)->p.balls);
    printf ("Strike rate: %.2f\n",((float)((q+a)->p.runs)/(float)((q+a)->p.balls))*100);
    printf ("Fours: %d\n",(q+a)->p.fours);
    printf ("Sixes: %d\n",(q+a)->p.sixes);
    printf("\n\n");
        }
        }
        printf ("\nDid not bat: ");
        for(a=0;a<=4;a++){
        if ((q+a)->p.balls == 0){
    printf("%s,",(q+a)->name);
    
        }
        }
        printf ("\n\n");
         printf ("\n");
        printf ("                                                 %s's bowlers and their economy: \n",q[0].tname);
        printf("\n\n\n\n");
        for (a=0; a<=4;a++){
            if ((q+a)->p.bballs>0){
                printf ("%s: %d - %d\n",(q+a)->name,(q+a)->p.wick,(q+a)->p.bruns);
                printf("Economy: %.2f",(((float)((q+a)->p.bruns))/(float)((q+a)->p.bballs))*6);
                printf ("\n\n");
            }
        }

         
    printf ("\n\n");
   
        
    printf ("                                                           %s's bowlers and their economy: \n",r[0].tname);
        for (a=0; a<=4;a++){
            if ((r+a)->p.bballs>0){
                printf ("%s: %d - %d\n",(r+a)->name,(r+a)->p.wick,(r+a)->p.bruns);
                printf("Economy: %.2f",(((float)((r+a)->p.bruns))/(float)((r+a)->p.bballs))*6);
                printf ("\n\n");
            }
        }

           printf ("                                                   %s's batsmen and their strike rate ",r[0].tname);
    printf("\n\n\n\n");
    for(int a=0;a<=4;a++){
        if ((r+a)->p.balls != 0){
    printf("%s : %d(%d)\n",(r+a)->name,(r+a)->p.runs,(r+a)->p.balls);
    printf ("Strike rate: %.2f\n",((float)((r+a)->p.runs)/(float)((r+a)->p.balls))*100);
    printf ("Fours: %d\n",(r+a)->p.fours);
    printf ("Sixes: %d\n",(r+a)->p.sixes);
    printf("\n\n");
        }
        }
        printf ("\nDid not bat: ");
        for(a=0;a<=4;a++){
        if ((r+a)->p.balls ==0){
    printf("%s,",(r+a)->name);
    
        }
        }
       
    printf("Total runs : %d/%d\n",r[0].run,r[0].wickets);
    

    printf("\n\n\n\n\n\n");
    printf("                                            ********** Match Result **********");
    printf("\n\n\n\n");
    if (q[0].run>r[0].run){
        
        printf("                                                  %s won by %d runs\n\n\n",q[0].tname,q[0].run-r[0].run);

    }
    else if(r[0].run>q[0].run){
        
        printf("                                                  %s won by %d wicket\n\n\n",r[0].tname,4-r[0].wickets);
    }
    else{
        
        printf("It was a tie.\n");
    }
fclose(ptr);
         
   

    }

else if (nq==3){
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf ("Hmm let's see what lucky fact you get!!\n\n\n");
    
    printf ("                                                       Did you know that \n");
     int nn;
   srand(time(NULL));
    nn = rand() % 10;

if (nn==0){
        printf ("Virat Kohli once took a wicket off o balls? \n\n  Yeah he did! Apart from the magical batting, he once took Kevin Pieterson's wicket off 0 balls in a wide-ball stumping.");
    }
    else if (nn==1){
        printf ("Indian batsman Suresh Raina scored 2 T20 centuries on the same date but different years!! WHHAAAAAAT?");
    }
    else if (nn==2){
        printf("Sir Donald Bradman, the Don is the only batsman to get out on 299. SAAAD!");
    }
    else if (nn==3){
        printf ("Sir Vivian Richards is the only player to have played both Cricket and Football Worldcups! Damnnnnnn");
    }
    else if (nn==4){
        printf ("the only rule of cricket that hasn't been changed since it's origin is the LENGTH OF IT'S PITCH!! Do you know how much is it");
    }
    else if (nn==5){
        printf ("when Shahid Afridi scored the fastest ODI century in 37 balls against Sri Lanka in 1996, he used Sachin, the Master Blaster's bat! Crazyyyyy right?");

    }
    else if (nn==6){
        printf ("there are some ex-cricketer commentators out there who never played T20 cricket? Huhuhahaha ever gave it a thought?");
    }
    else if (nn==7){
        printf ("the longest cricket match was played for 12 days?? Yup it happened, between England and South Africa in 1939 and guess what? THEY STILL COULDN'T CONCLUDE A WINNER! SIKEEEEE");
    }
    else if(nn==8){
        printf("English Cricketer Alec Stewart was born on 8-4-63 and he scored 8463 Test runs..coincidences....");
    }
    else if (nn==9){
        printf("Sachin Tendulkar played for Pakistan before playing for India? Yeah you heard that right! He substituted as a fielder for Pakistan in the India - Pakistan match on his debut for India due to injured players in Pakistan");
    }
    else{
        printf("Donald Bradman, the legend..hit only...only 6 sixes in his ENTIRE CAREER! ");
    }
   
    
    
}
else if (nq==4){
    
}
else {

    printf ("\n\n\n                                     Error! Enter the options correctly!!\n\n\n");
    goto label666;
}
    }
    
