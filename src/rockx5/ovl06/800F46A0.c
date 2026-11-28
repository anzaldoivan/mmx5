#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

extern void func_80024548(s32);

void func_800F46A0_ovl06(u8* a0) {
    u8* d = D_8009A1F8.u;
    u8* g = g_playthrough_state.u;

    a0[0x8B] = 1;
    *(s16*)(a0 + 0x80) = *(s16*)(d + 0x24);
    *(s16*)(a0 + 0x82) = *(s16*)(d + 0x26);
    *(s16*)(d + 0x24) = 0xB50;
    *(s16*)(d + 0x26) = 0xB50;
    *(s16*)(d + 0x28) = 0xE0;
    *(s16*)(d + 0x2A) = 0xE0;
    g[0x24] = 1;
    g[0xA2] = 0x30;
    func_80024548(0);
    g[0x25] = 0;
    *(u8**)(g + 0x20) = a0;
    *(s16*)(a0 + 0x7E) = 3;
    a0[6]++;
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_80075660[];
extern u8 D_800FE4D8_ovl06[];

void func_800F4738_ovl06(u8* obj) {
    s32 t;
    s32 n;

    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
    }
    if (*(s16*)(obj + 0xA) < 0xBA0) {
        *(u16*)(obj + 0xA) += 3;
        return;
    }
    t = *(u16*)(obj + 0x7E) - 1;
    *(u16*)(obj + 0x7E) = t;
    if ((t << 16) == 0) {
        play_sound(0, 0xE, 0);
        *(s16*)(obj + 0x7E) = 3;
    }
    if (!(D_8009A420_as_s32 & 1)) {
        n = obj[0x5C] + 1;
        obj[0x5C] = n;
        if ((s8)n == 0x30) {
            *(u8**)(obj + 0x58) = D_80075660;
            *(u8**)(obj + 0x68) = D_800FE4D8_ovl06;
            obj[6]++;
        }
    }
}
#undef D_8009A420_as_s32

extern u32 func_8002DFB0(void);

void func_800F4818_ovl06(u8* a0) {
    u32 r = func_8002DFB0();
    *(s16*)(a0 + 0x7E) = 1;
    a0[6]++;
    *(s16*)(a0 + 0x7C) = (u8)(r % 50) + 40;
}

extern u8 D_800FE4DC_ovl06[];
extern u8 D_800FE4E0_ovl06[];

void func_800F4888_ovl06(u8* obj) {
    *(s32*)(obj + 0x20) = 0xFFFD0000;
    *(s32*)(obj + 0x28) = 0x3000;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x8D] = 1;
    obj[0x6]++;
    set_animation(obj, 1);
    *(u8**)(obj + 0x50) = D_800FE4DC_ovl06;
    *(u8**)(obj + 0x54) = D_800FE4E0_ovl06;
}

void func_800F48F4_ovl06(u8* obj) {
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) > 0) {
        *(s16*)(obj + 0x7C) = 0x14;
        obj[6]++;
    }
}

extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_800FE624_ovl06[];
extern u8 D_8009A244;

void func_800F4938_ovl06(u8* obj) {
    if (*(s16*)(obj + 0x7C) == 0) {
        apply_object_motion(obj);
    } else {
        *(s16*)(obj + 0x7C) -= 1;
    }
    if (obj[0x70] & 1) {
        func_80028B18(0, 0xC80, 0xE0, D_800FE624_ovl06);
        D_8009A244 = 1;
        play_sound(2, 0x1D, obj);
        func_8002A5C4(0x28, 4, 2);
        *(s16*)(obj + 0x7C) = 0x3C;
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        obj[6]++;
    }
}

extern u8 D_800FE4D0_ovl06[];
extern u8 D_800FE4D4_ovl06[];
extern u8 D_800FE62C_ovl06[];
extern u8 D_8009A244;

void func_800F49EC_ovl06(u8* obj) {
    if (*(s16*)(obj + 0x7C) == 0) {
        move_object(obj);
        if (*(s16*)(obj + 0xA) < 0xBA0) {
            obj[6] = 2;
        }
    } else if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        obj[0x8D] = 0;
        *(u8**)(obj + 0x50) = D_800FE4D0_ovl06;
        *(u8**)(obj + 0x54) = D_800FE4D4_ovl06;
        func_80028B18(0, 0xC80, 0xE0, D_800FE62C_ovl06);
        D_8009A244 = 1;
    }
}
