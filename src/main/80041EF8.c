#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/weapon.h"
#include "mmx5/system.h"

extern u8* find_free_visual_obj(void);
extern u8* func_8002D078();
extern s32 player_check_dash_jump_walk(u8* arg0);
extern void func_800444B4(u8* a0);

void func_80041EF8(u8* obj) {
    u8* p;
    u8* q;
    s8 t;

    if (*(s8*)(obj + 6) == 0) {
        q = find_free_visual_obj();
        if (q != 0) {
            q[0] = 1;
            q[1] = 3;
            q[2] = 0xE;
            q[0x14] = obj[0x14];
            *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
            *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(q + 0x42) = 0x7802;
            q[0x16] = 0;
            *(s32*)(q + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(q + 0xC) = *(s32*)(obj + 0xC);
            q[0x15] = obj[0x15];
        }
        obj[6]++;
    } else if (*(s8*)(obj + 6) == 1) {
        animate_object(obj);
        if (*(s8*)(obj + 0x45) & 0x80) {
            p = func_8002D078();
            if (p != 0) {
                p[0] = 0x21;
                p[1] = 0x3A;
                p[0x14] = obj[0x14];
                p[0x15] = obj[0x15];
            }
            obj[6]++;
            play_sound(1, 0xE, obj);
        }
    } else {
        t = *(s8*)(obj + 0x45);
        if (t == 1 && *(s8*)(obj + 0xD3) == 0) {
            obj[0x8E] = 0;
            if (player_check_dash_jump_walk(obj) != 0) {
                return;
            }
            obj[0x8E] = t;
        }
        animate_object(obj);
        func_800444B4(obj);
    }
}

extern s32 func_8003E6FC(void*, s8);
extern void func_800443A8(u8*, s8);
extern s32 func_80042494(u8*);
extern s32 func_8003952C(u8* arg0);
extern s32 check_crouch_input(u8* arg0);
extern s32 func_80041C80(u8* p);
extern s32 func_80044228(u8* p);
extern s32 func_80041B84(u8* p);
extern s32 func_80044328(u8*);
extern void func_8003CF74(u8*, s32);
extern s32 player_check_ladder_crouch_walk(u8* arg0);
extern void func_800444B4(u8* a0);

void func_80042090(u8* p);

static inline s32 func_80042090_probe(u8* p) {
    if (*(s8*)(p + 2) != 0 && *(s8*)(p + 0xD3) == 0) {
        p[0x156] = 1;
        if (func_80041C80(p) != 0) {
            return 1;
        }
        if (func_80044228(p) != 0) {
            return 1;
        }
        if (func_80041B84(p) != 0) {
            return 1;
        }
        p[0x156] = 0;
    }
    return 0;
}

static inline s32 func_80042090_reset(u8* p) {
    if (func_80044328(p) == 0) {
        return 0;
    }
    func_8003B33C(p, 0x58);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        func_8003CF74(p, 3);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x30;
    p[6] = 0;
    func_80042090(p);
    return 1;
}

void func_80042090(u8* p) {
    u8* q;
    s32 r;

    if (*(s8*)(p + 2) != 0 && *(s8*)(p + 0xD3) == 0 && *(s8*)(p + 0x93) == 3 &&
        (*(u16*)(p + 0x80) & 0x20) && *(s8*)(p + 0xA6) == 0) {
        r = func_8003E6FC(p, 3);
        if (!(*(s16*)(p + 0xAE) < r)) {
            q = player_spawn_weapon(1, 0x2B, 0, p);
            if (q != 0) {
                *(s16*)(p + 0xAE) -= func_8003E6FC(p, 3);
                q[0x99] = 0;
            }
        }
    }
    if (*(s8*)(p + 6) == 0) {
        p[6]++;
    } else {
        animate_object(p);
        func_800443A8(p, 0x18);
        if (func_80042494(p) != 0) {
            return;
        }
    }
    if (*(s8*)(p + 0xD3) == 0) {
        p[0x8E] = 0;
        if (!(p[0x45] & 1)) {
            if (func_8003952C(p) != 0) {
                return;
            }
            if (*(s8*)(p + 0xCB) < 2) {
                if (check_crouch_input(p) != 0) {
                    return;
                }
                if (p[0x45] & 0x40) {
                    if (func_80042090_probe(p) != 0) {
                        return;
                    }
                    if (func_80042090_reset(p) != 0) {
                        return;
                    }
                    if (player_check_ladder_crouch_walk(p) != 0) {
                        return;
                    }
                }
            }
        }
        p[0x8E] = 1;
    }
    func_800444B4(p);
}

extern s32 func_8003952C(u8* arg0);
extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);
extern void func_8003CD08(u8* obj);
extern void func_8003CD60(u8* obj);
extern s32 func_8003E6FC(void*, s8);
extern void func_800443A8(u8*, s8);

void func_80042304(u8* obj) {
    u8* p;
    s32 t;

    func_8003CD08(obj);
    t = *(s8*)(obj + 0x2);
    if (t != 0 && *(s8*)(obj + 0xD3) == 0 && (t = *(s8*)(obj + 0x93)) == 3 &&
        (*(u16*)(obj + 0x80) & 0x20) && *(s8*)(obj + 0xA6) == 0 &&
        func_8003E6FC(obj, 3) <= *(s16*)(obj + 0xAE)) {
        p = player_spawn_weapon(1, 0x2B, 0, obj);
        if (p != 0) {
            *(u16*)(obj + 0xAE) -= func_8003E6FC(obj, 3);
            p[0x99] = 0;
        }
    }
    if (*(s8*)(obj + 0x6) == 0) {
        obj[0x6]++;
    } else {
        animate_object(obj);
        func_800443A8(obj, 0x25);
    }
    if (*(u16*)(obj + 0x80) & 2) {
        obj[0x15] = 0;
    }
    if (*(u16*)(obj + 0x80) & 1) {
        obj[0x15] = 0x40;
    }
    if (*(s8*)(obj + 0xD3) == 0) {
        obj[0x8E] = 0;
        if (func_8003952C(obj) == 0) {
            obj[0x8E] = 1;
            goto block_18; // !FAKE: goto kept for the matching branch layout
        }
    } else {
    block_18:
        if (*(s8*)(obj + 0x46) == 0) {
            obj[0x8E] = 0;
            player_set_animation_frame(obj, 0x51, 2);
            obj[0x5] = 0x1A;
            obj[0x6] = 1;
        }
        func_8003CD60(obj);
    }
}
