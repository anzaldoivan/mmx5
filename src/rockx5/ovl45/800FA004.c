#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

extern u8 D_80091C44;
extern s16 D_800FA6CC_ovl45[][2];
extern u8 D_800FA6E0_ovl45[][8];

void func_800FA004_ovl45(u8* arg0) {
    u16 t;

    if (D_80091C44 == 0) {
        t = *(u16*)(arg0 + 4);
        if (!(t & 3)) {
            func_80028B18(1, D_800FA6CC_ovl45[(s16)t / 4][0],
                          D_800FA6CC_ovl45[(s16)t / 4][1],
                          D_800FA6E0_ovl45[(s16)t / 4]);
            D_8009A298.s = 1;
            if (*(s16*)(arg0 + 4) >= 0x10) {
                func_8002385C(0x18, 0xFF, 0);
                *(u16*)(arg0 + 4) = 0;
                arg0[1]++;
                return;
            }
        }
        *(u16*)(arg0 + 4) += 1;
    }
}

extern void (*D_800FA708_ovl45[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA0DC_ovl45(u8* arg0) {
    D_800FA708_ovl45[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

#define func_800FA078_ovl40 func_800FA150_ovl45
#include "shared/func_800FA078_ovl40.c"
#undef func_800FA078_ovl40

#define func_800FA0E4_ovl40 func_800FA1BC_ovl45
#include "shared/func_800FA0E4_ovl40.c"
#undef func_800FA0E4_ovl40

#define func_800FA128_ovl40 func_800FA200_ovl45
#include "shared/func_800FA128_ovl40.c"
#undef func_800FA128_ovl40

extern s32 D_80093DD8;

void func_800FA22C_ovl45(u8* arg0) {
    if (++*(s16*)(arg0 + 4) == 30) {
        play_sound(2, 0x4C, 0);
    }
    if (*(s16*)(arg0 + 4) >= 50) {
        D_80093DD8 = 0xFFFF0000;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

void func_800FA2A4_ovl45(u8* arg0) {
    u16 n;

    if (++*(s16*)(arg0 + 4) >= 4) {
        n = ++D_800D50DE;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        *(s16*)(arg0 + 4) = 0;
        if (n == 0x1F) {
            func_8002385C(0x16, 0xFF, 0);
            arg0[1]++;
        }
    }
}

extern void func_8002C1C8(void);
extern u8 D_80091C44;

void func_800FA344_ovl45(u8* arg0) {
    u8* p;
    u8* b;

    if (D_80091C44 == 0) {
        p = alloc_class6_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 10;
            p[0x36] = 50;
            p[2] = 0;
        }
        b = D_8009A1F8.u;
        *(s16*)(b + 0xB2) = 0;
        *(s16*)(b + 0xB6) = 0x100;
        b[0xF4] = 1;
        func_8002C1C8();
        p = alloc_class6_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 9;
            p[0x36] = 0x11;
            *(s16*)(p + 0x34) = 0x7FFF;
            p[2] = 0;
            *(s32*)(p + 0x38) = 30;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}

extern void func_800177B0(s32, s32);

void func_800FA410_ovl45(Ovl45State* arg0) {
    u8* p;

    if (arg0->unk4 == 0) {
        func_800177B0(0x1A, 0x7F);
        play_sound(2, 0x4D, 0);
        func_8002385C(0x17, 0xFF, 0);
        p = D_8009A1F8.u;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0;
        p[0x57] = 1;
        p[0xA0] = 1;
        arg0->unk1++;
    }
}

#define func_800FA190_ovl42 func_800FA494_ovl45
#include "shared/func_800FA190_ovl42.c"
#undef func_800FA190_ovl42

#define func_800FA2B8_ovl47 func_800FA4C4_ovl45
#include "shared/func_800FA2B8_ovl47.c"
#undef func_800FA2B8_ovl47

void func_800FA4F0_ovl45(Ovl45State* s) {
    u8* p = D_8009A1F8.u;
    UnkSpawn* c;

    *(s32*)(p + 0x60) += 0xCCCCC;
    *(s32*)(p + 0xB4) += 0xCCCCC;
    if (++s->unk4 >= 20) {
        *(s16*)(p + 0x62) = 0x100;
        *(s16*)(p + 0xB6) = 0x200;
        c = func_8002D27C();
        if (c != 0) {
            c->unk0 = 0x41;
            c->unk1 = 0x1D;
            c->unk2 = 0;
            c->unkA = 0x40;
            c->unkE = 0x44;
            c->unk54 = 5;
        }
        s->unk4 = 1;
        s->unk1++;
    }
}

void func_800FA5B4_ovl45(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x19, 0xFF, 0);
        arg0->unk1++;
    }
}

#define func_800FA2C0_ovl43 func_800FA600_ovl45
#include "shared/func_800FA2C0_ovl43.c"
#undef func_800FA2C0_ovl43

#define func_800FA30C_ovl43 func_800FA64C_ovl45
#include "shared/func_800FA30C_ovl43.c"
#undef func_800FA30C_ovl43
