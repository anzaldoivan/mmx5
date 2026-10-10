/* Shared body (DK-5), from the banked draft of func_800F05DC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Obj05DC {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x15];
    /* 0x45 */ signed char unk45;
} Obj05DC;

extern s32 func_80016490(s32, s32, void*);
extern void func_80017248(Obj05DC*);
extern void func_8002DED4(Obj05DC*);
extern s16 D_8009A0AA;

void DEDUP_NAME(Obj05DC* obj) {
    s16 d;

    if (obj->unk45 == 1) {
        func_80016490(2, 0x35, obj);
        d = D_8009A0AA - obj->unkA;
        if (d < 0) {
            obj->unk15 = 0;
            obj->unk20 = (d << 16) / 40;
        } else {
            obj->unk15 = 0x40;
            obj->unk20 = (d << 16) / 40;
        }
        obj->unk24 = 0x30000;
        obj->unk2C = 0x1999;
        obj->unk6++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
