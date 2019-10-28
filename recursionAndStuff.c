#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*      AUTHOR: the.drake1010(AKHIL SINGH)      */

/*
    RELEASE NOTES GO HERE
*/

int rfact(int n){
	if(n==1){
		return 1;
	}
	else{
		return n*rfact(n-1);
	}
}

void lfact(int n){
    int i,f=1;
    for(i=1;i<=n;i++){
        f*=i;
    }
    printf("Factorial : %d\n",f);

}

int rfib(int n){
	if(n==0){
        return 1;
	}
	if(n==1){
        return 1;
	}
	else{
        return rfib(n-1)+rfib(n-2);
	}
}

void lfib(int n){
    int i,f1=1,f2=1,f3;
    printf("1, 1, ");
    for(i=2;i<n;i++){
        f3=f1+f2;
        printf("%d ",f3);
        f1=f2;
        f2=f3;
    }
}

void rswap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void vswap(int a,int b){
    int temp;
    printf("Before V_Swap: a = %d || b = %d \n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("After V_Swap: a = %d || b = %d \n",a,b);
}

int main(){
    int sel,i,n;
    int x=10,y=20;

    do{
    printf("Enter your selection:\n1. fibonacci by loop\n2.fibonacci by recursion\n3.factorial by loop\n");
    printf("4.factorial by recursion\n5.R swap\n6.V swap\n7.EXIT\n");
    scanf("%d",&i);
    switch(i){
        case 1:
            printf("Up till which term? : ");
            scanf("%d",&n);
            lfib(n);
            break;
        case 2:
            printf("Up till which term? : ");
            scanf("%d",&n);
            printf("%d\n",rfib(n));
            break;
        case 3:
            printf("What number's factorial?");
            scanf("%d",&n);
            lfact(n);
            break;
        case 4:
            printf("What number's factorial?");
            scanf("%d",&n);
            printf("%d\n",rfact(n));
            break;
        case 5:
            printf("Before R_Swap: a = %d || b = %d \n",x,y);
            rswap(&x,&y);
            printf("After R_Swap: a = %d || b = %d \n",x,y);
            break;
        case 6:
            vswap(x,y);
            break;
        case 7:
            break;
    }
    printf("Wanna have another try? (Yes => 1 / No => 0) : ");
    scanf("%d",&sel);

    }while(sel==1);
}
