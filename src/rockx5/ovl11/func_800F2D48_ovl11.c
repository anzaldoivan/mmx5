#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2D48_ovl11(u8* obj) {
    u8 flags;

    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        flags = D_1F80004C.bytes[0x82];
        if (flags & 0x80) {
            switch (flags & 3) {
            case 0:
                set_animation(obj, 0xD);
                break;
            case 1:
                set_animation(obj, 0xC);
                break;
            case 2:
                set_animation(obj, 0xE);
                break;
            }
        } else {
            set_animation(obj, 0x1A);
        }
        obj[6]++;
    }
}
