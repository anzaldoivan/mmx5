#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern void func_8003A190(u8*);
extern void func_8003A670(u8* arg0);

void func_80037CB4(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 6) == 0) {
        if (obj[0xF5] == 4) {
            func_8003B33C(obj, 0x27);
            obj[6]++;
        }
    } else {
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] = 0;
            play_sound(0, 0x21, 0);
        }
        if (*(s8*)(obj + 0x46) == 0) {
            func_8003A190(g_Player);
            func_8003D2C4();
            func_8003A670(obj);
        }
    }
}
