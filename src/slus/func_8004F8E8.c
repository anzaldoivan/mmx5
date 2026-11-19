#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8007B5E8[];
extern u16 D_8007B684[][2];
extern s32 D_8007B5FC[][2];

void func_8004F8E8(u8* obj) {
    u8* g;
    s32 kill;
    s8 state;
    u8 b;

    g = g_Player;
    if (((s8*)g)[5] == 0x14) {
        clear_object_slot(obj);
        return;
    }
    if (((s8*)obj)[2] == 0x10) {
        kill = ((s8*)g)[0x5C] == 0;
        if (((s8*)g)[0xD3] != 0) {
            kill = 1;
        }
        if (((s8*)g)[0xCF] != 0) {
            kill = 1;
        }
        if (((s8*)obj)[0x5C] != g[0x17]) {
            kill = 1;
        }
        if (obj[0x15] != g[0x15] && (u8)(obj[0x5D] - 0x18) < 3) {
            kill = 1;
        }
        if (((s8*)obj)[4] == 0) {
            set_animation(obj, D_8007B5E8[(s8)obj[2]]);
            obj[3] = 1;
            obj[4]++;
        }
        animate_object(obj);
        if (((s8*)obj)[0x46] == 0) {
            kill = 1;
        }
        if (kill) {
            clear_object_slot(obj);
            return;
        }
        b = g[0x15];
        obj[0x15] = b;
        if (b == 0) {
            *(u16*)(obj + 0xA) =
                *(u16*)(g + 0xA) - D_8007B684[((s8*)obj)[0x5D] - 0x18][0];
        } else {
            *(u16*)(obj + 0xA) =
                *(u16*)(g + 0xA) + D_8007B684[((s8*)obj)[0x5D] - 0x18][0];
        }
        *(u16*)(obj + 0xE) =
            *(u16*)(g + 0xE) + D_8007B684[((s8*)obj)[0x5D] - 0x18][1];
        return;
    }
    state = obj[4];
    switch (state) {
    case 0:
        obj[3] = 1;
        set_animation(obj, D_8007B5E8[((s8*)obj)[2]]);
        obj[4]++;
        if ((u8)(obj[2] - 8) < 2) {
            obj[0x16] = 0x11;
        }
        func_8002D9EC(obj, D_8007B5FC[((s8*)obj)[2]][0],
                      D_8007B5FC[((s8*)obj)[2]][1]);
        break;
    case 1:
        if (is_off_screen(obj, D_8007B5FC[((s8*)obj)[2]][0],
                          D_8007B5FC[((s8*)obj)[2]][1]) != 0) {
            obj[4] = 2;
        } else {
            animate_object(obj);
            if (((s8*)obj)[2] == 9 && ((s8*)obj)[0x45] != 0) {
                obj[0x45] = 0;
                g[0xF2] = 0;
            }
            if (((s8*)obj)[2] == 0xE) {
                *(s32*)(obj + 8) = *(s32*)(g + 8);
                *(s32*)(obj + 0xC) = *(s32*)(g + 0xC);
                if (((s8*)g)[5] != 0x3E || (((s8*)g)[0x45] & 0x80)) {
                    obj[4] = 2;
                    obj[3] = 0;
                }
            } else if (((s8*)obj)[0x46] < 0) {
                obj[4] = 2;
            }
        }
        func_8002D9EC(obj, D_8007B5FC[((s8*)obj)[2]][0],
                      D_8007B5FC[((s8*)obj)[2]][1]);
        break;
    case 2:
        clear_object_slot(obj);
        break;
    }
}
