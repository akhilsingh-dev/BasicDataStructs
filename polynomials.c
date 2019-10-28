#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{float coef;int exp;}term;

void rswap(term *a,term *b){
    term temp=*a;
    *a=*b;
    *b=temp;
}

int bin_search(int n,int query,term a[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        if(a[mid].exp==query){
            return mid;
        }
        else if(a[mid].exp>query){
            bin_search(n,query,a,low,mid-1);
        }
        else if(a[mid].exp<query){
            bin_search(n,query,a,mid+1,high);
        }
    }
    return -1;
}

int get_poly(term p[11]){
    int i,n;
    printf("How many terms are there? ");
    fflush(stdin);
    scanf("%d",&n);
    fflush(stdin);
    for(i=0;i<n;i++){
        printf("Enter exponent: ");
        scanf("%d",&p[i].exp);
        printf("Enter Co-Efficient: ");
        scanf("%f",&p[i].coef);
    }
    return n;
}

void put_poly(int n,term p[11]){
    int i;

    printf("==================================================\n");
    printf("%.2f x^%d ",p[0].coef,p[0].exp);
    for(i=1;i<n;i++){
        if(p[i].exp!=0){
            if(p[i].coef>0)
                printf("+%.2f x^%d ",p[i].coef,p[i].exp);
            else if(p[i].coef<0)
                printf("%.2f x^%d ",p[i].coef,p[i].exp);
        }
        else if(p[i].exp==0){
            if(p[i].coef>0)
                printf("+%.2f ",p[i].coef);
            else if(p[i].coef<0)
                printf("%.2f ",p[i].coef);
        }

    }
    printf("\n");
    printf("==================================================\n");

}

void sort_poly(int n,term p[11]){
    int i,j,k,max;
    for(i=0;i<n-1;i++){
        max = i;
        for(j=i+1;(j<n);j++){
            if(p[j].exp>p[max].exp)
                max = j;
        }
        rswap(&p[max],&p[i]);
    }

}

int add_poly(int n1,int n2,term p1[11],term p2[11],term p3[11],int op){            // 1 = ADD AND 0 = SUB
    int i=0,j=0,n3;
    int k=0;
    sort_poly(n1,p1);
    sort_poly(n2,p2);
    put_poly(n1,p1);
    put_poly(n2,p2);

    while(i<n1 && j<n2){
        if(p1[i].exp>p2[j].exp){
            p3[k]=p1[i];
            i++;
        }
        else if(p1[i].exp<p2[j].exp){
            switch(op){
            case 0:
                p3[k].coef = p2[j].coef * -1;
                p3[k].exp = p2[j].exp;
                break;
            case 1:
                p3[k]=p2[j];
                break;
            }
            j++;
        }
        else if(p1[i].exp==p2[j].exp){
            switch(op){
            case 0:
                p3[k].exp = p1[i].exp;
                p3[k].coef = p1[i].coef - p2[j].coef;
                break;
            case 1:
                p3[k].exp = p1[i].exp;
                p3[k].coef = p1[i].coef + p2[j].coef;
                break;
            }
            i++; j++;
        }
        k++;
    }
    while(i<n1){
        p3[k]=p1[i];
        i++; k++;
    }
    while(j<n2){
        switch(op){
        case 0:
            p3[k].coef = p2[j].coef * -1;
            p3[k].exp = p2[j].exp;
            break;
        case 1:
            p3[k] = p2[j];
            break;
        }
        j++; k++;
    }
    n3 = k;
    put_poly(n3,p3);
    return n3;
}

int mult_poly(int n1,int n2,term p1[11],term p2[11],term p3[11]){
    if(n1>0 && n2>0){
        int n3=0,i,j,k=0;

        sort_poly(n1,p1);
        sort_poly(n2,p2);

        for(i=0;i<n1;i++){                                      //FOR EVERY ELEMENT IN P1
            for(j=0;j<n2;j++){                                  //TAKE EVERY ELEMENT IN P2
                p3[k].coef = p1[i].coef * p2[j].coef;           //MULTIPLY THE COEEFICIENTS
                p3[k].exp = p1[i].exp + p2[j].exp;              //ADD THE EXPONENTS
                k++;                                            //INCREMENT NUMBER OF TERMS
            }
        }
        n3 = k;
        for(i=0;i<n3;i++){                                      //FOR EVERY ELEMENT IN P3
            if(p3[i].exp==p3[i+1].exp){                         //CHECK IF NEXT ELEMENT HAS SAME POWER
                p3[i].coef += p3[i+1].coef;                     //IF YES, ADD THE COEF.
                for(j=i+1;j<n3;j++){                            //OVERWRITE THE SECOND TERM
                    p3[j] = p3[j+1];
                }
                n3--;                                           //DECREASE NUMBER OF TERMS
            }
        }

        printf("\t\t\tThe product is: \n");
        put_poly(n3,p3);
        return n3;
    }
    else{
        printf("ERROR: BAD POLYNOMIAL. CHECK INPUTS\n");
        return 0;
    }
}

float evaluate(int n1,term p[11],float x){
    float temp,val=0;
    int i;
    for(i=0;i<n1;i++){
        temp = p[i].coef * (pow(x,p[i].exp));
        val += temp;
    }

    return val;
}

int main(){
    term p1[11],p2[11],p3[11];
    int n1=0,n2=0,n3=0;
    int sel0=0,sel1;
    float x1,x;



    do{

    printf("\t\t\t=========  POLYNOMIAL OPERATIONS  ==========\n");
    printf("1.ADD TWO POLYNOMIALS\n2.SUBTRACT TWO POLYNOMIALS\n3.MULTIPLY TWO POLYNOMIALS\n");
    printf("4.EVALUATE A POLYNOMIAL\n5.EXIT\nPLEASE ENTER YOUR CHOICE: ");
    scanf("%d",&sel1);
    switch(sel1){
    case 1:
        n1 = get_poly(p1);
        n2 = get_poly(p2);
        n3 = add_poly(n1,n2,p1,p2,p3,1);
        break;

    case 2:
        n1 = get_poly(p1);
        n2 = get_poly(p2);
        n3 = add_poly(n1,n2,p1,p2,p3,0);
        break;

    case 3:
        n1 = get_poly(p1);
        n2 = get_poly(p2);
        n3 = mult_poly(n1,n2,p1,p2,p3);
        break;

    case 4:
        n1 = get_poly(p1);
        printf("Evaluate : \n");
        put_poly(n1,p1);
        printf("At : ");
        fflush(stdin);
        scanf("%f",&x);
        x1 = evaluate(n1,p1,x);
        printf("Value of polynomial at x = %.2f is %.3f\n",x,x1);
        break;

    case 5:
        break;

    default:
        printf("BAD INPUT! PLEASE TRY AGAIN!\n");
        break;
    }

    printf("Do you want to try again? (1 => YES || 0 => NO) : ");
    scanf("%d",&sel0);
    }while(sel0 == 1);

    return 0;
}
