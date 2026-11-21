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

void func_800F5E14_ovl26(u8* obj) {
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
        return;
    }
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
    }
}

void func_800F5E78_ovl26(u8* obj) {
    s8 state;

    animate_object(obj);
    state = obj[0x45];
    if (state == 2) {
        obj[4] = state;
    }
}
