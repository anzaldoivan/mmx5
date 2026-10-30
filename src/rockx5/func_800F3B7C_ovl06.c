#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern u32 func_8002DFB0(void);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];

void func_800F3B7C_ovl06(u8* obj) {
    u8* child;
    u8* pl;
    s32 ang;

    if (*(s8*)(obj + 0x45) == 2) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0xF;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8) + 0x300000;
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC) - 0x200000;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(u8**)(child + 0x7C) = obj;
            child[2] = 0;
            pl = D_8009A0A0;
            ang = ratan2(*(s16*)(pl + 0xE) - *(s16*)(child + 0xE),
                         *(s16*)(pl + 0xA) - *(s16*)(child + 0xA));
            *(s32*)(child + 0x20) = rcos(ang);
            *(s32*)(child + 0x24) = -rsin(ang);
        }
    }
    if (*(s8*)(obj + 0x45) == 7) {
        func_800171E8(obj, 0);
        *(s16*)(obj + 0x7C) = (u8)(func_8002DFB0() % 50) + 40;
        if (*(s16*)(obj + 0x7E) == 0) {
            obj[6] = obj[6] + 1;
        } else {
            *(s16*)(obj + 0x7E) = *(s16*)(obj + 0x7E) - 1;
            obj[6] = obj[6] - 1;
        }
    }
}
