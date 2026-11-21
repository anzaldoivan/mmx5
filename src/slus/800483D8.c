#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void* D_80077094[];

void func_800483D8(u8* obj) {
    if (is_off_screen(obj, 0x20, 0x20) == 0) {
        animate_object(obj);
        ((void (*)(u8*))D_80077094[(s8)obj[5]])(obj);
    } else {
        obj[3] = 0;
        obj[4] = 2;
    }
}

void func_80048448(s8* e) {
    *(s32*)(e + 0x50) = 0;
    if (e[2] == 0) {
        g_Player[0x98]--;
        g_Player[0x99]--;
    }
    clear_object_slot(e);
}
