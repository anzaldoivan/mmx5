#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void func_800EF5A0_ovl11(u8* arg0);
extern void func_800EFC54_ovl11(s32);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800EF890_ovl11(u8* p) {
    if (p[0x19] != 0) {
        p[0x19]--;
        return;
    }
    if (--p[0x1A] == 0) {
        func_800EF5A0_ovl11(p);
        p[0x1A] = 7;
    }
    p[0x18]++;
    if ((u8)(p[0x18] % 5) == 0) {
        D_800D50DE -= 2;
        D_8009A42E -= 0x40;
        D_80093E68 -= 0x800;
        if (D_800D50DE == 0) {
            p[4]++;
            func_800EFC54_ovl11(0);
        }
    }
}

extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 func_8002CE20(s32, s32);

void func_800EF978_ovl11(u8* arg0) {
    D_800D50DC = 0;
    D_8009A42C = 0;
    D_80093E66 = 0;
    func_8002C218();
    arg0[0x18] = 0x3C;
    arg0[0x19] = 4;
    arg0[0x1E] = 0;
    arg0[0x1A] = 3;
    arg0[0x1B] = 0x78;
    func_8002CE20(2, 1);
    arg0[7] = 10;
    arg0[4]++;
}

void func_800EF5A0_ovl11(u8* arg0);
extern u8 D_8009A1F8[];
extern void* D_800F96B0_ovl11[];

void func_800EF9F8_ovl11(u8* o) {
    u8* p;
    u8* b;

    if (o[0x1F] != 0) {
        p = o + 0x14;
        ((void (*)(u8*))D_800F96B0_ovl11[o[0x1E]])(o);
    } else {
        u8* q = o + 0x14;
        q[4] = o[0x18] - 1;
        p = q;
        if (q[4] == 0) {
            o[0x1F] = 1;
        }
    }
    b = D_8009A1F8;
    *(s16*)(o + 0xA) = *(u16*)(b + 0xA) + 0xA0;
    *(s16*)(o + 0xE) = *(u16*)(b + 0xE) + 0x80;
    p[6] = o[0x1A] - 1;
    if (p[6] == 0) {
        func_800EF5A0_ovl11(o);
        o[0x1A] = 7;
    }
    if (*(s8*)(o + 7) == 0) {
        o[7] = 10;
    }
    o[7] = o[7] - 1;
    p[7] = o[0x1B] - 1;
    if (p[7] == 0) {
        o[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800EFB14_ovl11
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
