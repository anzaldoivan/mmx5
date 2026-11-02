#include "types.h"
#include "addr.h"

#define SCR D_1F80004C.scr82
extern void func_800171E8(u8* obj, s32 state);
extern s32 D_800FB638_ovl10;
extern u8 D_8009A0A0[];
extern u8 D_80074DA0[];
extern u8 D_80074EE0[];
extern u8 D_800FB6A0_ovl10[];
extern u8 D_800FB6A4_ovl10[];
extern Unk800770CC D_800FB6B0_ovl10;
extern u8 D_800FB6B4_ovl10[];
extern u8 D_800FB6B8_ovl10[];
extern u8 D_800FB6BC_ovl10[];

void func_800F0478_ovl10(u8* obj) {
    u8* g = D_8009A0A0;
    s32 v;

    *(s32**)(obj + 0x30) = &D_800FB638_ovl10;
    obj[0x14] = g[0x14];
    if (((s8*)obj)[2] >= 0x10) {
        obj[3] = 1;
        obj[0x5C] = 2;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FB6A0_ovl10;
        *(u8**)(obj + 0x54) = D_800FB6A4_ovl10;
        *(Unk800770CC**)(obj + 0x68) = &SCR->box;
        SCR->box = D_800FB6B0_ovl10;
        SCR->flags82 = 0;
        *(u8**)(obj + 0x58) = D_80074DA0;
        obj[4] = 4;
        obj[5] = 2;
        obj[0x70] = 0;
        obj[0x16] = 0;
        *(s16*)(D_1F80004C.bytes + 0x88) = 0x1F4;
        func_800171E8(obj, 0xC);
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x2C) = 0x1000;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
        switch (((s8*)obj)[2] - 0x10) {
        case 0:
            v = 0xFFFE0000;
            goto set; // !FAKE: goto kept for the matching branch layout
        case 1:
            v = 0xFFFF0000;
        set: // !FAKE: shared tail label
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = v;
            break;
        case 2:
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0x10000;
            break;
        case 3:
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0x20000;
            break;
        }
    } else {
        obj[0x5C] = 0x10;
        obj[0x60] = 4;
        *(u8**)(obj + 0x58) = D_80074EE0;
        obj[0x16] = 6;
        obj[0x61] = 0;
        obj[0x67] = 0;
        *(u8**)(obj + 0x54) = D_800FB6B8_ovl10;
        *(u8**)(obj + 0x50) = D_800FB6B4_ovl10;
        *(s32*)(obj + 0x18) = *(s32*)(obj + 8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_800171E8(obj, 0);
        D_1F80004C.bytes[0x80] = 0;
        obj[0x70] = 0;
        *(u8**)(obj + 0x68) = D_800FB6BC_ovl10;
        if (*(s16*)(g + 0xA) <= *(s16*)(obj + 0xA)) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        obj[0x67] = 1;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[5] = 5;
        obj[4] = 1;
        obj[6] = 0;
    }
}
