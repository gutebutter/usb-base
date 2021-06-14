#ifndef USB_HAL_PIC_H_
#define	USB_HAL_PIC_H_

#include <xc.h>
#include <stdint.h>

#if defined _16F1454
#define USB_BDT_BASE 0x2000
#elif defined _18F2550
#define USB_BDT_BASE 0x400
#elif defined _18F13K50
#else
#error "USB BDT addresses not defined for selected chip type."
#endif

#define USB_BUF_BASE 

// pic specific definitions for the usb macro

// usb buffer descriptor table
struct usb_bdt {
    uint8_t stat;
    uint8_t cnt;
    uint8_t adrl;
    uint8_t adrh;
};

#endif // USB_HAL_PIC_H_
