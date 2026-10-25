# game_80013348.s — hand asm for splat segment game_80013348 (0x3B48, 0x3C bytes); mk/slus.mk builds it in place
# of the generated asm/slus/game_80013348.s. spimdisasm emits a lui/ori pair as constants (ori is unsigned), so the
# saved-$sp slot (last word of bss D_800D4F40) is written here as %hi/%lo of the symbol: R_MIPS_HI16/LO16 relocs.
# ponytail: ori does not sign-extend; correct only while the target's lo16 < 0x8000 (0x50D8 today). A shift that
# pushes it to >= 0x8000 makes ld's carried %hi one too high: then use lui (x >> 16) via a link-time symbol instead.
.set noat
.set noreorder
.section .text, "ax"

.globl func_80013348
func_80013348:
    lui     $a0, %hi(D_800D4F40 + 0x198)
    ori     $a0, $a0, %lo(D_800D4F40 + 0x198)
    sw      $sp, 0x0($a0)
    nop
    lui     $sp, 0x1F80
    ori     $sp, $sp, 0x0400
    jr      $ra
    nop
    nop

.globl func_8001336C
func_8001336C:
    lui     $a0, %hi(D_800D4F40 + 0x198)
    ori     $a0, $a0, %lo(D_800D4F40 + 0x198)
    lw      $sp, 0x0($a0)
    nop
    jr      $ra
    nop
    nop
