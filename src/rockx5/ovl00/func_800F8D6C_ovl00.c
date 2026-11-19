#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F8D6C_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
