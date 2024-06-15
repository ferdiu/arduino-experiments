
#include "cb.hpp"

// Initialize the circular buffer
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->size = 0;
}

// Check if the buffer is full
bool isFull(CircularBuffer *cb) {
    return cb->size == BUFFER_SIZE;
}

// Check if the buffer is empty
bool isEmpty(CircularBuffer *cb) {
    return cb->size == 0;
}

// Add an item to the buffer, overwriting the oldest data if the buffer is full
void push(CircularBuffer *cb, int value) {
    cb->buffer[cb->head] = value;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    if (isFull(cb)) {
        cb->tail = (cb->tail + 1) % BUFFER_SIZE; // Overwrite the oldest data
    } else {
        cb->size++;
    }
}


// Remove an item from the buffer
bool pop(CircularBuffer *cb, int *value) {
    if (isEmpty(cb)) {
        printf("Buffer is empty, cannot pop\n");
        return false;
    }
    *value = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->size--;
    return true;
}

// Print the contents of the buffer
void printBuffer(CircularBuffer *cb) {
    printf("Buffer: ");
    for (int i = 0; i < cb->size; i++) {
        int index = (cb->tail + i) % BUFFER_SIZE;
        printf("%d ", cb->buffer[index]);
    }
    printf("\n");
}

// Calculate the average of values in the buffer
float averageBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) return 0.0;

    int sum = 0;
    for (int i = 0; i < cb->size; i++) {
        int index = (cb->tail + i) % BUFFER_SIZE;
        sum += cb->buffer[index];
    }

    return (float)sum / cb->size;
}