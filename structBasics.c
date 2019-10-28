#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*   AUTHOR: the.drake1010(AKHIL SINGH)     */

int i_count=0;


struct student{
    char fname[15],sname[15];
    long long int prn;
    float p,c,m,total;
};
struct student s[10];


//SUPPLEMENTARY FUNCTIONS:

struct student get_stud(){
    struct student a;
    printf("Please enter the details as prompted...\n");
    printf("Enter name(max 30 char) :  ");
    fflush(stdin);
    scanf("%s %s",&a.fname,&a.sname);
    fflush(stdin);
    printf("Enter PRN(max 10 char) :  ");
    scanf("%lld",&a.prn);
    printf("Enter P,C and M : ");
    scanf("%f %f %f",&a.p,&a.c,&a.m);
    a.total = a.p+a.c+a.m;
    printf("Details successfully entered!\n\n\n");
    return a;
}

void put_stud(struct student s){
    printf("\n==========================================================================================\n");
    printf("Student's name: ");
    printf("%s %s",s.fname,s.sname);
    printf("\nPRN : %lld\nPhysics : %.2f\nChemistry: %.2f\nMaths: %.2f\nTotal: %.2f\n",s.prn,s.p,s.c,s.m,s.total);
}

long long int get_prn(){
    long long int prn;
    printf("Enter PRN: ");
    scanf("%lld",&prn);
    return prn;
}

void get_name(struct student *a){
    printf("Enter Name(Max 30 char.): ");
    scanf("%s %s",a->fname,a->sname);
}

void r_swap(struct student *a, struct student *b){
    struct student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


//MAJOR FUNCTIONS:
int search(){
    int x,i;
    printf("How do you want to search:\n1. By PRN\n2. By Name\n");
    scanf("%d",&x);
    if(x==1){
        long long int p;
        p = get_prn();
        for(i=0;i<i_count;i++){
            if(p == s[i].prn){
                printf("Lookup successful!\n");
                return i;
                break;
            }
        }
    }
    if(x==2){
        char query[30];
        printf("Enter First name only: ");
        scanf("%s",&query);
        for(i=0;i<i_count;i++){
            int l = strcmp(query,s[i].fname);
            if(l==0){
                return i;
                break;
            }
        }
    }
}

struct student mod_obj(){
    struct student a;
    int sel, ch;
    printf("Press 1 to modify name\nPress 2 to modify PRN\nPress 3 to modify Marks\nYour selection: ");
    scanf("%d",&sel);
    switch(sel){
    case 1:
        get_name(&a);
        printf("Details changed successfully!\n");
        break;
    case 2:
        a.prn = get_prn();
        printf("Details changed successfully!\n");
        break;
    case 3:
        printf("Which marks do you want to Enter? (1. P || 2. C || 3. M)? : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter marks of Physics: ");
            scanf("%f",&a.p);
            break;
        case 2:
            printf("Enter marks of Chemistry: ");
            scanf("%f",&a.c);
            break;
        case 3:
            printf("Enter marks of Maths: ");
            scanf("%f",&a.m);
            break;
        case 4:
            break;
        }
        a.total = a.p + a.c + a.m;
        break;
    default:
        printf("Invalid input! Please try again.\n");
    }
    return a;
}

int sort_by_mks(){
    int sort_stat,i,j;
    float temp;
    for(i=0;i<i_count;i++){
        temp = s[i].total;
        j=i-1;
        while(j>=0 && s[j].total<temp){
            r_swap(&s[j],&s[j+1]);
            j--;
        }
    }
    sort_stat = 0;
    return sort_stat;
}

int sort_by_name(){
    int i,j,k,l,sort_stat;
    for(i=0;i<i_count;i++){
        for(j=i+1;j<i_count;j++){
            if(strcmp(s[i].fname,s[j].fname)>0){
                r_swap(&s[i],&s[j]);
            }
        }
    }
    sort_stat = 0;
    return sort_stat;
}

//DRIVER FUNCTION:

int main(){

    int n,i,x,temp;
    int stat_trak[10];
    int sel,a;

    do{
    printf("Please enter number corresponding to your operation: \n");
    printf("1.Create instance\n2.Search an instance\n3.Delete instance\n");
    printf("4.Modify an instance\n5.Print all instances\n6.Sort by Marks\n7.Sort by Name\n8.Exit\n");
    scanf("%d",&x);


    switch(x){
    case 1:                                                     //Create
        printf("how many students to enter: ");
        scanf("%d",&n);
        temp = i_count;
        for(i=temp;i<n+temp;i++){
            s[i] = get_stud();
            i_count++;
        }
        break;

    case 2:
        if(i_count>0){                                                        //SEARCH
            a = search();
            put_stud(s[a]);
        }
        else{
            printf("There are no students to search from! \n");
        }
        break;

    case 3:                                                     //DELETE
        if(i_count>0){
            a = search();
            for(i=a;i<i_count;i++){
                s[i]=s[i+1];
            }
            i_count--;
        }
        else{
            printf("There are no students to delete! \n");
        }
        break;

    case 4:                                                     //MODIFY
        if(i_count>0){
            a = search();
            printf("You are trying to modify data of : \n");
            put_stud(s[a]);
            s[a] = mod_obj();
        }
        else{
            printf("There are no students to modify data! \n");
        }
        break;

    case 5:                                                     //PRINT
        if(i_count>0){
            for(i=0;i<i_count;i++){
                put_stud(s[i]);
            }
        }
        else{
            printf("\n\n\t\t\t\tTHERE ARE NO STUDENTS TO PRINT! \n");
        }
        break;

    case 6:
        if(i_count>0){
            stat_trak[0]=sort_by_mks();
            printf("Exit Status of Function: %d\n",stat_trak[0]);
            printf("The Students are sorted as per their totals\n");        //SORT BY TOTAL
        }
        else{
            printf("\n\n\t\t\t\tTHERE ARE NO STUDENTS TO SORT! \n");
        }
        break;

    case 7:
        if(i_count>0){
            stat_trak[0]=sort_by_name();
            printf("Exit Status of Function: %d\n",stat_trak[0]);
            printf("The Students are sorted as per their names\n");         //SORT BY NAMES
        }
        else{
            printf("\n\n\t\t\t\tTHERE ARE NO STUDENTS TO SORT! \n");
        }
        break;
    }
    printf("Want to have another try?(1/0) : ");
    fflush(stdin);
    scanf("%d",&sel);
    fflush(stdin);

    }while(sel==1);

    printf("Final Global Count : %d",i_count);
    return 0;
}
