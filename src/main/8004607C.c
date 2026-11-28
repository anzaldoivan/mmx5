#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_80044F78(void* arg0);

void func_8004607C(u8* a0) {
    if (is_off_screen(a0, 0x20, 0x14) == 0 && *(s8*)(a0 + 0x98) == 0) {
        animate_object(a0);
        move_object(a0);
        func_8002D9EC(a0, 0x20, 0x14);
        if (a0[0x70] == 0) {
            ((s32(*)())func_8002F8FC)(a0);
            if (a0[0x70] == 0) {
                return;
            }
        }
        func_80044F78(a0);
    }
    a0[3] = 0;
    a0[4] = 3;
    *(s32*)(a0 + 0x50) = 0;
    *(s32*)(a0 + 0x68) = 0;
}

void func_80046124(u8* arg0) {
    *(s32*)(arg0 + 0x50) = 0;
    if (((s8*)arg0)[1] != 0x15) {
        g_Player[0x98]--;
    }
    clear_object_slot();
}
