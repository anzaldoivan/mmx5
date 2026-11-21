#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F9630_ovl09(Obj9630* obj) {
    s32 t;
    u16 e;
    u8 three = 3;
    u8 one;

    do { // !FAKE: fences cse of the incoming a0
        t = obj->unk2;
    } while (0);
    one = 1;
    obj->unk16 = three;
    obj->unk5C = 0;
    obj->unk20 = 0;
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk67 = one;
    obj->unk60 = 4;
    obj->unk68 = 0;
    obj->unk50 = 0;
    if (t == 0) {
        set_animation(obj, 2);
        if (obj->unk15 == 0) {
            obj->unkA -= 0xA;
        } else {
            obj->unkA += 0xA;
        }
    } else {
        set_animation(obj, 0xB);
        if (obj->unk15 == 0) {
            obj->unkA -= 0x10A;
        } else {
            obj->unkA += 0x10A;
        }
    }
    do {
        e = obj->unkE - 6;
    } while (0); // !FAKE: fences the sched2 delay-slot fill
    obj->unkE = e;
    obj->unk54 = 0;
    obj->unk5 = 0;
    obj->unk4 = 1;
    obj->unk6 = 0;
    obj->unk7 = 0;
    obj->unk3 = 1;
}

extern void (*D_800FB5BC_ovl09[])(u8* obj);

void func_800F9724_ovl09(u8* obj) {
    if (((signed char*)*(u8**)(obj + 0x7C))[4] != 3) {
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    animate_object(obj);
    D_800FB5BC_ovl09[(signed char)obj[5]](obj);
    func_800317B8(obj);
}

#define D_800EEBA0_ovl00 func_800F979C_ovl09
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
