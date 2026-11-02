#include "types.h"

extern s32 func_80066D78(s32, s32);
extern int CdGetSector(void* madr, int size);
extern int CdPosToInt(void* p);
extern void* func_80066D98(void* func);
extern s32 CdControlB(s32, s32, u8*);
extern s32 CdControl(s32, u8*, u8*);

extern void* D_80010038[4];
extern s32* D_80070308[];
extern u8 D_8009811C;
extern s32 D_8009E790;
extern s32 D_800BE9A8;
extern s32 D_800E5A18;
extern s32 D_800E5A20;
extern s32 D_800E5A24;
extern u32* D_800E5A28;
extern u32 D_800E5A2C;
extern s32 D_800E5A34;
extern u8 D_800E5A3D;
extern s32 D_800E5A40;
extern s32 D_800E5BD8;
extern s32 D_800E5BDC;
extern s32 D_800E5BE0;
extern s32 D_800E5BE4;
extern void D_800E5BF8;
extern u32 D_800E6368[];

void func_80014A30(void) {
    void* tab[4];
    s32 r;
    u32 t;
    s32 n;
    s32 m;

    tab[0] = D_80010038[0];
    tab[1] = D_80010038[1];
    tab[2] = D_80010038[2];
    tab[3] = D_80010038[3];
    if (D_8009811C == 0x80) {
        return;
    }
    r = func_80066D78(1, 0);
    if (r != 1) {
        func_80066D98(0);
        CdControlB(9, 0, 0);
        D_8009811C = 0x80;
    } else {
        if (D_800E5A40 == 0) {
            D_800E5A28 = D_800E6368;
            CdGetSector(&D_800E5BF8, 3);
            if (CdPosToInt(&D_800E5BF8) != D_800E5A24) {
                func_80066D98(0);
                CdControlB(9, 0, 0);
                D_8009811C = 0x80;
                return;
            }
            CdGetSector(D_800E5A28, 0x200);
            D_800E5A34 = *D_800E5A28++;
            D_800E5A20 = *D_800E5A28++;
            D_800E5A2C = *D_800E5A28++;
            n = *D_800E5A28++;
            D_800E5A3D = r;
            D_800E5BD8 = D_800E5BE0;
            D_800E5A40++;
            D_800E5A18 = n;
            D_800E5BDC = n;
            return;
        }
        ((void (*)(void))tab[D_800E5A2C >> 16])();
        if (D_800E5A18 == 0) {
            if ((D_800E5A2C >> 16) == 0) {
                *D_80070308[D_800E5A2C] = D_800E5BD8;
                D_800E5BD8 += D_800E5BDC;
            }
            D_800E5A34--;
            t = *D_800E5A28++;
            D_800E5A2C = t;
            m = *D_800E5A28++;
            D_800E5A18 = m;
            if ((t >> 16) == 0) {
                D_800E5BDC = m;
            }
            D_800E5A3D = r;
        }
        D_800E5A40++;
        if (D_800E5A34 == 0) {
            func_80066D98(0);
            D_8009811C = 0;
            while (CdControl(9, 0, 0) == 0) {
            }
            D_8009811C = 2;
            D_800BE9A8 = D_800E5BD8;
            D_8009E790 = D_800E5BE4;
        }
    }
}
