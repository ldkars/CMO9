#include "random.h"
double rand0to1(void){
    return (double)((double)rand()) / (RAND_MAX);
}
