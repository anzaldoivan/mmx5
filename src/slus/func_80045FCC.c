/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EE5D4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_00_lemon.c:lemon_deflected, AGPL-3.0; proven shared with X6 by exact signature 9c5292152b2a (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define BASE_OBJECT(object) ((X4_Obj*)(object))
#define MOVING_OBJECT(object) ((X4_Obj*)(object))
void func_80046030(void* arg0);

void func_80045FCC(X4_Obj* arg0) {
    if (is_off_screen(BASE_OBJECT(arg0), 0xC, 8) == 0) {
        animate_object(ANIMATED_OBJECT(arg0));
        move_object(MOVING_OBJECT(arg0));
        func_8002D9EC(BASE_OBJECT(arg0), 0xC, 8);
        return;
    }
    func_80046030(arg0);
}
