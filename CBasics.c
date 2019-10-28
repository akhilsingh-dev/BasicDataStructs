#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_prime(){
	int flag=0,n,i;
	printf("enter no. to be checked: ");
	scanf("%d",&n);
	for(i=2;i<n;i++){
		if(n<2){
			flag=2;
			break;
		}
		else if(n==2){
			flag=1;
			break;
		}
		else if(n%i==0){
			flag=0;
			break;
		}
	}
	if(flag==0)
	printf("Composite\n");
	if(flag==1)
	printf("Prime\n");
	if(flag==2){
		printf("Not determined\n");
	}
}

void check_leap(){
	int n;
		printf("Which year?");
		scanf("%d",&n);


	if(n%4==0 && n%100!=0){
		printf("Leap year\n");
	}
	else if(n%400==0){
		printf("Leap year\n");
	}
	else{
		printf("Not a leap year\n");
	}
}

void prnt_prime(){
	int flag=0,num,i,j,k=0,l=0;
	printf("enter no. to be checked: ");
	scanf("%d",&num);
	int prime[num/2];
	int comp[num];
	for(i=2;i<num;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				flag=0;
				break;
			}
			else{
				flag=1;
			}
		}
		if(flag==1){
			prime[k]=i;
			k++;
		}
		if(flag==0){
			comp[l]=i;
			l++;
		}
	}

	for(i=0;i<k;i++){
		printf("%d\t",prime[i]);
	}
	printf("\n\n\n");
	for(i=0;i<l;i++){
		printf("%d\t",comp[i]);
	}
}

void max_of_three(){
	int a, b, c;
	printf("Enter three nos.:  ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>=b && a>=c){
		printf("greatest no. = %d\n",a);
	}
	if(a>=b && a<c){
		printf("greatest no. = %d\n",c);
	}
	if(a<b && b>=c){
		printf("greatest no. = %d\n",b);
	}
	if(a<b && b<c){
		printf("greatest no. = %d\n",c);
	}
}

void si(){
	float p, r, n;
	printf("Enter Principle, RoI and no. of years:  ");
	scanf("%f %f %f",&p,&r,&n);
	printf("SI = %f",p*r*n/100);
}

void bindec(){
	int bin;
    int dec_value = 0;
    int base = 1;
    printf("enter a binary number: ");
	scanf("%d",&bin);
    int temp = bin;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp/10;

        dec_value += last_digit*base;

        base = base*2;
    }
    printf("Decimal equivalent = %d",dec_value);

}
void decoct(){
    int j,dec;
    printf("Enter Decimal number: ");
    scanf("%d",&dec);
    int oct[100];
    int i = 0;
    while (dec != 0) {
        oct[i] = dec % 8;
        dec = dec / 8;
        i++;
    }
    printf("Octal Equivalent is : ");
    for (int j = i - 1; j >= 0; j--){
        printf("%d",oct[j]);
    }
}

void dig_rev(){
	char scn[20];
	printf("Enter a number:");
	scanf("%s",scn);
	printf("Reversed number = %s",strrev(scn));
}
void floyd(){
	int j,i,n,c=1;
	printf("How many nos.? : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			printf(" %d ",c);
			c++;
		}
		printf("\n");
	}
}
void bill(){
	int unit,temp;
	float tax,fs,total;
	printf("Enter units consumed: ");
	scanf("%d",&unit);
	temp=unit;
	if (temp <= 50){
		total = 0.5*temp;
	}
	else if(temp > 50 && temp <= 150){
		temp-=50;
		total = 25 + temp*0.75;
	}
	else if(temp > 150 && temp <= 250){
		temp-=150;
		total = 100+temp*1.2;
	}
	else if(temp > 250){
		temp-=250;
		total = 220+temp*1.5;
	}
	fs = total *0.2;
	tax = total *0.1;
	total+=fs+tax;
	printf("Total payable amt. = %0.2f",total);
}



int main(){
	int sel,i,j;
	do{
    printf("Enter your selection: \n1.check for primalty\n2.print all primes\n3.check leap year\n4.max of three\n");
    printf("5.Simple interest\n6.Binary to Decimal\n7.Digital reversal\n8.Floyd triangle\n9.Bill Calc\n");
    printf("10.decimal to octal\n11.EXIT");
    scanf("%d",&i);
    switch(i){
    case 1:
        check_prime();
        break;
    case 2:
        prnt_prime();
        break;
    case 3:
        check_leap();
        break;
    case 4:
        max_of_three();
        break;
    case 5:
        si();
        break;
    case 6:
        bindec();
        break;
    case 7:
        dig_rev();
        break;
    case 8:
        floyd();
        break;
    case 9:
        bill();
        break;
    case 10:
        decoct();
        break;

    case 11:
        break;
    }
    printf("Wnat to try again? (Yes => 1 / No => 0) : ");
    scanf("%d",&sel);
    }while(sel==1);

	return 0;
}
