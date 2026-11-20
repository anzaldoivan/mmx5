#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* alloc_class3_slot(void);
extern void func_800F1260_ovl00(u8* p);
extern s8 D_800D1C27;

void func_800F1380_ovl00(u8* p) {
    s8 state;
    u8* s;

    state = *(s8*)(p + 4);
    if (state == 0) {
        func_800F1260_ovl00(p);
    } else if (state == 1) {
        s = alloc_class3_slot();
        if (s != 0) {
            s[0] = state;
            s[1] = 3;
            s[2] = 5;
        }
        set_animation(p, 0);
        play_sound(5, 6);
        {
            s32 r = random_byte();
            p[4]++;
            *(s16*)(p + 0xA) = (r % 20) * 16 + 0x118B;
        }
    } else if (state == 2) {
        ((s32(*)())animate_object)(p);
        p[3] = p[0x45];
        if (p[0x47] == 0) {
            p[0] |= 0x10;
        } else {
            p[0] &= 0xEF;
        }
        if (*(s8*)(p + 0x46) == 0) {
            p[4]++;
            if (D_800D1C27 != 0) {
                s = alloc_class3_slot();
                if (s != 0) {
                    s[0] = 1;
                    s[1] = 3;
                    s[2] = 6;
                }
                clear_object_slot(p);
            } else {
                *(u16*)(p + 0x54) = random_byte() % 80 + 30;
            }
        }
    } else if (state == 3) {
        if (--*(s16*)(p + 0x54) == 0) {
            p[4] = 1;
        }
        if (D_800D1C27 != 0) {
            s = alloc_class3_slot();
            if (s != 0) {
                s[0] = 1;
                s[1] = state;
                s[2] = 6;
            }
            clear_object_slot(p);
        }
    }
}
