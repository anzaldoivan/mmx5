#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800FD3F8_ovl38(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);
    s32 r;

    if (*(s8*)(p + 4) == 2) {
        obj[3] = 0;
        obj[4]++;
        *(s16*)(p + 0x84) = 1;
    } else {
        animate_object(obj);
        apply_object_motion(obj);
        r = is_off_screen(obj, 0x40, 0x40);
        if (r == 1) {
            *(s16*)(*(u8**)(obj + 0x50) + 0x84) = r;
            obj[4]++;
        }
    }
}

void func_800FD494_ovl38(u8* obj) {
    u8* parent;

    if (*(s8*)(*(u8**)(obj + 0x50) + 4) == 2) {
        obj[3] = 0;
        obj[4]++;
        return;
    }
    animate_object(obj);
    parent = *(u8**)(obj + 0x50);
    obj[3] = 1;
    *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA);
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE);
    obj[0x15] = parent[0x15];
}
