/* Lever expr_ptr_plus_index (after): the same entry as pointer-plus-index (T + i)->f; the registers swap and the
   scaled index takes the address sum (`addu idx,idx,base`). ((Ent *)((u8 *)T + i * 12))->f gives the same. */
typedef struct { unsigned char pad0[8]; unsigned short unk8; unsigned char padA[2]; } Ent;
extern Ent D_tbl[];
int lever_idx(int a, int i) { return a + (D_tbl + i)->unk8; }
