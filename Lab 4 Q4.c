#include <stdio.h>
#include <math.h>
void main(void){
float out;
srand(time(NULL));
out = (1 + rand()%4);
printf("%f",out);
}
