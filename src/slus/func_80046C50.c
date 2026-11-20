#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80046C50(u8* obj) {
    u8* p;

    if (((s8*)obj)[2] == 0) {
        p = g_Player;
        p[0x98]--;
        p[0x99]--;
        p[0xA6]--;
    }
    clear_object_slot(obj);
}
