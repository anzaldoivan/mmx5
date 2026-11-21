#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "addr.h"

extern void func_800F81F4_ovl11(u8* obj);

s32 func_800F7BB4_ovl11(u8* obj) {
    s32 ret;
    obj[0x60] = 8;
    obj[0x62] = 0;
    *(s32*)(obj + 0x68) = 0;
    set_animation(obj, 1);
    animate_object(obj);
    func_800F81F4_ovl11(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x40000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
    ret = play_sound(2, 0x32, obj);
    obj[0x9A] = 1;
    return ret;
}

extern s16 D_800FA060_ovl11;

void func_800F7C34_ovl11(u8* obj) {
    u32 r;

    move_object(obj);
    animate_object(obj);
    if (*(s16*)(obj + 0xE) < D_800FA060_ovl11) {
        D_1F80004C.bytes[0x92] = 7;
        set_animation(obj, 2);
        *(s16*)(obj + 0x7C) = 0x5A;
        r = random_byte();
        obj[6]++;
        *(s16*)(obj + 0x7E) = (u8)(r % 3) + 4;
    }
}

extern u8 D_800F9D10_ovl11[];
extern u8 D_800F9D14_ovl11[];

void func_800F7CDC_ovl11(u8* obj) {
    u8 r;

    if (--*(s16*)(obj + 0x7C) == 0) {
        *(u8**)(obj + 0x54) = D_800F9D10_ovl11;
        *(u8**)(obj + 0x50) = D_800F9D14_ovl11;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7E) -= 1;
        r = ((u32(*)())random_byte)() % 3;
        if (r == 0) {
            obj[6] = 3;
            if (D_1F80004C.bytes[0x92] == 3) {
                obj[6] = 7;
            }
        } else if (r == 1) {
            obj[6] = 5;
        } else {
            obj[6] = 7;
            if (D_1F80004C.bytes[0x92] == 7) {
                obj[6] = 3;
            }
        }
    }
}
