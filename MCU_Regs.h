#ifndef MCU_Regs_H
#define MCU_Regs_H

/************************* NVIC ****************************** */
#define NVIC_EN(x)         (*((volatile uint32*)(0xE000E100+(x*4))))
#define NVIC_DISABLE(x)    (*((volatile uint32*)(0xE000E180+(x*4))))
#define NVIC_PRI(x)        (*((volatile uint32*)(0xE000E400+(x*4))))

/* ************************ SCB ******************************** */
#define Intrrupt_Ctrl      (*((volatile uint32*)(0xE000ED0C )))



























#endif