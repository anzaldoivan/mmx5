#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_8004CC34(u8* obj) {
    if ((s8)g_Player[5] == 0x3B) {
        g_Player[6] = 2;
    }
    clear_object_slot(obj);
}
