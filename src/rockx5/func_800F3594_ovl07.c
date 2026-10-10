#include "types.h"

typedef struct Ent3594 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[8];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
} Ent3594;

#define D_1F80004C (*(Scr3594**)0x1F80004C)

extern void func_8002DF54(Ent3594*);
extern s32 func_800F37C4_ovl07(Ent3594*);

void func_800F3594_ovl07(Ent3594* e) {
    func_8002DF54(e);
    if (D_1F80004C->unk82 - 0x20 >= e->unkE) {
        e->unk24 = -0x8000;
        if (D_1F80004C->unk84) {
            D_1F80004C->unk84 = 0;
        } else if (func_800F37C4_ovl07(e)) {
            e->unk24 = 0xFFFD0000;
        }
        e->unk5 = 3;
    }
}
