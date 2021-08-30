/*
 * Ejemplo encender led desde pantalla nextion
 */
#include <Nextion.h>
#define led 2

//[page id:0,component id:1, component name: "b0"].
NexButton b0 = NexButton(0, 1, "b0");

char buffer[100] = {0};

NexTouch *nex_listen_list[] = 
{
    &b0,
    NULL
};




volatile bool estado_led = false;//variable usada para controlar el estado del led

void setup(void)
{
    nexInit();
    pinMode(led, OUTPUT);
    b0.attachPop(b0PopCallback, &b0);

    //aseguramos la condicion inicial 
    digitalWrite(led, estado_led);
}

void loop(void)
{   
    nexLoop(nex_listen_list);
    
}

void b0PopCallback(void *ptr)
{
  estado_led = !estado_led;
  digitalWrite(led, estado_led);
}
