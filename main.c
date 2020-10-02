#include<stdio.h>

#include<windows.h>  //baraye taghyire makane makannoma
 void gotoxy(int x, int y)  
{  
   COORD coord = {x, y};  
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
} 

#include <time.h> //estefade az tabe delay
void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}
 

void hanoi(int n,char a,char b,char c);  
void move(int n,char a,char b);  
void Print();  
void Printpanel(int n);  
int a1=0,a2=0,a3=0; 

int main() 
 
{  
    int n;  
    char a='A',b='B',c='C';  //baraye namayesh satri dar khat aval
      
    printf("Please Enter number of loops :(0~9):");  
    scanf("%d",&n);
	a1=n;//bekhater inke nemitunim az aval meghdar dehi konim darune tabe maine inkaro mikonim    
    Print();  
    gotoxy(0,11-n);  
    Printpanel(n);  
    delay(500);   
    gotoxy(25,0);  
    hanoi(n,a,b,c);
    return 0;  
}  

void hanoi(int n,char a,char b,char c)  
{  
    if(n==1)  //halate tavaghof tabe bazghashti
        move(n,a,b);
    else  
    {  
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }  
}  
void move(int n,char a,char b)  
{  
    
  
    int j;  
    switch(a)  //pak kardan yek disk
    {  
        case 'A'://Yani dar sotun A in kararo anjam bede
		a1--;//mizan kardane Y
		gotoxy(21+n,10-a1);//ye Y balatar vaymise pointer  
        for(j=0;j<n*2;j++)
		printf(" \b\b");//hazf disk 
        gotoxy(22,10-a1);//ba'd az hazf , pointer be makani aghabtar miravad ke in gotoxy aan ra dorost mikond
		printf("|");//printe | bejaye disk  
        break;  
        case 'B':
		a2--;
		gotoxy(38+n,10-a2);  
        for(j=0;j<n*2;j++)
		printf(" \b\b");
        gotoxy(39,10-a2);
		printf("|"); 
        break;  
        case 'C':a3--;
		gotoxy(55+n,10-a3);  
        for(j=0;j<n*2;j++)
		printf(" \b\b");  
        gotoxy(56,10-a3);
		printf("|");  
        break;  
    }  
    gotoxy(40,0); //namayesh dar khat aval 
    printf("Move %d, %c-->%c\n",n,a,b);  
    switch(b)  //baraye keshidan makane jadide halghe
    {  
        case 'A':
		gotoxy(23-n,10-a1);
		a1++;  
        for(j=0;j<n*2-1;j++)  
        printf("=");
		gotoxy(0,22);
		delay(800);  
        break;  
        
        case 'B':
		gotoxy(40-n,10-a2);
		a2++;  
        for(j=0;j<n*2-1;j++)  
        printf("=");
		gotoxy(0,22);
		delay(800);   
        break;  
        
        case 'C':
		gotoxy(57-n,10-a3);
		a3++;  
        for(j=0;j<n*2-1;j++)  
        printf("=");
		gotoxy(0,22);
		delay(800); 
        break;  
        
    }  
  
}  
void Print()  
{  
    printf("\n\n");  
     
    printf("\t\t      |                |                |     \n");  
    printf("\t\t      |                |                |     \n");  
    printf("\t\t      |                |                |     \n");  
    printf("\t\t      |                |                |     \n");  
    printf("\t\t      |                |                |     \n");  
    printf("\t\t      |                |                |     \n");  
    printf("\t\t      |	               |                |     \n");  
    printf("\t\t      |                |                |     \n");  
    printf("\t\t _____A________________B________________C_____\n");  
 
     
}  
void Printpanel(int n)  
{  
    int i,j;  
    for(i=1;i<=n;i++)  
    {  
        for(j=1;j<=23-i;j++) //fasele dadan ta sotun  
            printf(" ");  
        for(j=1;j<=i*2-1;j++)//*2-1: baraye in ke '='ha tedadeshan fard bashad- 1,3,5,... 
            printf("=");  
        printf("\n");  //paridan be khat ba'di baraye shurue dobareye halghe va rasme halghe jadid
    }  
}
