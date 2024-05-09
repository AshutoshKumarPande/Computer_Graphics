#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
union REGS i, o; struct pt
{ int x, y;
};
float xl, xr, yt, yb, m, slope[20];
int bc = 0, xc, yc, n = 0, k;
int dx, dy, x, y, temp, a[20][2], xi[20];
struct point
{ float x, y;
};
enum bound
University of Delhi
12
{ left,
right,
bottom,
top
};
int inside( struct point p, enum bound b )
{ int c
=
1;
switch( b )
{
case left:
c = 0;
if( p.x < xl )
break; case right:
if( p.x > xr ) c = 0;
break; case
bottom:
if( p.y > yb )
c = 0;
case top:
break;
if( p.y < yt ) c = 0;
break;
}
return c;
}
struct point intersect( struct point p1, struct point p2, enum bound b )
{
struct point t; float m = 0;
if( p2.x != p1.x )
m = ( p2.y - p1.y ) / ( p2.x - p1.x );
switch( b )
{
case left:
t.x = xl;
t.y = p2.y + ( xl - p2.x ) * m;
case right:
University of Delhi
13
break;
t.x = xr;
t.y = p2.y + ( xr - p2.x ) * m;
break;
case bottom:
t.y = yb;
if( p1.x == p2.x )
t.x = p2.x;
else
t.x = p2.x + ( yb - p2.y ) / m;
break;
case top:
t.y = yt;
if( p1.x == p2.x )
t.x = p2.x;
else
t.x = p2.x + ( yt - p2.y ) / m;
break;
}
return t;
}
int initmouse( )
{ i.x.ax =
0; int86( 0X33, &
i, &
o
); return( o.x.ax );
}
void showmouseptr( )
{ i.x.ax =
1;
int86( 0X33, &i, &o );
}
void hidemouseptr( )
{ i.x.ax =
2;
int86( 0X33, &i, &o );
}
University of Delhi
14
void getmousepos( int *button, int *x, int *y )
{ i.x.ax =
3; int86( 0X33, &
i, &
o
);
*button = o.x.bx;
*x = o.x.cx;
*y = o.x.dx;
}
void main( )
{
enum bound b; int cou, i, flag;
struct point p[30], pout[30], z;
int gdriver = DETECT, gmode;
initgraph( &gdriver, &gmode, "..\\BGI" );
cleardevice( );
showmouseptr( );
while( bc != 2 )
{
getmousepos( &bc, &xc, &yc );
if( bc == 1 )
{
p[n].x = xc;
p[n].y = yc;
n++;
hidemouseptr( ); if( n > 1 )
line( p[n-2].x, p[n-2].y, xc, yc );
showmouseptr( ); delay( 100 );
}
}
p[n] = p[0]; hidemouseptr( );
line( p[n-1].x, p[n-1].y, p[n].x, p[n].y );
showmouseptr( );
getmousepos( &bc, &xc, &yc );
flag = 1; bc = 0; while( bc != 2 )
{ if( (
bc == 1
University of Delhi
15
)
&& (
flag == 1
)
)
{
xl = xc; yt = yc;
flag = 2;
}
else
{}
xr = xc; yb = yc;
getmousepos( &bc, &xc, &yc );
}
rectangle( xl, yt, xr, yb ); getch( );
for(b=left; b <= top; b++)
{
cou = -1;
for( i = 0; i < n; i++ )
if( ( inside( p[i], b ) == 0 ) && ( inside( p[i + 1], b ) == 1 ) ){1 ) ))
== 0 ) )
else
}
else
z = intersect( p[i], p[i + 1], b );
pout[++cou] = z;
pout[++cou] = p[i + 1];
if( ( inside( p[i], b ) == 1 ) && ( inside( p[i + 1], b ) == pout[++cou]
= p[i + 1];
if( ( inside( p[i], b ) == 1 ) && ( inside( p[i + 1], b
{
z = intersect( p[i], p[i + 1], b );
pout[++cou] = z;
}
pout[++cou] = pout[0];
n = cou;
for( i = 0; i <= n; i++ ) p[i] = pout[i];
}
University of Delhi
16
getch( ); cleardevice( );
rectangle( xl, yt, xr, yb );
for( i = 0; i < n; i++ )
line( p[i].x, p[i].y, p[i + 1].x, p[i + 1].y );
for( i = 0; i < n; i++ )
{
a[i][0] = p[i].x;
a[i][1] = p[i].y;
}
getch( );
closegraph( );
}
