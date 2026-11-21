#include "types.h"
#include "mmx5/ovl05.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

extern s32 func_800F0FFC_ovl05(u8* obj);

void func_800F0CDC_ovl05(u8* obj) {
    s32 v;

    func_800F103C_ovl05(obj);
    if (((g_Player_as_X4_Obj.y_pos.i.hi - *(s16*)(obj + 0xE)) < 0
             ? (*(s16*)(obj + 0xE) - g_Player_as_X4_Obj.y_pos.i.hi)
             : (g_Player_as_X4_Obj.y_pos.i.hi - *(s16*)(obj + 0xE))) >= 3) {
        v = 0x20000;
        if (g_Player_as_X4_Obj.y_pos.i.hi >= *(s16*)(obj + 0xE)) {
            v = 0xFFFD0000;
        }
        *(s32*)(obj + 0x24) = v | 0x8000;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    if (((g_Player_as_X4_Obj.x_pos.i.hi - *(s16*)(obj + 0xA)) < 0
             ? (*(s16*)(obj + 0xA) - g_Player_as_X4_Obj.x_pos.i.hi)
             : (g_Player_as_X4_Obj.x_pos.i.hi - *(s16*)(obj + 0xA))) < 0x11) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
    }
    apply_object_motion(obj);
    if (func_800F0FFC_ovl05(obj) != 0) {
        obj[3] = 0;
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 2;
    }
}
