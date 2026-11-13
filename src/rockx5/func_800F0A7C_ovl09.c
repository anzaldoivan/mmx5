#include "types.h"
#include "addr.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern s32 func_8002B5B4(s32);
extern u8* func_8002D0E4(void);
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800171E8(u8* obj, s32 state);
extern u16 D_800D50DE;
extern u8 D_800C9310;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800FAAF0_ovl09[];
extern u8 D_8009A1F8[];
extern u8 D_800FAAE8_ovl09[];

void func_800F0A7C_ovl09(u8* obj) {
    s32 i;
    u8* p;
    u8* q;
    s32 a;
    s32 b;

    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = 5;
        if (((s8*)obj)[2] == 2) {
            D_800D50DE = 0;
            D_8009A42E = 0;
            D_80093E68 = 0;
            D_800C9310 |= 1;
            for (i = 0x17; i >= 0; i--) {
                p = func_8002D27C();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0x31;
                    p[0x15] = func_8002DF78() & 0x40;
                    p[2] = 3;
                    *(u16*)(p + 0xA) =
                        *(u16*)(obj + 0xA) + (func_8002DFB0() % 8 * 16 - 0x80);
                    *(u16*)(p + 0xE) =
                        *(u16*)(obj + 0xE) + (func_8002DFB0() % 64 - 0x20);
                    *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(0x9C)] >> 7;
                    *(s32*)(p + 0x3C) = (s32)D_1F800020.s32s +
                                        D_1F800020.s32s[func_8002B5B4(0x9C)];
                    a = func_8002B5B4(0x9C);
                    b = func_8002B5B4(0x9C);
                    *(u16*)(p + 0x42) =
                        ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
                    p[0x14] = D_8009A0B4;
                }
                q = func_8002D0E4();
                if (q != 0) {
                    q[0] = 0x21;
                    q[1] = 4;
                    q[2] = 0;
                    q[4] = 0;
                    q[5] = 0;
                    q[6] = 0;
                    *(u16*)(q + 0xA) =
                        *(u16*)(obj + 0xA) + (func_8002DFB0() % 128 - 0x80);
                    *(u16*)(q + 0xE) =
                        *(u16*)(obj + 0xE) + (func_8002DFB0() % 128 - 0x40);
                    q[0x15] = 0;
                    q[0x14] = 0;
                    q[0x16] = 1;
                }
            }
            func_80028B18(0, 0x9C0, 0x610, D_800FAAF0_ovl09);
            D_8009A1F8[0x4C] = 1;
            obj[4]++;
        }
    } else {
        if (((s8*)obj)[2] == 2) {
            D_800D50DE = 0;
            D_8009A42E = 0;
            D_80093E68 = 0;
            D_800C9310 |= 1;
        }
        if ((obj[0x7C] & 7) == 0) {
            q = func_8002D0E4();
            if (q != 0) {
                q[0] = 0x21;
                q[1] = 4;
                q[2] = 0;
                q[4] = 0;
                q[5] = 0;
                q[6] = 0;
                if (((s8*)obj)[2] == 0) {
                    *(u16*)(q + 0xA) =
                        *(u16*)(obj + 0xA) + (func_8002DFB0() % 32 - 0x20);
                } else {
                    *(u16*)(q + 0xA) =
                        *(u16*)(obj + 0xA) - (func_8002DFB0() % 32 - 0x20);
                }
                *(u16*)(q + 0xE) =
                    *(u16*)(obj + 0xE) + (func_8002DFB0() % 64 - 0x20);
                q[0x15] = 0;
                q[0x14] = 0;
                q[0x16] = 1;
            }
            if ((obj[0x7C] & 0x1F) == 0) {
                func_8004D4F4(7, D_800FAAE8_ovl09, obj);
            }
            if (((s8*)obj)[2] == 2 && (obj[0x7C] & 0xF) == 0) {
                D_800D50DE = 0x1F;
                D_8009A42E = 0x3E0;
                D_800C9310 |= 1;
                D_80093E68 = 0x7C00;
            }
        }
    }
    if (*(s16*)(obj + 0x7C) == 0x3C) {
        func_800171E8(obj, 4);
    }
}
