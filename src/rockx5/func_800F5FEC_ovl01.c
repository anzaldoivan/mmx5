#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 D_800FD1DC_ovl01[];

void func_800F5FEC_ovl01(u8* obj) {
    s8 state;
    s16 t;

    func_80017248(obj);
    state = obj[7];
    if (state == 0) {
        t = *(s16*)(obj + 0x7C);
        if (t == 0) {
            func_800171E8(obj, 0x15);
            *(s16*)(obj + 0x7C) = 0x5A;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x87] = 2;
            obj[7]++;
            return;
        }
        if ((s16)(t % 90) == 0) {
            func_800171E8(obj, D_800FD1DC_ovl01[(s16)(t / 90)]);
        }
        *(s16*)(obj + 0x7C) -= 1;
    } else if (state == 1) {
        if (--*(s16*)(obj + 0x7C) == 0) {
            obj[4] = 6;
        }
    }
}
