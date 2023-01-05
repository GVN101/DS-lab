#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Node;

typedef struct {
    Node heap[MAX_SIZE];
    int size;
} PriorityQueue;

void init(PriorityQueue *q) {
    q->size = 0;
}

void push(PriorityQueue *q, int data, int priority) {
    if (q->size >= MAX_SIZE) {
        printf("Error: Queue is full\n");
        return;
    }

    Node n;
    n.data = data;
    n.priority = priority;

    q->heap[q->size] = n;

    int current = q->size;
    int parent = (current - 1) / 2;

    while (q->heap[current].priority > q->heap[parent].priority) {
        Node temp = q->heap[current];
        q->heap[current] = q->heap[parent];
        q->heap[parent] = temp;

        current = parent;
        parent = (current - 1) / 2;
    }

    q->size++;
}

void pop(PriorityQueue *q) {
    if (q->size <= 0) {
        printf("Error: Queue is empty\n");
        return;
    }

    q->heap[0] = q->heap[q->size - 1];
    q->size--;

    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;

        if (left >= q->size) {
            break;
        }

        int max = left;
        if (right < q->size && q->heap[right].priority > q->heap[left].priority) {
            max = right;
        }

        if (q->heap[current].priority < q->heap[max].priority) {
            Node temp = q->heap[current];
            q->heap[current] = q->heap[max];
            q->heap[max] = temp;

            current = max;
        } else {
            break;
        }
    }
}

int top(PriorityQueue *q) {
    return q->heap[0].data;
}

int main() {
    PriorityQueue q;
    init(&q);

    push(&q, 1, 2);
    push(&q, 2, 3);
    push(&q, 3, 1);

    printf("%d\n", top(&q));  // prints 3
    pop(&q);
    printf("%d\n", top(&q));  // prints 2
    pop(&q);
    printf("%d\n", top(&q));  // prints 1

    return 0;
}