#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_8004DC9C(u8* a0) {
    if ((((s8*)a0)[2] & 0x80) && is_off_screen(a0, 0x80000, 0x80000) == 1) {
        clear_object_slot(a0);
        return;
    }
    animate_object(a0);
    move_object(a0);
    func_8002D9EC(a0, 0x80000, 0x80000);
}
