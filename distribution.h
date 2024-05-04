#ifndef _DISTRIBUTION_H
#define _DISTRIBUTION_H

float generate_normal_distribution(float, float);
int generate_poisson_distribution(float);
int* poission_distribution(int, float);
float* normal_distribution (int, int, int);
void print_normal_distribution(float*, int);
void print_poisson_distribution (int*, int);
void free_normal(float*);
void free_poisson(int*);

#endif