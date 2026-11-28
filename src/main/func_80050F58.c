#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_80050F58(u8* obj) {
    u8* g;
    s32 sel;
    u8* sp;
    s32 off;

    g = g_Player;
    if (((s8*)obj)[4] == 0) {
        obj[3] = 1;
        ((s8*)obj)[2] = -1;
        sp = D_1F80001C.bytes;
        off = *(s32*)(sp + 0x30);
        *(u32***)(obj + 0x30) = g_visual_animation_tables.p;
        *(s16*)(obj + 0x40) = 0;
        *(s16*)(obj + 0x42) = 0x7802;
        obj[0x16] = 3;
        obj[0x5C] = 0;
        obj[4]++;
        *(u8**)(obj + 0x3C) = sp + off;
    }
    sel = -1;
    if ((u8)(g[0x47] + 0x1B) < 2) {
        sel = 0;
    }
    if ((u8)(g[0x47] + 0x23) < 2) {
        sel = 1;
    }
    if ((u8)(g[0x47] + 0x21) < 2) {
        sel = 2;
    }
    if ((u8)(g[0x47] + 0x1F) < 2) {
        sel = 3;
    }
    if ((u8)(g[0x47] + 0x1D) < 2) {
        sel = 4;
    }
    if (sel == -1) {
        clear_object_slot(obj);
        return;
    }
    if (sel != (s8)obj[2]) {
        set_animation(obj, sel + 0x20);
        obj[2] = sel;
    } else {
        animate_object(obj);
    }
    obj[0x15] = g[0x15];
    *(s32*)(obj + 8) = *(s32*)(g + 8);
    *(s32*)(obj + 0xC) = *(s32*)(g + 0xC);
    if (((s8*)obj)[0x5C] == 0) {
        obj[0x5C] = 8;
        play_sound(0, 0x1F, obj);
    } else {
        ((s8*)obj)[0x5C]--;
    }
    func_8002D9EC(obj, 0x28, 0x28);
}
