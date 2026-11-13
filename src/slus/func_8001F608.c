#include "types.h"

extern void func_800132F8(s8 arg);
extern void func_80016490(s32, s32, void*);
extern void func_800211C4(void*, s32);
extern void func_80016D1C(u8 arg0);
extern s32 func_80017D88(void);
extern void func_800177B0(s32, s32);
extern u8 D_8009A420[];
extern u16 D_800C931C[];
extern u8 D_800D1599;
extern u8 D_8006FADD;
extern u8 D_8006FADC;
extern u8 D_800D1F28[];
extern u8 D_80071048[];

void func_8001F608(u8* arg0) {
    u8 old;
    u8 t;
    u16 c;
    u16 d;
    u16 e;
    u8* b = D_8009A420;
    u8* q;
    u8* r;

    if (((s8*)b)[4] != 0) {
        return;
    }
    if ((D_800C931C[2] & 0x10) && D_8009A420[7] != 4) {
        func_800132F8(8);
        D_8009A420[7] = 5;
        arg0[1]++;
        return;
    }
    if ((D_800C931C[2] & 0x40) && (D_8009A420[7] == 2 || D_8009A420[7] == 5)) {
        func_80016490(0, 0x22, 0);
        func_800132F8(8);
        arg0[1]++;
        return;
    }
    old = D_8009A420[7];
    func_800211C4(&D_8009A420[7], *(s16*)(arg0 + 8));
    if ((D_800C931C[2] & 0xA040) && D_8009A420[7] == 3) {
        func_80016490(0, 0xC, 0);
        D_800D1599 ^= 1;
        func_80016D1C(D_800D1599);
    }
    if ((D_800C931C[2] & 0xA040) && D_8009A420[7] == 1) {
        func_80016490(0, 0xC, 0);
        D_8006FADD ^= 1;
    }
    c = D_800C931C[2];
    if ((c & 0xA000) && D_8009A420[7] == 0) {
        if (c & 0x8000) {
            func_80016490(0, 0xC, 0);
            if (D_8006FADC != 0) {
                D_8006FADC--;
            } else {
                D_8006FADC = 2;
            }
        } else if (c & 0x2000) {
            func_80016490(0, 0xC, 0);
            if (D_8006FADC < 2) {
                D_8006FADC++;
            } else {
                D_8006FADC = 0;
            }
        }
    }
    d = D_800C931C[2];
    if ((d & 0xA050) && D_8009A420[7] == 4) {
        q = D_800D1F28;
        t = q[3];
        if (d & 0x8000) {
            if (t != 0) {
                q[3] = t - 1;
            }
        } else if (d & 0x2000) {
            if ((s8)t < 30) {
                q[3] = t + 1;
            }
        }
        r = D_800D1F28;
        if (t != ((s8*)r)[3]) {
            func_80016490(0, 0xC, 0);
        }
        e = D_800C931C[2];
        if (e & 0x10) {
            func_80017D88();
        } else if (e & 0x40) {
            func_80017D88();
            func_800177B0(D_80071048[((s8*)r)[3]], 0x7F);
        }
    }
    if (D_8009A420[7] != 4 && old == 4) {
        func_80017D88();
    }
}
