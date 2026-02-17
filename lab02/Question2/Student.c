#include "Student.h"
#include <stdlib.h>

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q = malloc(sizeof(MyCircularQueue));
    q->data = malloc(sizeof(int) * k);

    q->capacity = k;
    q->size = 0;
    q->head = 0;
    q->tail = 0;

    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity)
        return false;

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0)
        return false;

    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;

    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;

    int index = obj->tail - 1;
    if (index < 0)
        index += obj->capacity;

    return obj->data[index];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}
