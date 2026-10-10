.section .text, "ax"

nonmatching func_80002010, 0x10

glabel func_80002010
    /* 1110 80002010 00000000 */  lui $at, %hi(jtbl_80002004)
    /* 1114 80002014 00000000 */  lw $at, %lo(jtbl_80002004)($at)
    /* 1118 80002018 00000000 */  jr $at
    /* 111C 8000201C 00000000 */  nop
endlabel func_80002010
