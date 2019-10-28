#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int front,rear;
    int data[MAX];
}queue;

void init(queue *q){
    q->front = -1;
    q->rear = -1;
}

int isfull(queue q){
    if( q.rear+1 == q.front){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(queue q){
    if(q.front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void display(queue q){
    int i;
    if(isempty(q) == 0){
        for(i = q.front;i < q.rear+1;i = (i + 1)% MAX){
            printf("%d\t",q.data[i]);
        }
    }
    else{
        printf("<Display> : Queue empty!\n");
    }
    printf("\n");
}

void enqueue(queue *q,int x){
    if(isfull(*q) == 1){
        printf("<Enqueue> : Queue full!\n");
    }
    else if(isfull(*q) == 0){
        if(q->front == -1){
            q->front = 0;
        }
        q->rear = (q->rear + 1)% MAX;
        q->data[q->rear] = x;
    }
}

int dequeue(queue *q){
    int temp;
    if(isempty(*q) == 1){
        printf("<Dequeue> : Queue is empty!\n");
    }
    else if(isempty(*q) == 0){
        temp = q->data[q->front];
        if(q->front == q->rear){
            init(q);
            printf("<Dequeue> : Last element, Queue re-initialized!\n");
        }
        else{
            q->front = (q->front+1) % MAX;
        }
    }
    return temp;
}




int main(){
    queue q1,q2;
    init(&q1); init(&q2);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    display(q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    display(q1);
    dequeue(&q1);
    dequeue(&q1);
    display(q1);
    return 0;
}
