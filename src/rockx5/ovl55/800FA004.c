#include "types.h"
#include "mmx5/ovl55.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

#define D_800FBAB8_ovl55_as_Blk200 (*(Blk200*)D_800FBAB8_ovl55)
#define D_800FBEB8_ovl55_as_Blk200 (*(Blk200*)D_800FBEB8_ovl55)
#define D_800FC2B8_ovl55_as_Blk200 (*(Blk200*)D_800FC2B8_ovl55)
#define D_800FC6B8_ovl55_as_Blk200 (*(Blk200*)D_800FC6B8_ovl55)
#define D_800FCAB8_ovl55_as_Blk200 (*(Blk200*)D_800FCAB8_ovl55)
#define D_800FCEB8_ovl55_as_Blk200 (*(Blk200*)D_800FCEB8_ovl55)

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A23C;

void func_800FA004_ovl55(u8* arg0) {
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
    D_8009A23C = 0;
    src = D_1F800028 + 0xC00;
    D_800FBAB8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2000;
    D_800FBEB8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0xA00;
    D_800FC2B8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x800;
    D_800FC6B8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1200;
    D_800FCAB8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1400;
    D_800FCEB8_ovl55_as_Blk200 = *(Blk200*)src;
    arg0[1]++;
}
#undef D_800FBAB8_ovl55_as_Blk200
#undef D_800FBEB8_ovl55_as_Blk200
#undef D_800FC2B8_ovl55_as_Blk200
#undef D_800FC6B8_ovl55_as_Blk200
#undef D_800FCAB8_ovl55_as_Blk200
#undef D_800FCEB8_ovl55_as_Blk200

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800FBCB8_ovl55[];
extern u8 D_800FC0B8_ovl55[];
extern u8 D_800FC4B8_ovl55[];
extern u8 D_800FC8B8_ovl55[];

void func_800FA478_ovl55(u8* arg0) {
    u8* r;
    s32 t;

    t = *(u16*)(arg0 + 4) + 1;
    *(u16*)(arg0 + 4) = t;
    if (t & 1) {
        u8* p = D_8009A1F8.u;
        *(s16*)(p + 0xA) = random_byte() % 9;
        *(s16*)(p + 0xE) = random_byte() % 5;
    } else {
        u8* q = D_8009A1F8.u;
        *(s16*)(q + 0xA) = 0;
        *(s16*)(q + 0xE) = 0;
    }
    r = D_8009A1F8.u;
    r[0x4C] = 1;
    func_8002C3CC(D_800FC0B8_ovl55, D_800FBEB8_ovl55, 0x100, *(s16*)(arg0 + 4),
                  0x1E);
    load_palette(0x100, D_800FC0B8_ovl55, 0x10);
    func_8002C3CC(D_800FC4B8_ovl55, D_800FC2B8_ovl55, 0x100, *(s16*)(arg0 + 4),
                  0x1E);
    load_palette(0x50, D_800FC4B8_ovl55, 0x10);
    func_8002C3CC(D_800FC8B8_ovl55, D_800FC6B8_ovl55, 0x100, *(s16*)(arg0 + 4),
                  0x1E);
    load_palette(0x40, D_800FC8B8_ovl55, 0x10);
    func_8002C3CC(D_800FBCB8_ovl55, D_800FBAB8_ovl55, 0x100,
                  0x1E - *(s16*)(arg0 + 4), 0x1E);
    load_palette(0x60, D_800FBCB8_ovl55, 0x10);
    r[3] = 1;
    if (*(s16*)(arg0 + 4) >= 0x1E) {
        *(u16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 rsin(s32);
extern u8 D_800FCCB8_ovl55[];
extern u8 D_800FD0B8_ovl55[];
extern s32 D_800FD2BC_ovl55;

void func_800FA660_ovl55(u8* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = rsin(D_800FD2BC_ovl55);
    v = s * 0x10;
    D_800FD2BC_ovl55 = (D_800FD2BC_ovl55 + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8.u;
    *(s32*)(p + 0xB4) = 0x02000000 - v;
    p[0xF4] = 1;
    func_8002C3CC(D_800FCCB8_ovl55, D_800FCAB8_ovl55, 0x100,
                  ++*(s16*)(arg0 + 4), 0x78);
    ((s32(*)())load_palette)(0x90, D_800FCCB8_ovl55, 0x10);
    func_8002C3CC(D_800FD0B8_ovl55, D_800FCEB8_ovl55, 0x100,
                  0x78 - *(s16*)(arg0 + 4), 0x78);
    ((s32(*)())load_palette)(0xA0, D_800FD0B8_ovl55, 0x10);
    if (*(s16*)(arg0 + 4) >= 0x78) {
        func_8002385C(0x49, 0xFF, 0);
        arg0[1]++;
    }
}

extern s32 rsin(s32);
extern u8 D_80091C44;
extern s32 D_800FD2BC_ovl55;

void func_800FA788_ovl55(u8* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = rsin(D_800FD2BC_ovl55);
    v = s << 4;
    D_800FD2BC_ovl55 = (D_800FD2BC_ovl55 + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8.u;
    *(s32*)(p + 0xB4) = 0x02000000 - v;
    p[0xF4] = 1;
    if (D_80091C44 == 0) {
        play_sound(2, 0x6C, 0);
        p[0x57] = 0;
        p[0x3] = 1;
        *(s16*)(p + 0xA) = 0x70;
        *(s16*)(p + 0xE) = 0x100;
        p[0x4C] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        arg0[1]++;
        func_8002385C(0x4A, 0xFF, 0);
    }
}

#define func_800FA520_ovl52 func_800FA864_ovl55
#include "shared/func_800FA520_ovl52.c"
#undef func_800FA520_ovl52

extern void (*D_800FBA10_ovl55[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA934_ovl55(u8* arg0) {
    D_800FBA10_ovl55[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
