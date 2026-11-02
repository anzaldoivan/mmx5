#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern s8 D_8009A0A2;
extern u8 D_80100F9C_ovl07[];
extern u8 D_80100FE0_ovl07[];

extern D1030 D_80101030_ovl07;

void func_800F24C4_ovl07(u8* obj) {
    s32 d;
    u16 t;

    if (obj[0x83] != 0) {
        func_8002DF54(obj);
        if (*(s8*)(obj + 2) != 0) {
            if (*(s16*)(obj + 0x7E) - *(s16*)(obj + 0xE) >= 0) {
                d = obj[0x7E] - obj[0xE];
            } else {
                d = obj[0xE] - obj[0x7E];
            }
            obj[0x82] = d;
            obj[0x47] = D_80100FE0_ovl07[obj[0x82]];
        } else {
            if (*(s16*)(obj + 0x7C) - *(s16*)(obj + 0xA) >= 0) {
                d = obj[0x7C] - obj[0xA];
            } else {
                d = obj[0xA] - obj[0x7C];
            }
            obj[0x82] = d;
            obj[0x47] = D_80100F9C_ovl07[obj[0x82]];
        }
        if ((obj[0x82] >> 4) >= obj[0x81]) {
            if (*(s8*)(obj + 2) != 0) {
                func_800171E8(obj, 0);
                *(s16*)(obj + 0xE) = *(u16*)(obj + 0x7E) - 0x30;
            } else {
                func_800171E8(obj, 4);
                if (obj[0x86] != 0) {
                    *(s16*)(obj + 0xA) = *(u16*)(obj + 0x7C) + 0x40;
                } else {
                    *(s16*)(obj + 0xA) = *(u16*)(obj + 0x7C) - 0x40;
                }
            }
            t = D_80101030_ovl07.f4[D_8009A0A2];
            obj[5] = 4;
            obj[6] = 0;
            *(u16*)(obj + 0x88) = t;
        }
        obj[0x83]--;
        return;
    }
    obj[5] = 6;
    obj[6] = 0;
}
