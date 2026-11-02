#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8001296C(s32, s32);
extern s32 func_8003D29C(s32, s32);
extern u8* func_8002D144(void);
extern void func_800FAC9C_ovl04(u8*, s32);
extern s32 func_8002DF78(void);
extern void func_8002ABA4(u8*);
extern void func_8002AC34(u8*);
extern u8 D_800D1C00[];
extern u8 D_8009A0B5;
extern s8 D_8009A23C[];
extern u8* D_8010308C_ovl04;
extern u8 D_80074EE0[];
extern u8 D_800755C0[];
extern u8 D_8009A1F8[];
extern u8 D_80102B10_ovl04[];
extern u8 D_80102AF0_ovl04[];
extern s32 D_8009A420;

static inline void func_800FADF0_ovl04_inl(u8* arg0) {
    u8* g = D_800D1C00;
    s32 r;

    if (*(u16*)(g + 0x28) == 0) {
        if (arg0[0x8D] != 0) {
            arg0[0x8D]--;
            if (arg0[0x8D] != 0) {
                return;
            }
        }
        r = func_8002DF78() & 0xF;
        if ((g[0x2A] & 3) == 3) {
            g[0x28] = D_80102B10_ovl04[r * 2];
            g[0x29] = (&D_80102B10_ovl04[r * 2])[1];
        } else {
            g[0x28] = D_80102AF0_ovl04[r * 2];
            g[0x29] = (&D_80102AF0_ovl04[r * 2])[1];
        }
        arg0[0x8D] = 0x78;
    }
}

void func_800FADF0_ovl04(u8* arg0) {
    s32 r;
    u8* p;
    u8* b;
    u8* t;
    u8* g;
    s8* q;
    u8 c;
    s32 i;

    r = func_80031DD0(arg0);
    if (r < 0) {
        func_8001296C(0xA, r);
        g = D_800D1C00;
        g[0x2A] |= 4;
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
        func_8003D29C(0x14, D_8009A0B5);
        arg0[5]++;
        g[0x24] = 0;
        *(s16*)(arg0 + 0x7C) = 0;
        D_8009A23C[0] = 1;
        t = func_8002D144();
        D_8010308C_ovl04 = t;
        if (t != 0) {
            *t = 1;
            D_8010308C_ovl04[1] = 0xB;
        }
        return;
    }
    if (r > 0) {
        D_800D1C00[0x27] |= 1;
        if (r != 0x7F) {
            arg0[0x8F] = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
            *(u8**)(arg0 + 0x58) = D_80074EE0;
        }
    }
    c = arg0[0x8F];
    if (c != 0) {
        arg0[0x8F] = c + 0xFF;
        if (c & 2) {
            *(u16*)(arg0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
        if (arg0[0x8F] == 0) {
            *(u8**)(arg0 + 0x58) = D_800755C0;
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
    }
    func_800FAC9C_ovl04(arg0, r);
    func_800FADF0_ovl04_inl(arg0);
    b = D_8009A1F8;
    i = *(s16*)(arg0 + 0x86);
    *(s16*)(arg0 + 0xA) = *(u16*)(b + 0xA) + i;
    q = (s8*)D_800D1C00;
    if (q[0x2B] == 2) {
        if (D_8009A420 & 2) {
            *(s16*)(arg0 + 0xE) = *(u16*)(b + 0xE) + 0x76;
        } else {
            *(s16*)(arg0 + 0xE) = *(u16*)(b + 0xE) + 0x7A;
        }
    } else {
        *(s16*)(arg0 + 0xE) = *(u16*)(b + 0xE) + 0x78;
    }
    p = D_8009A1F8;
    if (*(u16*)(p + 0x34) & 0x10) {
        func_8002ABA4(p);
    }
    if (*(u16*)(p + 0x34) & 1) {
        func_8002AC34(p);
    }
}
