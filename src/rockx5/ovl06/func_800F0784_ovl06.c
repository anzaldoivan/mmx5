#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void silence_sound(s32, s32);
extern void func_8003CD08(u8* obj);
extern u8 D_800FDE88_ovl06[];

void func_800F0784_ovl06(u8* obj) {
    u8 f;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x61] = 1;
        *(u8**)(obj + 0x68) = D_800FDE88_ovl06;
        obj[0x8C] = 0;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        silence_sound(5, 8);
        if (!(obj[0x97] & 2)) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0x20000;
            *(s32*)(obj + 0x2C) = 0x4000;
        }
        f = obj[0x97];
        if (f & 0x40) {
            if (!(f & 2)) {
                *(s32*)(obj + 0x24) = 0;
                *(s32*)(obj + 0x2C) = 0;
            }
            g_Player[0xD5] = 0;
            obj[0x97] ^= 0x40;
            func_8003CD08(g_Player);
        }
        if (!(obj[0xA8] & 8)) {
            obj[5] = 0xC;
            obj[6] = 0;
        } else {
            set_animation(obj, 0x13);
        }
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    if (obj[0xA8] & 8) {
        *(s32*)(obj + 0x24) = 0;
    }
    if (((s8*)obj)[0x46] == 0) {
        obj[6] = 0;
        obj[5] = 0;
        silence_sound(5, 8);
        obj[0x8C] = 0;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
    }
    if (!(obj[0x97] & 2)) {
        apply_object_motion(obj);
    }
    animate_object(obj);
}
