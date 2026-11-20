#include "types.h"
#include "mmx5/graphics.h"

#include "addr.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;

void func_800FB9EC_ovl38(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        set_animation(a, 0);
        a->unk6++;
    }
}
