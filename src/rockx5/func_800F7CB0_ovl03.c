#include "types.h"

typedef struct Ent7CB0 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x7C - 7];
    s16 unk7C;
    u8 pad7E[0x92 - 0x7E];
    u8 unk92;
    u8 unk93;
} Ent7CB0;

extern void func_80017248(Ent7CB0*);
extern void func_8002DED4(Ent7CB0*);
extern u8 D_800FA0BC_ovl03[][6];

void func_800F7CB0_ovl03(Ent7CB0* e) {
    if (++e->unk7C == 6) {
        u8 t;
        t = D_800FA0BC_ovl03[e->unk92][e->unk93++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    func_80017248(e);
    func_8002DED4(e);
}
