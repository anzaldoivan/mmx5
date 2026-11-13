#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_80016D54(s32, s32);
extern void func_800FD050_ovl30(s32, void*, u8*, s32);

extern u8 D_800FD7C4_ovl30[];
extern u8 D_800FD7CC_ovl30[];
extern u8 D_800FD7D0_ovl30[];
extern u8 D_800FD7D4_ovl30[];
extern u8 D_800FD7D8_ovl30[];
extern u8 D_800FD7DC_ovl30[];
extern u8 D_800FD7E0_ovl30[];
extern u8 D_800FD7E4_ovl30[];
extern u8 D_800FDBD8_ovl30[];

void func_800FB2CC_ovl30(u8* o) {
    s8 st;

    if (*(s16*)(o + 0x7C) < 20) {
        *(s16*)(o + 0x7C) += 1;
        return;
    }
    func_80017248(o);
    switch (o[0x47]) {
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
        *(void**)(o + 0x50) = 0;
        *(void**)(o + 0x54) = 0;
        break;
    case 0x20:
        *(void**)(o + 0x50) = 0;
        *(void**)(o + 0x54) = D_800FD7C4_ovl30;
        break;
    case 0x21:
    case 0x22:
    case 0x23:
        *(void**)(o + 0x54) = D_800FD7CC_ovl30;
        break;
    case 0x24:
        *(void**)(o + 0x50) = D_800FD7D0_ovl30;
        *(void**)(o + 0x54) = D_800FD7D4_ovl30;
        break;
    case 0x25:
        *(void**)(o + 0x50) = D_800FD7D8_ovl30;
        *(void**)(o + 0x54) = D_800FD7DC_ovl30;
        break;
    case 0x26:
        if (o[0x15]) {
            func_800FD050_ovl30(2, D_800FDBD8_ovl30, o, 5);
        } else {
            func_800FD050_ovl30(2, D_800FDBD8_ovl30, o, 6);
        }
    case 0x27:
    case 0x28:
        *(void**)(o + 0x50) = D_800FD7E0_ovl30;
        *(void**)(o + 0x54) = D_800FD7E4_ovl30;
        break;
    }
    st = *(s8*)(o + 0x45);
    if (st == 1) {
        o[6] = 5;
        *(s16*)(o + 0x7E) = 0x40;
    } else if (st == 0x10) {
        func_80016490(2, 8, o);
    } else if (st == 0x20) {
        func_80016D54(2, 8);
    }
}
