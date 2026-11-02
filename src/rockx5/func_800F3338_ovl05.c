#include "types.h"

extern void func_800F2AE8_ovl05(void);
extern void func_800F2C44_ovl05(u8*);
extern void func_80016490(s32, s32, void*);
extern void func_80012BF4(s32);
extern void func_80012BD8(void);
extern u8 D_8009A1F8[];
extern s16 D_800F5960_ovl05;
extern s16 D_800F5962_ovl05;
extern u8 D_80092090[];
extern u8 D_80096D98[];
extern u8 D_800D1DBC;
extern s32 D_8009A420;

void func_800F3338_ovl05(u8* o) {
    u8* p;
    u8* d;
    u8* e;
    s32 i;

    ((s16*)o)[0x3E] += 1;
    d = D_8009A1F8;
    ((s16*)d)[0x2F] -= 0x10;
    func_80012BF4(2);
    D_800F5960_ovl05 = ((s16*)d)[5] - 0x40;
    D_800F5962_ovl05 = D_800F5960_ovl05 + 0x27F;
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
    if (((s16*)o)[0x3E] >= 0xD2) {
        func_80012BD8();
        e = D_8009A1F8;
        e[0xA0] = 1;
        e[0xA1] = 0;
        *(s16*)(e + 0x5E) = (*(s16*)(e + 0x5E) & 0x7F) | 0x380;
        e[0xA2] = D_800D1DBC - 1;
        ((s16*)o)[0x3E] = 0;
        o[6]++;
        ((s16*)o)[0x3F] = *(s16*)(e + 0x5E) - 0xB0;
        ((s16*)o)[0x3F] /= 16;
        o[0x81] = 0;
    }
    if (D_8009A420 % 60 == 0) {
        func_80016490(2, 0x19, o);
    }
}
