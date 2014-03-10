#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<cstdlib>

char a[10][10];
int n;

void printmatrix()
{
 int i,j;
 printf("n");
 for(i=0;i < n;i++)
       {
       for(j=0;j < n;j++)
            printf("%ct",a[i][j]);
       printf("nn");
       }
}

//------------------------------------------

int getmarkedcol(int row)
{
 int i,j;
 for(i=0;i < n;i++)
     if(a[row][i]=='Q')
     {
     return(i);
     break;
     }
}

//------------------------------------------

int feasible(int row, int col)
{
 int i,tcol;
 for(i=0;i < n;i++)
     {
     tcol=getmarkedcol(i);
         if(col==tcol || abs(row-i)==abs(col-tcol))
              return 0;
     }
 return 1;
}

//------------------------------------------

void nqueen(int row)
{
 int i,j;
 if(row < n)
 {
  for(i=0;i < n;i++)
     {
     if(feasible(row,i))
         {
         a[row][i]='Q';
         nqueen(row+1);
         a[row][i]='.';
         }
     }
 }
 else
 {
 printf("nThe solution is:- ");
 printmatrix();
 }
}

//---------------------------------

int main()
{
 int i,j;
 clrscr();

 printf("n Enter the no. of queens:- ");
 scanf("%d",&n);

 for(i=0;i < n;i++)
     for(j=0;j < n;j++)
  a[i][j]='.';

 nqueen(0);
 getch();
}
