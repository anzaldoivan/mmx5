#include "types.h"
#include "mmx5/ovl56.h"
#include "mmx5/globals.h"
#include "addr.h"

#define D_800FC700_ovl56_as_Blk200 (*(Blk200*)D_800FC700_ovl56)
#define D_800FCB00_ovl56_as_Blk200 (*(Blk200*)D_800FCB00_ovl56)
#define D_800FCF00_ovl56_as_Blk200 (*(Blk200*)D_800FCF00_ovl56)
#define D_800FD300_ovl56_as_Blk200 (*(Blk200*)D_800FD300_ovl56)
#define D_800FD700_ovl56_as_Blk200 (*(Blk200*)D_800FD700_ovl56)
#define D_800FDB00_ovl56_as_Blk200 (*(Blk200*)D_800FDB00_ovl56)

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FA004_ovl56(u8* arg0) {
    u8* src;

    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    src = D_1F800028 + 0x800;
    D_800FBF00_ovl56.blk = *(Blk200*)src;
    src = D_1F800028 + 0xA00;
    D_800FC300_ovl56.blk = *(Blk200*)src;
    src = D_1F800028 + 0x2400;
    D_800FC700_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2600;
    D_800FCB00_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2800;
    D_800FCF00_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1C00;
    D_800FD300_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2A00;
    D_800FD700_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1E00;
    D_800FDB00_ovl56_as_Blk200 = *(Blk200*)src;
    arg0[1]++;
}
#undef D_800FC700_ovl56_as_Blk200
#undef D_800FCB00_ovl56_as_Blk200
#undef D_800FCF00_ovl56_as_Blk200
#undef D_800FD300_ovl56_as_Blk200
#undef D_800FD700_ovl56_as_Blk200
#undef D_800FDB00_ovl56_as_Blk200

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800D1F3C;
extern u8 D_800FD900_ovl56[];
extern u8 D_800FDD00_ovl56[];
extern u8 D_800FD500_ovl56[];

void func_800FA5C8_ovl56(u8* arg) {
    if (D_800D1F3C == 2) {
        u8* p = D_8009A1F8.u;
        *(s16*)(p + 0x62) = 0x500;
        p[0xA0] = 1;
        *(s16*)(arg + 4) = 0;
        func_8002C3CC(D_800FD900_ovl56, D_800FD700_ovl56, 0x100, 0x5A, 0x5A);
        load_palette(0x150, D_800FD900_ovl56, 0x10);
        func_8002C3CC(D_800FDD00_ovl56, D_800FDB00_ovl56, 0x100,
                      0x5A - *(s16*)(arg + 4), 0x5A);
        load_palette(0xF0, D_800FDD00_ovl56, 0x10);
        func_8002C3CC(D_800FD500_ovl56, D_800FD300_ovl56, 0x100,
                      *(s16*)(arg + 4), 0x5A);
        load_palette(0xE0, D_800FD500_ovl56, 0x10);
        arg[1]++;
        func_8002385C(0x67, 0xFF, 0);
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800FD900_ovl56[];
extern u8 D_800FDD00_ovl56[];
extern u8 D_800FD500_ovl56[];
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern u8 D_800D50DC;
extern X4_BackgroundObj D_8009A24C[3];
extern s32 D_80093DD0[];

void func_800FA6E4_ovl56(u8* arg) {
    func_8002C3CC(D_800FD900_ovl56, D_800FD700_ovl56, 0x100,
                  0x5A - *(s16*)(arg + 4), 0x5A);
    ((s32(*)())load_palette)(0x150, D_800FD900_ovl56, 0x10);
    func_8002C3CC(D_800FDD00_ovl56, D_800FDB00_ovl56, 0x100,
                  0x5A - *(s16*)(arg + 4), 0x5A);
    ((s32(*)())load_palette)(0xF0, D_800FDD00_ovl56, 0x10);
    func_8002C3CC(D_800FD500_ovl56, D_800FD300_ovl56, 0x100, *(s16*)(arg + 4),
                  0x5A);
    ((s32(*)())load_palette)(0xE0, D_800FD500_ovl56, 0x10);
    if (++*(s16*)(arg + 4) >= 0x5A) {
        D_8009A42C = 0;
        D_80093E66 = 0;
        D_800D50DC = 1;
        D_8009A24C[0].unk3 = 0;
        D_80093DD0[7] = -1;
        D_80093DD0[10] = 0xFFFF;
        arg[1]++;
        func_8002385C(0x68, 0xFF, 0);
    }
}

extern u8 D_800FCD00_ovl56[];
extern u8 D_800FD100_ovl56[];

void func_8002C1C8(void);
void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA834_ovl56(Ovl45State* arg0) {
    u8* g = D_8009A1F8.u;

    g[0xF4] = 1;
    *(s32*)(g + 0xB0) += 0x22222;
    arg0->unk4++;
    if (arg0->unk4 >= 0x5A) {
        func_8002C1C8();
        *(s16*)(g + 0xB2) = 0xC0;
        g[0xF4] = 1;
        arg0->unk4 = 0;
        func_8002C3CC(D_800FCD00_ovl56, D_800FCB00_ovl56, 0x100, 0x5A, 0x5A);
        load_palette(0x130, D_800FCD00_ovl56, 0x10);
        func_8002C3CC(D_800FD100_ovl56, D_800FCF00_ovl56, 0x100,
                      0x5A - arg0->unk4, 0x5A);
        load_palette(0x140, D_800FD100_ovl56, 0x10);
        arg0->unk1++;
        func_8002385C(0x6C, 0xFF, 0);
    }
}

extern u8 D_800FC900_ovl56[];
extern u8 D_800FCD00_ovl56[];
extern u8 D_800FD100_ovl56[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA954_ovl56(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FC900_ovl56, D_800FC700_ovl56, 0x100, arg0->unk4, 0x5A);
    ((s32(*)())load_palette)(0x120, D_800FC900_ovl56, 0x10);
    func_8002C3CC(D_800FCD00_ovl56, D_800FCB00_ovl56, 0x100, 0x5A - arg0->unk4,
                  0x5A);
    ((s32(*)())load_palette)(0x130, D_800FCD00_ovl56, 0x10);
    func_8002C3CC(D_800FD100_ovl56, D_800FCF00_ovl56, 0x100, 0x5A - arg0->unk4,
                  0x5A);
    ((s32(*)())load_palette)(0x140, D_800FD100_ovl56, 0x10);
    if (arg0->unk4 >= 0x5A) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
