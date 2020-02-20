#include <stdio.h>

int main()
{
    unsigned int i;
    unsigned int r;
    unsigned int g;
    unsigned int b;

    i = 0xFFFFFF;
    r = i >> 16;
    g = i << 8;
    g = g >> 24;
    b = i << 16;
    b = b >> 24;
    printf("i:%d r:%d g:%d b:%d\n", i, r, g, b);
    // i = 0x0000FF;
    // r = i >> 16;
    // g = i >> 8;
    // g = g << 8;
    // b = i << 16;
    // b = b >> 16;
    // printf("i:%d r:%d g:%d b:%d\n", i, r, g, b);
    // i = 0x00FF00;
    // r = i >> 16;
    // g = i >> 8;
    // g = g << 8;
    // b = i << 16;
    // b = b >> 16;
    // printf("i:%d r:%d g:%d b:%d\n", i, r, g, b);
}