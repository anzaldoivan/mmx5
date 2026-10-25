/* Shared body (DK-5), from the banked draft of func_800F05DC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_80017248(Obj05DC*);
extern void func_8002DED4(Obj05DC*);
extern s16 D_8009A0AA;

void DEDUP_NAME(Obj05DC* obj) {
    s16 d;

    if (obj->unk45 == 1) {
        func_80016490(2, 0x35, obj);
        d = D_8009A0AA - obj->unkA;
        if (d < 0) {
            obj->unk15 = 0;
            obj->unk20 = (d << 16) / 40;
        } else {
            obj->unk15 = 0x40;
            obj->unk20 = (d << 16) / 40;
        }
        obj->unk24 = 0x30000;
        obj->unk2C = 0x1999;
        obj->unk6++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
