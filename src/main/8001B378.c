#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s32 func_8001D7E8(u8);
extern s32 func_8001D3A8(u8);
extern s32 memcard_list_files(s32, u8*, u8*);
extern s32 memcard_read_save_file(s32, s32, s32);
extern void func_8001DB78(s32);
extern s16 func_8001FF18(void*, s32);
extern void func_8001B984(void);
extern u8 D_800E81E8[];
extern u8 D_8009A427;
extern u8 D_80010090[];
extern u8 D_80070F98[];

static inline s32 func_8001B378_poll(u8* arg0) {
    s32 t;

    t = func_8001D7E8(D_800E81D8[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            arg0[1] = 5;
            D_800E81D8[8] = one;
        } else {
            arg0[1] = 5;
            D_800E81D8[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: do-while(0) for the register choice
        return 1;
    }
    return 0;
}

void func_8001B378(u8* arg0) {
    u8* p;
    u8* q;
    u8* m;
    u8* o;
    u32 r;

    p = D_800E81D8;
    if (p[0xA] != 0) {
        p[0xA]--;
        return;
    }
    if (func_8001B378_poll(arg0) != 0) {
        return;
    }
    q = D_800E81D8;
    r = func_8001D3A8(q[6]);
    switch (r) {
    case 1:
        arg0[1] = 5;
        q[8] = 0;
        arg0[3] = 1;
        return;
    case 2:
        arg0[1] = 5;
        q[8] = 1;
        arg0[3] = r;
        return;
    case 3:
        arg0[1] = 5;
        q[8] = 1;
        arg0[3] = 0x12;
        return;
    case 0:
        if (memcard_list_files(q[6], D_800E81E8, D_80010090) != 0) {
            return;
        }
        if (D_800E81E8[0x14A] != 0) {
            if (memcard_read_save_file(*(s32*)D_800E81D8, q[6], 0x2000) != 0) {
                return;
            }
            func_8001DB78(*(s32*)(q + 0xC));
            func_8002C50C();
            func_8001FF18(D_80070F98, 0);
            m = alloc_class6_slot();
            if (m != 0) {
                m[0] = 1;
                m[1] = 0xE;
                m[2] = 1;
            }
            o = func_8002D27C();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0x3E;
                o[2] = 0x10;
            }
            o = func_8002D27C();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0x3E;
                o[2] = 2;
            }
            arg0[3] = 3;
            D_8009A427 = 0;
            do {
                arg0[1]++;
            } while (
                0); // !FAKE: fence weights arg0 for the saved-register order
            func_8001B984();
        } else {
            arg0[3] = 2;
            q[8] = 0;
            arg0[1] = 5;
        }
        return;
    }
}

#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&g_pad1_buttons)

extern s32 func_8001D7E8(u8);
extern void func_8001B984(void);
extern u8 D_8009A427;
extern u8 D_800D1F28[];
extern void* D_800E81D4;

static inline s32 func_8001B5B8_start(u8* arg0) {
    u8* b = D_800E81D8;
    s32 t;

    t = func_8001D7E8(b[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;

        if (t == one) {
            arg0[1] = 5;
            b[8] = one;
        } else {
            arg0[1] = 5;
            b[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: keeps the flag set after the store (block order)
        return 1;
    }
    return 0;
}

void func_8001B5B8(u8* arg0) {
    s32 i;
    u8* p;
    u8* b;
    u8* q;
    u8* e;
    u8* f;
    u8* r;

    if (func_8001B5B8_start(arg0) != 0) {
        return;
    }
    if (D_800C931C_as_Pad800218E0.unk4 & 0x1000) {
        if (D_8009A420[7] == 0) {
            for (i = 0; i < 7; i++) {
                p = D_800E81D8;
                *(u8**)(p + 0xC) += 0x158;
            }
            D_8009A420[7] = 7;
        } else {
            e = D_800E81D8;
            q = *(u8**)(e + 0xC);
            D_8009A420[7]--;
            *(u8**)(e + 0xC) = q - 0x158;
        }
        func_8001B984();
    }
    if (D_800C931C_as_Pad800218E0.unk4 & 0x4000) {
        if (D_8009A420[7] == 7) {
            for (i = 0; i < 7; i++) {
                p = D_800E81D8;
                *(u8**)(p + 0xC) -= 0x158;
            }
            D_8009A420[7] = 0;
        } else {
            f = D_800E81D8;
            r = *(u8**)(f + 0xC);
            D_8009A420[7]++;
            *(u8**)(f + 0xC) = r + 0x158;
        }
        func_8001B984();
    }
    if (D_800C931C_as_Pad800218E0.unk4 & 0x10) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        D_800D1F28[0] = 7;
        D_800D1F28[1] = 5;
        return;
    }
    b = D_800E81D8;
    if ((D_800C931C_as_Pad800218E0.unk4 & 0x40) && **(u8**)(b + 0xC) != 0xFF) {
        play_sound(0, 0x22, 0);
        b[7] = D_8009A427;
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x3E;
            p[2] = 0x11;
        }
        D_800E81D4 = p;
        b[0xA] = 3;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[3] = 4;
        arg0[1]++;
        func_8001B984();
    }
}
#undef D_800C931C_as_Pad800218E0

/* Adapted from mmx6 @c1c892d src/shared/rock_18/func_800EAFF0.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define D_800E81D8_as_X4_Obj (*(X4_Obj*)&D_800E81D8)

M2C_UNK func_800132F8(M2C_UNK);
s32 func_8001D7E8(u8);
void func_8001B984(void);
void func_8001C904(void);
extern u8 D_8009A427;
#define D_800D1C00_as_X4_EngineObj (*(X4_EngineObj*)&g_playthrough_state)
extern void* D_800E81D4;

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))

void func_8001B818(u8* arg0) {
    // !FAKE: pins self to $17; gcc 2.7.2 allocates another register without it (byte mismatch)
    register u8* self asm("$17") = arg0;
    s32 t;
    s32 f;
    u8* p;
    s32 n;

    arg0 = 0;
    if (D_800E81D8_as_X4_Obj.x_pos.bytes[2] != 0) {
        D_800E81D8_as_X4_Obj.x_pos.bytes[2]--;
        return;
    }
    t = func_8001D7E8((u8)D_800E81D8_as_X4_Obj.unk6);
    if (t != 0) {
        // !FAKE: pins one to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 one asm("$4") = 1;
        // !FAKE: pins two to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 two asm("$3") = 2;
        if (t == one) {
            AB_B(self, 1) = 5;
            D_800E81D8_as_X4_Obj.x_pos.bytes[0] = one;
        } else {
            AB_B(self, 1) = 5;
            D_800E81D8_as_X4_Obj.x_pos.bytes[0] = two;
        }
        AB_B(self, 3) = one;
        do {
            D_8009A427 = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        D_800D1C00_as_X4_EngineObj.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = D_800E81D4;
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (D_800D1C00_as_X4_EngineObj.unkA == 0) {
            AB_B(self, 1)++;
            func_8001C904();
            func_800132F8(8);
            return;
        }
        AB_B(self, 3) = 3;
        AB_B(self, 1)--;
        func_8001B984();
    }
}

#undef AB_B
