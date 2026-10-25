# x4adapter --selftest: hand-written game asm (no game bytes, G12). Three anchors of one shape: a call through a
# symbols-file name (fx_callee) and two globals by %hi/%lo. The `/* rom vram */` comments are what carve.asm_index
# reads to map a glabel to this file.
.set noreorder
.set noat
.text

.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro endlabel label
    .size \label, . - \label
.endm

glabel func_80020100
/* 100 80020100 */ addiu $sp, $sp, -24
/* 104 80020104 */ sw $ra, 16($sp)
/* 108 80020108 */ jal fx_callee
/* 10C 8002010C */ nop
/* 110 80020110 */ lui $v0, %hi(D_80030000)
/* 114 80020114 */ lw $v0, %lo(D_80030000)($v0)
/* 118 80020118 */ lui $v1, %hi(D_80030010)
/* 11C 8002011C */ lw $v1, %lo(D_80030010)($v1)
/* 120 80020120 */ lw $ra, 16($sp)
/* 124 80020124 */ addiu $sp, $sp, 24
/* 128 80020128 */ jr $ra
/* 12C 8002012C */ nop
endlabel func_80020100

glabel func_80020200
/* 200 80020200 */ addiu $sp, $sp, -24
/* 204 80020204 */ sw $ra, 16($sp)
/* 208 80020208 */ jal fx_callee
/* 20C 8002020C */ nop
/* 210 80020210 */ lui $v0, %hi(D_80030000)
/* 214 80020214 */ lw $v0, %lo(D_80030000)($v0)
/* 218 80020218 */ lui $v1, %hi(D_80030010)
/* 21C 8002021C */ lw $v1, %lo(D_80030010)($v1)
/* 220 80020220 */ lw $ra, 16($sp)
/* 224 80020224 */ addiu $sp, $sp, 24
/* 228 80020228 */ jr $ra
/* 22C 8002022C */ nop
endlabel func_80020200

glabel func_80020300
/* 300 80020300 */ addiu $sp, $sp, -24
/* 304 80020304 */ sw $ra, 16($sp)
/* 308 80020308 */ jal fx_callee
/* 30C 8002030C */ nop
/* 310 80020310 */ lui $v0, %hi(D_80030000)
/* 314 80020314 */ lw $v0, %lo(D_80030000)($v0)
/* 318 80020318 */ lui $v1, %hi(D_80030010)
/* 31C 8002031C */ lw $v1, %lo(D_80030010)($v1)
/* 320 80020320 */ lw $ra, 16($sp)
/* 324 80020324 */ addiu $sp, $sp, 24
/* 328 80020328 */ jr $ra
/* 32C 8002032C */ nop
endlabel func_80020300
