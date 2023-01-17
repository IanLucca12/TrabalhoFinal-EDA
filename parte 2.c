#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct dados{
    char category[40];
    float amount;
};

void insertionSort(float list[], int n,int o[]){
    int i, j;
    float next;
    for (i=1; i<n; i++) {
        next = list[i];
        for (j=i-1; j>=0&&next>list[j];j--){
            list[j+1] = list[j];
            o[i]=j;
        }
        list[j+1] = next;
    }

 }

 FILE acessLine(FILE *fp, int line){
    char ch;
    int count = 0;
    while(count<line){
        ch = fgetc(fp);
        if(ch == '\n'){
            count = count+1;
        }
    }
    return *fp;
}

 int main(){
    struct dados D;
    float lis[129000];
    int line,j,o[129000], num=0;
    FILE *fp, *fp2;
    FILE *copy;
    fp = fopen ( "Trimmed_File.csv", "r" ) ;
    if ( fp == NULL ){
        puts ( "Cannot open file" ) ;
        system("pause");
        exit(0) ;
    }
    while(1){
        char result;
        result = fscanf(fp, "%s %f", D.category, &D.amount);
        lis[num]=D.amount;
        num=num+1;
        if ( result == EOF)
            break;
            //printf("%s - %.2f \n", D.category,D.amount);
    }
    fclose(fp);
    copy = fopen("Amazonsalecopy.csv","w");
    insertionSort(lis,num,o);
    printf("\n ORDENADO: \n");

    fp2 = fopen("Acess_Line.csv", "w");
            if ( fp2 == NULL ){
                puts ( "Cannot open file" ) ;
                system("pause");
                exit(0) ;
            }


    for(j=0;j<=num;j++){
            fp = fopen ( "Amazonsale.csv", "r" ) ;
            line=o[j];
            *fp = acessLine(fp, line);
            char ch = fgetc(fp);

            while(ch !=' '){
                fputc(ch,fp2);
                ch = fgetc(fp);
            }

        //printf("%d\n",o[j]);
        printf("%.2f\n",lis[j]);
        fprintf(fp2," %.2f\n",lis[j]);

    }
    printf("estou aqui");
    fclose(copy);
    fclose(fp);
}
