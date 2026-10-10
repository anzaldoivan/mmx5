#include "types.h"

typedef struct {
    u8 pad0[6];
    signed char unk6;
    u8 pad7[0xA - 7];
    s16 unkA;
    u8 padC[0x15 - 0xC];
    u8 unk15;
} Ent59B0;

extern s16 D_8009A0AA;
extern void (*D_800FADFC_ovl09[])(Ent59B0*);
extern void func_8002D9EC(Ent59B0* obj, s32 a, s32 b);

void func_800F59B0_ovl09(Ent59B0* obj) {
    if (D_8009A0AA > obj->unkA) {
        obj->unk15 = 0x40;
    } else {
        obj->unk15 = 0;
    }
    D_800FADFC_ovl09[obj->unk6](obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
