#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800484F0(u8* e) {
    if ((e[2] & 0x3F) == 0) {
        g_Player[0x98]--;
        g_Player[0x99]--;
    }
    clear_object_slot(e);
}
