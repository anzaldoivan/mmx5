/* Adapted from mmx6 @a8f96d1 src/shared/SLUS_013.95/wait_for_file_load.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern s32 CdControlB(s32, s32, u8*);
extern s32 CdReset(s32);
extern int VSync(int mode);
extern void task_yield(s32);
extern void func_80013288(s32);
extern void func_80013E14(void);
extern void func_80014574(s32, s32);
extern void func_80013D94(void);
extern void func_80014684(s32, s32, s32);
extern s32 func_80066D78(s32, s32);
extern void* func_80066D98(void* func);

extern u8 D_80091D50;
extern s32 D_80091D54;
extern u8 D_8009811C;
extern s8 D_8009A424;
extern s32 D_800E5A18;
extern u8* D_800E5A1C;
extern s32 D_800E5A20;
extern s32 D_800E5A24;
extern s32 D_800E5A30;
extern u8 D_800E5BE8;
extern u8 D_800E5BE9;
extern u8 D_800E5BEA;
extern s32 D_800E5BEC;
extern u32 D_800E5BF0;
extern s32 D_800E5C08[][2];

// Inlined twin of the PC port's file-table lookup: stores the member size, returns its lba.
static inline s32 func_8001551C_lookup(u8 idx, s32* out) {
    s32* e = D_800E5C08[idx];
    *out = e[1];
    return e[0];
}

void wait_for_file_load(s32 a0, s32 a1) {
    u8 arg0 = a0;
    u8 arg1 = a1;
    u8 sp10[8];
    u8 sp18;

    sp18 = 0xA0;
    D_800E5BE8 = 0;
    D_80091D54 = 0;
    while (D_8009811C != 2 || D_80091D50 != 0) {
        if (D_800E5BE8 == 0 && arg1 == 0 && D_8009A424 == 0) {
            ((void (*)(s32))func_80013288)(8);
            D_800E5BE8++;
        }
        ((void (*)())func_80013D94)(arg0);
        if (D_8009811C & 0xC0) {
            if (D_800E5A30 == 0) {
                u8 idx = D_800E5BE9;
                s32 v = D_800E5BEC;

                if (func_80066D78(1, 0) != 0) {
                    CdControlB(9, 0, 0);
                }
                if (D_8009811C != 0x80) {
                    D_800E5BF0 = 0;
                }
                D_8009811C = 0;
                D_800E5BE9 = idx;
                D_800E5BEC = v;
                do {
                    while (CdControlB(1, 0, sp10) == 0) {
                    }
                } while (sp10[0] & 0x40);
                D_800E5A30 = 0;
                D_800E5A24 = func_8001551C_lookup(idx, &D_800E5A20);
                D_800E5A1C = (u8*)v;
                D_800E5A18 = D_800E5A20;
                ((void (*)(void))func_80014574)();
            } else {
                func_80014684(D_800E5BE9, D_800E5BEA, D_800E5BEC);
            }
        } else if (++D_800E5BF0 >= 0x259) {
            func_80066D98(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, (u8*)&sp18, 0) == 0) {
            }
            VSync(3);
            D_8009811C = 0xC0;
        }
        task_yield(1);
    }
    if (arg1 != 0) {
        func_80013E14();
    }
}
