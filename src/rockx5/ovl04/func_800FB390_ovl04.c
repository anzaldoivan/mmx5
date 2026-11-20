#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800D1C00[];

void func_800FB390_ovl04(u8* obj) {
    s8 flag;
    s8 state;
    u8* spawn;
    u8* p;

    animate_object(obj);
    flag = obj[0x45];
    if (flag & 0x80) {
        obj[0x45] &= 0x7F;
        spawn = func_8002D1A4(flag);
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0xB;
            *(u8**)(spawn + 0x7C) = obj;
            spawn[2] = 2;
        }
        play_sound(2, 0x14, obj);
    } else if (flag == 1) {
        state = obj[2];
        if (state == 12) {
            set_animation(obj, 0xD);
        } else if (state == 13) {
            set_animation(obj, 0xE);
        } else if (state == 14) {
            set_animation(obj, 0xF);
        } else if (state == 15) {
            set_animation(obj, 0x10);
        }
        p = D_800D1C00;
        p[0x28] &= obj[0x95];
        p[0x29] &= obj[0x96];
        obj[5]--;
    }
    func_8002D9EC(obj, 0x10, 0x10);
}
