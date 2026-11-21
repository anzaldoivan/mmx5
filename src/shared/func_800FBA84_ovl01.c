#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C1D;

void func_800FBA84_ovl01(u8* obj) {
    u8* g = g_Player;

    if (*(s16*)(g + 0xA) > 0x1100) {
        if (g[0xF7] == 0) {
            move_object(obj);
        }
        func_8002D9EC(obj, 0xF0, 0x20);
    }
    if (D_800D1C1D == 4) {
        obj[4]++;
    }
}
