#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800F1334_ovl05(u8* parent, s16 x, s16 y, s32 kind);
extern u8 D_8009A0B4;
extern u8 D_800F5550_ovl05[];
extern u8 D_800F55A8_ovl05[];
extern s16 D_800F55B8_ovl05[][2];

void func_800F10FC_ovl05(u8* obj) {
    u8 kind;

    obj[0x16] = 7;
    obj[0x15] = 0;
    obj[0x14] = D_8009A0B4;
    *(u8**)(obj + 0x30) = D_800F5550_ovl05;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    kind = D_800F55A8_ovl05[obj[2] & 0xF];
    func_800F1334_ovl05(obj, *(s16*)(obj + 0xA) + D_800F55B8_ovl05[kind][0],
                        *(s16*)(obj + 0xE) + D_800F55B8_ovl05[kind][1],
                        ((volatile u8*)obj)[2] >>
                            4); // !FAKE: volatile reload of obj[2]
    switch (kind) {
    case 0:
        func_800171E8(obj, 9);
        break;
    case 1:
        func_800171E8(obj, 0xA);
        break;
    case 2:
        func_800171E8(obj, 0xC);
        break;
    case 3:
        func_800171E8(obj, 0xB);
        break;
    }
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[4] = 1;
    if (D_1F80004C.scr1334->unk80 == 0) {
        obj[4] = 2;
    }
}
