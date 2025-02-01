#include <stdio.h>
#include <math.h>
double hyp(double,double);
void main(void){
double s1,s2;
printf("Please input value of the first side:");
scanf("%lf",&s1);
printf("Please input value of the second side:");
scanf("%lf",&s2);
printf("Hypotenuse is %lf",hyp(s1,s2));
}

double hyp(double i,double j){
    double s;
    s = sqrt(pow(i,2) + pow(j,2));
    return s;

}
