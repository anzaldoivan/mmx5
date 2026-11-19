#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F9888_ovl29[];

void func_800F3570_ovl29(u8* obj) {
    s16 t;
    u8* p;

    t = *(s16*)(obj + 0x7C);
    if (t >= 0x21) {
        *(u8**)(obj + 0x68) = D_800F9888_ovl29;
        if ((obj[0x70] & 8) && t >= 0x31) {
            set_animation(obj, 0x10);
            obj[0x67] = 0;
            play_sound(2, 0xAF, obj);
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0;
            obj[6]++;
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x26;
                p[2] = 2;
                *(u8**)(p + 0x50) = obj;
            }
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x26;
                p[2] = 3;
                *(u8**)(p + 0x50) = obj;
            }
        }
    }
    (*(s16*)(obj + 0x7C))++;
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
