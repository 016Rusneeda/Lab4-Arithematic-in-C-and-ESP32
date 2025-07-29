#include <stdio.h>
#include <math.h> // สำหรับใช้ฟังก์ชัน sqrt และ pow
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 🏷️ Tag สำหรับ Log
static const char *TAG = "ADVANCED_MATH";

// 🔢 ค่าคงที่ทางคณิตศาสตร์
#define PI 3.14159265359
#define SQUARE_METERS_TO_RAI 1600.0  // 1 ไร่ = 1,600 ตร.ม.

// 📐 โครงสร้างข้อมูลรูปทรง (ปรับปรุงเพื่อให้รองรับสามเหลี่ยมและกรวยได้ดีขึ้น)
typedef struct {
    char name[50];
    double param1;       // ความยาว/รัศมี/ฐาน
    double param2;       // ความกว้าง/ความสูง/ด้านที่ 2 (สำหรับสามเหลี่ยม)
    double param3;       // ความสูง/ความลึก/ด้านที่ 3 (สำหรับสามเหลี่ยม)
} shape_t;

// 🏟️ ฟังก์ชันคำนวณสี่เหลี่ยม
void calculate_rectangle(shape_t shape) {
    double length = shape.param1;
    double width = shape.param2;
    double area = length * width;
    double perimeter = 2 * (length + width);
    double area_in_rai = area / SQUARE_METERS_TO_RAI;

    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           %s           ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 ความยาว: %.2f เมตร", length);
    ESP_LOGI(TAG, "║ 📏 ความกว้าง: %.2f เมตร", width);
    ESP_LOGI(TAG, "║ 📐 พื้นที่: %.2f × %.2f = %.2f ตร.ม.",
             length, width, area);
    ESP_LOGI(TAG, "║ 🔄 ปริเมตร: 2×(%.0f+%.0f) = %.2f ม.",
             length, width, perimeter);
    ESP_LOGI(TAG, "║ 🌾 เท่ากับ: %.4f ไร่", area_in_rai);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// 🏊‍♀️ ฟังก์ชันคำนวณวงกลม
void calculate_circle(shape_t shape) {
    double radius = shape.param1;   // ใช้ param1 เป็น radius
    double height = shape.param3;   // ใช้ param3 เป็นความลึก/สูง (สำหรับทรงกระบอก/ทรงกลม)
    double surface_area = PI * radius * radius;
    double circumference = 2 * PI * radius;
    double volume = surface_area * height;  // ปริมาตรทรงกระบอก

    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           %s             ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 รัศมี: %.2f เมตร", radius);
    ESP_LOGI(TAG, "║ 📏 ความลึก: %.2f เมตร", height);
    ESP_LOGI(TAG, "║ 🌊 พื้นที่ผิวน้ำ: π × %.0f² = %.2f ตร.ม.",
             radius, surface_area);
    ESP_LOGI(TAG, "║ ⭕ เส้นรอบวง: 2π × %.0f = %.2f ม.",
             radius, circumference);
    ESP_LOGI(TAG, "║ 💧 ปริมาตรน้ำ: %.2f × %.2f = %.2f ลบ.ม.",
             surface_area, height, volume);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// 🎁 ฟังก์ชันคำนวณทรงสี่เหลี่ยมมุมฉาก (Box)
void calculate_box(shape_t shape) {
    double length = shape.param1;
    double width = shape.param2;
    double height = shape.param3;
    double volume = length * width * height;
    double surface_area = 2 * (length * width +
                                width * height +
                                length * height);

    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           %s           ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 ความยาว: %.2f ซม.", length);
    ESP_LOGI(TAG, "║ 📏 ความกว้าง: %.2f ซม.", width);
    ESP_LOGI(TAG, "║ 📏 ความสูง: %.2f ซม.", height);
    ESP_LOGI(TAG, "║ 📦 ปริมาตร: %.0f×%.0f×%.0f = %.2f ลบ.ซม.",
             length, width, height, volume);
    ESP_LOGI(TAG, "║ 🎀 พื้นที่ผิว: %.2f ตร.ซม.", surface_area);
    ESP_LOGI(TAG, "║ 📐 เท่ากับ: %.6f ลิตร", volume / 1000.0);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// 🔺 ฟังก์ชันคำนวณสามเหลี่ยม
void calculate_triangle(shape_t shape) {
    double base = shape.param1;    // ฐาน
    double height = shape.param2;   // สูง (สำหรับพื้นที่)
    double side1 = shape.param1;
    double side2 = shape.param2;
    double side3 = shape.param3;

    double area = 0.5 * base * height;
    // คำนวณเส้นรอบรูป ถ้ามีข้อมูลด้านครบ
    double perimeter = 0.0;
    if (side1 > 0 && side2 > 0 && side3 > 0) {
        perimeter = side1 + side2 + side3;
    } else {
        ESP_LOGW(TAG, "Warning: ข้อมูลด้านไม่ครบถ้วนสำหรับการคำนวณเส้นรอบรูปสามเหลี่ยม");
    }

    ESP_LOGI(TAG, "╔═══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           %s            ║", shape.name);
    ESP_LOGI(TAG, "╠═══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 ฐาน: %.2f ซม.", base);
    ESP_LOGI(TAG, "║ 📏 สูง: %.2f ซม.", height);
    ESP_LOGI(TAG, "║ 📐 พื้นที่: ½ × %.2f × %.2f = %.2f ตร.ซม.",
             base, height, area);
    if (perimeter > 0) {
        ESP_LOGI(TAG, "║ 🔄 ปริเมตร: %.2f + %.2f + %.2f = %.2f ซม.",
                 side1, side2, side3, perimeter);
    }
    ESP_LOGI(TAG, "╚═══════════════════════════════════════╝");
}

// 🍦 ฟังก์ชันคำนวณทรงกรวย
void calculate_cone(shape_t shape) {
    double radius = shape.param1; // รัศมีฐาน
    double height = shape.param2; // ความสูง
    
    // คำนวณความสูงเอียง (slant height)
    double slant_height = sqrt(pow(radius, 2) + pow(height, 2));
    
    // พื้นที่ฐาน (วงกลม)
    double base_area = PI * pow(radius, 2);
    // พื้นที่ผิวข้าง
    double lateral_surface_area = PI * radius * slant_height;
    // พื้นที่ผิวทั้งหมด
    double total_surface_area = base_area + lateral_surface_area;
    // ปริมาตรกรวย
    double volume = (1.0/3.0) * PI * pow(radius, 2) * height;

    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           %s            ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 รัศมีฐาน: %.2f ซม.", radius);
    ESP_LOGI(TAG, "║ 📏 ความสูง: %.2f ซม.", height);
    ESP_LOGI(TAG, "║ 📏 สูงเอียง: %.2f ซม.", slant_height);
    ESP_LOGI(TAG, "║ 🍦 ปริมาตร: ⅓π × %.2f² × %.2f = %.2f ลบ.ซม.",
             radius, height, volume);
    ESP_LOGI(TAG, "║ 🌈 พื้นที่ผิว: %.2f ตร.ซม.", total_surface_area);
    ESP_LOGI(TAG, "║ 📐 เท่ากับ: %.6f ลิตร", volume / 1000.0);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// ↔️ ฟังก์ชันแปลงหน่วย: เมตร -> ตารางเมตร -> ไร่
void convert_meter_to_sqm_to_rai(double meter_value) {
    ESP_LOGI(TAG, "\n🔄 การแปลงหน่วย:");
    ESP_LOGI(TAG, "╔═══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║       แปลงหน่วย (เมตร -> ตร.ม. -> ไร่)  ║");
    ESP_LOGI(TAG, "╠═══════════════════════════════════════╣");
    
    // ถ้าเป็นความยาว
    ESP_LOGI(TAG, "║ 📏 %.2f เมตร", meter_value);

    // ถ้าคิดว่าเป็นด้านของสี่เหลี่ยมจัตุรัส แล้วแปลงเป็นพื้นที่
    double area_sqm = meter_value * meter_value;
    ESP_LOGI(TAG, "║ ➡️ ถ้าเป็นสี่เหลี่ยมจัตุรัส: พื้นที่ = %.2f ตร.ม.", area_sqm);

    // แปลงจาก ตร.ม. เป็น ไร่
    double area_rai = area_sqm / SQUARE_METERS_TO_RAI;
    ESP_LOGI(TAG, "║ ➡️ แปลงเป็นไร่: %.2f ตร.ม. ÷ %.0f = %.6f ไร่", area_sqm, SQUARE_METERS_TO_RAI, area_rai);
    ESP_LOGI(TAG, "╚═══════════════════════════════════════╝");
}

// 📊 ฟังก์ชันเปรียบเทียบผลลัพธ์ (อาจจะต้องปรับปรุงถ้าต้องการเปรียบเทียบฟังก์ชันใหม่ด้วย)
void compare_results(void) {
    ESP_LOGI(TAG, "\n🔍 การเปรียบเทียบผลลัพธ์ (เบื้องต้น):");
    ESP_LOGI(TAG, "╔════════════════════════════════════╗");
    ESP_LOGI(TAG, "║   สนามฟุตบอล vs สระน้ำ vs กล่อง    ║");
    ESP_LOGI(TAG, "╠════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 🏟️ สนาม: ใหญ่ที่สุด (6,000 ตร.ม.)  ║");
    ESP_LOGI(TAG, "║ 🏊‍♀️ สระ: กลาง (78.54 ตร.ม.)       ║");
    ESP_LOGI(TAG, "║ 🎁 กล่อง: เล็กที่สุด (300 ลบ.ซม.)  ║");
    // อาจเพิ่มสามเหลี่ยมและกรวยได้ที่นี่ถ้าต้องการเปรียบเทียบกัน
    ESP_LOGI(TAG, "╚════════════════════════════════════╝");
}

// 🎓 ฟังก์ชันแสดงความรู้เพิ่มเติม
void show_math_facts(void) {
    ESP_LOGI(TAG, "\n📚 ความรู้ทางคณิตศาสตร์:");
    ESP_LOGI(TAG, "╔═══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           สูตรคณิตศาสตร์            ║");
    ESP_LOGI(TAG, "╠═══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📐 สี่เหลี่ยม: พื้นที่ = ยาว × กว้าง   ║");
    ESP_LOGI(TAG, "║ ⭕ วงกลม: พื้นที่ = π × r²           ║");
    ESP_LOGI(TAG, "║ 📦 ทรงสี่เหลี่ยม: ปริมาตร = ย×ก×ส   ║"); // เปลี่ยนจากทรงผีเสื้อเป็นทรงสี่เหลี่ยม
    ESP_LOGI(TAG, "║ 🔺 สามเหลี่ยม: พื้นที่ = ½ × ฐาน × สูง ║"); // เพิ่มสามเหลี่ยม
    ESP_LOGI(TAG, "║ 🍦 ทรงกรวย: ปริมาตร = ⅓ × π × r² × ส ║"); // เพิ่มทรงกรวย
    ESP_LOGI(TAG, "║ 💡 π (pi) ≈ 3.14159                  ║");
    ESP_LOGI(TAG, "║ 🌾 1 ไร่ = 1,600 ตารางเมตร          ║");
    ESP_LOGI(TAG, "╚═══════════════════════════════════════╝");
}

// 🎯 ฟังก์ชันท้าทาย - คำนวณสามเหลี่ยม (เปลี่ยนเป็นตัวอย่างการใช้ฟังก์ชันใหม่)
// void calculate_triangle_bonus(void) { ... } // จะไม่ใช้แล้ว แต่ใช้ calculate_triangle แทน

void app_main(void) {
    ESP_LOGI(TAG, "🚀 เริ่มต้นโปรแกรมคณิตศาสตร์ขั้นสูง!");
    ESP_LOGI(TAG, "📐 การคำนวณพื้นที่และปริมาตร\n");

    // รอสักครู่เพื่อให้ระบบเริ่มต้นเสร็จสิ้น
    vTaskDelay(pdMS_TO_TICKS(1000));

    // 🏟️ สนามฟุตบอล
    shape_t football_field = {
        .name = "สนามฟุตบอล",
        .param1 = 100.0, // ความยาว
        .param2 = 60.0,  // ความกว้าง
        .param3 = 0.0    // ไม่ได้ใช้
    };

    // 🏊‍♀️ สระน้ำกลม (ทรงกระบอก)
    shape_t swimming_pool = {
        .name = "สระน้ำกลม (ทรงกระบอก)", // ปรับชื่อให้ชัดเจน
        .param1 = 5.0,    // รัศมี
        .param2 = 0.0,    // ไม่ได้ใช้
        .param3 = 2.0     // ความลึก
    };

    // 🎁 กล่องของขวัญ (ทรงสี่เหลี่ยมมุมฉาก)
    shape_t gift_box = {
        .name = "กล่องของขวัญ (ทรงสี่เหลี่ยม)", // ปรับชื่อให้ชัดเจน
        .param1 = 20.0, // ความยาว
        .param2 = 15.0, // ความกว้าง
        .param3 = 10.0  // ความสูง
    };

    // 🔺 สามเหลี่ยม
    shape_t triangle = {
        .name = "สามเหลี่ยม (มุมฉาก)",
        .param1 = 10.0, // ฐาน
        .param2 = 8.0,  // สูง
        .param3 = 6.0   // ด้านที่ 3 (สำหรับเส้นรอบรูป)
    };

    // 🍦 ทรงกรวย
    shape_t ice_cream_cone = {
        .name = "ทรงกรวย",
        .param1 = 3.0,  // รัศมีฐาน
        .param2 = 10.0, // ความสูง
        .param3 = 0.0   // ไม่ได้ใช้
    };

    // 🎨 ASCII Art
    ESP_LOGI(TAG, "   🏟️     🏊‍♀️     🎁     🔺     🍦");
    ESP_LOGI(TAG, " ┌─────┐  ╭─────╮  ┌─────┐  ╱\\   ╱\\");
    ESP_LOGI(TAG, " │ ⚽  │  │ 💧💧 │  │ 🎀  │  ╱  \\  /  \\");
    ESP_LOGI(TAG, " │     │  │     │  │     │  ───  ────");
    ESP_LOGI(TAG, " └─────┘  ╰─────╯  └─────┘");


    // คำนวณแต่ละรูปทรง
    calculate_rectangle(football_field);
    vTaskDelay(pdMS_TO_TICKS(2000));

    calculate_circle(swimming_pool);
    vTaskDelay(pdMS_TO_TICKS(2000));

    calculate_box(gift_box);
    vTaskDelay(pdMS_TO_TICKS(2000));

    // *** เพิ่มการคำนวณสามเหลี่ยม ***
    calculate_triangle(triangle);
    vTaskDelay(pdMS_TO_TICKS(2000));

    // *** เพิ่มการคำนวณทรงกรวย ***
    calculate_cone(ice_cream_cone);
    vTaskDelay(pdMS_TO_TICKS(2000));

    // *** เพิ่มการแปลงหน่วย ***
    convert_meter_to_sqm_to_rai(100.0); // ลองแปลง 100 เมตร
    vTaskDelay(pdMS_TO_TICKS(2000));

    // เปรียบเทียบผลลัพธ์
    compare_results();
    vTaskDelay(pdMS_TO_TICKS(2000));

    // แสดงความรู้เพิ่มเติม
    show_math_facts();
    vTaskDelay(pdMS_TO_TICKS(2000));

    ESP_LOGI(TAG, "\n✅ เสร็จสิ้นการคำนวณทั้งหมด!");
    ESP_LOGI(TAG, "🎓 ได้เรียนรู้: คณิตศาสตร์ขั้นสูง, struct, #define, และฟังก์ชันคณิตศาสตร์");
}