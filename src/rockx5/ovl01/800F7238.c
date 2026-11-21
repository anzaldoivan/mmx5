#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"

extern u8 D_80074DA0[];
extern u8 D_800FD2B8_ovl01[];
extern u8 D_800FD2C0_ovl01[];
extern u8 D_800FD2C4_ovl01[];
extern u8 D_800FD2C8_ovl01[];
extern u8 D_800FD2CC_ovl01[];

void func_800F7238_ovl01(u8* obj) {
    s8 state;

    state = ((s8*)obj)[2];
    obj[3] = 0;
    obj[0x5C] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    switch (state) {
    case 0:
        obj[0x60] = 3;
        set_animation(obj, 2);
        *(u8**)(obj + 0x50) = D_800FD2B8_ovl01;
        *(s32*)(obj + 0x58) = 0;
        *(u8**)(obj + 0x68) = D_800FD2C8_ovl01;
        *(s32*)(obj + 0x54) = 0;
        obj[4] = 1;
        obj[5] = 0;
        obj[0x15] = 0;
        obj[0x16] = 6;
        *(u16*)(obj + 0xA) -= 0x20;
        func_8002D9EC(obj, 0x10, 0x10);
        break;
    case 1:
        obj[0x60] = 6;
        set_animation(obj, 9);
        *(s32*)(obj + 0x58) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x68) = 0;
        obj[4] = state;
        obj[5] = state;
        obj[0x15] = 0;
        obj[0x16] = 0x30;
        break;
    case 2:
        obj[3] = 1;
        set_animation(obj, 6);
        obj[0x60] = 4;
        obj[0x5C] = 3;
        *(u8**)(obj + 0x58) = D_80074DA0;
        *(u8**)(obj + 0x50) = D_800FD2C0_ovl01;
        *(u8**)(obj + 0x54) = D_800FD2C4_ovl01;
        *(u8**)(obj + 0x68) = D_800FD2CC_ovl01;
        obj[4] = state;
        obj[5] = 0;
        obj[0x15] = 0;
        obj[0x16] = 6;
        *(u16*)(obj + 0xE) -= 0x20;
        break;
    }
    obj[6] = 0;
    obj[7] = 0;
}

extern u8 D_8009A197;
extern void (*D_800FD2EC_ovl01[])(u8*);
extern u8 D_800FD2D0_ovl01[];
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F73E0_ovl01(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) != 5) {
        if (D_8009A197 == 0) {
            D_800FD2EC_ovl01[*(s8*)(obj + 5)](obj);
            animate_object(obj);
        }
        if (func_800317B8(obj) == 0 && func_80031DD0(obj) >= 0) {
            goto alive; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8004FD24(obj);
    func_8004D4F4(2, D_800FD2D0_ovl01, obj);
    obj[4] = 3;
    return;
alive: // !FAKE: label kept for the matching branch layout
    if (is_off_screen(obj, 0x200, 0x100) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 3;
}
