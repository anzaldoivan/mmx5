#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);
extern void func_80013288(s32);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FA18C_ovl46(u8* arg0) {
    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    func_80013288(8);
    arg0[1]++;
}

extern s8 D_8009A424;

void func_800FA200_ovl46(u8* arg0) {
    u8* p;

    if (D_8009A424 == 0) {
        p = D_8009A1F8.u;
        p[0x3] = 0;
        p[0x57] = 0;
        p[0xAB] = 1;
        *(s32*)(p + 0xB0) = 0;
        *(s32*)(p + 0xB4) = 0;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD8;

void func_800FA248_ovl46(u8* arg0) {
    if (++*(s16*)(arg0 + 4) == 30) {
        play_sound(2, 0x4E, 0);
    }
    if (*(s16*)(arg0 + 4) == 50) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DD8 = 0xFFFF0000;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800FA2D8_ovl46(u8* arg0) {
    if (!(D_8009A420_as_s32 & 3)) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE >= 0x1F) {
        func_8002385C(0x1A, 0xFF, 0);
        arg0[1]++;
    }
}
#undef D_8009A420_as_s32

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8* D_800FAC30_ovl46;

void func_800FA368_ovl46(u8* arg0) {
    u8* b;
    Spawn800FB000* p;

    if (D_80091C44 == 0) {
        b = D_8009A1F8.u;
        *(s16*)(b + 0xB2) = 0;
        *(s16*)(b + 0xB6) = 0x100;
        b[0xF4] = 1;
        func_8002C1C8();
        p = alloc_class6_slot();
        if (p != 0) {
            p->unk0 = 1;
            p->unk1 = 0xA;
            p->unk36 = 0x31;
            p->unk2 = 0;
            D_800FAC30_ovl46 = (u8*)p;
        }
        p = alloc_class6_slot();
        if (p != 0) {
            p->unk1 = 9;
            p->unk36 = 0x20;
            p->unk0 = 1;
            p->unk34 = 0x7FFF;
            p->unk2 = 2;
            p->unk38 = 0x1E;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}

void func_800FA43C_ovl46(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x1B, 0xFF, 0);
        D_8009A1F8.u[0x57] = 1;
        *(s32*)(D_8009A1F8.u + 0x5C) = 0;
        *(s32*)(D_8009A1F8.u + 0x60) = 0;
        D_8009A1F8.u[0xA0] = 1;
        arg0->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_80091C44;
extern u8 D_800FABB0_ovl46[];

void func_800FA4A4_ovl46(Ovl45State* e) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0x20, 0x10, D_800FABB0_ovl46);
        D_8009A298.u = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FABB8_ovl46[];

void func_800FA504_ovl46(Ovl45State* e) {
    if (++e->unk4 == 4) {
        func_80028B18(1, 0x10, 0x60, D_800FABB8_ovl46);
        D_8009A298.u = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FABC0_ovl46[];

void func_800FA574_ovl46(Ovl45State* e) {
    if (++e->unk4 == 4) {
        func_80028B18(1, 0x70, 0x60, D_800FABC0_ovl46);
        D_8009A298.u = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FABC8_ovl46[];

void func_800FA5E4_ovl46(Ovl45State* e) {
    if (++e->unk4 == 4) {
        func_80028B18(1, 0xC0, 0x10, D_800FABC8_ovl46);
        D_8009A298.u = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FABD0_ovl46[];

void func_800FA654_ovl46(Ovl45State* e) {
    if (++e->unk4 == 4) {
        func_80028B18(1, 0xD0, 0x60, D_800FABD0_ovl46);
        D_8009A298.u = 1;
        func_8002385C(0x1C, 0xFF, 0);
        e->unk4 = 0;
        e->unk1++;
    }
}

#include "shared/func_800FA6D4_ovl46.c"

#define func_800FA190_ovl42 func_800FA71C_ovl46
#include "shared/func_800FA190_ovl42.c"
#undef func_800FA190_ovl42

void func_800FA74C_ovl46(u8* e) {
    u8* p = D_8009A1F8.u;
    s32 a = *(s32*)(p + 0x60) + 0xCCCCC;
    s32 b = *(s32*)(p + 0xB4) + 0xCCCCC;

    p[0xA0] = 1;
    p[0xF4] = 1;
    *(s32*)(p + 0x60) = a;
    *(s32*)(p + 0xB4) = b;
    if (a > 0xFFFFFF) {
        func_8002385C(0x1D, 0xFF, 0);
        *(s32*)(p + 0x60) = 0x1000000;
        *(s32*)(p + 0xB4) = 0x2000000;
        e[1]++;
    }
}

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A24C[3];
extern u8* D_800FAC30_ovl46;

void func_800FA7E8_ovl46(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A24C[0].unk3 = 0;
        arg0->unk4 = 0;
        arg0->unk1++;
        D_800FAC30_ovl46[6] = 2;
    }
}

void func_800FA828_ovl46(UnkObj* obj) {
    UnkSpawn* s;

    s = func_8002D27C();
    if (s != 0) {
        s->unk0 = 0x41;
        s->unk1 = 0x1D;
        s->unk2 = 2;
        s->unkA = 0xA0;
        s->unkE = 0x60;
    }
    obj->unk4 = 1;
    obj->unk1++;
}

void func_800FA890_ovl46(UnkObj* e) {
    u8* p;

    if (e->unk4 == 0) {
        func_8002385C(0x1E, 0xFF, 0);
        p = D_8009A1F8.u;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0x200;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        e->unk4 = 0;
        e->unk6 = 0x14;
        e->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FA904_ovl46(UnkObj* e) {
    u8* p;
    u8* q;

    if (--e->unk6 == 0) {
        q = D_8009A1F8.u;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        e->unk6 = 0x3C;
    }
    p = D_8009A1F8.u;
    p[0xF4] = 1;
    if (D_80091C44 == 0) {
        *(s16*)(p + 0xA) = 0x340;
        p[3] = 1;
        *(s16*)(p + 0xE) = 0;
        p[0x4C] = 1;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x260;
        *(s16*)(p + 0x62) = 8;
        p[0xA0] = 1;
        e->unk1++;
    }
}

void func_800FA9AC_ovl46(UnkObj* e) {
    u8* p;
    u8* q;

    if (--e->unk6 == 0) {
        q = D_8009A1F8.u;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        e->unk6 = 0x3C;
    }
    p = D_8009A1F8.u;
    p[0xF4] = 1;
    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += -0xB3333;
    if (*(s32*)(p + 0x5C) <= 0x1F00000) {
        *(s32*)(p + 0x5C) = 0x1F00000;
        e->unk4 = 0;
        e->unk1++;
    }
}

void func_800FAA4C_ovl46(UnkObj* e) {
    u8* p;
    u8* q;

    if (--e->unk6 == 0) {
        q = D_8009A1F8.u;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        e->unk6 = 0x3C;
    }
    p = D_8009A1F8.u;
    p[0xF4] = 1;
    p[0x4C] = 1;
    *(s32*)(p + 8) += -0xCCCCC;
    if (*(s32*)(p + 8) <= 0x2C00000) {
        *(s32*)(p + 8) = 0x2C00000;
        func_8002385C(0x1F, 0xFF, 0);
        e->unk4 = 0;
        e->unk1++;
    }
}

#include "shared/func_800FAB0C_ovl46.c"
