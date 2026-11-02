#include "types.h"

extern void func_80016490(s32, s32, s32, void*);
extern s8 D_80074A10[];
extern s8 D_80074A14[];
extern s8 D_80074A18[];
extern s8 D_800D1C1C;

void func_8003DB8C(u8* obj) {
    u16 in;
    s32 m;
    s8 i;

    if (*(s8*)(obj + 0xD3) != 0) {
        return;
    }
    if (*(s8*)(obj + 0x99) != 0) {
        return;
    }
    if (*(s8*)(obj + 0xD5) != 0) {
        return;
    }
    if (D_800D1C1C != 0) {
        return;
    }
    if (obj[0xF7] != 0) {
        return;
    }
    in = *(u16*)(obj + 0x80);
    m = in & 0x600;
    if (m == 0) {
        return;
    }
    if ((*(u16*)(obj + 0x7C) & 0x600) == 0x600 || m == 0x600) {
        if (*(s8*)(obj + 0x93) != 0) {
            *(s8*)(obj + 0x93) = 0;
            func_80016490(0, 0xC, 0, obj);
        }
        return;
    }
    i = D_80074A18[*(s8*)(obj + 0x93)];
    if (in & 0x200) {
        do {
            i++;
            if (i == 4) {
                i = 0;
                break;
            }
        } while (!(D_80074A10[i] & obj[0xC9]));
    } else {
        do {
            i--;
            if (i < 0) {
                i = 3;
            }
            if (i == 0) {
                break;
            }
        } while (!(D_80074A10[i] & obj[0xC9]));
    }
    i = D_80074A14[i];
    if (i != *(s8*)(obj + 0x93)) {
        *(s8*)(obj + 0x93) = i;
        func_80016490(0, 0xC, 0, obj);
    }
}
