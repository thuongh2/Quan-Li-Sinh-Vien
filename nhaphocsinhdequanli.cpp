#include <stdio.h>
struct student 
{
	char mshs [5];
	char name [30];
	int day, month, year;
	char local [50];
	char male [3];
	float math, phy , chem;
};
void input (student A[], int &n);
void nhapMotHocSinh (student &x);
void output (student A[], int n);
void xuat (student x);
void avg (student A[], int n);
void connguoita (student A[], int n);
void xephocsinh (student A[], int n);
float tb (student A[]);
void hoandoi (student &x, student &y);
void xuatman ();
int main ()
{
	student A[30];
	int n;
	int a;
	xuatman ();

	do
	{	
		printf ("\nNhap lua chon: ");
		scanf ("%d", &a);
		if (a==1)
			input (A,n);
		else if (a==2)
			output (A,n);
		else if (a==3)
			avg (A,n);
		else if (a==4)
			connguoita (A,n);
		else if (a==5)
			xephocsinh (A,n);
			
	} while (a !=0);
		xephocsinh (A,n);
	return 0;
}
void input (student A[], int &n)
{
	printf ("Nhap so hoc sinh: ");
	scanf ("%d", &n);
	for (int i=0; i<n; i++)
	{
		nhapMotHocSinh (A[i]);
	}
}
void nhapMotHocSinh (student &x)
{
	printf ("\nNhap MSSV: ");
	fflush (stdin);
	gets (x.mshs);
	fflush (stdin);
	printf ("\nNhap Ho va Ten: ");
	gets (x.name);
	fflush (stdin);
	printf ("\nNhap ngay thang nam sinh: ");
	int d,m,y;
	scanf ("%d%d%d", &d, &m, &y);
	x.day=d; x.month= m; x.year= y;
	fflush (stdin);
	printf ("\nNhap dia chi: ");
	gets (x.local);
	fflush (stdin);
	printf ("\nNhap gioi tinh : ");
	gets (x.male);
	printf ("\nNhap diem Toan, Li, Hoa : ");
	float t,l,h;
	scanf ("%f%f%f", &t, &l, &h);
	x.math=t; x.phy= l; x.chem = h;
	fflush (stdin);
}
void output (student A[], int n)
{
	for (int i=0; i<n; i++)
	{
		xuat (A[i]);
	}
}
void xuat (student x)
{
	printf ("%s		%s		%d %d %d		%s		%s		%.1f %.1f %.1f",x.mshs, x.name, x.day, x.month, x.year, x.local,x.male,x.math,x.phy,x.chem);
	printf ("\n");
}
void avg (student A[], int n)
{
	int d=0;
	for (int i=0; i<n; i++)
	{
		float tb= (A[i].math + A[i].phy +A[i].chem )/3;
		if (tb >= 5)
		{
			printf ("\nDanh sach hoc sinh duoc len lop:\n");
			xuat (A[i]);
			d++;
		}
		
	}
	printf ("So hoc sinh duoc len lop: %d", d);
}
void connguoita (student A[], int n)
{
		float max= (A[0].math + A[0].phy +A[0].chem )/3;
	for (int i=1; i<n; i++)
	{
		float tb= (A[i].math + A[i].phy +A[i].chem )/3;
		if (tb > max)
			max= tb;	
	}
	for (int i=0; i<n; i++)
	{
			float tb= (A[i].math + A[i].phy +A[i].chem )/3;
		if (max== tb)
			xuat (A[i]);
	}
}
void xephocsinh (student A[], int n)
{

	for (int i=0; i<n-1; i++)
	{
		float tb1= (A[i].math + A[i].phy +A[i].chem )/3;
		for (int j=1; j<n ; j++)
		{
			float tb2= (A[j].math + A[j].phy +A[j].chem )/3;
			if ( tb1 < tb2)
				hoandoi (A[i], A[j]);
		}
	}
	output (A,n);
}

void hoandoi (student &x, student &y)
{
	student c=x;
	x=y;
	y=c;
}
void xuatman ()
{
	printf ("\n======================NHAP LUA CHON============================");
	printf ("\n=			1 Nhap sinh vien        	  	 =");
	printf ("\n=			2 Xuat sinh vien			 =");
	printf ("\n=			3 Xuat hoc sinh duoc len lop		 =");
	printf ("\n=			4 Xuat hoc sinh gioi nhat		 =");
	printf ("\n=			5 Sap xep theo thu tu diem trung binh	 =");
	printf ("\n=			0 Thoat					 =");
	printf ("\n===============================================================");
}
