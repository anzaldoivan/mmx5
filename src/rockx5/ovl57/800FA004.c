#include "types.h"
#include "mmx5/ovl57.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

#define D_800FABE8_ovl57_as_Blk200 (*(Blk200*)D_800FABE8_ovl57)
#define D_800FAFE8_ovl57_as_Blk200 (*(Blk200*)D_800FAFE8_ovl57)
#define D_800FB3E8_ovl57_as_Blk200 (*(Blk200*)D_800FB3E8_ovl57)

extern void func_80013288(s32);

void func_800FA004_ovl57(u8* arg0) {
    Blk200* s;

    D_8009A1F8.u[0x3] = 0;
    D_8009A1F8.u[0x57] = 0;
    D_8009A1F8.u[0xAB] = 1;
    *(s16*)(D_8009A1F8.u + 0xB2) = 0;
    *(s16*)(D_8009A1F8.u + 0xB6) = 0;
    D_8009A1F8.u[0xF4] = 1;
    s = (Blk200*)(D_1F800028 + 0x800);
    D_800FABE8_ovl57_as_Blk200 = *s;
    s = (Blk200*)(D_1F800028 + 0xA00);
    D_800FAFE8_ovl57_as_Blk200 = *s;
    s = (Blk200*)(D_1F800028 + 0x1200);
    D_800FB3E8_ovl57_as_Blk200 = *s;
    func_80013288(8);
    arg0[1]++;
}
#undef D_800FABE8_ovl57_as_Blk200
#undef D_800FAFE8_ovl57_as_Blk200
#undef D_800FB3E8_ovl57_as_Blk200

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_800FB1E8_ovl57[];
extern u8 D_800FB5E8_ovl57[];

void func_800FA25C_ovl57(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        func_8002C3CC(D_800FB1E8_ovl57, D_800FAFE8_ovl57, 0x100,
                      0x3C - *(s16*)(arg0 + 4), 0x3C);
        load_palette(0x50, D_800FB1E8_ovl57, 0x10);
        func_8002C3CC(D_800FB5E8_ovl57, D_800FB3E8_ovl57, 0x100,
                      0x3C - *(s16*)(arg0 + 4), 0x3C);
        load_palette(0x90, D_800FB5E8_ovl57, 0x10);
        p = D_8009A1F8.u;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x20;
        *(s16*)(p + 0x62) = 0;
        p[0xA0] = 1;
        play_sound(2, 0x5A, 0);
        arg0[1]++;
    }
}

extern u8 D_800FADE8_ovl57[];
extern u8 D_800FB1E8_ovl57[];
extern u8 D_800FB5E8_ovl57[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA34C_ovl57(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FADE8_ovl57, D_800FABE8_ovl57, 0x100, arg0->unk4, 0x3C);
    ((s32(*)())load_palette)(0x40, D_800FADE8_ovl57, 0x10);
    func_8002C3CC(D_800FB1E8_ovl57, D_800FAFE8_ovl57, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    ((s32(*)())load_palette)(0x50, D_800FB1E8_ovl57, 0x10);
    func_8002C3CC(D_800FB5E8_ovl57, D_800FB3E8_ovl57, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    ((s32(*)())load_palette)(0x90, D_800FB5E8_ovl57, 0x10);
    if (arg0->unk4 >= 0x3C) {
        func_8002385C(0x6E, 0xFF, 0);
        arg0->unk1++;
    }
}
