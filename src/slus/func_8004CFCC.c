#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D89C(u8*);
extern u8 D_80077534[];
extern u8 D_8009A420[];

void func_8004CFCC(u8* obj) {
    s8 kind = obj[2];
    u8 raw = obj[2];

    if (kind < 0) {
        *(u8**)(obj + 0x30) = D_80077534;
        obj[0x16] = 0;
        *(s8*)(obj + 0x14) = -1;
        obj[0x15] = 0;
        if (kind == -1) {
            u8* p = D_8009A420;
            *(s16*)(obj + 0x40) = 0x1D00;
            *(s32*)(obj + 0x3C) = D_801F300C + (s32)D_801F3000;
            *(s16*)(obj + 0x42) = 0x780A;
            *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[p[7] * 2] + 8;
            obj[0x54] = p[7];
            func_800171E8(obj, 0);
        } else {
            *(s16*)(obj + 0x40) = 0x1E00;
            *(s32*)(obj + 0x3C) = *(s32*)(D_801F3000 + 0x14) + (s32)D_801F3000;
            *(s16*)(obj + 0x42) = 0x7848;
            *(s16*)(obj + 0xA) = 0xA0;
            *(s16*)(obj + 0xE) = 0xD8;
            obj[0x47] = 1;
        }
        obj[4] = 1;
    } else {
        *(s16*)(obj + 0x40) = 0x1F00;
        *(s32*)(obj + 0x3C) = *(s32*)(D_801F3000 + 0x10) + (s32)D_801F3000;
        *(s8*)(obj + 0x14) = -1;
        obj[0x15] = 0;
        *(s16*)(obj + 0xA) = 0xA0;
        obj[0x16] = 0;
        if (kind == 0x20) {
            *(s16*)(obj + 0x42) = 0x7802;
            obj[4] = 1;
        } else {
            *(s16*)(obj + 0x42) = 0x7800;
            if (kind < 7) {
                *(s16*)(obj + 0xA) = 0x38;
                obj[4] = 3;
            } else if (kind < 0x10) {
                *(s16*)(obj + 0xA) = 0x110;
                obj[2] = raw - 7;
                obj[4] = 4;
            } else {
                obj[4] = 2;
            }
        }
    }
    func_8002D89C(obj);
}
