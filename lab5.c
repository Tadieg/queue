#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 4
int queue[CAPACITY];
unsigned int size  = 0;
unsigned int rear  = CAPACITY - 1;  
unsigned int front = 0;
int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();
int main()
{
    int ch, data;
    while (1)
    {
    	printf(" The ff is the queue implementation in array \n");
        printf(" enter 1 for insert \n");
        printf(" enter 2 for delete \n");
        printf(" enter 3 to know the size of the queue\n");
        printf(" enter 4 to display the rear \n");
        printf(" enter 5 to display the front\n");
        printf(" enter 0 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                if (enqueue(data))
                    printf("Successfully inserted");
                else
                    printf("Queue is filled .");
                break;
            case 2:
                data = dequeue();
                if (data ==0)
                    printf("Queue is empty.");
                else
                    printf("The data successfully deleted");
                break;
            case 3: 
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Queue size => %d", size);
                break;
            case 4: 
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Rear => %d", getRear());
                break;
            case 5: 
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Front => %d", getFront());
                break;
            case 0:
                printf("Exiting from app.\n");
                exit(0);
            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }
        printf("\n\n");
    }
}
int enqueue(int data)
{
    if (isFull()) 
    {
        return 0;
    }
    rear = (rear + 1) % CAPACITY;
    size++;
    queue[rear] = data;
    return 1;
}
int dequeue()
{
    int data;
    if (isEmpty())
    {
        return 0;
    }
    data = queue[front];
    front = (front + 1) % CAPACITY;
    size--;
    return data;
}
int isFull()
{
    return (size == CAPACITY);
}
int isEmpty()
{
    return (size == 0);
}
int getFront()
{
    return (isEmpty())   ? 0 : queue[front];
}
int getRear()
{
    return (isEmpty()) ? 0: queue[rear];

}
