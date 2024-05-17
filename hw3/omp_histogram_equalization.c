#include <stdio.h>
#include "image.h"
#include "timer.h"
#include <omp.h>
#include <stdlib.h>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int thread_count;

// Function to perform histogram equalisation on an image
void histogram_equalization(Image *srcImage, Image *destImage) {
 
    // declare 2 arrays for storing histogram values (frequencies) and
    // new gray level values (newly mapped pixel values as per algorithm)
    int hist[3][256] = { 0 };
    int new_gray_level[3][256] = { 0 };
    
#   pragma omp parallel num_threads(thread_count)
    {
        int private_hist[3][256] = {0};
        // Calculating frequency of occurrence for all pixel values
#       pragma omp for 
        for (int row=0; row<srcImage->height; row++) {
            for (int col=0; col<srcImage->width; col++) {
                for (int ch=0; ch<srcImage->bpp; ch++) {
                    int index = Index(col,row,srcImage->width,ch,srcImage->bpp);
                    private_hist[ch][srcImage->data[index]]++;
                }      
            }
        }

#       pragma omp critical
        {
            for (int ch = 0; ch < 3; ch++) {
                for (int i = 0; i < 256; i++) {
                    hist[ch][i] += private_hist[ch][i];
                }
            }
        }


    }
  
    // calculating cumulative frequency and new gray levels
#   pragma omp parallel for num_threads(thread_count)
    for (int ch = 0; ch < srcImage->bpp; ch++) {
        long curr = 0;
        for (int i = 0; i < 256; i++) {
            curr += hist[ch][i];
            new_gray_level[ch][i] = round((((float)curr) * 255) / (srcImage->height * srcImage->width));
        }
    }

    // performing histogram equalisation by mapping new gray levels
#   pragma omp parallel for num_threads(thread_count)
    for (int row=0; row<srcImage->height; row++) {
        for (int pix=0; pix<srcImage->width; pix++) {
            for (int ch=0; ch<srcImage->bpp; ch++) {
                int index = Index(pix,row,srcImage->width,1,srcImage->bpp);
                destImage->data[index] = new_gray_level[ch][srcImage->data[index]];
            }
        }
    }
 
}

// Usage: Prints usage information for the program
int Usage(){
    printf("Usage: image <filename>\n");
    return -1;
}

// main: expects a filename as argument (can be jpg, png, bmp, tga)
int main(int argc,char** argv) {
    stbi_set_flip_vertically_on_load(0); 
    
    if (argc!=3) return Usage();
    char* fileName = argv[1];

    // Get the number of threads from command line **
    thread_count = strtol(argv[2], NULL, 10);

    //initiaitng Image type called srcImage which holds the data for an image
    Image srcImage;   
    srcImage.data = stbi_load(fileName,&srcImage.width,&srcImage.height,&srcImage.bpp,0);
    if (!srcImage.data){
        printf("Error loading file %s.\n",fileName);
        return -1;
    }

    printf("Image size is %d by %d.\n", srcImage.width, srcImage.height);
#ifdef DEBUG
    printf("Image has %d channels.\n", srcImage.bpp);
#endif

    //initiaitng Image type called destImage which holds the data for an image
    Image destImage;
    destImage.bpp = srcImage.bpp;
    destImage.height = srcImage.height;
    destImage.width = srcImage.width;
    destImage.data = malloc(sizeof(uint8_t)*destImage.width*destImage.bpp*destImage.height);

    double start, finish;
    GET_TIME(start);
    //might need to add a pramga here, im not too sure.
    //I am going to go with for loop reductions
    histogram_equalization(&srcImage, &destImage);
    GET_TIME(finish);

    printf("Histogram equalization took %f seconds\n", finish-start);

    stbi_write_png("output.png",destImage.width,destImage.height,destImage.bpp,destImage.data,destImage.bpp*destImage.width);
    stbi_image_free(srcImage.data);
    
    free(destImage.data);
    
    return 0;
} /* compile with cc histogram_equalization.c -lm -o heq */