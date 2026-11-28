#include "types.h"
#include "mmx5/ovl56.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

#define D_800FB5F0_ovl58 D_800FBEF0_ovl56

#define func_800FA454_ovl58 func_800FAAD4_ovl56
#include "shared/func_800FA454_ovl58.c"
#undef func_800FA454_ovl58
#undef D_800FB5F0_ovl58

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FAB48_ovl56(Ovl45State* a) {
    if (D_8009A424 == 0) {
        func_800177B0(0x1B, 0x7F);
        a->unk1++;
        a->unk4 = 0;
    }
}

extern u8 D_800D1F3C;
extern u8 D_800FC500_ovl56[];

extern void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FAB90_ovl56(u8* e) {
    u8* p;

    if (D_800D1F3C == 2) {
        func_8002C3CC(D_800FC500_ovl56, D_800FC300_ovl56.u, 0x100,
                      0x3C - *(s16*)(e + 4), 0x3C);
        load_palette(0x50, D_800FC500_ovl56, 0x10);
        p = D_8009A1F8.u;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0;
        p[0xA0] = 1;
        e[1]++;
    }
}

void func_800FAC30_ovl56(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    p->unkA0 = 1;
    *(s32*)p->pad60 += 0x22222;
    arg0->unk4++;
    if (arg0->unk4 >= 60) {
        *(s32*)p->pad60 = 0x800000;
        func_8002385C(0x5E, 0xFF, 0);
        arg0->unk1++;
    }
}

#define func_800FA628_ovl58 func_800FACBC_ovl56
#include "shared/func_800FA628_ovl58.c"
#undef func_800FA628_ovl58

extern u8 D_800FC100_ovl56[];
extern u8 D_800FC500_ovl56[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FAD14_ovl56(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FC100_ovl56, D_800FBF00_ovl56.u, 0x100, arg0->unk4,
                  0x3C);
    ((s32(*)())load_palette)(0x40, D_800FC100_ovl56, 0x10);
    func_8002C3CC(D_800FC500_ovl56, D_800FC300_ovl56.u, 0x100,
                  0x3C - arg0->unk4, 0x3C);
    ((s32(*)())load_palette)(0x50, D_800FC500_ovl56, 0x10);
    if (arg0->unk4 >= 0x3C) {
        arg0->unk1++;
        func_8002385C(0x5F, 0xFF, 0);
    }
}

extern u8 D_80091C44;
extern u8* D_800FBEF0_ovl56;

void func_800FADF0_ovl56(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        D_800FBEF0_ovl56[0x36] = 0x21;
        p[3] = 0;
        load_palette(0x40, D_800FBF00_ovl56.u, 0x10);
        load_palette(0x50, D_800FC300_ovl56.u, 0x10);
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x100;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

void func_800FAE8C_ovl56(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    p->unkA0 = 1;
    *(s32*)p->pad60 += 0x3BBBB;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        func_8002385C(0x60, 0xFF, 0);
        p->unk62 = 0x170;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

#define func_800FA844_ovl58 func_800FAF2C_ovl56
#include "shared/func_800FA844_ovl58.c"
#undef func_800FA844_ovl58

#define func_800FA88C_ovl58 func_800FAF74_ovl56
#include "shared/func_800FA88C_ovl58.c"
#undef func_800FA88C_ovl58

/* e: UnkObj: unk1, unk4 */
extern u8 D_80091C44;
extern u8 D_800FBE34_ovl56[];

void func_800FB010_ovl56(UnkObj* e) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        p[0x57] = 1;
        p[0xAB] = 0;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x200;
        func_80028B18(1, 0x70, 0x230, D_800FBE34_ovl56);
        p[0xA0] = 1;
        e->unk4 = 0;
        func_8002385C(0x62, 0xFF, 0);
        e->unk1++;
    }
}

#define func_800FA9B8_ovl58 func_800FB0AC_ovl56
#include "shared/func_800FA9B8_ovl58.c"
#undef func_800FA9B8_ovl58

#define func_800FAA00_ovl58 func_800FB0F4_ovl56
#include "shared/func_800FAA00_ovl58.c"
#undef func_800FAA00_ovl58

#define func_800FAA8C_ovl58 func_800FB180_ovl56
#include "shared/func_800FAA8C_ovl58.c"
#undef func_800FAA8C_ovl58

extern void func_8002C1C8(void);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DE0;

void func_800FB1E8_ovl56(UnkObj* arg0) {
    arg0->unk4++;
    if (arg0->unk4 >= 0x14) {
        arg0->unk4 = 0;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DE0 = 0xFFFF;
        func_8002385C(0x63, 0xFF, 0);
        arg0->unk1++;
    }
}

#define func_800FAB80_ovl58 func_800FB274_ovl56
#include "shared/func_800FAB80_ovl58.c"
#undef func_800FAB80_ovl58

#define func_800FAC04_ovl58 func_800FB2F8_ovl56
#include "shared/func_800FAC04_ovl58.c"
#undef func_800FAC04_ovl58

#define func_800FACC4_ovl58 func_800FB3B8_ovl56
#include "shared/func_800FACC4_ovl58.c"
#undef func_800FACC4_ovl58

#define func_800FAD10_ovl58 func_800FB404_ovl56
#include "shared/func_800FAD10_ovl58.c"
#undef func_800FAD10_ovl58

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FB46C_ovl56(u8* arg) {
    if (D_80091C44 == 0) {
        play_sound(2, 0x55, 0);
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DD0[5] = 0xFFFF;
        D_80093DD0[6] = 0xFFFF0000;
        arg[1]++;
        *(s16*)(arg + 6) = 0;
    }
}

void func_800FB4EC_ovl56(u8* arg0) {
    u16 t = ++D_800D50DE;

    D_8009A42E += 0x20;
    D_80093E68 += 0x400;
    if (t >= 0x1F) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

#define func_800FAE70_ovl58 func_800FB540_ovl56
#include "shared/func_800FAE70_ovl58.c"
#undef func_800FAE70_ovl58

#define func_800FAEDC_ovl58 func_800FB5AC_ovl56
#include "shared/func_800FAEDC_ovl58.c"
#undef func_800FAEDC_ovl58

extern u8 D_80091C44;
extern s32 func_80017E54(s32);

void func_800FB644_ovl56(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        func_80017E54(3);
        p = D_8009A1F8.u;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x400;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        *(s16*)(arg0 + 6) = 0;
        arg0[1]++;
    }
}

void func_800FB6AC_ovl56(u8* e) {
    u8* p;

    if (*(s16*)(e + 6) < 0x5B) {
        *(s16*)(e + 6) += 1;
        return;
    }
    p = D_8009A1F8.u;
    p[0xA0] = 1;
    *(s32*)(p + 0x60) += 0x2D82D;
    *(s16*)(e + 4) += 1;
    if (*(s16*)(e + 4) >= 0x5A) {
        e[1]++;
    }
}

extern u8 D_800D1F3C;
extern void func_800177B0(s32, s32);

void func_800FB72C_ovl56(u8* arg0) {
    if (D_800D1F3C == 0) {
        func_800177B0(0x13, 0x7F);
        arg0[1]++;
    }
}

extern u8 D_80091C44;

void func_800FB774_ovl56(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.bg[0].unk3 = 1;
        D_8009A1F8.bg[0].x_pos.i.hi = 0x60;
        D_8009A1F8.bg[0].y_pos.i.hi = 0x300;
        D_8009A1F8.bg[0].pad4C[0] = 1;
        D_8009A1F8.bg[2].unk3 = 0;
        play_sound(2, 0x5A, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);
extern u8 D_80091C44;

void func_800FB7E8_ovl56(u8* arg0) {
    if (D_80091C44 == 0) {
        if (!(D_8009A420_as_s32 & 1)) {
            D_80093E68 += 0x400;
            D_800D50DE++;
            D_8009A42E += 0x20;
        }
        if (D_80093E68 >= 0x7C00) {
            func_800132F8(8);
            func_80017E54(3);
            arg0[1]++;
        }
    }
}
#undef D_8009A420_as_s32

extern void func_8002C1C8(void);
extern u8 D_800D1F3C;
extern signed char D_8009A424;

void func_800FB88C_ovl56(u8* a0) {
    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8002C1C8();
        D_8009A1F8.u[0x3] = 0;
        D_8009A1F8.u[0x57] = 0;
        D_8009A1F8.u[0xAB] = 1;
        *(s16*)(D_8009A1F8.u + 0xB2) = 0;
        *(s16*)(D_8009A1F8.u + 0xB6) = 0x500;
        D_8009A1F8.u[0xF4] = 1;
        a0[1]++;
    }
}

extern void func_80013288(s32);

void func_800FB90C_ovl56(u8* o) {
    func_80013288(2);
    o[1]++;
}

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FB940_ovl56(Actor50* a) {
    if (D_8009A424 == 0) {
        func_800177B0(2, 0x7F);
        a->step++;
    }
}

extern u8 D_800D1F3C;

void func_800FB988_ovl56(u8* arg0) {
    if (D_800D1F3C == 2) {
        func_8002385C(0x69, 0xFF, 0);
        arg0[1]++;
    }
}

extern u8 D_80091C44;
extern u8* D_800FBEF0_ovl56;

void func_800FB9D8_ovl56(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        D_800FBEF0_ovl56[4] = 2;
        *(s16*)(p + 0xE) = 0x100;
        p[3] = 1;
        *(s16*)(p + 0xA) = 0x200;
        p[0x4C] = 1;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0xF8;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

void func_800FBA4C_ovl56(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    p->unkA0 = 1;
    *(s32*)&p->pad58[4] -= 0x3BBBB;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        p->unk5E = 0x190;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        func_8002385C(0x6A, 0xFF, 0);
        arg0->pad2[0] = 3;
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FBAE8_ovl56(UnkObj* arg0) {
    if (((s8*)arg0)[2] != 0) {
        if (arg0->unk6 == 0) {
            ((u8*)arg0)[2]--;
            play_sound(0, 0x13, 0);
            arg0->unk6 = 0x3C;
        } else {
            arg0->unk6--;
        }
    }
    if (D_80091C44 == 0) {
        arg0->unk1++;
    }
}

void func_800FBB74_ovl56(UnkObj* arg0) {
    u8* p;
    u8 n;

    n = arg0->pad2[0];
    if (*(s8*)&arg0->pad2[0] != 0) {
        if (arg0->unk6 == 0) {
            arg0->pad2[0] = n - 1;
            play_sound(0, 0x13, 0);
            arg0->unk6 = 0x3C;
        } else {
            arg0->unk6--;
        }
    }
    p = D_8009A1F8.u;
    p[0x4C] = 1;
    *(s32*)(p + 8) += 0xFFFBBBBC;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        *(s16*)(p + 0xA) = 0x180;
        p[0x4C] = 1;
        func_8002385C(0x6B, 0xFF, 0);
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FBC4C_ovl56(UnkObj* arg0) {
    u8* p;

    if (((s8*)arg0)[2] != 0) {
        if (arg0->unk6 == 0) {
            ((u8*)arg0)[2]--;
            play_sound(0, 0x13, 0);
            arg0->unk6 = 0x3C;
        } else {
            arg0->unk6--;
        }
    }
    if (D_80091C44 == 0) {
        p = (u8*)&D_8009A1F8.t;
        p[0x3] = 0;
        p[0x57] = 0;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x600;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FBCFC_ovl56(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.unk57 = 1;
        D_8009A1F8.t.unk5E = 0;
        D_8009A1F8.t.unk62 = 0x600;
        D_8009A1F8.t.unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);

void func_800FBD48_ovl56(u8* arg0) {
    if (++*(s16*)(arg0 + 4) >= 300) {
        func_800132F8(8);
        arg0[1]++;
        func_80017E54(3);
    }
}

#define func_800FAAF8_ovl57 func_800FBDA8_ovl56
#include "shared/func_800FAAF8_ovl57.c"
#undef func_800FAAF8_ovl57
