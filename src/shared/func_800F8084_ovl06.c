/* Shared body (DK-5), from the banked draft of func_800F8084_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8003D29C(s32, s32);
extern void func_80024548(s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800FAFFC_ovl06(u8*, s32, s32, s32);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];
extern u16 D_800FF94C_ovl06;
extern u16 D_800FF94E_ovl06;

void DEDUP_NAME(u8* arg0) {
    s16 t;
    u8* p;
    u8* g = D_800D1C00;
    u8* q;
    u16 a;
    u16 b;
    u8 n;
    s8* r;
    s32 c;

    if (*(s8*)(g + 0xF) == 0) {
        t = --*(s16*)(arg0 + 0x7C);
        if (t == 0) {
            func_8003D29C(0x14, 0x40);
        } else if (t == 0x32) {
            q = D_8009A1F8;
            *(s32*)(arg0 + 0x8C) = *(s16*)(q + 0x26);
            *(s16*)(q + 0x26) = *(u16*)(q + 0x24) - 0x10;
        }
        if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
            r = (s8*)D_800D1C00;
            c = r[0xC];
            r[0x24] = 1;
            r[0x25] = 0;
            r[0xA2] = 0x36;
            *(u8**)(r + 0x20) = arg0;
            if (c == 0xC) {
                func_80024548(-1);
            } else {
                func_80024548(1);
            }
            p = D_1F80004C.bytes;
            p[0x86] = D_800D1C00[0xA2];
            arg0[0x15] = 0;
            *(s32*)(arg0 + 0x20) = 0;
            *(s32*)(arg0 + 0x28) = 0;
            *(s32*)(arg0 + 0x24) = 0;
            *(s32*)(arg0 + 0x2C) = 0x1000;
            func_800171E8(arg0, 0x14);
            func_800FAFFC_ovl06(arg0, *(s16*)(arg0 + 0xA), *(s16*)(arg0 + 0xE),
                                0x10);
            arg0[3] = 1;
            a = D_800FF94C_ovl06;
            b = D_800FF94E_ovl06;
            n = arg0[6];
            *(s16*)(arg0 + 0xA) = a + 0x12B8;
            *(s16*)(arg0 + 0xE) = b;
            arg0[6] = n + 1;
        }
    }
}
