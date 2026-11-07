#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_80046420(u8* o) {
    u8* p;
    u8 t;

    if (*(s8*)(o + 5) == 0) {
        t = o[0x8C];
        p = o + 0x8C;
        if (t == 0) {
            func_800171E8(o, 0x1F);
            *(s32*)(o + 0x50) = 0;
            o[5] = 1;
        } else {
            o[0x8C] = t - 1;
            t = p[1];
            if (t == 0) {
                p[1] = 8;
                o[0x64]++;
            } else {
                p[1] = t - 1;
            }
        }
    } else if (*(s8*)(o + 0x46) == 0) {
        o[3] = 0;
        o[4] = 3;
        *(s32*)(o + 0x50) = 0;
        *(s32*)(o + 0x68) = 0;
        return;
    }
    func_8002D9EC(o, 0x2A, 0x22);
}
