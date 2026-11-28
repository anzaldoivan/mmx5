#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

#define D_800D1C00_as_D_800D1C00_t (*(D_800D1C00_t*)&g_playthrough_state)

void func_800FA004_ovl48(u8* obj) {
    s32 sum;
    s32 i;
    s32 hit;
    u32 r;
    u8 id;

    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += D_800D1C00_as_D_800D1C00_t.c6[i];
    }
    sum *= 4;
    sum += D_800D1C00_as_D_800D1C00_t.ca;
    id = obj[0xA9];
    if (id == 0xD) {
        sum = 0;
    }
    obj[0xCB] = 0x10;
    obj[0x79] = 5;
    r = (random_byte(id) >> 2) & 0xF;
    hit = 0;
    if (sum >= 0x51) {
        hit = 1;
    } else if (sum >= 0x3D) {
        if (r < 0xC) {
            hit = 1;
        }
    } else if (sum >= 0x29) {
        if (r < 6) {
            hit = 1;
        }
    } else if (sum >= 0x15) {
        if (r < 2) {
            hit = 1;
        }
    } else if (sum > 0 && r == 0) {
        hit = 1;
    }
    if (hit) {
        obj[0xCB] |= 0x80;
    }
}

extern void (*D_800FA510_ovl48[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA120_ovl48(u8* arg0) {
    D_800FA510_ovl48[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

extern void func_800FA194_ovl48(u8*);
extern void func_800FA214_ovl48(u8*);
extern void func_800FA24C_ovl48(u8*);
extern void func_800FA2D4_ovl48(u8*);
extern void func_800FA32C_ovl48(u8*);
extern void func_800FA374_ovl48(u8*);
extern void func_800FA3F8_ovl48(u8*);
extern void func_800FA444_ovl48(u8*);

void (*D_800FA510_ovl48[])(u8*) = {
    func_800FA194_ovl48, func_800FA214_ovl48, func_800FA24C_ovl48,
    func_800FA2D4_ovl48, func_800FA32C_ovl48, func_800FA374_ovl48,
    func_800FA3F8_ovl48, func_800FA444_ovl48,
};
