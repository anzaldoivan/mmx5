#include "types.h"
#include "mmx5/globals.h"

extern s32 try_enter_wall_cling(void* self);
extern s32 func_8003979C(u8* self);
extern void func_8003ABD0(u8* self);
extern s32 func_80040BBC(void* self);

void func_80040830(u8* self) {
    s32 dir;

    if (func_80040B6C(self) != 0) {
        return;
    }
    if (try_enter_wall_cling(self) != 0) {
        return;
    }
    if (func_8003979C(self) != 0 && self[0x92] == 0) {
        func_8003ABD0(self);
        return;
    }
    dir = func_80040BBC(self);
    if (dir != 0) {
        self[0xE8] = 0x28;
        player_hover_set_direction(self, dir);
    } else {
        func_8003F2D8(self, 0x15);
    }
}
