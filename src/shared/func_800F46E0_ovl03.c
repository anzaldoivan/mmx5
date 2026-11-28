#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/ovl03.h"
#include "mmx5/system.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F46E0_ovl03(Obj3DD4* obj) {
    s16 d;

    if (obj->unk20 < 0) {
        if (obj->unkA <= D_800FA240_ovl03) {
            obj->unkA = D_800FA240_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (obj->unk20 > 0) {
        if (obj->unkA >= D_800FA242_ovl03) {
            obj->unkA = D_800FA242_ovl03;
        clear:
            obj->unk20 = 0;
        }
    }
    if (obj->unkE <= D_800FA244_ovl03) {
        obj->unkE = D_800FA244_ovl03;
        obj->unk24 = 0;
    }
    if (obj->unk20 == 0 && obj->unk24 == 0) {
        set_animation(obj, 3);
        ((u8*)obj)[0x62] = 3;
        if (obj->unk15 == 0) {
            d = D_8009A0AA - D_800FA242_ovl03;
            if (d < 0x10 - (D_800FA242_ovl03 - D_800FA240_ovl03)) {
                d = 0x10 - (D_800FA242_ovl03 - D_800FA240_ovl03);
            }
            if (d >= -0xF) {
                d = -0x10;
            }
        } else {
            d = D_8009A0AA - D_800FA240_ovl03;
            if (D_800FA242_ovl03 - D_800FA240_ovl03 - 0x10 < d) {
                d = D_800FA242_ovl03 - D_800FA240_ovl03 - 0x10;
            }
            if (d < 0x10) {
                d = 0x10;
            }
        }
        obj->unk24 = 0xFFFA0000;
        *(s32*)((u8*)obj + 0x2C) = -0x2800;
        obj->unk7E = 0;
        obj->unk6++;
        obj->unk20 = (d << 16) / 40;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F48D4_ovl03(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    s16 d;

    if (*(s32*)(obj + 0x24) > 0 && *(s16*)(obj + 0x7E) == 0) {
        if (obj[0x15] == 0) {
            d = D_800FA240_ovl03 - *(s16*)(obj + 0xA);
        } else {
            d = D_800FA242_ovl03 - *(s16*)(obj + 0xA);
        }
        *(s16*)(obj + 0x7E) = 1;
        *(s32*)(obj + 0x20) = (d << 16) / 40;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x11, obj);
    }
    if (*(s32*)(obj + 0x24) > 0x10000) {
        set_animation(obj, 4);
        obj[0x62] = 0;
        obj[6]++;
    }
    if (obj[0x8D] == 0xFF) {
        p = g_Player;
        if (((s8*)p)[2] == 0) {
            set_animation(obj, 6);
        } else {
            set_animation(obj, 7);
        }
        obj[0x16] = 0;
        obj[0x62] = 0;
        q = g_Player;
        if (((s8*)q)[2] == 0) {
            q[0x15] = obj[0x15];
        } else if (obj[0x15] == 0) {
            q[0x15] = 0x40;
        } else {
            q[0x15] = 0;
        }
        r = g_Player;
        if (*(s16*)(r + 0xA) < D_800FA240_ovl03 ||
            D_800FA242_ovl03 < *(s16*)(r + 0xA)) {
            *(s16*)(r + 0xA) = *(s16*)(obj + 0xA);
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(r + 0xA);
        }
        t = g_Player;
        if (*(s16*)(t + 0xE) < D_800FA244_ovl03) {
            *(s16*)(t + 0xE) = *(s16*)(obj + 0xE);
        } else {
            *(s16*)(obj + 0xE) = *(s16*)(t + 0xE);
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6] += 2;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F4AF4_ovl03(u8* o) {
    if (*(s32*)(o + 0x20) < 0) {
        if (*(s16*)(o + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(o + 0xA) = D_800FA240_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    } else if (*(s32*)(o + 0x20) > 0) {
        if (*(s16*)(o + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(o + 0xA) = D_800FA242_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    }
    if (*(s16*)(o + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(o + 0xE) = D_800FA244_ovl03;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
    }
    if (*(s32*)(o + 0x20) == 0 && *(s32*)(o + 0x24) == 0) {
        set_animation(o, 1);
        o[5] = D_800FA0BC_ovl03[o[0x92]][o[0x93]++];
        o[6] = 0;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8003D010(s8 dmg);
extern void start_pad_vibration(s32);
extern s16 D_800FA248_ovl03;
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F4C10_ovl03(u8* obj) {
    u8* p;
    s16 x;
    s16 a;
    s32 y;

    p = g_Player;
    if (((s8*)p)[2] == 0) {
        p[0x15] = obj[0x15];
    } else if (obj[0x15] == 0) {
        p[0x15] = 0x40;
    } else {
        p[0x15] = 0;
    }
    if (++*(s16*)(obj + 0x7C) == 40) {
        if (*(s16*)(obj + 0x7E) == 4) {
            set_animation(obj, 1);
            obj[0x16] = 5;
            if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
                x = D_800FA240_ovl03 - 1;
            } else {
                x = D_800FA242_ovl03 + 1;
            }
            y = *(s16*)(obj + 0xE) + 1;
            a = ratan2(D_800FA244_ovl03 - y, x - *(s16*)(obj + 0xA));
            *(s32*)(obj + 0x20) = rcos(a) * 48;
            *(s32*)(obj + 0x24) = -rsin(a) * 48;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x50) = 0;
            *(s16*)(obj + 0x7C) = 0;
            obj[6]++;
            animate_object(obj);
            apply_object_motion(obj);
            return;
        }
        func_8003D010(1);
        start_pad_vibration(8);
        if (g_Player[0x5C] == 0x80) {
            set_animation(obj, 1);
        }
        {
            u8* q = g_playthrough_state.u;
            if (((s8*)obj)[0x5C] <= ((s8*)q)[0xA2] - 2) {
                obj[0x5C] += 2;
            } else {
                obj[0x5C] = q[0xA2];
            }
        }
        {
            u8* q = g_playthrough_state.u;
            if (((s8*)obj)[0x5C] > ((s8*)q)[0xA2]) {
                obj[0x5C] = q[0xA2];
            }
        }
        *(s16*)(obj + 0x7C) = 0;
        (*(s16*)(obj + 0x7E))++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern u8 D_800F9E68_ovl03[];
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F4E2C_ovl03(u8* obj) {
    u8* p;

    p = g_Player;
    if (*(s16*)(p + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    g_Player[0xCA] = 0;
    if ((s16)((s16)(*(u16*)(obj + 0x7C))++ % 40) == 0) {
        play_sound(2, 0x11, obj);
    }
    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 0;
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA242_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 1;
        }
    }
    if (*(s16*)(obj + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA244_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        *(u8**)(obj + 0x50) = D_800F9E68_ovl03;
        obj[5] = D_800FA0BC_ovl03[obj[0x92]][obj[0x93]++];
        obj[6] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA248_ovl03;
extern s16 D_800FA24E_ovl03;

void func_800F4FE0_ovl03(Obj4FE0* obj) {
    s16 x;
    s16 a;
    s32 e;

    set_animation(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
        obj->unk15 = 0x40;
    } else {
        x = D_800FA242_ovl03 + 1;
        obj->unk15 = 0;
    }
    e = obj->unkE - 1;
    a = ratan2(D_800FA24E_ovl03 - e, x - obj->unkA);
    obj->unk20 = rcos(a) * 48;
    obj->unk24 = -rsin(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA24E_ovl03;

void func_800F50E0_ovl03(u8* obj) {
    s32 v;
    s32 r;

    v = *(s32*)(obj + 0x20);
    if (v < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (v > 0 && *(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
        *(s16*)(obj + 0xA) = D_800FA242_ovl03;
    clear:
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s16*)(obj + 0xE) >= D_800FA24E_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA24E_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        r = random_byte() & 0xF;
        if (r < 5) {
            obj[7] = 0;
        } else {
            if (r < 0xC) {
                obj[7] = 3;
            } else if (r < 0xE) {
                obj[7] = 6;
            } else {
                obj[7] = 9;
            }
        }
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FA24C_ovl03;
extern s16 D_800FA24E_ovl03;

void func_800F51FC_ovl03(u8* obj) {
    s32 i;
    s8 state;
    u8* child;

    if (*(s32*)(obj + 0x24) > 0) {
        if (*(s16*)(obj + 0xE) <= D_800FA24C_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA24C_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (*(s32*)(obj + 0x24) < 0 &&
               *(s16*)(obj + 0xE) >= D_800FA24E_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA24E_ovl03;
    clear:
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x24) == 0) {
        state = obj[7];
        if (state == 0 || state == 3 || state == 6 || state == 9) {
            set_animation(obj, 8);
            for (i = 0; i < 3; i++) {
                child = func_8002D1A4();
                if (child != 0) {
                    child[0] = 0x61;
                    child[1] = 0x15;
                    child[2] = i;
                    *(u8**)(child + 0x7C) = obj;
                }
            }
        } else {
            set_animation(obj, 9);
            for (i = 0; i < 3; i++) {
                child = func_8002D1A4();
                if (child != 0) {
                    child[0] = 0x61;
                    child[1] = 0x15;
                    child[2] = i + 3;
                    *(u8**)(child + 0x7C) = obj;
                }
            }
        }
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F5384_ovl03(u8* obj) {
    s8 st = *(s8*)(obj + 7);
    u8 st2 = obj[7];

    if (st == 2 || st == 5 || st == 8 || st == 11) {
        if (++*(s16*)(obj + 0x7C) == 100) {
            set_animation(obj, 1);
            obj[5] = D_800FA0BC_ovl03[obj[0x92]][obj[0x93]++];
            obj[6] = 0;
        }
    } else if (st == 0 || st == 3 || st == 6 || st == 9) {
        if (++*(s16*)(obj + 0x7C) == 0x93) {
            obj[7]++;
            obj[6] -= 2;
        }
    } else {
        if (++*(s16*)(obj + 0x7C) == 100) {
            obj[7] = st2 + 1;
            obj[6] -= 2;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}
