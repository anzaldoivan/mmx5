#include "types.h"

extern Obj80050880* func_8002D0E4(void);
extern s32 func_8002DF78(void);

void func_8005019C(u8 flags, u8 mode, u8* ent, s16 off, s16 count) {
    Obj80050880* obj;
    u8* box;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    u16 rx;
    u16 ry;
    s16 d;
    s16 i;

    box = *(u8**)(ent + 0x68);
    x0 = *(s16*)(ent + 0xA);
    x1 = x0;
    y0 = *(u16*)(ent + 0xE) + (s8)box[1];
    y1 = y0;
    switch (mode) {
    case 1:
        if (ent[0x15] == 0) {
            x0 = x0 + (s8)box[0];
            x0 = x0 - box[2];
            x1 = x0 + box[2] * 2;
        } else {
            x1 = x0 - (s8)box[0];
            x1 = box[2] + x1;
            x0 = x1 - box[2] * 2;
        }
        y0 = y0 - box[3];
        y1 = y0;
        break;
    case 2:
        if (ent[0x15] == 0) {
            x0 = x0 + (s8)box[0];
            x0 = x0 - box[2];
            x1 = x0 + box[2] * 2;
        } else {
            x1 = x0 - (s8)box[0];
            x1 = box[2] + x1;
            x0 = x1 - box[2] * 2;
        }
        y0 = box[3] + y0;
        y1 = y0;
        break;
    case 3:
        if (ent[0x15] == 0) {
            x0 = x0 + (s8)box[0];
            x1 = x0 = x0 - box[2];
        } else {
            x1 = x0 - (s8)box[0];
            x1 = x0 = box[2] + x1;
        }
        y0 = y0 - box[3];
        y1 = box[3] + y1;
        break;
    case 4:
        if (ent[0x15] == 0) {
            x0 = x0 + (s8)box[0];
            x1 = x0 = box[2] + x0;
        } else {
            x1 = x0 - (s8)box[0];
            x1 = x0 = x1 - box[2];
        }
        y0 = y0 - box[3];
        y1 = box[3] + y1;
        break;
    }
    x0 = x0 - off;
    x1 = x1 + off;
    y0 = y0 - off;
    y1 = y1 + off;

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
        switch (flags & 3) {
        case 1:
            obj->unk20 = 0;
            obj->unk24 = 0x10000;
            break;
        case 2:
            if (obj->unkA < *(s16*)(ent + 0xA)) {
                obj->unk20 = -0x18000;
                obj->unk24 = 0;
            } else {
                obj->unk20 = 0x18000;
                obj->unk24 = 0;
            }
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
