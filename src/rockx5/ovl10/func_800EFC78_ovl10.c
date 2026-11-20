#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FB364_ovl10[];
extern u8 D_800FB370_ovl10[];

void func_800EFC78_ovl10(u8* obj) {
    s8 ev;

    animate_object(obj);
    ev = *(s8*)(obj + 0x45);
    if (ev == 1) {
        if (*(s8*)(obj + 2) != 0) {
            *(u8**)(obj + 0x68) = D_800FB364_ovl10;
            set_animation(obj, 4);
        } else {
            *(u8**)(obj + 0x68) = D_800FB370_ovl10;
            set_animation(obj, 1);
        }
        obj[6]++;
    } else if (ev == 10) {
        play_sound(2, 0x5D, obj);
    } else if (ev == 20) {
        play_sound(2, 0x5E, obj);
    }
}
