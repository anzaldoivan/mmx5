#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/system.h"

extern void silence_sound(s32, s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800F3B04_ovl11(u8* arg0) {
    u8* g = g_Player;

    if (((s8*)g)[0xF3] == 0) {
        if (!(++arg0[0x85] & 1)) {
            u8* p = D_8009A1F8;
            *(u16*)(p + 0x28) -= 1;
            *(u16*)(p + 0x2A) -= 1;
        }
        move_object(arg0);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        if (!(++arg0[0x85] & 1)) {
            u8* q = D_8009A1F8;
            *(u16*)(q + 0x28) -= 1;
            *(u16*)(q + 0x2A) -= 1;
        }
        move_object(arg0);
    }
    if (*(s16*)(arg0 + 0xE) == 0x490) {
        u8* r;
        arg0[6]++;
        r = D_8009A1F8;
        if (*(s16*)(r + 0x2A) == *(s16*)(r + 0x28)) {
            silence_sound(5, 0x1D);
            play_sound(5, 0x1B, arg0);
            func_8002A600(0x20, 2, 1);
        }
    }
}

extern u8* find_free_visual_obj(void);
extern s32 func_8002DFB0(void);
extern void silence_sound(s32, s32);
extern void func_8002A600(s32, s32, s32);

extern u8 D_8009A1F8[];
extern u8 D_8009A244;
extern u8 D_800F9BD0_ovl11[];
extern u16 D_800F9C40_ovl11[];
extern u16 D_800F9C48_ovl11[];

static inline void func_800F3C34_ovl11_se(s32 a, u8 d) {
    if (d != 0xFF) {
        play_sound(a, d, 0);
    }
}

void func_800F3C34_ovl11(u8* o) {
    u8* g = g_Player;
    u8 t;
    u8* p;
    s32 i;

    if (((s8*)g)[0xF3] == 0) {
        o[0x85]++;
        if (!(o[0x85] & 1)) {
            u8* q = D_8009A1F8;
            (*(s16*)(q + 0x28))--;
            (*(s16*)(q + 0x2A))--;
        }
        move_object(o);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        o[0x85]++;
        if (!(o[0x85] & 1)) {
            u8* q = D_8009A1F8;
            (*(s16*)(q + 0x28))--;
            (*(s16*)(q + 0x2A))--;
        }
        move_object(o);
    }

    if (*(s16*)(o + 0xE) == 0x388 && o[0x82] == 0) {
        if (random_byte() & 1) {
            t = 0;
        } else {
            t = 1;
        }
        func_800F3C34_ovl11_se(0, t);
        func_80028B18(0, 0xE10, 0x330, D_800F9BD0_ovl11);
        D_8009A244 = 1;
        o[0x82] = 1;
        for (i = 0; i < 20; i++) {
            p = func_8002D27C();
            if (p != 0) {
                u8* h;
                p[0] = 0x41;
                p[1] = 0x31;
                p[0x15] = random_byte() & 0x40;
                p[2] = 1;
                *(s16*)(p + 0xA) = D_800F9C40_ovl11[random_byte() & 3] + 0xE10;
                *(s16*)(p + 0xE) = D_800F9C48_ovl11[random_byte() & 7] + 0x340;
                *(s16*)(p + 0x40) = *(s16*)(o + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
                *(s16*)(p + 0x42) = *(s16*)(o + 0x42);
                h = g_Player;
                p[0x14] = h[0x14];
            }
            p = find_free_visual_obj();
            if (p != 0 && i % 5 == 0) {
                p[0] = 0x21;
                p[1] = 4;
                *(s16*)(p + 0xA) = func_8002DFB0() % 48 + 0xE10;
                *(s16*)(p + 0xE) = func_8002DFB0() % 48 + 0x330;
                p[0x16] = 1;
            }
        }
    }

    if (*(s16*)(o + 0xE) == 0x2B0) {
        o[6]++;
        {
            u8* q = D_8009A1F8;
            if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
                silence_sound(5, 0x1D);
                play_sound(5, 0x1B, o);
                func_8002A600(0x20, 2, 1);
            }
        }
    }
}

extern u8* find_free_visual_obj(void);
extern s32 func_8002DFB0(void);
extern void silence_sound(s32, s32);
extern void func_8002A600(s32, s32, s32);

extern u8 D_8009A1F8[];
extern u8 D_8009A244;
extern s8 D_800D1C1D;
extern u8 D_800F9BD8_ovl11[];
extern u8 D_800F9BE0_ovl11[];
extern u16 D_800F9C40_ovl11[];
extern u16 D_800F9C48_ovl11[];

static inline void func_800F3F88_ovl11_se(s32 a, u8 d) {
    if (d != 0xFF) {
        play_sound(a, d, 0);
    }
}

void func_800F3F88_ovl11(u8* o) {
    u8* g = g_Player;
    u8 t;
    u8* p;
    s32 i;

    if (((s8*)g)[0xF3] == 0) {
        o[0x85]++;
        if (*(s16*)(o + 0x80) == 0) {
            if (!(o[0x85] & 1)) {
                u8* q = D_8009A1F8;
                (*(s16*)(q + 0x28))--;
                (*(s16*)(q + 0x2A))--;
            }
        } else if (*(s16*)(g + 0xE) < 0xC1) {
            *(s16*)(o + 0x80) = 1;
        }
        move_object(o);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        o[0x85]++;
        if (*(s16*)(o + 0x80) == 0) {
            if (!(o[0x85] & 1)) {
                u8* q = D_8009A1F8;
                (*(s16*)(q + 0x28))--;
                (*(s16*)(q + 0x2A))--;
            }
        } else if (*(s16*)(g + 0xE) < 0xC1) {
            *(s16*)(o + 0x80) = 1;
        }
        move_object(o);
    }

    if (*(s16*)(o + 0xE) == 0x1C8 && o[0x82] == 1) {
        func_80028B18(0, 0xE40, 0x170, D_800F9BD8_ovl11);
        {
            s32 v = 2;
            D_8009A244 = 1;
            do {
                do {
                    o[0x82] = v;
                } while (
                    0); // !FAKE: loop depth raises the constant's regalloc priority
            } while (
                0); // !FAKE: loop depth raises the constant's regalloc priority
        }
        if (random_byte() & 1) {
            t = 0;
        } else {
            t = 1;
        }
        func_800F3F88_ovl11_se(0, t);
        for (i = 0; i < 20; i++) {
            p = func_8002D27C();
            if (p != 0) {
                u8* h;
                p[0] = 0x41;
                p[1] = 0x31;
                p[0x15] = random_byte() & 0x40;
                p[2] = 1;
                *(s16*)(p + 0xA) = D_800F9C40_ovl11[random_byte() & 3] + 0xE40;
                *(s16*)(p + 0xE) = D_800F9C48_ovl11[random_byte() & 7] + 0x180;
                *(s16*)(p + 0x40) = *(s16*)(o + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
                *(s16*)(p + 0x42) = *(s16*)(o + 0x42);
                h = g_Player;
                p[0x14] = h[0x14];
            }
            p = find_free_visual_obj();
            if (p != 0 && i % 5 == 0) {
                p[0] = 0x21;
                p[1] = 4;
                *(s16*)(p + 0xA) = func_8002DFB0() % 48 + 0xE40;
                *(s16*)(p + 0xE) = func_8002DFB0() % 48 + 0x170;
                p[0x16] = 1;
            }
        }
    }

    if (*(s16*)(o + 0xE) == 0x158 && o[0x82] == 2) {
        func_80028B18(0, 0xDE0, 0x100, D_800F9BE0_ovl11);
        D_8009A244 = 1;
        if (random_byte() & 1) {
            t = 0;
        } else {
            t = 1;
        }
        func_800F3F88_ovl11_se(0, t);
        for (i = 0; i < 20; i++) {
            p = func_8002D27C();
            if (p != 0) {
                u8* h;
                p[0] = 0x41;
                p[1] = 0x31;
                p[0x15] = random_byte() & 0x40;
                p[2] = 1;
                *(s16*)(p + 0xA) = D_800F9C40_ovl11[random_byte() & 3] + 0xDE0;
                *(s16*)(p + 0xE) = D_800F9C48_ovl11[random_byte() & 7] + 0x110;
                *(s16*)(p + 0x40) = *(s16*)(o + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
                *(s16*)(p + 0x42) = *(s16*)(o + 0x42);
                h = g_Player;
                p[0x14] = h[0x14];
            }
            p = find_free_visual_obj();
            if (p != 0 && i % 5 == 0) {
                p[0] = 0x21;
                p[1] = 4;
                *(s16*)(p + 0xA) = func_8002DFB0() % 48 + 0xDE0;
                *(s16*)(p + 0xE) = func_8002DFB0() % 48 + 0x100;
                p[0x16] = 1;
            }
        }
    }

    {
        u8* e = g_Player;
        if (*(s16*)(e + 0xA) >= 0xF10 && *(s16*)(e + 0xE) < 0xC1) {
            silence_sound(5, 0x1D);
        }
    }

    if (*(s16*)(o + 0xE) == 0xD0) {
        o[5] = 8;
        if (D_800D1C1D < 4) {
            u8* q = D_8009A1F8;
            if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
                silence_sound(5, 0x1D);
                play_sound(5, 0x1B, o);
                func_8002A600(0x20, 4, 1);
            }
        }
    }
}
