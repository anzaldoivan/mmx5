#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80046124(u8* arg0) {
    *(s32*)(arg0 + 0x50) = 0;
    if (((s8*)arg0)[1] != 0x15) {
        g_Player[0x98]--;
    }
    clear_object_slot();
}
