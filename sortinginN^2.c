#include <stdio.h>
#include <stdlib.h>

void rswap(int *a, int *b);
void print_array(int n, int a[]);
void bub_sort(int n,int a[],char rev);
void ins_sort(int n,int a[],char rev);
void sel_sort(int n,int a[],char rev);
int get_array(int a[]);

int main(){
    int sel=0;
    char rev;
    int a[10];
    int n = get_array(a);
    printf("1. bubble sort\n2. Insertion sort\n3. Selection sort\nEnter your choice: ");
    scanf("%d",&sel);
    printf("Press 'T' for Descending and 'F' for Ascending order: ");
    fflush(stdin);
    scanf("%c",&rev);
    switch(sel){
    case 1:
        printf("\n\t\t\t\tBUBBLE SORT : \n");
        bub_sort(n,a,rev);
        print_array(n,a);
        break;
    case 2:
        printf("\n\t\t\t\tINSERTION SORT : \n");
        ins_sort(n,a,rev);
        print_array(n,a);
        break;
    case 3:
        printf("\n\t\t\t\tSELECTION SORT : \n");
        sel_sort(n,a,rev);
        print_array(n,a);
        break;
    default:
        break;
    }

    return 0;
}

int get_array(int a[]){
    int i,n;
    printf("How many elements are there? : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    return n;
}

void rswap(int *a, int *b){
    int temp;
    temp = *a; *a = *b; *b = temp;
}

void print_array(int n, int a[]){
    int i;
    printf("\t\t\t");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\n");
}

void bub_sort(int n, int a[],char rev){
    int i,j;
    switch(rev){

    case 'T':
    case 't':
    case 'F':
    case 'f':
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(rev=='T' || rev == 't'){
                    if(a[i]>a[j]){
                        rswap(&a[i],&a[j]);
                    }
                }
                else if(rev=='F'||rev == 'f'){
                    if(a[i]<a[j]){
                        rswap(&a[i],&a[j]);
                    }
                }

            }
        }
        break;
    default:
        printf("ERROR: Invalid Parameters\n\t\t\t\tThe Array will not be sorted\n");
    }
}

void ins_sort(int n,int a[],char rev){
    int i,j,key;
    if(rev=='F' || rev == 'f'){
        for(i=1;i<n;i++){
            key = a[i];
            j=i-1;
            while(j>=0 && a[j]>key){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
    }
    else if(rev == 'T' || rev == 't'){
        for(i=1;i<n;i++){
            key = a[i];
            j=i-1;
            while(j>=0 && a[j]<key){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
    }
    else{
        printf("ERROR: Invalid Parameters\n\t\t\t\tThe Array will not be sorted\n");
    }
}

void sel_sort(int n,int a[],char rev){
    int ind,i,j;
    if(rev=='T' || rev == 't'){
        for(i=0;i<n-1;i++){
            ind = i;
            for(j=i+1;j<n;j++){
                if(a[j]>a[ind]){
                    ind = j;
                }
            }
            rswap(&a[ind],&a[i]);
        }

    }

    else if(rev == 'F' || rev == 'f'){
        for(i=0;i<n-1;i++){
            ind = i;
            for(j=i+1;j<n;j++){
                if(a[j]<a[ind]){
                    ind = j;
                }
            }
            rswap(&a[ind],&a[i]);
        }
    }

    else{
        printf("ERROR: Invalid Parameters\n\t\t\t\tThe Array will not be sorted\n");
    }
}
