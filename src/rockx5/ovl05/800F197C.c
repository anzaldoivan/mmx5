#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F197C_ovl05(Obj197C* o) {
    switch (o->state) {
    case 0:
    case 1:
    case 2:
        set_animation(o, 13);
        o->unk92 = 4;
        break;
    case 3:
    case 4:
    case 5:
        set_animation(o, 0);
        o->unk92 = 1;
        break;
    }
    o->unk91 = 2;
    play_sound(2, 0x18, o);
    o->step++;
}

void func_800F1A00_ovl05(Obj1A00* obj) {
    u8 t = obj->unk45;

    if (obj->unk45 == 2) {
        s8 s = obj->unk2;
        if (s >= 0) {
            if (s < 3) {
                set_animation(obj, 0xE);
                obj->unk88 = 0xE;
            } else if (s < 6) {
                set_animation(obj, 1);
                obj->unk88 = 0xB4;
            }
        }
        obj->unk6++;
        return;
    }
    obj->unk8D = -t;
    obj->unk8F = t;
}

void func_800F1A94_ovl05(u8* obj) {
    if (obj[0x90] != 0) {
        switch (*(signed char*)(obj + 2)) {
        case 0:
        case 1:
        case 2:
            set_animation(obj, 0xF);
            break;
        case 3:
        case 4:
        case 5:
            set_animation(obj, 2);
            break;
        }
        obj[6] = 4;
        *(s16*)(obj + 0x8A) = *(s16*)(obj + 0x88);
    } else if (--*(s16*)(obj + 0x88) == -1) {
        switch (*(signed char*)(obj + 2)) {
        case 0:
        case 1:
        case 2:
            set_animation(obj, 0xF);
            break;
        case 3:
        case 4:
        case 5:
            set_animation(obj, 2);
            break;
        }
        obj[6]++;
    }
    obj[0x8D] = -obj[0x45];
    obj[0x8F] = obj[0x45];
}

s32 func_800F1B8C_ovl05(Obj1B8C* e) {
    s32 ret;

    if (e->unk45 == 1) {
        if (e->unk90 != 0) {
            e->unk91 = 1;
            e->unk5 = 2;
            e->unk6 = 0;
            e->unk8A = e->unk88;
        } else if (--e->unk92 == 0) {
            e->unk91 = 1;
            e->unk5 = 2;
            e->unk6 = 0;
        } else {
            switch (e->unk2) {
            case 0:
            case 1:
            case 2:
                set_animation(e, 13);
                break;
            case 3:
            case 4:
            case 5:
                set_animation(e, 0);
                break;
            }
            ret = play_sound(2, 0x18, e);
            e->unk6 = 1;
            return ret;
        }
    } else {
        e->unk8D = -e->unk45;
        e->unk8F = e->unk45;
    }
}

void func_800F1C74_ovl05(u8* a0) {
    s8 s;
    u8 u;

    s = ((s8*)a0)[0x45];
    u = a0[0x45];
    if (s == 1) {
        a0[0x91] = s;
        a0[0x5] = 2;
        a0[0x6] = 0;
        return;
    }
    a0[0x8D] = -u;
    a0[0x8F] = u;
}
