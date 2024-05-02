#include <stdio.h>
#define N 256
#define M 256

int pixelrgbToGray(int r, int g, int b){
    return (r * 0.2989 + g * 0.5870 + b * 0.1140);
}

//the following function takes in an BMP image and as a bidimensional array of integers as well as another bidimensional array of integers that will be filled with the grayscale converted image, it returns 0
int rgbToGray(int img[N][M], int gray[N][M/3]){
    int k = 0;
    for(int i = 0; i < N; i++){
        k = 0;
        for(int j = 0; j < M; j+=3){
            gray[i][k++] = pixelrgbToGray(img[i][j], img[i][j+1], img[i][j+2]);
        }
    }

    return 0;
}

int main(void){
//write a test for this function

    return 0;
}