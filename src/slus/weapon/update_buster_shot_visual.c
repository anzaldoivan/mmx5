/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80049478.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004F1FC(X4_Obj*);         /* extern */
M2C_UNK func_8004F6DC(void*, void*); /* extern */
extern s8 D_8009A0A5;

void update_buster_shot_visual(void* arg0) {
    if (D_8009A0A5 == 0x14) {
        clear_object_slot(arg0, arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        ((void (*)())func_8004F1FC)(arg0, arg0);
        return;
    }
    func_8004F6DC(arg0, arg0);
}
