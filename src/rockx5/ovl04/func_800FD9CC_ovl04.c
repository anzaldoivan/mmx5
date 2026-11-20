#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FD9CC_ovl04(u8* o) {
    animate_object();
    move_object(o);
    if (*(s8*)(o + 0x46) == 0) {
        *(u8*)(o + 4) = 2;
    }
}
