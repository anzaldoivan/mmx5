#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8 D_800FD580_ovl38[];
extern u8 D_800FD584_ovl38[];
extern u8 D_800FD588_ovl38[];

void func_800FC048_ovl38(u8* p) {
    if (*(s8*)(p + 0x45) != 0) {
        *(u8**)(p + 0x50) = D_800FD580_ovl38;
        *(u8**)(p + 0x54) = D_800FD584_ovl38;
        *(u8**)(p + 0x68) = D_800FD588_ovl38;
        if (p[0x15] == 0) {
            *(s32*)(p + 0x20) = -0x28000;
        } else {
            *(s32*)(p + 0x20) = 0x28000;
        }
        *(s32*)(p + 0x28) = 0x3200;
        *(s32*)(p + 0x24) = 0;
        *(s32*)(p + 0x2C) = 0;
        *(s16*)(p + 0x7C) = 8;
        func_80016490(2, 0xA1, p);
        p[6]++;
    }
}
