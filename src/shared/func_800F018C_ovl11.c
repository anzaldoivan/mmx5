#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void func_800F0330_ovl11(u8* obj);
extern void func_800F0414_ovl11(u8* obj);

void func_800F018C_ovl11(u8* obj) {
    if (obj[0x87] != 0) {
        obj[0x87]--;
        *(s32*)(obj + 0x8) += *(s32*)(obj + 0x20);
        *(s32*)(obj + 0x20) += *(s32*)(obj + 0x28);
    } else {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
    }
    func_800F0330_ovl11(obj);
    animate_object(obj);
    func_800F0414_ovl11(obj);
    if (*(signed char*)(obj + 0x2) == 0) {
        apply_object_motion(obj);
    }
    func_8002D9EC(obj, 0x30, 0x20);
}
