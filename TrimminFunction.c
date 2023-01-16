#include <stdio.h>
#include <stdlib.h>

int random(int min, int max){
   return rand() % (max + 1 - min) + min;
}

void trim(int TrimmedFileSize, FILE *fp, int fileLines){    /*o primeiro argumento é um inteiro, entre 1 e 99, que representa o percentual de linahs no novo arquivo. para metade utilize 50.*/
FILE *fp2;                                                  /*o segundo argumento é um ponteiro que aponta para o começo do arquivo original*/
int newFileLines =0;                                        /*o terceiro é o numero de linhas no arquivo original*/
fp2 = fopen("Trimmed_File.csv", "w");
int randomic;
int *vet;
vet = (int*)calloc(fileLines,sizeof(int));
int count=0;


if ( fp2 == NULL ){
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;}

char ch =fgetc(fp);

if(TrimmedFileSize>50){     /*escrever os zeros, n escrever os 1*/
while(newFileLines < (100-TrimmedFileSize)*fileLines/100){
    randomic = random(0, fileLines);
    if (vet[randomic] == 0){
            vet[randomic]= 1;
            newFileLines = newFileLines+1;
}
}


while (fileLines > count)
  {

    if (vet[count] == 0){
    while(ch != 10){
    fputc (ch, fp2);
    ch = fgetc(fp);}
    fputc (ch, fp2);
    ch = fgetc(fp);
    }
    if (vet[count] == 1){
    while(ch != 10){
    ch = fgetc(fp);}
    ch = fgetc(fp);
    }
    count = count +1;


  }

}

if(TrimmedFileSize<=50){     /*escrever os zeros, n escrever os 1*/
while(newFileLines != TrimmedFileSize*fileLines/100){
    randomic = random(0, fileLines);
    if (vet[randomic] == 0){
            vet[randomic]= 1;
            newFileLines = newFileLines+1;

}
}


while (fileLines > count)
  {

    if (vet[count] == 1){
    while(ch != 10){
    fputc (ch, fp2);
    ch = fgetc(fp);}
    fputc (ch, fp2);
    ch = fgetc(fp);
    }
    if (vet[count] == 0){
    while(ch != 10){
    ch = fgetc(fp);}
    ch = fgetc(fp);
    }
    count = count +1;


  }

}
free(vet);
}
int main(){
FILE *fp;
fp = fopen( "Amazonsale.csv", "r" );
if ( fp == NULL ){
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;}
trim(1,fp,128974);
}
