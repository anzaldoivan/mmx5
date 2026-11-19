#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_8004815C(u8* obj) {
    s8 v;
    s32 t;
    u8* p;

    animate_object(obj);
    if (!(obj[2] & 0x3F)) {
        if (is_off_screen(obj, 0xA0, 0xA0) == 0) {
            move_object(obj);
            func_8002D9EC(obj, 0x20, 0x20);
        } else {
            obj[3] = 0;
            obj[4] = 2;
        }
    } else {
        p = *(u8**)(obj + 0x7C);
        v = ((s8*)p)[4];
        if (v == 2) {
            obj[3] = 0;
            obj[4] = v;
        } else {
            move_object(obj);
        }
        func_8002D9EC(obj, 0x20, 0x20);
    }
    if (obj[0x8D] != 0) {
        obj[0x8D]--;
    }
    if (obj[0x8C] == 0 && obj[0x8D] == 0) {
        t = obj[2];
        obj[0x8C] = 1;
        if ((t & 0x3F) < 4) {
            p = player_spawn_weapon(((s8*)obj)[0], ((s8*)obj)[1], (s8)(t + 1),
                                    obj);
            if (p != 0) {
                *(s32*)(p + 8) = *(s32*)(obj + 8);
                *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
                p[0x15] = obj[0x15];
            }
        }
    }
}
