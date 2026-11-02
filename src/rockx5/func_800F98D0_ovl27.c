#include "types.h"

extern void func_8001296C(s32);
extern void func_80012BF4(s32);
extern void func_80016490(s32, s32, void*);
extern void func_80016D54(s32, s32);
extern void func_8002A600(s32, s32, s32);
extern void func_8002DF54(u8* a0);
extern void func_800FAFE0_ovl27(u8*, s32);
extern void func_800FB104_ovl27(u8*, s32, s32);
extern u8 D_8009A0A0[];

static inline void func_800F98D0_ovl27_step(u8* obj) {
    func_8002DF54(obj);
    if (((s8*)obj)[2] == 0) {
        if (*(s16*)(obj + 0xA) >= 0x12D8) {
            func_8001296C(3);
            func_80016490(2, 0x69, 0);
            func_800FB104_ovl27(obj, 0x1340, 0xB0);
            func_800FAFE0_ovl27(obj, 2);
            func_8002A600(0x1E, 4, 2);
            *(s16*)(obj + 0xA) = 0x12D8;
            obj[6]++;
        } else if (--*(s16*)(obj + 0x80) == 0) {
            func_80012BF4(7);
            *(u16*)(obj + 0x80) = 0x20;
            func_8002A600(0x18, 1, 2);
        }
    } else if (*(s16*)(obj + 0xA) < 0x13A9) {
        func_800FAFE0_ovl27(obj, 3);
        *(s16*)(obj + 0xA) = 0x13A8;
        obj[6]++;
    }
}

void func_800F98D0_ovl27(u8* obj) {
    if ((u32)(D_8009A0A0[0xFA] - 2) < 2) {
        if (((s8*)obj)[2] == 0) {
            if (((s8*)obj)[0x82] != ((s8*)D_8009A0A0)[0xF3]) {
                if (((s8*)D_8009A0A0)[0xF3] == 0) {
                    func_80016490(2, 0x68, 0);
                } else {
                    func_80016D54(2, 0x68);
                }
            }
            obj[0x82] = D_8009A0A0[0xF3];
        }
    }
    {
        u8* d = D_8009A0A0;

        if (((s8*)d)[0xF3] == 0) {
            func_800F98D0_ovl27_step(obj);
        } else if ((u32)(d[0xFA] - 2) >= 2) {
            func_800F98D0_ovl27_step(obj);
        }
    }
}
