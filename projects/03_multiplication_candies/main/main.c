#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "CANDIES_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🍬 เริ่มต้นโปรแกรมนับลูกอมในถุง 🍬");
    ESP_LOGI(TAG, "====================================");

    int number_of_bags = 7;
    int candies_per_bag = 8;
    int total_candiess;

    int strawberry_bags = 3;    // ถุงรสสตรอเบอร์รี่
    int orange_bags = 2;        // ถุงรสส้ม
    int grape_bags = 4;         // ถุงรสองุ่น
    int total_bags = strawberry_bags + orange_bags + grape_bags;
    int total_candies = total_bags * candies_per_bag;

    int friends = 12;           // จำนวนเพื่อน
    int candies_per_friend = total_candies / friends;  // ลูกอมต่อคน
    int remaining_candies = total_candies % friends;   // ลูกอมที่เหลือ

    
    

    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   มีถุงลูกอม: %d ถุง", number_of_bags);
    ESP_LOGI(TAG, "   ถุงละ: %d เม็ด", candies_per_bag);
    ESP_LOGI(TAG, "   ❓ มีลูกอมทั้งหมดกี่เม็ด?");
    ESP_LOGI(TAG, "");

    vTaskDelay(3000 / portTICK_PERIOD_MS);

    total_candies = number_of_bags * candies_per_bag;

    ESP_LOGI(TAG, "👥 แจกให้เพื่อน %d คน:", friends);
    ESP_LOGI(TAG, "   คนละ %d เม็ด", candies_per_friend);
    ESP_LOGI(TAG, "   เหลือ %d เม็ด", remaining_candies);
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🍓 สตรอเบอร์รี่: %d ถุง = %d เม็ด", 
         strawberry_bags, strawberry_bags * candies_per_bag);
    ESP_LOGI(TAG, "🍊 รสส้ม: %d ถุง = %d เม็ด", 
         orange_bags, orange_bags * candies_per_bag);
    ESP_LOGI(TAG, "🍇 รสองุ่น: %d ถุง = %d เม็ด", 
         grape_bags, grape_bags * candies_per_bag);

    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   จำนวนถุง × ลูกอมต่อถุง");
    ESP_LOGI(TAG, "   = %d × %d", number_of_bags, candies_per_bag);
    ESP_LOGI(TAG, "   = %d เม็ด", total_candies);
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   มีลูกอมทั้งหมด %d เม็ด", total_candies);
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   ถุงที่ 1: 🍬🍬🍬🍬🍬🍬 (%d เม็ด)", candies_per_bag);
    ESP_LOGI(TAG, "   ถุงที่ 2: 🍬🍬🍬🍬🍬🍬 (%d เม็ด)", candies_per_bag);
    ESP_LOGI(TAG, "   ถุงที่ 3: 🍬🍬🍬🍬🍬🍬 (%d เม็ด)", candies_per_bag);
    ESP_LOGI(TAG, "   ถุงที่ 4: 🍬🍬🍬🍬🍬🍬 (%d เม็ด)", candies_per_bag);
    ESP_LOGI(TAG, "   ถุงที่ 5: 🍬🍬🍬🍬🍬🍬 (%d เม็ด)", candies_per_bag);
    ESP_LOGI(TAG, "   รวม:     %d เม็ด", total_candies);
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🔄 เปรียบเทียบกับการบวกซ้ำๆ:");
    ESP_LOGI(TAG, "   การคูณ: %d × %d = %d", number_of_bags, candies_per_bag, total_candies);

    // ✅ แก้ตรงนี้
    ESP_LOGI(TAG, "   การบวกซ้ำๆ:");
    int sum_check = 0;
    for (int i = 1; i <= number_of_bags; i++) {
        sum_check += candies_per_bag;
        if (i == 1) {
            ESP_LOGI(TAG, "                  %d", candies_per_bag);
        } else if (i < number_of_bags) {
            ESP_LOGI(TAG, "                + %d", candies_per_bag);
        } else {
            ESP_LOGI(TAG, "                + %d = %d", candies_per_bag, sum_check);
        }
    }
    ESP_LOGI(TAG, "   ผลลัพธ์เหมือนกัน! การคูณคือการบวกซ้ำๆ");
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "📊 ตารางสูตรคูณ %d:", candies_per_bag);
    for (int i = 1; i <= 10; i++) {
        ESP_LOGI(TAG, "   %d × %d = %d", i, candies_per_bag, i * candies_per_bag);
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "📊 ตารางสูตรคูณของ %d:", candies_per_bag);
    for (int i = 1; i <= 10; i++) {
        ESP_LOGI(TAG, "   %d x %d = %d", i, candies_per_bag, i * candies_per_bag);
    }

    ESP_LOGI(TAG, "💡 ตัวอย่างเพิ่มเติม:");
    int ex1_bags = 3;
    int ex1_candies = 8;
    int ex1_total = ex1_bags * ex1_candies;
    ESP_LOGI(TAG, "   ถ้ามีถุงลูกอม %d ถุง ถุงละ %d เม็ด", ex1_bags, ex1_candies);
    ESP_LOGI(TAG, "   จะได้ลูกอม %d × %d = %d เม็ด", ex1_bags, ex1_candies, ex1_total);
    ESP_LOGI(TAG, "");

    int ex2_bags = 7;
    int ex2_candies = 4;
    int ex2_total = ex2_bags * ex2_candies;
    ESP_LOGI(TAG, "   ถ้ามีถุงลูกอม %d ถุง ถุงละ %d เม็ด", ex2_bags, ex2_candies);
    ESP_LOGI(TAG, "   จะได้ลูกอม %d × %d = %d เม็ด", ex2_bags, ex2_candies, ex2_total);
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🔄 เปรียบเทียบการดำเนินการ:");
    ESP_LOGI(TAG, "   การบวก (+): เพิ่มจำนวน (เช่น ไข่ 4 + 2 = 6)");
    ESP_LOGI(TAG, "   การลบ (-): ลดจำนวน (เช่น ของเล่น 8 - 3 = 5)");
    ESP_LOGI(TAG, "   การคูณ (×): บวกซ้ำๆ (เช่น ลูกอม 5 × 6 = 30)");
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🎓 แนวคิดขั้นสูง:");
    ESP_LOGI(TAG, "   1. การคูณมีคุณสมบัติการสับเปลี่ยน:");
    ESP_LOGI(TAG, "      %d × %d = %d × %d = %d", number_of_bags, candies_per_bag, candies_per_bag, number_of_bags, total_candies);
    ESP_LOGI(TAG, "   2. การคูณด้วย 0 จะได้ 0 เสมอ:");
    ESP_LOGI(TAG, "      %d × 0 = 0 (ไม่มีถุงลูกอม)", number_of_bags);
    ESP_LOGI(TAG, "   3. การคูณด้วย 1 จะได้ตัวเลขเดิม:");
    ESP_LOGI(TAG, "      %d × 1 = %d (มีถุงเดียว)", candies_per_bag, candies_per_bag);
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "📚 สิ่งที่เรียนรู้:");
    ESP_LOGI(TAG, "   1. การคูณเลข (Multiplication): a × b = c");
    ESP_LOGI(TAG, "   2. การใช้ for loop สำหรับการทำซ้ำ");
    ESP_LOGI(TAG, "   3. ความสัมพันธ์ระหว่างการคูณและการบวกซ้ำๆ");
    ESP_LOGI(TAG, "   4. คุณสมบัติพิเศษของการคูณ");
    ESP_LOGI(TAG, "   5. การแสดงผลแบบตาราง");
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🎉 จบโปรแกรมนับลูกอมในถุง!");
    ESP_LOGI(TAG, "📖 อ่านต่อในโปรเจคถัดไป: 04_division_cookies");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
}