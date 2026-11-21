#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

extern s32 func_8002DFF8(void* arg0, s32 arg1, s32 arg2);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s16 D_800FB632_ovl09;
extern s16 D_800FB634_ovl09;

void func_800F3DBC_ovl09(u8* obj) {
    set_animation(obj, 0);
    if (D_8009A0AA <= D_800FB632_ovl09) {
        obj[0x15] = 0;
        func_8002E0F8(
            (s32*)(obj + 0x20), (s32*)(obj + 0x24),
            func_8002DFF8(obj, D_800FB630_ovl09 << 16, D_800FB634_ovl09 << 16));
    } else {
        obj[0x15] = 0x40;
        func_8002E0F8(
            (s32*)(obj + 0x20), (s32*)(obj + 0x24),
            func_8002DFF8(obj, D_800FB62E_ovl09 << 16, D_800FB634_ovl09 << 16));
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 3;
    *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 3;
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s16 D_800FB634_ovl09;

void func_800F3EB8_ovl09(u8* o) {
    s16 x;
    s16 t;

    if (o[0x15] == 0) {
        if (*(s32*)(o + 0x20) < 0) {
            if (*(s16*)(o + 0xA) <= D_800FB630_ovl09) {
                *(s16*)(o + 0xA) = D_800FB630_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        } else if (*(s32*)(o + 0x20) > 0) {
            if (*(s16*)(o + 0xA) >= D_800FB630_ovl09) {
                *(s16*)(o + 0xA) = D_800FB630_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        }
        if (*(s32*)(o + 0x24) > 0) {
            if (*(s16*)(o + 0xE) <= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        } else if (*(s32*)(o + 0x24) < 0) {
            if (*(s16*)(o + 0xE) >= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        }
        x = *(s16*)(o + 0xA);
        t = D_800FB630_ovl09;
    } else {
        if (*(s32*)(o + 0x20) < 0) {
            if (*(s16*)(o + 0xA) <= D_800FB62E_ovl09) {
                *(s16*)(o + 0xA) = D_800FB62E_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        } else if (*(s32*)(o + 0x20) > 0) {
            if (*(s16*)(o + 0xA) >= D_800FB62E_ovl09) {
                *(s16*)(o + 0xA) = D_800FB62E_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        }
        if (*(s32*)(o + 0x24) > 0) {
            if (*(s16*)(o + 0xE) <= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        } else if (*(s32*)(o + 0x24) < 0) {
            if (*(s16*)(o + 0xE) >= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        }
        x = *(s16*)(o + 0xA);
        t = D_800FB62E_ovl09;
    }
    if (x == t && *(s16*)(o + 0xE) == D_800FB634_ovl09) {
        set_animation(o, 8);
        *(s16*)(o + 0x7C) = 0;
        *(s16*)(o + 0x7E) = -1;
        o[6]++;
    }
    animate_object(o);
    apply_object_motion(o);
}

void func_800F40C8_ovl09(u8* obj) {
    s16 n;
    u8* child;

    n = *(s16*)(obj + 0x7E);
    if (n < 0) {
        if (++*(s16*)(obj + 0x7C) == 14) {
            *(s16*)(obj + 0x7C) = 0;
            *(s16*)(obj + 0x7E) = 0;
        }
    } else if (++*(s16*)(obj + 0x7C) == 20) {
        *(s16*)(obj + 0x7C) = 0;
        if (n < 8) {
            child = func_8002D1A4(n);
            if (child != 0) {
                play_sound(2, 0x82, obj);
                child[0] = 0x41;
                child[1] = 0x10;
                child[2] = obj[0x7E] + 6;
                *(u8**)(child + 0x7C) = obj;
            }
        }
        if (++*(s16*)(obj + 0x7E) == 9) {
            set_animation(obj, 0);
        }
    }
    if (*(s16*)(obj + 0x7E) == 10) {
        if (obj[0x15] == 0) {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0xFFFA0000;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = 0x60000;
        }
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;

void func_800F4218_ovl09(u8* obj) {
    s16 cur;
    s16 lim;
    s32 v;

    if (obj[0x15] == 0) {
        v = *(s32*)(obj + 0x20);
        if (v < 0) {
            if (*(s16*)(obj + 0xA) <= D_800FB630_ovl09) {
                *(s16*)(obj + 0xA) = D_800FB630_ovl09;
                goto clear0; // !FAKE: goto kept for the matching branch layout
            }
        } else if (v > 0 && *(s16*)(obj + 0xA) >= D_800FB630_ovl09) {
            *(s16*)(obj + 0xA) = D_800FB630_ovl09;
        clear0:
            *(s32*)(obj + 0x20) = 0;
        }
        cur = *(s16*)(obj + 0xA);
        lim = D_800FB630_ovl09;
    } else {
        v = *(s32*)(obj + 0x20);
        if (v < 0) {
            if (*(s16*)(obj + 0xA) <= D_800FB62E_ovl09) {
                *(s16*)(obj + 0xA) = D_800FB62E_ovl09;
                goto clear1; // !FAKE: goto kept for the matching branch layout
            }
        } else if (v > 0 && *(s16*)(obj + 0xA) >= D_800FB62E_ovl09) {
            *(s16*)(obj + 0xA) = D_800FB62E_ovl09;
        clear1:
            *(s32*)(obj + 0x20) = 0;
        }
        cur = *(s16*)(obj + 0xA);
        lim = D_800FB62E_ovl09;
    }
    if (cur == lim) {
        set_animation(obj, 8);
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
