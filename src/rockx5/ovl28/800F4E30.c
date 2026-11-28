#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"

extern s32 D_8009A0A8;

void func_800F4E30_ovl28(u8* obj) {
    load_palette(0x13C, D_1F800030 + 0x60, 1);
    load_palette(0x13D, D_1F800030 + 0x80, 1);
    *(u16*)(obj + 0x42) = 0x7CCC;
    play_sound(2, 0x6C, obj);
    func_8003D29C(0x14, (D_8009A0A8 <= *(s32*)(obj + 8)) << 6);
    obj[5] = 1;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    set_animation(obj, 0xB);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x61] = 0x19;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    if (*(s32*)(obj + 0x24) > 0) {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s32*)(obj + 0x2C) = 0x4200;
    func_8002D9EC(obj, 0x60, 0x60);
}

extern u8* alloc_class3_slot(void);

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))
#define G D_1F80004C.bytes
void func_800F4F20_ovl28(u8* obj) {
    u8* child;
    s16 r;
    s32 v;

    animate_object(obj);
    apply_object_motion(obj);
    if (!(obj[0x70] & 8)) {
        return;
    }
    if (--S16(obj, 0x7C) == 0) {
        obj[5] = 2;
        child = alloc_class3_slot();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            U16(child, 0xA) = U16(obj, 0xA);
            U16(child, 0xE) = U16(obj, 0xE);
            *(u8**)(G + 0x80) = child;
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
#undef G

extern u8 D_8009A0B5;

void func_800F5040_ovl28(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x60, 0x60);
    if (D_800D50DE == 0x1F) {
        func_8003D29C(0x48, D_8009A0B5);
        set_animation(obj, 0x17);
        obj[5] = 4;
    }
}

void func_800F50A8_ovl28(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x60, 0x60);
    if (*(s8*)(obj + 0x45) == 1 && D_800D50DE == 0) {
        func_8002385C(0x43, 0xFF, 0);
        obj[5] = 5;
    }
}

extern u8 D_80091C44;

void func_800F5110_ovl28(void) {
    if (D_80091C44 == 0) {
        u8* o = g_playthrough_state.u;
        u8* b = D_8009A1F8.u;
        o[0xF] = 0x10;
        o[0x24] = 0;
        *(s32*)(o + 0x20) = 0;
        *(u16*)(b + 0x2A) = *(u16*)(b + 0xE);
    }
}
