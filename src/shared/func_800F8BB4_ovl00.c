#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FB448_ovl00[][6];

void func_800F8BB4_ovl00(u8* obj) {
    u8* p;

    if (--*(s16*)(obj + 0x7C) == 0) {
        if (*(s16*)(obj + 0x7E) == 2) {
            set_animation(obj, 0);
            obj[5] = D_800FB448_ovl00[obj[0x8D]][obj[0x8E]++];
            obj[6] = 0;
        } else {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 3;
                p[2] = obj[0x7E];
                *(u8**)(p + 0x7C) = obj;
                play_sound(2, 1, obj);
            }
        }
        if (++*(s16*)(obj + 0x7E) == 1) {
            *(s16*)(obj + 0x7C) = 0x14;
        } else {
            *(s16*)(obj + 0x7C) = 0x78;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}
