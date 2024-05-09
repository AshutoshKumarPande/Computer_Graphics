#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda_line_algo(intx1,inty1,intx2,inty2){
int dx,dy,st;
dx=x2-x1;
dy=y2-y1;
float y,x,xinc,yinc;
int xmid,ymid; xmid=getmaxx()/2;
University of Delhi
5
ymid=getmaxy()/2;
if(abs(dx)>abs(dy)){ st=abs(dx);
}
else{ st=abs(dy);}
xinc=dx/st;
yinc=dy/st;
x=x1;
y=y1;
for(inti=0;i<st;i++){ x+=xinc; y+=yinc;
putpixel(ceil(x)+xmid,ymid-ceil(y),YELLOW);}}
void main(){ clrscr();
int gdriver=DETECT,gmode,errorcode;
int x1,y1,x2,y2,xmid,ymid;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
cout<<"Enterthexco-ordinateoffirstpoint:";
cin>>x1;
cout<<"\nEntertheyco-ordinateoffirstpoint:"; cin>>y1;
cout<<"\nEnterthexco-ordinateofsecondpoint:"; cin>>x2;
cout<<"\nEntertheyco-ordinateofsecondpoint:"; cin>>y2;
xmid=getmaxx()/2;
ymid=getmaxy()/2; line(xmid,0,xmid,getmaxy());
line(0,ymid,getmaxx(),ymid);
dda_line_algo(x1,y1,x2,y2); getch();}
