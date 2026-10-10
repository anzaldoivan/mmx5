/* Lever expr_ptr_plus_index (before): a 12-byte table entry as an array ref T[i].f; the table base gets the
   first register and takes the address sum (`addu base,base,idx`). */
typedef struct { unsigned char pad0[8]; unsigned short unk8; unsigned char padA[2]; } Ent;
extern Ent D_tbl[];
int lever_idx(int a, int i) { return a + D_tbl[i].unk8; }
