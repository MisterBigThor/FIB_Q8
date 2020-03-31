
//BCM2835 GPIO REGISTER DEFINITION:
enum{

    BASE = 0x7E200000,

    GPFSEL0 = BASE + 0x00, 
    GPFSEL1 = BASE + 0x04,
    GPFSEL2 = BASE + 0x08,
    GPFSEL3 = BASE + 0x0C,
    GPFSEL4 = BASE + 0x10,
    GPFSEL5 = BASE + 0x14,  

    GPSET0 = BASE + 0x1C,
    GPSET1 = BASE + 0x20,

    GPCLR0 = BASE + 0x28,
    GPCLR1 = BASE + 0x2C,

    GPLEV0 = BASE + 0x34,
    GPLEV1 = BASE + 0x38,

    GPEDS0 = BASE + 0x40,
    GPEDS1 = BASE + 0x44,

    GPREN0 = BASE + 0x4C,
    GPREN1 = BASE + 0x50,

    GPFEN0 = BASE + 0x58,
    GPFEN1 = BASE + 0x5C,

    GPHEN0 = BASE + 0x64,
    GPHEN1 = BASE + 0x68,

    GPLEN0 = BASE + 0x70,
    GPLEN1 = BASE + 0x74,

    GPAREN0 = BASE + 0x7C,
    GPAREN1 = BASE + 0x80,

    GPAFEN0 = BASE + 0x88,
    GPAFEN1 = BASE + 0x8C,

    GPPUD = BASE + 0x94,
    GPPUDCLK0 = BASE + 0x98,
    GPPUDCLK1 = BASE + 0x9C,

};
/*
    Look at the BCM manual for more detail.
    GPFSELn. Each of the 54 gpio pins has at least two alterneatives.
    By default, a GPIO pin is set as INPUT.
    GPSETn. Set a pin, if the pin is used as OUTPUT.
    GPCLRn. Clear a registrer, if the pins is used as OUTPUT.
    GPLEVn. Level of the respective GPIO pin
    GPEDSn. Event detect status, (levelEvent or edgeEvent). 
    GPRENn. enable rising Edge for GPIO pin
    GPRENn. enable falling Edge for GPIO pin
    GPHENn. enable high level event for GPIO pin
    GPLENn. enable low level event for GPIO pin
    GPARENn. Async risign edge
    GPAFENn. Async falling edge
    GPPUD. Internal pullUp/Down control to ALL the GPIO pins
    GPPUDCLK1. Internal pullUp/Down clock registers.

*/