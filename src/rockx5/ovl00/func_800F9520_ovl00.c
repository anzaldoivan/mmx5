#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);

void func_800F9520_ovl00(u8* obj) {
    u8* p;
    s32 t;
    s16 c;

    t = *(u16*)(obj + 0x7C) - 1;
    *(u16*)(obj + 0x7C) = t;
    if ((t << 16) == 0) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 3;
            p[2] = 3;
            *(u8**)(p + 0x7C) = obj;
            start_pad_vibration(2);
            play_sound(2, 2, obj);
        }
        obj[7] = 0;
        obj[6]++;
    }
    c = *(s16*)(obj + 0x7C);
    if (c == 30) {
        *(s32*)(obj + 0x24) = 0x20000;
    } else if (c < 30 &&
               !(*(volatile u16*)(obj + 0x7C) &
                 1)) { // !FAKE: volatile keeps the lhu after the slti test
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
    animate_object(obj);
    apply_object_motion(obj);
}
