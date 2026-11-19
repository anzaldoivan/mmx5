/* Shared body (DK-5), from the banked draft of func_800EFC00_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern u8 D_800FA870_ovl00[];
extern void (*D_800FA8A8_ovl00[])(X4_Obj*);
extern void func_800F0C28_ovl00(X4_Obj*);
extern void func_8004D4F4(s32 a0, void* a1, X4_Obj* a2);

void DEDUP_NAME(X4_Obj* obj) {
    if (D_8009A197 == 0) {
        animate_object(obj);
        obj->unk18 = obj->x_pos;
        obj->unk1C = obj->y_pos;
        D_800FA8A8_ovl00[obj->unk5](obj);
    }
    func_800F0C28_ovl00(obj);
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(1, D_800FA870_ovl00, obj);
        if (obj->unk5 == 4) {
            obj->state = 5;
        } else {
            obj->state = 4;
        }
    } else {
        func_8002D9EC(obj, 0x20, 0x20);
        func_8002FB58(obj);
    }
}
