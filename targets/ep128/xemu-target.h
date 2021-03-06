#define TARGET_NAME "ep128"
#define TARGET_DESC "Enterprise 128"
#define CONFIG_Z180
#ifdef XEMU_ARCH_NATIVE
#define XEP128_GTK
#endif
#ifdef CONFIG_Z180
#define Z80EX_Z180_SUPPORT
#endif
#define Z80EX_ED_TRAPPING_SUPPORT
#define Z80EX_CALLBACK_PROTOTYPE extern
#define CONFIG_SDEXT_SUPPORT
#ifdef __EMSCRIPTEN__
#define NO_CONSOLE
#endif
