#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_80046258(u8* self) {
    if (is_off_screen(self, 0x20, 0x20) == 0) {
        animate_object(self);
        move_object(self);
        if ((D_8009A420_as_s32 & 3) == 0) {
            self[0x64]++;
        }
        return;
    }
    self[3] = 0;
    self[4] = 2;
    *(s32*)(self + 0x50) = 0;
}
