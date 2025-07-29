#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "TOYS_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🧸 เริ่มต้นโปรแกรมนับของเล่นของน้อง 🧸");
    ESP_LOGI(TAG, "=========================================");
    
    // ประกาศตัวแปรเก็บจำนวนของเล่น
    int num_friends = 10;
    int toys_per_friend = 2;

    // คำถามที่ 1: ต้องมีของเล่นกี่ชิ้น?
    int total_toys_needed = num_friends * toys_per_friend;
    //printf("ต้องมีของเล่นทั้งหมด: %d ชิ้น\n", total_toys_needed);

    // คำถามที่ 2: ถ้ามี 15 ชิ้น จะขาดกี่ชิ้น?
    int toys_available = 15;
    int toys_short = total_toys_needed - toys_available;

    if (toys_short > 0) {
        printf("ถ้ามี %d ชิ้น จะขาดอีก: %d ชิ้น\n", toys_available, toys_short);
    } else {
        printf("ถ้ามี %d ชิ้น จะไม่ขาดของเล่น\n", toys_available);
    }

    // แสดงข้อมูลเริ่มต้น 
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    
    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG,"หากน้องอยากแจกของเล่นให้เพื่อน 10 คน คนละ 2 ชิ้น ");
    ESP_LOGI(TAG,"น้องต้องมี %d ตัว",total_toys_needed);
    ESP_LOGI(TAG,"ถ้ามี 15 ชิ้น จะขาดอีก %d ",toys_short);
    ESP_LOGI(TAG,"");
    ESP_LOGI(TAG,"");
    ESP_LOGI(TAG,"");   
    
    // สรุปการเรียนรู้
    ESP_LOGI(TAG, "📚 สิ่งที่เรียนรู้:");
    ESP_LOGI(TAG, "   1. การลบเลข (Subtraction): a - b = c");
    ESP_LOGI(TAG, "   2. การตรวจสอบเงื่อนไข (if statement)");
    ESP_LOGI(TAG, "   3. การจัดการกรณีพิเศษ (edge cases)");
    ESP_LOGI(TAG, "   4. ความแตกต่างระหว่างการบวกและการลบ");
    ESP_LOGI(TAG, "   5. การป้องกันผลลัพธ์ที่ไม่สมเหตุสมผล");
    ESP_LOGI(TAG, "");
    
    ESP_LOGI(TAG, "🎉 จบโปรแกรมนับของเล่นของน้อง!");
    ESP_LOGI(TAG, "📖 อ่านต่อในโปรเจคถัดไป: 03_multiplication_candies");
    
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
