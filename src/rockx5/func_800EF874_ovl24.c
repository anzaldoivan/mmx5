#include "types.h"

extern u8 D_800D1C00[];
extern u8 D_8009A427;
extern void func_8001E668(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);

void func_800EF874_ovl24(u8* a0) {
    u8* p;

    func_8001E668();
    func_8002ACC4();
    p = D_800D1C00;
    func_8002906C();
    func_80027238();
    D_8009A427 = 0;
    p[0x28] = 1;
    func_800F0C00_ovl24((s32)a0, 6, 1);
    func_800F0C00_ovl24((s32)a0, 8, 1);
    func_800F0C00_ovl24((s32)a0, 7, 1);
    func_800F0C00_ovl24((s32)a0, 9, 1);
    func_800F0C00_ovl24((s32)a0, 0xDB, 1);
    switch (((s8*)p)[0x27]) {
    case 0:
        func_800F0C00_ovl24((s32)a0, 0, 1);
        break;
    case 1:
        func_800F0C00_ovl24((s32)a0, 1, 1);
        break;
    case 2:
        func_800F0C00_ovl24((s32)a0, 0x16, 1);
        break;
    }
    if (D_800D1C00[0x26] < 0xB && a0[0x79] < 5) {
        func_800F0C00_ovl24((s32)a0, 0xDD, 1);
    }
    a0[2]++;
}
