#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8002E274(u8* a0, u8* a1);

void func_800F0370_ovl10(u8* obj) {
    u8* g = g_Player;

    if (g[0xF7] == 0) {
        animate_object(obj);
        move_object(obj);
    }
    if (func_800317B8(obj) == 0) {
        if (func_80031DD0(obj) < 0) {
            goto dead;
        }
        if (func_8002E274(obj, g) == 0) {
            if (obj[0x70] != 0) {
            dead:
                ((s32(*)())func_8004FD24)(obj);
                obj[4]++;
                return;
            }
            if (is_off_screen(obj, 0x20, 0x20) == 0) {
                func_8002D9EC(obj, 0x10, 0x10);
                return;
            }
        }
    }
    obj[4]++;
}
