#include "types.h"

extern u32 func_8002DF78(void);
extern void func_800F8DFC_ovl09(u8* obj, s32 x, s32 y, s32 slot, s32 a4,
                                s32 a5);
extern s16 D_800FB454_ovl09[];
extern u8 D_800FB49C_ovl09[];
extern u8 D_800FB4E4_ovl09[];

void func_800F7E40_ovl09(u8* arg0) {
    u8 i;
    u8 j;
    u8 a, b, c;
    u8 d, e, f;
    s32 k;

    i = func_8002DF78() % 24;
    j = i * 3;
    a = D_800FB49C_ovl09[j];
    b = D_800FB49C_ovl09[j + 1];
    c = D_800FB49C_ovl09[j + 2];
    k = 0xF;
    i = func_8002DF78() % 6;
    j = i * 3;
    d = D_800FB4E4_ovl09[j];
    e = D_800FB4E4_ovl09[j + 1];
    f = D_800FB4E4_ovl09[j + 2];
    func_800F8DFC_ovl09(arg0, D_800FB454_ovl09[a - 1], 0x830, 1, k, d);
    func_800F8DFC_ovl09(arg0, D_800FB454_ovl09[b - 1], 0x830, 2, k, e);
    func_800F8DFC_ovl09(arg0, D_800FB454_ovl09[c - 1], 0x830, 3, k, f);
    arg0[6]++;
}
