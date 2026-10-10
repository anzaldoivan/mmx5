#include "types.h"

typedef struct Ent62C8 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x8D];
    /* 0x94 */ u8 unk94;
} Ent62C8;

extern void func_8002D9EC(Ent62C8*, s32, s32);
extern void (*D_800FAE64_ovl09[])(Ent62C8*);

void func_800F62C8_ovl09(Ent62C8* e) {
    if (e->unk94 < 0x50) {
        e->unk94 = 0x64;
    }
    D_800FAE64_ovl09[e->unk6](e);
    func_8002D9EC(e, 0x64, 0x64);
}
