#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"
#include "addr.h"

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_80034140(u8* obj) {
    s32 frame;
    s32 idx;

    frame = D_8009A420_as_s32;
    if (frame & 1) {
        return;
    }
    idx = ((s8*)obj)[0x14] != 10;
    if (*(s32*)(obj + 0x30) != 0) {
        u8* base = g_playthrough_state.u;
        u8* q = base + 0x76;
        u8* p;
        s32 v;
        p = q + idx;
        v = *p & 0x7F;
        if (v != 0) {
            u8* x = g_Player;
            s32 t = x[0x5C];
            s32 lim;
            idx = v - 1;
            *p = idx | 0x80;
            idx = (s8)((t & 0x7F) + 1);
            lim = ((D1C00*)base)->unk47[((s8*)x)[2]];
            if (lim < idx) {
                idx = lim;
            }
            x[0x5C] = idx;
            if (!(frame & 3)) {
                play_sound(0, 0x17, 0);
            }
        } else {
            u8* x = g_Player;
            s32 lim = ((D1C00*)base)->unk47[((s8*)x)[2]];
            if (((s8*)x)[0x5C] != lim) {
                idx = (s8)((x[0x5C] & 0x7F) + 1);
                if (lim < idx) {
                    idx = lim;
                }
                x[0x5C] = idx;
                if (!(frame & 3)) {
                    play_sound(0, 0x17, 0);
                }
            } else {
                obj[5] = 1;
                *(s32*)(obj + 0x30) = 0;
                if (idx == 0) {
                    if (((s8*)base)[0x77] < 0) {
                        base[0x76] = base[0x77];
                        base[0x77] = base[0x77] & 0x80;
                    }
                }
            }
        }
    } else {
        u8* base2 = g_playthrough_state.u;
        u8* q2 = base2 + 0x76;
        u8* p2;
        s32 m = -0x80;
        s32 v2;
        p2 = q2 + idx;
        v2 = *p2 & 0x7F;
        if (v2 != 0) {
            u8* x2 = g_Player;
            s32 t2 = x2[0x5C];
            s32 lim2;
            s32 hi;
            idx = v2 - 1;
            *p2 = idx | m;
            idx = (s8)((t2 & 0x7F) + 1);
            hi = (s8)(t2 & m);
            lim2 = ((D1C00*)base2)->unk47[((s8*)x2)[2]];
            if (lim2 < idx) {
                idx = lim2;
            }
            x2[0x5C] = idx | hi;
            if (!(frame & 3)) {
                play_sound(0, 0x17, 0);
            }
        } else {
            obj[5] = 1;
            if (idx == 0) {
                if (((s8*)base2)[0x77] < 0) {
                    base2[0x76] = base2[0x77];
                    base2[0x77] = base2[0x77] & 0x80;
                }
            }
        }
    }
}
#undef D_8009A420_as_s32

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_8003432C(u8* obj) {
    u8* b;
    s16* p;
    u32 i;
    s32 flag;
    s32 v;
    s32 t;

    if (!(D_8009A420_as_s32 & 1)) {
        flag = 0;
        if (*(s32*)(obj + 0x34) != 0) {
            for (i = 0; i < 9; i++) {
                b = g_Player;
                p = (s16*)(b + 0xA8) + i;
                if (*p >= *(s16*)(b + 0x148)) {
                    *p = *(s16*)(b + 0x148);
                } else {
                    *p += 6;
                    if (*(s16*)(b + 0x148) < *p) {
                        *p = *(s16*)(b + 0x148);
                    } else {
                        flag = 1;
                    }
                }
            }
            if (flag) {
                goto tail; // !FAKE: goto kept for the matching branch layout
            }
            t = g_playthrough_state.u[0x78] & 0x7F;
            v = t - 1;
            if (t != 0) {
                g_playthrough_state.u[0x78] = v;
                return;
            }
            obj[5] = 1;
            *(s32*)(obj + 0x34) = 0;
            return;
        }
        i = 0;
        if (g_playthrough_state.u[0x78] & 0x7F) {
            b = g_Player;
            for (p = (s16*)(b + 0xA8); i < 9; i++, p++) {
                if (!(*p < *(s16*)(b + 0x148))) {
                    *p = *(s16*)(b + 0x148);
                } else {
                    *p += 6;
                    if (!(*p < *(s16*)(b + 0x148))) {
                        *p = *(s16*)(b + 0x148);
                    } else {
                        flag = 1;
                    }
                }
            }
            if (flag) {
            tail:
                v = g_playthrough_state.u[0x78] & 0x7F;
                if (v != 0) {
                    v--;
                }
                g_playthrough_state.u[0x78] = v;
                if (!(D_8009A420_as_s32 & 3)) {
                    play_sound(0, 0x17, 0);
                }
                return;
            }
            t = g_playthrough_state.u[0x78] & 0x7F;
            v = t - 1;
            if (t != 0) {
                g_playthrough_state.u[0x78] = v;
                return;
            }
        }
        obj[5] = 1;
    }
}
#undef D_8009A420_as_s32

extern void func_800132F8(s8 arg);
extern void func_800183E8(void);
extern u8* func_8002D2DC(void);
extern void func_80013288(s32);
extern s32 func_800231B4(void);
extern void func_80011FD4(s8 arg0, s8 arg1);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);
extern s8 D_8009A424;
extern u16 D_800733C4[][6];
extern u8* D_800E9538[];

void func_80034508(u8* obj) {
    u8* p;
    s32 i;
    s32 x;
    s8 y;
    s32 t;

    t = *(s8*)(obj + 6);
    switch (t) {
    case 0:
        func_800132F8(8);
        t = obj[6];
        t++;
        obj[6] = t;
        func_800272DC();
        return;
    case 1:
        if (D_8009A424 != 0) {
            func_800272DC();
        } else {
            func_800183E8();
            obj[6]++;
        }
        return;
    case 2:
        load_palette(0x15, D_801F3000 + D_801F3004, 2);
        for (i = 0; i < 10; i++) {
            p = func_8002D2DC();
            if (p != 0) {
                p[0] = 1;
                p[1] = 2;
                p[2] = i;
            }
        }
        for (i = 0; i < 4; i++) {
            D_800E9538[i] = alloc_class6_slot();
            if (D_800E9538[i] != 0) {
                D_800E9538[i][0] = 1;
                D_800E9538[i][1] = 0xB;
                D_800E9538[i][0x36] = 0xFF;
                if ((s8)g_Player[2] != 0) {
                    *(s16*)(D_800E9538[i] + 0x34) = 0x1F;
                } else {
                    *(s16*)(D_800E9538[i] + 0x34) = 0x7C00;
                }
                *(s8*)(D_800E9538[i] + 0x37) = -1;
                *(s16*)(D_800E9538[i] + 0xA) = 0;
                *(s16*)(D_800E9538[i] + 0xE) = 0;
                D_800E9538[i][3] = 1;
                *(u16*)(D_800E9538[i] + 0x16) = D_800733C4[i][0];
                *(u16*)(D_800E9538[i] + 0x1A) = D_800733C4[i][1];
                *(u16*)(D_800E9538[i] + 0x1E) = D_800733C4[i][2];
                *(u16*)(D_800E9538[i] + 0x22) = D_800733C4[i][3];
                *(u16*)(D_800E9538[i] + 0x26) = D_800733C4[i][2];
                *(u16*)(D_800E9538[i] + 0x2A) = D_800733C4[i][3];
                *(u16*)(D_800E9538[i] + 0x2E) = D_800733C4[i][4];
                *(u16*)(D_800E9538[i] + 0x32) = D_800733C4[i][5];
            }
        }
        func_80013288(8);
        t = obj[6];
        t++;
        obj[6] = t;
        func_800231B4();
        return;
    case 3:
        if (D_8009A424 == 0) {
            obj[6]++;
        }
        func_800231B4();
        D_800C9310.b |= 1;
        if (g_Player[0xF7] == 2) {
            g_Player[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        break;
    case 4:
        x = g_playthrough_state.u[0x1B9];
        y = g_playthrough_state.u[0x1B9];
        if (g_pad1_buttons[2] & 0x1000) {
            if (y >= -15) {
                g_playthrough_state.u[0x1B9] = x - 1;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            if ((s8)g_playthrough_state.u[0x1B9] < 16) {
                g_playthrough_state.u[0x1B9]++;
            }
        }
        if (g_pad1_buttons[2] & 0x8000) {
            if ((s8)g_playthrough_state.u[0x1B8] >= -15) {
                g_playthrough_state.u[0x1B8]--;
            }
        }
        if (g_pad1_buttons[2] & 0x2000) {
            if ((s8)g_playthrough_state.u[0x1B8] < 16) {
                g_playthrough_state.u[0x1B8]++;
            }
        }
        if (g_pad1_buttons[2] & 0x40) {
            obj[6]++;
        }
        if (g_pad1_buttons[2] & 0x10) {
            g_playthrough_state.u[0x1B8] = 0;
            g_playthrough_state.u[0x1B9] = 0;
        }
        func_80011FD4(g_playthrough_state.u[0x1B8],
                      g_playthrough_state.u[0x1B9]);
        func_800231B4();
        if (g_Player[0xF7] == 2) {
            g_Player[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        break;
    case 5:
        if (g_pad1_buttons[0] == 0) {
            obj[6]++;
        }
        func_800231B4();
        if (g_Player[0xF7] == 2) {
            g_Player[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        break;
    case 6:
        for (i = 0; i < 4; i++) {
            if (D_800E9538[i] != 0) {
                clear_object_slot(D_800E9538[i]);
            }
        }
        g_playthrough_state.u[1] = 0;
        obj[4] = 0;
        obj[5] = 0;
        func_800231B4();
        if (g_Player[0xF7] == 2) {
            g_Player[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        return;
    }
}
