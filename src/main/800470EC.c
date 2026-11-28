#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800470EC(u8* arg0) {
    u8* obj;

    obj = *(u8**)(arg0 + 0x7C);
    arg0[3] = 0;
    arg0[4]++;
    if (*(s8*)(obj + 2) == 0) {
        if (*(s8*)(obj + 5) != 0x26) {
            arg0[4] = 3;
        }
    } else {
        if (*(s8*)(obj + 5) != 0x3F) {
            arg0[4] = 3;
        }
    }
}

void func_80047138(void* arg0) {
    g_Player[0xF7] = 0;
    D_800C9310.b = 1;
    g_Player[0x98]--;
    g_Player[0x99]--;
    clear_object_slot(arg0);
}
