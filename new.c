#include <stdio.h>
float average(float,float,float);
void main()
{
    float n1,n2,n3;
    scanf(" %f %f %f",&n1,&n2,&n3);
    printf("%f is the average",average(n1,n2,n3));
}

float average(float i, float j, float k)
{
    float avg = (i+j+k)/3;
    return avg;
}
