/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h> // Required for time functions

int main() {
    touch_data_t touch_data;
    time_t raw_time;
    struct tm *time_info;
    char time_string[20];

    /* Module Init */
    if(DEV_ModuleInit() != 0){
        DEV_ModuleExit();
        exit(0);
    }
	
    st7796_init();
    ft6336u_init();

    st7796_clear(0XF800);
    DEV_Delay_ms(1000);
    st7796_clear(0X400);
    DEV_Delay_ms(1000);

    while (1){
        // Fetch current system time
        time(&raw_time);
        time_info = localtime(&raw_time);

        // Format time into 12-hour format: "01:23:45 PM"
        strftime(time_string, sizeof(time_string), "%I:%M:%S %p", time_info);

        if (get_touch_data(&touch_data)) {
            // Prints the time to the console instead of touch coordinates
            printf("Current Time: %s \r\n", time_string);
            
            // Note: st7796_draw_rectangle has been removed as requested
        }
        DEV_Delay_ms(10); // Added missing semicolon from original script
    }
    
    return 0;
}