.section .text, "ax"

nonmatching func_80001030, 0x10

glabel func_80001030
    /* 1030 80001030 00000000 */  lui $at, %hi(jtbl_80009000)
    /* 1034 80001034 00000000 */  lw $at, %lo(jtbl_80009000)($at)
    /* 1038 80001038 00000000 */  jr $at
    /* 103C 8000103C 00000000 */  nop
endlabel func_80001030

nonmatching func_80001040, 0x10

glabel func_80001040
    /* 1040 80001040 00000000 */  lui $v0, %hi(D_80000FC0)
    /* 1044 80001044 00000000 */  lw $v0, %lo(D_80000FC0)($v0)
    /* 1048 80001048 00000000 */  jr $ra
    /* 104C 8000104C 00000000 */  nop
endlabel func_80001040

nonmatching func_80001050, 0x20

glabel func_80001050
    /* 1050 80001050 00000000 */  lui $v0, %hi(D_80000FC0)
    /* 1054 80001054 00000000 */  lw $v0, %lo(D_80000FC0)($v0)
    /* 1058 80001058 00000000 */  jr $ra
    /* 105C 8000105C 00000000 */  nop
endlabel func_80001050
