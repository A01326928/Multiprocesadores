/*
	Miguel Angel Fierro Gutiérrez
	A01326928

	Conversión de una imagen de entrada a color (RGB) a una imagen de salida
	en escala de grises utilizando malloc y paralelización para mejorar la calidad
	de salida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 60
#define NUM_PIXELS 927361

//927361

int main()
{
    FILE *image, *outputImage, *lecturas;
    image = fopen("sample.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("img2_dd.bmp","wb");    //Imagen transformada

    unsigned char r, g, b;               //Pixel
    
    unsigned char *input, *output;
    input = (unsigned char*)malloc(NUM_PIXELS*3*sizeof(unsigned char));
    output = (unsigned char*)malloc(NUM_PIXELS*3*sizeof(unsigned char));
    int j = 0;

    for(int i=0; i<54; i++) fputc(fgetc(image), outputImage);   //Copia cabecera a nueva imagen
    
    omp_set_num_threads(NUM_THREADS);
    
    while(!feof(image)){
        *(input + j) = fgetc(image);
        j++;
    }
    
    #pragma omp parallel
    {
           #pragma omp for ordered
           for(int i =0; i < NUM_PIXELS*3; i+=3){
               r = *(input + i);
               g = *(input + i + 1);
               b = *(input + i + 2);

               unsigned char pixel = 0.21*r+0.72*g+0.07*b;
               #pragma omp ordered
               {
                   *(output + i) = pixel;
                   *(output + i + 1) = pixel;
                   *(output + i + 2) = pixel;
               }
           }
           
    }

    for(int i = 0; i < NUM_PIXELS*3; i++){
        fputc(*(output + i), outputImage);
    }
    
    free(input);
    free(output);
    fclose(image);
    fclose(outputImage);
    return 0;
}