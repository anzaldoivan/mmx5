#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FA3E8_ovl51[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA004_ovl51(u8* arg0) {
    D_800FA3E8_ovl51[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

extern void func_800FA078_ovl51(u8*);
// unprototyped: these five are defined below with UnkObj*
extern void func_800FA0E4_ovl51();
extern void func_800FA12C_ovl51(u8*);
extern void func_800FA174_ovl51();
extern void func_800FA1F4_ovl51();
extern void func_800FA238_ovl51();
extern void func_800FA290_ovl51();
extern void func_800FA31C_ovl51(u8*);
extern void func_800FA368_ovl51(u8*);

void (*D_800FA3E8_ovl51[])(u8*) = {
    func_800FA078_ovl51, func_800FA0E4_ovl51, func_800FA12C_ovl51,
    func_800FA174_ovl51, func_800FA1F4_ovl51, func_800FA238_ovl51,
    func_800FA290_ovl51, func_800FA31C_ovl51, func_800FA368_ovl51,
};

#define func_800FA078_ovl40 func_800FA078_ovl51
#include "shared/func_800FA078_ovl40.c"
#undef func_800FA078_ovl40

extern void func_80013288(s32);

void func_800FA0E4_ovl51(UnkObj* obj) {
    u8* p = D_8009A1F8.u;

    p[0x3] = 0;
    p[0x57] = 0;
    p[0xAB] = 0;
    func_80013288(8);
    obj->unk1++;
}

extern void func_800177B0(s32, s32);
extern signed char D_8009A424;

void func_800FA12C_ovl51(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[1]++;
        func_800177B0(0x17, 0x7F);
        *(s16*)(arg0 + 4) = 0;
    }
}

extern u8 D_800D1F3C;

void func_800FA174_ovl51(UnkObj* obj) {
    u8 v = D_800D1F3C;
    UnkSpawn* s;

    if (v == 2) {
        s = func_8002D27C();
        if (s != 0) {
            s->unk0 = 0x41;
            s->unk1 = 0x1D;
            s->unk2 = v;
            s->unkA = 0xA0;
            s->unkE = 0x60;
        }
        obj->unk4 = 1;
        obj->unk1++;
    }
}

void func_800FA1F4_ovl51(UnkObj* arg0) {
    u8* p;

    if (arg0->unk4 == 0) {
        p = D_8009A1F8.u;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FA238_ovl51(UnkObj* arg0) {
    u8* p;

    if (arg0->unk4 < 30) {
        arg0->unk4++;
        return;
    }
    p = D_8009A1F8.u;
    p[0x57] = 1;
    *(s16*)(p + 0x5E) = 0x140;
    *(s16*)(p + 0x62) = 0x100;
    p[0xA0] = 1;
    arg0->unk4 = 0;
    arg0->unk1++;
}

void func_800FA290_ovl51(UnkObj* arg0) {
    u8* p = D_8009A1F8.u;

    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += -0xB3333;
    arg0->unk4++;
    if (arg0->unk4 >= 11) {
        *(s16*)(p + 0x5E) = 0xD0;
        func_8002385C(0x44, 0xFF, 0);
        arg0->unk1++;
    }
}

#define func_800FA2C0_ovl43 func_800FA31C_ovl51
#include "shared/func_800FA2C0_ovl43.c"
#undef func_800FA2C0_ovl43

#define func_800FA30C_ovl43 func_800FA368_ovl51
#include "shared/func_800FA30C_ovl43.c"
#undef func_800FA30C_ovl43
