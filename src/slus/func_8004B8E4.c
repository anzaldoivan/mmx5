#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 D_80077268[];
extern s32 D_80077380[];
extern s8 D_8009A0A6;
extern s32 D_8009A420;

void func_8004B8E4(u8* obj, u8* src) {
    u8* p;
    u8 t;
    s32 v;

    if (*(s8*)(obj + 1) == 0x2C) {
        p = *(u8**)(obj + 0x7C);
        *(s32*)(obj + 0x8) = *(s32*)(p + 0x8);
        *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
        obj[0x15] = p[0x15];
    } else {
        *(s32*)(obj + 0x8) = *(s32*)(src + 0x8);
        *(s32*)(obj + 0xC) = *(s32*)(src + 0xC);
        obj[0x15] = src[0x15];
    }
    if (*(s8*)(obj + 0x45) == 0) {
        *(s32*)(obj + 0x50) = 0;
    } else {
        if ((*(s32*)(src + 0xFC) & 0x8000) && !(*(s8*)obj & 0x80)) {
            *(s32**)(obj + 0x50) = &D_80077380[*(s8*)(obj + 0x45)];
        } else {
            *(s32**)(obj + 0x50) = &D_80077268[*(s8*)(obj + 0x45)];
        }
    }
    t = obj[1];
    if ((u8)(t - 0x18) < 2 || (s8)t == 0x25 || (s8)t == 0x26 || (s8)t == 0x27 ||
        (s8)t == 0x28 || (s8)t == 0x29 || (s8)t == 0x2C) {
        v = obj[2] + 1;
        goto store; // !FAKE: goto kept for the matching branch layout
    }
    if ((s8)t == 0x23) {
        goto count; // !FAKE: goto kept for the matching branch layout
    }
    if ((s8)t == 0x1A || (s8)t == 0x20 || !(D_8009A420 & 3)) {
        v = obj[0x45];
    store:
        obj[0x64] = v;
    }
    if (*(s8*)(obj + 1) == 0x23) {
    count:
        if (*(s32*)(obj + 0x90) != 0) {
            *(s32*)(obj + 0x90) = *(s32*)(obj + 0x90) - 1;
            *(s32*)(obj + 0x50) = 0;
        }
        if (*(s8*)(obj + 0x98) != 0) {
            obj[0x98] = 0;
            *(s32*)(obj + 0x90) = 2;
            *(s32*)(obj + 0x50) = 0;
            *(u32*)(obj + 0x8C) = *(u32*)(obj + 0x8C) + 1;
        }
        if (*(u32*)(obj + 0x8C) >= 4) {
            *(s32*)(obj + 0x50) = 0;
        }
        if (D_8009A0A6 == 2 && obj[0x17] != 0x79) {
            func_800171E8(obj, 0x79);
        }
    }
    func_8002D9EC(obj, 0x80, 0x80);
}
