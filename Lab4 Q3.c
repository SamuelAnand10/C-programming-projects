#include <stdio.h>

float smallest(float,float,float);
int main(void){
float a,b,c;
printf("put first float:");
scanf("%f",&a);
printf("put second float:");
scanf("%f",&b);
printf("put third float:");
scanf("%f",&c);
printf("smallest is %f",smallest(a,b,c));
}
float smallest(float i, float j, float k){
if ((i<j) && (i<k)){ return i;}
if ((j<i) && (j<k)) {return j;}
if ((k<j) && (k<i)){return k;}

}
