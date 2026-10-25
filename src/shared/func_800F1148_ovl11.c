/* Shared body (DK-5), from the banked draft of func_800F1148_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj1148* DEDUP_CALLEE();
extern u8 D_800F9854_ovl11[];

void DEDUP_NAME(Obj1148* arg0) {
    Obj1148* obj;
    u8 i;

    for (i = 0; i < 2; i++) {
        obj = DEDUP_CALLEE();
        if (obj != 0) {
            obj->unk0 = 0x41;
            obj->unk1 = 0x1E;
            if (i == 0) {
                obj->unk2 = 0;
            } else {
                obj->unk2 = 2;
            }
            obj->unk7C = arg0;
            obj->unk42 = arg0->unk42;
            obj->unk30 = D_800F9854_ovl11;
            obj->unk3C = arg0->unk3C;
            obj->unk40 = arg0->unk40;
            obj->unk15 = arg0->unk15;
            obj->unk14 = arg0->unk14;
            obj->unk16 = 4;
        }
    }
}
