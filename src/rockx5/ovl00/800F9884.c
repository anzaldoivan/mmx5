#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern u8 D_8009A0B5;

void func_800F9884_ovl00(Ent657C* e) {
    e->unk7C = 0x7F;
    e->unk7E = 0x19;
    e->unk61 = 0x19;
    e->unk42 &= 0x7FFF;
    e->unk5++;
    func_8003D29C(0x14, D_8009A0B5);
    func_8002D9EC(e, 0xFF, 0xFF);
}

extern u8* alloc_class3_slot(void);
extern u8 D_800D1C27;

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))

void func_800F98F0_ovl00(u8* obj) {
    u8* child;
    s16 r;
    s32 v;

    if (--S16(obj, 0x7C) == 0) {
        child = alloc_class3_slot();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            U16(child, 0xA) = U16(obj, 0xA);
            U16(child, 0xE) = U16(obj, 0xE);
            *(u8**)(obj + 0x80) = child;
        }
        obj[5]++;
        D_800D1C27 = 1;
    }
    if (S16(obj, 0x7E)-- == 0) {
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
    func_8002D9EC(obj, 0xFF, 0xFF);
}
#undef S16
#undef U16
#undef S8

extern s8 D_800D1C0F;

void func_800F99F8_ovl00(u8* obj) {
    s8* child = *(s8**)(obj + 0x80);

    if (child[0] != 0) {
        if (child[7] == 0) {
            if (--*(s16*)(obj + 0x7E) == -1) {
                *(s16*)(obj + 0x7E) = 5;
                *(u16*)(obj + 0x42) ^= 0x8000;
            }
            func_8002D9EC(obj, 0xFF, 0xFF);
        }
    } else {
        D_800D1C0F = 0x10;
        clear_object_slot();
    }
}
