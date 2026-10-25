/* W47 draft: unless D_800D1C2A[1] or o[0x46] is set, set state 0x3A (o[5]==2) or 0x3C and advance o[6] (rockx5 ovl04). */
#include "types.h"

extern u8 D_800D1C2A;
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800FDF84_ovl04(u8* o) {
    func_80017248(o);
    if (((s8*)&D_800D1C2A)[1] == 0 && ((s8*)o)[0x46] == 0) {
        if ((s8)o[5] == 2) {
            func_800171E8(o, 0x3A);
        } else {
            func_800171E8(o, 0x3C);
        }
        o[6]++;
    }
}
