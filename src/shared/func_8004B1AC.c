#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_8004B1AC(s8* e) {
    if (e[2] == 0) {
        g_Player[0x98]--;
        g_Player[0x99]--;
    }
    clear_object_slot(e);
}
