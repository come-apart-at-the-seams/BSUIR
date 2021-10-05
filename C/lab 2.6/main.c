//
//  main.c
//  lab 2.6


#include <stdio.h>
#include <math.h>


int main(int argc, const char * argv[]) {
    const  double pi=3.14159265359;
    printf("e= ");
    double e;
    scanf("%lf", &e);
    for(double x=0; x<=pi; x+= pi/24){
        printf("X= %f\n", x);
        double sinus= sin(x), sin_sum=0, arg=x;
        double ee=e+1;
        for(int n=1; ee>e;n++){
            sin_sum+=arg;
            arg*= (-1) * pow(x,2) / ((2 * n)*(2 * n + 1));
            ee = fabs(sinus - sin_sum);
            printf("n= %d\n", n);
        }
        printf("sin_sum= %f", sin_sum);
        printf(", sin= %f\n\n", sinus);
        
    }
return 0;
        
}
