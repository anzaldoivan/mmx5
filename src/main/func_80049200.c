#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8 D_800770AC[];

void func_80049200(u8* obj) {
    s32 t;

    animate_object(obj);
    t = *(u16*)(obj + 0x92) + 1;
    *(u16*)(obj + 0x92) = t;
    if (*(s8*)(obj + 5) == 0) {
        move_object(obj);
        obj[3] = 1;
        if (*(s16*)(obj + 0xE) - D_8009A206.s >= 0x141) {
            obj[3] = 0;
            if (*(s16*)(obj + 0x92) >= 0x12D) {
                obj[4] = 2;
                return;
            }
            *(void**)(obj + 0x50) = 0;
            obj[5]++;
        }
    } else if ((s16)((s16)t % 60) == 0) {
        u8* d;
        s32 r;

        play_sound(1, 0x10, obj);
        *(void**)(obj + 0x50) = D_800770AC;
        r = random_byte();
        d = D_8009A1F8.u;
        *(s16*)(obj + 0xA) = *(u16*)(d + 0xA) + (r % 150) * 2 + 0xA;
        *(s16*)(obj + 0xE) = *(u16*)(d + 0xE) - 0x50;
        obj[5]--;
    }
}
