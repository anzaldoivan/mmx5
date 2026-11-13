/* Shared body (DK-5), from the banked draft of func_800F486C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern s16 D_80102FEC_ovl04[][20];
extern u8 D_8009A0A0[];
extern s8 D_800D1C00[];
extern s16 D_8009A0AE;

void DEDUP_NAME(u8* obj) {
    u8* p;
    u8* base;
    s32 i;
    s32 y;
    s32 k;
    s32 h;
    s32 g;
    s32 m;
    s16 x;
    u8* q;
    s16 t;

    if (obj[0x8F] == 0) {
        t = *(s16*)(obj + 0x7E);
        if (t >= 0x250) {
            return;
        }
        x = *(s16*)(obj + 0xE);
        k = t + 0x10;
        h = D_80102FEC_ovl04[obj[0x91]][k / 32] - 0x10;
        if (h < x) {
            *(s16*)(obj + 0xE) = *(s16*)(obj + 0xE) - 4;
        } else if (x < h) {
            *(s16*)(obj + 0xE) = *(s16*)(obj + 0xE) + 4;
        }
        if ((*(u16*)(obj + 0x7E) & 0x1F) == 0 && *(s16*)(obj + 0x7E) < 0x230) {
            func_800171E8(obj, 0x17);
            base = D_8009A0A0;
            for (i = 0; i < 6; i++) {
                p = func_8002D27C();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0x1A;
                    p[0x15] = func_8002DF78() & 0x40;
                    p[2] = 6;
                    *(s32*)(p + 0x20) = 0xFFFF0000;
                    *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                    *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                    *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
                    *(s16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                    *(s16*)(p + 0xA) =
                        *(s16*)(obj + 0xA) - ((func_8002DFB0() & 0xF) | 0x10);
                    *(s16*)(p + 0xE) =
                        *(s16*)(obj + 0xE) + (func_8002DFB0() & 7) + 0x10;
                    p[0x14] = base[0x14];
                }
            }
        }
        *(s16*)(obj + 0x7E) += 1;
        return;
    }

    *(s32*)(obj + 0x98) += 0x100;
    if (*(s8*)(obj + 0x45) == 7) {
        func_80016490(2, 0x17, obj);
        q = func_8002D1A4();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = 0x22;
            q[2] = 1;
            *(s16*)(q + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(q + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s16*)(q + 0xA) = *(s16*)(obj + 0xA) - 0x10;
            *(s16*)(q + 0xE) = *(s16*)(obj + 0xE) + 0x10;
            q[0x15] = obj[0x15];
            *(u8**)(q + 0x7C) = obj;
        }
        base = D_8009A0A0;
        for (i = 0; i < 3; i++) {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x1A;
                p[0x15] = func_8002DF78() & 0x40;
                p[2] = 3;
                *(s32*)(p + 0x20) = 0;
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
                *(s16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - (func_8002DFB0() & 7);
                *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 0x10;
                p[0x14] = base[0x14];
            }
        }
    }
    if (*(s8*)(obj + 0x45) == 9) {
        func_800171E8(obj, 4);
    }
    if (obj[0x8E] != 0) {
        if (--obj[0x8E] == 0) {
            func_800171E8(obj, 7);
        }
        return;
    }
    t = *(s16*)(obj + 0x94);
    if (t == *(s16*)(obj + 0xE)) {
        if (D_8009A0AE < t) {
            *(s16*)(obj + 0x94) = *(s16*)(obj + 0xE) - 0x20;
        } else if (t < D_8009A0AE) {
            *(s16*)(obj + 0x94) = *(s16*)(obj + 0xE) + 0x20;
        }
        g = (s32)
            D_800D1C00; // !FAKE: base set in each arm keeps the lui/addiu pair and lb 0xC
    } else {
        g = (s32)
            D_800D1C00; // !FAKE: base set in each arm keeps the lui/addiu pair and lb 0xC
    }
    m = 0xC; // !FAKE: compare constant in the 0x94 local keeps it in v1
    t = *(s8*)(g + 0xC);
    if (t != m) {
        if (*(s16*)(obj + 0x94) > 0xA0) {
            *(s16*)(obj + 0x94) = 0xA0;
        }
        if (*(s16*)(obj + 0x94) < 0x20) {
            *(s16*)(obj + 0x94) = 0x20;
        }
    } else {
        if (*(s16*)(obj + 0x94) > 0xB0) {
            *(s16*)(obj + 0x94) = 0xB0;
        }
        if (*(s16*)(obj + 0x94) < 0x30) {
            *(s16*)(obj + 0x94) = 0x30;
        }
    }
    k = *(s16*)(obj + 0xE);
    m = *(s16*)(obj + 0x94);
    y = *(u16*)(obj + 0xE);
    if (m < k) {
        *(s16*)(obj + 0xE) = y - 1;
    } else if (k < m) {
        *(s16*)(obj + 0xE) = y + 1;
    } else {
        return;
    }
    if (*(s16*)(obj + 0xE) == *(s16*)(obj + 0x94)) {
        obj[0x8E] = 0x78;
    }
}
