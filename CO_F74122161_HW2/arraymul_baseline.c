"li t1, 0\n\t"
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"
"i_loop:\n\t"
    "mul t0, %[h], %[x]\n\t"
        "addi %[mul_cnt], %[mul_cnt], 1\n\t"
    "add t0, t0, %[id]\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "sw t0, 0(%[y])\n\t"
        "addi %[sw_cnt], %[sw_cnt], 1\n\t"
    "addi %[x], %[x], 4\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "addi %[h], %[h], 4\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
    "addi %[y], %[y], 4\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t1, t1, 1\n\t"
    "addi %[add_cnt], %[add_cnt], 1\n\t"
    "addi %[others_cnt], %[others_cnt], 1\n\t"
"blt t1, %[arr_size], i_loop\n\t"