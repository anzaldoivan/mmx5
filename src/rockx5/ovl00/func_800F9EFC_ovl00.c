#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F9EFC_ovl00(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) == 2) {
        obj[4]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_800317B8(obj);
    if (is_off_screen(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4]++;
    }
}
