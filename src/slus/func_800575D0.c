#include "types.h"

extern void func_8004FE6C(u8* self, s32 a1, s32 a2, s32 a3, s32 a4);
extern s32 func_8002DFB0(void);
extern u8* func_8002D53C(void);
extern s32 func_8002DF78(void);
extern s32 func_80016490(s32, s32, void*);
extern u16 D_80093E68;
extern u16 D_80093F70;
extern u8 D_8009A197;
extern u32 D_8009A420;
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern s8 D_800D1C00[];
extern u16 D_800D50DE;

void func_800575D0(u8* arg0) {
    u8* o;
    u8* o2;
    s32 f; // !FAKE: one s32 local reused for two flag words
    s8* c;
    s8* c2;
    s8* c3;

    do { // !FAKE: block fence keeps the sh before the sb
        *(u16*)(arg0 + 0x14) += 1;
        arg0[0x16]--;
    } while (0);
    if (((s8*)arg0)[0x16] == 0) {
        arg0[0x16] = 4;
        func_8004FE6C(arg0, 1, 0x60, 0x60, 2);
    }
    if (!(func_8002DFB0() & 1)) {
        o = func_8002D53C();
        if (o != 0) {
            o[0] = 1;
            o[1] = 4;
            func_8002DF78();
            *(u16*)(o + 8) = D_80093F70 & 0xFFF;
            *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
        }
    }
    if (!(func_8002DF78() & 3)) {
        o2 = func_8002D53C();
        if (o2 != 0) {
            o2[0] = 1;
            o2[1] = 6;
            *(u16*)(o2 + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(o2 + 0xE) = *(u16*)(arg0 + 0xE);
        }
    }
    if ((u16)(*(u16*)(arg0 + 0x14) % 5) == 0) {
        c = D_800D1C00;
        if (c[0xC] == 0xC && c[0x31] == 2 && (f = c[0x1D]) == 0x15) {
            f = D_8009A420 & 1;
            if (f == 0) {
                D_800D50DE += 1;
                D_8009A42E += 0x20;
                D_80093E68 += 0x400;
            }
        } else {
            D_800D50DE += 1;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
        c2 = D_800D1C00;
        if (c2[0xC] == 0x12 && D_800D50DE >= 0x11) {
            c2[0x2A] = 1;
        }
        if (D_800D50DE == 0x1F) {
            arg0[4]++;
            if (((s8*)arg0)[0] & 0x80) {
                *(u16*)(arg0 + 0x14) = 0xC8;
            } else {
                *(u16*)(arg0 + 0x14) = 0x28;
            }
            arg0[7] = 1;
            c3 = D_800D1C00;
            c3[0x24] = 0;
            func_80016490(0, 5, 0);
            D_8009A197 = 0;
            D_800C9310 = 1;
            if (c3[0xC] == 0) {
                *(u16*)(arg0 + 0x14) = 0x78;
            } else if (c3[0xC] == 0xC && c3[0x31] == 2 && c3[0x1D] == 0x15) {
                *(u16*)(arg0 + 0x14) = 0xB4;
            }
        }
    }
}
