#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

/*
    It has two structs working as stacks.

    "stack" is a character stack.
    All functions with no prefixes are related to stack. Eg : (push, pop)

    "intstack" is an integer stack.
    All functions with prefix "i_" are related to intstack. Eg : (i_push, i_pop)

    The functions with return type int and no particular return motive usually return statuses of execution for further scaling and easier debugging.

    These are the times when you understand the importance of classes and function overloading  :'(
*/

typedef struct {
    char data[MAX];
    int top;
}stack;

typedef struct {
    int data[MAX];
    int top;
}intstack;


int init(stack *s);
int isfull(stack s);
int isempty(stack s);
int push(stack *s, char x);
char pop(stack *s);
void display(stack s);



int i_init(intstack *s);
int i_isfull(intstack s);
int i_isempty(intstack s);
int i_push(intstack *s, int x);
int i_pop(intstack *s);
void i_display(intstack s);



int op_prec(char x);
int in_to_post(char source[],stack *s,char target[]);
int in_to_pre(char source[],stack *s,char target[]);
int post_eval(char source[],intstack *s);
void switch_braces(char source[]);


int main(){
    int i;
    char expr[25],post[25],pre[25];
    stack s1;
    init(&s1);

    fflush(stdin);
    printf("Please Enter the infix expression: ");
    gets(expr);
    printf("The input expression is : \n");
    puts(expr);

    int n_post = in_to_post(expr,&s1,post);
    int n_pre = in_to_pre(expr,&s1,pre);
    printf("\n\n\n\t\t\tFINAL ANSWER:\n");
    printf("POST : %s\n",post);
    printf("PRE : %s\n",pre);



    intstack s2;
    i_init(&s2);
    printf("Please enter the postfix expression to be evaluated : ");
    fflush(stdin);
    gets(expr);
    printf("Entered expression is: ");
    puts(expr);
    post_eval(expr,&s2);

    return 0;
}


int init(stack *s){
    s->top = -1;
    if(s->top == -1){
        printf("<init> : Stack initialized successfully!\n");
        return 0;
    }
    return 1;
}

int isempty(stack s){
    if(s.top == -1)
        return 1;
    else if(s.top > -1 && s.top < MAX){
        return 0;
    }
    else{
        printf("<isempty> : Unexpected top pointer. Check initialization!\n");
        return -1;
    }
}

int isfull(stack s){
    if(s.top == MAX-1){
        printf("<isfull> : Stack Full!\n");
        return 1;
    }
    else if(s.top >= MAX){
        return -1;
        printf("<isfull> : Undefined Stack Behaviour!\n");
    }
    else{
        return 0;
    }

}

void display(stack s){
    int i;
    if(isempty(s)==0){
        for(i = 0;i <= s.top;i++){
            printf("%c ",s.data[i]);
        }
        printf("\n");
    }
    else if(isempty(s) == 1){
        printf("<display> : Stack is Empty!\n");
    }
    else{
        printf("<display> : Undefined Stack Behaviour!\n");
    }
}

int push(stack *s,char x){
    if(isfull(*s) == 1){
        printf("<push> : Can't Push, Stack is full!\n");
        return 0;
    }
    else{
        (*s).top++;
        s->data[s->top] = x;
        printf("<push> : Element added successfully!\n");
        return 1;
    }
}

char pop(stack *s){
    char temp;
    if(isempty(*s) == 0){
        printf("<pop> : Element popped successfully!\n");
        temp = s->data[s->top];
        (s->top)--;
    }
    else{
        printf("<pop> : Can't Pop.Stack is empty!\n");
        temp = 0;
    }
    return temp;
}


//INT STACK OPS...

int i_init(intstack *s){
    s->top = -1;
    if(s->top == -1){
        printf("<init> : Stack initialized successfully!\n");
        return 0;
    }
    return 1;
}

int i_isfull(intstack s){
    if(s.top == MAX-1){
        printf("<isfull> : Stack Full!\n");
        return 1;
    }
    else if(s.top >= MAX){
        return -1;
        printf("<isfull> : Undefined Stack Behaviour!\n");
    }
    else{
        return 0;
    }
}

int i_isempty(intstack s){
    if(s.top == -1)
        return 1;
    else if(s.top > -1 && s.top < MAX){
        return 0;
    }
    else{
        printf("<isempty> : Unexpected top pointer. Check initialization!\n");
        return -1;
    }
}

int i_push(intstack *s, int x){
    if(i_isfull(*s) == 1){
        printf("<push> : Can't Push, Stack is full!\n");
        return 0;
    }
    else{
        (*s).top++;
        s->data[s->top] = x;
        printf("<push> : Element added successfully!\n");
        return 1;
    }
}

int i_pop(intstack *s){
    int temp;
    if(i_isempty(*s) == 0){
        printf("<pop> : Element popped successfully!\n");
        temp = s->data[s->top];
        (s->top)--;
    }
    else{
        printf("<pop> : Can't Pop.Stack is empty!\n");
        temp = -111111111;
    }
    return temp;
}

void i_display(intstack s){
    int i;
    if(i_isempty(s)==0){
        for(i = 0;i <= s.top;i++){
            printf("%d ",s.data[i]);
        }
        printf("\n");
    }
    else if(i_isempty(s) == 1){
        printf("<display> : Stack is Empty!\n");
    }
    else{
        printf("<display> : Undefined Stack Behaviour!\n");
    }
}


// AFTER 12 FUNCTIONS FINALLY...HERE WE GO...



int op_prec(char x){
    //printf("char scanned: %c \n",x);
    switch(x){

    case ')':
        return -6;
        break;

    case '(':
        printf("<op_prec> : Round braces!\n");
        return -5;
        break;

    case ']':
        return -4;
        break;

    case '[':
        printf("<op_prec> : Square braces!\n");
        return -3;
        break;

    case '}':
        return -2;
        break;

    case '{':
        printf("<op_prec> : Curly braces!\n");
        return -1;
        break;


    case '-':
    case '+':
        printf("<op_prec> : Add/Sub!\n");
        return 1;
        break;

    case '*':
    case '/':
        printf("<op_prec> : Mult/Div!\n");
        return 2;
        break;

    case '^':
    case '|':
        printf("<op_prec> : AND/OR!\n");
        return 3;
        break;

    default:
        printf("<op_prec> : operator encountered!\n");
        return 0;

    }
}

int in_to_pre(char source[],stack *s,char target[]){
    int t_count = -1;
    strrev(source);
    //printf("Rev Source : %s\n",source);
    switch_braces(source);
    //printf("After switching braces : %s\n",source);
    t_count = in_to_post(source,s,target);
    target[t_count+1] = '\0';


    //printf("Target string before rev : %s\n",target);
    strrev(target);
    //printf("Reversing target: %s\n",target);
    return t_count;
}

void switch_braces(char source[]){
    int i;
    for(i=0;source[i]!='\0';i++){
        switch(source[i]){
        case '(':
            source[i] = ')';
            break;
        case ')':
            source[i] = '(';
            break;
        case '[':
            source[i] = ']';
            break;
        case ']':
            source[i] = '[';
            break;
        case '{':
            source[i] = '}';
            break;
        case '}':
            source[i] = '{';
            break;
        default:
            break;
        }
    }
}

int in_to_post(char source[],stack *s,char target[]){
    int i,prec,temp0;
    char garb;
    int t_count = -1;
    for(i=0;source[i]!='\0';i++){
        prec = op_prec(source[i]);
        if(prec == 0){                      //Is an operand, direct target append
            t_count++;
            target[t_count] = source[i];
        }

        else if(prec > 0){                  //If it is an operation...
            if(isempty(*s) == 1){           //If char stack empty, direct push
                push(s,source[i]);
            }
            else if(isempty(*s) == 0){              //If not empty, check previous precedence
                if(op_prec(s->data[s->top]) < prec){                   //if less, append
                    push(s,source[i]);
                }


                else{                               //otherwise pop till higher level obtained
                    while(op_prec(s->data[s->top]) >= prec){
                        t_count++;
                        target[t_count] = pop(s);
                    }
                    push(s,source[i]);
                }

            }
        }
        else if(prec < 0){                      //If a brace is encountered...
            if(-1*prec % 2 == 1){               //If it is an opening brace push it onto the stack
                push(s,source[i]);
            }
            else if(-1*prec % 2 == 0){          //If it is a closing brace...
                while(op_prec(s->data[s->top]) != prec + 1){    //pop till similar opening brace is encountered
                    t_count++;
                    target[t_count] = pop(s);
                }
                garb = pop(s);                  //final pop to eliminate the opening brace
            }
        }
    //printf("\n");
    //display(*s);
    //printf("\n");

    }
    while(isempty(*s) != 1){
        t_count++;
        target[t_count] = pop(s);
    }
    target[t_count+1] = '\0';
    return t_count;
}

int post_eval(char source[],intstack *s){
    char* e = &source[0];
    int n1=0,n2=0,n3=0;
    int num;

    while(*e != '\0'){
        if(isdigit(*e)){
            num = *e - 48;
            i_push(s,num);
        }
        else{
            n1 = i_pop(s);
            n2 = i_pop(s);
            switch(*e){
            case '+':
                n3 = n1 + n2;
                break;

            case '-':
                n3 = n2 - n1;
                break;

            case '*':
                n3 = n1 * n2;
                break;

            case '/':
                n3 = n2 / n1;
                break;

            }
            i_push(s,n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",source,i_pop(s));
}

