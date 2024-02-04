#include <stdio.h>
#include <unistd.h>
#define __NR_new_syscall 451

int main(){
	int result = syscall(__NR_new_syscall, 10);
	printf("result: %d\n", result);
	return 0;
}
