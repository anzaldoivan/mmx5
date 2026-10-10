#include "types.h"

extern void func_80017248(ObjFA284*);
extern void func_8002DED4(ObjFA284*);
extern s32 func_8002FB58(ObjFA284*);
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(ObjFA284*, s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800F9CF8_ovl06(ObjFA284* o) {
    func_80017248(o);
    func_8002DED4(o);
    func_8002FB58(o);
    if (o->flags70 & 8) {
        func_8001296C(5);
        func_80016490(2, 7, o);
        func_800171E8(o, 0x15);
        o->p50 = D_800FF1CC_ovl06;
        o->p54 = D_800FF1D0_ovl06;
        o->timer = 0x28;
        o->step++;
    }
}
