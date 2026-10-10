#include "types.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[0xA];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x34];
    u8 unk5C;
} Obj80050880;

extern Obj80050880* func_8002D0E4(void);
extern s32 func_8002DF78(void);
extern s32 D_8007B748[];
extern s32 D_8007B728[];

void func_80050880(u8 flags, s16 x0, s16 y0, s16 x1, s16 y1, s16 count) {
    Obj80050880* obj;
    u16 rx;
    u16 ry;
    s16 d;
    s16 i;

    for (i = 0; i < count; i++) {
        obj = func_8002D0E4();
        if (obj == 0) {
            continue;
        }
        obj->unk0 = 0x21;
        obj->unk1 = 9;
        obj->unk2 = 0;
        rx = (func_8002DF78() << 8) + func_8002DF78() + 1;
        ry = (func_8002DF78() << 8) + func_8002DF78() + 1;
        d = x1 - x0;
        if (d == 0) {
            obj->unkA = x0;
        } else {
            obj->unkA = x0 + rx % d;
        }
        d = y1 - y0;
        if (d == 0) {
            obj->unkE = y0;
        } else {
            obj->unkE = y0 + ry % d;
        }
        obj->unk8 = 0;
        obj->unkC = 0;
        switch (flags & 0xF) {
        case 1:
            obj->unk20 = D_8007B748[func_8002DF78() & 7] << 2;
            obj->unk24 = D_8007B728[func_8002DF78() & 3] << 2;
            break;
        case 2:
            obj->unk20 = -(D_8007B748[func_8002DF78() & 7] << 2);
            obj->unk24 = D_8007B728[func_8002DF78() & 3] << 2;
            break;
        case 4:
            obj->unk20 = -(D_8007B748[func_8002DF78() & 7] << 2);
            obj->unk24 = -(D_8007B728[func_8002DF78() & 3] << 2);
            break;
        case 8:
            obj->unk20 = D_8007B748[func_8002DF78() & 7] << 2;
            obj->unk24 = -(D_8007B728[func_8002DF78() & 3] << 2);
            break;
        default:
            obj->unk20 = 0;
            obj->unk24 = 0;
            break;
        }
        obj->unk15 = 0;
        obj->unk5C = flags >> 4;
        obj->unk4 = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
    }
}
