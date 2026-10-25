#include "types.h"

extern u8 D_8009A197;
extern u8 D_800FCF80_ovl01[];
extern void (*D_800FD244_ovl01[])(Obj6298*);
extern s32 func_800317B8(Obj6298*);
extern s32 func_80031DD0(Obj6298*);
extern s32 func_8004FD24(Obj6298*);
extern void func_8004D4F4(s32 a0, void* a1, Obj6298* a2);
extern void func_8002D9EC(Obj6298*, s32, s32);
extern void func_800F6BDC_ovl01(Obj6298*);

void func_800F6298_ovl01(Obj6298* obj) {
    if (D_8009A197 == 0) {
        obj->unk18 = obj->x_pos;
        obj->unk1C = obj->y_pos;
        D_800FD244_ovl01[obj->unk5](obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(2, D_800FCF80_ovl01, obj);
        obj->unk3 = 0;
        obj->unk7C = 0xF;
        obj->unk7E = 5;
        obj->state = 7;
    } else {
        func_8002D9EC(obj, 0x40, 0x20);
        func_800F6BDC_ovl01(obj);
    }
}
