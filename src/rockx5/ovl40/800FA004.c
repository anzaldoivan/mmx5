#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_800FA658_ovl40[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA004_ovl40(u8* arg0) {
    D_800FA658_ovl40[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

#include "shared/func_800FA078_ovl40.c"

#include "shared/func_800FA0E4_ovl40.c"

#include "shared/func_800FA128_ovl40.c"

void func_800FA154_ovl40(Ovl45State* s) {
    D_8009A1F8.tB0.unkB0 += 0x10000;
    if (++s->unk4 >= 0xC0) {
        func_8002385C(0, 0xFF, 0);
        ((s16*)&D_8009A1F8.tB0.unkB0)[1] = 0xC0;
        s->unk4 = 0;
        s->unk1++;
    }
}

extern void func_8002C1C8(void);

extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD8;

void func_800FA1DC_ovl40(u8* arg0) {
    if (D_80091C44 == 0) {
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        D_80093DD8 = 0xFFFF0000;
        arg0[1]++;
    }
}

extern void func_8002C1C8(void);

void func_800FA244_ovl40(u8* arg0) {
    u8* p;
    u8* o;

    D_800D50DE++;
    D_8009A42E += 0x20;
    D_80093E68 += 0x400;
    if (D_800D50DE == 0x1F) {
        p = D_8009A1F8.u;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x100;
        p[0xF4] = 1;
        func_8002C1C8();
        o = alloc_class6_slot();
        if (o != 0) {
            o[0] = 1;
            o[1] = 9;
            o[0x36] = 0x11;
            *(s16*)(o + 0x34) = 0;
            o[2] = 0;
            *(s32*)(o + 0x38) = 0x3C;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}

extern s32 D_800FA688_ovl40;

void func_800FA310_ovl40(Ovl45State* a0) {
    u8* p;

    if (a0->unk4 == 0) {
        func_8002385C(1, 0xFF, 0);
        a0->unk1++;
        p = D_8009A1F8.u;
        D_800FA688_ovl40 = 0x700000;
        a0->unk4 = 0x3C;
        p[0x3] = 0;
        *(s16*)(p + 0x62) = 0;
        *(s16*)(p + 0x5E) = 0x200;
        *(s32*)(p + 0x5C) += 0x700000;
        p[0xA0] = 1;
        p[0x57] = 1;
    }
}
