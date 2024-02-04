#include <linux/kernel.h>
#include <linux/syscalls.h>
#define QUEUE_SIZE (256 / sizeof(uint32_t))

static int front = 0, rear = 0;
static long queue[QUEUE_SIZE];

SYSCALL_DEFINE1(enqueue, uint32_t, data) {
	if (front == (rear+1) % QUEUE_SIZE) {
		return -1;
	}
	queue[rear] = data;
	rear = (rear+1) % QUEUE_SIZE;
	return 0;
}

SYSCALL_DEFINE0(dequeue) {
	long data;
	if (front == rear) {
		return -1;
	}
	data = queue[front];
	front = (front+1) % QUEUE_SIZE;
	return data;
}
