#include "types.h"
#include "addr.h"
#include "mmx5/graphics.h"

void func_800F09F4_ovl00(Ent09F4* e) {
    if (D_1F80004C.scr09f4->unk90 == 0) {
        e->unk54 = 0;
        e->unk68 = 0;
        e->unk15 = D_1F80004C.scr09f4->unk80->unk15;
        e->unkA = D_1F80004C.scr09f4->unk80->unkA;
        e->unkE = D_1F80004C.scr09f4->unk80->unkE;
        e->unk6++;
    }
}

extern u8 D_800FA75C_ovl00[];
extern u8 D_800FA77C_ovl00[];

#define CTX (D_1F80004C.bytes)
#define CTX80 (*(u8**)(CTX + 0x80))

void func_800F0A84_ovl00(u8* obj) {
    s8 t;

    if (CTX[0x90] == 0) {
        *(u16*)(obj + 0xA) = *(u16*)(CTX80 + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(CTX80 + 0xE);
        t = *(s8*)(CTX80 + 0x45);
        if (t == 2) {
            set_animation(obj, 3);
        } else if (t == 1) {
            obj[5] = 2;
            obj[6] = 0;
            *(u8**)(obj + 0x54) = D_800FA75C_ovl00;
            *(u8**)(obj + 0x68) = D_800FA77C_ovl00;
        }
    }
}
