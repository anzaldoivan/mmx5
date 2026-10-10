.include "macro.inc"

.section .text, "ax"

    /* 100 80100000 01000000 */  .word 0x00000001

glabel func_80100004_ovl00
    /* 104 80100004 0800E003 */  jr         $ra
    /* 108 80100008 00000000 */   nop
endlabel func_80100004_ovl00
    /* 10C 8010000C 00000000 */  nop

dlabel D_80100010_ovl00
    /* 110 80100010 04001080 */ .word func_80100004_ovl00
enddlabel D_80100010_ovl00
