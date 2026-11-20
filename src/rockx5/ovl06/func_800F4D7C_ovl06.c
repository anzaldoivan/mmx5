#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

static inline u8 func_800F4D7C_ovl06_face(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        if (obj[0x8A] == 0) {
            return 0;
        }
        if (obj[0x8A] & 1) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        return 1;
    }
    if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    return 0;
}

void func_800F4D7C_ovl06(u8* obj) {
    u8 st;

    if (((s8*)obj)[6] == 0) {
        obj[6]++;
        obj[0x8A] = 0;
        set_animation(obj, 0);
        *(s16*)(obj + 0x84) = 0x160;
        obj[0x8C] = random_byte() & 0x3F;
        func_800F4D7C_ovl06_face(obj);
    }
    if (obj[0x70] & 8) {
        if (obj[0x8C] != 0) {
            goto dec; // !FAKE: goto kept for the matching branch layout
        }
        if (obj[0x8D] & 2) {
            goto call; // !FAKE: goto kept for the matching branch layout
        }
        if (func_800F4D7C_ovl06_face(obj)) {
            st = 3;
        } else if (obj[0x86] != 0) {
            st = 8;
        } else if (obj[0x87] != 0) {
            st = 9;
        } else {
            goto call; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        st = 4;
    }
    obj[5] = st;
    obj[6] = 0;
    return;
call:
    animate_object(obj);
    return;
dec:
    obj[0x8C]--;
    animate_object(obj);
}
