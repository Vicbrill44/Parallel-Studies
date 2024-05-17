#include <stdio.h>
#include <cuda.h>

/* Device code: runs on GPU */
__global__ void Hello(void) {

    printf("Hello from thread %d!\n", threadIdx.x);

}


/* Host code: runs on CPU */
int main(int argc, char *argv[]) {
    int thread_count;
    thread_count = strtol(argv[1],NULL, 10);

    Hello <<<2, thread_count/2 >>>();

    cudaDeviceSynchronize(); //wait for GPU to finish
    
    return 0; 

}