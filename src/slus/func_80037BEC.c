#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void func_8003CE64(u8* obj);
extern void set_stand_animation_by_hp(u8* obj);

void func_80037BEC(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        animate_object(obj);
        apply_object_motion(obj);
        if (*(s32*)(obj + 0x24) <= 0) {
            func_8003B33C(obj, 0xB);
            ((s8*)obj)[0x67] = -1;
            *(s32*)(obj + 0x24) = 0;
            obj[6]++;
        }
    } else if (obj[0x89] & 8) {
        func_8003CE64(obj);
        set_stand_animation_by_hp(obj);
        obj[0x67] = 0;
        ((s8*)obj)[0xD0] = -1;
        obj[5] = 0x14;
        obj[6] = 0;
    } else {
        animate_object(obj);
        apply_object_motion(obj);
    }
}
