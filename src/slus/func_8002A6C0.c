/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029538.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:func_80027974, AGPL-3.0; proven shared with X6 by exact signature a09eb2b42e5f (see THIRD_PARTY.md). */
#include "types.h"
extern int func_8002A7E0();
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_8002A720(X4_BackgroundObj*);
void func_8002A770(X4_BackgroundObj*);
void func_8002A830(X4_BackgroundObj*);
void func_80029184(X4_BackgroundObj*);

void func_8002A6C0(X4_BackgroundObj* arg0) {
    s32 temp_a1;
    arg0->unk14.val = arg0->x_pos.val;
    temp_a1 = arg0->y_pos.val;
    arg0->unk18.val = temp_a1;
    M2C_FIELD(arg0, s8*, 0x49) = -M2C_FIELD(arg0, s8*, 0x48);
    func_8002A7E0(arg0);
    func_8002A720(arg0);
    func_8002A770(arg0);
    func_8002A830(arg0);
    func_80029184(arg0);
}
