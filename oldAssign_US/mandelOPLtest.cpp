#include <stdlib.h>
float width=600, height=600; // window size
int windowID;
float minX = -2.2, maxX = 0.8, minY = -1.5, maxY = 1.5;
float stepX = (maxX - minX)/width;
float stepY = (maxY - minY)/height;
const int paletteSize = 128;
float palette[paletteSize][3];
const float radius = 5.0;

void createPalette(){
  for(int i=0; i < 32; i++){
    palette[i][0] = (8*i)/255;
    palette[i][1] = (128-4*i)255;
    palette[i][2] = (255-8*i)/255;
  }
  for(int i=0; i < 32; i++){
    palette[32+i][0] = 1;
    palette[32+i][1] = (8*i)/255;
    palette[32+i][2] = 0;
  }
  for(int i=0; i < 32; i++){
    palette[64+i][0] = (128-4*i)/(GLfloat)255;
    palette[64+i][1] = (GLfloat)1;
    palette[64+i][2] = (8*i)/(GLfloat)255;
  }
  for(int i=0; i < 32; i++){
    palette[96+i][0] = (GLfloat)0;
    palette[96+i][1] = (255-8*i)/(GLfloat)255;
    palette[96+i][2] = (8*i)/(GLfloat)255; 
  }
}


int main(int argc, char** argv){
  return 0;
}
