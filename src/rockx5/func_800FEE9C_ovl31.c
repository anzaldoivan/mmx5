#include "types.h"

extern Tbl7EB0 D_800FA004_ovl31;

extern void func_80017248(Ent7EB0* obj);
extern void func_8002DED4(Ent7EB0* obj);

void func_800FEE9C_ovl31(Ent7EB0* obj) {
    Tbl7EB0 tbl = D_800FA004_ovl31;

    if (tbl.b[obj->unk7] != 0) {
        obj->unk24 = 0x30000;
    } else {
        obj->unk24 = -0x30000;
    }
    obj->unk6++;
    func_80017248(obj);
    func_8002DED4(obj);
}
