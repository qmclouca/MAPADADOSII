#include <stdio.h>

void intercala(int v1[], int i1, int f1,
               int v2[], int i2, int f2,
               int v3[]){
    int n1,n2,n3,k1,k2;
    int i;
    n1 = f1-i1+1;
    n2 = f2-i2+1;
    n3 = n1+n2;

    k1 = i1;
    k2 = i2;
    for(i = 0; i < n3; i++){
        if(k1 <= f1 && k2 <= f2){
            if(v1[k1] <= v2[k2]){ v3[i] = v1[k1]; k1++; }
            else{ v3[i] = v2[k2]; k2++; }
        }
        else if(k1 <= f1){ v3[i] = v1[k1]; k1++; }
        else{ v3[i] = v2[k2]; k2++; }
    }
}

void mergesort(int v[], int inic, int fim){
    int *aux;
    int m = (inic+fim)/2;
    int i;
    if(inic < fim){
        mergesort(v, inic, m);
        mergesort(v, m+1, fim);

        aux = (int *)malloc(sizeof(int)*(fim-inic+1));

        intercala(v, inic, m,
                  v, m+1, fim,
                  aux);
        for(i = 0; i < fim-inic+1; i++)
            v[inic + i] = aux[i];
        free(aux);
    }
}

int main(){
    int v[] = {6,8,5,7,4,1,2,3};
    int i;
    mergesort(v, 0, 7);
    for(i = 0; i < 8; i++)
        printf(" %d ", v[i]);
    printf("\n");

    return 0;
}