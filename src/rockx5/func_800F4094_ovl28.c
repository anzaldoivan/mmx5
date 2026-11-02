#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002F8FC(u8* a0);
extern u8* func_8002D0E4(void);
extern s32 func_8002B5B4(s32);
extern u8* func_8002D1A4();
extern s32 func_80031DD0(u8* a0);

void func_800F4094_ovl28(u8* a0) {
    u8* p;
    u8* q;
    u8* o;
    s32 r0;
    s32 r1;
    s8 t;

    if (func_8002D938(a0, 0x20, 0x14) == 0) {
        if (func_800317B8(a0) == 0) {
            func_80017248(a0);
            func_8002DF54(a0);
            func_8002D9EC(a0, 0x20, 0x14);
            if (a0[0x70] != 0 || (func_8002F8FC(a0), a0[0x70] != 0)) {
                p = func_8002D0E4();
                if (p != 0) {
                    p[0] = 0x61;
                    p[1] = 0xB;
                    p[2] = 7;
                    *(u16*)(p + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(p + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(p + 0x3C) = *(s32*)(a0 + 0x3C);
                    r0 = func_8002B5B4(0x40);
                    r1 = func_8002B5B4(0x40);
                    *(s16*)(p + 0x42) =
                        ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
                    if (a0[0x15] == 0) {
                        p[0x15] = 0x40;
                        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA) - 0x10;
                    } else {
                        p[0x15] = 0;
                        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA) + 0x10;
                    }
                    *(u16*)(p + 0xE) = *(u16*)(a0 + 0xE);
                    *(u8**)(p + 0x50) = a0;
                }
                a0[4]++;
            }
        } else {
            o = *(u8**)(a0 + 0x7C);
            if (o[0x8D] == 0) {
                o[0x8D] = 1;
                q = func_8002D1A4();
                if (q != 0) {
                    q[0] = 0x61;
                    q[1] = 0x23;
                    q[2] = 0xA;
                    *(s16*)(q + 0x42) = *(s16*)(a0 + 0x42) & 0x7FFF;
                    *(u16*)(q + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(q + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(q + 0x3C) = *(s32*)(a0 + 0x3C);
                    *(s32*)(q + 0x8) = *(s32*)(a0 + 0x8);
                    *(s32*)(q + 0xC) = *(s32*)(a0 + 0xC);
                    *(u8**)(q + 0x7C) = *(u8**)(a0 + 0x7C);
                }
            }
        }
        if (func_80031DD0(a0) < 0) {
            a0[4]++;
        }
    } else {
        a0[4]++;
    }
    t = (*(s8**)(a0 + 0x7C))[4];
    if (t == 2) {
        a0[4] = t;
    }
}
