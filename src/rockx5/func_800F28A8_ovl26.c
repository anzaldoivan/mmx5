#include "types.h"
#include "addr.h"

extern u8* func_8002D144(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);

void func_800F28A8_ovl26(u8* p) {
    u8* q;
    u8* r;
    s8 v;
    s32 n;
    s32 t;

    if (--*(s16*)(p + 0x7C) == 0) {
        p[5] = 2;
        r = func_8002D144();
        if (r != 0) {
            r[0] = 1;
            r[1] = 0x1A;
            *(s16*)(r + 0xA) = *(s16*)(p + 0xA);
            *(s16*)(r + 0xE) = *(s16*)(p + 0xE);
            *(u8**)(D_1F80004C.bytes + 0x84) = r;
        }
    }
    func_8002D9EC(p, 0x60, 0x60);
    if (--*(s16*)(p + 0x7E) == -1) {
        *(u16*)(p + 0x42) ^= 0x8000;
        p[0x61] -= 5;
        if ((s8)p[0x61] >= 0x1A) {
            p[0x61] = 0;
        }
        v = p[0x61];
        n = v < 6;
        if (n) {
            n = 5;
        } else {
            n = v;
        }
        *(s16*)(p + 0x7E) = n;
        q = func_8002D27C();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = 0x3D;
            q[2] = 1;
            *(s32*)(q + 0x3C) = *(s32*)(p + 0x3C);
            *(s16*)(q + 0x40) = *(s16*)(p + 0x40);
            *(s32*)(q + 0x30) = *(s32*)(p + 0x30);
            *(s16*)(q + 0x42) = *(s16*)(p + 0x42);
            t = (func_8002DF78() & 3) * 16 - 0x30;
            *(s16*)(q + 0xA) = *(s16*)(p + 0xA) + t;
            t = (func_8002DF78() & 1) * 16 - 0x10;
            *(s16*)(q + 0xE) = *(s16*)(p + 0xE) + t;
            q[0x15] = func_8002DF78() & 0x40;
            *(u8**)(q + 0x50) = p;
        }
    }
}
