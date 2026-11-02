#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_800F6D58_ovl00(s32);
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;
extern s32 D_800FB694_ovl00;
extern s32 D_800FB698_ovl00;

void func_800F711C_ovl00(u8* arg0) {
    s16 t;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        if (++D_800FB694_ovl00 == 3) {
            func_80016490(0, 5, arg0);
        }
        switch (D_800FB694_ovl00) {
        case 0:
            *(s16*)(arg0 + 0x7C) = 0x5A;
            break;
        case 1:
            *(s16*)(arg0 + 0x7C) = 0x46;
            break;
        case 2:
            *(s16*)(arg0 + 0x7C) = 0x32;
            break;
        default:
            *(s16*)(arg0 + 0x7C) = 0x78;
            break;
        }
    }
    if (D_800FB694_ovl00 == 0) {
        if (*(s16*)(arg0 + 0x7C) < 0x28) {
            func_800F6D58_ovl00(0);
            if (!(D_800FB698_ovl00 & 1)) {
                func_80016490(2, 3, arg0);
                D_800FB698_ovl00 |= 1;
            }
        }
    } else if (D_800FB694_ovl00 >= 0 && D_800FB694_ovl00 < 3) {
        func_800F6D58_ovl00(0);
    }
    if (D_800FB694_ovl00 == 1) {
        if (*(s16*)(arg0 + 0x7C) < 0x46) {
            func_800F6D58_ovl00(1);
            if (!(D_800FB698_ovl00 & 2)) {
                func_80016490(2, 3, arg0);
                D_800FB698_ovl00 |= 2;
            }
        }
    } else if (D_800FB694_ovl00 >= 1 && D_800FB694_ovl00 < 3) {
        func_800F6D58_ovl00(1);
    }
    if (D_800FB694_ovl00 == 2) {
        if (*(s16*)(arg0 + 0x7C) < 0x46) {
            func_800F6D58_ovl00(2);
            if (!(D_800FB698_ovl00 & 4)) {
                func_80016490(2, 3, arg0);
                D_800FB698_ovl00 |= 4;
            }
        }
    }
    if (D_800FB694_ovl00 == 3) {
        func_800F6D58_ovl00(3);
    }
    if (D_800FB694_ovl00 >= 3) {
        if (!(*(u16*)(arg0 + 0x7E) & 7)) {
            func_8004FD90(arg0, 1, 0x3F, 0x3F);
        }
        t = ++*(s16*)(arg0 + 0x7E);
        if (t % 5 == 0) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
            if (D_800D50DE == 0x1F) {
                *(s16*)(arg0 + 0x7C) = 0x78;
                *(s16*)(arg0 + 0xA) += 0x20;
                arg0[6] += 3;
            }
        }
    }
}
