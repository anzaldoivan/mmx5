#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800FB218_ovl04(s8* obj) {
    if ((u8)g_playthrough_state.s[0x28] & 0xF) {
        u8 m = obj[0x93] & 0xF;
        if ((u8)g_playthrough_state.s[0x28] & m) {
            obj[0x95] = ~obj[0x93] | 0xF0;
            ((u8*)obj)[0x96] = 0xFF;
            obj[5]++;
        }
    }
    if (!((u8)g_playthrough_state.s[0x28] & 0xF)) {
        s32 t = obj[0x93] & 0xF0;
        if (g_playthrough_state.s[0x28] & t) {
            obj[0x95] = ~obj[0x93] | 0xF;
            ((u8*)obj)[0x96] = 0xFF;
            obj[5]++;
        }
    }
    if (g_playthrough_state.s[0x28] == 0) {
        if ((u8)g_playthrough_state.s[0x29] & 0xF) {
            u8 m = obj[0x93] & 0xF;
            if ((u8)g_playthrough_state.s[0x29] & m) {
                ((u8*)obj)[0x95] = 0xFF;
                obj[0x96] = ~obj[0x93] | 0xF0;
                obj[5]++;
            }
        }
        if (!((u8)g_playthrough_state.s[0x29] & 0xF)) {
            s32 t = obj[0x93] & 0xF0;
            if (g_playthrough_state.s[0x29] & t) {
                ((u8*)obj)[0x95] = 0xFF;
                obj[0x96] = ~obj[0x93] | 0xF;
                obj[5]++;
            }
        }
    }
    func_8002D9EC((u8*)obj, 0x10, 0x10);
}

void func_800FB390_ovl04(u8* obj) {
    s8 flag;
    s8 state;
    u8* spawn;
    u8* p;

    animate_object(obj);
    flag = obj[0x45];
    if (flag & 0x80) {
        obj[0x45] &= 0x7F;
        spawn = func_8002D1A4(flag);
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0xB;
            *(u8**)(spawn + 0x7C) = obj;
            spawn[2] = 2;
        }
        play_sound(2, 0x14, obj);
    } else if (flag == 1) {
        state = obj[2];
        if (state == 12) {
            set_animation(obj, 0xD);
        } else if (state == 13) {
            set_animation(obj, 0xE);
        } else if (state == 14) {
            set_animation(obj, 0xF);
        } else if (state == 15) {
            set_animation(obj, 0x10);
        }
        p = g_playthrough_state.u;
        p[0x28] &= obj[0x95];
        p[0x29] &= obj[0x96];
        obj[5]--;
    }
    func_8002D9EC(obj, 0x10, 0x10);
}

extern u8 D_80102AB4_ovl04[];
extern u8 D_80102AB8_ovl04[];

void func_800FB4D8_ovl04(u8* obj) {
    u8* g = g_playthrough_state.u;
    s32 t;
    s8 k;

    g[0x28] &= ~obj[0x93];
    g[0x29] &= ~obj[0x93];
    t = *(s32*)(obj + 0x84) + 1;
    *(s32*)(obj + 0x84) = t;
    if (t >= 0x78) {
        k = obj[2];
        if (k == 12) {
            set_animation(obj, 0xD);
        } else if (k == 13) {
            set_animation(obj, 0xE);
        } else if (k == 14) {
            set_animation(obj, 0xF);
        } else if (k == 15) {
            set_animation(obj, 0x10);
        }
        obj[0x5C] = 0x10;
        *(u8**)(obj + 0x54) = D_80102AB4_ovl04;
        *(u8**)(obj + 0x50) = D_80102AB8_ovl04;
        obj[5] = 2;
        return;
    }
    if (t >= 0x3C) {
        if (t & 1) {
            k = obj[2];
            if (k == 12) {
                set_animation(obj, 0xD);
            } else if (k == 13) {
                set_animation(obj, 0xE);
            } else if (k == 14) {
                set_animation(obj, 0xF);
            } else if (k == 15) {
                set_animation(obj, 0x10);
            }
        } else {
            k = obj[2];
            if (k == 12) {
                set_animation(obj, 0x11);
            } else if (k == 13) {
                set_animation(obj, 0x37);
            } else if (k == 14) {
                set_animation(obj, 0x38);
            } else if (k == 15) {
                set_animation(obj, 0x39);
            }
        }
        obj[3] = 1;
        return;
    }
    if (t & 1) {
        obj[3] = 0;
        return;
    }
    obj[3] = 1;
}
