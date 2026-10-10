.include "macro.inc"

.section .text, "ax"

glabel func_8010001C_ovl00
    /* 11C 8010001C 01000224 */  addiu      $v0, $zero, 0x1
    /* 120 80100020 0800E003 */  jr         $ra
  jlabel .L80100024_ovl00
    /* 124 80100024 00000000 */   nop
endlabel func_8010001C_ovl00
