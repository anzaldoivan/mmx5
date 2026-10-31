#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];

static inline u8* func_800FC834_spawn(u8* obj) {
    u8* p;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xB;
        *(u8**)(p + 0x7C) = obj;
        p[2] = 4;
    }
    return p;
}

void func_800FC834_ovl04(u8* obj) {
    u8* p;
    u8* d;
    u8* e;
    s32 ang;
    s8 f;
    s8 st;

    func_80017248(obj);
    f = *(s8*)(obj + 0x45);
    if (f & 0x80) {
        obj[0x45] &= 0x7F;
        p = func_800FC834_spawn(obj);
        if (p != 0) {
            d = D_8009A0A0;
            ang = ratan2(*(s16*)(d + 0xE) - *(s16*)(obj + 0xE),
                         *(s16*)(d + 0xA) - *(s16*)(obj + 0xA));
            *(s32*)(p + 0x20) = rcos(ang);
            *(s32*)(p + 0x24) = -rsin(ang);
        }
    } else if (f == 1) {
        st = *(s8*)(obj + 2);
        if (st == 0x14) {
            func_800171E8(obj, 0x18);
        } else if (st == 0x15) {
            func_800171E8(obj, 0x19);
        } else if (st == 0x16) {
            func_800171E8(obj, 0x1A);
        } else if (st == 0x17) {
            func_800171E8(obj, 0x1B);
        }
        e = D_800D1C00;
        e[0x28] &= obj[0x95];
        obj[5]--;
    }
    func_8002D9EC(obj, 0x10, 0x10);
}
