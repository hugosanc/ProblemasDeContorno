#include<stdio.h>
#include<math.h>

#define N 2
#define Npontos 10

typedef double (*sistfunc)();

double z0( double x, double *y )
{	return (y[1]);
}

double z1( double x, double *y )
{	return (3* y[1] - 2* y[0] + 6* pow(M_E, -x));
}

void RK4( sistfunc func[], double *y, double x, double h)
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
}

void main()
{	double x, h, xmin = 0, xmax = 1, y[N] = {2, 2};
	sistfunc equacoes[N]={z0,z1};
	
	h = (xmax - xmin)/ Npontos;
	
	for( x = xmin; x <= xmax; x += h )
	{	printf("%lf\t%lf\t%lf\n", x, y[0], y[1]);
		RK4(equacoes, y, x, h);
	}
} 
