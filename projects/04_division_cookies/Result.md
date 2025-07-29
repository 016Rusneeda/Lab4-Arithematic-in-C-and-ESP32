# โปรเจค 4: การหาร - คุกกี้แบ่งกัน 🍪

### 📝 แบบฝึกหัดที่ 1: เปลี่ยนจำนวนคุกกี้
```c
// หาบรรทัดนี้ในโค้ด:
int total_cookies = 20;    // คุกกี้ทั้งหมด
int friends = 4;           // จำนวนเพื่อน

// ลองเปลี่ยนเป็น:
int total_cookies = 24;    // เพิ่มเป็น 24 ชิ้น
int friends = 6;           // เพิ่มเป็น 6 คน
```
ผลลัพธ์ที่ได้
```
I (13849) COOKIES_MATH: 🧮 ขั้นตอนการคิด:
I (13849) COOKIES_MATH:    คุกกี้ทั้งหมด ÷ จำนวนเพื่อน
I (13849) COOKIES_MATH:    = 24 ÷ 6
I (13849) COOKIES_MATH:    = 4 ชิ้นต่อคน
I (13849) COOKIES_MATH: 
I (13849) COOKIES_MATH: ✅ คำตอบ:
I (13849) COOKIES_MATH:    แต่ละคนได้คุกกี้ 4 ชิ้น
I (13849) COOKIES_MATH:    แบ่งได้พอดี ไม่มีเหลือ
I (13849) COOKIES_MATH:
I (13849) COOKIES_MATH: 🎨 ภาพประกอบการแบ่ง:
I (13849) COOKIES_MATH:    คุกกี้ทั้งหมด: 🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪 (24 ชิ้น)
I (13849) COOKIES_MATH:
I (13849) COOKIES_MATH:    เพื่อนคนที่ 1: 
I (13849) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (13849) COOKIES_MATH:    เพื่อนคนที่ 2: 
I (13849) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (13849) COOKIES_MATH:    เพื่อนคนที่ 3: 
I (13849) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (13849) COOKIES_MATH:    เพื่อนคนที่ 4: 
I (13849) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (13849) COOKIES_MATH:    เพื่อนคนที่ 5: 
I (13849) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (13849) COOKIES_MATH:    เพื่อนคนที่ 6: 
I (13849) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (13849) COOKIES_MATH: 
I (13849) COOKIES_MATH: 💡 ตัวอย่างเพิ่มเติม:
I (13849) COOKIES_MATH:    คุกกี้ 15 ชิ้น แบ่งให้ 3 คน
I (13849) COOKIES_MATH:    = 15 ÷ 3 = 5 ชิ้นต่อคน, เหลือ 0 ชิ้น
I (13849) COOKIES_MATH:
I (13849) COOKIES_MATH:    คุกกี้ 13 ชิ้น แบ่งให้ 4 คน
I (13849) COOKIES_MATH:    = 13 ÷ 4 = 3 ชิ้นต่อคน, เหลือ 1 ชิ้น
I (13849) COOKIES_MATH:    (หารไม่ลงตัว)
I (13849) COOKIES_MATH:
I (13849) COOKIES_MATH: ⚠️  กรณีพิเศษ - หารด้วยศูนย์:
I (13849) COOKIES_MATH:    ถ้าไม่มีเพื่อนมาแบ่ง (หารด้วย 0)
I (13849) COOKIES_MATH:    ไม่สามารถคำนวณได้ในทางคณิตศาสตร์
I (13849) COOKIES_MATH:    ในชีวิตจริง: คุกกี้จะเหลือทั้งหมด
I (13849) COOKIES_MATH: 
I (13849) COOKIES_MATH: 🔄 ความสัมพันธ์กับการคูณ:
I (13849) COOKIES_MATH:    การหาร: 24 ÷ 6 = 4
I (13849) COOKIES_MATH:    การคูณ: 4 × 6 = 24
I (13849) COOKIES_MATH:    การหารและการคูณเป็นการดำเนินการตรงข้ามกัน
I (13849) COOKIES_MATH:
I (13849) COOKIES_MATH: 📊 สรุปการดำเนินการทั้งหมด:
I (13849) COOKIES_MATH:    การบวก (+): เพิ่มจำนวน
I (13849) COOKIES_MATH:    การลบ (-): ลดจำนวน
I (13849) COOKIES_MATH:    การคูณ (×): บวกซ้ำๆ หลายชุด
I (13859) COOKIES_MATH:    การหาร (÷): แบ่งออกเป็นกลุ่มเท่าๆ กัน
I (13859) COOKIES_MATH:
I (13859) COOKIES_MATH: 🎓 แนวคิดขั้นสูง:
I (13859) COOKIES_MATH:    1. การหารจะได้ผลหาร (quotient) และเศษ (remainder)
I (13859) COOKIES_MATH:    2. ในภาษา C:
I (13859) COOKIES_MATH:       ผลหาร = a / b
I (13859) COOKIES_MATH:       เศษ = a % b
I (13859) COOKIES_MATH:    3. การตรวจสอบการหารด้วยศูนย์เป็นสิ่งสำคัญ
I (13859) COOKIES_MATH:    4. การหารด้วย 1 จะได้ตัวเลขเดิม
I (13859) COOKIES_MATH:    5. การหารตัวเลขด้วยตัวมันเองจะได้ 1
I (13859) COOKIES_MATH: 
I (13859) COOKIES_MATH: 📚 สิ่งที่เรียนรู้:
I (13859) COOKIES_MATH:    1. การหารเลข (Division): a ÷ b = c
I (13859) COOKIES_MATH:    2. การใช้ Modulo operator (%) หาเศษ
I (13859) COOKIES_MATH:    3. การตรวจสอบการหารด้วยศูนย์
I (13859) COOKIES_MATH:    4. ความแตกต่างระหว่างหารลงตัวและไม่ลงตัว
I (13859) COOKIES_MATH:    5. ความสัมพันธ์ระหว่างการหารและการคูณ
I (13859) COOKIES_MATH:    6. การจัดการกรณีพิเศษ (Error Handling)
I (13859) COOKIES_MATH:
I (13859) COOKIES_MATH: 🎉 จบโปรแกรมแบ่งคุกกี้!
I (13859) COOKIES_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 05_mixed_shopping
I (15859) main_task: Returned from app_main()

```
<img width="1026" height="951" alt="image" src="https://github.com/user-attachments/assets/417f3bce-6660-4649-8d9d-bcb1029e57de" />

### 📝 แบบฝึกหัดที่ 2: เพิ่มการตรวจสอบหารลงตัว
เพิ่มการตรวจสอบว่าหารลงตัวไหม:
```c
int cookies_per_person = total_cookies / friends;
int remaining_cookies = total_cookies % friends;

if (remaining_cookies == 0) {
    ESP_LOGI(TAG, "✅ หารลงตัว! ทุกคนได้เท่ากัน");
} else {
    ESP_LOGI(TAG, "⚠️ หารไม่ลงตัว! เหลือ %d ชิ้น", remaining_cookies);
}
```
ผลลัพธ์ที่ได้
```

I (14932) COOKIES_MATH: ✅ หารลงตัว! ทุกคนได้เท่ากัน
I (14932) COOKIES_MATH: 
I (14932) COOKIES_MATH: 
I (14932) COOKIES_MATH: 🧮 ขั้นตอนการคิด:
I (14932) COOKIES_MATH:    คุกกี้ทั้งหมด ÷ จำนวนเพื่อน
I (14932) COOKIES_MATH:    = 24 ÷ 6
I (14932) COOKIES_MATH:    = 4 ชิ้นต่อคน
I (14932) COOKIES_MATH:
I (14932) COOKIES_MATH: ✅ คำตอบ:
I (14932) COOKIES_MATH:    แต่ละคนได้คุกกี้ 4 ชิ้น
I (14932) COOKIES_MATH:    แบ่งได้พอดี ไม่มีเหลือ
I (14932) COOKIES_MATH: 
I (14932) COOKIES_MATH: 🎨 ภาพประกอบการแบ่ง:
I (14932) COOKIES_MATH:    คุกกี้ทั้งหมด: 🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪 (24 ชิ้น)
I (14932) COOKIES_MATH:
I (14932) COOKIES_MATH:    เพื่อนคนที่ 1: 
I (14932) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (14932) COOKIES_MATH:    เพื่อนคนที่ 2: 
I (14932) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (14932) COOKIES_MATH:    เพื่อนคนที่ 3: 
I (14932) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (14932) COOKIES_MATH:    เพื่อนคนที่ 4: 
I (14932) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (14932) COOKIES_MATH:    เพื่อนคนที่ 5: 
I (14932) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (14932) COOKIES_MATH:    เพื่อนคนที่ 6: 
I (14932) COOKIES_MATH: 🍪🍪🍪 (4 ชิ้น)
I (14932) COOKIES_MATH: 
I (14932) COOKIES_MATH: 💡 ตัวอย่างเพิ่มเติม:
I (14932) COOKIES_MATH:    คุกกี้ 15 ชิ้น แบ่งให้ 3 คน
I (14932) COOKIES_MATH:    = 15 ÷ 3 = 5 ชิ้นต่อคน, เหลือ 0 ชิ้น
I (14932) COOKIES_MATH: 
I (14932) COOKIES_MATH:    คุกกี้ 13 ชิ้น แบ่งให้ 4 คน
I (14942) COOKIES_MATH:    = 13 ÷ 4 = 3 ชิ้นต่อคน, เหลือ 1 ชิ้น
I (14942) COOKIES_MATH:    (หารไม่ลงตัว)
I (14942) COOKIES_MATH:
I (14942) COOKIES_MATH: ⚠️  กรณีพิเศษ - หารด้วยศูนย์:
I (14942) COOKIES_MATH:    ถ้าไม่มีเพื่อนมาแบ่ง (หารด้วย 0)
I (14942) COOKIES_MATH:    ไม่สามารถคำนวณได้ในทางคณิตศาสตร์
I (14942) COOKIES_MATH:    ในชีวิตจริง: คุกกี้จะเหลือทั้งหมด
I (14942) COOKIES_MATH: 
I (14942) COOKIES_MATH: 🔄 ความสัมพันธ์กับการคูณ:
I (14942) COOKIES_MATH:    การหาร: 24 ÷ 6 = 4
I (14942) COOKIES_MATH:    การคูณ: 4 × 6 = 24
I (14942) COOKIES_MATH:    การหารและการคูณเป็นการดำเนินการตรงข้ามกัน
I (14942) COOKIES_MATH: 
I (14942) COOKIES_MATH: 📊 สรุปการดำเนินการทั้งหมด:
I (14942) COOKIES_MATH:    การบวก (+): เพิ่มจำนวน
I (14942) COOKIES_MATH:    การลบ (-): ลดจำนวน
I (14942) COOKIES_MATH:    การคูณ (×): บวกซ้ำๆ หลายชุด
I (14942) COOKIES_MATH:    การหาร (÷): แบ่งออกเป็นกลุ่มเท่าๆ กัน
I (14952) COOKIES_MATH:
I (14952) COOKIES_MATH: 🎓 แนวคิดขั้นสูง:
I (14952) COOKIES_MATH:    1. การหารจะได้ผลหาร (quotient) และเศษ (remainder)
I (14952) COOKIES_MATH:    2. ในภาษา C:
I (14952) COOKIES_MATH:       ผลหาร = a / b
I (14952) COOKIES_MATH:       เศษ = a % b
I (14952) COOKIES_MATH:    3. การตรวจสอบการหารด้วยศูนย์เป็นสิ่งสำคัญ
I (14952) COOKIES_MATH:    4. การหารด้วย 1 จะได้ตัวเลขเดิม
I (14952) COOKIES_MATH:    5. การหารตัวเลขด้วยตัวมันเองจะได้ 1
I (14952) COOKIES_MATH:
I (14952) COOKIES_MATH: 📚 สิ่งที่เรียนรู้:
I (14952) COOKIES_MATH:    1. การหารเลข (Division): a ÷ b = c
I (14952) COOKIES_MATH:    2. การใช้ Modulo operator (%) หาเศษ
I (14952) COOKIES_MATH:    3. การตรวจสอบการหารด้วยศูนย์
I (14952) COOKIES_MATH:    4. ความแตกต่างระหว่างหารลงตัวและไม่ลงตัว
I (14952) COOKIES_MATH:    5. ความสัมพันธ์ระหว่างการหารและการคูณ
I (14952) COOKIES_MATH:    6. การจัดการกรณีพิเศษ (Error Handling)
I (14952) COOKIES_MATH: 
I (14952) COOKIES_MATH: 🎉 จบโปรแกรมแบ่งคุกกี้!
I (14952) COOKIES_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 05_mixed_shopping
I (16952) main_task: Returned from app_main()
```


<img width="843" height="904" alt="image" src="https://github.com/user-attachments/assets/f7869086-a14f-4e33-a5f4-332d645524d3" />



### 📝 แบบฝึกหัดที่ 3: หาจำนวนเพื่อนที่เหมาะสม
ลองหาว่าคุกกี้ 30 ชิ้น จะแจกให้กี่คนได้หารลงตัว:
```c
int cookies = 30;
ESP_LOGI(TAG, "🔍 คุกกี้ %d ชิ้น หารลงตัวกับ:", cookies);

for (int people = 1; people <= 10; people++) {
    if (cookies % people == 0) {
        ESP_LOGI(TAG, "   ✅ %d คน → คนละ %d ชิ้น", 
                 people, cookies / people);
    }
}
```
ผลลัพธ์ที่ได้
```
I (15409) COOKIES_MATH: 🔍 คุกกี้ 30 ชิ้น หารลงตัวกับ:
I (15409) COOKIES_MATH:    ✅ 1 คน → คนละ 30 ชิ้น
I (15409) COOKIES_MATH:    ✅ 2 คน → คนละ 15 ชิ้น
I (15409) COOKIES_MATH:    ✅ 3 คน → คนละ 10 ชิ้น
I (15409) COOKIES_MATH:    ✅ 5 คน → คนละ 6 ชิ้น
I (15409) COOKIES_MATH:    ✅ 6 คน → คนละ 5 ชิ้น
I (15409) COOKIES_MATH:    ✅ 10 คน → คนละ 3 ชิ้น
I (17409) main_task: Returned from app_main()
```
<img width="904" height="932" alt="image" src="https://github.com/user-attachments/assets/800fe939-a3de-40d8-92ba-ea5e6b0ee74d" />

