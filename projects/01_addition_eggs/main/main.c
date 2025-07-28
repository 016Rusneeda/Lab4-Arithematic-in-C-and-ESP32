#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// กำหนดชื่อสำหรับแสดงใน log
static const char *TAG = "EGGS_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🥚 เริ่มต้นโปรแกรมนับไข่ไก่ของแม่ 🥚");
    ESP_LOGI(TAG, "=====================================");
    

    // ประกาศตัวแปรเก็บจำนวนแอปเปิ้ล
    int apple_already_have = 19;
    int apple_add =5;
    int total_apple_in_basket;

    // ประกาศตัวแปรเก็บจำนวนหนังสือ
    int book_already_have = 25;    
    int book_add = 6;       
    int total_book;  

    // ประกาศตัวแปรเก็บจำนวนรถ
    int car_in_park = 30;
    int car_add =8;
    int total_car_in_park;

    // ประกาศตัวแปรเก็บจำนวนดาว
    int star_in_the_sky = 50000;
    int star_delete =200;
    int total_star_in_the_sky;

    total_apple_in_basket = apple_already_have + apple_add;
    total_book = book_already_have + book_add;
    total_car_in_park = car_in_park + car_add;
    total_star_in_the_sky = star_in_the_sky - star_delete;
    
    
    // รอสักครู่เพื่อให้อ่านโจทย์
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    
    // คำนวณผลรวม (การบวก)
     
   // แอปเปิ้ล
    ESP_LOGI(TAG,"มีแอปเปิ้ลอยู่แล้ว : %d ผล",apple_already_have);
    ESP_LOGI(TAG,"เพิ่มแอปเปิ้ล : %d ผล",apple_add);
    ESP_LOGI(TAG,"รวมมีแอปเปิ้ลอยู่ในตะกร้าทั้งหมด : %d ผล", total_apple_in_basket);
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "");

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   แอปเปิ้ลที่มีอยู่ + แอปเปิ้ลที่เพิ่มเข้ามา");
    ESP_LOGI(TAG, "   = %d + %d", apple_already_have, apple_add);
    ESP_LOGI(TAG, "   = %d ผล", total_apple_in_basket);
    ESP_LOGI(TAG, "");
    
    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   รวมมีแอปเปิ้ลอยู่ในตะกร้าทั้งหมด %d ผล", total_apple_in_basket);
    ESP_LOGI(TAG, "");
    
    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   แอปเปิ้ลเดิม: 🍎 (%d ฟอง)", apple_already_have);
    ESP_LOGI(TAG, "   แอปเปิ้ลใหม่: 🍎 (%d ฟอง)", apple_add);
    ESP_LOGI(TAG, "   รวม:   🍎 (%d ฟอง)", total_apple_in_basket);
    ESP_LOGI(TAG, "");

    // หนังสือ
    ESP_LOGI(TAG,"มีหนังสืออยู่ %d เล่ม",book_already_have);
    ESP_LOGI(TAG,"เพิ่มหนังสืออีก %d เล่ม",book_add);
    ESP_LOGI(TAG,"มีหนังสือบนชั้นวางทั้งหมด %d เล่ม",total_book);
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "");

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   หนังสือที่มีอยู่ + หนังสือที่เพิ่มเข้ามา");
    ESP_LOGI(TAG, "   = %d + %d", book_already_have, book_add);
    ESP_LOGI(TAG, "   = %d เล่ม", total_book);
    ESP_LOGI(TAG, "");
    
    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   รวมมีหนังสืออยู่บนชั้นวางทั้งหมด %d เล่ม", total_book);
    ESP_LOGI(TAG, "");
    
    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   หนังสือเดิม: 📚 (%d เล่ม)", book_already_have);
    ESP_LOGI(TAG, "   หนังสือใหม่: 📚 (%d เล่ม)", book_add);
    ESP_LOGI(TAG, "   รวม:   📚 (%d เล่ม)", total_book);
    ESP_LOGI(TAG, "");

    //รถ
    ESP_LOGI(TAG,"มีรถจอดอยู่ : %d คัน",car_in_park);
    ESP_LOGI(TAG,"มีรถมาจอดเพิ่ม : %d คัน",car_add);
    ESP_LOGI(TAG,"มีรถจอดทั้งหมด : %d คัน", total_car_in_park);
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "");

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   รถที่มีอยู่ + รถที่เพิ่มเข้ามา");
    ESP_LOGI(TAG, "   = %d + %d", car_in_park, car_add);
    ESP_LOGI(TAG, "   = %d คัน", total_car_in_park);
    ESP_LOGI(TAG, "");
    
    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   รวมมีรถที่จอดทั้งหมด %d คัน", total_car_in_park);
    ESP_LOGI(TAG, "");
    
    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   รถเดิม : 🚗 (%d คัน)", car_in_park);
    ESP_LOGI(TAG, "   รถใหม่ : 🚗 (%d คัน)", car_add);
    ESP_LOGI(TAG, "   รวม :   🚗 (%d คัน)", total_car_in_park);
    ESP_LOGI(TAG, "");

    //ดวงดาว
    ESP_LOGI(TAG,"มีดาวอยู่บนฟ้า : %d ดวง",star_in_the_sky);
    ESP_LOGI(TAG,"ดวงดวงเลือนหายไป : %d ดวง",star_delete);
    ESP_LOGI(TAG,"เหลือดาวบนฟ้าทั้งหมด : %d ดาว", total_star_in_the_sky);
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "");

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   ดวงดาวที่มีอยู่ + ดวงดาวที่ลบไป");
    ESP_LOGI(TAG, "   = %d - %d", star_in_the_sky, star_delete);
    ESP_LOGI(TAG, "   = %d ดวง", total_star_in_the_sky);
    ESP_LOGI(TAG, "");

    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   มีดวงดาวทั้งอยู่บนฟ้าทั้งหมด %d ดวง", total_star_in_the_sky);
    ESP_LOGI(TAG, "");
    
    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   ดวงดาวเดิม: 🌟 (%d ดวง)", star_in_the_sky);
    ESP_LOGI(TAG, "   ดวงดาวใหม่: 🌟 (%d ดวง)", star_delete);
    ESP_LOGI(TAG, "   รวม:   🌟 (%d ดวง)", total_star_in_the_sky);
    ESP_LOGI(TAG, "");
    
    
    
    
    
    
    
    
    // รอสักครู่ก่อนจบโปรแกรม
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
