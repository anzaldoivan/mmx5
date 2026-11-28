#include "types.h"

#include "types.h"

extern void (*D_800FA7DC_ovl44[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA274_ovl44(u8* arg0) {
    D_800FA7DC_ovl44[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}

extern void func_800FA2E8_ovl44(u8*);
extern void func_800FA354_ovl44(u8*);
extern void func_800FA398_ovl44(u8*);
extern void func_800FA3D8_ovl44(u8*);
extern void func_800FA428_ovl44(u8*);
extern void func_800FA474_ovl44(u8*);
extern void func_800FA4F8_ovl44(u8*);
extern void func_800FA588_ovl44(u8*);
extern void func_800FA608_ovl44(u8*);
extern void func_800FA68C_ovl44(u8*);
extern void func_800FA700_ovl44(u8*);
extern void func_800FA774_ovl44(u8*);
extern void func_800FA7A0_ovl44(u8*);
extern void func_800FA180_ovl44(u8*);

void (*D_800FA7DC_ovl44[])(u8*) = {
    func_800FA2E8_ovl44, func_800FA354_ovl44, func_800FA398_ovl44,
    func_800FA3D8_ovl44, func_800FA428_ovl44, func_800FA474_ovl44,
    func_800FA4F8_ovl44, func_800FA588_ovl44, func_800FA608_ovl44,
    func_800FA68C_ovl44, func_800FA700_ovl44, func_800FA774_ovl44,
    func_800FA7A0_ovl44, func_800FA180_ovl44,
};
