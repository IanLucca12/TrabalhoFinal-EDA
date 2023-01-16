#include <stdio.h>
#include <stdlib.h>


FILE acessLine(FILE *fp, int line){  /* the first argument is a file pointer that points to the first element of a file*/
                                        /*the second argument is the line u want to acess*/
                                        /*after using this the next fgetc(fp) will point to the first element of the line u wanted to acess*/
    char ch;                            /*see an exemple in the main*/
    int count = 0;
    while(count<line){
        ch = fgetc(fp);
        if(ch == 10){
            count = count+1;
        }
    }
    return *fp;
}

int main(){

FILE *fp, *fp2;
fp = fopen( "Amazonsale.csv", "r" );
if ( fp == NULL ){
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;}

int line=5;

fp2 = fopen("Acess_Line.csv", "w");
if ( fp2 == NULL ){
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;}

*fp = acessLine(fp, line);
char ch = fgetc(fp);

while(ch !=10){
    fputc(ch,fp2);
    ch = fgetc(fp);
}





}
