#include <stdio.h>
int integerPower(int,int);
void main(void){
int base,exponent;
printf("input value of base:");
scanf("%d",&base);
printf("input value of exponent:");
scanf("%d",&exponent);
printf("integer returned is: %d", integerPower(base,exponent));
}
int integerPower(int i, int j){
    int exp = 1;
    for (int count = 0; count != j; ++count){
        exp = exp * i;}
        return exp;
}
