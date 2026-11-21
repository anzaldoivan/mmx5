#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F17EC_ovl26(Obj17EC* arg0) {
    s32 d;

    move_object(arg0);
    if ((((d = D_8009A0AA - arg0->unkA) >= 0)
             ? (d < 5)
             : ((arg0->unkA - D_8009A0AA) < 5)) ||
        !((((d = *(s16*)(D_1F80004C.bytes + 0x82) - arg0->unkA) >= 0)
               ? (d < 0xA0)
               : ((arg0->unkA - *(s16*)(D_1F80004C.bytes + 0x82)) < 0xA0)))) {
        set_animation(arg0, 2);
        arg0->unk54 = 0;
        arg0->unk50 = 0;
        arg0->unk7C = 0;
        arg0->unk6++;
    }
}
