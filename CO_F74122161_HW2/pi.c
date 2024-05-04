/*
 * description: Gregory-Leibniz series
 *
 *    we use Leibniz formula to approximate Pi
 *
 *    pi/4 = (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
 *    pi   = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
 *
 */
/* original code
for (int i = 0; i < N; i++){
    term = (-1)^i / (2*i+1);
    pi += term;
}
*/
"li t1, 0\n\t"
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"
"i_loop:\n\t" // i loop start

    "add t2, t2, t1\n\t" // t2 = i
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "slli t2, t2, 1\n\t" // 2*i
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "addi t2, t2, 1\n\t" // 2*i + 1
        "addi %[add_cnt], %[add_cnt], 1\n\t"

    "li t4, 1\n\t"       // t4 = 1
        "addi %[lw_cnt], %[lw_cnt], 1\n\t"
    "and t3, t1, t4\n\t" // t3 = 1 if i is odd else even
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "bne t3, t4, i_even\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"

    // if t3 is odd
    "li t4, -1\n\t"
        "addi %[lw_cnt], %[lw_cnt], 1\n\t"
    "mul t2, t2, t4\n\t" // t2 = -(t2)
        "addi %[mul_cnt], %[mul_cnt], 1\n\t"
    // if t3 is even
    "i_even:\n\t"
    "fcvt.d.w f1, t2\n\t" // int convert to float (t2 into f1)
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "li t4, 1\n\t"
        "addi %[lw_cnt], %[lw_cnt], 1\n\t"
    "fcvt.d.w f2, t4\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "fdiv.d f1, f2, f1\n\t" // f1 = 1 / 2*i + 1
        "addi %[div_cnt], %[div_cnt], 1\n\t"
    "fadd.d %[pi], %[pi], f1\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"

"addi t1, t1, 1\n\t"       // i++
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"
"blt t1, %[N], i_loop\n\t" // i < N
    "addi %[others_cnt], %[others_cnt], 1\n\t"
