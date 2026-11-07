#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0A0[];

void func_800F8AA8_ovl27(u8* obj) {
    u8* p;
    u8* q;
    s32 t;
    s32 d;
    s32 v;
    s32 one;

    t = *(u16*)(obj + 0x7C) - 1;
    *(u16*)(obj + 0x7C) = t;
    if ((t << 16) == 0) {
        func_800171E8(obj, 0x13);
        p = D_8009A0A0;
        *(s32*)(obj + 0x20) = 0;
        d = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
        if (d >= 0) {
            if (d < 8) {
                one = 1;
                v = 3;
                goto set; // !FAKE: goto kept for the matching branch layout
            }
            goto far; // !FAKE: goto kept for the matching branch layout
        }
        if (*(s16*)(obj + 0xE) - *(s16*)(p + 0xE) >= 8) {
        far: // !FAKE: label kept for the matching branch layout
            q = D_8009A0A0;
            if (*(s16*)(q + 0xE) < *(s16*)(obj + 0xE)) {
                func_80016490(2, 0x66, obj);
                *(s32*)(obj + 0x24) = 0x20000;
                v = obj[6] + 1;
                obj[6] = v;
                return;
            }
            func_80016490(2, 0x66, obj);
            *(s32*)(obj + 0x24) = 0xFFFE0000;
            v = obj[6] + 1;
            obj[6] = v;
            return;
        }
        one = 1;
        v = 3;
    set: // !FAKE: label kept for the matching branch layout
        *(u16*)(obj + 0x7C) = one;
        obj[6] = v;
    }
}
