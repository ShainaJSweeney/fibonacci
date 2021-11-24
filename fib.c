#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n;
int *fib;
void *fibo(void *arg){
	fib[0] = 0;
	fib[1] = 1;
	int i;
	for(i=2;i<n;i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	pthread_exit(0);
}

int main(int argc, char *argv[]){
	int x;
	if(argc != 2){
		printf("must input an integer parameter");
		return -1;
	}
	int param = atoi(argv[1]);
	if(param<0){
		printf("%d must be >=0\n", param);
		return -1;
	}
	n = param;
	fib = (int *)malloc(n * sizeof(int));

	pthread_t threadId;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&threadId, &attr, fibo, NULL);
	pthread_join(threadId, NULL);
	printf("Fibonacci: ");
	for(x=0; x<n; x++){
		printf("%d, ", fib[x]);
	}
	printf("\n");
	return 0;
}


