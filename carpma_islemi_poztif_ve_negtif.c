#include <stdio.h>
#include <stdlib.h>

/*Klavyeden girilen iki sayinin çarpimlarini (*) operandi kullanmadan, rekürsif fonksiyon kullanarak
bulduran C kodunu yaziniz. */

	int negatifCarpmaIslemi(int x, int y);
	int carpma_islemi( int A , int B);

int main() {

int sayi1 ,sayi2,sonuc;
printf("birinic sayi giriniz :");
scanf(" %d",&sayi1);

printf(" ikinci sayi giriniz :");
scanf("%d",&sayi2);

	if ( sayi1 < 0 || sayi2 < 0 )


	{
	sonuc = negatifCarpmaIslemi(sayi1, sayi2);

	printf("%d * %d = %d\n", sayi1, sayi2, sonuc);

	
	}

	 else {
     
     
     	sonuc =carpma_islemi( sayi1,sayi2);
 		printf("%d * %d = %d\n", sayi1, sayi2, sonuc);
     
 		}
 

return 0;

}

int carpma_islemi( int A , int B)
{
	
	if ( A==0 || B==0) 
	
	return 0 ;			// herhangi bir sayinin sifirla carpmanin sonucu sifirdir
	
	else if ( B> 0) // B sifirdan buyuk oldugu surece  toplama islemi tekrarlanir
	
	return A +  carpma_islemi( A , B-1);
	
	
}


int negatifCarpmaIslemi(int x, int y) 
	{

	if (y == 0)

	return 0;

	if (y < 0)

	return (-x) + negatifCarpmaIslemi(x, y + 1);

	return x + negatifCarpmaIslemi(x, y - 1);
	}
