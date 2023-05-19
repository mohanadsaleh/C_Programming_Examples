#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct ogrenci {
    int numara;
    char name[20];
    float vize, final;
    struct ogrenci* next;
};

void kayit_goster(struct ogrenci* bas);

struct ogrenci* kayit_ekle(struct ogrenci* bas) {
    struct ogrenci* ogrenci = (struct ogrenci*)malloc(sizeof(struct ogrenci));

    printf("Ogrenci numarasini giriniz:\n");
    printf("Numara: ");
    scanf("%d", &ogrenci->numara);
    printf("Ogrenci adini giriniz:\n");
    printf("Ad: ");
    scanf("%s", ogrenci->name);
    printf("Ogrenci vize notunu giriniz:\n");
    printf("Vize notu: ");
    scanf("%f", &ogrenci->vize);
    printf("Ogrencinin final notunu giriniz:\n");
    printf("Final notu: ");
    scanf("%f", &ogrenci->final);
    printf("Kayit eklendi.\n");

    if (bas == NULL) {
        bas = ogrenci;
    }
    else
        ogrenci->next = bas;
    bas = ogrenci;

    return bas;
}

void updet(struct ogrenci* bas, int std_num) {
    struct ogrenci* temp = bas;

    while (temp != NULL) {
        if (temp->numara == std_num) {
            printf("Istediginiz kaydi buldum.\n");
            printf("Yeni ogrenci adini giriniz:\n");
            printf("Adi: ");
            scanf("%s", temp->name);
            printf("Yeni ogrenci vize notunu giriniz:\n");
            printf("Vize notu: ");
            scanf("%f", &temp->vize);
            printf("Yeni ogrencinin final notunu giriniz:\n");
            printf("Final notu: ");
            scanf("%f", &temp->final);
            printf("Kayit guncellendi.\n");
            return;
        }

        temp = temp->next;
    }
    printf("Aranan ogrenci kaydi bulunamadi!\n");
}

void ortalama(struct ogrenci* bas) {
    struct ogrenci* temp = bas;
    if (temp == NULL) {
        printf("KAYIT YOK\n");
        return;
    }

    float ortalama = 0, count = 0;
    while (temp != NULL) {
        ortalama += (0.4 * temp->vize) + (0.6 * temp->final);
        count++;
        temp = temp->next;
    }
    printf("Sinif ortalamasi = %.2f\n", ortalama / count);
}

void best_student(struct ogrenci* bas) {
    struct ogrenci* temp = bas;
    struct ogrenci* best = bas;
    if (temp == NULL) {
        printf("KAYIT YOK\n");
        return;
    }

    while (temp != NULL) {
        if (((0.4 * temp->vize) + (0.6 * temp->final)) > ((0.4 * best->vize) + (0.6 * best->final))) {
            best = temp;
        }
        temp = temp->next;
    }
    printf("\n\tEn iyi ogrenci\n");
    kayit_goster(best);
}

void kayit_sil(struct ogrenci* bas, int numara) {
    if (bas == NULL) {
        printf("Kayit bulunamadi.\n");
        printf("------------------------\n");
        return;
    }

    struct ogrenci* temp = bas;

    if (temp != NULL && temp->numara == numara) {
        bas = temp->next;
        free(temp);
        printf("Kayit silindi.\n");
        return;
    }
}

void kayit_goster(struct ogrenci* bas) {
    printf("Numara: %d\n", bas->numara);
    printf("Ad: %s\n", bas->name);
    printf("Vize Notu: %.2f\n", bas->vize);
    printf("Final Notu: %.2f\n", bas->final);
    printf("-------------------------\n");
}

void ada_gore_ara(struct ogrenci* bas, char* name) {
//*Aranacak öðrenci no girilecek ve uyan kayýt varsa tüm bilgisi listelenece
    if (bas == NULL) {
        printf("Kayit bulunamadi.\n");
        return;
    }

    struct ogrenci* temp = bas;
    int bulundu = 0;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            kayit_goster(temp);
            bulundu = 1;
        }
        temp = temp->next;
    }
    if (!bulundu)
        printf("Verilen isme sahip kayit bulunamadi.\n");
}

void numaraya_gore_ara(struct ogrenci* bas, int numara) {
	//Aranacak isim girilecek ve uyan kayýtlarýn hepsi listelenecek
    if (bas == NULL) {
        printf("Kayit bulunamadi.\n");
        return;
    }

    struct ogrenci* temp = bas;
    int bulundu = 0;
    while (temp != NULL) {
        if (temp->numara == numara) {
            kayit_goster(temp);
            bulundu = 1;
        }
        temp = temp->next;
    }

    if (!bulundu) {
    	printf("------------------------------------------\n");
        printf("Verilen numaraya sahip kayit bulunamadi.\n");
    }
}

void listLess(struct ogrenci* bas) {
	// listede baþarý notu 60’ýn altýnda olan öðrencileri listeden silecektir.
    struct ogrenci* temp = bas;
    if (temp == NULL)
        printf("Kayit Yok\n");

    while (temp != NULL) {
        if ((0.4 * temp->vize + 0.6 * temp->final) < 60) {
        	printf("------------------------------------------\n");
            printf("%d numarali ogrenci ortalamasi dusuk oldugu icin kayit kayidi silinecektir.\n", temp->numara);
            
            kayit_sil(bas, temp->numara);
        }
        temp = temp->next;
    }
}

void updateAhmet(struct ogrenci* bas) {
	//“Ahmet” olan tüm kayýtlarý “AHMET” olarak güncelleyecek.
    struct ogrenci* temp = bas;
    if (temp == NULL) {
    	printf("------------------------------------------\n");
        printf("KAYIT YOK\n");
        printf("------------------------------------------\n");
        return;
    }

    while (temp != NULL) {
        if (strcmp(temp->name, "Ahmet") == 0) {
            strcpy(temp->name, "AHMET");
        }
        temp = temp->next;
    }
}

void exchange(struct ogrenci* bas) {
	
	//e listede yer alan ilk kayýt ile son kaydý yer deðiþtirecektir Fonksiyonu
    if (bas == NULL || bas->next == NULL){
    	printf("------------------------------------------\n");
    
    	 return;
    }
 
    struct ogrenci* temp = bas;
    struct ogrenci* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    temp->next = (bas)->next;
    bas->next = NULL;
    prev->next = bas;
    bas = temp;
    while(bas!=NULL){
    	kayit_goster(bas);
	}
}

int main(void) {
    struct ogrenci* bas = NULL;
    int secim, islem;
    int num, silmek_numarasi;
    char isem[20];

    while (secim != 9) {
    	printf("------------------------------------------\n");
        printf("Menu:\n");
        printf("1-Yeni Kayit Ekleme\n");
        printf("2-Kayit Listeleme\n");
        printf("3-Kayit Guncelleme\n");
        printf("4-Sinif Ortalamasi Hesaplama\n");
        printf("5-En Basarili Ogrenci Bilgilerini Goster\n");
        printf("6-Kayit Silme\n");
        printf("7-ilk kayit son kayit ile yer degister\n");
        printf("8-Listedeki (Ahmet) isminin ( AHMET) olarak yaz\n");
        printf("8-Cikis\n");
        printf("------------------------------------------\n");
        printf("Seciminizi yapin:\n ");
         
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                bas = kayit_ekle(bas);
               
                break;
            case 2:
                printf("\t 1-Numaraya Gore Kayit Ara\n");
                printf("\t 2-Isme Gore Kayit Ara\n");
                printf("\t 3-Listede Basari Notu 60'in Altinda Olan Kayitlari Sil\n");
                printf("Istediginiz islem numarasini giriniz: ");
                scanf("%d", &islem);
                switch (islem) {
                    case 1:
                        printf("Ogrenci numarasini giriniz: ");
                        scanf("%d", &num);
                        numaraya_gore_ara(bas, num);
                        break;
                    case 2:
                        printf("Ogrenci adini giriniz: ");
                        scanf("%s", isem);
                        ada_gore_ara(bas, isem);
                        break;
                    case 3:
                        listLess(bas);
                        break;
                }
                break;
            case 3:
                printf("Guncellemek istediginiz ogrenci numarasini giriniz: \n");
                printf("Numara: ");
                scanf("%d", &num);
                updet(bas, num);
                break;
            case 4:
                ortalama(bas);
                break;
            case 5:
                best_student(bas);
                break;
            case 6:
                printf("Silmek istediginiz ogrenci numarasini giriniz: \n");
                scanf("%d", &silmek_numarasi);
                kayit_sil(bas, silmek_numarasi);
                break;
            case 7:
			exchange(bas);
			 while(bas!=NULL){
            	kayit_goster(bas);
            	bas=bas->next;
            }
             break;
            case  8:
            updateAhmet(bas);
            while(bas!=NULL){
            	kayit_goster(bas);
            	bas=bas->next;
		  }
            
            break;
            case 9:
            	printf(" programdan cikilyor....");
            	
               
        }
        
    }

    return 0;
}

