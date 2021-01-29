//Du lieu vao luon dung dan
#include <stdio.h>
struct ps
{
	int tu;
	int mau;
};
void nhap (ps A[], int n);
void nhap1 (ps &x);
void xuat (ps A[], int n);
void phanSoMax (ps A[], int n);
void xuat1 (ps x);
void tong1 (ps x, ps y);
void tong (ps A[], int n);
int uchung (int x, int y);
void rutgon (ps &x);
void tich (ps A[], int n);
void tich1 (ps x, ps y);
void nghichdao (ps A[], int n);
void hoanvi (int &x, int & y);
int main ()
{
	ps A[50];
	int n=0;
	scanf ("%d", &n);
	nhap (A,n);
	xuat (A,n);
	phanSoMax (A,n);
	tong (A,n);
	tich (A,n);
	nghichdao (A,n);
	
}
void nghichdao (ps A[], int n)
{
	for (int i=0; i<n; i++)
	{
		int t=A[i].tu;
		int m=A[i].mau;
		hoanvi( t,m ) ;
		printf ("\nSo hoan vi A[%d]", i);
		printf ("%d/%d", t,m);
		
	}
}
void hoanvi (int &x, int & y)
{
	int  c= x;
	x=y;
	y=c;
}
void tich (ps A[], int n)
{
	for (int i=0; i<n-1; i++)
		for (int j=1; j<n; j++)
		{
			printf ("\nTich hai phan so A[%d]+ A[%d]: ",i,j);
			tich1 (A[i],A[j]);
		}
	
}
void tich1 (ps x, ps y)
{
	ps tich;
	tich.tu = (x.tu * y.tu);
	tich.mau= x.mau* y.mau;
	if (tich.mau==0)
		printf ("Khong the chia duoc");
	else if (tich.tu ==0)
		printf ("0");
	else
	{
		rutgon (tich);
		
		xuat1 (tich);
	}	
	
}
void phanSoMax (ps A[], int n)
{
	float max= (float (A[0].tu)/ (A[0]. mau));
	for (int i=1; i<n; i++)
	{	float giatri = (float (A[i].tu)/ (A[i]. mau));
		
		if (max < giatri )
			max= giatri;
	}
	for (int i=0; i<n; i++)
	{	float giatri = (float (A[i].tu)/ (A[i]. mau));
		if (max= giatri)
		{
			printf ("\nPhan so lon nhat: ");
			xuat1 (A[i]);
			break;
		}
	}
}
void tong (ps A[], int n)
{
	
	for (int i=0; i<n-1; i++)
		for (int j=1; j<n; j++)
		{
			printf ("\nTong hai phan so A[%d]+ A[%d]: ",i,j);
			tong1 (A[i],A[j]);
		}
		
}
void tong1 (ps x, ps y)
{
	ps tong;
	tong.tu= (x.tu * y.mau)+ (y.tu * x.mau);
	
	tong.mau= (x.mau * y.mau);
	if (tong.mau==0)
		printf ("Khong the chia duoc");
	else if (tong.tu ==0)
		printf ("0");
	else
	{
		rutgon (tong);
		
		xuat1 (tong);
	}	
}
void rutgon (ps &x)
{	int uc= uchung (x.tu,x.mau);
	x.tu= x.tu / uc;
	x.mau = x.mau/uc;
}
int uchung (int x, int y)
{
	while (x != y)
	{
		if (x>y)
			x=x-y;
		if (x<y)
			y= y-x;
	}
	return x;
	
}
void nhap (ps A[], int n)
{
	for (int i=0; i<n;i++)
	{
		nhap1 (A[i]);
	}
}
void nhap1 (ps &x)
{
	fflush (stdin);
	printf ("Nhap tu: ");
	scanf ("%d", &x.tu);
	printf ("Nhap mau: ");
	fflush (stdin);
	scanf ("%d", &x.mau);
}
void xuat (ps A[], int n)
{
	for (int i=0; i<n; i++)
	{
		xuat1 (A[i]);
	}
}
void xuat1 (ps x)
{
	printf ("%d/%d ", x.tu, x.mau);
}
