//Author SK AHIDULLA THU,27,OCTOBER,2022
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
void structure(void); //square shape 
void input(void); //take input 
void point(void); // count score 
void flow(void); //flow of fruit 
void border(void); //out
int x=18,y=10;
char ch;
int rand1,rand2,rand3,rand4 ;
int score ,fl1=3,fl2=4,fl3=3,fl4=4,speed,ext=0,choice,n=1000,life=50;

int main()
{
    start:
    system("cls");
    rand1=(rand()%(N-3)+2);
    rand2=(rand()%(N-3)+2);
    rand3=(rand()%(N-3)+2);
    rand4=(rand()%(N-3)+2);
    printf("WELCOME TO NEW GAME\n\nFOR START GAME  [press any alphabet]\nFOR SETTINGS    [press 1]\n\nDEFAULT SPEED MEDIUM");
    
    choice = getch(); //settings and start game
    
    if(choice=='1')
     {
        system("cls");
        while(1) // settings control 
         { 
           char choice1;
           system("cls");
           printf("GAME SPEED [DEFAULT MEDIUM]\n\nLOW       [1]\nMEDIUM    [2]\nHIGH      [3]\nMAIN MENU [0]");
           choice1 = getch() ;
           switch(choice1)
           {
              case '1':n=100000; goto start; break ;
              case '2':n=1000; goto start; break ;
              case '3':n=10; goto start; break ;
              case '0': goto start; break ;
              default: break ;
           }
         }
     }
    else // for game 
    {
     system("cls");
     printf("R FOR RIGHT\nL FOR LEFT\nENJOY :)\n\nENTER ANY KEY TO START THE GAME");
     getch();
     while(1)
     {
       if(ext>0||life==0) break; //game over 
       structure (); //function calling 
       input();
       flow();
       point();
       border();
       for(speed=0;speed<=1000*n;speed++); //for maintaining speed 
       printf("IF YOU WANT TO EXIT CLICK E\nYOUR LIFE IS : %d\nYOUR SCORE = %d\n",life,score);
     }
    }
    system("cls");
    printf("YOU QUIT THE GAME \n!!GAME OVER!!\n\nYOUR FINAL SCORE IS : %d",score);
    return 0;
}
void border()
{
   if(fl1==N)
    {
     srand(time(NULL));
     fl1=rand()%4+2;
     life--;
    }
    else if(fl2==N)
    {
     srand(time(NULL));
     fl2=rand()%4+2;
     life--;
    }
    else if(fl3==N)
    {
     srand(time(NULL));
     fl3=rand()%4+2;
     life--;
    }
    else if(fl4==N)
    {
     srand(time(NULL));
     fl4=rand()%4+2;
     life--;
    }
}
void flow()
{
   fl1++;
   fl2++;
   fl3++;
   fl4++;
}
void point()
{
   if(x==fl1&&y==rand1)
    {
       score += 5;
       srand(score);
       rand1=rand()%N+1;
    }
   else if(x==fl2&&y==rand2)
    {
       score += 5;
       srand(score);
       rand2=rand()%N+1;
    }
    else if(x==fl3&&y==rand3)
    {
       score += 5;
       srand(score);
       rand3=rand()%N+1;
    }
    else if(x==fl4&&y==rand4)
    {
       score += 5;
       srand(score);
       rand4=rand()%N+1;
    }
}
void structure()
{
   int i,j;
   system("cls");
   for(i=1;i<=N;i++)
    {
      for(j=1;j<=N;j++)
      {
        if(i==1||j==1||i==N||j==N)
         {
           printf("# ");
         }
        else 
         {
            if(x==i&&y==j)
             {
               printf("WW");
             }
            else if(i==fl1&&j==rand1)
             {
               printf("* ");
             }
            else if(i==fl2&&j==rand2)
             {
               printf("* ");
             }
            else if(i==fl3&&j==rand3)
             {
               printf("* ");
             }
            else if(i==fl4&&j==rand4)
             {
               printf("* ");
             }
            else 
               printf("  ");
         }
      }
      printf("\n");
    }
}
void input()
{
    
     if(kbhit())
      {
         ch=getch();
        
         if(y==0)
          {
             y=N-1;
          }
         else if(y==N)
          {
             y=2;
          }
         else 
          {
            switch(ch)
            {
             case 'r':
             case 'R': y++; break;
             case 'l':
             case 'L': y--; break;
             case 'E': ext++; break;
             default : break;
            }
          }
      }
}
