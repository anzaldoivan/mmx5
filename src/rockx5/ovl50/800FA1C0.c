#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/ovl50.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/system.h"

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern Blk200 D_800FB488_ovl50;
extern Blk200 D_800FB888_ovl50;

void func_800FA1C0_ovl50(u8* arg0) {
    Blk200* s;

    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    s = (Blk200*)(D_1F800028 + 0x1800);
    D_8009A1F8.u[0x3] = 0;
    D_8009A1F8.u[0x57] = 0;
    D_800FB488_ovl50 = *s;
    s = (Blk200*)(D_1F800028 + 0x2200);
    D_800FB888_ovl50 = *s;
    arg0[1]++;
}

#define func_800EEC94_ovl21 func_800FA38C_ovl50
#include "shared/func_800EEC94_ovl21.c"
#undef func_800EEC94_ovl21

#include "shared/func_800FA3C0_ovl50.c"

#include "shared/func_800FA408_ovl50.c"

#include "shared/func_800FA458_ovl50.c"

#include "shared/func_800FA4F8_ovl50.c"

#define func_800FA498_ovl47 func_800FA584_ovl50
#include "shared/func_800FA498_ovl47.c"
#undef func_800FA498_ovl47

#include "shared/func_800FA5B0_ovl50.c"

#include "shared/func_800FA66C_ovl50.c"

#include "shared/func_800FA6B8_ovl50.c"

#include "shared/func_800FA734_ovl50.c"

#include "shared/func_800FA780_ovl50.c"

#include "shared/func_800FA820_ovl50.c"

#include "shared/func_800FA858_ovl50.c"

#include "shared/func_800FA8E0_ovl50.c"

#include "shared/func_800FA944_ovl50.c"

#include "shared/func_800FA990_ovl50.c"

extern s32 func_80017E54(s32);

void func_800FAA38_ovl50(u8* arg0) {
    u8* p;
    u8* q;
    u8* e;
    s32 t;
    s32 r;

    t = *(u16*)(arg0 + 6) + 1;
    *(u16*)(arg0 + 6) = t;
    if (t & 1) {
        r = random_byte();
        p = D_8009A1F8.u;
        *(s16*)(p + 0xB6) = r % 5 + 0x104;
    } else {
        e = D_8009A1F8.u;
        *(s16*)(e + 0xB6) = 0x100;
    }
    if (*(s16*)(arg0 + 4) < 0x1E) {
        *(s16*)(arg0 + 4) = *(s16*)(arg0 + 4) + 1;
        return;
    }
    play_sound(2, 0x6C, 0);
    play_sound(2, 0x51, 0);
    q = D_8009A1F8.u;
    *(s32*)(q + 0x5C) = 0x02000000;
    *(s32*)(q + 0x60) = 0x01800000;
    q[0xA0] = 1;
    q[0x57] = 1;
    *(s16*)(arg0 + 4) = 0;
    func_80017E54(3);
    arg0[1]++;
}

#define D_80091C44 D_800D1F3C

#define func_800FA498_ovl47 func_800FAB4C_ovl50
#include "shared/func_800FA498_ovl47.c"
#undef func_800FA498_ovl47
#undef D_80091C44

extern u8 D_80091C44;

void func_800FAB78_ovl50(u8* arg0) {
    if (D_80091C44 == 0) {
        play_sound(2, 0x6C, 0);
        play_sound(2, 0x4E, 0);
        arg0[1]++;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800FABD4_ovl50(u8* arg0) {
    if (D_8009A420_as_s32 & 1) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE == 0x1F) {
        func_8002385C(0x3B, 0xFF, 0);
        arg0[1]++;
    }
}
#undef D_8009A420_as_s32

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FAC60_ovl50(u8* arg0) {
    u8* p;
    u8* o;

    if (D_80091C44 == 0) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        p = D_8009A1F8.u;
        *(s32*)(p + 0xB4) = 0x02000000;
        p[3] = 0;
        p[0x57] = 0;
        p[0xF4] = 1;
        ((s32*)p)[0x2C] = 0;
        D_800FBC88_ovl50[0x36] = 0x32;
        o = alloc_class6_slot();
        if (o != 0) {
            o[0] = 1;
            o[1] = 9;
            o[0x36] = 0x11;
            *(s16*)(o + 0x34) = 0x7FFF;
            o[2] = 2;
            *(s32*)(o + 0x38) = 0x1E;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}

void func_800FAD30_ovl50(UnkObj* arg0) {
    u8* p;

    if (arg0->unk4 == 0) {
        p = D_8009A1F8.u;
        p[3] = 0;
        *(s32*)(p + 0x5C) = 0;
        *(s32*)(p + 0x60) = 0;
        p[0xA0] = 1;
        p[0x57] = 1;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk1++;
        play_sound(2, 0x4D, 0);
    }
}

void func_800FAD9C_ovl50(u8* arg0) {
    u8* p;

    if (*(s16*)(arg0 + 6) < 90) {
        (*(s16*)(arg0 + 6))++;
        return;
    }
    p = D_8009A1F8.u;
    *(s32*)(p + 0xB4) += 0xCCCCC;
    (*(s16*)(arg0 + 4))++;
    if (*(s16*)(arg0 + 4) >= 20) {
        *(s32*)(p + 0xB4) = 0x3000000;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

extern u8 D_800FB3D8_ovl50[];

void func_800FAE18_ovl50(Actor50* arg0) {
    func_80028B18(1, D_800FB3C8_ovl50[0], D_800FB3C8_ovl50[1],
                  D_800FB3D8_ovl50);
    D_8009A298.u = 1;
    func_8002385C(0x3C, 0xFF, 0);
    arg0->step++;
}

extern u8 D_80091C44;
extern u8 D_800FB3E0_ovl50[];

void func_800FAE80_ovl50(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, D_800FB3C8_ovl50[2], D_800FB3C8_ovl50[3],
                      D_800FB3E0_ovl50);
        D_8009A298.u = 1;
        func_8002385C(0x3D, 0xFF, 0);
        arg0->step++;
    }
}

extern u8 D_80091C44;
extern u8 D_800FB3E8_ovl50[];

void func_800FAEF8_ovl50(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, D_800FB3C8_ovl50[4], D_800FB3C8_ovl50[5],
                      D_800FB3E8_ovl50);
        D_8009A298.u = 1;
        func_8002385C(0x3E, 0xFF, 0);
        arg0->step++;
    }
}

extern u8 D_80091C44;
extern u8 D_800FB3F0_ovl50[];

void func_800FAF70_ovl50(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, D_800FB3C8_ovl50[6], D_800FB3C8_ovl50[7],
                      D_800FB3F0_ovl50);
        D_8009A298.u = 1;
        func_8002385C(0x3F, 0xFF, 0);
        arg0->step++;
    }
}

extern u8 D_80091C44;

void func_800FAFE8_ovl50(u8* a0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        p = &D_8009A1F8.t;
        p->pad0[3] = 0;
        p->unk57 = 0;
        *(u16*)(p->padA1 + 0x11) = 0x200;
        p->unkB6 = 0x400;
        p->padA1[0xA] = 1;
        p->unkF4 = 1;
        *(s16*)(a0 + 4) = 0;
        func_8002385C(0x40, 0xFF, 0);
        play_sound(2, 0x52, 0);
        a0[1]++;
    }
}

extern u8 D_80091C44;
extern s32 D_80093DE8;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FB074_ovl50(u8* arg0) {
    if (*(u16*)(arg0 + 4) & 1) {
        u8* p1 = D_8009A1F8.u;
        *(s16*)(p1 + 0xB6) = random_byte() % 5 + 0x404;
    } else {
        u8* p2 = D_8009A1F8.u;
        *(s16*)(p2 + 0xB6) = 0x400;
    }
    *(u16*)(arg0 + 4) += 1;
    if (D_80091C44 == 0) {
        u8* p = D_8009A1F8.u;
        *(s16*)(p + 0xB6) = 0x400;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
        D_80093DE8 = 0xFFFF;
        *(u16*)(arg0 + 4) = 0;
        arg0[1]++;
        play_sound(2, 0x56, 0);
    }
}

void func_800FB184_ovl50(Ovl45State* arg0) {
    if (++arg0->unk4 >= 2) {
        arg0->unk4 = 0;
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            func_8002385C(0x41, 0xFF, 0);
            arg0->unk1++;
        }
    }
}

extern u8 D_80091C44;

void func_800FB224_ovl50(UnkObj* arg0) {
    D_8009A1F8_t* p;

    if (D_80091C44 == 0) {
        play_sound(2, 0x57, 0);
        p = &D_8009A1F8.t;
        *(s32*)(p->pad58 + 4) = 0x1400000;
        *(s32*)p->pad60 = 0x4000000;
        p->unk57 = 1;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FB294_ovl50(Ovl45State* arg0) {
    D_8009A1F8.w[0x5C / 4] -= 0xAAAAA;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        D_8009A1F8.w[0x5C / 4] = 0;
        arg0->unk4 = 0;
        func_8002385C(0x42, 0xFF, 0);
        arg0->unk1++;
    }
}

#define func_800FA594_ovl40 func_800FB318_ovl50
#include "shared/func_800FA594_ovl40.c"
#undef func_800FA594_ovl40

extern signed char D_8009A424;

void func_800FB35C_ovl50(u8* arg0) {
    s32 i;
    u8* p;

    if (D_8009A424 == 0) {
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
        arg0[0] = 0x15;
    }
}
