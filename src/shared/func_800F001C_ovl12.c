/* Shared body (DK-5), from the banked draft of func_800F001C_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_800171E8(Obj001C*, s32);
extern s16 D_8009A0AA;
extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(Obj001C* obj) {
    if (obj->unk46 == 0) {
        if ((func_8002DF78() & 3) == 0) {
            func_80016490(2, 0x3D, obj);
            func_800171E8(obj, 8);
            if (D_8009A0AA > obj->unkA) {
                obj->unk15 = 0x40;
            } else {
                obj->unk15 = 0;
            }
            obj->unk7C = 0;
            obj->unk6++;
        } else {
            func_800171E8(obj, 1);
            obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
            obj->unk6 = 0;
        }
    }
}
