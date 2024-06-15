
#pragma once

#define BUFFER_SIZE 10

typedef struct {
    float buffer[BUFFER_SIZE];
    int head;
    int tail;
    int size;
} CircularBuffer;

void initBuffer(CircularBuffer *cb);
bool isFull(CircularBuffer *cb);
bool isEmpty(CircularBuffer *cb);
void push(CircularBuffer *cb, int value);
bool pop(CircularBuffer *cb, int *value);
void printBuffer(CircularBuffer *cb);
float averageBuffer(CircularBuffer *cb);