#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_800D1C00[];

void func_800FB218_ovl04(s8* obj) {
    if ((u8)D_800D1C00[0x28] & 0xF) {
        u8 m = obj[0x93] & 0xF;
        if ((u8)D_800D1C00[0x28] & m) {
            obj[0x95] = ~obj[0x93] | 0xF0;
            ((u8*)obj)[0x96] = 0xFF;
            obj[5]++;
        }
    }
    if (!((u8)D_800D1C00[0x28] & 0xF)) {
        s32 t = obj[0x93] & 0xF0;
        if (D_800D1C00[0x28] & t) {
            obj[0x95] = ~obj[0x93] | 0xF;
            ((u8*)obj)[0x96] = 0xFF;
            obj[5]++;
        }
    }
    if (D_800D1C00[0x28] == 0) {
        if ((u8)D_800D1C00[0x29] & 0xF) {
            u8 m = obj[0x93] & 0xF;
            if ((u8)D_800D1C00[0x29] & m) {
                ((u8*)obj)[0x95] = 0xFF;
                obj[0x96] = ~obj[0x93] | 0xF0;
                obj[5]++;
            }
        }
        if (!((u8)D_800D1C00[0x29] & 0xF)) {
            s32 t = obj[0x93] & 0xF0;
            if (D_800D1C00[0x29] & t) {
                ((u8*)obj)[0x95] = 0xFF;
                obj[0x96] = ~obj[0x93] | 0xF;
                obj[5]++;
            }
        }
    }
    func_8002D9EC((u8*)obj, 0x10, 0x10);
}
