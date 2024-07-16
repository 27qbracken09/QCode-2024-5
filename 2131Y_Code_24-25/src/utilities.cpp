#include "main.h"

float clamp(float num, float min, float max){
    if (num > max) return max;
    if (num < min) return min;
    else return num;
}