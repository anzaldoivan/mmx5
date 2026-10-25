#include "types.h"

extern void func_80017248(EntBD40*);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8003D2C4(void);
extern signed char D_800D1CA2;

void func_800FBD40_ovl38(EntBD40* obj) {
    func_80017248(obj);
    if (--obj->unk7C == 0) {
        func_80016490(0, 0xE, 0);
        obj->unk7C = 2;
    }
    if (++obj->unk5C >= D_800D1CA2) {
        func_8003D2C4();
        obj->unk6++;
    }
}
