#include "types.h"

extern Slot8002D0E4 D_80096D98[];
extern s32 func_8002E408(u8* p, s32 a, u8* b, u8* c);

s32 func_80033024(s32 arg0) {
    u8* p;
    s32 ret;

    ret = 0;
    for (p = (u8*)D_80096D98; p < (u8*)D_80096D98 + 0x1380; p += 0x9C) {
        if (*(s8*)p != 0) {
            if (func_8002E408(p, arg0, p + 0x80, p + 0x82) != 0) {
                ret = ((s8*)p)[1];
                p[0x70] |= 0xF;
            }
        }
    }
    return ret;
}
