#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
voidbezier_curve(int x[4],int y[4]){
for(double t=0.0;t<1.0;t=t+0.0005)
{ Double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-
t)*x[2]+pow(t,3)*x[3];
University of Delhi
36
Double yt=pow(1-t,3)*y[0]+3*t*pow(1-
t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,YELLOW);
} for(inti=0;i<3;i++)
{ line(x[i],y[i],x[i+1],y[i+1]);
}
}
Void hermite_curve(int x1,int y1,int x2,int y2,double t1,double t4){
Float x,y,t;
for(t=0.0;t<=1.0;t+=0.001){
x=(2*t*t*t-3*t*t+1)*x1+(-2*t*t*t+3*t*t)*x2+(t*t*t-
2*t*t+t)*t1+(t*t*t-t*t)*t4;
y=(2*t*t*t-3*t*t+1)*y1+(-2*t*t*t+3*t*t)*y2+(t*t*t-
2*t*t+1)*t1+(t*t*t-t*t)*t4;
putpixel(x,y,YELLOW);
}
putpixel(x1,y1,GREEN);
putpixel(x2,y2,GREEN);
line(x1,y1,x2,y2);
}
Void main()
{
clrscr();
Int gdriver=DETECT,gmode,errorcode;
intx1,y1,x2,y2,n;
Double t1,t4;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
intx[4],y[4];
inti;
cout<<"1.BezierCurve \n 2.HermiteCurve\n";
cout<<"Enter your choice:"; cin>>n;
if(n==1){
cout<<"Enter x and y coordinates\n";
for(i=0;i<4;i++){ cout<<"x"<<i+1<<":";
cin>>x[i];
University of Delhi
37
cout<<"y"<<i+1<<":";
cin>>y[i]; cout<<endl;
}
bezier_curve(x,y);
}
elseif(n==2){
cout<<"Enter the x coordinate of 1st hermite point:";
cin>>x1;
cout<<"Enter the y coordinate of 1st hermite point:";
cin>>y1; cout<<"Enter the x coordinate of 4th hermite point:";
cin>>x2;
cout<<"Enter the y coordinate of 4th hermite point:";
cin>>y2;
cout<<"Enter tangent at p1:";
cin>>t1; cout<<"Enter tangent at p4:";
cin>>t4;
hermite_curve(x1,y1,x2,y2,t1,t4);
}
else{ cout<<"\nInvalid Choice";
}
getch();
