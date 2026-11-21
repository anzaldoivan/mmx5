#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"

void func_800F0C98_ovl00(u8* e) {
    if (*(s8*)(e + 4) == 1 && D_1F80004C.bytes[0x85] == 0) {
        *(s16*)(D_1F80004C.bytes + 0x96) = 0;
        if (--D_1F80004C.bytes[0x92] == 0xFF) {
            *(s32*)(D_1F80004C.bytes + 0x88) = 0;
            D_1F80004C.bytes[0x87] = 0;
            e[5] = 4;
            e[6] = 0;
            D_1F80004C.bytes[0x92] = 0x32;
        }
    }
}

void func_800F0D34_ovl00(Obj800F0D34* obj) {
    Obj800F0D34* s = func_8002D27C();

    if (s != 0) {
        s->unk0 = 0x41;
        s->unk1 = 5;
        s->unk2 = obj->unk2;
        s->unk40 = obj->unk40;
        s->unk42 = obj->unk42 & 0x7FFF;
        s->unk30 = obj->unk30;
        s->unk3C = obj->unk3C;
        s->unk14 = obj->unk14;
        s->unk8 = obj->unk8;
        s->unkC = obj->unkC;
        s->unk50 = obj;
        s->unk4 = 0;
    }
}
