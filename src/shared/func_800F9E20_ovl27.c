/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80042214.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"

void func_800F9E20_ovl27(void* arg0) {
    if (--*(s16*)((u8*)arg0 + 0x7C) == 0) {
        clear_object_slot();
    }
}
