#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern u8 D_800D1C00[];
extern s32 func_80044DE0();
extern void func_8002D9EC(Ent8EF0* obj, s32 a, s32 b);
extern s32 func_80016490(s32, s32, s32);
extern void func_8003D2C4(void);
extern void func_80017248(Ent8EF0*);
extern void func_8002DED4(Ent8EF0*);

void func_800F91D8_ovl28(Ent8EF0* obj) {
    u8* g = D_800D1C00;

    g[0x24] = 1;
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.unk26 = obj->unk94;
    D_8009A1F8.unk2A = D_8009A1F8.unk28;
    if (obj->unk5C < ((s8*)g)[0xA2]) {
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
