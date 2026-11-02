#include "types.h"

extern s32 func_80032844(u8* a, u8* b);
extern void func_80032B00(u8* a, u8* b, s32 flags);
extern void func_8002ECB0(u8* a, u8* b, s32 c);
extern s32 func_8002FB58(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_800C9318;
extern s8 D_800D1DC0[];
extern s8 D_800D1E70[];

void func_8003240C(u8* arg0) {
    u8* p;
    register u8* q asm("$17"); // !FAKE: pin keeps the base in s1
    s16 x;
    s16 y;

    if (*(s32*)(arg0 + 0x68) != 0 && D_800C9318 == 0) {
        p = D_8009A0A0;
        x = *(s16*)(p + 0xA);
        y = *(s16*)(p + 0xE);
        if (func_80032844(arg0, p) == 0) {
            if (*(s8*)(arg0 + 0x76) > 0) {
                func_80032B00(arg0, p, arg0[0x72]);
            }
            func_8002ECB0(arg0, p, 0);
            func_8002FB58(p);
            if ((p[0x70] & 0xC) != 0xC && (p[0x70] & 3) != 3) {
                *(s32*)(p + 0x18) = *(s32*)(p + 0x8);
                *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
            } else {
                *(s16*)(p + 0xA) = x;
                *(s16*)(p + 0xE) = y;
            }
        }
        if (D_800D1DC0[0] != 0) {
            q = (u8*)D_800D1DC0;
            func_80032844(arg0, q);
            if (*(s8*)(arg0 + 0x77) > 0) {
                func_80032B00(arg0, q, arg0[0x73]);
            }
            func_8002ECB0(arg0, q, 1);
        }
        if (D_800D1E70[0] != 0) {
            q = (u8*)D_800D1E70;
            func_80032844(arg0, q);
            if (*(s8*)(arg0 + 0x78) > 0) {
                func_80032B00(arg0, q, arg0[0x74]);
            }
            func_8002ECB0(arg0, q, 2);
        }
    }
}
