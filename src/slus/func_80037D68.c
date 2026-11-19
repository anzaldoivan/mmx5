#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern void func_8003B28C(u8* obj);
extern u8 D_800D1F3C;

void func_80037D68(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 6) == 0) {
        if (D_800D1F3C == 0) {
            func_8003B33C(obj, 0x27);
            obj[6]++;
        }
    } else {
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] = 0;
            play_sound(0, 0x21, 0);
        }
        if (*(s8*)(obj + 0x46) == 0) {
            func_8003B33C(obj, 0x28);
            func_8003B28C(obj);
        }
    }
}
