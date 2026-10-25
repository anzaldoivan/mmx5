/* Lever regalloc_abs_const_lw (before): the global as an extern symbol. The SYMBOL_REF address is split into
   `lui %hi` / `lw %lo` in two registers ($3 then $4). */
extern int D_801F3004;
unsigned char *lever_abslw(void) { return (unsigned char *)0x801F3000 + D_801F3004; }
