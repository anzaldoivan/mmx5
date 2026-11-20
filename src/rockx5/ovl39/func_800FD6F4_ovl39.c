#include "types.h"
#include "mmx5/object.h"

extern s32 D_8009A0A8;

void func_800FD6F4_ovl39(u8* obj) {
    *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
    move_object(obj);
    if (*(s16*)(obj + 0xE) >= 0x770) {
        *(s16*)(obj + 0x82) = 0x5A;
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
    }
}
