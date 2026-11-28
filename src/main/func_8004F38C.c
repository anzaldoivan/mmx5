#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void* D_8007B5C0[];

void func_8004F38C(u8* obj) {
    u8* g = g_Player;

    if ((s8)g[5] == 0x14) {
        clear_object_slot(obj);
    } else {
        ((void (*)(u8*, u8*))D_8007B5C0[(s8)obj[4]])(obj, g);
    }
}
