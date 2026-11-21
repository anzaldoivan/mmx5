#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s8 D_8009A0FC;

void func_800F0414_ovl06(u8* obj) {
    s32 press;
    s32 hit;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        set_animation(obj, 7);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x30;
            g_Player[6] = 0;
        }
    }
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (!(*(u16*)(obj + 0x8A) & 0x80)) {
            goto zero; // !FAKE: goto kept for the matching branch layout
        }
        hit = 1;
    } else if (D_8009A0FC == -0x80) {
        hit = 1;
    } else {
    zero:
        hit = 0;
    }
    if (hit) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (((s8*)obj)[0x46] == 0) {
            obj[5] = 1;
            obj[6] = 0;
        } else if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 4;
            obj[6] = 0;
        } else {
            if (*(u16*)(obj + 0x8A) & 0x30) {
                press = 1;
                if (((s8*)obj)[2] != 0) {
                    press = obj[0x7E] == 0;
                }
            } else {
                press = 0;
            }
            if (press || (*(u16*)(obj + 0x88) & 3)) {
                obj[5] = 3;
                obj[6] = 0;
            }
        }
        animate_object(obj);
        return;
    }
    animate_object(obj);
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8* func_8002D078();

void func_800F0568_ovl06(u8* obj) {
    u8* child;
    u8* g;
    u8 st;
    s32 t;
    u8 f;
    u16 h;
    u16 v;
    s32 mask;
    s32 m1;
    s8 s6;

    if (!(D_8009A420_as_s32 & 3) && (random_byte() & 1)) {
        random_byte();
    }
    s6 = *(s8*)(obj + 6);
    if (s6 == 0) {
        obj[6] = s6 + 1;
        child = func_8002D078();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x3E;
            child[2] = 1;
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            child[0x16] = obj[0x16];
            *(u8**)(child + 0x7C) = obj;
            child[0x15] = obj[0x15];
        }
        set_animation(obj, 9);
        if (obj[0x8D] == 0) {
            g = g_Player;
            g[0xD8] = 0x37;
            g[6] = 0;
        }
        play_sound(5, 0xB, 0);
    }
    st = obj[0xA8];
    t = obj[0x90] - 1;
    obj[0x90] = t;
    if (!(st & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    f = obj[0x97];
    if (!(f & 2)) {
        if ((st & 3) || (obj[0x45] & 1)) {
            if ((s8)t < 0) {
                obj[5] = 8;
                obj[6] = 0;
            } else {
                goto add; // !FAKE: goto kept for the matching branch layout
            }
        } else {
            if (!(f & 8)) {
                m1 = 2;
                if (obj[0x15] != 0) {
                    m1 = 1;
                }
                v = *(u16*)(obj + 0x88) & m1;
            } else {
                mask = 2;
                if (obj[0x15] != 0) {
                    mask = 1;
                }
                h = *(u16*)(obj + 0x88);
                if (h & mask) {
                    goto add; // !FAKE: goto kept for the matching branch layout
                }
                v = h & 0x100;
            }
            if (v != 0) {
            add:
                *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            }
        }
        animate_object(obj);
        return;
    }
    animate_object(obj);
}
#undef D_8009A420_as_s32

extern void silence_sound(s32, s32);
extern void func_8003CD08(u8* obj);
extern u8 D_800FDE88_ovl06[];

void func_800F0784_ovl06(u8* obj) {
    u8 f;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x61] = 1;
        *(u8**)(obj + 0x68) = D_800FDE88_ovl06;
        obj[0x8C] = 0;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        silence_sound(5, 8);
        if (!(obj[0x97] & 2)) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0x20000;
            *(s32*)(obj + 0x2C) = 0x4000;
        }
        f = obj[0x97];
        if (f & 0x40) {
            if (!(f & 2)) {
                *(s32*)(obj + 0x24) = 0;
                *(s32*)(obj + 0x2C) = 0;
            }
            g_Player[0xD5] = 0;
            obj[0x97] ^= 0x40;
            func_8003CD08(g_Player);
        }
        if (!(obj[0xA8] & 8)) {
            obj[5] = 0xC;
            obj[6] = 0;
        } else {
            set_animation(obj, 0x13);
        }
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    if (obj[0xA8] & 8) {
        *(s32*)(obj + 0x24) = 0;
    }
    if (((s8*)obj)[0x46] == 0) {
        obj[6] = 0;
        obj[5] = 0;
        silence_sound(5, 8);
        obj[0x8C] = 0;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
    }
    if (!(obj[0x97] & 2)) {
        apply_object_motion(obj);
    }
    animate_object(obj);
}

extern s8 D_8009A0FC;

static inline s32 func_800F08EC_ovl06_hit(u8* obj) {
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            return 1;
        }
    } else {
        if (D_8009A0FC == -0x80) {
            return 1;
        }
    }
    return 0;
}

void func_800F08EC_ovl06(u8* obj) {
    u8 flags;
    u8 t;
    s32 x;
    u16 t2;
    s32 hit;
    s32 press;
    s32 dir;
    s32 vx;
    u16 pad;
    u16 sides;

    if (*(s8*)(obj + 6) == 0) {
        *(s8*)(obj + 6) = 1;
        *(s32*)(obj + 0x2C) = 0x4200;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        obj[0x96] = 0x28;
        obj[0x67] = 1;
        if (obj[0x97] & 0x40) {
            if (obj[0x8D] == 0) {
                g_Player[0xD8] = 0x2C;
                g_Player[6] = 0;
            }
        }
        set_animation(obj, 3);
    }
    t = obj[0x97];
    x = t & 0x40;
    flags = t;
    if (x) {
        hit = func_800F08EC_ovl06_hit(obj);
        if (hit) {
            obj[5] = 0xB;
            *(s8*)(obj + 6) = 0;
            return;
        }
    }
    t = 0; // !FAKE: dead reset ends the cse copy equivalence so flags keeps its own register (C0070)
    if (obj[0xA8] & 8) {
        if (flags & 0x40) {
            obj[5] = 5;
        } else {
            obj[0x67] = 0;
            obj[5] = 0xB;
        }
        *(s8*)(obj + 6) = 0;
        return;
    }
    if (flags & 2) {
        return;
    }
    if (flags & 0x40) {
        t2 = *(u16*)(obj + 0x8A);
        x = t2 & 0x30;
        pad = t2;
        if (x) {
            press = 1;
            if (*(s8*)(obj + 2) != 0) {
                press = obj[0x7E] == 0;
            }
        } else {
            press = 0;
        }
        t2 =
            0; // !FAKE: dead reset ends the cse copy equivalence so pad keeps its own register (C0070)
        if (press) {
            obj[5] = 6;
            *(s8*)(obj + 6) = 0;
            return;
        }
        if (*(s8*)(obj + 2) != 0 && obj[0x7D] == 0 && (pad & 0x80)) {
            obj[5] = 0xE;
            *(s8*)(obj + 6) = 0;
            return;
        }
        sides = *(u16*)(obj + 0x88);
        *(s32*)(obj + 0x20) = 0;
        if (sides & 2) {
            obj[0x15] = 0;
            dir = 1;
        } else if (sides & 1) {
            obj[0x15] = 0x40;
            dir = 1;
        } else {
            dir = 0;
        }
        if (dir) {
            vx = *(s16*)(obj + 0x98) << 8;
            if (obj[0x15] == 0) {
                vx = -vx;
            }
            *(s32*)(obj + 0x20) = vx;
        }
        if (*(s32*)(obj + 0x24) < -0x5E000) {
            *(s32*)(obj + 0x24) = -0x5E000;
        }
        apply_object_motion(obj);
    } else {
        apply_object_motion(obj);
    }
}
