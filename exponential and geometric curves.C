#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void calcxy(int k);
void calcab(int n,double sumX,double sumX2,double sumY,double sumXY,int z);
void display(double a,double b,int k);

void main()
{       int k = 0;
	start:
	system("cls");
	printf("MENU\n");
	printf("1. y = a * e^(bx)\n");
	printf("2. y = a * b^(x)\n");
	printf("3. y = a * x^(b)\n");
	printf("Enter thy choice :");
	scanf("%d",&k);
	if( k==1 || k==2 || k==3 )
		calcxy(k);
	else
	{	printf("Invalid Input !");
		goto start;
	}
	printf("\n");
	system("Pause");
}


void calcxy(int k)
{	int n,i;
	double x[10],y[10],sumX=0,sumY=0,sumX2=0,sumXY=0;
	double X[10],Y[10];
	printf("Enter the number of elements :");
	scanf("%d",&n);
	printf("Enter the elements for x\n");
	for(i=0;i<n;i++)
	{	printf("Enter the element x[%d] :",i);
		scanf("%lf",&x[i]);
		if(k == 1 || k == 2)
			X[i] = x[i];
		else if(k == 3)
			X[i] = log(x[i]);
		sumX = sumX + (X[i]);
		sumX2 = sumX2 + (X[i]*X[i]);
	}
	printf("\nEnter the element for y\n");
	for(i=0;i<n;i++)
	{	printf("Enter the elements y[%d] :",i);
		scanf("%lf",&y[i]);
		Y[i] = log(y[i]);
		sumY = sumY + Y[i];
		sumXY = sumXY + X[i]*Y[i];

	}
	printf("\nSumX : %0.4lf",sumX);
	printf("\nSumX2 : %0.4lf",sumX2);
	printf("\nSumY : %0.4lf",sumY);
	printf("\nSumXY : %0.4lf\n",sumXY);
	getch();
	calcab(n,sumX,sumX2,sumY,sumXY,k);

}

void calcab(int n,double sumX,double sumX2,double sumY,double sumXY,int z)
{
	double x,y;
	double del;

/*	del = (n*sumX2)-(sumX*sumX);
	del = 1/del;

	x = (del*sumX2*sumY)-(del*sumX*sumY);
	y = (n*del*sumXY)-(del*sumX*sumY);
*/
	y = (sumX*sumY-n*sumXY)/(sumX*sumX-n*sumX2);
	x = (sumY-y*sumX)/n;

	printf("\nThe value of A : %0.4lf",x);
	printf("\nThe value of B : %0.4lf\n",y);

	if(z == 1 || z == 3)
	{	x = exp(x);
		y = y;
	}
	else if(z == 2)
	{       x = exp(x);
		y = exp(y);
	}
	display(x,y,z);
}

void display(double a,double b,int k)
{       printf("\nHence the required equation is as follows :\n");
	if(k==1)
	{	printf("y = %0.4lf * e^(%0.4lf * x) ",a,b);	}
	else if(k==2)
	{	printf("y = %0.4lf * %0.4lf^(x) ",a,b);	}
	else if(k==3)
	{	printf("y = %0.4lf * x^(%0.4lf) ",a,b);	}
}
