#include <stdio.h>
int main()
{
    int f, i = 0;
    int h[9] = {0}, x[6] = {0}, y[6] = {0};
    FILE *input = fopen("../input/4.txt", "r");
    for (i = 0; i < 9; i++)
        fscanf(input, "%d", &h[i]);
    for (i = 0; i < 6; i++)
        fscanf(input, "%d", &x[i]);
    for (i = 0; i < 6; i++)
        fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];
    // y[2*i+j] += h[3*i+f] * x[2*f+j];
    asm volatile(
        "li t0, 0\n\t"
        "i_loop:\n\t"
        "li t1, 0\n\t"
        "j_loop:\n\t"
        "li t2, 0\n\t"
        "f_loop:\n\t"
        // for loop start

        //"mul t3, t0, t4\n\t"   // 3i
        "slli t3, t0, 1\n\t"
        "add t3, t3, t0\n\t"
        "add t3, t3, t2\n\t"   // 3i+f
        "slli t3, t3, 2\n\t"   // 3i+f * 4(byte)
        "add t3, t3, %[h]\n\t" // h[3i + f]
        "lw t4, 0(t3)\n\t"     // t4 : h[3i + f]

        "slli t3, t2, 1\n\t" // 2f
        "add t3, t3, t1\n\t" // 2f + i
        "slli t3, t3, 2\n\t" // 2f+i * 4
        "add t3,t3,%[x]\n\t" // x[2f+i]
        "lw t5, 0(t3)\n\t"   // t5 : x[2f + i]

        "slli t3, t0, 1\n\t"   // 2i
        "add t3, t3, t1\n\t"   // 2i+j
        "slli t3, t3, 2\n\t"   // 2i+j * 4
        "add t3, t3, %[y]\n\t" // y[2i+j]
        "lw t6, 0(t3)\n\t"     // t6 : y[2i+j]

        "mul t4, t4, t5\n\t" // x*h
        "add t6, t6, t4\n\t" // y += x*h
        "sw t6, 0(t3)\n\t"   //???

        // for loop end
        "addi t2, t2, 1\n\t"
        "li t3, 3\n\t"
        "blt t2, t3, f_loop\n\t" // f < 3

        "addi t1, t1, 1\n\t"
        "li t3, 2\n\t"
        "blt t1, t3, j_loop\n\t" // j < 2

        "addi t0, t0, 1\n\t"
        "li t3, 3\n\t"
        "blt t0, t3, i_loop\n\t" // i < 3
        :
        : [y] "r"(p_y), [h] "r"(p_h), [x] "r"(p_x));

    p_y = &y[0];
    for (i = 0; i < 6; i++)
        printf("%d ", *p_y++);
    printf("\n");
    return 0;
}