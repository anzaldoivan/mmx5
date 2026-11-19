#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_800C9310;

void func_80047138(void* arg0) {
    g_Player[0xF7] = 0;
    D_800C9310 = 1;
    g_Player[0x98]--;
    g_Player[0x99]--;
    clear_object_slot(arg0);
}
