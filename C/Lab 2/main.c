
#include <stdio.h>
#include <stdlib.h>

float LenInput() {
    float len=0;
    printf("1. Entering the edge length of a tetrahedron \n");
    while (!scanf("%f", &len)) {
        printf("WTF, MAN?\n");
        while (getchar() != '\n');
    };
    return len;
};
float P(float len) {
    printf("1. Entering the edge length of a tetrahedron \n");
    return len*6;
};
float S(float len) {
    printf("3. Conclusion S surface \n");
    return len * len * 1.73205;
};
float V(float len) {
    printf("4. Conclusion V \n");
    return len * len * len *0.117851;
};
float H(float len) {
    printf("5. Height output \n");
    return len * 0.8164966;
};
float Rr(float len) {
    printf("6. Derivation of the radius of the inscribed ball \n");
    return len * 0.204124;
};
void Inf() {
    printf("Ver. 1.0.0 \n Make by I");
};
void Exit() {
    printf("8. Exit................ \n");
    exit(0);
}
void Mn() {
    printf("Press: \n");
    printf("1. Entering the edge length of a tetrahedron \n");
    printf("2. Perimeter output \n");
    printf("3. Conclusion S surface \n");
    printf("4. Conclusion V \n");
    printf("5. Height output \n");
    printf("6. Derivation of the radius of the inscribed ball \n");
    printf("7. Version and Author Information \n");
    printf("8. Exit \n");
}

int main()
{
    
    int num = 0;
    float len=0;
    while (1) {
        num = 0;
        Mn();
        scanf("%d", &num);
        if (num !=0 ) {
            if (num == 1) {
                len = 0;
                len = LenInput();
                if (len == 0) {
                    system("cls");
                    printf("ERRROR: Incorrectly input\n");
                    continue;
                }
            }
            switch (num)
            {
            case -1:
                len = 0;
                len = LenInput();
                if (len == 0) {
                    printf("ERRROR: Incorrectly input");
                }
                break;
            case 2:
                printf("%f", P(len));
                break;
            case 3:
                printf("%f", S(len));
                break;
            case 4:
                printf("%f", V(len));
                break;
            case 5:
                printf("%f", H(len));
                break;
            case 6:
                printf("%f", Rr(len));
                break;
            case 7:
                Inf();
                break;
            case 8:
                Exit();
                break;
            default:
                printf("ERROR 1.01 \n");
                break;
            }
        }
        else printf("ERRROR: Incorrectly input");
    }
    

    return 0;
}
