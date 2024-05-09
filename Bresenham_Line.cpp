#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void bresenham_line_algo(int x1,int y1,int x2,int y2)
{ float dy,dx,p; int x,y,xend,yend,dx1,dy1;
int xmid,ymid;
xmid=getmaxx()/2;
ymid=getmaxy()/2;
dx=abs(x2-x1);
dy=abs(y2-y1);
dx1=x2-x1;
dy1=y2- y1;
float m;
m=dy1/dx1;
const int c1=2*dy,c2=2*(dy-dx);
const int d1=2*dx,d2=2*(dx-dy);
if(m<=1&&m>0){
p=2*dy-dx; if(x1>x2){
x=x2; y=y2;
else{ y=y1;
xend=x2;
x=x1;
}
xend=x1;
}
putpixel(x,y,YELLOW);
while(x<xend){
x++;
University of Delhi
3
if(p<0){ p=p+c1;
} else{
y++;
p=p+c2;
}}
else{ p=2*dx-dy; if(y1>y2){
}
y=y2;
x=x2; yend=y1;
putpixel(xmid+x,ymid-y,YELLOW);
}
else{ x=x1; y=y1;
yend=y2;
}
putpixel(x,y,YELLOW);
while(y<yend){
y++;
if(p<0){
p=p+d1;
x--;
}
else{
p=p+d2; }
putpixel(xmid+x,ymid-y,YELLOW);
}}}
void main(){
clrscr();
int gdriver=DETECT,gmode,errorcode;
int x1,y1,x2,y2,xmid,ymid;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
cout<<"Enterthexco-ordinateoffirstpoint:";
cin>>x1;
cout<<"\nEntertheyco-ordinateoffirstpoint:";
cin>>y1;
cout<<"\nEnterthexco-ordinateofsecondpoint:";
cin>>x2;
cout<<"\nEntertheyco- ordinateofsecondpoint:"; cin>>y2;
University of Delhi
4
xmid=getmaxx()/2;
ymid=getmaxy()/2;
line(xmid,0,xmid,getmaxy());
line(0,ymid,getmaxx(),ymid);
bresenham_line_algo(x1,y1,x2,y2);
getch();}
