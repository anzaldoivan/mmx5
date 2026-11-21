#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();

void func_800F1108_ovl06(u8* arg0) {
    u8* o;
    s32 r;
    s32 v;

    if (((s8*)arg0)[6] == 0) {
        arg0[6] = 1;
        if (arg0[0x86] < 3) {
            o = func_8002D078();
            if (o != 0) {
                o[0] = 0x41;
                o[1] = 0x3B;
                o[2] = 0;
                *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                r = func_8002B5B4(0x81) & 0xFF;
                *(s16*)(o + 0x42) =
                    ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                o[0x16] = arg0[0x16];
                *(u8**)(o + 0x7C) = arg0;
                o[0x15] = arg0[0x15];
                arg0[0x86]++;
            }
        }
        set_animation(arg0, 8);
        if (arg0[0x8D] == 0) {
            g_Player[0xD8] = 0x3F;
            g_Player[6] = 0;
        }
        play_sound(5, 7, 0);
    }
    if (((s8*)arg0)[0x46] == 0) {
        arg0[0x87] = 0;
        arg0[5] = 1;
        arg0[6] = 0;
        return;
    }
    if (((s8*)arg0)[0x45] != 0) {
        v = 0;
        if (*(u16*)(arg0 + 0x8A) & 0x30) {
            v = 1;
            if (((s8*)arg0)[2] != 0) {
                v = arg0[0x7E] == 0;
            }
        }
        if (v != 0 && arg0[0x86] < 3) {
            arg0[5] = 3;
            arg0[6] = 0;
        }
    }
    animate_object(arg0);
}

extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();

void func_800F12E8_ovl06(u8* arg0) {
    u8* o;
    s32 r;
    s32 v;
    s32 hit;
    u16 f;
    s32 one;

    if (((s8*)arg0)[6] == 0) {
        arg0[6] = 1;
        if (*(u16*)(arg0 + 0x88) & 8) {
            set_animation(arg0, 9);
            if (arg0[0x8D] == 0) {
                g_Player[0xD8] = 0x33;
                g_Player[6] = 0;
            }
            if (arg0[0x86] < 3) {
                o = func_8002D078();
                one = 1;
                if (o != 0) {
                    o[0] = 0x41;
                    o[1] = 0x3B;
                    o[2] = one;
                    *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                    *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                    *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                    *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                    *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                    r = func_8002B5B4(0x81) & 0xFF;
                    *(s16*)(o + 0x42) =
                        ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                    o[0x16] = arg0[0x16];
                    *(u8**)(o + 0x7C) = arg0;
                    o[0x15] = arg0[0x15];
                    arg0[0x86]++;
                }
            }
        } else {
            if (arg0[0x86] < 3) {
                o = func_8002D078();
                if (o != 0) {
                    o[0] = 0x41;
                    o[1] = 0x3B;
                    o[2] = 0;
                    *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                    *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                    *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                    *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                    *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                    r = func_8002B5B4(0x81) & 0xFF;
                    *(s16*)(o + 0x42) =
                        ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                    o[0x16] = arg0[0x16];
                    *(u8**)(o + 0x7C) = arg0;
                    o[0x15] = arg0[0x15];
                    arg0[0x86]++;
                }
            }
        }
        play_sound(5, 7, 0);
    }
    if (arg0[0xA8] & 8) {
        arg0[5] = 5;
        arg0[6] = 0;
        return;
    }
    if (!(arg0[0x97] & 2)) {
        f = *(u16*)(arg0 + 0x88);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        if (f & 3) {
            v = *(s16*)(arg0 + 0x98) << 8;
            if (!(f & 1)) {
                v = -v;
            }
            *(s32*)(arg0 + 0x20) = v;
        }
        if (*(s32*)(arg0 + 0x24) >= 0) {
            if ((arg0[0xA8] & 4) || !(*(u16*)(arg0 + 0x88) & 0x80)) {
                *(s32*)(arg0 + 0x24) = 0;
            }
        }
        if (((s8*)arg0)[0x46] == 0) {
            arg0[5] = (*(s32*)(arg0 + 0x24) < 0) ? 0xC : 4;
        } else {
            if (*(s32*)(arg0 + 0x24) < -0x5E000) {
                *(s32*)(arg0 + 0x24) = -0x5E000;
            }
            apply_object_motion(arg0);
            if (((s8*)arg0)[0x45] != 0) {
                hit = 0;
                if (*(u16*)(arg0 + 0x8A) & 0x30) {
                    hit = 1;
                    if (((s8*)arg0)[2] != 0) {
                        hit = arg0[0x7E] == 0;
                    }
                }
                if (hit != 0 && arg0[0x86] < 3) {
                    arg0[5] = 6;
                    arg0[6] = 0;
                }
            }
        }
        animate_object(arg0);
    } else {
        animate_object(arg0);
    }
}

extern s8 D_8009A0FC;

void func_800F1630_ovl06(u8* arg0) {
    s32 flag;
    u16 m;
    s32 hit;
    u8 t;
    s32 st;
    s32 c;

    if (*(s8*)(arg0 + 6) == 0) {
        arg0[6] = 1;
        arg0[0x7D] = 1;
        *(s16*)(arg0 + 0x98) = 0x420;
        if (arg0[0x15] != 0) {
            *(s32*)(arg0 + 0x20) = 0x42000;
        } else {
            *(s32*)(arg0 + 0x20) = -0x42000;
        }
        arg0[0x90] = 0x1E;
        *(s32*)(arg0 + 0x2C) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        set_animation(arg0, 0xC);
        if (arg0[0x8D] == 0) {
            g_Player[0xD8] = 0x2F;
            g_Player[6] = 0;
        }
        play_sound(5, 2, 0);
    }
    if ((*(u16*)(arg0 + 0x88) & 7) == 4) {
        flag = 1;
        if (*(u16*)(arg0 + 0x8A) & 0x80) {
        } else {
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        flag = 1;
        if (D_8009A0FC != -0x80) {
        clear:
            flag = 0;
        }
    }
    if (flag != 0) {
        st = 0xB;
        goto out; // !FAKE: goto kept for the matching branch layout
    }
    if (arg0[0x97] & 2) {
        goto call2; // !FAKE: goto kept for the matching branch layout
    }
    hit = 0;
    if (*(u16*)(arg0 + 0x8A) & 0x30) {
        hit = 1;
        if (*(s8*)(arg0 + 2) != 0) {
            hit = arg0[0x7E] == 0;
        }
    }
    if (hit != 0) {
        arg0[5] = 0x10;
        arg0[6] = 0;
        goto call; // !FAKE: goto kept for the matching branch layout
    }
    if (arg0[0xA8] & 3) {
        st = 0xC;
        goto out; // !FAKE: goto kept for the matching branch layout
    }
    if (!(arg0[0x97] & 8)) {
        m = 2;
        if (arg0[0x15] != 0) {
            m = 1;
        }
        c = *(u16*)(arg0 + 0x88) & m;
    } else {
        m = 2;
        if (arg0[0x15] != 0) {
            m = 1;
        }
        if (*(u16*)(arg0 + 0x88) & m) {
            goto move; // !FAKE: goto kept for the matching branch layout
        }
        c = *(u16*)(arg0 + 0x88) & 0x100;
    }
    if (c == 0) {
        st = 0xC;
        goto out; // !FAKE: goto kept for the matching branch layout
    }
move:
    t = arg0[0x90];
    *(s32*)(arg0 + 8) += *(s32*)(arg0 + 0x20);
    arg0[0x90] = t - 1;
    if ((s8)t >= 0) {
        goto call; // !FAKE: goto kept for the matching branch layout
    }
    st = 0xC;
out:
    arg0[5] = st;
    arg0[6] = 0;
    return;
call:
    animate_object(arg0);
    return;
call2:
    animate_object(arg0);
}

extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();

void func_800F1838_ovl06(u8* arg0) {
    u8* o;
    s32 r;
    s32 v;
    s32 m;
    u16 c;
    s32 t;
    s8 st;

    st = ((s8*)arg0)[6];
    if (st == 0) {
        arg0[6] = st + 1;
        if (*(u16*)(arg0 + 0x88) & 8) {
            if (arg0[0x86] < 3) {
                o = func_8002D078();
                if (o != 0) {
                    o[0] = 0x41;
                    o[1] = 0x3B;
                    o[2] = 1;
                    *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                    *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                    *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                    *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                    *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                    r = func_8002B5B4(0x81) & 0xFF;
                    *(s16*)(o + 0x42) =
                        ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                    o[0x16] = arg0[0x16];
                    *(u8**)(o + 0x7C) = arg0;
                    o[0x15] = arg0[0x15];
                    arg0[0x86]++;
                }
            }
            set_animation(arg0, 10);
            if (arg0[0x8D] == 0) {
                g_Player[0xD8] = 0x37;
                g_Player[6] = 0;
            }
        } else if (arg0[0x86] < 3) {
            o = func_8002D078();
            if (o != 0) {
                o[0] = 0x41;
                o[1] = 0x3B;
                o[2] = 0;
                *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                r = func_8002B5B4(0x81) & 0xFF;
                *(s16*)(o + 0x42) =
                    ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                o[0x16] = arg0[0x16];
                *(u8**)(o + 0x7C) = arg0;
                o[0x15] = arg0[0x15];
                arg0[0x86]++;
            }
        }
        play_sound(5, 7, 0);
    }
    t = arg0[0x90] - 1;
    arg0[0x90] = t;
    if (!(arg0[0x97] & 2)) {
        if ((arg0[0xA8] & 3) || (s8)t < 0) {
            arg0[5] = 12;
            arg0[6] = 0;
        } else if (((s8*)arg0)[0x46] == 0) {
            arg0[5] = 15;
            arg0[6] = 1;
            *(s32*)(arg0 + 8) += *(s32*)(arg0 + 0x20);
        } else {
            if (!(arg0[0x97] & 8)) {
                c = arg0[0x15] ? 1 : 2;
                c = *(u16*)(arg0 + 0x88) & c;
            } else {
                m = arg0[0x15] ? 1 : 2;
                c = *(u16*)(arg0 + 0x88) & m;
                if (c == 0) {
                    c = *(u16*)(arg0 + 0x88) & 0x100;
                }
            }
            if (c) {
                *(s32*)(arg0 + 8) += *(s32*)(arg0 + 0x20);
            }
            v = 0;
            if (*(u16*)(arg0 + 0x8A) & 0x30) {
                v = 1;
                if (((s8*)arg0)[2] != 0) {
                    v = arg0[0x7E] == 0;
                }
            }
            if (v != 0 && arg0[0x86] < 3) {
                arg0[5] = 0x10;
                arg0[6] = 0;
                if (*(u16*)(arg0 + 0x88) & 8) {
                    set_animation(arg0, 10);
                } else {
                    set_animation(arg0, 12);
                }
            }
        }
        animate_object(arg0);
    } else {
        animate_object(arg0);
    }
}

extern s8 D_8009A0FC;

void func_800F1C0C_ovl06(u8* obj) {
    s32 hit;
    s32 press;
    s32 moved;
    u16 pad;
    s32 x;
    u16 t;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x7D] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        set_animation(obj, 0xD);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x3C;
            g_Player[6] = 0;
        }
        obj[0x87] = 0;
        play_sound(5, 5, 0);
    }

    t = *(u16*)(obj + 0x88);
    x = t & 7;
    pad = t;
    if (x == 4) {
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
    t = 0; // !FAKE: dead reset ends the cse copy equivalence so pad keeps its own register (C0070)
    if (hit) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (obj[0xA8] & 8) {
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 0xC;
            obj[6] = 0;
            return;
        }
        if (*(u16*)(obj + 0x8A) & 0x30) {
            press = 1;
            if (((s8*)obj)[2] != 0) {
                press = obj[0x7E] == 0;
            }
        } else {
            press = 0;
        }
        if (press) {
            obj[5] = 0x11;
            obj[6] = 0;
            return;
        }
        if (pad & 2) {
            obj[0x15] = 0;
            moved = 1;
        } else if (pad & 1) {
            obj[0x15] = 0x40;
            moved = 1;
        } else {
            moved = 0;
        }
        if (moved) {
            if (obj[0x15]) {
                *(s32*)(obj + 0x20) = 0x16000;
            } else {
                *(s32*)(obj + 0x20) = -0x16000;
            }
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
        }
        animate_object(obj);
        return;
    }
    animate_object(obj);
}

extern u8* func_8002D078();
extern s32 func_8002B5B4(s32);
extern s8 D_8009A0FC;

static inline void func_800F1DD8_ovl06_spawn(u8* p, u8* obj, s32 k) {
    s32 r;

    p[0] = 0x41;
    p[1] = 0x3B;
    p[2] = k;
    *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
    *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
    *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
    *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
    *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
    r = (u8)func_8002B5B4(0x81);
    *(u16*)(p + 0x42) = ((r * 4 + 0x18) % 16) | ((((r + 6) / 4) + 0x1E0) << 6);
    p[0x16] = obj[0x16];
    *(u8**)(p + 0x7C) = obj;
    p[0x15] = obj[0x15];
    obj[0x86]++;
}

static inline s32 func_800F1DD8_ovl06_test(u8* obj) {
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            return 1;
        }
    } else if (D_8009A0FC == -0x80) {
        return 1;
    }
    return 0;
}

static inline s32 func_800F1DD8_ovl06_dir(u8* obj) {
    if (*(u16*)(obj + 0x88) & 2) {
        obj[0x15] = 0;
        return 1;
    }
    if (*(u16*)(obj + 0x88) & 1) {
        obj[0x15] = 0x40;
        return 1;
    }
    return 0;
}

static inline s32 func_800F1DD8_ovl06_jump(u8* obj) {
    s32 r;

    if (*(u16*)(obj + 0x8A) & 0x30) {
        r = 1;
        if (*(s8*)(obj + 2) != 0) {
            r = obj[0x7E] == 0;
        }
    } else {
        r = 0;
    }
    return r;
}

void func_800F1DD8_ovl06(u8* obj) {
    u8* p;
    s32 flag;
    s32 t;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        obj[0x7D] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        if (*(u16*)(obj + 0x88) & 8) {
            if (obj[0x86] < 3) {
                p = func_8002D078();
                if (p != 0) {
                    func_800F1DD8_ovl06_spawn(p, obj, 1);
                }
            }
            set_animation(obj, 0xB);
            if (obj[0x8D] == 0) {
                g_Player[0xD8] = 0x3D;
                g_Player[6] = 0;
            }
        } else if (obj[0x86] < 3) {
            p = func_8002D078();
            if (p != 0) {
                func_800F1DD8_ovl06_spawn(p, obj, 0);
            }
        }
        obj[0x87] = 0;
        play_sound(5, 7, 0);
    }
    flag = func_800F1DD8_ovl06_test(obj);
    if (flag) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (obj[0xA8] & 8) {
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    if ((obj[0x97] & 2) == 0) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 0xC;
            obj[6] = 0;
            return;
        }
        if (*(s8*)(obj + 0x46) < 0) {
            obj[5] = 0xE;
            obj[6] = 0;
            return;
        }
        if (*(s8*)(obj + 0x45) != 0) {
            t = func_800F1DD8_ovl06_jump(obj);
            if (t && obj[0x86] < 3) {
                obj[5] = 0x11;
                if (*(u16*)(obj + 0x88) & 8) {
                    p = func_8002D078();
                    if (p != 0) {
                        func_800F1DD8_ovl06_spawn(p, obj, 1);
                    }
                    set_animation(obj, 0xB);
                    if (obj[0x8D] == 0) {
                        g_Player[0xD8] = 0x3D;
                        g_Player[6] = 0;
                    }
                    return;
                }
                set_animation(obj, 0xD);
                if (obj[0x8D] == 0) {
                    g_Player[0xD8] = 0x3C;
                    g_Player[6] = 0;
                }
                if (obj[0x86] < 3) {
                    p = func_8002D078();
                    if (p != 0) {
                        func_800F1DD8_ovl06_spawn(p, obj, 0);
                    }
                }
                return;
            }
        }
        if (func_800F1DD8_ovl06_dir(obj)) {
            if (obj[0x15] != 0) {
                *(s32*)(obj + 0x20) = 0x16000;
            } else {
                *(s32*)(obj + 0x20) = -0x16000;
            }
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
        }
        animate_object(obj);
    } else {
        animate_object(obj);
    }
}
