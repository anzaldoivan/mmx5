#include "types.h"
#include "mmx5/ovl58.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

#include "shared/func_800FA454_ovl58.c"

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FA4C8_ovl58(Actor50* a) {
    if (D_8009A424 == 0) {
        func_800177B0(0x1B, 0x7F);
        a->step++;
    }
}

extern u8 D_800D1F3C;

void func_800FA510_ovl58(UnkObj* arg0) {
    if (D_800D1F3C == 2) {
        D_8009A1F8.t.unk57 = 1;
        D_8009A1F8.t.unk5E = 0;
        D_8009A1F8.t.unk62 = 0;
        D_8009A1F8.t.unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern u8 D_800FBC00_ovl58[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA558_ovl58(UnkObj* arg0) {
    u8* p = D_8009A1F8.u;

    p[0xA0] = 1;
    *(s32*)(p + 0x60) += 0x22222;
    if (++arg0->unk4 >= 60) {
        *(s32*)(p + 0x60) = 0x800000;
        func_8002385C(0x5E, 0xFF, 0);
        arg0->unk4 = 0;
        func_8002C3CC(D_800FBC00_ovl58, D_800FBA00_ovl58.u, 0x100, 0x3C, 0x3C);
        ((s32(*)())load_palette)(0x60, D_800FBC00_ovl58, 0x10);
        arg0->unk1++;
    }
}

#include "shared/func_800FA628_ovl58.c"

extern u8 D_800FB800_ovl58[];
extern u8 D_800FBC00_ovl58[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FA680_ovl58(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FB800_ovl58, D_800FB600_ovl58.u, 0x100, arg0->unk4,
                  0x3C);
    ((s32(*)())load_palette)(0x50, D_800FB800_ovl58, 0x10);
    func_8002C3CC(D_800FBC00_ovl58, D_800FBA00_ovl58.u, 0x100,
                  0x3C - arg0->unk4, 0x3C);
    ((s32(*)())load_palette)(0x60, D_800FBC00_ovl58, 0x10);
    if (arg0->unk4 >= 0x3C) {
        arg0->unk1++;
        func_8002385C(0x5F, 0xFF, 0);
    }
}

extern u8 D_80091C44;

void func_800FA75C_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.pad0[3] = 0;
        D_8009A1F8.t.unk5E = 0;
        D_8009A1F8.t.unk62 = 0x100;
        D_8009A1F8.t.unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FA7A8_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    *(s32*)&p->pad60[0] += 0x40000;
    p->unkA0 = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        func_8002385C(0x60, 0xFF, 0);
        p->unk62 = 0x178;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

#include "shared/func_800FA844_ovl58.c"

#include "shared/func_800FA88C_ovl58.c"

extern u8 D_80091C44;
extern u8 D_800FB554_ovl58[];

void func_800FA928_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.padA1[0xA] = 0;
        D_8009A1F8.t.unk5E = 0;
        D_8009A1F8.t.unk62 = 0x200;
        func_80028B18(1, 0x70, 0x230, D_800FB554_ovl58);
        D_8009A1F8.t.unkA0 = 1;
        arg0->unk4 = 0;
        func_8002385C(0x62, 0xFF, 0);
        arg0->unk1++;
    }
}

#include "shared/func_800FA9B8_ovl58.c"

#include "shared/func_800FAA00_ovl58.c"

#include "shared/func_800FAA8C_ovl58.c"

extern void func_8002C1C8(void);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DE4;

void func_800FAAF4_ovl58(UnkObj* arg0) {
    arg0->unk4++;
    if (arg0->unk4 >= 0x14) {
        arg0->unk4 = 0;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DE4 = 0xFFFF0000;
        func_8002385C(0x63, 0xFF, 0);
        arg0->unk1++;
    }
}

#include "shared/func_800FAB80_ovl58.c"

#include "shared/func_800FAC04_ovl58.c"

#include "shared/func_800FACC4_ovl58.c"

#include "shared/func_800FAD10_ovl58.c"

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FAD78_ovl58(u8* arg) {
    if (D_80091C44 == 0) {
        play_sound(2, 0x55, 0);
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DD0[5] = 0xFFFF;
        D_80093DD0[6] = -1;
        D_80093DD0[7] = -1;
        arg[1]++;
        *(s16*)(arg + 6) = 0;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800FADFC_ovl58(UnkObj* arg0) {
    if ((D_8009A420_as_s32 & 1) == 0) {
        D_800D50DE += 1;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE >= 0x1F) {
        arg0->unk1++;
        arg0->unk4 = 0;
    }
}
#undef D_8009A420_as_s32

#include "shared/func_800FAE70_ovl58.c"

#include "shared/func_800FAEDC_ovl58.c"

extern u8 D_80091C44;

void func_800FAF74_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.unk57 = 1;
        D_8009A1F8.t.unk5E = 0x140;
        D_8009A1F8.t.unk62 = 0x400;
        D_8009A1F8.t.unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FAFC4_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    *(s32*)&p->pad58[4] -= 0x55555;
    p->unkA0 = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 60) {
        p->unk5E = 0;
        p->unkA0 = 1;
        func_8002385C(0x74, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FB050_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.pad0[3] = 1;
        D_8009A1F8.t.unkA = 0;
        D_8009A1F8.t.unkE = 0xE0;
        D_8009A1F8.t.pad49[0x4C - 0x49] = 1;
        D_8009A1F8.t.padA1[0xAB - 0xA1] = 0;
        arg0->unk1++;
    }
}

void func_800FB0A0_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    *(s32*)p->padC += 0x22222;
    p->pad49[0x4C - 0x49] = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 60) {
        p->unkE = 0x160;
        p->pad49[0x4C - 0x49] = 1;
        func_8002385C(0x75, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FB130_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.unk57 = 0;
        D_8009A1F8.t.padA1[0xAB - 0xA1] = 1;
        *(s16*)&D_8009A1F8.t.padA1[0xB2 - 0xA1] = 0;
        D_8009A1F8.t.unkB6 = 0x500;
        D_8009A1F8.t.unkF4 = 1;
        arg0->unk1++;
    }
}

void func_800FB180_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    *(s32*)&p->padA1[0xB0 - 0xA1] += 0x33333;
    p->unkF4 = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 60) {
        *(s16*)&p->padA1[0xB2 - 0xA1] = 0xC0;
        p->unkF4 = 1;
        func_8002385C(0x76, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FB210_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.pad0[3] = 0;
        D_8009A1F8.t.unk57 = 1;
        D_8009A1F8.t.unk5E = 0;
        D_8009A1F8.t.unk62 = 0x560;
        D_8009A1F8.t.unkA0 = 1;
        arg0->unk1++;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_80091C44;

void func_800FB260_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        if ((D_8009A420_as_s32 & 3) == 0) {
            D_80093E68 += 0x400;
            D_800D50DE += 1;
            D_8009A42E += 0x20;
        }
        if (D_80093E68 == 0x7C00) {
            D_8009A1F8.t.pad0[3] = 0;
            D_8009A1F8.t.unk57 = 1;
            D_8009A1F8.t.unk5E = 0x200;
            D_8009A1F8.t.unk62 = 0x100;
            D_8009A1F8.t.unkA0 = 1;
            arg0->unk1++;
            arg0->unk4 = 0;
        }
    }
}
#undef D_8009A420_as_s32

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800FC040_ovl58[];

void func_800FB304_ovl58(UnkObj* arg0) {
    u8* p = D_8009A1F8.u;

    p[0xAB] = 1;
    *(s16*)(p + 0xB2) = 0;
    *(s16*)(p + 0xB6) = 0x400;
    p[0xF4] = 1;
    func_8002C3CC(D_800FC040_ovl58, D_800FBE40_ovl58.u, 0x100,
                  0x3C - arg0->unk4, 0x3C);
    ((s32(*)())load_palette)(0xD0, D_800FC040_ovl58, 0x10);
    arg0->unk1++;
}

extern u8 D_800FBE20_ovl58[];
extern u8 D_800FC040_ovl58[];

void func_8002C1C8(void);
void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FB394_ovl58(Ovl45State* arg0) {
    func_8002C1C8();
    arg0->unk4++;
    func_8002C3CC(D_800FBE20_ovl58, D_800FBE00_ovl58.u, 0x10, arg0->unk4, 0x3C);
    ((s32(*)())load_palette)(0x40, D_800FBE20_ovl58, 1);
    func_8002C3CC(D_800FC040_ovl58, D_800FBE40_ovl58.u, 0x100,
                  0x3C - arg0->unk4, 0x3C);
    ((s32(*)())load_palette)(0xD0, D_800FC040_ovl58, 0x10);
    if (arg0->unk4 >= 0x3C) {
        arg0->unk4 = 0;
        func_8002385C(0x78, 0xFF, 0);
        arg0->unk1++;
    }
}

#define func_800FA2C0_ovl43 func_800FB47C_ovl58
#include "shared/func_800FA2C0_ovl43.c"
#undef func_800FA2C0_ovl43

#define func_800FAAF8_ovl57 func_800FB4C8_ovl58
#include "shared/func_800FAAF8_ovl57.c"
#undef func_800FAAF8_ovl57
