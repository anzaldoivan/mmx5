#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_8009A427;

void func_800EF74C_ovl24(u8* arg0) {
    s32 two = 2;
    u8* p;
    u8 v;

    if (D_800C931C[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        p = D_8009A420;
        v = p[7];
        if (v == 0) {
            p[7] = two;
        } else {
            p[7] = v - 1;
        }
    } else if (D_800C931C[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        p = D_8009A420;
        v = p[7];
        if (v == two) {
            p[7] = 0;
        } else {
            p[7] = v + 1;
        }
    }
    if (D_800C931C[2] & 0x40) {
        play_sound(0, 0x22, 0);
        switch (D_8009A427) {
        case 0:
            arg0[1] = 6;
            arg0[2] = 0;
            break;
        case 1:
            arg0[1] = 7;
            arg0[2] = 0;
            break;
        case 2:
            arg0[1] = 9;
            arg0[2] = 0;
            break;
        }
    }
}

extern u8 D_800D1C00[];
extern u8 D_8009A427;
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);

void func_800EF874_ovl24(u8* a0) {
    u8* p;

    func_8001E668();
    init_checkpoint_positions();
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
