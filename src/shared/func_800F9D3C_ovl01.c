#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9D3C_ovl01(Ent657C* e) {
    g_Player[0xCA] = 0;
    func_8003D29C(0x14, g_Player[0x15]);
    e->unk5 = 1;
    e->unk42 &= 0x7FFF;
    set_animation(e, 3);
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    func_8002D9EC(e, 0x60, 0x60);
}

extern u8* alloc_class3_slot(void);

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))

void func_800F9DB8_ovl01(u8* obj) {
    u8* child;
    s16 r;
    s32 v;

    if (--S16(obj, 0x7C) == 0) {
        obj[5] = 2;
        child = alloc_class3_slot();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            U16(child, 0xA) = U16(obj, 0xA);
            U16(child, 0xE) = U16(obj, 0xE);
            *(u8**)(obj + 0x8C) = child;
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
