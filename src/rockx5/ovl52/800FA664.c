#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl52.h"
#include "mmx5/sound.h"

extern void SetDispMask(s32);

void func_800FA664_ovl52(u8* arg0) {
    SetDispMask(1);
    func_8002385C(0x45, 0xFF, 0);
    arg0[1]++;
}

extern u8 D_80091C44;
extern void func_800132F8(s8 arg);

void func_800FA6A8_ovl52(Actor50* a) {
    if (D_80091C44 == 0) {
        func_800132F8(0x20);
        a->step++;
    }
}

extern signed char D_8009A424;
extern void func_80013288(s32);

void func_800FA6EC_ovl52(Actor50* a) {
    if (D_8009A424 == 0) {
        func_80013288(8);
        a->step++;
    }
}

#define func_800FA128_ovl40 func_800FA730_ovl52
#include "shared/func_800FA128_ovl40.c"
#undef func_800FA128_ovl40

void func_800FA75C_ovl52(UnkObj* obj) {
    UnkSpawn* s;

    s = func_8002D27C();
    if (s != 0) {
        s->unk0 = 0x41;
        s->unk1 = 0x1D;
        s->unk2 = 0;
        s->unkA = 0x40;
        s->unkE = 0x44;
        s->unk54 = 9;
    }
    obj->unk4 = 1;
    obj->unk1++;
}

extern X4_BackgroundObj D_8009A24C[3];

void func_800FA7C8_ovl52(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        D_8009A24C[0].unk3 = 1;
        func_8002385C(0x46, 0xFF, 0);
        arg0->unk1++;
    }
}

extern u8 D_80091C44;
extern void func_8002C1C8(void);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD8;

void func_800FA820_ovl52(u8* arg) {
    u8* p;

    if (D_80091C44 == 0) {
        p = (u8*)&D_8009A1F8.t;
        p[0xAB] = 1;
        *(u16*)(p + 0xB6) = 0x100;
        *(u16*)(p + 0xB2) = 0;
        p[0xF4] = 1;
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        D_80093DD8 = 0xFFFF;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        arg[1]++;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800FA8C8_ovl52(u8* arg0) {
    if (!(D_8009A420_as_s32 & 1)) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
    }
    if (D_800D50DE == 0) {
        func_8002385C(0x47, 0xFF, 0);
        arg0[1]++;
    }
}
#undef D_8009A420_as_s32

#include "shared/func_800FA954_ovl52.c"

extern u8* D_800FB960_ovl52;

void func_800FA99C_ovl52(u8* arg0) {
    D_8009A1F8.t99C.unkA0 = 1;
    D_8009A1F8.t99C.unk60.val += -0x44444;
    if (D_8009A1F8.t99C.unk60.val <= 0) {
        D_800FB960_ovl52[0x36] = 0x21;
        D_8009A1F8.t99C.unk60.val = 0;
        D_8009A1F8.t99C.unk5E = 0;
        D_8009A1F8.t99C.unk60.i.hi = 0x200;
        func_8002385C(0x48, 0xFF, 0);
        arg0[1]++;
    }
}

extern u8 D_80091C44;
extern u8 D_800FB360_ovl52[];
extern s32 D_800FB964_ovl52;

extern void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FAA24_ovl52(u8* e) {
    if (D_80091C44 == 0) {
        *(s16*)(e + 4) = 0;
        play_sound(2, 0x53, 0);
        func_8002C3CC(D_800FB360_ovl52, D_800FB160_ovl52, 0x100, *(s16*)(e + 4),
                      0x78);
        load_palette(0x60, D_800FB360_ovl52, 0x10);
        D_800FB964_ovl52 = 0;
        e[1]++;
    }
}

extern u8 D_80091C44;

void func_800FAABC_ovl52(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.u[0xA0] = 1;
        *(s32*)(D_8009A1F8.u + 0x5C) += -0x99999;
        if (*(s32*)(D_8009A1F8.u + 0x5C) <= 0) {
            *(s32*)(D_8009A1F8.u + 0x5C) = 0;
            func_8002385C(0x4B, 0xFF, 0);
            arg0[1]++;
        }
    }
}

extern u8 D_80091C44;

void func_800FAB34_ovl52(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.u[0x4C] = 1;
        *(s32*)(D_8009A1F8.u + 8) += -0xB3333;
        if (*(s32*)(D_8009A1F8.u + 8) <= 0x1200000) {
            *(s32*)(D_8009A1F8.u + 8) = 0x1200000;
            func_8002385C(0x4C, 0xFF, 0);
            arg0[1]++;
        }
    }
}

extern u8 D_80091C44;
extern u8* D_800FB960_ovl52;
extern s32 D_800FB964_ovl52;

void func_800FABB4_ovl52(u8* arg0) {
    if (D_80091C44 == 0) {
        D_800FB960_ovl52[0x36] = 0x21;
        D_8009A1F8.u[3] = 0;
        D_8009A1F8.u[0x4C] = 1;
        D_8009A1F8.u[0x57] = 1;
        *(s16*)(D_8009A1F8.u + 0x5E) = 0x200;
        *(s16*)(D_8009A1F8.u + 0x62) = 0x200;
        D_8009A1F8.u[0xA0] = 1;
        D_8009A1F8.u[0xAB] = 1;
        *(s16*)(D_8009A1F8.u + 0xB2) = 0;
        *(s16*)(D_8009A1F8.u + 0xB6) = 0x200;
        D_8009A1F8.u[0xF4] = 1;
        *(s16*)(arg0 + 4) = 0;
        D_800FB964_ovl52 = 0;
        play_sound(2, 0x53, 0);
        arg0[1]++;
    }
}

#include "shared/func_800FAC54_ovl52.c"

void func_800FACFC_ovl52(u8* arg0) {
    u8* p = D_8009A1F8.u;

    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += 0x100000;
    if (*(s32*)(p + 0x5C) > 0x33FFFFF) {
        *(s32*)(p + 0x5C) = 0x3400000;
        *(s16*)(arg0 + 4) = 0;
        *(s16*)(arg0 + 6) = 0;
        arg0[1]++;
    }
}

/* e: UnkObj: unk1, unk4, unk6 */
extern u8 D_800FB0D0_ovl52[];

void func_800FAD50_ovl52(UnkObj* e) {
    if (e->unk6 < 30) {
        e->unk6++;
        return;
    }
    if (++e->unk4 >= 8) {
        func_80028B18(1, 0x340, 0x240, D_800FB0D0_ovl52);
        D_8009A298.u = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

#include "shared/func_800FADE0_ovl52.c"

#define D_800FB0D8_ovl52 D_800FB0E0_ovl52

#define func_800FADE0_ovl52 func_800FAE54_ovl52
#include "shared/func_800FADE0_ovl52.c"
#undef func_800FADE0_ovl52
#undef D_800FB0D8_ovl52

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FB0E8_ovl52[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FAEC8_ovl52(Ovl45State* e) {
    if (++e->unk4 >= 8) {
        func_80028B18(1, 0x340, 0x240, D_800FB0E8_ovl52);
        D_8009A298.u = 1;
        e->unk4 = 0;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        D_80093DD0[6] = 0xFFFF;
        D_80093DD0[7] = 0xFFFF;
        e->unk1++;
        func_8002385C(0x4D, 0xFF, 0);
    }
}

#include "shared/func_800FAF7C_ovl52.c"

#define func_800FA2C0_ovl43 func_800FB004_ovl52
#include "shared/func_800FA2C0_ovl43.c"
#undef func_800FA2C0_ovl43

#define func_800FA30C_ovl43 func_800FB050_ovl52
#include "shared/func_800FA30C_ovl43.c"
#undef func_800FA30C_ovl43
