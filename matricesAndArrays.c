#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*      AUTHOR: the.drake1010(AKHIL SINGH)      */

/*
    Three types of functions are used:
        1. Supplementary Functions, which support the actual functions.
        2. Major functions, which are primary to assignment
        3. Driver/Main function, which provides interface to execute all functions.
    Function Purpose is shown by the comment at start of function definition.

    Notations:
        a,b,c are matrices.
        p,q,r,s are used as dimensions(rows/columns) for matrices (p X q) and (r X s).
        o, sel are used as operation selectors in functions with multiple uses.
        i,j,k are used as iterators in loops( Except in "rec_search" ).

*/


                                    //SUPPLEMENTARY FUNCTIONS:

int largest(int a[], int p){                            //RETURNS LARGEST ELEMENT IN AN ARRAY
    int i;
    int max = a[0];
    for (i = 1; i < p; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void get_mat(int p,int q,int matrix[][q]){              //GETS INPUT FOR A MATRIX
    int i,j;
	printf("Enter elements of %d by %d matrix: ",p,q);
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
}

void put_mat(int p,int q,int matrix[][q]){              //PRINTS A MATRIX
    int i,j;

    for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
    printf("\n\n");
}

int rec_srch(int query,int i,int* a,int a_size){        //RECURSION SEARCH IN ARRAY
    if(query == a[i]){
        return i;                   //termination0
    }
    if(i>=a_size){
        return -1;                  //killswitch
    }
    else{
        rec_srch(query,i+1,a,a_size);     //recursive part
    }

}

int is_equal(int p,int q,int a[p][q],int b[p][q]){      //EQUALITY CHECK FOR MATRICES(RETURNS 1 IF TRUE)
    int i,j,flag=1;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            if(a[i][j]!=b[i][j]){
                flag=0;
                break;
            }
        }
    }
    return flag;
}



                                    //MAJOR FUNCTIONS:

void mat_art(int p,int q,int a[p][q],int b[p][q],int c[p][q]){    //ADD SUBTRACT TWO MATRICES
    int i,j,o;
    printf("ADDITION(Press 0) OR SUBSTRACTION(Press 1) ? :");
    scanf("%d",&o);
    get_mat(p,q,a);
    get_mat(p,q,b);
    if(o==0){                                   //addition at o=0
        for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        printf("The sum of given matrices is: \n");
    }
    if(o==1){                                   //subtract at o=1
        for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        printf("The difference of given matrices is: \n");
    }
    put_mat(p,q,c);
}

void mat_tr(int p,int q,int a[p][q],int b[q][p]){                       //TRANSPOSE
    int i,j;
    get_mat(p,q,a);
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            b[j][i] = a[i][j];
        }
    }
    printf("The Transpose of given matrix is: \n");
    put_mat(q,p,b);
}

void mat_mult(int p,int q,int a[p][q],int s,int b[q][s],int c[p][s]){   //MULTIPLICATION
    int i,j,k;
    get_mat(p,q,a);
    get_mat(q,s,b);
    for(i=0;i<p;i++){
        for(j=0;j<s;j++){
            int sum=0;
            for(k=0;k<q;k++){
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    printf("The product of matrices is: \n");
    put_mat(p,s,c);
}

void big_row(int p,int q,int a[p][q]){                                  //MAX OF A ROW
    int i,j,max[p];
    get_mat(p,q,a);
    for(i=0;i<p;i++){
        max[i] = largest(a[i],q);
    }
    printf("input matrix is: \n");
    put_mat(p,q,a);
    printf("Max of each rows is: \n");
    put_mat(1,p,max);
}

int diag_sum(int p,int q,int a[p][q]){                                  //DIAGONAL SUM
    int sel,i,j,sum=0;
    get_mat(p,q,a);
    printf("Which Diagonal's Trace is required?[0 => Major ||| 1 => Minor]\n");
    scanf("%d",&sel);
    if(sel==0){
        for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                if(i==j){
                    sum+=a[i][j];
                }
            }
        }
    }
    else if(sel==1){
        for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                if(i+j==p-1){
                    sum+=a[i][j];
                }
            }
        }
    }
    else{
        printf("The input : %d is invalid!",sel);
    }
    printf("The sum of requested diagonal is : %d",sum);
    return sum;
}

void is_spl(int p,int a[p][p]){                                         //TRIANGULAR CHECK
    int flag=1,i,j,sel;
    get_mat(p,p,a);
    printf("What should I check for? [0 => Lower Triangle ||| 1 => Upper Triangle]");
    scanf("%d",&sel);
    if(sel==0){                         //LWR TRIANGLE
        for(i=0;i<p;i++){
            for(j=i+1;j<p;j++){
                if(a[i][j]!=0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0){
            printf("Not a Lower Triangle matrix!\n");
        }
        else if(flag==1){
            printf("It is a Lower Triangular matrix!\n");
        }
    }
    else if(sel==1){                    //UPR TRIANGLE
        for(i=0;i<p;i++){
            for(j=0;j<i;j++){
                if(a[i][j]!=0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0){
            printf("Not a Upper Triangle matrix!\n");
        }
        else if(flag==1){
            printf("It is a Upper Triangular matrix!\n");
        }
    }
    else{
        printf("Invalid input : %d",sel);
    }
}

void is_sym(int p,int a[p][p]){                                         //SYMMETRIC MATRIX
    int b[p][p];
    mat_tr(p,p,a,b);
    int x = is_equal(p,p,a,b);
    if(x==1){
        printf("The matrix is Symmetric!\n");
    }
    if(x==0){
        printf("The matrix is not Symmetric\n");
    }
}

void arr_ins(int p,int a[]){                                           //ARRAY INSERTION
    int i,ins;
    char sel;
    printf("Is this array newly created? :[Y / N] ");
    scanf("%c",&sel);
    if(sel=='Y' || sel=='y'){
        get_mat(1,p,a);
    }
    printf("Here's how your array looks like right now: \n");
    put_mat(1,p,a);
    printf("\nSo, What element do you want to insert? : ");
    scanf("%d",&ins);
    printf("At what position do you want it? : ");
    scanf("%d",&i);
    a[i-1] = ins;
    printf("Working on it...\nOkay, here's how it looks now...\n");
    put_mat(1,p,a);
}

void arr_del(int p,int a[]){                                           //ARRAY DELETION
    int i,d;
    char sel='n';
    printf("Is this array newly created? :[Y / N] ");
    scanf("%c",&sel);
    if(sel=='Y' || sel=='y'){
        get_mat(1,p,a);
    }
    printf("Here's how your array looks like right now: \n");
    put_mat(1,p,a);
    int s;
    printf("Please enter your selection:\n1. Delete by index\n2. Delete by element\n3. Exit(K/S)\n");
    scanf("%d",&s);
    if(s==1){                                                               //DEL BY INDEX
        printf("Please tell the position at which element is located: ");
        scanf("%d",&d);
        for(i=d-1;i<p;i++){
            a[i]=a[i+1];
        }
        printf("Deletion successful. Here's how your array looks now...\n");
        put_mat(1,p-1,a);
    }
    else if(s==2){                                                          //DEL BY SEARCH
        printf("Please Enter the element to be deleted: ");
        scanf("%d",&d);
        int l = rec_srch(d,0,a,p);
        if(l==-1){
            printf("Lookup unsuccessful...please have a look at the array. Redirecting to program start...: \n");
            put_mat(1,p,a);
            arr_del(p,a);
        }
        else{
            for(i=l;i<p;i++){
                a[i]=a[i+1];
            }
            printf("Deletion successful. Here's how your array looks now...\n");
            put_mat(1,p-1,a);
        }
    }
    else if(s==3){                                                      //RECURSION KILLSWITCH
        printf("arr_del : You have exited the function.\n");
    }
    else{                                                               //INVALID INPUT
        printf("Invalid input: %d.",s);
    }
}


                                    //DRIVER FUNCTION:

int main(){
    int m1[10][10],m2[10][10],m3[10][10];
    int arr[20]={1,2,3,4,5,6,7,8,9,10};                     //DECLARATIONS
    int x,l,m,n,choice,sel;

    do{
        printf ("Enter which operation to perform\n");
        printf("Enter 1. For Addition or subtraction of 2 Matrix\n");
        printf("Enter 2. For Transpose of a Matrix\n");
        printf("Enter 3. For Multiplication of 2 Matrix\n");
        printf("Enter 4. To Find Maximum element in each Row of a Matrix\n");
        printf("Enter 5. To find Trace of Major/Minor Diagonal Elements of Matrix\n");
        printf("Enter 6. To Print Lower/Upper Triangular matrix form of Entered matrix\n");
        printf("Enter 7. To Check if Entered Matrix is Symmetric or not\n");
        printf("Enter 8. To Delete an Element of an Array\n");
        printf("Enter 9. To Insert an element into an Array\n");
        printf("Your Input : ");
        scanf("%d",&choice);


        switch(choice){                                                 //DRIVER SWITCH
        case 1:
            printf("Enter the two dimensions of matrix:(dims should be less than 10!) : ");
            scanf("%d %d",&l,&m);
            mat_art(l,m,m1,m2,m3);
            break;

        case 2:
            printf("Enter the two dimensions of matrix:(dims should be less than 10!) : ");
            scanf("%d %d",&l,&m);
            mat_tr(l,m,m1,m2);
            break;

        case 3:
            printf("Enter the two dimensions of First Matrix:(dims should be less than 10!) : ");
            scanf("%d %d",&l,&m);
            printf("Enter the number of columns of Second Matrix: ");
            scanf("%d",&n);
            mat_mult(l,m,m1,n,m2,m3);
            break;

        case 4:
            printf("Enter the two dimensions of Matrix:(dims should be less than 10!) : ");
            scanf("%d %d",&l,&m);
            big_row(l,m,m1);
            break;

        case 5:
            printf("Enter the two dimensions of Matrix:(dims should be less than 10!) : ");
            scanf("%d %d",&l,&m);
            x=diag_sum(l,m,m1);
            break;

        case 6:
            printf("Enter the dimension of Matrix:(dims should be less than 10!) : ");
            scanf("%d",&l);
            is_spl(l,m1);
            break;

        case 7:
            printf("Enter the dimension of Matrix:(dims should be less than 10!) : ");
            scanf("%d",&l);
            is_sym(l,m1);
            break;

        case 8:
            arr_del(5,arr);
            break;

        case 9:
            arr_ins(5,arr);
            break;

        default:
            break;
        }

        printf("Do you want to : EXIT(Press 0) or RESTART(Press 1) : ");
        scanf("%d",&sel);

    }while(sel==1);

    return 0;
}



