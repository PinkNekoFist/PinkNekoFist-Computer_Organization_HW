"improved_loop:\n\t"
    "vsetvli t0, %[arr_size], e16\n\t" // wtf?
        "addi %[others_cnt], %[other_cnt], 1\n\t"
    "vle16.v v0, 0(%[x])\n\t"
    "vle16.v v1, 0(%[h])\n\t"
        "addi %[lw_cnt], %[lw_cnt], 2\n\t"

    "vmul.vv v2, v0, v1\n\t"
        "addi %[mul_cnt], %[mul_cnt], 1\n\t"
    "vadd.vv v2, v2, %[id]\n\t"
        "addi %[add_cnt], %[add_cnt], 1\n\t"

    "vse16.v v2, 0(%[y]\n\t)"
        "addi %[lw_cnt], %[lw_cnt], 1\n\t"

    "addi %[x], %[x], 16\n\t"
    "addi %[h], %[h], 16\n\t"
    "addi %[y], %[y], 16\n\t"
        "addi %[add_cnt], %[add_cnt], 3\n\t"

    "sub %[arr_size], %[arr_size], t0\n\t"
        "addi %[sub_cnt], %[sub_cnt], 1\n\t"
        "addi %[others_cnt], %[other_cnt], 1\n\t"
    "bgez %[arr_size], improved_loop\n\t"


