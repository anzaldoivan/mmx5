#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/graphics.h"

void func_800F9BCC_ovl06(Obj8AA8* obj) {
    func_800FAEF8_ovl06(obj);
    set_animation(obj, 0x13);
    obj->unk50 = D_800FF1DC_ovl06.w;
    obj->unk54 = D_800FF1E0_ovl06.w;
    if (obj->unk15 == 0) {
        obj->unk20 = 0xFFFDE9BE;
    } else {
        obj->unk20 = 0x21642;
    }
    obj->unk28 = 0;
    obj->unk24 = 0x85502;
    obj->unk2C = 0x5CBD;
    obj->unk6++;
}
