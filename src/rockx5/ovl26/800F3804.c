#include "types.h"
#include "mmx5/ovl26.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F3804_ovl26(Ent3804* o) {
    animate_object(o);
    if (o->unk2 < 8) {
        move_object(o);
        if (o->unk20 < 0) {
            if (o->unkA <= 0x910 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi) {
                o->unkA = 0x910 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi;
                set_animation(o, 0);
                o->unk6++;
            }
        } else if (o->unkA >=
                   D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0xA10) {
            o->unkA = D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0xA10;
            set_animation(o, 0);
            o->unk6++;
        }
    } else {
        o->unk6++;
    }
}

extern Tbl800EE9A8 D_800EE9A8_ovl26;
extern Tbl800EE9A8 D_800EE9D8_ovl26;

void func_800F38F4_ovl26(u8* obj) {
    Tbl800EE9A8 a;
    Tbl800EE9A8 b;
    s8 v;

    a = D_800EE9A8_ovl26;
    b = D_800EE9D8_ovl26;
    animate_object(obj);
    if (((s8*)*(u8**)(obj + 0x7C))[7] == 0) {
        if ((*(u8**)(obj + 0x7C))[0x96] == 0) {
            v = ((s8*)obj)[2];
            if (v < 8) {
                obj[2] = a.b[obj[0x94] - 3][v];
            }
        } else {
            v = ((s8*)obj)[2];
            if (v < 8) {
                obj[2] = b.b[obj[0x94] - 3][v];
            }
        }
        obj[6]++;
    }
}

void func_800F3B10_ovl26(Ent3804* o) {
    animate_object(o);
    move_object(o);
    if ((*(u8**)((u8*)o + 0x7C))[0x96] == 0) {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0x910) {
                o->unkA = D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0x910;
                set_animation(o, 0);
                o->unk6++;
            }
        } else {
            if (o->unkA >= 0xA50 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi) {
                o->unkA = 0xA50 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi;
                set_animation(o, 0);
                o->unk6++;
            }
        }
    } else if (o->unk20 < 0) {
        if (o->unkA <= D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0x8D0) {
            o->unkA = D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0x8D0;
            set_animation(o, 0);
            o->unk6++;
        }
    } else {
        if (o->unkA >= 0xA10 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi) {
            o->unkA = 0xA10 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi;
            set_animation(o, 0);
            o->unk6++;
        }
    }
}

void func_800F3C64_ovl26(Ent3804* o) {
    animate_object(o);
    if (o->unk2 < 8) {
        move_object(o);
        if (o->unk20 < 0) {
            if (o->unkA <= 0x950 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi) {
                o->unkA = 0x950 - D_800F9F24_ovl26.p[o->unk94][o->unk2].hi;
                set_animation(o, 0);
                o->unk6++;
            }
        } else if (o->unkA >=
                   D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0x9D0) {
            o->unkA = D_800F9F24_ovl26.p[o->unk94][o->unk2].hi + 0x9D0;
            set_animation(o, 0);
            o->unk6++;
        }
    } else {
        o->unk6++;
    }
}
