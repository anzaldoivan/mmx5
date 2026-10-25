/* Lever regalloc_abs_const_lw (after): the global as an absolute-address constant (the include/addr.h form). cc1
   emits one `lw $N,<const>`; the assembler's lw macro expands it with the dest register for the lui. */
#define D_801F3004 (*(int *)0x801F3004)
unsigned char *lever_abslw(void) { return (unsigned char *)0x801F3000 + D_801F3004; }
