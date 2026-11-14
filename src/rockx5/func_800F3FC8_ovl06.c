#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern void func_80028B18(s32, s32, s32, void*);
extern s32 func_8002DFB0(void);
extern s32 func_8002DF78(void);
extern void func_80017248(u8* obj);
extern s32 rsin(s32);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8*);
extern u8 D_8009A0A0[];
extern void* D_800FE664_ovl06[];
extern u8 D_800FE62C_ovl06[];
extern u8 D_8009A244;
extern u8 D_80074EE0[];
extern u8 D_80075660[];
extern u8 D_8009A1F8[];
extern u8 D_8009A420;

void func_800F3FC8_ovl06(u8* obj) {
    u8* q2;
    u8* p;
    u8* q;
    s32 r;
    s32 d;

    func_800317B8(obj);
    p = D_8009A0A0;
    if (*(s16*)(p + 0xA) >= 0xBF0 || obj[0x8B] != 0) {
        if (obj[0x8B] == 0) {
            obj[5] = 5;
            obj[6] = 0;
        }
        ((void (*)(u8*))D_800FE664_ovl06[(s8)obj[5]])(obj);
        func_8002FB58(obj);
        r = func_80031DD0(obj);
        if (obj[0x8E] == 0) {
            if (r < 0) {
                obj[5] = 6;
                obj[6] = 0;
                func_80028B18(0, 0xC80, 0xE0, D_800FE62C_ovl06);
                D_8009A244 = 1;
                return;
            }
            if (r != 0 && r != 0x7F) {
                *(u8**)(obj + 0x58) = D_80074EE0;
                *(u16*)(obj + 0x42) |= 0x8000;
                if ((u32)(r - 0x19) < 2) {
                    obj[0x8E] = 2;
                } else {
                    obj[0x8E] = 0x1E;
                }
            }
        } else {
            if (--obj[0x8E] == 0) {
                *(u8**)(obj + 0x58) = D_80075660;
                *(u16*)(obj + 0x42) &= 0x7FFF;
            } else if (
                !(((volatile u8*)obj)[0x8E] &
                  1)) { // !FAKE: volatile forces the reload the target does
                *(u16*)(obj + 0x42) |= 0x8000;
            } else {
                *(u16*)(obj + 0x42) &= 0x7FFF;
            }
        }
    } else {
        if (obj[0x89] == 0) {
            obj[0x89]++;
            obj[5] = 3;
            obj[6] = 0;
            obj[0x8A]++;
            if ((func_8002DFB0() & 3) == 0) {
                d = *(s16*)(obj + 0xE) - *(s16*)(p + 0xE);
                if ((d >= 0) ? (d > 0x10)
                             : (*(s16*)(p + 0xE) - *(s16*)(obj + 0xE) > 0x10)) {
                    *(s16*)(obj + 0x7C) = 0;
                    obj[0x8A] = 0;
                    obj[5] = 4;
                    obj[0x88] = (func_8002DF78() & 3) + 1;
                }
            }
        }
        ((void (*)(u8*))D_800FE664_ovl06[(s8)obj[5]])(obj);
        func_80031DD0(obj);
        q = D_8009A1F8;
        if (*(s16*)(obj + 0xA) - *(s16*)(q + 0xA) >= 0x31) {
            *(s16*)(obj + 0xA) = *(s16*)(q + 0xA) + 0x30;
        }
        if (*(s16*)(obj + 0xA) - *(s16*)(q + 0xA) < 0) {
            *(s16*)(obj + 0xA) = *(s16*)(q + 0xA);
        }
        if (*(s16*)(obj + 0xE) - *(s16*)(q + 0xE) < 0x40) {
            *(s16*)(obj + 0xE) = *(s16*)(obj + 0xE) + 1;
        }
        if (*(s16*)(obj + 0xE) - *(s16*)(q + 0xE) >= 0xA1) {
            *(s16*)(obj + 0xE) = *(s16*)(obj + 0xE) - 1;
        }
        if (*(s16*)(obj + 0xA) < 0x200 && *(s16*)(obj + 0xE) >= 0x1A1) {
            *(s16*)(obj + 0xE) = *(s16*)(obj + 0xE) - 0x3C;
        }
        if (*(s16*)(obj + 0xA) >= 0x9D0) {
            q2 = D_8009A1F8;
            if (*(s16*)(obj + 0xE) - *(s16*)(q2 + 0xE) > 0x80) {
                (*(s16*)(obj + 0xE))--;
            }
        }
    }
    func_80017248(obj);
    if (obj[0x8D] == 0) {
        if (!(D_8009A420 & 1)) {
            obj[0x8C] = (obj[0x8C] + 1) & 0x3F;
            *(s16*)(obj + 0xE) += rsin(obj[0x8C] << 7) / 2096;
        }
        if (--((s8*)obj)[7] == 0) {
            func_80016490(2, 0x1B, obj);
            obj[7] = 0x3C;
        }
    }
    if (func_8002D800(obj) == 0) {
        func_8002D89C(obj);
    } else {
        obj[4] = 2;
    }
}
