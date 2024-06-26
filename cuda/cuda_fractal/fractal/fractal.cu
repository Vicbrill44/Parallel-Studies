#include <stdio.h>
#include <stdlib.h>
#include "cuda.h"
#include "fractal.h"
#include "timer.h"

static const double Delta = 0.001;
static const double xMid =  0.23701;
static const double yMid =  0.521;

__global__ void computeFractal(unsigned char *pic, int width, int height, double xMid, double yMid, double Delta, int num_frames) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int frame = blockIdx.z * blockDim.z + threadIdx.z;

    if (col >= width || row >= height || frame >= num_frames) return;

    double aspect_ratio = (double)width / height;
    double delta = Delta * pow(0.98, frame);  
    double x0 = xMid - delta * aspect_ratio;
    double y0 = yMid - delta;
    double dx = 2.0 * delta * aspect_ratio / width;
    double dy = 2.0 * delta / height;

    double cx = x0 + col * dx;
    double cy = y0 + row * dy;
    double x = cx;
    double y = cy;
    int depth = 256;

    double x2, y2;
    do {
        x2 = x * x;
        y2 = y * y;
        y = 2 * x * y + cy;
        x = x2 - y2 + cx;
        depth--;
    } while ((depth > 0) && ((x2 + y2) < 5.0));

    pic[frame * height * width + row * width + col] = (unsigned char)depth;
}


int main(int argc, char *argv[]) {
    double start, end;
    printf("Fractal v1.6 [CUDA]\n");

    /* read command line arguments */
    if (argc != 4) {fprintf(stderr, "usage: %s height width num_frames\n", argv[0]); exit(-1);}
    int width = atoi(argv[1]);
    if (width < 10) {fprintf(stderr, "error: width must be at least 10\n"); exit(-1);}
    int height = atoi(argv[2]);
    if (height < 10) {fprintf(stderr, "error: height must be at least 10\n"); exit(-1);}
    int num_frames = atoi(argv[3]);
    if (num_frames < 1) {fprintf(stderr, "error: num_frames must be at least 1\n"); exit(-1);}
    printf("Computing %d frames of %d by %d fractal\n", num_frames, width, height);


    size_t size = num_frames * height * width * sizeof(unsigned char);
    unsigned char *d_pic;
    cudaMalloc(&d_pic, size);

    dim3 threadsPerBlock(16, 16, 1);
    dim3 numBlocks((width + threadsPerBlock.x - 1) / threadsPerBlock.x,
                   (height + threadsPerBlock.y - 1) / threadsPerBlock.y,
                   (num_frames + threadsPerBlock.z - 1) / threadsPerBlock.z);

     /* start time */
    GET_TIME(start);

    computeFractal<<<numBlocks, threadsPerBlock>>>(d_pic, width, height, xMid, yMid, Delta, num_frames);
    cudaDeviceSynchronize();

    /* end time */
    GET_TIME(end);
    double elapsed = end - start;
    printf("Parrallel time: %.4f s\n", elapsed);

    // Memory for output
    unsigned char *pic = (unsigned char*)malloc(size);
    cudaMemcpy(pic, d_pic, size, cudaMemcpyDeviceToHost);

      /* write frames to BMP files */
    if ((width <= 320) && (num_frames <= 100)) { /* do not write if images large or many */
        for (int frame = 0; frame < num_frames; frame++) {
        char name[32];
        sprintf(name, "fractal%d.bmp", frame + 1000);
        writeBMP(width, height, &pic[frame * height * width], name);
        }
    }

    cudaFree(d_pic);
    return 0;
}
