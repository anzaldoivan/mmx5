#include "types.h"

typedef struct Ent3620 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[8];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
} Ent3620;

#define D_1F80004C (*(Scr3594**)0x1F80004C)

extern void func_8002DF54(Ent3620*);
extern s32 func_800F37C4_ovl07(Ent3620*);

void func_800F3620_ovl07(Ent3620* e) {
    func_8002DF54(e);
    if (e->unkE >= D_1F80004C->unk82 + 0x20) {
        e->unk24 = 0x8000;
        if (D_1F80004C->unk84) {
            D_1F80004C->unk84 = 0;
        } else if (func_800F37C4_ovl07(e)) {
            e->unk2C = 0x30000;
        }
        e->unk5 = 2;
    }
}
