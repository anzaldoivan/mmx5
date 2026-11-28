#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/object.h"

extern s32 func_8003E6FC(void*, s8);
extern s32 func_800390A4(u8* p);
extern void func_800443A8(u8*, s8);
extern s32 func_80044328(u8*);
extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern s32 try_grab_ladder_from_air(u8* obj);
extern s32 try_enter_wall_cling(void* self);
extern s32 func_80038850(u8* self);
extern void func_8003D120(u8*);
extern void func_8003D344(void* arg0);
extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);

void func_80042770(u8* o);

static inline s32 func_80042770_a(u8* o) {
    if (func_80044328(o)) {
        if (o[0xC9] & 1) {
            func_8003B33C(o, 0x60);
            play_sound(1, 7, o);
            player_spawn_visual(1, 0x11, 0, (s32)o);
            o[5] = 0x35;
        } else {
            func_8003B33C(o, 0x5B);
            play_sound(1, 8, o);
            o[5] = 0x31;
        }
        o[6] = 0;
        func_80042770(o);
        return 1;
    }
    return 0;
}

void func_80042770(u8* o) {
    u8* p;
    s8 saved;
    s32 t;

    if (((s8*)o)[2] != 0 && ((s8*)o)[0xD3] == 0 && ((s8*)o)[0x93] == 3 &&
        (*(u16*)(o + 0x80) & 0x20) && ((s8*)o)[0xA6] == 0) {
        t = func_8003E6FC(o, 3);
        if (*(s16*)(o + 0xAE) >= t) {
            p = player_spawn_weapon(1, 0x2B, 0, o);
            if (p != 0) {
                *(s16*)(o + 0xAE) -= func_8003E6FC(o, 3);
                p[0x99] = 0;
            }
        }
    }
    if (func_800390A4(o)) {
        return;
    }
    if (((s8*)o)[6] == 0) {
        if (((s8*)o)[5] == 0x31) {
            func_800443A8(o, 0x1B);
        }
        o[6]++;
    } else {
        animate_object(o);
        if (((s8*)o)[5] == 0x35) {
            func_800443A8(o, 0x20);
        }
    }
    if (((s8*)o)[0xD3] != 0) {
        *(s32*)(o + 0x24) = 0;
    }
    if (o[0x89] & 4) {
        *(s32*)(o + 0x24) = 0;
    }
    if (!(*(u16*)(o + 0x7C) & 0x80)) {
        *(s32*)(o + 0x24) = 0;
    }
    if (((s8*)o)[0x8E] != 0 && ((s8*)o)[0x46] == 0) {
        o[0x8E] = 0;
    }
    if (func_80042770_a(o)) {
        return;
    }
    saved = ((s8*)o)[0x8E];
    o[0x8E] = 0;
    if (o[0x45] & 0x40) {
        if (func_80042770_a(o)) {
            return;
        }
    }
    if (((s8*)o)[0x8B] == 0) {
        if (try_grab_ladder_from_air(o)) {
            return;
        }
        if (try_enter_wall_cling(o)) {
            return;
        }
        if (func_80038850(o)) {
            return;
        }
    } else {
        o[0x8B]--;
    }
    o[0x8E] = saved;
    func_8003D120(o);
    func_8003D344(o);
    if (*(s32*)(o + 0x24) > 0) {
        return;
    }
    if (((s8*)o)[0x8E] != 0) {
        if (((s8*)o)[5] == 0x31) {
            o[5] = 0x32;
        } else {
            o[5] = 0x36;
        }
        o[6] = 1;
    } else {
        player_set_animation_frame(o, 0xB, 5);
        o[0x8A] = 0;
        o[5] = 7;
        o[6] = 0;
    }
    ((s8*)o)[0x67] = -1;
}

extern s32 func_8003E6FC(void*, s8);
extern s32 func_800390A4(u8* p);
extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);
extern void func_800443E4(u8* a0, s8 a1);
extern void func_8003A9AC(u8* arg0);
extern void func_800443A8(u8*, s8);
extern s32 func_80044138(u8*);
extern s32 func_80044328(u8*);
extern void* player_spawn_visual(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern s32 try_grab_ladder_from_air(u8* obj);
extern s32 try_enter_wall_cling(void* self);
extern s32 func_80038850(u8* self);
extern void func_8003D120(u8*);
extern void func_8003D344(void* arg0);

void func_80042B18(u8* o);

static inline s32 func_80042B18_check(u8* o) {
    if (((s8*)o)[2] == 0) {
        return 0;
    }
    if (((s8*)o)[0xD3] != 0) {
        return 0;
    }
    if (func_80044138(o) != 0) {
        return 1;
    }
    if (func_80044328(o) == 0) {
        return 0;
    }
    if (o[0xC9] & 1) {
        func_8003B33C(o, 0x60);
        play_sound(1, 7, o);
        player_spawn_visual(1, 0x11, 0, (s32)o);
        o[5] = 0x36;
    } else {
        func_8003B33C(o, 0x5B);
        play_sound(1, 8, o);
        o[5] = 0x32;
    }
    o[6] = 0;
    func_80042B18(o);
    return 1;
}

void func_80042B18(u8* o) {
    u8* p;
    s32 t;

    if (((s8*)o)[2] != 0 && ((s8*)o)[0xD3] == 0 && ((s8*)o)[0x93] == 3 &&
        (*(u16*)(o + 0x80) & 0x20) && ((s8*)o)[0xA6] == 0 &&
        func_8003E6FC(o, 3) <= *(s16*)(o + 0xAE)) {
        p = player_spawn_weapon(1, 0x2B, 0, o);
        if (p != 0) {
            *(s16*)(o + 0xAE) -= func_8003E6FC(o, 3);
            p[0x99] = 0;
        }
    }
    if (func_800390A4(o) != 0) {
        return;
    }
    if (o[0x89] & 8) {
        o[0x67] = 0;
        o[0x84] = 0;
        o[0x86] = 0;
        o[0x8C] = 0;
        if (((s8*)o)[0x8E] != 0) {
            if (((s8*)o)[5] == 0x32) {
                s8 s = ((s8*)o)[0x44];

                player_set_animation_frame(o, 0x5C, o[0x45] & 0x1F);
                ((s8*)o)[0x44] = s;
                func_800443E4(o, 0x1C);
                o[5] = 0x30;
                o[6] = 1;
                return;
            }
            o[0x8E] = 0;
        }
        func_8003A9AC(o);
        return;
    }
    if (((s8*)o)[6] == 0) {
        if (((s8*)o)[5] == 0x32) {
            func_800443A8(o, 0x1B);
        }
        o[6]++;
    } else {
        animate_object(o);
        if (((s8*)o)[5] == 0x36) {
            func_800443A8(o, 0x20);
        }
    }
    if (((s8*)o)[0x8E] != 0 && ((s8*)o)[0x46] == 0) {
        o[0x8E] = 0;
    }
    if (func_80042B18_check(o) != 0) {
        return;
    }
    t = ((s8*)o)[0x8E];
    o[0x8E] = 0;
    if ((o[0x45] & 0x40) && func_80042B18_check(o) != 0) {
        return;
    }
    if (try_grab_ladder_from_air(o) != 0) {
        return;
    }
    if (try_enter_wall_cling(o) != 0) {
        return;
    }
    if (func_80038850(o) != 0) {
        return;
    }
    ((s8*)o)[0x8E] = t;
    func_8003D120(o);
    func_8003D344(o);
    if (((s8*)o)[0x8E] == 0) {
        player_set_animation_frame(o, 0xB, 5);
        o[5] = 7;
        o[6] = 0;
    }
}

extern s32 func_8003E6FC(void*, s8);
extern s32 player_check_ladder_release(u8*);
extern void func_800443A8(u8*, s8);
extern s32 func_80044328(u8*);
extern void func_8003CF74(u8*, s32);
extern void player_set_animation_frame(u8* obj, s32 arg1, s32 arg2);
extern void func_8003B0EC(u8* obj);
void func_80042F00(u8* p);

static inline s32 func_80042F00_land(u8* p) {
    if (func_80044328(p) == 0) {
        return 0;
    }
    func_8003B33C(p, 0x5D);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        func_8003CF74(p, 8);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[0x5] = 0x33;
    p[0x6] = 0;
    func_80042F00(p);
    return 1;
}

void func_80042F00(u8* p) {
    u8* q;

    if (*(s8*)(p + 0x2) != 0 && *(s8*)(p + 0xD3) == 0 &&
        *(s8*)(p + 0x93) == 3 && (*(u16*)(p + 0x80) & 0x20) &&
        *(s8*)(p + 0xA6) == 0 && func_8003E6FC(p, 3) <= *(s16*)(p + 0xAE)) {
        q = player_spawn_weapon(1, 0x2B, 0, p);
        if (q != 0) {
            *(s16*)(p + 0xAE) -= func_8003E6FC(p, 3);
            q[0x99] = 0;
        }
    }
    if (player_check_ladder_release(p) != 0) {
        p[0x8E] = 0;
        return;
    }
    if (*(s8*)(p + 0x6) == 0) {
        p[0x6] = p[0x6] + 1;
    } else {
        animate_object(p);
    }
    func_800443A8(p, 0x1E);
    if (p[0x45] & 0x40) {
        p[0x8E] = 0;
        if (func_80042F00_land(p) != 0) {
            return;
        }
        p[0x8E] = 1;
    }
    if (*(u16*)(p + 0x80) & 2) {
        p[0x15] = 0;
    }
    if (*(u16*)(p + 0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (*(s8*)(p + 0x46) == 0) {
        p[0x8E] = 0;
        player_set_animation_frame(p, 0x1F, 2);
        func_8003B0EC(p);
    }
}

extern s32 func_8003E6FC(void*, s8);
extern void func_8003A9AC(u8*);
extern void func_8003A94C(u8*);
extern s32 try_wall_jump(u8*);
extern s32 is_pressing_into_wall(u8*);
extern void func_800443A8(u8*, s8);
extern s32 func_80044328(u8*);
extern void func_8003CF74(u8*, s32);
extern void func_8003D344(void*);
extern void func_8003AEF0(u8*);

void func_800430FC(u8* o);

static inline s32 func_800430FC_sub(u8* o) {
    if (func_80044328(o) == 0) {
        return 0;
    }
    func_8003B33C(o, 0x5E);
    play_sound(1, 7, o);
    if (random_byte() & 4) {
        func_8003CF74(o, 8);
    }
    o[5] = 0x34;
    o[6] = 0;
    func_800430FC(o);
    return 1;
}

void func_800430FC(u8* o) {
    u8* p;
    u8 t;
    s32 v;

    if (((s8*)o)[2] != 0 && ((s8*)o)[0xD3] == 0 && ((s8*)o)[0x93] == 3 &&
        (*(u16*)(o + 0x80) & 0x20) && ((s8*)o)[0xA6] == 0 &&
        func_8003E6FC(o, 3) <= *(s16*)(o + 0xAE)) {
        p = player_spawn_weapon(1, 0x2B, 0, o);
        if (p != 0) {
            *(s16*)(o + 0xAE) -= func_8003E6FC(o, 3);
            p[0x99] = 0;
        }
    }
    t = o[0x89];
    if (t & 8) {
        o[0x8E] = 0;
        func_8003A9AC(o);
        return;
    }
    v = ((s8*)o)[0xD3] != 0;
    if (!(t & 3)) {
        v = 1;
    }
    if (v) {
        o[0x8E] = 0;
        func_8003A94C(o);
        return;
    }
    if (try_wall_jump(o)) {
        o[0x8E] = 0;
        return;
    }
    if (is_pressing_into_wall(o)) {
        if (((s8*)o)[6] == 0) {
            o[6]++;
        } else {
            animate_object(o);
        }
        func_800443A8(o, 0x1F);
        if (o[0x45] & 0x40) {
            o[0x8E] = 0;
            if (func_800430FC_sub(o)) {
                return;
            }
            o[0x8E] = 1;
        }
        move_object(o);
        func_8003D344(o);
        if (((s8*)o)[0x46] == 0) {
            o[0x8E] = 0;
            func_8003B33C(o, 0xF);
            o[5] = 0xB;
            o[6] = 0;
        }
    } else {
        o[0x8E] = 0;
        func_8003AEF0(o);
    }
}
