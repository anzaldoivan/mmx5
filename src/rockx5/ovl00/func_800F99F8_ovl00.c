#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C0F;

void func_800F99F8_ovl00(u8* obj) {
    s8* child = *(s8**)(obj + 0x80);

    if (child[0] != 0) {
        if (child[7] == 0) {
            if (--*(s16*)(obj + 0x7E) == -1) {
                *(s16*)(obj + 0x7E) = 5;
                *(u16*)(obj + 0x42) ^= 0x8000;
            }
            func_8002D9EC(obj, 0xFF, 0xFF);
        }
    } else {
        D_800D1C0F = 0x10;
        clear_object_slot();
    }
}
