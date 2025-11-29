//implementation of circular queue
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 6
#define MESSAGE_LENGTH 100

typedef struct {
    char content[MESSAGE_LENGTH];
}Message;

typedef struct {
    Message queue[QUEUE_SIZE];
    int front;
    int rear;
    int count;
}MessageQueue;

void initMessageQueue(MessageQueue* mq, int n){
    mq->front=0;
    mq->rear=n-1;
    mq->count=n;
}

/*
MENU
1. send_message - enqueue
2. recieve_message -dequeue
3. latest_message
4. earliest_message
5. empty_queue
6. display_queue
*/

void send_message(MessageQueue* mq){
    if (mq->count>QUEUE_SIZE){
        printf("Queue is full - overflow!");
        return;
    }
    mq->rear= (mq->rear + 1)% QUEUE_SIZE;

    Message * message = &mq->queue[mq->rear];
    printf("Enter the message: ");
    scanf("%s", message->content);

    mq->rear++;
    mq->queue[mq->rear]=message->content;
}


void MENU(){
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case (1):{
            send_message(&mq);
            break;
        }
        case (2):{
            recieve_message();
            break;
        }
        case (3):{
            latest_message();
            break;
        }
        case (4):{
            earliest_message();
            break;
        }
        case (5):{
            empty_queue();
            break;
        }
        case (6):{
            display_queue();
            break;
        }
        case (7):{
            return;
        }
    }
    MENU();
}

int main(){  
    printf("Enter the number of elements in the queue");
    int n;
    scanf("%d", &n);

    MessageQueue myQueue;
    initMessageQueue(&myQueue, n);

    printf("MENU\n 1. send_message - enqueue\n 2. recieve_message -dequeue\n 3. latest_message\n 4. earliest_message\n 5. reached_limit\n 6. empty_queue\n 7. display_queue 8. Exit\n");
    MENU();
}