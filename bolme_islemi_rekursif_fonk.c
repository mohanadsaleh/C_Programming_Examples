#include <stdio.h>
#include <stdlib.h>


/* Klavyeden girilen iki tamsayinin bölme operandi (/) kullanmadan, birbirlerine bölümü ile elde
edilecek olan sonucu (bölüm), rekürsif fonksiyon kullanarak bulduran C kodunu yaziniz. */

int bolme_islemi( int X , int Y)
{
	
	if (  X < Y) //  1/2 = sonuc tamsayi olarak olamaz
	
	return  0 ;
	
	else 
	return 1+ bolme_islemi( X-Y, Y );     									 
	
									
}

int main(int argc, char *argv[]) {
	
	int num1 ,num2 ,sonuc ;
	printf(" birinci sayi giriniz : ");
	
	scanf("%d",&num1);
	
	printf( "ikinci sayi girinz :");
	
	scanf( " %d",&num2);
	
	sonuc=bolme_islemi( num1, num2);
	printf( " %d / %d = %d ",num1 ,num2 ,sonuc );

	return 0;
}
