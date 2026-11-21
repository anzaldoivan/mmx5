#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800D1C00[];

void func_800FDD58_ovl04(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        if (*(s8*)(obj + 0x5) == 2) {
            set_animation(obj, 0);
        }
        obj[0x6] = 0;
        D_800D1C00[0x28] &= obj[0x95];
        D_800D1C00[0x29] &= obj[0x96];
    }
}

extern u8* func_8002C938();

void func_800FDDDC_ovl04(u8* arg0) {
    u8* o;

    if (++arg0[0x8D] == 4) {
        o = func_8002C938();
        if (o != 0) {
            o[1] = 3;
            o[2] = 0x11;
            o[0] = 0x41;
            *(s16*)(o + 0xA) = *(u16*)(arg0 + 0xA) - 0x30;
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
        }
    }
    if (arg0[0x8D] == 8) {
        o = func_8002C938();
        if (o != 0) {
            o[1] = 3;
            o[2] = 0x10;
            o[0] = 0x41;
            *(s16*)(o + 0xA) = *(u16*)(arg0 + 0xA) - 0x30;
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
        }
    }
    if (arg0[0x8D] >= 0xC) {
        arg0[6]--;
    }
}

/* W40 draft: after 61 ticks, flag D_800D1C2A[1] and spawn two 0x41/0xB children (rockx5 ovl04). */

extern u8 D_800D1C2A;

void func_800FDED4_ovl04(u8* o) {
    u8* c;

    animate_object(o);
    if (++o[0x8D] >= 0x3D) {
        (&D_800D1C2A)[1] = 2;
        c = func_8002D1A4();
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 0xB;
            *(u8**)(c + 0x7C) = o;
            c[2] = 1;
        }
        c = func_8002D1A4();
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 0xB;
            *(u8**)(c + 0x7C) = o;
            c[2] = 3;
        }
        o[6]++;
    }
}

/* W47 draft: unless D_800D1C2A[1] or o[0x46] is set, set state 0x3A (o[5]==2) or 0x3C and advance o[6] (rockx5 ovl04). */

extern u8 D_800D1C2A;

void func_800FDF84_ovl04(u8* o) {
    animate_object(o);
    if (((s8*)&D_800D1C2A)[1] == 0 && ((s8*)o)[0x46] == 0) {
        if ((s8)o[5] == 2) {
            set_animation(o, 0x3A);
        } else {
            set_animation(o, 0x3C);
        }
        o[6]++;
    }
}

extern u8 D_800D1C00[];

void func_800FE004_ovl04(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[0x6] = 0;
        D_800D1C00[0x28] &= obj[0x95];
        D_800D1C00[0x29] &= obj[0x96];
    }
}
