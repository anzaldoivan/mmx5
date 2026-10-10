#include "types.h"

typedef struct Obj8140 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x89];
    /* 0x90 */ u8 unk90;
} Obj8140;

extern void func_8002D9EC(Obj8140*, s32, s32);
extern void (*D_800FA1C4_ovl03[])(Obj8140*);

void func_800F8140_ovl03(Obj8140* e) {
    if (e->unk90 < 0x50) {
        e->unk90 = 0x64;
    }
    D_800FA1C4_ovl03[e->unk6](e);
    func_8002D9EC(e, 0x64, 0x64);
}
