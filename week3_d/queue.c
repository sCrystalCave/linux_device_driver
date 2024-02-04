#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __NR_enqueue 451
#define __NR_dequeue 452

int main(int argc, char *argv[]) {
	long data, result;
	if (argc == 3 && !strcmp(argv[1], "enqueue")) {
		data = atol(argv[2]);
		result = syscall(__NR_enqueue, data);
		if (result != 0) {
			fprintf(stderr, "Failed to push!\n");
		}
	} else if (argc == 2 && !strcmp(argv[1], "dequeue")) {
		result = syscall(__NR_dequeue);
		if (result != -1) {
			printf("Value : %ld\n", result);
		} else {
			fprintf(stderr, "Failed to pop!\n");
		}
	} else {
		fprintf(stderr, "Usage : %s <enqueue| dequeue>"
				"[data]\n", argv[0]);
		return -1;
	}
	return 0;
}
