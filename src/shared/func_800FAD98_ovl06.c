/* Shared body (DK-5), from the banked draft of func_800FAD98_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(Ent08D8*);
extern s32 func_8002FB58(Ent08D8*);
extern void func_80017248(Ent08D8*);
extern void func_8001296C(s32);
extern s32 func_80016490(s32, s32, void*);

void DEDUP_NAME(Ent08D8* obj) {
    func_8002DED4(obj);
    func_8002FB58(obj);
    func_80017248(obj);
    if (obj->unk70 & 8) {
        func_8001296C(5);
        func_80016490(2, 7, obj);
        obj->unk24 = 0x30000;
        obj->unk2C = 0x1000;
        obj->unk6 = obj->unk6 + 1;
    }
}
