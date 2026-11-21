#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_8009A0B5;

void func_800F6AF0_ovl11(Ent6AF0* e) {
    func_8003D29C(0x14, D_8009A0B5);
    e->unk5 = 1;
    e->unk47 = 0x35;
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    e->unk42 &= 0x7FFF;
    func_8002D9EC(e, 0x60, 0x60);
}

extern u8* alloc_class3_slot(void);

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))
void func_800F6B60_ovl11(u8* obj) {
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
            *(u8**)(D_1F80004C.bytes + 0x84) = child;
        }
    }
    func_8002D9EC(obj, 0x60, 0x60);
    if (--S16(obj, 0x7E) != -1) {
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
