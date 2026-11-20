#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F5EEC_ovl26(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (is_off_screen(obj, 0x80, 0x80) == 0) {
        func_8002D9EC(obj, 0x60, 0x60);
    } else {
        obj[4] = 2;
    }
}
