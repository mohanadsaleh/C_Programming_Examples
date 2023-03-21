#include <stdio.h>
#include <stdlib.h>

// Bir sayinin istenen kuvvetini rekürsif fonksiyon ile bulan C programini yaziniz. 
double kuvvet (double sayi, int us )
{
	if (us==0)
	return 1;  // herhangi bir sayinin sifirinci kuvveti bire esittir
     
     else if( us%2==0) 
     return kuvvet( sayi*sayi , us/2);
     else return sayi* kuvvet ( sayi*sayi,(us-1)/2);
	
	
	
}

int main(int argc, char *argv[]) {
	
	
	double num,sonuc;
	int us;
	
	printf(" sayi giriniz :");	  			scanf("%lf",&num);

	printf("sayinin kuvveti giriniz : ");   scanf("%d",&us);
	
	sonuc=kuvvet(num , us);
	printf(" %.2lf ^ %d = %.2lf ",num,us,sonuc);
	
	return 0;
}
