#include "types.h"
#include "mmx5/ovl52.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

#define D_800FB160_ovl52_as_Blk200 (*(Blk200*)D_800FB160_ovl52)
#define D_800FB560_ovl52_as_Blk200 (*(Blk200*)D_800FB560_ovl52)

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FA004_ovl52(u8* arg0) {
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
    src = D_1F800028 + 0xC00;
    D_800FB160_ovl52_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0xE00;
    D_800FB560_ovl52_as_Blk200 = *(Blk200*)src;
    D_8009A1F8.u[3] = 0;
    D_8009A1F8.u[0xAB] = 0;
    D_8009A1F8.u[0x57] = 0;
    *(s16*)(D_8009A1F8.u + 0x5E) = 0;
    *(s16*)(D_8009A1F8.u + 0x62) = 0x100;
    D_8009A1F8.u[0xA0] = 1;
    arg0[1]++;
}
#undef D_800FB160_ovl52_as_Blk200
#undef D_800FB560_ovl52_as_Blk200

extern u8 D_800D1F3C;
extern u8 D_800FB760_ovl52[];
extern u8* D_800FB960_ovl52;
extern void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA1EC_ovl52(u8* obj) {
    u8* g;
    u8* s;

    if (D_800D1F3C == 2) {
        g = D_8009A1F8.u;
        g[0x57] = 1;
        *(s16*)(g + 0x5E) = 0x200;
        *(s16*)(g + 0x62) = 0x80;
        g[0xA0] = 1;
        g[0xAB] = 1;
        *(s16*)(g + 0xB2) = 0;
        *(s16*)(g + 0xB6) = 0x200;
        g[0xF4] = 1;
        *(s16*)(obj + 4) = 0;
        func_8002C3CC(D_800FB760_ovl52, D_800FB560_ovl52, 0x100, 0x78, 0x78);
        load_palette(0x70, D_800FB760_ovl52, 0x10);
        s = alloc_class6_slot();
        if (s != 0) {
            s[0] = 1;
            s[1] = 0xA;
            s[0x36] = 0x11;
            s[2] = 0;
            D_800FB960_ovl52 = s;
        }
        obj[1]++;
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 rsin(s32);
extern u8 D_800FB360_ovl52[];
extern u8 D_800FB760_ovl52[];
extern s32 D_800FB964_ovl52;

void func_800FA2DC_ovl52(u8* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = rsin(D_800FB964_ovl52);
    v = s * 0x10;
    D_800FB964_ovl52 = (D_800FB964_ovl52 + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8.u;
    *(s32*)(p + 0xB4) = 0x02000000 - v;
    p[0xF4] = 1;
    func_8002C3CC(D_800FB360_ovl52, D_800FB160_ovl52, 0x100,
                  ++*(s16*)(arg0 + 4), 0x78);
    ((s32(*)())load_palette)(0x60, D_800FB360_ovl52, 0x10);
    func_8002C3CC(D_800FB760_ovl52, D_800FB560_ovl52, 0x100,
                  0x78 - *(s16*)(arg0 + 4), 0x78);
    ((s32(*)())load_palette)(0x70, D_800FB760_ovl52, 0x10);
    if (*(s16*)(arg0 + 4) >= 0x78) {
        func_8002385C(0x49, 0xFF, 0);
        arg0[1]++;
    }
}

extern s32 rsin(s32);
extern u8 D_80091C44;
extern s32 D_800FB964_ovl52;

void func_800FA404_ovl52(u8* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = rsin(D_800FB964_ovl52);
    v = s * 0x10;
    D_800FB964_ovl52 = (D_800FB964_ovl52 + 0x10) & 0xFFF;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8.u;
    *(s32*)(p + 0xB4) = 0x02000000 - v;
    p[0xF4] = 1;
    if (D_80091C44 == 0) {
        load_palette(0x60, D_800FB160_ovl52, 0x10);
        load_palette(0x70, D_800FB560_ovl52, 0x10);
        *(s16*)(p + 0xA) = 0x1A0;
        p[0x3] = 1;
        *(s16*)(p + 0xE) = 8;
        *(s16*)(p + 0x5E) = 0x70;
        p[0x4C] = 1;
        p[0x57] = 1;
        *(s16*)(p + 0x62) = 8;
        p[0xA0] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x300;
        p[0xF4] = 1;
        play_sound(2, 0x6C, 0);
        func_8002385C(0x4A, 0xFF, 0);
        arg0[1]++;
    }
}

#include "shared/func_800FA520_ovl52.c"

extern void (*D_800FB0F0_ovl52[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA5F0_ovl52(u8* arg0) {
    D_800FB0F0_ovl52[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
