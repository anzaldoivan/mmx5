#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* find_free_visual_obj(void);
extern s32 func_8002B5B4(s32);

static inline s32 func_800F2C20_ovl28_mask(u8 c) {
    s32 m;

    m = 2;
    if (c != 0) {
        m = 1;
    }
    return m;
}

void func_800F2C20_ovl28(u8* obj) {
    u8* p;
    s32 r0;
    s32 r1;
    s32 m;
    s8 t;
    s32 d;
    u8 c;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 3) {
        return;
    }
    apply_object_motion(obj);
    p = find_free_visual_obj();
    if (p != 0 && *(s8*)(obj + 0x45) == 4) {
        p[0] = 0x61;
        p[1] = 0xB;
        p[2] = 5;
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        r0 = func_8002B5B4(0x40);
        r1 = func_8002B5B4(0x40);
        *(s16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        p[0x15] = obj[0x15];
        if (p[0x15] == 0) {
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0x30;
        } else {
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x30;
        }
        *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 0x10;
        *(u8**)(p + 0x50) = obj;
    }
    if (*(s8*)(obj + 0x45) == 1 && (t = *(s8*)(obj + 7)) == 2) {
        obj[7] = 3;
        obj[6] = 5;
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0xB;
            p[2] = t;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x15] = obj[0x15];
            if (p[0x15] == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x20;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0x20;
            }
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 8;
            *(u8**)(p + 0x50) = obj;
        }
    } else {
        c = obj[0x15];
        m = func_800F2C20_ovl28_mask(c);
        if (c != 0) {
            if (*(s32*)(obj + 0x20) < 0x42000) {
                *(s32*)(obj + 0x20) = 0x42000;
            }
        } else if (*(s32*)(obj + 0x20) > -0x42000) {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        if ((((obj[0x70] & m) ||
              ((d = D_8009A0AA - *(s16*)(obj + 0xA)) >= 0
                   ? (d < 0x41)
                   : (*(s16*)(obj + 0xA) - D_8009A0AA < 0x41))) &&
             *(s8*)(obj + 0x45) == 2) ||
            --*(s16*)(obj + 0x7C) == 0) {
            set_animation(obj, 0x19);
            play_sound(2, 0x72, obj);
            obj[6]++;
        }
    }
}
