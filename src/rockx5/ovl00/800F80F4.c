#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;

void func_800F80F4_ovl00(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(s16*)(p + 0xA) = a->unkA;
            *(s16*)(p + 0xE) = a->unkE;
            *(u8**)((u8*)a + 0x80) = p;
        }
        a->unk6++;
    }
}

extern s8 D_800D1C2E;

void func_800F8170_ovl00(u8* arg0) {
    u8* p;

    if (**(s8**)(arg0 + 0x80) == 0) {
        if (D_800D1C2E != 0) {
            arg0[6] += 3;
        } else {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0x3A;
                *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
                *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
                arg0[6]++;
            }
        }
    }
}

extern u8 D_800D1C00[];

void func_800F8224_ovl00(u8* a0) {
    u8* p = D_800D1C00;

    if (((s8*)p)[0x28] != 0) {
        func_8002385C(0, 0xFF, p[0x2E]);
        p[0x16] = 1;
        p[0x13] = 1;
        p[0x19] = 1;
        p[0x18] = 1;
        p[0x17] = 1;
        p[0x14] = 1;
        p[0x15] = 1;
        a0[6]++;
    }
}

extern u8 D_80091C44;
extern u8 D_800D1C00[];

void func_800F82A0_ovl00(u8* a0) {
    if (D_80091C44 == 0) {
        u8* p = D_800D1C00;

        a0[6]++;
        p[0x16] = 0;
        p[0x13] = 0;
        p[0x19] = 0;
        p[0x18] = 0;
        p[0x17] = 0;
        p[0x14] = 0;
        p[0x15] = 0;
    }
}

extern void func_8002A600(s32, s32, s32);
extern u8* alloc_class3_slot(void);
extern u8 D_800FB46C_ovl00[];
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_800FB698_ovl00;

void func_800F82E8_ovl00(u8* arg0) {
    u8* p;
    u8* b;

    func_8002A600(0x10, 6, 3);
    b = D_800FB46C_ovl00;
    *(s16*)(b + 0xC) = 0;
    *(s16*)(b + 0x1A) = 0;
    *(s16*)(b + 0x28) = 0;
    *(s16*)(b + 0x36) = 0;
    D_800D50DC = 0;
    D_8009A42C = 0;
    D_80093E66 = 0;
    func_8002C218();
    *(s16*)(arg0 + 0x7E) = 0;
    *(s16*)(arg0 + 0x7C) = 0x10;
    *(s16*)(arg0 + 0xA) -= 0x20;
    D_800FB698_ovl00 = 0;
    arg0[6]++;
    p = alloc_class3_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 3;
        p[2] = 3;
    }
}

extern void func_800F6D58_ovl00(s32);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;

void func_800F839C_ovl00(u8* arg0) {
    func_800F6D58_ovl00(0);
    func_800F6D58_ovl00(1);
    func_800F6D58_ovl00(2);
    func_800F6D58_ovl00(3);
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        D_800D50DC = 0;
        D_8009A42C = 0;
        D_80093E66 = 0;
        ((s32(*)())func_8002C218)();
        arg0[6]++;
    }
}

extern void func_800F6D58_ovl00(s32);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800F8420_ovl00(u8* obj) {
    func_800F6D58_ovl00(0);
    func_800F6D58_ovl00(1);
    func_800F6D58_ovl00(2);
    func_800F6D58_ovl00(3);
    *(s16*)(obj + 0x7C) += 1;
    if ((s16)(*(s16*)(obj + 0x7C) % 5) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            *(s16*)(obj + 0x7C) = 0x78;
            obj[6]++;
        }
    }
}

extern u8 D_8009A1F8[];
extern s32 D_800FB694_ovl00;

void func_800F84F4_ovl00(u8* obj) {
    u8* g;

    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        g = D_8009A1F8;
        g[0x98] = 0;
        g[0xA6] = 0;
        obj[0x90] = 1;
        *(s32*)(obj + 0x24) = 0xFFFF0000;
        *(s32*)(obj + 0x2C) = -0x600;
        D_800FB694_ovl00 = 30000;
        obj[6]++;
    }
}

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800F857C_ovl00(u8* obj) {
    *(s16*)(obj + 0x7C) += 1;
    if ((s16)(*(s16*)(obj + 0x7C) % 5) == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            obj[6]++;
        }
    }
    animate_object(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
