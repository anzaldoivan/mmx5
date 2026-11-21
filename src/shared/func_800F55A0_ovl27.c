#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F5C58_ovl27(Obj5524*);

void func_800F55A0_ovl27(Obj5524* obj) {
    u8* sp;

    if (--obj->timer7E == 0) {
        obj->timer7E = 0x28;
        func_800F5C58_ovl27(obj);
    }
    if (--obj->timer7C == 0) {
        sp = D_1F80004C.bytes;
        if (sp[0x87] == 0) {
            func_800F59D8_ovl27(obj);
        } else {
            sp[0x86] = 0;
            set_animation(obj, 1);
            obj->state6++;
        }
    }
}

void func_800F5648_ovl27(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        D_1F80004C.bytes[0x87] = 0;
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
