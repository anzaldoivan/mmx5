#include "types.h"

extern s32 func_8002D800(u8* a0);
extern int func_8002D6FC();
extern void func_8002D760(u8* a0);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern s32 D_800E92F8;

void func_80055F60(u8* a0) {
    s16 x;
    u8* r;
    u8* g;
    u8* d;
    u16 v;

    if (func_8002D800(a0) == 0) {
        r = *(u8**)(a0 + 0x18);
        g = D_8009A0A0;
        x = *(s16*)(g + 0xA);
        if (*(u16*)(r + 2) >= x && x >= *(u16*)(r + 0)) {
            x = *(s16*)(g + 0xE);
            if (*(u16*)(r + 6) >= x && x >= *(u16*)(r + 4)) {
                d = D_8009A1F8;
                d[0x47] = 2;
                v = *(u16*)(*(u8**)(a0 + 0x18) + 8);
                if (v != 0xFFFF) {
                    *(u16*)(d + 0x26) = v;
                }
                v = *(u16*)(*(u8**)(a0 + 0x18) + 0xA);
                if (v != 0xFFFF) {
                    *(u16*)(d + 0x24) = v;
                }
                v = *(u16*)(*(u8**)(a0 + 0x18) + 0xC);
                if (v != 0xFFFF) {
                    *(u16*)(d + 0x2A) = v;
                }
                v = *(u16*)(*(u8**)(a0 + 0x18) + 0xE);
                if (v != 0xFFFF) {
                    *(u16*)(d + 0x28) = v;
                }
                if (((s8*)a0)[2] & 0x80) {
                    D_800E92F8 = 1;
                    func_8002D6FC(a0, g);
                }
            }
        }
    } else {
        func_8002D760(a0);
    }
}
