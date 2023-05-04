#include <stdio.h>
int main()
{
    int a[10]={10,20,30,40,50,60,70,80,90,100};
    FILE *fout =fopen("file3.txt","w");
    for(int i=0;i<10;i++){
        fprintf(fout, "%d ",a[i]);
        printf("%d ",a[i]);
    }
    fclose(fout);

    int b[10];
    FILE *fin =fopen("file3.txt","r");
    for(int i=0;i<10;i++){
        fscanf(fin, "%d ",&b[i]);
        printf("%d ",b[i]);
    }
    fclose(fin);
}
