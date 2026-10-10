#include "types.h"

typedef struct Ent5B3C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x96 - 0x30];
    /* 0x96 */ u8 unk96;
    /* 0x97 */ u8 unk97;
} Ent5B3C;

extern s16 D_800FB61E_ovl09;
extern u8 D_800FAD58_ovl09[][6];
extern void func_80017248(Ent5B3C*);
extern void func_8002DED4(Ent5B3C*);

void func_800F5B3C_ovl09(Ent5B3C* e) {
    if (e->unkE <= D_800FB61E_ovl09) {
        e->unkE = D_800FB61E_ovl09;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
    }
    func_80017248(e);
    func_8002DED4(e);
}
