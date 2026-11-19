#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F9894_ovl29[];

void func_800F5364_ovl29(u8* obj) {
    u8* child;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 6);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
        obj[0x60] = 4;
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 2;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 3;
            *(u8**)(child + 0x50) = obj;
        }
        obj[0x67] = 0;
        play_sound(2, 0xAF, obj);
    }
}
