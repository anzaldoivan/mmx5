#include "types.h"
#include "addr.h"

extern u8* func_8002D1A4();
extern u16 D_800F9F24_ovl26[][32];

void func_800F407C_ovl26(u8* o) {
    u8* c;

    if (--*(s16*)(o + 0x7E) == 0 && (c = func_8002D1A4()) != 0) {
        c[0] = 0x41;
        c[1] = 0x17;
        c[2] = o[0x7C];
        c[0x15] = 0;
        *(u16*)(c + 0x40) = *(u16*)(o + 0x40);
        *(u16*)(c + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
        *(s32*)(c + 0x30) = *(s32*)(o + 0x30);
        *(s32*)(c + 0x3C) = *(s32*)(o + 0x3C);
        *(s16*)(c + 0xA) = 0x8A0;
        *(u16*)(c + 0xE) =
            D_800F9F24_ovl26[D_1F80004C.bytes[0x94]][*(s16*)(o + 0x7C) * 2];
        *(s32*)(c + 0x20) = 0x60000;
        *(s32*)(c + 0x28) = 0;
        *(s32*)(c + 0x24) = 0;
        *(s32*)(c + 0x2C) = 0;
        *(u8**)(c + 0x7C) = o;
        c[0x94] = D_1F80004C.bytes[0x94];
        if (*(s16*)(o + 0x7C) == 0xF) {
            o[6]++;
            return;
        }
        *(s16*)(o + 0x7C) += 1;
        *(s16*)(o + 0x7E) = 0x23;
    }
}
