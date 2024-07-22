#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x) {
    return sin(x) + sin(2 * x) + x; 
}

float iter_y(float (*f)(float), float y, float a, float b, float tol) {
    float c, fc;
    while ((b - a) / 2 > tol) {
        c = (a + b) / 2;
        fc = f(c);
        if (fabs(fc - y) < tol)
            return c;
        else {
            if (fc > y)
                b = c;
            else
                a = c;
        }
    }
    return -1;
}

float rec_y(float (*f)(float), float y, float a, float b, float tol){
    if ((b - a) / 2 > tol){
        if (fabs(f((a + b) / 2) - y) < tol)
            return (a + b) / 2;
        else {
            if (f((a + b) / 2) > y)
                return rec_y(f, y, a, (a + b) / 2, tol);
            else
                return rec_y(f, y, (a + b) / 2, b, tol);
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    if (argc != 4)
        return -1;

    float y = atof(argv[1]);
    float a = atof(argv[2]);
    float b = atof(argv[3]);

    printf("%.8f\n", iter_y(f, y, a, b, 0.00000005));
    printf("%.8f\n", rec_y(f, y, a, b, 0.00000005));
    return 0;
}
