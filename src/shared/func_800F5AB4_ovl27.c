#include "types.h"
#include "mmx5/system.h"
#include "addr.h"
#include "mmx5/globals.h"

extern s32 rsin(s32);

// advance the scratchpad state's phase by a random step, set y from its sine
void func_800F5AB4_ovl27(u8* e) {
    s32 t;
    s32 r;

    t = rsin(D_1F80004C.scr5308->unk84) << 7;
    r = (random_byte() & 0x1F) + 0x10;
    D_1F80004C.scr5308->unk84 += r;
    D_1F80004C.scr5308->unk84 &= 0xFFF;
    *(s32*)(e + 0xC) = D_1F80004C.scr5308->unk80 + t;
}

void func_800F5B44_ovl27(ObjF5B44* arg0, s32 a1) {
    u8 arg1 = a1;
    ObjF5B44* obj = func_8002D1A4();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x26;
        obj->unk7C = arg0;
        obj->unk15 = arg0->unk15;
        obj->unk2 = arg1;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk14 = arg0->unk14;
        if (arg1 == 0) {
            if (arg0->unk15 == 0) {
                obj->unkA = arg0->unkA - 0x2B;
            } else {
                obj->unkA = arg0->unkA + 0x2B;
            }
            obj->unkE = arg0->unkE;
        } else {
            if (arg0->unk15 == 0) {
                obj->unkA = arg0->unkA - 0x2C;
            } else {
                obj->unkA = arg0->unkA + 0x2C;
            }
            obj->unkE = arg0->unkE + 0x19;
        }
        obj->unk8 = 0;
        obj->unkC = 0;
    }
}
