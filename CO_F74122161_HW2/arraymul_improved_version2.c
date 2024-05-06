
"improved_loop:\n\t"
    "vsetivli t0, 8, e16\n"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "vle16.v v0, 0(%[x])\n\t"
    "vle16.v v1, 0(%[h])\n\t"
        "addi %[lw_cnt], %[lw_cnt], 2\n\t"

    "vmul.vv v2, v0, v1\n\t"
        "addi %[mul_cnt], %[mul_cnt], 1\n\t"
    "vadd.vx v2, v2, %[id]\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"

    "vse16.v v2, 0(%[y])\n\t"
        "addi %[sw_cnt], %[sw_cnt], 1\n\t"

    "addi %[x], %[x], 16\n\t"
    "addi %[h], %[h], 16\n\t"
    "addi %[y], %[y], 16\n\t"
        "addi %[add_cnt], %[add_cnt], 3\n\t"

    "sub %[arr_size], %[arr_size], t0\n\t"
        "addi %[sub_cnt], %[sub_cnt], 1\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
    "bgt %[arr_size], x0, improved_loop\n\t"