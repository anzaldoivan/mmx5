#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"

extern u8 D_8009A0B5;

void func_800FB550_ovl38(u8* obj) {
    func_8003D29C(0x14, D_8009A0B5);
    obj[5]++;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 0x13);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    func_8002D9EC(obj, 0x60, 0x60);
}

extern u8* alloc_class3_slot(void);

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))

void func_800FB5C8_ovl38(u8* obj) {
    u8* child;
    s16 r;
    s32 v;

    if (--S16(obj, 0x7C) == 0) {
        obj[5]++;
        child = alloc_class3_slot();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            U16(child, 0xA) = U16(obj, 0xA);
            U16(child, 0xE) = U16(obj, 0xE);
            *(u8**)(D_1F80004C.bytes + 0x80) = child;
        }
    }
    func_8002D9EC(obj, 0x60, 0x60);
    if (S16(obj, 0x7E)-- != 0) {
        return;
    }
    U16(obj, 0x42) ^= 0x8000;
    S8(obj, 0x61) -= 5;
    if (S8(obj, 0x61) >= 0x1A) {
        S8(obj, 0x61) = 0;
    }
    v = S8(obj, 0x61);
    if (v >= 6) {
        r = v;
    } else {
        r = 5;
    }
    S16(obj, 0x7E) = r;
}
#undef S16
#undef U16
#undef S8

extern u8 D_8009A11A;

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))

void func_800FB6D0_ovl38(u8* obj) {
    u8* child;
    u8* g;

    obj[3] = 0;
    child = *(u8**)(D_1F80004C.bytes + 0x80);
    if (S8(child, 0) != 0) {
        if (S8(child, 7) == 0) {
            if (--S16(obj, 0x7E) == -1) {
                S16(obj, 0x7E) = 5;
                U16(obj, 0x42) ^= 0x8000;
            }
            func_8002D9EC(obj, 0x60, 0x60);
        }
    } else {
        g = g_playthrough_state.u;
        g[0x24] = 0;
        *(s32*)(g + 0x20) = 0;
        D_8009A11A = 0;
        obj[5]++;
    }
}
#undef S16
#undef U16
#undef S8

#define D_800EEBA0_ovl00 func_800FB788_ovl38
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800FB7A8_ovl38
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void (*D_800FD978_ovl38[])(u8*);

void func_800FB7C8_ovl38(u8* a0) {
    if (((s8*)*(u8**)(D_1F80004C.bytes + 0x80))[4] == 2) {
        a0[3] = 0;
        a0[4]++;
    } else {
        D_800FD978_ovl38[(s8)a0[5]](a0);
        if ((s8)a0[2] == 4 && ((s8*)a0)[3] != 0) {
            func_800317B8(a0);
        }
    }
}
