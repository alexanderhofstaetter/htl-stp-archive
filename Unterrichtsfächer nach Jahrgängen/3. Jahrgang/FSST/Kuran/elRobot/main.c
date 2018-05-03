#include "elRobot.h"


int main(void)
{
    init();
    unsigned char x = 0;
    int y = 0;

    led(LED_VR, LED_MODE_S);

    beeper_start();

    while(1)
    {
        beeper_setfreq(x);
        if(y++ >= 100) x++;
    }

    return 0;
}
