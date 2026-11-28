#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);

void func_800EEC44_ovl21(u8* arg0) {
    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    arg0[1]++;
}

#include "shared/func_800EEC94_ovl21.c"

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800EECC8_ovl21(Ovl45State* s) {
    if (D_8009A424 == 0) {
        s->unk4 = 0;
        s->unk1++;
        func_800177B0(0x18, 0x7F);
    }
}

extern u8 D_800D1F3C;

void func_800EED08_ovl21(u8* a0) {
    u8* p;

    if (D_800D1F3C == 2) {
        p = D_8009A1F8.u;
        *(s32*)(p + 0xC) += -0x88888;
        p[0x4C] = 1;
        *(s16*)(a0 + 4) += 1;
        if (*(s16*)(a0 + 4) >= 30) {
            *(s32*)(p + 0x8) = 0x800000;
            *(s32*)(p + 0xC) = 0x1000000;
            *(s32*)(p + 0x5C) = 0;
            *(s32*)(p + 0x60) = 0x1000000;
            p[0x4C] = 1;
            p[0xA0] = 1;
            *(s16*)(a0 + 4) = 0;
            a0[1]++;
        }
    }
}

void func_800EED98_ovl21(u8* a0) {
    u8* p;

    p = D_8009A1F8.u;
    *(s32*)(p + 0x8) += -0x40000;
    *(s32*)(p + 0xC) += -0x80000;
    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 30) {
        p[3] = 0;
        *(s16*)(a0 + 4) = 0;
        a0[1]++;
    }
}

void func_800EEE00_ovl21(u8* a0) {
    u8* p;

    p = D_8009A1F8.u;
    *(s32*)(p + 0x5C) += 0x2AAAA;
    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 60) {
        *(s32*)(p + 0x5C) = 0;
        *(s32*)(p + 0x60) = 0x2000000;
        p[0xA0] = 1;
        *(s16*)(a0 + 4) = 0;
        *(s16*)(a0 + 6) = 0;
        a0[1]++;
    }
}

void func_800EEE6C_ovl21(u8* arg0) {
    if (*(s16*)(arg0 + 6) < 0x50) {
        *(s16*)(arg0 + 6) += 1;
        return;
    }
    arg0[1] += 1;
}

void func_800EEE9C_ovl21(u8* a0) {
    s32 i;
    u8* p;

    for (i = 0; i < 4; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x30;
            p[2] = i;
            *(u8**)(p + 0x50) = a0;
        }
    }
    *(s16*)(a0 + 4) = 1;
    a0[1]++;
}

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800EEF20_ovl21(u8* arg) {
    if (*(s16*)(arg + 4) == 0) {
        ((s32(*)())func_8002C218)();
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        D_800C9310.b |= 1;
        *(s16*)(arg + 4) = 0;
        arg[1]++;
    }
}

extern void func_8002C1C8(void);

void func_800EEFB4_ovl21(u8* o) {
    if (++*(s16*)(o + 4) >= 3) {
        func_8002C1C8();
        *(s16*)(o + 4) = 0;
        o[1]++;
    }
}

/* e: Ovl45State, same shape as this function's accesses */
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800EF010_ovl21(Ovl45State* e) {
    if (++e->unk4 >= 5) {
        ((s32(*)())func_8002C218)();
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        D_800C9310.b |= 1;
        e->unk4 = 0;
        e->unk1++;
    }
}

void func_800EF0B8_ovl21(u8* a0) {
    u8* p;

    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 9) {
        p = D_8009A1F8.u;
        *(s32*)(p + 0x8) = 0x4000000;
        *(s32*)(p + 0xC) = 0;
        p[0x4C] = 1;
        p[3] = 1;
        *(s16*)(a0 + 4) = 0;
        a0[1]++;
    }
}

extern void func_8002C1C8(void);

void func_800EF114_ovl21(u8* a0) {
    u8* p;

    func_8002C1C8();
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x30;
        p[2] = 4;
        *(u8**)(p + 0x50) = a0;
    }
    a0[1]++;
}

void func_800EF170_ovl21(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 0x78) {
        arg0[1]++;
    }
}

#define func_80013288 func_800132F8

#define func_800EEC94_ovl21 func_800EF1AC_ovl21
#include "shared/func_800EEC94_ovl21.c"
#undef func_800EEC94_ovl21
