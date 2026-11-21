#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800FA3F8_ovl28(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
    obj[0x14] = 0;
    obj[0x16] = 7;
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 0;
    obj[0x60] = 0;
    set_animation(obj, 10);
    obj[0x5] = 0;
    obj[0x4]++;
}

void func_800FA4A4_ovl28(u8* obj) {
    u8* p;
    u8 st;
    s8 v;
    s32 t;

    p = *(u8**)(obj + 0x7C);
    t = p[0x15];
    obj[0x15] = t;
    t = *(u16*)(p + 0xA);
    *(volatile u16*)(obj + 0xA) =
        t; // !FAKE: volatile pins the reload below this store
    p = *(
        u8* volatile*)(obj +
                       0x7C); // !FAKE: volatile forces the target's parent reload
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    st = p[0x47];
    switch (*(s8*)(obj + 5)) {
    case 0:
        if ((u32)(st - 7) < 4) {
            set_animation(obj, 0xB);
            obj[5]++;
        }
        break;
    case 1:
        if ((u32)(st - 7) >= 4) {
            set_animation(obj, 0xA);
            obj[5]--;
        }
        break;
    }
    v = *(s8*)(*(u8**)(obj + 0x7C) + 4);
    if (v == 2) {
        obj[4] = v;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    animate_object(obj);
    apply_object_motion(obj);
}

#define D_800EEBA0_ovl00 func_800FA598_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
