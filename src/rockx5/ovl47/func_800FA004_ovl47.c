#include "types.h"

#include "types.h"

extern void (*D_800FA580_ovl47[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA004_ovl47(u8* arg0) {
    D_800FA580_ovl47[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

extern void func_800FA078_ovl47(u8*);
extern void func_800FA0F8_ovl47(u8*);
extern void func_800FA130_ovl47(u8*);
extern void func_800FA1B8_ovl47(u8*);
extern void func_800FA228_ovl47(u8*);
extern void func_800FA2B8_ovl47(u8*);
extern void func_800FA2E4_ovl47(u8*);
extern void func_800FA390_ovl47(u8*);
extern void func_800FA404_ovl47(u8*);
extern void func_800FA498_ovl47(u8*);
extern void func_800FA4C4_ovl47(u8*);
extern void func_800FA500_ovl47(u8*);

void (*D_800FA580_ovl47[])(u8*) = {
    func_800FA078_ovl47, func_800FA0F8_ovl47, func_800FA130_ovl47,
    func_800FA1B8_ovl47, func_800FA228_ovl47, func_800FA2B8_ovl47,
    func_800FA2E4_ovl47, func_800FA390_ovl47, func_800FA404_ovl47,
    func_800FA498_ovl47, func_800FA4C4_ovl47, func_800FA500_ovl47,
};
