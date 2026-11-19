#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80048448(s8* e) {
    *(s32*)(e + 0x50) = 0;
    if (e[2] == 0) {
        g_Player[0x98]--;
        g_Player[0x99]--;
    }
    clear_object_slot(e);
}
