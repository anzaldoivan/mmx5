#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80046A6C(void* a0) {
    g_Player[0x98]--;
    g_Player[0x99]--;
    clear_object_slot(a0);
}
