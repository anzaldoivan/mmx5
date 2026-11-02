#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern void func_8004FD90(u8*, s32, s32, s32);
extern u8 D_8009A244;
extern s32 D_800E92F8;
extern u8 D_80100858_ovl07[];

void func_800EF148_ovl07(u8* obj) {
    (*(u16*)(obj + 0x9C))++;
    if (*(u16*)(obj + 0x9C) < 120) {
        if (!(((volatile u16*)obj)[0x9C / 2] &
              7)) { // !FAKE: volatile reload of the counter
            func_8004FD90(obj, 1, 0x30, 0x30);
            func_8004FD90(obj, 1, 0x30, 0x30);
            func_8004FD90(obj, 1, 0x30, 0x30);
            func_8004FD90(obj, 1, 0x30, 0x30);
        }
    } else {
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        func_8004FD90(obj, 1, 0x30, 0x30);
        D_800E92F8 = 1;
        func_80028B18(0, 0x1EC0, 0xA0, D_80100858_ovl07);
        D_8009A244 = 1;
        *(u16*)(obj + 0x9C) = 0;
        obj[5]++;
    }
}
