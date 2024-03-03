#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Turkish");

  // De�i�ken tan�mlamalar�
  int sayac;
  int kul_ad;
  int sifre;
  int son_sec;
  char linse[256];
	char ogrn_bilgi[50];
  FILE *fp;
  char secim;

  printf("OKUL S�STEM�NE HO� GELD�N�Z \nL�TFEN S�ZE UYGUN OLAN SE�ENE�� A�A�IDAN SE��N�Z \n");
  printf("1-Y�NET�C� G�R��\n2- ��RENC� S�STEM� G�R��\n");
  scanf("%d", &secim);

  switch (secim) {
  case 1:
    printf("Y�NET�C� G�R�� EKRANINA HO� GELD�N�Z\n L�TFEN A�A�IDAK� B�LG�LER� G�R�N�Z\n");

    printf("KULLANICI ADINIZ:��");
    scanf("%d", &kul_ad);
    printf("��FREN�Z : ");
    scanf("%d", &sifre);

    if (kul_ad == 1234 && sifre == 1234) {
      printf("G�R�� BA�ARILI Y�NLEND�R�L�YORSUNUZn");
      printf("----YAPMAK �STED���N�Z ��LEM� A�A�IDAK� MEN�DEN SE��N�Z----\n");
      printf("1- YEN� ��RENC� KAYDI \n 2- ��RENC� KAYDI S�L\n 3-T�M ��RENC�LER� L�STELE\n 4- ��RENC� BUL\n");
      scanf("%d", &son_sec);

      switch (son_sec) {
      case 3:
        fp = fopen("ogrenciler.txt", "r");

        if (fp == NULL) {
          printf("Dosya a��lamad�!\n");
          return 1;
        }

        while (fgets(linse, sizeof(linse), fp) != NULL) {
          // Her seferinde s�f�rlay�n
          linse[0] = '\0';

          // Sat�r� okuyun ve ekleyin
          fgets(linse, sizeof(linse), fp);
          strcat(linse, "\n");

          // Sat�r� ekrana yazd�r�n
          printf("%s", linse);
        }

        fclose(fp);

        break;
        case 4 : 
       
         printf("��RENC� B�LG� ARAMA S�STEM�NE HO� GELD�N�Z\n");
        printf("��RENC� HAKKINDA B�LG� G�R�N�Z (�RN: OGRENC� NO / ��RENC� ADI VB)\n");
        scanf("%s", &ogrn_bilgi);

        fp = fopen("ogrenciler.txt", "r");

        if (fp == NULL) {
          printf("Dosya a��lamad�!\n");
          return 1;
        }

        while (fgets(linse, sizeof(linse), fp) != NULL) {
          if (strstr(linse, ogrn_bilgi)) {
            printf("%s", linse);
          }
        }

        fclose(fp);

        break;

      default:
        printf("YANLI� SE��M YAPTINIZ");
        return (19);

        break;
      }
    } else {
      printf("YANLI� KULLANICI ADI VEYA ��FRE");
    }

    break;
  case 2:
  	printf("��RENC� B�LG� EKRANINA HO� GELD�N�Z\n");
        printf("��RENC� NUMARANIZI G�R�N�Z\n");
        scanf("%s", &ogrn_bilgi);

        fp = fopen("ogrenciler.txt", "r");

        if (fp == NULL) {
          printf("Dosya a��lamad�!\n");
          return 1;
        }

        while (fgets(linse, sizeof(linse), fp) != NULL) {
          if (strstr(linse, ogrn_bilgi)) {
            printf("%s", linse);
          }
        }

        fclose(fp);

        break;
    break;
  }

  return 0;
}

