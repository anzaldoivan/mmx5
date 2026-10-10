#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern signed char D_800D1CA2;
extern s32 func_80044DE0();
extern void func_8002D9EC(Ent8EF0* obj, s32 a, s32 b);
extern s32 func_80016490(s32, s32, s32);
extern void func_8003D2C4(void);
extern void func_80017248(Ent8EF0*);
extern void func_8002DED4(Ent8EF0*);

void func_800F8EF0_ovl28(Ent8EF0* obj) {
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.unk26 = obj->unk94;
    D_8009A1F8.unk2A = D_8009A1F8.unk28;
    if (obj->unk5C < D_800D1CA2) {
        if (--obj->unk7C == 0) {
            func_80016490(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.unk48 = 8;
    func_8003D2C4();
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    obj->unk5 = 3;
    obj->unk6 = 0;
}
