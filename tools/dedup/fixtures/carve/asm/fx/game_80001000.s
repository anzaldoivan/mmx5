.section .text, "ax"

nonmatching func_80001000, 0x10

glabel func_80001000
    /* 1000 80001000 00000000 */  nop
    /* 1004 80001004 00000000 */  nop
    /* 1008 80001008 00000000 */  nop
    /* 100C 8000100C 00000000 */  nop
endlabel func_80001000

nonmatching func_80001010, 0x10

glabel func_80001010
    /* 1010 80001010 00000000 */  lui $v0, %hi(D_80000F80)
    /* 1014 80001014 00000000 */  lw $v0, %lo(D_80000F80)($v0)
    /* 1018 80001018 00000000 */  nop
    /* 101C 8000101C 00000000 */  nop
endlabel func_80001010

nonmatching func_80001020, 0x10

glabel func_80001020
    /* 1020 80001020 00000000 */  nop
    /* 1024 80001024 00000000 */  nop
    /* 1028 80001028 00000000 */  nop
    /* 102C 8000102C 00000000 */  nop
endlabel func_80001020
