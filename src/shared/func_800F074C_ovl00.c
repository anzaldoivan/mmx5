#include "types.h"
#include "addr.h"
#include "mmx5/graphics.h"

void func_800F074C_ovl00(u8* a0) {
    u8* ctx = D_1F80004C.bytes;

    if (ctx[0x90] == 0) {
        switch (*(signed char*)(*(u8**)(ctx + 0x80) + 2)) {
        case 0:
        case 1:
            a0[6] = 1;
            break;
        case 2:
            a0[6] = 3;
            break;
        case 3:
            a0[6] = 5;
            break;
        }
    }
}

void func_800F07C0_ovl00(u8* obj) {
    u8* p;
    s8 st;

    if (D_1F80004C.bytes[0x90] == 0) {
        p = *(u8**)(D_1F80004C.bytes + 0x80);
        if (((s8*)p)[2] == 0 && (st = ((s8*)p)[5]) == 3) {
            set_animation(obj, 1);
            obj[5] = st;
            obj[6] = 0;
        } else {
            *(u16*)(obj + 0xA) =
                *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xA);
            {
                u8* q = *(u8**)(D_1F80004C.bytes + 0x80);
                *(u16*)(obj + 0xE) = *(u16*)(q + 0xE) + *(u16*)(q + 0x8A);
            }
            if ((*(u8**)(D_1F80004C.bytes + 0x80))[0x91] != 0) {
                obj[6] = 1;
            }
        }
    }
}

void func_800F08A8_ovl00(Self780* self) {
    Scr780* scr = D_1F80004C.scr780;

    if (scr->unk90 == 0) {
        self->unkA = scr->unk80->unkA - scr->unk80->unk8A;
        self->unkE = D_1F80004C.scr780->unk80->unkE;
        /* 0x91 lies past Pl780's proven fields */
        if (((u8*)D_1F80004C.scr780->unk80)[0x91] != 0) {
            self->unk6 = 3;
        }
    }
}

void func_800F0930_ovl00(Self780* self) {
    Scr780* scr = D_1F80004C.scr780;

    if (scr->unk90 == 0) {
        self->unkA = scr->unk80->unkA + scr->unk80->unk8A;
        self->unkE = D_1F80004C.scr780->unk80->unkE;
        /* 0x91 lies past Pl780's proven fields */
        if (((u8*)D_1F80004C.scr780->unk80)[0x91] != 0) {
            self->unk6 = 5;
        }
    }
}
