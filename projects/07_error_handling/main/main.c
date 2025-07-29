#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "ERROR_HANDLING";

typedef enum {
    ERROR_NONE = 0,
    ERROR_DIVISION_BY_ZERO,
    ERROR_INVALID_INPUT,
    ERROR_OUT_OF_RANGE,
    ERROR_NEGATIVE_VALUE,
    ERROR_OVERFLOW,
    ERROR_UNDERFLOW
} error_code_t;

typedef struct {
    double result;
    error_code_t error;
    char message[200];
} calculation_result_t;

void show_ascii_art(error_code_t error) {
    switch(error) {
        case ERROR_NONE:
            ESP_LOGI(TAG, "   ✅ SUCCESS ✅");
            ESP_LOGI(TAG, "      🎉🎉🎉");
            ESP_LOGI(TAG, "    สำเร็จแล้ว!");
            break;
        case ERROR_DIVISION_BY_ZERO:
            ESP_LOGI(TAG, "   🍕 ÷ 0 = ❌");
            ESP_LOGI(TAG, "   😱 โอ้ะโอ!");
            ESP_LOGI(TAG, "  ไม่มีลูกค้า!");
            break;
        case ERROR_INVALID_INPUT:
            ESP_LOGI(TAG, "   📝 ABC บาท?");
            ESP_LOGI(TAG, "   🤔 งง...");
            ESP_LOGI(TAG, "  ตัวเลขหายไป");
            break;
        case ERROR_OUT_OF_RANGE:
            ESP_LOGI(TAG, "   📈 ∞∞∞∞∞");
            ESP_LOGI(TAG, "   😵 เกินขีด!");
            ESP_LOGI(TAG, "  ใหญ่เกินไป");
            break;
        default:
            ESP_LOGI(TAG, "   ❓ ERROR ❓");
            ESP_LOGI(TAG, "   🔧 แก้ไข");
            ESP_LOGI(TAG, "  ต้องตรวจสอบ");
    }
}

calculation_result_t safe_divide(double dividend, double divisor, const char* context) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n🔍 ตรวจสอบการหาร: %s", context);
    ESP_LOGI(TAG, "📊 %g ÷ %g = ?", dividend, divisor);

    if (divisor == 0.0) {
        result.error = ERROR_DIVISION_BY_ZERO;
        strcpy(result.message, "❌ ข้อผิดพลาด: ไม่สามารถหารด้วยศูนย์ได้!");
        ESP_LOGE(TAG, "%s", result.message);
        show_ascii_art(ERROR_DIVISION_BY_ZERO);
        ESP_LOGI(TAG, "💡 แนะนำ: ตรวจสอบจำนวนลูกค้าก่อนแบ่งพิซซ่า");
        return result;
    }

    result.result = dividend / divisor;
    if (isinf(result.result)) {
        result.error = ERROR_OVERFLOW;
        strcpy(result.message, "⚠️ เตือน: ผลลัพธ์เป็น infinity!");
        ESP_LOGW(TAG, "%s", result.message);
        return result;
    }

    result.error = ERROR_NONE;
    sprintf(result.message, "✅ สำเร็จ: %.2f ÷ %.2f = %.2f", dividend, divisor, result.result);
    ESP_LOGI(TAG, "%s", result.message);
    show_ascii_art(ERROR_NONE);
    return result;
}

calculation_result_t validate_money(double amount, const char* description) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n💰 ตรวจสอบเงิน: %s", description);
    ESP_LOGI(TAG, "💵 จำนวน: %.2f บาท", amount);

    if (amount < 0) {
        result.error = ERROR_NEGATIVE_VALUE;
        strcpy(result.message, "❌ ข้อผิดพลาด: จำนวนเงินไม่สามารถติดลบได้!");
        ESP_LOGE(TAG, "%s", result.message);
        ESP_LOGI(TAG, "💡 แนะนำ: ตรวจสอบการคิดเงินใหม่");
        return result;
    }

    if (amount > 1000000000000.0) {
        result.error = ERROR_OUT_OF_RANGE;
        strcpy(result.message, "⚠️ เตือน: จำนวนเงินเกินขีดจำกัดระบบ!");
        ESP_LOGW(TAG, "%s", result.message);
        show_ascii_art(ERROR_OUT_OF_RANGE);
        ESP_LOGI(TAG, "💡 แนะนำ: ใช้ระบบธนาคารกลาง");
        return result;
    }

    double rounded = round(amount * 100) / 100;
    if (fabs(amount - rounded) > 0.001) {
        ESP_LOGW(TAG, "⚠️ เตือน: ปัดเศษจาก %.4f เป็น %.2f บาท", amount, rounded);
        amount = rounded;
    }

    result.result = amount;
    result.error = ERROR_NONE;
    sprintf(result.message, "✅ จำนวนเงินถูกต้อง: %.2f บาท", amount);
    ESP_LOGI(TAG, "%s", result.message);
    return result;
}

calculation_result_t validate_number(const char* input, const char* field_name) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n🔢 ตรวจสอบตัวเลข: %s", field_name);
    ESP_LOGI(TAG, "📝 ข้อมูลที่ป้อน: '%s'", input);

    if (input == NULL || strlen(input) == 0) {
        result.error = ERROR_INVALID_INPUT;
        strcpy(result.message, "❌ ข้อผิดพลาด: ไม่มีข้อมูล!");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    char* endptr;
    double value = strtod(input, &endptr);

    if (*endptr != '\0') {
        result.error = ERROR_INVALID_INPUT;
        sprintf(result.message, "❌ ข้อผิดพลาด: '%s' ไม่ใช่ตัวเลข!", input);
        ESP_LOGE(TAG, "%s", result.message);
        show_ascii_art(ERROR_INVALID_INPUT);
        ESP_LOGI(TAG, "💡 แนะนำ: ใช้เฉพาะตัวเลข 0-9 และจุดทศนิยม");
        return result;
    }

    if (isnan(value) || isinf(value)) {
        result.error = ERROR_INVALID_INPUT;
        strcpy(result.message, "❌ ข้อผิดพลาด: ตัวเลขไม่ถูกต้อง!");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    result.result = value;
    result.error = ERROR_NONE;
    sprintf(result.message, "✅ ตัวเลขถูกต้อง: %.2f", value);
    ESP_LOGI(TAG, "%s", result.message);
    return result;
}

calculation_result_t calculate_interest(double principal, double rate, int years) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n🏦 คำนวณดอกเบี้ย");
    ESP_LOGI(TAG, "💰 เงินต้น: %.2f บาท", principal);
    ESP_LOGI(TAG, "📈 อัตราดอกเบี้ย: %.2f%% ต่อปี", rate);
    ESP_LOGI(TAG, "⏰ ระยะเวลา: %d ปี", years);

    if (principal <= 0) {
        result.error = ERROR_NEGATIVE_VALUE;
        strcpy(result.message, "❌ เงินต้นต้องมากกว่าศูนย์!");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    if (rate < -100 || rate > 100) {
        result.error = ERROR_OUT_OF_RANGE;
        strcpy(result.message, "❌ อัตราดอกเบี้ยไม่สมเหตุสมผล!");
        ESP_LOGE(TAG, "%s", result.message);
        ESP_LOGI(TAG, "💡 แนะนำ: ใช้อัตรา -100%% ถึง 100%%");
        return result;
    }

    if (years < 0 || years > 100) {
        result.error = ERROR_OUT_OF_RANGE;
        strcpy(result.message, "❌ ระยะเวลาไม่สมเหตุสมผล!");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    double interest = principal * (rate / 100.0) * years;
    double total = principal + interest;

    if (total > DBL_MAX / 2) {
        result.error = ERROR_OVERFLOW;
        strcpy(result.message, "⚠️ เตือน: ผลลัพธ์ใหญ่เกินไป!");
        ESP_LOGW(TAG, "%s", result.message);
        return result;
    }

    result.result = total;
    result.error = ERROR_NONE;
    sprintf(result.message, "✅ ดอกเบี้ย: %.2f บาท, รวม: %.2f บาท", interest, total);
    ESP_LOGI(TAG, "%s", result.message);
    return result;
}

calculation_result_t validate_email(const char* email) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n📧 ตรวจสอบอีเมล: '%s'", email);

    if (email == NULL || strlen(email) < 5) {
        result.error = ERROR_INVALID_INPUT;
        snprintf(result.message, sizeof(result.message), "❌ อีเมลว่างหรือสั้นเกินไป");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    const char* at = strchr(email, '@');
    const char* dot = strrchr(email, '.');

    if (!at || !dot || at >= dot || email[0] == '@' || email[0] == '.' || email[strlen(email)-1] == '.') {
        result.error = ERROR_INVALID_INPUT;
        snprintf(result.message, sizeof(result.message), "❌ อีเมลรูปแบบไม่ถูกต้อง (ต้องมี @ และ .)");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    if (strchr(email, ' ')) {
        result.error = ERROR_INVALID_INPUT;
        snprintf(result.message, sizeof(result.message), "❌ อีเมลต้องไม่มีช่องว่าง");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    result.error = ERROR_NONE;
    snprintf(result.message, sizeof(result.message), "✅ อีเมลถูกต้อง: %s", email);
    ESP_LOGI(TAG, "%s", result.message);
    return result;
}

// ...existing code...

calculation_result_t validate_phone(const char* phone) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n📱 ตรวจสอบเบอร์โทรศัพท์: '%s'", phone);

    if (phone == NULL || strlen(phone) < 9 || strlen(phone) > 15) {
        result.error = ERROR_INVALID_INPUT;
        snprintf(result.message, sizeof(result.message), "❌ เบอร์โทรศัพท์ว่างหรือความยาวไม่ถูกต้อง (9-15 หลัก)");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    for (size_t i = 0; i < strlen(phone); ++i) {
        if (phone[i] < '0' || phone[i] > '9') {
            result.error = ERROR_INVALID_INPUT;
            snprintf(result.message, sizeof(result.message), "❌ เบอร์โทรศัพท์ต้องเป็นตัวเลขเท่านั้น");
            ESP_LOGE(TAG, "%s", result.message);
            return result;
        }
    }

    result.error = ERROR_NONE;
    snprintf(result.message, sizeof(result.message), "✅ เบอร์โทรศัพท์ถูกต้อง: %s", phone);
    ESP_LOGI(TAG, "%s", result.message);
    return result;
}

calculation_result_t validate_thai_id(const char* id) {
    calculation_result_t result = {0};
    ESP_LOGI(TAG, "\n🆔 ตรวจสอบรหัสประจำตัวประชาชน: '%s'", id);

    if (id == NULL || strlen(id) != 13) {
        result.error = ERROR_INVALID_INPUT;
        snprintf(result.message, sizeof(result.message), "❌ รหัสประชาชนต้องมี 13 หลัก");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }
    for (size_t i = 0; i < 13; ++i) {
        if (id[i] < '0' || id[i] > '9') {
            result.error = ERROR_INVALID_INPUT;
            snprintf(result.message, sizeof(result.message), "❌ ต้องเป็นตัวเลขเท่านั้น");
            ESP_LOGE(TAG, "%s", result.message);
            return result;
        }
    }
    // ตรวจสอบ checksum
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        sum += (id[i] - '0') * (13 - i);
    }
    int check = (11 - (sum % 11)) % 10;
    if (check != (id[12] - '0')) {
        result.error = ERROR_INVALID_INPUT;
        snprintf(result.message, sizeof(result.message), "❌ รหัสประชาชนไม่ถูกต้อง (checksum ผิด)");
        ESP_LOGE(TAG, "%s", result.message);
        return result;
    }

    result.error = ERROR_NONE;
    snprintf(result.message, sizeof(result.message), "✅ รหัสประชาชนถูกต้อง: %s", id);
    ESP_LOGI(TAG, "%s", result.message);
    return result;
}


void pizza_shop_scenario(void) {
    ESP_LOGI(TAG, "\n🍕 === สถานการณ์ร้านพิซซ่า ===");
    ESP_LOGI(TAG, "📖 วันนี้ฝนตก ไม่มีลูกค้ามากิน");
    calculation_result_t result;

    result = safe_divide(12, 4, "แบ่งพิซซ่า 12 ชิ้นให้ลูกค้า 4 คน");
    ESP_LOGI(TAG, "%s", result.message);  // ✅ ใช้ result
    vTaskDelay(pdMS_TO_TICKS(2000));

    result = safe_divide(12, 0, "แบ่งพิซซ่า 12 ชิ้นให้ลูกค้า 0 คน");
    ESP_LOGI(TAG, "%s", result.message);  // ✅ ใช้ result
    vTaskDelay(pdMS_TO_TICKS(2000));

    ESP_LOGI(TAG, "\n🌞 ฝนหยุดแล้ว! มีลูกค้ามา 3 คน");
    result = safe_divide(12, 3, "แบ่งพิซซ่า 12 ชิ้นให้ลูกค้า 3 คน");
    ESP_LOGI(TAG, "%s", result.message);  // ✅ ใช้ result
}


void shop_scenario(void) {
    ESP_LOGI(TAG, "\n🛒 === สถานการณ์ร้านขายของ ===");
    calculation_result_t result;

    result = validate_number("ABC", "ราคาสินค้า");
    ESP_LOGI(TAG, "%s", result.message);

    result = validate_number("12.50", "ราคาสินค้า");
    ESP_LOGI(TAG, "%s", result.message);

    result = validate_money(-50.0, "เงินทอน");
    ESP_LOGI(TAG, "%s", result.message);

    result = validate_money(25.75, "เงินทอน");
    ESP_LOGI(TAG, "%s", result.message);
}


void bank_scenario(void) {
    ESP_LOGI(TAG, "\n🏦 === สถานการณ์ธนาคาร ===");
    calculation_result_t result;

    result = calculate_interest(100000, 2.5, 5);
    ESP_LOGI(TAG, "%s", result.message);  // ✅
    vTaskDelay(pdMS_TO_TICKS(2000));

    result = calculate_interest(100000, -5.0, 5);
    ESP_LOGI(TAG, "%s", result.message);  // ✅
    vTaskDelay(pdMS_TO_TICKS(2000));

    result = validate_money(999999999999.0, "เงินฝาก");
    ESP_LOGI(TAG, "%s", result.message);  // ✅
    vTaskDelay(pdMS_TO_TICKS(2000));

    result = calculate_interest(100000, 3.0, 10);
    ESP_LOGI(TAG, "%s", result.message);  // ✅
}


void show_error_handling_summary(void) {
    ESP_LOGI(TAG, "\n📚 === สรุปการจัดการข้อผิดพลาด ===");
    ESP_LOGI(TAG, "╔════════════════════════════════════════════╗");
    ESP_LOGI(TAG, "║              ประเภทข้อผิดพลาด             ║");
    ESP_LOGI(TAG, "╠════════════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 🚫 Division by Zero - หารด้วยศูนย์        ║");
    ESP_LOGI(TAG, "║ 📝 Invalid Input - ข้อมูลผิดประเภท       ║");
    ESP_LOGI(TAG, "║ 📊 Out of Range - เกินขอบเขต             ║");
    ESP_LOGI(TAG, "║ ➖ Negative Value - ค่าติดลบไม่เหมาะสม   ║");
    ESP_LOGI(TAG, "║ ⬆️ Overflow - ข้อมูลล้น                  ║");
    ESP_LOGI(TAG, "╚════════════════════════════════════════════╝");

    ESP_LOGI(TAG, "\n🛡️ === หลักการจัดการข้อผิดพลาด ===");
    ESP_LOGI(TAG, "✅ 1. ตรวจสอบข้อมูลก่อนคำนวณ");
    ESP_LOGI(TAG, "✅ 2. แสดงข้อความที่เข้าใจง่าย");
    ESP_LOGI(TAG, "✅ 3. ให้คำแนะนำในการแก้ไข");
    ESP_LOGI(TAG, "✅ 4. ป้องกันโปรแกรมค้างหรือ crash");
    ESP_LOGI(TAG, "✅ 5. ใช้ enum และ struct จัดการสถานะ");
}

// ...existing code...

void app_main(void) {
    ESP_LOGI(TAG, "🚀 เริ่มต้นโปรแกรมจัดการข้อผิดพลาด!");
    ESP_LOGI(TAG, "🛡️ การตรวจสอบและป้องกันข้อผิดพลาด\n");

    calculation_result_t result;

    vTaskDelay(pdMS_TO_TICKS(1000));
    pizza_shop_scenario();
    vTaskDelay(pdMS_TO_TICKS(3000));

    shop_scenario();
    vTaskDelay(pdMS_TO_TICKS(3000));

    bank_scenario();
    vTaskDelay(pdMS_TO_TICKS(3000));

    result = validate_email("rusneedakuwi@gmail.com");
    result = validate_phone("0926782094");

    // === ระบบ retry mechanism สำหรับรหัสประชาชน ===
    const char* thai_ids[] = {
        "75294555455117", // ผิด
        "1959900800028", // ถูก (ตัวอย่าง)
        "78495896536457"  // ผิด
    };
    int max_retry = 3;
    int retry = 0;
    do {
        result = validate_thai_id(thai_ids[retry]);
        if (result.error == ERROR_NONE) {
            ESP_LOGI(TAG, "🎉 ตรวจสอบรหัสประชาชนผ่านในรอบที่ %d", retry + 1);
            break;
        } else {
            ESP_LOGW(TAG, "🔁 กำลังลองใหม่ (ครั้งที่ %d)", retry + 1);
        }
        retry++;
    } while (retry < max_retry);

    if (result.error != ERROR_NONE) {
        ESP_LOGE(TAG, "❌ ตรวจสอบรหัสประชาชนไม่ผ่านหลังจากลอง %d ครั้ง", max_retry);
    }

    show_error_handling_summary();

    ESP_LOGI(TAG, "\n✅ เสร็จสิ้นการเรียนรู้การจัดการข้อผิดพลาด!");
    ESP_LOGI(TAG, "🎓 ได้เรียนรู้: enum, struct, error codes, และการตรวจสอบข้อมูล");
    ESP_LOGI(TAG, "🏆 ตอนนี้คุณสามารถเขียนโค้ดที่ปลอดภัยและน่าเชื่อถือแล้ว!");
}
// ...existing code...