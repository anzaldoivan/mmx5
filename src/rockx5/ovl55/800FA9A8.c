#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/system.h"
#include "mmx5/ovl55.h"

extern void func_80013288(s32);

void func_800FA9A8_ovl55(u8* e) {
    u8* p = D_8009A1F8.u;

    p[0x3] = 0;
    p[0x57] = 1;
    *(s16*)(p + 0x5E) = 0;
    *(s16*)(p + 0x62) = 0;
    p[0xA0] = 1;
    p[0xAB] = 1;
    *(s16*)(p + 0xB2) = 0;
    *(s16*)(p + 0xB6) = 0;
    p[0xF4] = 1;
    func_80013288(8);
    e[1]++;
}

extern void func_800177B0(s32, s32);
extern signed char D_8009A424;

void func_800FAA0C_ovl55(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[1]++;
        func_800177B0(0x16, 0x7F);
        *(s16*)(arg0 + 4) = 0;
    }
}

#define func_800FA190_ovl42 func_800FAA54_ovl55
#include "shared/func_800FA190_ovl42.c"
#undef func_800FA190_ovl42

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FB9D8_ovl55[];

void func_800FAA84_ovl55(Ovl45State* e) {
    if (++e->unk4 >= 20) {
        func_80028B18(1, 0xD0, 0x10, D_800FB9D8_ovl55);
        D_8009A298.u = 1;
        func_8002385C(0x59, 0xFF, 0);
        e->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_80091C44;
extern u8 D_800FB9E0_ovl55[];

void func_800FAB08_ovl55(Ovl45State* e) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0x10, 0x10, D_800FB9E0_ovl55);
        D_8009A298.u = 1;
        e->unk4 = 0;
        func_8002385C(0x5A, 0xFF, 0);
        e->unk1++;
    }
}

extern u8 D_80091C44;
extern u8* D_800FBAA8_ovl55;
extern u8* D_800FD2B8_ovl55;

void func_800FAB7C_ovl55(u8* e) {
    u8* p;

    if (D_80091C44 == 0) {
        D_800FBAA8_ovl55 = ((u8 * (*)()) alloc_class6_slot)();
        if (D_800FBAA8_ovl55 != 0) {
            D_800FBAA8_ovl55[0] = 1;
            D_800FBAA8_ovl55[1] = 10;
            D_800FBAA8_ovl55[0x36] = 1;
            D_800FBAA8_ovl55[2] = 0;
            D_800FD2B8_ovl55 = D_800FBAA8_ovl55;
        }
        p = D_8009A1F8.u;
        p[3] = 0;
        *(s16*)(p + 0xA) = 0;
        *(s16*)(p + 0xE) = 0;
        p[0x4C] = 1;
        *(s16*)(e + 4) = 0;
        *(s16*)(e + 6) = 0;
        e[1]++;
        play_sound(2, 0x52, 0);
    }
}

void func_800FAC34_ovl55(u8* arg0) {
    u8* p;
    u8* q;

    if (++*(u16*)(arg0 + 4) & 1) {
        p = D_8009A1F8.u;
        *(s16*)(p + 0xA) = random_byte() % 9;
        *(s16*)(p + 0xE) = random_byte() % 5;
    } else {
        u8* r = D_8009A1F8.u;
        *(s16*)(r + 0xA) = 0;
        *(s16*)(r + 0xE) = 0;
    }
    q = D_8009A1F8.u;
    q[0x4C] = 1;
    if (*(s16*)(arg0 + 4) >= 0xF1) {
        *(s16*)(q + 0xA) = 0;
        *(s16*)(q + 0xE) = 0;
        *(s16*)(arg0 + 4) = 0;
        *(s16*)(arg0 + 6) = 0;
        arg0[1]++;
    }
}

extern u8* D_800FD2B8_ovl55;

void func_800FAD38_ovl55(u8* a0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    ((u8*)p)[3] = 0;
    load_palette(0x40, D_800FC6B8_ovl55, 0x10);
    load_palette(0x100, D_800FBEB8_ovl55, 0x10);
    load_palette(0x50, D_800FC2B8_ovl55, 0x10);
    p->unk62 = 0x100;
    p->unkA0 = 1;
    p->unk5E = 0;
    D_800FD2B8_ovl55[4] = 2;
    a0[1]++;
}

extern u8 D_800FB9E8_ovl55[];

void func_800FADD8_ovl55(u8* a0) {
    if (++*(s16*)(a0 + 4) >= 20) {
        func_80028B18(1, 0x20, 0x160, D_800FB9E8_ovl55);
        D_8009A298.u = 1;
        a0[1]++;
        func_8002385C(0x5B, 0xFF, 0);
    }
}

extern u8 D_80091C44;

void func_800FAE58_ovl55(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.t.unk57 = 0;
        *(s16*)&D_8009A1F8.t.padA1[0xB2 - 0xA1] = 0;
        D_8009A1F8.t.unkB6 = 0x100;
        D_8009A1F8.t.unkF4 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern void func_8002C1C8(void);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DDC;

void func_800FAEA4_ovl55(Ovl45State* e) {
    if (++e->unk4 == 40) {
        play_sound(2, 0x57, 0);
    }
    if (e->unk4 >= 61) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DDC = 0xFFFF;
        e->unk1++;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800FAF38_ovl55(u8* arg0) {
    if (D_8009A420_as_s32 % 3 == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE >= 0x1F) {
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
#undef D_8009A420_as_s32

void func_800FAFC4_ovl55(u8* p) {
    if (*(s16*)(p + 4) < 0x5A) {
        (*(s16*)(p + 4))++;
    } else {
        func_8002385C(0x5C, 0xFF, 0);
        p[1]++;
    }
}

extern void func_8002C1C8(void);
extern s32 func_80017E54(s32);
extern u8 D_80091C44;

void func_800FB020_ovl55(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        p[0x3] = 0;
        p[0x57] = 0;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x300;
        p[0xF4] = 1;
        func_8002C1C8();
        arg0[1]++;
        func_80017E54(3);
    }
}

void func_800FB088_ovl55(u8* a0) {
    u8* p = D_8009A1F8.u;

    p[0xF4] = 1;
    *(s32*)(p + 0xB0) += 0x10000;
    if (*(s32*)(p + 0xB0) > 0xBFFFFF) {
        *(s32*)(p + 0xB0) = 0xC00000;
        a0[1]++;
        *(s16*)(a0 + 4) = 0;
        func_8002385C(0x5D, 0xFF, 0);
    }
}

#define func_800FA954_ovl52 func_800FB0F8_ovl55
#include "shared/func_800FA954_ovl52.c"
#undef func_800FA954_ovl52

extern u8 D_800D1F3C;
extern u8* D_800FD2B8_ovl55;

void func_800FB140_ovl55(u8* e) {
    u8* p;
    u8* q;

    if (D_800D1F3C == 2) {
        p = D_8009A1F8.u;
        p[3] = 0;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0x80;
        p[0xA0] = 1;
        p[0xAB] = 0;
        q = alloc_class6_slot();
        if (q != 0) {
            q[0] = 1;
            q[1] = 10;
            q[0x36] = 0x11;
            q[2] = 0;
            D_800FD2B8_ovl55 = q;
        }
        e[1]++;
    }
}

extern u8* D_800FD2B8_ovl55;

void func_800FB1E0_ovl55(u8* arg0) {
    D_8009A1F8.t99C.unkA0 = 1;
    D_8009A1F8.t99C.unk60.val += -0x44444;
    if (D_8009A1F8.t99C.unk60.val <= 0) {
        D_8009A1F8.t99C.unk60.i.hi = 0;
        D_800FD2B8_ovl55[0x36] = 0x21;
        func_8002385C(0x48, 0xFF, 0);
        arg0[1]++;
    }
}

extern u8 D_80091C44;
extern u8 D_800FD0B8_ovl55[];

extern void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FB25C_ovl55(u8* e) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x200;
        p[0xA0] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x200;
        p[0xF4] = 1;
        *(s16*)(e + 4) = 0;
        func_8002C3CC(D_800FD0B8_ovl55, D_800FCEB8_ovl55, 0x100, 0x78, 0x78);
        ((s32(*)())load_palette)(0xA0, D_800FD0B8_ovl55, 0x10);
        e[1]++;
    }
}

extern u8 D_800FCCB8_ovl55[];
extern s32 D_800FD2BC_ovl55;

extern void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800FB30C_ovl55(u8* e) {
    *(s16*)(e + 4) = 0;
    func_8002C3CC(D_800FCCB8_ovl55, D_800FCAB8_ovl55, 0x100, 0, 0x78);
    load_palette(0x90, D_800FCCB8_ovl55, 0x10);
    D_800FD2BC_ovl55 = 0;
    play_sound(2, 0x53, 0);
    e[1]++;
}

extern u8 D_80091C44;

void func_800FB394_ovl55(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.u[0x4C] = 1;
        *(s32*)(D_8009A1F8.u + 8) += -0xB3333;
        if (*(s32*)(D_8009A1F8.u + 8) <= 0) {
            *(s32*)(D_8009A1F8.u + 8) = 0;
            arg0->unk4 = 0;
            arg0->unk1++;
            func_8002385C(0x4B, 0xFF, 0);
        }
    }
}

extern u8 D_80091C44;

void func_800FB408_ovl55(UnkObj* obj) {
    UnkSpawn* s;

    if (D_80091C44 == 0) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = 0;
            s->unkA = 0x100;
            s->unkE = 0x7C;
            s->unk54 = 12;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}

extern s32 D_800E92F8;

void func_800FB484_ovl55(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x4C, 0xFF, 0);
        D_800E92F8 = 1;
        arg0->unk1++;
    }
}

extern u8 D_80091C44;
extern s32 D_800FD2BC_ovl55;

void func_800FB4DC_ovl55(u8* e) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        p[0x57] = 1;
        p[0xA0] = 1;
        p[0xAB] = 1;
        p[0xF4] = 1;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0x200;
        *(s16*)(p + 0xB6) = 0x200;
        p[3] = 0;
        *(s16*)(p + 0xB2) = 0;
        D_800FD2BC_ovl55 = 0;
        play_sound(2, 0x53, 0);
        *(s16*)(e + 4) = 0;
        e[1]++;
    }
}

#define D_800FB964_ovl52 D_800FD2BC_ovl55

#define func_800FAC54_ovl52 func_800FB564_ovl55
#include "shared/func_800FAC54_ovl52.c"
#undef func_800FAC54_ovl52
#undef D_800FB964_ovl52

void func_800FB60C_ovl55(u8* e) {
    u8* p;
    s32 v;

    p = D_8009A1F8.u;
    p[0xA0] = 1;
    v = *(s32*)(p + 0x5C) + 0x100000;
    *(s32*)(p + 0x5C) = v;
    if (v > 0x33FFFFF) {
        *(s32*)(p + 0x5C) = 0x3400000;
        *(s16*)(e + 4) = 0;
        e[1]++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FB9F0_ovl55[];

void func_800FB65C_ovl55(Ovl45State* e) {
    if (++e->unk4 >= 0x3C) {
        func_80028B18(1, 0x340, 0x240, D_800FB9F0_ovl55);
        D_8009A298.u = 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

#define D_800FB0D8_ovl52 D_800FB9F8_ovl55

#define func_800FADE0_ovl52 func_800FB6D0_ovl55
#include "shared/func_800FADE0_ovl52.c"
#undef func_800FADE0_ovl52
#undef D_800FB0D8_ovl52

#define D_800FB0D8_ovl52 D_800FBA00_ovl55

#define func_800FADE0_ovl52 func_800FB744_ovl55
#include "shared/func_800FADE0_ovl52.c"
#undef func_800FADE0_ovl52
#undef D_800FB0D8_ovl52

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FBA08_ovl55[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD0[];

void func_800FB7B8_ovl55(Ovl45State* e) {
    if (++e->unk4 >= 8) {
        func_80028B18(1, 0x340, 0x240, D_800FBA08_ovl55);
        D_8009A298.u = 1;
        e->unk4 = 0;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        D_80093DD0[6] = 0xFFFF0000;
        D_80093DD0[9] = 0xFFFF;
        func_8002385C(0x4D, 0xFF, 0);
        e->unk1++;
    }
}

#define func_800FAF7C_ovl52 func_800FB874_ovl55
#include "shared/func_800FAF7C_ovl52.c"
#undef func_800FAF7C_ovl52

#define func_800FA2C0_ovl43 func_800FB8FC_ovl55
#include "shared/func_800FA2C0_ovl43.c"
#undef func_800FA2C0_ovl43

extern u8 D_800D1F3C;
extern signed char D_8009A424;

void func_800FB948_ovl55(u8* arg0) {
    s32 i;
    u8* p;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8.u[0x3] = 0;
        D_8009A1F8.u[0x57] = 0;
        D_8009A1F8.u[0xAB] = 0;
        func_8002C50C();
        i = 15;
        p = arg0 + 0x35;
        for (; i >= 0; i--) {
            *p-- = 0;
        }
        arg0[0xCB] = 0x10;
        arg0[0x79] = 5;
        arg0[0] = 0x15;
    }
}
