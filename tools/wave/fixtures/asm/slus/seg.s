# Synthetic fixture for tools/wave/waves.py --selftest (hand-written, no game bytes).
.section .text
glabel fa
    lui        $v0, %hi(D_80001000)
    lw         $v0, %lo(D_80001000)($v0)
    jr         $ra
    nop
endlabel fa
glabel fb_c
    jr         $ra
    nop
endlabel fb_c
glabel fd
    jal        fbank
    nop
    jr         $ra
    nop
endlabel fd
glabel fe_twin
    jr         $ra
    nop
endlabel fe_twin
glabel ff
    addu       $v0, $a0, $zero
    jr         $ra
    nop
endlabel ff
glabel fg
    jr         $ra
    nop
endlabel fg
glabel big
    jr         $ra
    nop
endlabel big
