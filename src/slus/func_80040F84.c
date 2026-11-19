#include "types.h"
#include "mmx5/movement.h"

extern void func_8003A9AC(void);
extern void player_set_animation_shooting(u8* arg0, s32 arg1);

void func_80040F84(u8* obj) {
    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    apply_object_motion(obj);
    if (*(signed char*)(obj + 0x46) == 0) {
        player_set_animation_shooting(obj, 0xB);
        obj[5] = 7;
        obj[6] = 0;
    }
}
