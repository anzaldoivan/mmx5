#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F5DAC_ovl26(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        (*(u8**)(obj + 0x7C))[7] = 2;
        obj[6]++;
        *(s16*)(obj + 0x90) = (random_byte() & 0xF) + 1;
    }
}
