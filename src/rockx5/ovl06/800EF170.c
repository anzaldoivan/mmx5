#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s32 func_8002E804(u8*, u8*);
extern u8 D_800D1C00[];
extern u8 D_800D1DC0[];
extern u8 D_800FDE88_ovl06[];

void func_800EF170_ovl06(u8* obj) {
    u8* g;
    u8* h;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(u8**)(obj + 0x68) = D_800FDE88_ovl06;
        obj[0x8C] = 0;
        set_animation(obj, 0x11);
        return;
    }
    if (!(obj[0xA8] & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    g = g_Player;
    if (((s8*)g)[0xD0] != 0) {
        return;
    }
    h = D_800D1C00;
    if (((s8*)h)[0xF] != 0) {
        return;
    }
    if (((s8*)g)[2] != 0 && ((s8*)g)[0x8E] != 0) {
        return;
    }
    if (((s8*)g)[0x7A] != 0 || ((s8*)g)[0xF3] != 0) {
        return;
    }
    if (*(u16*)(obj + 0x96) & 0x8200) {
        return;
    }
    if (func_8002E804(g, obj) == 0) {
        return;
    }
    if (((s8*)h)[0xF] != 0 || ((s8*)g)[0x5C] <= 0 || ((s8*)g)[0xA4] != 0 ||
        ((s8*)g)[0x79] != 0) {
        return;
    }
    obj[5] = 0xA;
    obj[6] = 0;
    set_animation(obj, 0x12);
    obj[0x97] |= 0x40;
    g[0xD5] = (obj == D_800D1DC0) ? 1 : 2;
}

extern u8* find_free_visual_obj(void);
extern u8 D_800FDE84_ovl06[];
extern u8 D_800FDE8C_ovl06[];

void func_800EF2FC_ovl06(u8* obj) {
    u8* p;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        *(u8**)(obj + 0x68) = D_800FDE84_ovl06;
        set_animation(obj, 0x12);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x39;
            g_Player[6] = 0;
        }
        play_sound(5, 0xF, 0);
    }
    if (((s8*)obj)[0x46] == 0) {
        if (obj[0x8C] == 0) {
            obj[0x61] = 0;
        }
        obj[5] = 1;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        obj[6] = 0;
        *(u8**)(obj + 0x54) = D_800FDE8C_ovl06;
        return;
    }
    if (obj[0x45] & 1) {
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = obj[0];
            p[1] = 0xC;
            p[2] = 7;
            *(s32*)(p + 8) = *(s32*)(obj + 8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x16] = obj[0x16];
            p[0x15] = obj[0x15];
            *(u8**)(p + 0x50) = obj;
        }
        obj[0x45] = 0;
        return;
    }
    animate_object(obj);
}

extern s8 D_8009A0FC;

void func_800EF470_ovl06(u8* obj) {
    s32 press;
    s32 hit;
    s32 moved;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        set_animation(obj, 0);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x29;
            g_Player[6] = 0;
        }
        obj[0x87] = 0;
    }
    if (obj[0x94] == 2) {
        obj[5] = 0xD;
        obj[6] = 0;
        return;
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
    if (!(obj[0xA8] & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (*(u16*)(obj + 0x88) & 2) {
            obj[0x15] = 0;
            moved = 1;
        } else if (*(u16*)(obj + 0x88) & 1) {
            obj[0x15] = 0x40;
            moved = 1;
        } else {
            moved = 0;
        }
        if (moved) {
            obj[5] = 2;
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
            if (press) {
                obj[5] = 3;
                obj[6] = 0;
            }
        }
        animate_object(obj);
        return;
    }
    animate_object(obj);
}

extern s8 D_8009A0FC;

void func_800EF60C_ovl06(u8* obj) {
    s32 press;
    s32 hit;
    s32 moved;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        set_animation(obj, 1);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x2A;
            g_Player[6] = 0;
        }
        obj[0x87] = 0;
    }
    if (obj[0x94] == 2) {
        obj[5] = 0xD;
        obj[6] = 0;
        return;
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
    if (!(obj[0xA8] & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (*(u16*)(obj + 0x88) & 2) {
            obj[0x15] = 0;
            moved = 1;
        } else if (*(u16*)(obj + 0x88) & 1) {
            obj[0x15] = 0x40;
            moved = 1;
        } else {
            moved = 0;
        }
        if (!moved) {
            obj[5] = 1;
            obj[6] = 0;
            return;
        }
        if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 4;
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
            obj[5] = 3;
            obj[6] = 0;
            return;
        }
        if (obj[0x15]) {
            *(s32*)(obj + 0x20) = 0x16000;
        } else {
            *(s32*)(obj + 0x20) = -0x16000;
        }
        *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
    }
    animate_object(obj);
    if (((s8*)obj)[0x45] != 0) {
        play_sound(5, 0xC, 0);
        obj[0x45] = 0;
    }
}

extern u8* func_8002D078();

void func_800EF7E8_ovl06(u8* obj) {
    u8* q;
    u8* p;
    s32 v;
    s32 hit;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        if (obj[0x87] == 1) {
            q = func_8002D078();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x3E;
                q[2] = 2;
                *(u16*)(q + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(q + 0xE) = *(u16*)(obj + 0xE);
                *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
                *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(q + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                q[0x16] = obj[0x16];
                *(u8**)(q + 0x7C) = obj;
                q[0x15] = obj[0x15];
            }
            set_animation(obj, 10);
            if (obj[0x8D] == 0) {
                g_Player[0xD8] = 0x32;
                g_Player[6] = 0;
            }
            play_sound(5, 0x10, 0);
        } else {
            p = func_8002D078();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x3D;
                p[2] = 0;
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                p[0x16] = obj[0x16];
                *(u8**)(p + 0x7C) = obj;
                p[0x15] = obj[0x15];
            }
            set_animation(obj, 8);
            if (obj[0x8D] == 0) {
                g_Player[0xD8] = 0x31;
                g_Player[6] = 0;
            }
            play_sound(5, 0xB, 0);
        }
        obj[0x81] = 0;
    }
    if (((s8*)obj)[0x46] == 0) {
        v = obj[0x81];
        if (v != 0) {
            v = 3;
        } else {
            v = 1;
            obj[0x87] = 0;
            obj[0x81] = 0;
        }
        obj[5] = v;
        obj[6] = 0;
        return;
    }
    if (obj[0x45] & 1) {
        hit = 0;
        if (*(u16*)(obj + 0x8A) & 0x30) {
            hit = 1;
            if (((s8*)obj)[2] != 0) {
                hit = obj[0x7E] == 0;
            }
        }
        if (hit && obj[0x81] == 0 && obj[0x87] < 2) {
            obj[0x87]++;
            obj[0x81] = 1;
        }
    }
    animate_object(obj);
}

extern u8* find_free_visual_obj(void);
extern s8 D_8009A0FC;

void func_800EFA80_ovl06(u8* obj) {
    u8* p;
    s32 press;
    s32 hit;
    s32 moved;
    s32 v;

    if (((s8*)obj)[6] == 0) {
        *(s32*)(obj + 0x24) = 0x58000;
        obj[6] = 1;
        *(s32*)(obj + 0x2C) = 0x4200;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
        if (((s8*)obj)[2] == 0) {
            p = find_free_visual_obj();
            if (p != 0) {
                p[0] = obj[0];
                p[1] = 0xC;
                p[2] = 6;
                *(s32*)(p + 8) = *(s32*)(obj + 8);
                *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                p[0x16] = obj[0x16];
                p[0x15] = obj[0x15];
                *(u8**)(p + 0x50) = obj;
            }
        }
        set_animation(obj, 2);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x2B;
            g_Player[6] = 0;
        }
        obj[0x87] = 0;
        if (((s8*)obj)[2] == 0) {
            play_sound(5, 0xF, 0);
        } else {
            play_sound(5, 3, 0);
        }
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
        obj[5] = 6;
        obj[6] = 0;
        return;
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
        *(s32*)(obj + 0x20) = 0;
        if (*(u16*)(obj + 0x88) & 2) {
            obj[0x15] = 0;
            moved = 1;
        } else if (*(u16*)(obj + 0x88) & 1) {
            obj[0x15] = 0x40;
            moved = 1;
        } else {
            moved = 0;
        }
        if (moved) {
            v = *(s16*)(obj + 0x98) << 8;
            if (obj[0x15] == 0) {
                v = -v;
            }
            *(s32*)(obj + 0x20) = v;
        }
        if (!(obj[0xA8] & 4) && *(s32*)(obj + 0x24) >= 0 &&
            (*(u16*)(obj + 0x88) & 0x80)) {
            apply_object_motion(obj);
            return;
        }
        obj[5] = 0xC;
        obj[6] = 0;
    }
}

extern void silence_sound(s32, s32);
extern s8 D_8009A0FC;

void func_800EFD10_ovl06(u8* obj) {
    s32 hit;
    s32 press;
    s32 moved;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        obj[0x67] = 0;
        obj[0x7D] = 0;
        set_animation(obj, 4);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x2D;
            g_Player[6] = 0;
        }
        obj[0xA8] |= 8;
        if (((s8*)obj)[2] == 0) {
            play_sound(5, 0xD, 0);
        } else {
            play_sound(5, 0, 0);
            silence_sound(5, 5);
            play_sound(5, 0, 0);
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
    if (((s8*)obj)[0x46] == 0) {
        obj[5] = 1;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (!(obj[0xA8] & 8)) {
            obj[5] = 0xC;
            obj[6] = 0;
        } else {
            press = 0;
            if (*(u16*)(obj + 0x8A) & 0x30) {
                press = 1;
                if (((s8*)obj)[2] != 0) {
                    press = obj[0x7E] == 0;
                }
            }
            if (press) {
                obj[5] = 3;
                obj[6] = 0;
            } else {
                if (*(u16*)(obj + 0x88) & 2) {
                    obj[0x15] = 0;
                    moved = 1;
                } else if (*(u16*)(obj + 0x88) & 1) {
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
            }
        }
        animate_object(obj);
        return;
    }
    animate_object(obj);
}

extern u8* func_8002D078();

void func_800EFF34_ovl06(u8* arg0) {
    s32 v;
    u16 f;
    u8 c;
    u8* o;
    u8* g;

    if (*(s8*)(arg0 + 6) == 0) {
        arg0[6] = 1;
        o = func_8002D078();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x3E;
            o[2] = 3;
            *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
            *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
            *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
            *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            o[0x16] = arg0[0x16];
            *(u8**)(o + 0x7C) = arg0;
            o[0x15] = arg0[0x15];
        }
        set_animation(arg0, 0xB);
        if (arg0[0x8D] == 0) {
            g = g_Player;
            g[0xD8] = 0x33;
            g[6] = 0;
        }
        play_sound(5, 0x10, 0);
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
        if (*(s32*)(arg0 + 0x24) >= 0 &&
            ((arg0[0xA8] & 4) || !(*(u16*)(arg0 + 0x88) & 0x80))) {
            *(s32*)(arg0 + 0x24) = 0;
        }
        if (*(s8*)(arg0 + 0x46) == 0) {
            c = 4;
            if (*(s32*)(arg0 + 0x24) < 0) {
                c = 0xC;
            }
            arg0[5] = c;
        } else {
            if (*(s32*)(arg0 + 0x24) < -0x5E000) {
                *(s32*)(arg0 + 0x24) = -0x5E000;
            }
            apply_object_motion(arg0);
        }
        animate_object(arg0);
        return;
    }
    animate_object(arg0);
}
