#include<iostream.h>
#include<conio.h.>
#include<graphics.h>
void midpointcircle(int,int,int);
void main()
{ int x,y,r;
clrscr();
cout<<"ENTER THE VALUES FOR X,Y,R : ";
cin>>x>>y>>r;
midpointcircle(x,y,r);
getch();
}
void midpointcircle(int a,int b,int r)
University of Delhi
7
{ int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setfillstyle(1,GREEN);
setcolor(GREEN);
outtextxy(100,10,"PROGRAM TO START CONVERT A CIRCLE USING MID POINT ALGORITHM");
line(10,480,10,0);
outtextxy(480,10,"Y");
line(0,470,640,470);
outtextxy(640,70,"X");
int x=0,y=r,d=1-r; while(x<=y)
{
putpixel(10+(a+x),470-(b+y),2);
putpixel(10+(a+x),470-(by),
2); putpixel(10+(a-x),470-(b+y),2);
putpixel(10+(a+y),470-
(b+x),2); putpixel(10+(a-x),470-(b-y),2);
putpixel(10+(a+y),470-(b-x),2);
putpixel(10+(a-y),470-
(b+x),2);
putpixel(10+(a-y),470-(b-x),2);
if(d<0)
d=d+(2*x)+3;
else
{d=d+(2*(x-y))+5; y--;
} x++;
}
floodfill(10+a,470-b,GREEN);
putpixel(10+a,470-b,0);
}
