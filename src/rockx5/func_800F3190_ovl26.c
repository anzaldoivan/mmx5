#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F3190_ovl26(u8* o) {
    u8* p;
    u8* s;

    func_80017248(o);
    if (--*(s16*)(o + 0x7E) == 0) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x17;
            p[2] = o[0x7C];
            p[0x15] = 0;
            *(u16*)(p + 0x40) = *(u16*)(o + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(o + 0x42) & 0x7FFF;
            *(s32*)(p + 0x30) = *(s32*)(o + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
            s = D_1F80004C.bytes;
            if (s[0x96] != 0) {
                *(u16*)(p + 0xA) =
                    *(u16*)(o + 0xA) +
                    D_800F9F24_ovl26[s[0x94]][*(s16*)(o + 0x7C)].hi;
            } else {
                *(u16*)(p + 0xA) =
                    *(u16*)(o + 0xA) -
                    D_800F9F24_ovl26[s[0x94]][*(s16*)(o + 0x7C)].hi;
            }
            *(s16*)(p + 0xE) = 0x1280;
            *(s32*)(p + 0x20) = 0;
            *(s32*)(p + 0x28) = 0;
            *(s32*)(p + 0x24) = 0x40000;
            *(s32*)(p + 0x2C) = 0;
            *(u8**)(p + 0x7C) = o;
            p[0x94] = D_1F80004C.bytes[0x94];
            if (*(s16*)(o + 0x7C) == 15) {
                o[6]++;
            } else {
                *(s16*)(o + 0x7C) += 1;
                *(s16*)(o + 0x7E) = 2;
            }
        }
    }
}
