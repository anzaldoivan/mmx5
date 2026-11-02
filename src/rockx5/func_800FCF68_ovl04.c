#include "types.h"

extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern s16 D_8009A206;
extern u8 D_8009A1F8[];
extern u16 D_80102D64_ovl04[];

static inline u8* func_800FCF68_ovl04_spawn(s32 kind, s32 arg0) {
    u8* p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x18;
        p[2] = kind;
        *(s32*)(p + 0x50) = arg0;
    }
    return p;
}

void func_800FCF68_ovl04(s32 arg0, s32 arg1) {
    s32 in;
    s32 kind;
    u8* obj;

    in = func_8002DF78();
    kind = 7;
    if (!(in & 4)) {
        kind = 8;
        if (D_8009A206 < 0x41) {
            kind = 7;
        }
    }
    obj = func_800FCF68_ovl04_spawn(kind, arg0);
    if (obj != 0) {
        if (kind == 7) {
            u8* base;
            u32 r = func_8002DF78();
            base = D_8009A1F8;
            *(u16*)(obj + 0xA) = *(u16*)(base + 0xA) + (u8)(r % 161) * 2;
            *(u16*)(obj + 0xE) = *(u16*)(base + 0xE) + 0xF0;
        } else {
            u8* base = D_8009A1F8;
            *(u16*)(obj + 0xA) =
                *(u16*)(base + 0xA) + D_80102D64_ovl04[arg1 * 2];
            if (arg1 == 1) {
                *(u16*)(obj + 0xE) = *(u16*)(base + 0xE) + 0xB0;
            } else {
                *(u16*)(obj + 0xE) = *(u16*)(base + 0xE) + 0xA0;
            }
        }
        if (in & 1) {
            *(u16*)(obj + 0xA) -= 3;
        } else if (in & 2) {
            *(u16*)(obj + 0xA) += 3;
        }
    }
}
