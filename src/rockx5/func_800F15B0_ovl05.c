#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern u8 D_8009A197;
extern void* D_800F55E4_ovl05[];

void func_800F15B0_ovl05(u8* p) {
    s8 t;

    if (func_8002D938(p, 0x70, 0x70) != 0) {
        p[4] = 3;
        p[0x91] = 0;
        *(s16*)(p + 0x88) = 5;
    } else {
        func_8002D9EC(p, 0x60, 0x60);
        if (D_8009A197 == 0) {
            *(s32*)(p + 0x18) = *(s32*)(p + 8);
            *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
            func_80017248(p);
            ((void (*)(u8*))D_800F55E4_ovl05[(s8)p[5]])(p);
        }
        if ((s8)p[5] != 2) {
            t = p[0x45];
            if (t >= 0x32 || t == 2) {
                func_800317B8(p);
            }
            if (func_80031DD0(p) < 0) {
                p[0x90] = 1;
            }
            return;
        }
    }
    p[3] = 0;
}
