# โปรเจค 1: การบวก - ไข่ไก่ของแม่
 ### 📝 แบบฝึกหัดที่ 1: เปลี่ยนจำนวนไข่
```c
// หาบรรทัดนี้ในโค้ด:
int eggs_already_have = 4;    // ไข่ไก่ที่แม่มีอยู่แล้ว
int eggs_new_today = 2;       // ไข่ไก่ที่ไก่ออกวันนี้

// ลองเปลี่ยนเป็น:
int eggs_already_have = 8;    // เพิ่มเป็น 8 ฟอง
int eggs_new_today = 3;       // เพิ่มเป็น 3 ฟอง
```
   ### ผลลัพธ์ที่ได้
- I (16603) EGGS_MATH: 🧮 ขั้นตอนการคิด:
- I (16603) EGGS_MATH:    ไข่ไก่ที่มีอยู่ + ไข่ไก่ที่ออกใหม่
- I (16603) EGGS_MATH:    = 8 + 3
- I (16603) EGGS_MATH:    = 11 ฟอง
- I (16603) EGGS_MATH:
- I (16603) EGGS_MATH: ✅ คำตอบ:
- I (16603) EGGS_MATH:    วันนี้แม่มีไข่ไก่ทั้งหมด 11 ฟอง
- I (16603) EGGS_MATH: 
- I (16603) EGGS_MATH: 🎨 ภาพประกอบ:
- I (16603) EGGS_MATH:    ไข่เดิม: 🥚🥚🥚🥚 (8 ฟอง)
- I (16603) EGGS_MATH:    ไข่ใหม่: 🥚🥚 (3 ฟอง)
- I (16603) EGGS_MATH:    รวม:    🥚🥚🥚🥚🥚🥚 (11 ฟอง)
- I (16613) EGGS_MATH:
- I (16613) EGGS_MATH: 💡 ตัวอย่างเพิ่มเติม:
- I (16613) EGGS_MATH:    ถ้าแม่มีไข่ 7 ฟอง และไก่ออกไข่ 3 ฟอง
- I (16613) EGGS_MATH:    จะได้ไข่ทั้งหมด 7 + 3 = 10 ฟอง
- I (16613) EGGS_MATH:
- I (16613) EGGS_MATH:    ถ้าแม่มีไข่ 10 ฟอง และไก่ออกไข่ 5 ฟอง
- I (16613) EGGS_MATH:    จะได้ไข่ทั้งหมด 10 + 5 = 15 ฟอง
- I (16613) EGGS_MATH: 
- I (16613) EGGS_MATH: 📚 สิ่งที่เรียนรู้:
- I (16613) EGGS_MATH:    1. การบวกเลข (Addition): a + b = c
- I (16613) EGGS_MATH:    2. การใช้ตัวแปร (Variables) เก็บค่า
- I (16613) EGGS_MATH:    3. การแสดงผลด้วย ESP_LOGI
- I (16623) EGGS_MATH:    4. การแก้โจทย์แบบมีขั้นตอน
- I (16623) EGGS_MATH:
- I (16623) EGGS_MATH: 🎉 จบโปรแกรมนับไข่ไก่ของแม่!
- I (16623) EGGS_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 02_subtraction_toys
- I (18623) main_task: Returned from app_main()

  
  <img width="1598" height="994" alt="image" src="https://github.com/user-attachments/assets/d8298904-e705-4951-abf4-830c08f0aedf" />

  ### 📝 แบบฝึกหัดที่ 2: เพิ่มไข่เป็ด
  เพิ่มโค้ดนี้หลังบรรทัด int total_eggs;:
```c
int duck_eggs = 3;            // ไข่เป็ดที่แม่มี
int total_all_eggs;           // ไข่ทั้งหมด (ไก่ + เป็ด)
```
แล้วเพิ่มการคำนวณหลังบรรทัด total_eggs = eggs_already_have + eggs_new_today;:
```c
total_all_eggs = total_eggs + duck_eggs;

// แสดงผลไข่เป็ด
ESP_LOGI(TAG, "🦆 และแม่มีไข่เป็ด: %d ฟอง", duck_eggs);
ESP_LOGI(TAG, "🥚 ไข่ทั้งหมด (ไก่+เป็ด): %d ฟอง", total_all_eggs);
```
  
  ###ผลลัพธ์ที่ได้
- I (13033) EGGS_MATH: 🦆 และแม่มีไข่เป็ด: 3 ฟอง
- I (13033) EGGS_MATH: 🥚 ไข่ทั้งหมด (ไก่+เป็ด): 14 ฟอง
- I (13033) EGGS_MATH: 🧮 ขั้นตอนการคิด:
- I (13033) EGGS_MATH:    ไข่ไก่ที่มีอยู่ + ไข่ไก่ที่ออกใหม่
- I (13033) EGGS_MATH:    = 8 + 3
- I (13033) EGGS_MATH:    = 11 ฟอง
- I (13033) EGGS_MATH: 
- I (13033) EGGS_MATH: ✅ คำตอบ:
- I (13033) EGGS_MATH:    วันนี้แม่มีไข่ไก่ทั้งหมด 11 ฟอง
- I (13033) EGGS_MATH:
- I (13033) EGGS_MATH: 🎨 ภาพประกอบ:
- I (13033) EGGS_MATH:    ไข่เดิม: 🥚🥚🥚🥚 (8 ฟอง)
- I (13033) EGGS_MATH:    ไข่ใหม่: 🥚🥚 (3 ฟอง)
- I (13033) EGGS_MATH:    รวม:    🥚🥚🥚🥚🥚🥚 (11 ฟอง)
- I (13033) EGGS_MATH: 
- I (13033) EGGS_MATH: 💡 ตัวอย่างเพิ่มเติม:
- I (13033) EGGS_MATH:    ถ้าแม่มีไข่ 7 ฟอง และไก่ออกไข่ 3 ฟอง
- I (13043) EGGS_MATH:    จะได้ไข่ทั้งหมด 7 + 3 = 10 ฟอง
- I (13043) EGGS_MATH: 
- I (13043) EGGS_MATH:    ถ้าแม่มีไข่ 10 ฟอง และไก่ออกไข่ 5 ฟอง
- I (13043) EGGS_MATH:    จะได้ไข่ทั้งหมด 10 + 5 = 15 ฟอง
- I (13043) EGGS_MATH:
- I (13043) EGGS_MATH: 📚 สิ่งที่เรียนรู้:
- I (13043) EGGS_MATH:    1. การบวกเลข (Addition): a + b = c
- I (13043) EGGS_MATH:    2. การใช้ตัวแปร (Variables) เก็บค่า
- I (13043) EGGS_MATH:    3. การแสดงผลด้วย ESP_LOGI
- I (13043) EGGS_MATH:    4. การแก้โจทย์แบบมีขั้นตอน
- I (13053) EGGS_MATH: 
- I (13053) EGGS_MATH: 🎉 จบโปรแกรมนับไข่ไก่ของแม่!
- I (13053) EGGS_MATH: 📖 อ่านต่อในโปรเจคถัดไป: 02_subtraction_toys
- I (15053) main_task: Returned from app_main()


<img width="1378" height="874" alt="image" src="https://github.com/user-attachments/assets/e14229b7-d620-443f-8c28-b291f45ecfe6" />

### 📝 แบบฝึกหัดที่ 3: สร้างโจทย์ของตัวเอง
ลองเปลี่ยนเป็นโจทย์อื่น เช่น:
- 🍎 แอปเปิ้ลในตะกร้า
- 📚 หนังสือบนชั้น  
- 🚗 รถในลานจอด
- 🌟 ดาวในท้องฟ้า

  ###ผลลัพธ์ที่ได้
- I (16257) EGGS_MATH: มีแอปเปิ้ลอยู่แล้ว : 19 ผล
- I (16257) EGGS_MATH: เพิ่มแอปเปิ้ล : 5 ผล
- I (16257) EGGS_MATH: รวมมีแอปเปิ้ลอยู่ในตะกร้าทั้งหมด : 24 ผล
- I (16257) EGGS_MATH: รวมมีแอปเปิ้ลอยู่ในตะกร้าทั้งหมด : 24 ผล
- I (16257) EGGS_MATH: 
- I (16257) EGGS_MATH:
- I (16257) EGGS_MATH: 🧮 ขั้นตอนการคิด:
- I (16257) EGGS_MATH:    แอปเปิ้ลที่มีอยู่ + แอปเปิ้ลที่เพิ่มเข้ามา
- I (16257) EGGS_MATH:    = 19 + 5
- I (16257) EGGS_MATH:    = 24 ผล
- I (16257) EGGS_MATH: 
- I (16257) EGGS_MATH: ✅ คำตอบ:
- I (16257) EGGS_MATH:    รวมมีแอปเปิ้ลอยู่ในตะกร้าทั้งหมด 24 ผล
- I (16257) EGGS_MATH:
- I (16257) EGGS_MATH: 🎨 ภาพประกอบ:
- I (16257) EGGS_MATH:    แอปเปิ้ลเดิม: 🍎 (19 ฟอง)
- I (16257) EGGS_MATH:    แอปเปิ้ลใหม่: 🍎 (5 ฟอง)
- I (16257) EGGS_MATH:    รวม:   🍎 (24 ฟอง)
- I (16257) EGGS_MATH: 
- I (16257) EGGS_MATH: มีหนังสืออยู่ 25 เล่ม
- I (16257) EGGS_MATH: เพิ่มหนังสืออีก 6 เล่ม
- I (16257) EGGS_MATH: มีหนังสือบนชั้นวางทั้งหมด 31 เล่ม
- I (16267) EGGS_MATH:
- I (16267) EGGS_MATH: 
- I (16267) EGGS_MATH: 🧮 ขั้นตอนการคิด:
- I (16267) EGGS_MATH:    หนังสือที่มีอยู่ + หนังสือที่เพิ่มเข้ามา
- I (16267) EGGS_MATH:    = 25 + 6
- I (16267) EGGS_MATH:    = 31 เล่ม
- I (16267) EGGS_MATH: 
- I (16267) EGGS_MATH: ✅ คำตอบ:
- I (16267) EGGS_MATH:    รวมมีหนังสืออยู่บนชั้นวางทั้งหมด 31 เล่ม
- I (16267) EGGS_MATH: 
- I (16267) EGGS_MATH: 🎨 ภาพประกอบ:
- I (16267) EGGS_MATH:    หนังสือเดิม: 📚 (25 เล่ม)
- I (16267) EGGS_MATH:    หนังสือใหม่: 📚 (6 เล่ม)
- I (16267) EGGS_MATH:    รวม:   📚 (31 เล่ม)
- I (16267) EGGS_MATH:
- I (16277) EGGS_MATH: มีรถจอดอยู่ : 30 คัน
- I (16277) EGGS_MATH: มีรถมาจอดเพิ่ม : 8 คัน
- I (16277) EGGS_MATH: มีรถจอดทั้งหมด : 38 คัน
- I (16277) EGGS_MATH: 
- I (16277) EGGS_MATH:
- I (16277) EGGS_MATH: 🧮 ขั้นตอนการคิด:
- I (16277) EGGS_MATH:    รถที่มีอยู่ + รถที่เพิ่มเข้ามา
- I (16277) EGGS_MATH:    = 30 + 8
- I (16277) EGGS_MATH:    = 38 คัน
- I (16277) EGGS_MATH: 
- I (16277) EGGS_MATH: ✅ คำตอบ:
- I (16277) EGGS_MATH:    รวมมีรถที่จอดทั้งหมด 38 คัน
- I (16277) EGGS_MATH:
- I (16277) EGGS_MATH: 🎨 ภาพประกอบ:
- I (16277) EGGS_MATH:    รถเดิม : 🚗 (30 คัน)
- I (16277) EGGS_MATH:    รถใหม่ : 🚗 (8 คัน)
- I (16277) EGGS_MATH:    รวม :   🚗 (38 คัน)
- I (16277) EGGS_MATH: 
- I (16277) EGGS_MATH: มีดาวอยู่บนฟ้า : 50000 ดวง
- I (16277) EGGS_MATH: ดวงดวงเลือนหายไป : 200 ดวง
- I (16277) EGGS_MATH: เหลือดาวบนฟ้าทั้งหมด : 49800 ดาว
- I (16277) EGGS_MATH: 
- I (16277) EGGS_MATH:
- I (16277) EGGS_MATH: 🧮 ขั้นตอนการคิด:
- I (16277) EGGS_MATH:    ดวงดาวที่มีอยู่ + ดวงดาวที่ลบไป
- I (16277) EGGS_MATH:    = 50000 - 200
- I (16277) EGGS_MATH:    = 49800 ดวง
- I (16277) EGGS_MATH: 
- I (16277) EGGS_MATH: ✅ คำตอบ:
- I (16277) EGGS_MATH:    มีดวงดาวทั้งอยู่บนฟ้าทั้งหมด 49800 ดวง
- I (16277) EGGS_MATH: 
- I (16277) EGGS_MATH: 🎨 ภาพประกอบ:
- I (16277) EGGS_MATH:    ดวงดาวเดิม: 🌟 (50000 ดวง)
- I (16277) EGGS_MATH:    ดวงดาวใหม่: 🌟 (200 ดวง)
- I (16277) EGGS_MATH:    รวม:   🌟 (49800 ดวง)
- I (16277) EGGS_MATH:
- I (18277) main_task: Returned from app_main()

  
  <img width="1585" height="936" alt="image" src="https://github.com/user-attachments/assets/8fcad913-ebaa-47b7-800b-02ee455b6544" />



