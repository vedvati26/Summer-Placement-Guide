int Queue::push(int element) {
    if (isFull) {
        return -1;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = element;
    if (rear == front) {
        isFull = true;
    }

    return 1;
}
int Queue::pop() {
    if (isEmpty()) {
        return -1;
    }

    front = (front + 1) % capacity;
    isFull = false;

    return 1;
}
