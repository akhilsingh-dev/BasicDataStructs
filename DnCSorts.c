#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp = *a; *a = *b; *b = temp;
}

void get_arr(int n,int arr[]){
    int i;
    printf("Enter contents of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Recorded successfully!\n");
}

void merge_sort(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);

int l_partition(int arr[],int low, int high);
int m_partition(int arr[],int low,int high);

void quick_sort(int arr[],int low,int high);

int main(){
    int a[]={17,8,-9,2,0,-5,7,-32,21};
    int b[] = {17,8,-9,2,0,-5,7,-32,21};
    int i;
    //get_arr(7,a);
    printf("\n\tBy quick sort:\n");
    for(i=0;i<9;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    merge_sort(b,0,8);
    quick_sort(a,0,8);
    for(i=0;i<9;i++){
        printf("%d\t",a[i]);
    }

    printf("\n\n\n\tBy merge sort:\n");

    for(i=0;i<9;i++){
        printf("%d\t",b[i]);
    }

}


int l_partition(int arr[],int low,int high){
    int i,j,pivot;
    pivot = arr[high];
    i = low - 1;
    for(j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

int m_partition(int arr[],int low,int high){
    int i,j,pivot;

    pivot = arr[(high+low)/2];

    swap(&arr[(high+low)/2], &arr[low]);

    i=low+1;
    j = high;

    while(i < j){
        i=low+1;
        j = high;
        while(arr[i] < arr[high] && i<= high){
            i++;
        }
        while(arr[j] >= arr[high] && j > low){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}


void quick_sort(int arr[],int low,int high){
    if(low < high){
        int i;
        int pi = m_partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
        for(i =0 ;i < 7;i++)
            printf("%d\t",arr[i]);
        printf("\n");
    }
}


void merge_sort(int arr[],int low,int high){
    if(low < high){
        int i;
        int mid = (low+high) / 2;

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
        for(i=0;i<7;i++){
            printf("%d\t",arr[i]);
        }
        printf("\n");
    }
}

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int temp[20];
    i = low; j = mid + 1; k = 0;

    while(i <= mid && j <= high){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i < mid+1){
        temp[k] = arr[i];
        i++; k++;
    }
    while(j < high+1){
        temp[k] = arr[j];
        j++; k++;
    }

    for(i = 0;i < k;i++){
        arr[low++] = temp[i];
    }
}


