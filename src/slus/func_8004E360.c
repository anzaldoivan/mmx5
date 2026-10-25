#include "types.h"

extern int func_8002D6FC();
extern s32 func_80017248(Obj8004E360*);
extern void func_800171E8(Obj8004E360*, s32);
extern void func_8002D89C(Obj8004E360*);
extern u8 D_800C9320;
extern u8 D_80091C38[];

void func_8004E360(Obj8004E360* o) {
    u8 s1;

    switch (o->unk2) {
    case 1:
        if (D_800C9320 != 0) {
            func_8002D6FC(o);
            break;
        }
        if (--o->unk56 == 0) {
            o->unk56 = 0x20;
            o->unk54 ^= 1;
        }
        if (o->unk54 != 0) {
            o->unk3 = 0;
            break;
        }
        func_8002D89C(o);
        break;
    case 2:
        if (D_80091C38[0xC] == 0) {
            func_8002D6FC(o);
            break;
        }
        if (D_80091C38[0xD] == 0 || D_80091C38[0xD] == 4) {
            func_80017248(o);
        }
        func_8002D89C(o);
        break;
    case 3:
        if (o->unk50[D_80091C38[0xE]] != 0 && (s1 = D_80091C38[0xC]) == 1) {
            if (o->unk55 == 0) {
                func_800171E8(o, 1);
                o->unk55 = s1;
            } else {
                func_80017248(o);
                if (o->unk45 != 0) {
                    o->unk55 = 0;
                }
            }
        } else if (o->unk55 != 0) {
            func_80017248(o);
            if (o->unk45 != 0) {
                o->unk55 = 0;
                func_800171E8(o, 0);
            }
        } else {
            func_800171E8(o, 0);
        }
        func_8002D89C(o);
        break;
    case 4:
        func_80017248(o);
        func_8002D89C(o);
        break;
    case 5:
        if (o->unk50[D_80091C38[0xE]] == 0 && (s1 = D_80091C38[0xC]) == 1) {
            if (o->unk55 == 0) {
                func_800171E8(o, o->unk54 + 1);
                o->unk55 = s1;
            } else {
                func_80017248(o);
                if (o->unk45 != 0) {
                    o->unk55 = 0;
                }
            }
        } else if (o->unk55 != 0) {
            func_80017248(o);
            if (o->unk45 != 0) {
                o->unk55 = 0;
                func_800171E8(o, o->unk54);
            }
        } else {
            func_800171E8(o, o->unk54);
        }
        func_8002D89C(o);
        break;
    case 6:
    case 7:
        break;
    case 8:
        if (o->unk5 == 0) {
            func_80017248(o);
            if (--*(s8*)&o->unk56 == 0) {
                o->unk5 = 1;
            }
            if (o->unk6 != 0) {
                o->unk8 = *(s32*)(o->unk50 + 8);
                o->unkC = *(s32*)(o->unk50 + 0xC);
            }
        case 0: /* shared update tail; the dead arm stays after it, as in the target */
            func_8002D89C(o);
            break;
        }
        o->unk3 = 0;
        func_8002D6FC(o);
        break;
    }
}
