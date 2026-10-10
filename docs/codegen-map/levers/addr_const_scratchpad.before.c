/* Lever addr_const_scratchpad (before): the scratchpad pointer as an extern symbol. A SYMBOL_REF address is split
   (mips_check_split) into a HIGH pseudo plus a LO_SUM load: `lui %hi` / `lw %lo` in two registers. */
extern unsigned char *D_1F80004C;
int lever_scr(void) { return D_1F80004C[0x97]; }
