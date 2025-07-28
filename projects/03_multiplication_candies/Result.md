# โปรเจค 3: การคูณ - ลูกอมในถุง 🍬

### 📝 แบบฝึกหัดที่ 1: เปลี่ยนจำนวนถุงลูกอม
```c
// หาบรรทัดนี้ในโค้ด:
int candy_bags = 5;         // จำนวนถุง
int candies_per_bag = 6;    // ลูกอมต่อถุง

// ลองเปลี่ยนเป็น:
int candy_bags = 7;         // เพิ่มเป็น 7 ถุง
int candies_per_bag = 8;    // ลูกอมถุงละ 8 เม็ด
```
ผลลัพธ์ที่ได้
```
I (13040) CANDIES_MATH: 🧮 ขั้นตอนการคิด:
I (13040) CANDIES_MATH:    จำนวนถุง × ลูกอมต่อถุง
I (13040) CANDIES_MATH:    = 7 × 8
I (13040) CANDIES_MATH:    = 56 เม็ด
I (13040) CANDIES_MATH: 
I (13040) CANDIES_MATH: ✅ คำตอบ:
I (13040) CANDIES_MATH:    มีลูกอมทั้งหมด 56 เม็ด
I (13040) CANDIES_MATH:
I (13040) CANDIES_MATH: 🎨 ภาพประกอบ:
I (13040) CANDIES_MATH:    ถุงที่ 1: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (13040) CANDIES_MATH:    ถุงที่ 2: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (13040) CANDIES_MATH:    ถุงที่ 3: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (13040) CANDIES_MATH:    ถุงที่ 4: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (13040) CANDIES_MATH:    ถุงที่ 5: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (13040) CANDIES_MATH:    รวม:     56 เม็ด
I (13040) CANDIES_MATH: 
I (13040) CANDIES_MATH: 🔄 เปรียบเทียบกับการบวกซ้ำๆ:
I (13040) CANDIES_MATH:    การคูณ: 7 × 8 = 56
I (13040) CANDIES_MATH:    การบวกซ้ำๆ:
I (13040) CANDIES_MATH:                   8
I (13040) CANDIES_MATH:                 + 8
I (13040) CANDIES_MATH:                 + 8
I (13040) CANDIES_MATH:                 + 8
I (13040) CANDIES_MATH:                 + 8
I (13040) CANDIES_MATH:                 + 8
I (13040) CANDIES_MATH:                 + 8 = 56
I (13040) CANDIES_MATH:    ผลลัพธ์เหมือนกัน! การคูณคือการบวกซ้ำๆ
I (13040) CANDIES_MATH:
I (13040) CANDIES_MATH: 📊 ตารางสูตรคูณ 8:
I (13040) CANDIES_MATH:    1 × 8 = 8
I (13340) CANDIES_MATH:    2 × 8 = 16
I (13640) CANDIES_MATH:    3 × 8 = 24
I (13940) CANDIES_MATH:    4 × 8 = 32
I (14240) CANDIES_MATH:    5 × 8 = 40
I (14540) CANDIES_MATH:    6 × 8 = 48
I (14840) CANDIES_MATH:    7 × 8 = 56
I (15140) CANDIES_MATH:    8 × 8 = 64
I (15440) CANDIES_MATH:    9 × 8 = 72
I (15740) CANDIES_MATH:    10 × 8 = 80
I (16040) CANDIES_MATH: 
I (16040) CANDIES_MATH: 💡 ตัวอย่างเพิ่มเติม:
I (16040) CANDIES_MATH:    ถ้ามีถุงลูกอม 3 ถุง ถุงละ 8 เม็ด
I (16040) CANDIES_MATH:    จะได้ลูกอม 3 × 8 = 24 เม็ด
I (16040) CANDIES_MATH: 
I (16040) CANDIES_MATH:    ถ้ามีถุงลูกอม 7 ถุง ถุงละ 4 เม็ด
I (16040) CANDIES_MATH:    จะได้ลูกอม 7 × 4 = 28 เม็ด
I (16040) CANDIES_MATH:
I (16040) CANDIES_MATH: 🔄 เปรียบเทียบการดำเนินการ:
I (16040) CANDIES_MATH:    การบวก (+): เพิ่มจำนวน (เช่น ไข่ 4 + 2 = 6)
I (16040) CANDIES_MATH:    การลบ (-): ลดจำนวน (เช่น ของเล่น 8 - 3 = 5)
I (16040) CANDIES_MATH:    การคูณ (×): บวกซ้ำๆ (เช่น ลูกอม 5 × 6 = 30)
I (16040) CANDIES_MATH:
I (16040) CANDIES_MATH: 🎓 แนวคิดขั้นสูง:
I (16040) CANDIES_MATH:    1. การคูณมีคุณสมบัติการสับเปลี่ยน:
I (16040) CANDIES_MATH:       7 × 8 = 8 × 7 = 56
I (16040) CANDIES_MATH:    2. การคูณด้วย 0 จะได้ 0 เสมอ:
I (16050) CANDIES_MATH:       7 × 0 = 0 (ไม่มีถุงลูกอม)
I (16050) CANDIES_MATH:    3. การคูณด้วย 1 จะได้ตัวเลขเดิม:
I (16050) CANDIES_MATH:       8 × 1 = 8 (มีถุงเดียว)
I (16050) CANDIES_MATH:
I (16050) CANDIES_MATH: 📚 สิ่งที่เรียนรู้:
I (16050) CANDIES_MATH:    1. การคูณเลข (Multiplication): a × b = c
I (16050) CANDIES_MATH:    2. การใช้ for loop สำหรับการทำซ้ำ
I (16050) CANDIES_MATH:    3. ความสัมพันธ์ระหว่างการคูณและการบวกซ้ำๆ
I (16050) CANDIES_MATH:    4. คุณสมบัติพิเศษของการคูณ
I (16050) CANDIES_MATH:    5. การแสดงผลแบบตาราง
I (16050) CANDIES_MATH:
I (16050) CANDIES_MATH: 🎉 จบโปรแกรมนับลูกอมในถุง!
I (16050) CANDIES_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 04_division_cookies
I (18060) main_task: Returned from app_main()

```
<img width="898" height="953" alt="image" src="https://github.com/user-attachments/assets/1bee18c8-e5d6-4d55-b21d-80fbcb0c7d67" />

### 📝 แบบฝึกหัดที่ 2: เพิ่มลูกอมหลายรส
เพิ่มลูกอมหลายรส:
```c
int strawberry_bags = 3;    // ถุงรสสตรอเบอร์รี่
int orange_bags = 2;        // ถุงรสส้ม
int grape_bags = 4;         // ถุงรสองุ่น

int total_bags = strawberry_bags + orange_bags + grape_bags;
int total_candies = total_bags * candies_per_bag;

ESP_LOGI(TAG, "🍓 สตรอเบอร์รี่: %d ถุง = %d เม็ด", 
         strawberry_bags, strawberry_bags * candies_per_bag);
ESP_LOGI(TAG, "🍊 รสส้ม: %d ถุง = %d เม็ด", 
         orange_bags, orange_bags * candies_per_bag);
ESP_LOGI(TAG, "🍇 รสองุ่น: %d ถุง = %d เม็ด", 
         grape_bags, grape_bags * candies_per_bag);
```
ผลลัพธ์ที่ได้
```
I (21000) CANDIES_MATH: 🍓 สตรอเบอร์รี่: 3 ถุง = 24 เม็ด
I (21000) CANDIES_MATH: 🍊 รสส้ม: 2 ถุง = 16 เม็ด
I (21000) CANDIES_MATH: 🍇 รสองุ่น: 4 ถุง = 32 เม็ด
I (21000) CANDIES_MATH: 🧮 ขั้นตอนการคิด:
I (21000) CANDIES_MATH:    จำนวนถุง × ลูกอมต่อถุง
I (21000) CANDIES_MATH:    = 7 × 8
I (21000) CANDIES_MATH:    = 56 เม็ด
I (21000) CANDIES_MATH:
I (21000) CANDIES_MATH: ✅ คำตอบ:
I (21000) CANDIES_MATH:    มีลูกอมทั้งหมด 56 เม็ด
I (21000) CANDIES_MATH:
I (21000) CANDIES_MATH: 🎨 ภาพประกอบ:
I (21000) CANDIES_MATH:    ถุงที่ 1: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (21000) CANDIES_MATH:    ถุงที่ 2: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (21010) CANDIES_MATH:    ถุงที่ 3: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (21010) CANDIES_MATH:    ถุงที่ 4: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (21010) CANDIES_MATH:    ถุงที่ 5: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (21010) CANDIES_MATH:    รวม:     56 เม็ด
I (21010) CANDIES_MATH: 
I (21010) CANDIES_MATH: 🔄 เปรียบเทียบกับการบวกซ้ำๆ:
I (21010) CANDIES_MATH:    การคูณ: 7 × 8 = 56
I (21010) CANDIES_MATH:    การบวกซ้ำๆ:
I (21010) CANDIES_MATH:                   8
I (21010) CANDIES_MATH:                 + 8
I (21010) CANDIES_MATH:                 + 8
I (21020) CANDIES_MATH:                 + 8
I (21020) CANDIES_MATH:                 + 8
I (21020) CANDIES_MATH:                 + 8
I (21020) CANDIES_MATH:                 + 8 = 56
I (21020) CANDIES_MATH:    ผลลัพธ์เหมือนกัน! การคูณคือการบวกซ้ำๆ
I (21020) CANDIES_MATH: 
I (21020) CANDIES_MATH: 📊 ตารางสูตรคูณ 8:
I (21020) CANDIES_MATH:    1 × 8 = 8
I (21320) CANDIES_MATH:    2 × 8 = 16
I (21620) CANDIES_MATH:    3 × 8 = 24
I (21920) CANDIES_MATH:    4 × 8 = 32
I (22220) CANDIES_MATH:    5 × 8 = 40
I (22520) CANDIES_MATH:    6 × 8 = 48
I (22820) CANDIES_MATH:    7 × 8 = 56
I (23120) CANDIES_MATH:    8 × 8 = 64
I (23420) CANDIES_MATH:    9 × 8 = 72
I (23720) CANDIES_MATH:    10 × 8 = 80
I (24020) CANDIES_MATH: 
I (24020) CANDIES_MATH: 💡 ตัวอย่างเพิ่มเติม:
I (24020) CANDIES_MATH:    ถ้ามีถุงลูกอม 3 ถุง ถุงละ 8 เม็ด
I (24020) CANDIES_MATH:    จะได้ลูกอม 3 × 8 = 24 เม็ด
I (24020) CANDIES_MATH:
I (24020) CANDIES_MATH:    ถ้ามีถุงลูกอม 7 ถุง ถุงละ 4 เม็ด
I (24020) CANDIES_MATH:    จะได้ลูกอม 7 × 4 = 28 เม็ด
I (24020) CANDIES_MATH:
I (24020) CANDIES_MATH: 🔄 เปรียบเทียบการดำเนินการ:
I (24020) CANDIES_MATH:    การบวก (+): เพิ่มจำนวน (เช่น ไข่ 4 + 2 = 6)
I (24020) CANDIES_MATH:    การลบ (-): ลดจำนวน (เช่น ของเล่น 8 - 3 = 5)
I (24020) CANDIES_MATH:    การคูณ (×): บวกซ้ำๆ (เช่น ลูกอม 5 × 6 = 30)
I (24020) CANDIES_MATH: 
I (24020) CANDIES_MATH: 🎓 แนวคิดขั้นสูง:
I (24020) CANDIES_MATH:    1. การคูณมีคุณสมบัติการสับเปลี่ยน:
I (24020) CANDIES_MATH:       7 × 8 = 8 × 7 = 56
I (24030) CANDIES_MATH:    2. การคูณด้วย 0 จะได้ 0 เสมอ:
I (24030) CANDIES_MATH:       7 × 0 = 0 (ไม่มีถุงลูกอม)
I (24030) CANDIES_MATH:    3. การคูณด้วย 1 จะได้ตัวเลขเดิม:
I (24030) CANDIES_MATH:       8 × 1 = 8 (มีถุงเดียว)
I (24030) CANDIES_MATH: 
I (24030) CANDIES_MATH: 📚 สิ่งที่เรียนรู้:
I (24030) CANDIES_MATH:    1. การคูณเลข (Multiplication): a × b = c
I (24030) CANDIES_MATH:    2. การใช้ for loop สำหรับการทำซ้ำ
I (24030) CANDIES_MATH:    3. ความสัมพันธ์ระหว่างการคูณและการบวกซ้ำๆ
I (24030) CANDIES_MATH:    4. คุณสมบัติพิเศษของการคูณ
I (24030) CANDIES_MATH:    5. การแสดงผลแบบตาราง
I (24030) CANDIES_MATH: 
I (24040) CANDIES_MATH: 🎉 จบโปรแกรมนับลูกอมในถุง!
I (24040) CANDIES_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 04_division_cookies
I (26040) main_task: Returned from app_main()

```
<img width="719" height="945" alt="image" src="https://github.com/user-attachments/assets/ed57e34e-fa29-4a91-b6bf-c7cac1d137e9" />

### 📝 แบบฝึกหัดที่ 3: สร้างตารางสูตรคูณ
เพิ่มการแสดงตารางสูตรคูณ:
```c
ESP_LOGI(TAG, "📊 ตารางสูตรคูณของ %d:", candies_per_bag);
for (int i = 1; i <= 10; i++) {
    ESP_LOGI(TAG, "   %d x %d = %d", i, candies_per_bag, i * candies_per_bag);
}
```
ผลลัพธ์ที่ได้

```
I (15409) CANDIES_MATH: 🍓 สตรอเบอร์รี่: 3 ถุง = 24 เม็ด
I (15409) CANDIES_MATH: 🍊 รสส้ม: 2 ถุง = 16 เม็ด
I (15409) CANDIES_MATH: 🍇 รสองุ่น: 4 ถุง = 32 เม็ด
I (15409) CANDIES_MATH: 🧮 ขั้นตอนการคิด:
I (15409) CANDIES_MATH:    จำนวนถุง × ลูกอมต่อถุง
I (15409) CANDIES_MATH:    = 7 × 8
I (15409) CANDIES_MATH:    = 56 เม็ด
I (15409) CANDIES_MATH: 
I (15409) CANDIES_MATH: ✅ คำตอบ:
I (15409) CANDIES_MATH:    มีลูกอมทั้งหมด 56 เม็ด
I (15409) CANDIES_MATH: 
I (15409) CANDIES_MATH: 🎨 ภาพประกอบ:
I (15409) CANDIES_MATH:    ถุงที่ 1: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (15419) CANDIES_MATH:    ถุงที่ 2: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (15419) CANDIES_MATH:    ถุงที่ 3: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (15419) CANDIES_MATH:    ถุงที่ 4: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (15419) CANDIES_MATH:    ถุงที่ 5: 🍬🍬🍬🍬🍬🍬 (8 เม็ด)
I (15419) CANDIES_MATH:    รวม:     56 เม็ด
I (15419) CANDIES_MATH: 
I (15419) CANDIES_MATH: 🔄 เปรียบเทียบกับการบวกซ้ำๆ:
I (15419) CANDIES_MATH:    การคูณ: 7 × 8 = 56
I (15419) CANDIES_MATH:    การบวกซ้ำๆ:
I (15419) CANDIES_MATH:                   8
I (15419) CANDIES_MATH:                 + 8
I (15419) CANDIES_MATH:                 + 8
I (15419) CANDIES_MATH:                 + 8
I (15419) CANDIES_MATH:                 + 8
I (15419) CANDIES_MATH:                 + 8
I (15419) CANDIES_MATH:                 + 8 = 56
I (15419) CANDIES_MATH:    ผลลัพธ์เหมือนกัน! การคูณคือการบวกซ้ำๆ
I (15429) CANDIES_MATH: 
I (15429) CANDIES_MATH: 📊 ตารางสูตรคูณ 8:
I (15429) CANDIES_MATH:    1 × 8 = 8
I (15729) CANDIES_MATH:    2 × 8 = 16
I (16029) CANDIES_MATH:    3 × 8 = 24
I (16329) CANDIES_MATH:    4 × 8 = 32
I (16629) CANDIES_MATH:    5 × 8 = 40
I (16929) CANDIES_MATH:    6 × 8 = 48
I (17229) CANDIES_MATH:    7 × 8 = 56
I (17529) CANDIES_MATH:    8 × 8 = 64
I (17829) CANDIES_MATH:    9 × 8 = 72
I (18129) CANDIES_MATH:    10 × 8 = 80
I (18429) CANDIES_MATH: 
I (18429) CANDIES_MATH: 📊 ตารางสูตรคูณของ 8:
I (18429) CANDIES_MATH:    1 x 8 = 8
I (18429) CANDIES_MATH:    2 x 8 = 16
I (18429) CANDIES_MATH:    3 x 8 = 24
I (18429) CANDIES_MATH:    4 x 8 = 32
I (18429) CANDIES_MATH:    5 x 8 = 40
I (18429) CANDIES_MATH:    6 x 8 = 48
I (18429) CANDIES_MATH:    7 x 8 = 56
I (18429) CANDIES_MATH:    8 x 8 = 64
I (18429) CANDIES_MATH:    9 x 8 = 72
I (18429) CANDIES_MATH:    10 x 8 = 80
I (18429) CANDIES_MATH: 💡 ตัวอย่างเพิ่มเติม:
I (18429) CANDIES_MATH:    ถ้ามีถุงลูกอม 3 ถุง ถุงละ 8 เม็ด
I (18429) CANDIES_MATH:    จะได้ลูกอม 3 × 8 = 24 เม็ด
I (18429) CANDIES_MATH:
I (18429) CANDIES_MATH:    ถ้ามีถุงลูกอม 7 ถุง ถุงละ 4 เม็ด
I (18429) CANDIES_MATH:    จะได้ลูกอม 7 × 4 = 28 เม็ด
I (18429) CANDIES_MATH:
I (18429) CANDIES_MATH: 🔄 เปรียบเทียบการดำเนินการ:
I (18429) CANDIES_MATH:    การบวก (+): เพิ่มจำนวน (เช่น ไข่ 4 + 2 = 6)
I (18439) CANDIES_MATH:    การลบ (-): ลดจำนวน (เช่น ของเล่น 8 - 3 = 5)
I (18439) CANDIES_MATH:    การคูณ (×): บวกซ้ำๆ (เช่น ลูกอม 5 × 6 = 30)
I (18439) CANDIES_MATH: 
I (18439) CANDIES_MATH: 🎓 แนวคิดขั้นสูง:
I (18439) CANDIES_MATH:    1. การคูณมีคุณสมบัติการสับเปลี่ยน:
I (18439) CANDIES_MATH:       7 × 8 = 8 × 7 = 56
I (18439) CANDIES_MATH:    2. การคูณด้วย 0 จะได้ 0 เสมอ:
I (18439) CANDIES_MATH:       7 × 0 = 0 (ไม่มีถุงลูกอม)
I (18439) CANDIES_MATH:    3. การคูณด้วย 1 จะได้ตัวเลขเดิม:
I (18439) CANDIES_MATH:       8 × 1 = 8 (มีถุงเดียว)
I (18439) CANDIES_MATH:
I (18439) CANDIES_MATH: 📚 สิ่งที่เรียนรู้:
I (18439) CANDIES_MATH:    1. การคูณเลข (Multiplication): a × b = c
I (18439) CANDIES_MATH:    2. การใช้ for loop สำหรับการทำซ้ำ
I (18449) CANDIES_MATH:    3. ความสัมพันธ์ระหว่างการคูณและการบวกซ้ำๆ
I (18449) CANDIES_MATH:    4. คุณสมบัติพิเศษของการคูณ
I (18449) CANDIES_MATH:    5. การแสดงผลแบบตาราง
I (18449) CANDIES_MATH: 
I (18449) CANDIES_MATH: 🎉 จบโปรแกรมนับลูกอมในถุง!
I (18449) CANDIES_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 04_division_cookies
I (20449) main_task: Returned from app_main()

```
<img width="1183" height="946" alt="image" src="https://github.com/user-attachments/assets/51257cc0-5018-4af1-9580-288349646230" />

### 📝 แบบฝึกหัดที่ 4: แจกลูกอมให้เพื่อน
คำนวณการแจกลูกอม:
```c
int friends = 12;           // จำนวนเพื่อน
int candies_per_friend = total_candies / friends;  // ลูกอมต่อคน
int remaining_candies = total_candies % friends;   // ลูกอมที่เหลือ

ESP_LOGI(TAG, "👥 แจกให้เพื่อน %d คน:", friends);
ESP_LOGI(TAG, "   คนละ %d เม็ด", candies_per_friend);
ESP_LOGI(TAG, "   เหลือ %d เม็ด", remaining_candies);
```
