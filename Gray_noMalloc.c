/*
  Miguel Angel Fierro Gutiérrez 
  A01326928

  Conversión de una imagen de entrada a color (RGB) a una imagen de salida
  en escala de grises.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *image, *outputImage;
    image = fopen("sample.bmp","rb");          // Imagen original a transformar
    outputImage = fopen("img2_dd.bmp","wb");    // Imagen transformada
    int c = 0;									// Contador de pixeles

    for(int i=0; i<54; i++) fputc(fgetc(image), outputImage);   //Copia cabecera a nueva imagen

    unsigned char r, g, b;               //Pixel

    while(!feof(image)){
       r = fgetc(image);                                        //Grises
       g = fgetc(image);
       b = fgetc(image);

       unsigned char pixel = 0.21*r+0.72*g+0.07*b;
       fputc(pixel, outputImage);
       fputc(pixel, outputImage);
       fputc(pixel, outputImage);

       c++;
    }

    fclose(image);
    fclose(outputImage);
    printf("%d\n", c);
    return 0;
}
