#include "sensor.h"
#include <stdlib.h>
#include <time.h>

float read_temperature()
{
    srand(time(NULL));
    return 20.0 + rand() % 15; // 20–34°C
}