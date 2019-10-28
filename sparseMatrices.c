#include <stdio.h>
#include <stdlib.h>

void rswap(int *a,int *b){
    int temp = *a; *a = *b; *b = temp;
}

void arr_cpy(int n, int s[n][3], int t[n]){
    int i;
    for(i=0;i<n;i++){
        t[i] = s[i][2];
    }
}

int max_of_arr(int n, int a[]){                     //RETURNS MAXIMUM COLUMN INDEX
    int i;
    int max = a[0];

    for(i=1;i<n;i++){
        if(a[i]>max)
            max = a[i];
    }

    return max;
}

void swap_row(int *a, int *b ,int *c, int *p, int *q, int *r){
    int temp = *a;
    *a = *p;
    *p = temp;

    temp = *b;
    *b = *q;
    *q = temp;

    temp = *c;
    *c = *r;
    *r = temp;
}

void get_mat(int p,int matrix[][3]){              //GETS INPUT FOR A MATRIX
    int i;
	for(i=0 ; i<p ; i++){
        printf("Enter row no. : ");
        scanf("%d",&matrix[i][1]);
        printf("Enter Column no. : ");
        scanf("%d",&matrix[i][2]);
        printf("Enter Element at %d, %d : ",matrix[i][1],matrix[i][2]);
        scanf("%d",&matrix[i][0]);
	}
}

void put_sp_mat(int p,int q,int matrix[][q]){              //PRINTS A SPARSE MATRIX
    int i,j;
    printf("====================================================\n");
    for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
    printf("\n\n");
}

void transpose(int p, int sp_mat[][3]){
    int i;
    for(i=0;i<p;i++){
        rswap(&sp_mat[i][1],&sp_mat[i][2]);
    }
}

void sort_by_row(int p,int sp_mat[][3],char rev){
    int i,j;
    for(i=0;i<p;i++){
        for(j=0;j<p;j++){
            if(sp_mat[i][1]<sp_mat[j][1]){
                swap_row(&sp_mat[i][0],&sp_mat[i][1],&sp_mat[i][2], &sp_mat[j][0],&sp_mat[j][1],&sp_mat[j][2]);
            }
            else if(sp_mat[i][1]==sp_mat[j][1]){
                if(sp_mat[i][2]<sp_mat[j][2]){
                    swap_row(&sp_mat[i][0],&sp_mat[i][1],&sp_mat[i][2], &sp_mat[j][0],&sp_mat[j][1],&sp_mat[j][2]);
                }
            }
        }
    }
}

int add_mat(int p,int q,int m1[p][3],int m2[q][3],int m3[][3],int op){
    int i=0,j=0,k=0;
    sort_by_row(p,m1,'f');
    sort_by_row(q,m2,'f');
    for(i=0;i<p+q;i++){
        m3[i][0] = 0;
        m3[i][1] = 0;
        m3[i][2] = 0;
    }


    i=0;
    while( i < p && j < q ){
        if(m1[i][1] == m2[j][1]){                   //IF ROWS ARE EQUAL

            if(m1[i][2] == m2[j][2]){               //CHECK FOR EQUAL COL.
                m3[k][1] = m1[i][1];                //ROW
                m3[k][2] = m1[i][2];                //COL
                switch(op){
                case 1:
                    m3[k][0] = m1[i][0] + m2[j][0];     //ELE ADDED
                    break;

                case 0:
                    m3[k][0] = m1[i][0] - m2[j][0];     //ELE SUBBED
                    break;

                default:
                    printf("BAD OP CODE! CHECK ARGUMENTS! \n");
                    break;

                }
                i++;j++;k++;                            //MOV M1,M2
            }
            else if(m1[i][2] < m2[j][2]){           //OR COPY LOWER COLUMN
                m3[k][1] = m1[i][1];                //ROW
                m3[k][2] = m1[i][2];                //COL
                m3[k][0] = m1[i][0];                //ELE
                i++;k++;                                //MOV M1
            }
            else{
                m3[k][1] = m2[j][1];                //ROW
                m3[k][2] = m2[j][2];                //COL
                switch(op){
                case 1:
                    m3[k][0] = m2[j][0];                //ELE ADDED
                    break;
                case 0:
                    m3[k][0] = -1 * m2[j][0];           //ELE SUBBED
                    break;
                default:
                    printf("BAD OP CODE! CHECK ARGUMENTS! \n");
                    break;
                }
                j++;k++;                                //MOV M2
            }
                                                    //INC. M3 SIZE
        }

        else if(m1[i][1] < m2[j][1]){               //COPY THE ONE WITH LOWER ROW
            m3[k][1] = m1[i][1];                    //ROW
            m3[k][2] = m1[i][2];                    //COL
            m3[k][0] = m1[i][0];                    //ELE
            i++;k++;                                //MOV M1 AND INC. M3 SIZE
        }

        else{
            m3[k][1] = m2[j][1];                //ROW
            m3[k][2] = m2[j][2];                //COL
            switch(op){
            case 1:
                m3[k][0] = m2[j][0];                //ELE
                break;
            case 0:
                m3[k][0] = -1 * m2[j][0];
                break;
            default:
                printf("BAD OP CODE! CHECK ARGUMENTS! \n");
                break;
            }
            j++;k++;                            //MOV M2 AND INC. M3 SIZE
        }
    }
    while(i<p){                                 //COPY ALL LEFTOVER ELEMENTS OF M1
        m3[k][1] = m1[i][1];                    //ROW
        m3[k][2] = m1[i][2];                    //COL
        m3[k][0] = m1[i][0];                    //ELE
        i++;k++;                                //MOV M1 AND INC. M3 SIZE
    }
    while(j<q){                             //COPY ALL LEFTOVER ELEMENTS OF M2
        m3[k][1] = m2[j][1];                //ROW
        m3[k][2] = m2[j][2];                //COL
        switch(op){
        case 1:
            m3[k][0] = m2[j][0];                //ELE ADDED
            break;
        case 0:
            m3[k][0] = -1 * m2[j][0];           //ELE SUBBED
            break;
        default:
            printf("BAD OP CODE. CHECK ARGUMENTS.\n");
            break;
        }
        j++;k++;                            //MOV M2 AND INC. M3 SIZE
    }
    return k;
}

void put_n_mat(int p,int a[][3]){
    sort_by_row(p,a,'f');
    int i,j,k=0;
    int temp[p];
    arr_cpy(p,a,temp);

    int x = a[p-1][1], y = max_of_arr(p,temp);
    printf("======================================================\n");
    for(i=0;i<=x;i++){
        for(j=0;j<=y;j++){
            if(i == a[k][1] && j == a[k][2]){
                printf("%d ", a[k][0]);
                k++;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int sel0,sel1;
    int n1=0,n2=0,n3=0;

    int t1[5][3] = {{21,2,1},{40,4,3},{60,6,0},{12,1,2},{24,2,4}};
    int t2[6][3] = {{60,6,0},{26,2,6},{31,3,1},{45,4,3},{55,5,5},{35,3,5}};



    printf("Enter number of elements in Matrix 1:");
    scanf("%d",&n1);
    printf("Enter number of elements in Matrix 2:");
    scanf("%d",&n2);
    int sp1[n1][3],sp2[n2][3],sp3[n1+n2][3];
    do{
        printf("\t\t\t\t======THE SPARSE MATRIX PROGRAM======\n");
        printf("1. ADD TWO SPARSE MATRICES\n2. SUBTRACT TWO SPARSE MATRICES\n3. TRANSPOSE OF A SPARSE MATRIX\n4. CONVERT TO NORMAL\n5. EXIT\n");
        scanf("%d",&sel1);
        switch(sel1){
        case 1:
            get_mat(n1,sp1);
            get_mat(n2,sp2);
            n3 = add_mat(n1,n2,sp1,sp2,sp3,1);
            put_sp_mat(n3,3,sp3);
            break;

        case 2:
            get_mat(n1,sp1);
            get_mat(n2,sp2);
            n3 = add_mat(n1,n2,sp1,sp2,sp3,0);
            put_sp_mat(n3,3,sp3);

            break;

        case 3:
            get_mat(n1,sp1);
            transpose(n1,sp1);
            put_sp_mat(n1,3,sp1);
            break;

        case 4:
            get_mat(n1,sp1);
            put_n_mat(n1,sp1);
            break;

        case 5:
            break;

        default:
            printf("BAD INPUT\n");
            break;
        }
        printf("Do you want to try again? ( 1 => YES || 0 => NO ) :");
        scanf("%d",&sel0);
    }while(sel0 == 1);



    return 0;
}

