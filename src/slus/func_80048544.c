#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002DF78(void);
extern s32 func_8003157C(void*, s16, s16);
extern s32 func_80031630(s32);
extern s32 func_80044F78(void* arg0);
extern void func_80045D44();
extern u8 D_800770B0[];
extern u8 D_800770CC[];
extern u8 D_800770E8[][3];
extern u8 D_8007B430[];
extern u8 D_8009A0A0[];
extern u8 D_800E9558;

void func_80048544(u8* arg0) {
    u8* p;
    u8* q;
    s32 t;
    u8* base;
    s32 r;
    u8 d;
    u8 k;
    u16 v;
    u16 v2;
    u16 v3;
    s32 i;

    p = D_1F800014;
    *(u8**)(arg0 + 0x38) = p + *(s32*)(p + 0x18);
    q = D_1F80001C.bytes;
    t = *(s32*)(q + 0x38);
    *(u8**)(arg0 + 0x30) = D_8007B430;
    *(s16*)(arg0 + 0x40) = 0x520;
    base = D_8009A0A0;
    *(s16*)(arg0 + 0x42) = 0x7801;
    arg0[0x16] = 0;
    *(u8**)(arg0 + 0x3C) = q + t;
    arg0[0x15] = base[0x15];
    func_80045D44(arg0, base, ((s8*)arg0)[1]);
    if (((s8*)arg0)[2] == 0) {
        r = func_8002DF78();
        arg0[0x8C] = 0;
        arg0[0x8D] = r % 6;
        k = D_800770E8[arg0[0x8D]][0];
        arg0[0x8E] = k;
        func_80016490(1, 0xF, arg0, k);
        D_800E9558 = arg0[0x15];
    } else {
        base[0x98]++;
        base[0x99]++;
        arg0[0x8E] = arg0[2];
        if (arg0[0x8E] != 1) {
            arg0[0x15] = D_800E9558;
        }
    }
    if (func_80031630(
            func_8003157C(arg0, *(s16*)(arg0 + 0xA), *(s16*)(arg0 + 0xE)))) {
        func_80044F78(arg0);
        arg0[4] = 2;
        return;
    }
    d = arg0[0x8E];
    if (d == 1) {
        v = *(u16*)(arg0 + 0xA);
        *(u16*)(arg0 + 0x90) = v;
        *(u16*)(arg0 + 0x92) = v;
        if (arg0[0x15]) {
            *(u16*)(arg0 + 0xA) = v + 0x30;
        } else {
            *(u16*)(arg0 + 0xA) = v - 0x30;
        }
        *(s32*)(arg0 + 0x20) = -0x60000;
        *(s32*)(arg0 + 0x24) = 0;
        func_800171E8(arg0, 0);
    } else if (d == 2) {
        v2 = *(u16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = -0x60000;
        *(u16*)(arg0 + 0x90) = v2;
        *(u16*)(arg0 + 0x92) = v2;
        v2 += 0x38;
        *(u16*)(arg0 + 0xE) = v2;
        func_800171E8(arg0, 1);
    } else {
        v3 = *(u16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0x60000;
        *(u16*)(arg0 + 0x90) = v3;
        *(u16*)(arg0 + 0x92) = v3;
        v3 -= 0x3C;
        *(u16*)(arg0 + 0xE) = v3;
        func_800171E8(arg0, 2);
    }
    i = arg0[0x45] & 0x3F;
    *(u8**)(arg0 + 0x68) = D_800770CC + i * 4;
    *(u8**)(arg0 + 0x50) = D_800770B0 + i * 4;
    arg0[0x94] = i;
    if (arg0[0x15]) {
        *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x20);
    }
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[0x64] = 0;
    arg0[0x67] = 1;
    arg0[5] = 0;
    arg0[4]++;
    func_8002D9EC(arg0, 0x30, 0x30);
}
