#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern u8 D_80100F9C_ovl07[];
extern u8 D_80100FE0_ovl07[];

void func_800F27CC_ovl07(u8* obj) {
    s32 d;

    if (obj[0x82] != 0) {
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
        return;
    }
    if (*(s8*)(obj + 2) != 0) {
        func_800171E8(obj, 3);
        *(s16*)(obj + 0xE) = *(s16*)(obj + 0x7E);
    } else {
        func_800171E8(obj, 8);
        *(s16*)(obj + 0xA) = *(s16*)(obj + 0x7C);
    }
    obj[5] = 6;
    obj[6] = 0;
}
