#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F2E74_ovl06(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (is_off_screen(obj, 0x20, 0x20) == 0 && *(s8*)(obj + 0x98) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4] = 2;
        obj[3] = 0;
        *(s32*)(obj + 0x50) = 0;
    }
}

void func_800F2EEC_ovl06(u8* arg0) {
    u8* p;
    u8 n;

    p = *(u8**)(arg0 + 0x7C);
    n = p[0x86];
    if (n != 0) {
        p[0x86] = n - 1;
    }
    clear_object_slot();
}
