#include "types.h"

extern void func_800F2AE8_ovl05(void);
extern void func_800F2C44_ovl05(u8*);
extern u8* func_8002D27C(void);
extern void func_80028B18(s32, s32, s32, void*);
extern void func_80016490(s32, s32, void*);
extern void func_80012BF4(s32);
extern u8 D_8009A1F8[];
extern s16 D_800F595C_ovl05;
extern s16 D_800F595E_ovl05;
extern s16 D_800F5960_ovl05;
extern s16 D_800F5962_ovl05;
extern u8 D_80092090[];
extern u8 D_80096D98[];
extern u8 D_800F5964_ovl05[];
extern u16 D_800F5894_ovl05[];
extern u8 D_800F589C_ovl05[];
extern s32 D_8009A420;

void func_800F302C_ovl05(u8* o) {
    u8* p;
    u8* q;
    u8* d;
    u8* e;
    u8* g;
    s32 i;
    s32 n;
    s16 dx;

    ((s16*)o)[0x3E] += 1;
    ((s16*)o)[5] += 0x10;
    d = D_8009A1F8;
    ((s16*)d)[0x2F] = D_800F595C_ovl05 - ((s16*)o)[5];
    ((s16*)d)[0x31] = D_800F595E_ovl05 - ((s16*)o)[7];
    D_800F5960_ovl05 = ((s16*)d)[5] - 0x40;
    D_800F5962_ovl05 = ((s16*)o)[5] + 0xF;
    func_800F2AE8_ovl05();
    p = D_80092090;
    for (i = 0; i < 48; i++) {
        if (((s8*)p)[0] != 0 && ((s8*)p)[1] == 0x18 && ((s8*)p)[4] == 1) {
            func_800F2C44_ovl05(p);
        }
        p += 0x9C;
    }
    p = D_80096D98;
    for (i = 0; i < 32; i++) {
        if (((s8*)p)[0] != 0 && ((s8*)p)[1] == 9 && ((s8*)p)[4] == 1) {
            func_800F2C44_ovl05(p);
        }
        p += 0x9C;
    }
    *(u8*)(D_800F5964_ovl05 + 1) = 1;
    e = D_8009A1F8;
    if (((s16*)o)[5] >= *(s16*)(e + 0xA) + 0x140) {
        e[0xA1] = 2;
        e[0xA2] = 5;
        ((s8*)e)[0xA6] = -1;
        e[0x98] = 1;
        e[0xA0] = 1;
        *(s16*)(e + 0x5E) += *(s16*)(e + 0xA);
        o[6]++;
        for (n = o[0x80]; n < 3; n++) {
            g = D_8009A1F8;
            dx = D_800F5894_ovl05[n] - *(u16*)(g + 0xA);
            if ((u16)dx < 0x141) {
                q = func_8002D27C();
                if (q != 0) {
                    *(u8**)(q + 0x50) = o;
                    q[0] = 0x41;
                    q[1] = 0x14;
                    q[2] = o[0x80];
                    o[0x80]++;
                    D_800F5964_ovl05[0] = 1;
                }
            }
        }
    } else {
        o[0x81]++;
        if (o[0x81] >= 8) {
            o[0x81] = 0;
        }
        if (!(o[0x81] & 1)) {
            func_80028B18(1, 0x600, 0x900,
                          D_800F589C_ovl05 + (o[0x81] >> 1) * 8);
        }
    }
    if (D_8009A420 % 60 == 0) {
        func_80016490(2, 0x19, o);
    }
    func_80012BF4(2);
}
