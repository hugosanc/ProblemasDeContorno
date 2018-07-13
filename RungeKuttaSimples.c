#include<stdio.h>
#include<math.h>

#define N 10

double f( double x, double y )
{	return (1 + pow(x - y, 2));
}

double RK4( double xmin, double xmax, double y0)
{	double k1, k2, k3, k4, x, y = y0, a = xmin, b = xmax, h;
	
	h = (b - a)/ N;
	for( x = a; x <= b; x += h )
	{	printf("%lf\t%lf\n", x, y);	
		k1 = f(x, y);
		k2 = f(x + h/ 2., y + h* k1/ 2.);
		k3 = f(x + h/ 2., y + h* k2/ 2.);
		k4 = f(x +h, y + h*k3);	
		y += (k1 + 2* k2 + 2* k3 + k4)*h/ 6.;
	}
}

void main()
{	double y;

	y = RK4(2, 3, 1);
} 
	
