/* include_asm.h — INCLUDE_ASM / INCLUDE_RODATA for splat `use_legacy_include_asm: False`.
 * Splat writes a not-yet-decompiled function to asm/<alias>/nonmatchings/<seg>/<name>.s;
 * the C TU pulls it back in with INCLUDE_ASM("asm/<alias>/nonmatchings/<seg>", name);
 * First exercised by tools/dedup/carve.py (phase 1.6 T4): the path holds; macro.inc (glabel/endlabel) comes
 * from CC_ASFLAGS -I asm/<alias>/include; noreorder/noat as the split .s files assume, restored after. */
#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#define INCLUDE_ASM(FOLDER, NAME)                                              \
    __asm__(".section .text\n"                                                 \
            "\t.include \"macro.inc\"\n"                                       \
            "\t.set noat\n"                                                     \
            "\t.set noreorder\n"                                                \
            "\t.include \"" FOLDER "/" #NAME ".s\"\n"                          \
            "\t.set reorder\n"                                                  \
            "\t.set at\n"                                                       \
            ".section .text\n")

#define INCLUDE_RODATA(FOLDER, NAME)                                           \
    __asm__(".section .rodata\n"                                               \
            "\t.include \"" FOLDER "/" #NAME ".s\"\n"                          \
            ".section .text\n")

#endif /* INCLUDE_ASM_H */
