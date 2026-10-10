# Synthetic fixture for tools/wave/waves.py --selftest (hand-written, no game bytes).
.section .text
glabel ra
    jr         $ra
    nop
endlabel ra
glabel rb
    jr         $ra
    nop
endlabel rb
