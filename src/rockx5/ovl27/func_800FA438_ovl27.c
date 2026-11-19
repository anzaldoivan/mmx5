#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void (*D_800FDB04_ovl27[])(u8*);

void func_800FA438_ovl27(u8* obj) {
    if ((*(u8**)(D_1F80004C.bytes + 0x80))[0x89] == 1) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            set_animation(obj, 0x13);
            play_sound(2, 0x66, obj);
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
            obj[5] = 5;
            obj[6] = 0;
            return;
        }
    }
    D_800FDB04_ovl27[((s8*)obj)[6]](obj);
}
