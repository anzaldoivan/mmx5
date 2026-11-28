#include "types.h"
#include "mmx5/globals.h"

#define func_800FA078_ovl40 func_800FA4D8_ovl57
#include "shared/func_800FA078_ovl40.c"
#undef func_800FA078_ovl40

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800FA544_ovl57(Actor50* a) {
    if (D_8009A424 == 0) {
        func_800177B0(0x13, 0x7F);
        a->step++;
    }
}

extern u8 D_800D1F3C;

void func_800FA58C_ovl57(Ovl45State* arg0) {
    if (D_800D1F3C == 2) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FA5BC_ovl57(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    p->unkF4 = 1;
    *(s32*)&p->padA1[0xB0 - 0xA1] += 0x19999;
    arg0->unk4++;
    if (arg0->unk4 >= 0x78) {
        func_8002385C(0x6D, 0xFF, 0);
        *(s16*)&p->padA1[0xB2 - 0xA1] = 0xC0;
        p->unkF4 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DDC;

void func_800FA65C_ovl57(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        D_80093DDC = 0xFFFF0000;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        p = D_8009A1F8.u;
        p[0x3] = 0;
        p[0x57] = 0;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x100;
        p[0xF4] = 1;
        arg0[1]++;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern s32 func_80017E54(s32);

s32 func_800FA714_ovl57(u8* arg0) {
    s32 r;

    if (!(D_8009A420_as_s32 & 1)) {
        D_80093E68 -= 0x400;
        D_800D50DE--;
        D_8009A42E -= 0x20;
    }
    if (D_80093E68 == 0) {
        r = func_80017E54(3);
        arg0[1]++;
        return r;
    }
}
#undef D_8009A420_as_s32

extern u8 D_800D1F3C;
extern void func_800177B0(s32, s32);

void func_800FA79C_ovl57(Actor50* a) {
    if (D_800D1F3C == 0) {
        func_800177B0(0x1C, 0x7F);
        a->step++;
    }
}

extern u8 D_800D1F3C;

void func_800FA7E4_ovl57(u8* arg0) {
    if (D_800D1F3C == 2) {
        func_8002385C(0x6F, 0xFF, 0);
        arg0[1]++;
    }
}

extern u8 D_80091C44;

void func_800FA834_ovl57(UnkObj* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        p[0x57] = 1;
        *(s16*)(p + 0x62) = 0x100;
        *(s16*)(p + 0x5E) = 0;
        p[0xA0] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x200;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FA890_ovl57(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 0x14) {
        arg0[1]++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_800FAB84_ovl57[];

void func_800FA8CC_ovl57(Ovl45State* e) {
    func_80028B18(1, 0x70, 0x110, D_800FAB84_ovl57);
    D_8009A298.u = 1;
    func_8002385C(0x70, 0xFF, 0);
    e->unk1++;
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_80091C44;
extern u8 D_800FAB8C_ovl57[];

void func_800FA92C_ovl57(Ovl45State* e) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0xD0, 0x140, D_800FAB8C_ovl57);
        D_8009A298.u = 1;
        func_8002385C(0x71, 0xFF, 0);
        e->unk1++;
    }
}

extern u8 D_80091C44;
extern u8 D_800FAB94_ovl57[];

void func_800FA99C_ovl57(u8* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0x10, 0x140, D_800FAB94_ovl57);
        D_8009A1F8.u[0xA0] = 1;
        *(s16*)(D_8009A1F8.u + 0xB2) = 0;
        *(s16*)(D_8009A1F8.u + 0xB6) = 0x200;
        D_8009A1F8.u[0xF4] = 1;
        func_8002385C(0x72, 0xFF, 0);
        arg0[1]++;
    }
}

extern u8 D_80091C44;

void func_800FAA20_ovl57(UnkObj* arg0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        p = &D_8009A1F8.t;
        arg0->unk1++;
        arg0->unk4 = 0;
        *(s16*)&p->padA1[0xB2 - 0xA1] = 0;
        p->unkB6 = 0x100;
        p->unkF4 = 1;
        p->pad0[3] = 0;
        p->unk57 = 0;
        func_8002385C(0x73, 0xFF, 0);
    }
}

extern u8 D_80091C44;
extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);

void func_800FAA88_ovl57(u8* o) {
    if (D_80091C44 == 0) {
        if (++*(s16*)(o + 4) >= 0x3D) {
            func_800132F8(8);
            func_80017E54(3);
            o[1]++;
        }
    }
}

#include "shared/func_800FAAF8_ovl57.c"
