#include "types.h"

void func_80026080(s32, u8);
void func_800266D4(s32, s32, s16, s32, s32, s32, s32);
s32 func_8003E6FC(void*, s8);
extern u8 D_8007182C[];
extern s8 D_8009A0A2;
extern D1C00 D_800D1C00;

void func_80025A74(HudObj* arg0) {
    s32 val;
    s8 n;

    if (arg0->unk93 == 0) {
        val = (s8)D_800D1C00.unk45;
        func_80026080(3, val / 10 + 0x3B);
        func_80026080(4, val % 10 + 0x3B);
    } else {
        val = arg0->unkA8[arg0->unk93];
        val = (s16)(val / func_8003E6FC(arg0, arg0->unk94));
        func_80026080(0xB, val / 100 + 0x3B);
        func_80026080(0xC, (s16)(val % 100) / 10 + 0x3B);
        func_80026080(0xD, val % 10 + 0x3B);
    }
    n = arg0->unk93;
    if (n != 0) {
        func_80026080(5, D_8007182C[n - 1]);
        n = arg0->unk93;
        if (n != 0) {
            val = (s16)(arg0->unkA8[n] / 6);
            if (val == 0 && arg0->unkA8[n] != 0) {
                val = 1;
            }
            func_800266D4(0x1F, 0x22, 0x50 - val, 0x50, 2,
                          (s16)(arg0->unk148 / 6), val);
            if (arg0->unk93 != 0) {
                val = (s16)(((s16)(arg0->unk148 / 6) - 0x30) / 2 + 0x99);
                if (val >= 0xA2) {
                    val = 0xA1;
                }
                func_80026080(2, val);
            }
        }
    }
    val = (D_800D1C00.unk47[D_8009A0A2] - 0x20) / 2 + 0x88;
    if (val >= 0x99) {
        val = 0x98;
    }
    func_80026080(0, val);
}
