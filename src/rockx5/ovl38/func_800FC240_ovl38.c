#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "addr.h"

void func_800FC240_ovl38(u8* obj) {
    if (obj[0x70] & 8) {
        if (D_1F80004C.bytes[0x91] == 0 &&
            ((signed char*)obj)[0x5C] <= D_800D1CA2 / 2 &&
            (random_byte() & 1)) {
            obj[5] = 9;
        } else {
            obj[5] = 3;
        }
        obj[6] = 0;
    } else {
        apply_object_motion(obj);
    }
}
