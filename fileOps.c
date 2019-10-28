#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

typedef struct{
    char name[50];
    int id;
    int basic,grade;
}emp;

emp ea[20];

int main(){

    FILE *fp;
    emp e,temp;
    int count1=0,check;
    int i,j,hits[15],cpy[15];
    int sel0=0,sel1=0;
    char fname[60],sname[30];

    fp = fopen("EMPLOYEE.dat","rb+");



    do{
        printf("1. Add record\n2. Read Record\n3. Find missing Emp ID\n");
        printf("4. Sort as per Emp Name\n5.Sort as per Emp ID\nPlease Enter your choice:");
        scanf("%d",&sel1);

        switch(sel1){
        case 1:
            fseek(fp,0,SEEK_END);


            printf("Enter ID No. : ");
            fflush(stdin);
            scanf("%d",&e.id);
            printf("Enter the name: ");
            fflush(stdin);
            scanf("%s %s",fname,sname);
            strcat(fname," ");
            strcat(fname,sname);
            strcpy(e.name,fname);
            printf("Enter Basic and grade pay: ");
            fflush(stdin);
            scanf("%d %d",&e.basic,&e.grade);


            fwrite(&e,sizeof(e),1,fp);


            printf("Details recorded successfully!\n");
            count++;
            break;

        case 2:
            rewind(fp);


            printf("ID\t\t\tName\t\t\tBasic Pay\t\tGrade Pay\n");


            while(fread(&e,sizeof(e),1,fp)==1){
                printf("%d\t\t\t%s\t\t%d\t\t\t%d\n",e.id,e.name,e.basic,e.grade);
            }


            break;

        case 3:
            rewind(fp);


            while(fread(&e,sizeof(e),1,fp) == 1){
                cpy[count1++] = e.id;
            }


            printf("\n");

            i=1;j=0;
            check = cpy[1];


            while(i < count1){
                if(cpy[i] != check){
                    printf("Employee No. %d Not Found\n",check);
                    hits[j] = check;

                    check++;

                    j++;
                }
                else{
                    check++;
                    i++;
                }
            }



            if(j==0){
                printf("No Employee Missing\n");
            }
            break;

        case 4:

            count = 0;
            rewind(fp);

            while(fread(&e,sizeof(e),1,fp)!=NULL)
                count++;


            rewind(fp);


            for(i=0;i<count;i++){
                fread(&ea[i],sizeof(e),1,fp);
            }

            for(i=0;i<count-1;i++){
                for(j=0;j<count-i-1;j++){
                    if(strcmp(&ea[j].name,&ea[j+1].name)>0){
                        temp=ea[j];
                        ea[j]=ea[j+1];
                        ea[j+1]=temp;
                    }
                }
            }


            rewind(fp);

            for(i=0;i<count;i++)
                fwrite(&ea[i],sizeof(e),1,fp);


            printf("Records were sorted as per name!\n");
            break;

        case 5:
            count = 0;
            rewind(fp);

            while(fread(&e,sizeof(e),1,fp)!=NULL)
                count++;


            rewind(fp);
            for(i=0;i<count;i++){
                fread(&ea[i],sizeof(e),1,fp);
            }

            for(i=0;i<count;i++){
                for(j=0;j<count;j++){
                    if(ea[i].id < ea[j].id){
                        temp=ea[i];
                        ea[i]=ea[j];
                        ea[j]=temp;
                    }
                }
            }

            rewind(fp);
            for(i=0;i<count;i++)
                fwrite(&ea[i],sizeof(e),1,fp);

            printf("Records were sorted as per ID!\n");
            break;

        case 6:
            fseek(fp,-1*sizeof(e),SEEK_END);
            fread(&e,sizeof(e),1,fp);
            printf("%s\t%d\n",e.name,e.id);

            break;

        default:
            printf("Please try again\n");
            break;
        }
        printf("Another try? (1 => YES || 0 => NO) : ");
        scanf("%d",&sel0);

    }while(sel0 == 1);

    fclose(fp);
    return 0;
}
