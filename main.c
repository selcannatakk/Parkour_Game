#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int i,j,k=0,satir,sutun,*dizi,indeks=0,sayac=0;
void BubbleSort(){
    int gecici;
    for(i=0; i<satir*sutun; i++){
        for(j=0; j<(satir*sutun)-i ; j++){
            if( dizi[j]> dizi[j+1]){
                gecici = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = gecici;
            }
        }
    }MatriksAlma();
}
void MatriksAlma(){
    int Matriks[satir][sutun];
    for(i=0; i<satir; i++){
        for(j=0; j<sutun; j++){
            Matriks[i][j]= dizi[k];
            k++;
        }
    }MatriksDosyasi(Matriks);
}
void MatriksDosyasi(int p[][sutun]){
    FILE *pdosya = fopen("tranpoze.txt","w+");
    for(i=0; i<satir; i++){
        for(j=0; j<sutun; j++){
            printf("%d\t",p[i][j]);
            fprintf(pdosya,"%d\t",p[i][j]);
        }fprintf(pdosya,"\n");printf("\n");
    }
   fclose(pdosya);
   TranspozeAlma();
}
void TranspozeAlma(){
    int Tranpoze[sutun][satir];
    for(i=0; i<sutun; i++){
        indeks=0;
        for(j=0; j<sutun*satir; j++){
            if(j%sutun==i){
                Tranpoze[i][indeks]=dizi[j];
                indeks++;
            }
        }
    }TranspozeDosyasi(Tranpoze);
}
void TranspozeDosyasi(int p[][satir]){
    int say;
    FILE *pdosya = fopen("tranpoze.txt","a");
    fprintf(pdosya,"\n\n");
    for(i=0; i<sutun; i++){
        for(j=0; j<satir; j++){
            fprintf(pdosya,"%d\t",p[i][j]);
            say=p[i][j];
            KaprekarMi(say);
        }fprintf(pdosya,"\n");
    }printf("\nYazdirma Islemi Tamam!\n");
    fclose(pdosya);

}
bool KaprekarMi(int sayi){
    int SayiKaresi,Basamak,gecici,toplam,k;
   if(sayi == 1){
    return true;
   }
   SayiKaresi = sayi*sayi;
   Basamak = 0;
   while(SayiKaresi!=0){
        Basamak++;
        SayiKaresi/=10;
   }
   SayiKaresi = sayi*sayi;
   for(k=1; k<Basamak; k++){
    gecici = pow(10,k);
    if(gecici == sayi){
        continue;
    }
    toplam = SayiKaresi/gecici+SayiKaresi%gecici;
    if(toplam == sayi){
            sayac++;
        return true;
    }
   }
   return false;
}
int main()
{
     int Random;
    printf("Dizi boyutu icin satir sayisini giriniz.\n");
    scanf("%d",&satir);
    printf("Dizi boyutu icin sutun sayisini giriniz.\n");
    scanf("%d",&sutun);
    dizi = (int*) malloc(sizeof(int) * satir*sutun);

    srand(time(NULL));
    for(i=0; i<(satir*sutun); i++){
        Random = 5+rand()%40000;
        dizi[i] = Random;
    }
    FILE *fp = fopen("kaprekar.txt","w+");
        if (fp == NULL){
        printf("Dosya acilamadi...\n");
        exit(1);
        }fclose(fp);
    BubbleSort();
    FILE *fp = fopen("kaprekar.txt","a");
        for(i=0; i<100000; i++){

        }
        fclose(fp);

    return 0;

}
