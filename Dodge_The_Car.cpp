
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <process.h>
#include <string.h>


void animation(void);
void loading(void);
void startpage1();
void startpage2();
void startpage3();
void startpage4();
void record(int);
void Drecord();
void crash();
void obstacle(int,int);
void display (void);
void game();
void car(int);
int score=0;
//int rect[8]={200,0,500,0,500,600,200,600};
void loading(void)
{
    int i,a, per = 0;
    cleardevice();
     for(i=0;i<=200;i++)
     {
    // setbkcolor(9);
     setcolor(7);
     outtextxy(250,244,"LOADING...");
     setcolor(8);
     line(224+i,238,224+i,256);
     setcolor(8);
     rectangle(224,238,425,256);
     delay(25);
     gotoxy(55,16);
     setcolor(RED);
     if(i % 2 == 0)
     {
	printf("%d%",per);
	per++;
     }

     }
     cleardevice();
     settextstyle(4, 0, 2);
     setcolor(WHITE);
     outtextxy(getmaxx()/2 - 140, getmaxy()/2 + 30, "Press any key to start the game!!!");
     getch();

   }

   void initialize(){
   int i;
   for(i=0;i<500;i=i+20)
{ settextstyle(4, 0, 2);
outtextxy(200,200,"DODGE THE CAR");
	line(0,389,640,389);
	if(kbhit())
	{break;
	}
       //	setbkcolor(9);
line(50+i,370,90+i,370);
line(130+i,370,220+i,370);
arc(110+i,370,0,180,20);
line(260+i,370,300+i,370);
arc(240+i,370,0,180,20);
line(300+i,370,300+i,350);
line(300+i,350,240+i,330);
line(240+i,330,200+i,300);
line(200+i,300,110+i,300);
line(110+i,300,80+i,330);
line(80+i,330,50+i,340);
line(50+i,340,50+i,370);
//carwindow
line(165+i,305,165+i,330);
line(165+i,330,230+i,330);
line(230+i,330,195+i,305);
line(195+i,305,165+i,305);
line(160+i,305,160+i,330);
line(160+i,330,95+i,330);
line(95+i,330,120+i,305);
line(120+i,305,160+i,305);

//whell
//setfillstyle(SOLID_FILL,RED);
circle(110+i,370,17);
//floodfill(111+i,369,BLUE);
circle(240+i,370,17);
delay(50);
cleardevice();
 }
 }
   void startpage1(void)
{
char a, ch1;
int b;
setcolor(15);
line(215,300,275,300);
line(215,200,420,200);

setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(BLUE);
settextstyle(6,DEFAULT_FONT, 5);
outtextxy(215,100,"Start");
line(215,150,300,150);
setcolor(RED);
outtextxy(215,150,"High Scores");
outtextxy(215,200,"Help");
outtextxy(215,250,"Exit");
a = getch();
if(a == 13)
{loading();
animation();
}
//game();
else if(a == 0)
{
ch1 = getch();
if (ch1 == 80)
startpage2();

else if (ch1 == 72)
startpage4();
else if(ch1 == 27) exit(1);
}
else
startpage1();
}

void startpage2()
{
char a, ch1;
setcolor(15);
line(215,150,300,150);
line(215,250,280,250);
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(RED);
settextstyle(6,DEFAULT_FONT, 5);
outtextxy(215,100,"Start");
setcolor(BLUE);
line(215,200,420,200);
outtextxy(215,150,"High Scores");
setcolor(RED);
outtextxy(215,200,"Help");
outtextxy(215,250,"Exit");
a = getch();
if( a == 13) {
cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
Drecord();
getch();
cleardevice();
startpage2();
}
else if(a == 0)
{
ch1 = getch();
if (ch1 == 80)
startpage3();
else if (ch1 == 72)
startpage1();
}
else
startpage2();
}

void startpage3()
{
char a, ch1;
setcolor(15);
line(215,200,420,200);
line(215,300,275,300);
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(RED);
settextstyle(6,DEFAULT_FONT, 5);
outtextxy(215,100,"Start");
outtextxy(215,150,"High Scores");
setcolor(BLUE);
line(215,250,280,250);
outtextxy(215,200,"Help");
setcolor(RED);
outtextxy(215,250,"Exit");
a = getch();
if(a == 13)
{
cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
setcolor(RED);
outtextxy(55,80,"GAME TIPS");
settextstyle(6,HORIZ_DIR,1);
setcolor(BLUE);
gotoxy(5,13);outtextxy(55,150,"Press P to pause at any time and press any key to resume. You can");
outtextxy(55,170,"Enter Esc key to exit from the game.");
gotoxy(5,15);outtextxy(55,190,"The speed of your car is increased as you proceed. So greater");
outtextxy(55,210,"difficulty is on the way as you proceed");
outtextxy(55,250,"PRESS THE ARROW KEYS TO MOVE THE CAR");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
setcolor(0);
outtextxy(55,300,"Press enter key to return to the main menu");
getch();
cleardevice();
startpage3();
}
else if(a == 0)
{
ch1 = getch();
if (ch1 == 80)
startpage4();
else if (ch1 == 72)
startpage2();
}
else
startpage3();

}

void startpage4()
{
char a, ch1;
setcolor(15);
line(215,250,280,250);
line(215,150,300,150);
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(RED);
settextstyle(6,DEFAULT_FONT, 5);
outtextxy(215,100,"Start");
outtextxy(215,150,"High Scores");
outtextxy(215,200,"Help");
setcolor(BLUE);
line(215,300,275,300);
outtextxy(215,250,"Exit");
a = getch();
if( a == 13)
{
cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setcolor(11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(BLUE);
settextstyle(3,0,4);
outtextxy(155,150,"THANKS FOR PLAYING");
settextstyle(6,0,5);
outtextxy(120,200,"PRESS ANY KEY TO EXIT");
getch();
exit(0);
}
if(a == 0)
{
ch1 = getch();
if (ch1 == 80)
startpage1();
else if (ch1 == 72)
startpage3();
}
else
startpage4();
}
void car(int p)
{int y;
//setbkcolor(7);
setcolor(7);

    outtextxy(20,20,"SCORE");

    settextstyle(3,0,5);
    //setcolor(0);
    char output[256];
    sprintf(output,"%d",score);
    outtextxy(50,57,output);

setcolor(7);
    settextstyle(6,0,5);

  setlinestyle(0,0,3);
   //setfillstyle(SOLID_FILL,BLACK);
    rectangle(200,0,500,600);
   //fillpoly(4,rect);
 //  floodfill(220,20,BLACK);

       setlinestyle(1,0,2);
	 line(300,0,300,600);
   line(400,0,400,600);

  setcolor(BLUE);
   line(330+p*100,415,330+p*100,465);
    line(370+p*100,415,370+p*100,465);
    arc(350+p*100,440,50,130,32);
    arc(350+p*100,440,230,310,32);

      setlinestyle(0,0,3);
      arc(350+p*100,440,50,130,20);
      arc(350+p*100,440,230,310,20);
      arc(310+p*100,440,330,30,30);
      arc(390+p*100,440,150,210,30);
      rectangle(340+p*100,430,360+p*100,450);

}


   void animation()
   {
   cleardevice();
   car(0);
  game();
 // obstacle();
 }

   void obstacle(int x,int i)
   {
	  setcolor(RED);
   //p=(rand())%2;
   line(x,i-5,x,i+45);
    line(x+40,i-5,x+40,i+45);
    arc(x+20,i+20,50,130,32);
    arc(x+20,i+20,230,310,32);

      arc(x+20,i+20,50,130,20);
      arc(x+20,i+20,230,310,20);
      arc(x-20,i+20,330,30,30);
     arc(x+60,i+20,150,210,30);
      rectangle(x+10,i+10,x+30,i+30);



   }
   void game()
   {char ch,ch1,ch2;
    int x,y,posn=0,speed=5;
    int t2,x1,y1,x2,y2;

   start:

    y1=1;
    x1=230+((rand())%3*100);
    t2=rand()%200;
    x2=230+((rand())%3*100);
    y2=1;
    if(x1==x2)
    x2=230+((rand())%3*100);
  while(y2<getmaxy()-1)
  {


  cleardevice();
   car(posn);

  obstacle(x1,y1);
  if(y1>t2)
 {   obstacle(x2,y2);
  y2=y2+speed;
   }

    y1=y1+speed;

   if(score>50)speed=10;
   if(score>100)speed=15;
   if(score>150)speed=20;
   if(score>200)speed=25;
   if(score>250)speed=30;
   if(score>300)speed=35;
   if(x2==330+posn*100)
   {if(y2>=360 && y2<=410)
   {record(score);
   score=0;
   speed=5;
   cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(9);
outtextxy(100,200,"Do you wish to play again: [Y/N]");
rectangle(400,200,440,225);

setfillstyle(SOLID_FILL,BLACK);
floodfill(405,205,9);
ch = getch();
if ((ch=='y') || (ch=='Y'))

goto start;
else if((ch =='n') || (ch == 'N')) {
cleardevice();
startpage1();
}



    }

   }
    if(x1==330+posn*100){

    if((y1>=360 && y1<=410))
    {record(score);
   score=0;
   speed=5;
   cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(9);
outtextxy(100,200,"Do you wish to play again: [Y/N]");
rectangle(400,200,440,225);

setfillstyle(SOLID_FILL,BLACK);
floodfill(405,205,9);
ch = getch();
if ((ch=='y') || (ch=='Y'))

goto start;
else if((ch =='n') || (ch == 'N')) {
cleardevice();
startpage1();
}



    }

   }
    delay(25);

       if(kbhit())
  {
       ch1=getch();
       if(ch1==13||ch1==75||ch1==77||ch1==27||ch1==112)
       {
   if(posn==0){
   if(ch1==75)
   {
   posn--;
   }
   else if(ch1==77)
   { posn++; }
  }
   if(posn==-1)
   {if(ch1==77)
   {posn++; }
   }
   if(posn==1){
   if(ch1==75)
   {posn--;

   }


}
  if (ch1==27)             //Esc key
{ cleardevice();
gotoxy(30,12); printf(" Sure to exit the game?" )   ;
gotoxy(30,13);printf(" If yes, press Y");
switch(getch())
{
case  'y':
case 'Y':
exit(0);
}
}
if (ch1==112)   //P to pause
{
 cleardevice();
gotoxy(30,15);
printf("Press any key to continue");
getch();


}


   }
   }


   }
   score=score+10;
   goto start;
   }
   void Drecord()
{
char fname[50];
int score, numRecords = 0, repeat = 1, x_co = 10, y_co = 10, y_co1 = 10, i, j;
FILE *fptr;
char *name;
if ((fptr = fopen("record2.txt","r")) == NULL) {
	printf("Error: Loading the file\n");
	exit(1);
}
settextstyle(10,0,3);
outtextxy(70,50,"MOST WANTED RACERS");
setcolor(5);
line(51,100,520,100);
setcolor(7);
rectangle(50,110,600,120);
setfillstyle(5,7);
floodfill(51,111,7);
setlinestyle(0,1,3);
setcolor(RED);
line(51,180,200,180);
line(51,230,200,230);
line(51,280,200,280);
line(51,330,200,330);
line(52,380,200,380);

line(380,180,599,180);
line(380,230,599,230);
line(380,280,599,280);
line(380,330,599,330);
line(380,380,599,380);
setlinestyle(0,1,1);

while(1) {
	if(fscanf(fptr,"%s %d",&fname, &score) == EOF)
		break;
	numRecords++;
}

if(numRecords == 0) {
setcolor(5);
settextstyle(3,0,4);
outtextxy(100,200,"Sorry,No records Available!!!");
}
rewind(fptr);

while ((repeat <= numRecords) && (repeat <= 10)) {
if(repeat <= 5) {
	fscanf(fptr, "%s %d", &fname, &score);
	gotoxy(x_co, y_co);
	printf("Name:\t  %s\n",fname);
	y_co++;
	gotoxy(x_co, y_co);
	printf("Bounty:  %d\n\n",score);
	y_co += 2;
	repeat++;
	}
else if(repeat > 5 && repeat <= 10) {
x_co = 305;
	fscanf(fptr, "%s %d", &fname, &score);
	gotoxy(x_co, y_co1);
	printf("Name:    %s\n",fname);
	y_co1++;
	gotoxy(x_co, y_co1);
	printf("Bounty:  %d\n\n",score);
	y_co1 += 2;
	repeat++;
	}

}
}

void record(int displayscore)
{
int loop;
char name[50], ch;
FILE *fptr;
if ((fptr = fopen("record2.txt","a+")) == NULL) {
	printf("Error: Opening the file\n");
	exit(1);
}
setcolor(WHITE);

settextstyle(3,0,10);
outtextxy(100,150,"CRASH!!!");
delay(2000);
cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(5);
settextstyle(3,0,1);
outtextxy(220,160,"Enter Name:");
setcolor(11);
rectangle(220,188,395,213);
rectangle(215,183,400,218);
setfillstyle(SOLID_FILL,GREEN);
floodfill(216,184,11);
setfillstyle(SOLID_FILL,BLACK);
floodfill(225,190,11);
gotoxy(29,13);
gets(name);
name[0] = toupper(name[0]);
for(loop = 0; loop < strlen(name); loop++) {
	if((name[loop]) == ' ')
		break;
}
name[loop + 1] = toupper(name[loop + 1]);
if(strlen(name) > 0) {
fputs(name,fptr);
fputs("\n",fptr);
fprintf(fptr, "%d", displayscore);
fputs("\n",fptr);
}
fclose(fptr);

cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(11);
rectangle(215,200,400,230);
setfillstyle(SOLID_FILL,BLACK);
floodfill(225,215,11);
gotoxy(29,14);
printf("RECORD SAVED!!!");
delay(1000);
}

void main()
{


int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\tc\\bgi");

initialize();
startpage1();



getch();

}
