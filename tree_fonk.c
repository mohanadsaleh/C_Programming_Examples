#include <stdio.h>

//Rekürsif fonksiyon kullanilarak görseldeki agaci çizdirecek C kodunu yaziniz. 

void drawTree(int satir) {
    int i, j;
	
	// satir sayisi 6'dan fazla ise fonksiyon sonlaniyor ( temel durum)
    if ( satir>6) return;
 
   // cizim basliyor 
	
    for (i = 1; i <=satir; i++) 
	{
        
		for ( j =0 ; j< satir-i+2;j++)
		printf(" ");  					// bosluk dongosu				

        	
		for ( j=0 ; j< (i*2)-1;j++)
		printf("*"); 
		
         printf("\n");
    }
		
		 
    
    
	// alt aðaçlarý  rekürsif olarak çiz
   	drawTree( satir+2);
}

int main() {
   int j;
    drawTree(3);
for ( j=0 ; j< 5;j++)
		{
			printf("    ");
			printf("|_|");
			printf("\n");
		}
	
    return 0;
}
          //fonksiyon olmadan normal C PROGRAMI

/*


int main(int argc, char *argv[]) {
	
	int row,i,j;
	printf("row sayisi girinzi \n");
	scanf("%d",&row);
	
	for ( i=1;i<=row;i++)
	{
		
		for ( j =0 ; j< row-i+2;j++)
		printf(" ");  									

		  
		
		for ( j=0 ; j< (i*2)-1;j++)
		printf("*");
		
		printf("\n");
		
		
	}
	
		
	for ( i=1;i<=row+2;i++)
	{
		
		for ( j =0 ; j< (row+2)-i;j++)
		printf(" ");  									

		  
		
		for ( j=0 ; j< (i*2)-1;j++)
		printf("*");
		
		printf("\n");
		
	}
			for (i = 1; i < row/2; i++) 
			{
				
		for ( j=0 ; j< i;j++)
		{
				printf("    ");
		
		

		printf("|_|");
			printf("\n");
		}
	
		
	}

	
	
	
	
	
	return 0;
} */
