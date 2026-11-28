#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_8004F654(u8* obj, u8* base);

void func_8004F0B4(u8* obj) {
    u8* base = g_Player;
    s32 flag;
    u8* scr;
    s32 off;

    if (((s8*)base)[5] == 0x14) {
        clear_object_slot(obj);
        return;
    }
    if (((s8*)obj)[4] == 0) {
        obj[3] = 1;
        *(s32*)(obj + 0x38) = 0;
        scr = D_1F80001C.bytes;
        off = ((s32*)scr)[1];
        *(u8**)(obj + 0x30) = g_visual_animation_tables.u;
        *(s16*)(obj + 0x40) = 0;
        *(s16*)(obj + 0x42) = 0x7802;
        obj[0x16] = 3;
        *(u8**)(obj + 0x3C) = scr + off;
        func_8004F654(obj, base);
        set_animation(obj, 2);
        obj[4]++;
    } else {
        animate_object(obj);
        func_8004F654(obj, base);
        flag = 0;
        if (((s8*)base)[0x84] > 0) {
            if (base[0x17] != 0x10) {
                flag = base[0x17] != 0x80;
            }
        } else if (base[0x17] != 0x12) {
            flag = 1;
        }
        if (((s8*)obj)[0x46] < 0) {
            flag = 1;
        }
        if (flag != 0) {
            clear_object_slot(obj);
            return;
        }
    }
    func_8002D89C(obj);
}
