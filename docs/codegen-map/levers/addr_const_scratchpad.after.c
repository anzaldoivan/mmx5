/* Lever addr_const_scratchpad (after): the scratchpad pointer as a raw constant-address cast. A CONST_INT address
   is not split: cc1 emits one `lw $N,0x1f80004c` and the assembler expands it through the dest register. */
#define D_1F80004C (*(unsigned char **)0x1F80004C)
int lever_scr(void) { return D_1F80004C[0x97]; }
