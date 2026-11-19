#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800498AC(u8* obj) {
    u8* p = g_Player;

    p[0x98]--;
    p[0x99]--;
    p[0xA6]--;
    clear_object_slot(obj);
}
