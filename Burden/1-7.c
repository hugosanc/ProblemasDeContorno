#include<stdio.h>
#include<math.h>

#define N 2 //ordem da equação
#define Npontos 100

typedef double (*sistfunc)();

double f0( double x, double *y )
{	return (y[1]);
}

double f2( double x, double *y )
{	return ((-2./x)*y[1]);
}

double f1( double x, double *y )
{	return (f2(x, y));
}

double RK4( sistfunc func[], double *y, double x, double h)
{	double k1[N], k2[N], k3[N], k4[N], yaux[N];
	int i;
	
	for( i = 0; i < N; i++ )
		k1[i] = func[i](x, y);
	for( i = 0; i < N; i++ )
		yaux[i] = y[i] + h* k1[i]/ 2.;
	for( i = 0; i < N; i++ )
		k2[i] = func[i](x + h/ 2., yaux);
	for( i = 0; i < N; i++ )
		yaux[i] = y[i] + h* k2[i]/ 2.;
	for( i = 0; i < N; i++ )
		k3[i] = func[i](x + h/ 2., yaux);
	for( i = 0; i < N; i++ )
		yaux[i] = y[i] + h*k3[i];
	for( i = 0; i < N; i++ )
		k4[i] = func[i](x + h, yaux );	
	for( i = 0; i < N; i++ )
		y[i] += (k1[i] + 2* k2[i] + 2* k3[i] + k4[i])*h/ 6.;
		
	return y[0];	
}

void main()
{	double x, h, xmin = 2, xmax = 4, y, B = 0, y1[N] = {110, 0}, y2[N] = {0, 1}, y1b, y2b, yp1[Npontos+1], yp2[Npontos+1];
	sistfunc equacoes1[N]={f0,f1};
	sistfunc equacoes2[N]={f0,f2};
	int i;
	
	h = (xmax - xmin)/Npontos;
	i = 0;
	yp1[0] = y1[0];
	yp2[0] = y2[0];
	for( x = xmin + h; x <= xmax; x += h )
	{	i++;
		yp1[i] = RK4(equacoes1, y1, x, h);
		yp2[i] = RK4(equacoes2, y2, x, h);
	}
	y1b = yp1[i];
	y2b = yp2[i];
	i = 0;
	for( x = xmin; x <= xmax; x += h )
	{	y = yp1[i] + ((B - y1b)/ y2b)* yp2[i]; 
		printf("%lf\t%lf\n", x, y);
		i++;
	}
} 
