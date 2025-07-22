# Lab4: Arithmetic Operations in C and ESP32 🧮

## 📖 การเรียนรู้แบบขั้นเป็นตอน

### สำหรับผู้เริ่มต้น:
- 📚 **[BEGINNER_GUIDE.md](BEGINNER_GUIDE.md)** - คู่มือเริ่มต้นภาษา C บนไมโครคอนโทรลเลอร์

### โปรเจคการเรียนรู้:
- � **[projects/](projects/)** - โปรเจคการเรียนรู้ 8 ขั้นตอน (จากง่ายไปยาก)

## 🎯 วัตถุประสงค์ของการทดลอง
1. เรียนรู้การเขียนโปรแกรมภาษา C สำหรับการคำนวณทางคณิตศาสตร์แบบขั้นเป็นตอน
2. ทำความเข้าใจการใช้งาน ESP32 development framework (ESP-IDF) 
3. ฝึกการใช้ Docker สำหรับการพัฒนา embedded systems
4. ทดสอบการทำงานของโปรแกรมบน ESP32 QEMU emulator

## 📈 การเรียนรู้แบบก้าวไปทีละขั้น
แต่ละโปรเจคได้รับการออกแบบให้นักศึกษาสามารถเรียนรู้ได้ทีละขั้นตอน ไม่ต้องรันทุกอย่างพร้อมกัน

## 🛠️ เครื่องมือที่ใช้
- **Docker** - สำหรับสภาพแวดล้อมการพัฒนา
- **ESP-IDF** - Espressif IoT Development Framework
- **ESP32 QEMU** - Emulator สำหรับทดสอบโค้ด
- **Visual Studio Code** - Editor (แนะนำ)

## 📁 โครงสร้างโปรเจค
```
Lab4 Arithematic in C and ESP32/
├── README.md                 # คู่มือหลัก
├── BEGINNER_GUIDE.md        # คู่มือเริ่มต้น
├── docker-compose.yml       # การตั้งค่า Docker
├── .gitignore              # ไฟล์ที่ไม่ต้อง commit
└── projects/               # โปรเจคการเรียนรู้ 8 ขั้นตอน
    ├── 01_addition_eggs/           # ขั้นที่ 1: การบวก
    ├── 02_subtraction_toys/        # ขั้นที่ 2: การลบ
    ├── 03_multiplication_candies/  # ขั้นที่ 3: การคูณ
    ├── 04_division_cookies/        # ขั้นที่ 4: การหาร
    ├── 05_mixed_shopping/          # ขั้นที่ 5: การผสมผสาน
    ├── 06_advanced_math/           # ขั้นที่ 6: คณิตศาสตร์ขั้นสูง
    ├── 07_error_handling/          # ขั้นที่ 7: การจัดการข้อผิดพลาด
    └── 08_final_calculator/        # ขั้นที่ 8: เครื่องคิดเลขครบครัน
```

## 🚀 วิธีการเริ่มต้น

### ขั้นตอนที่ 1: เตรียมความพร้อม
1. **ติดตั้ง Docker**
   ```bash
   docker --version
   ```

2. **Clone Repository (เฉพาะถ้ายังไม่ได้ clone)**
   ```bash
   git clone <repository-url>
   cd "Lab4 Arithematic in C and ESP32"
   ```

3. **สร้าง Docker Container**
   ```bash
   docker-compose up -d
   ```

4. **เข้าสู่ Docker Container**
   ```bash
   docker exec -it esp32-lab4 bash
   ```
   
   **🔍 อธิบายคำสั่ง docker exec:**
   - `docker exec` = รันคำสั่งใน container ที่กำลังทำงานอยู่
   - `-i` = เปิดโหมดรับ input (interactive) - พิมพ์คำสั่งได้
   - `-t` = สร้าง terminal จำลอง (tty) - ใช้งาน shell ได้เหมือนเครื่องจริง
   - `esp32-lab4` = ชื่อ container ที่ต้องการเข้าไป
   - `bash` = คำสั่งที่รันใน container (เปิด shell bash)
   
   *หมายเหตุ: esp32-lab4 คือชื่อ container ที่กำหนดใน docker-compose.yml*



### ขั้นตอนที่ 2: เลือกโปรเจคที่จะเรียน
- เริ่มจาก **โปรเจค 1** (01_addition_eggs) สำหรับผู้เริ่มต้น
- แต่ละโปรเจคมี README.md อธิบายรายละเอียด

### ขั้นตอนที่ 3: รันโปรเจคแต่ละอัน
```bash
# *** ก่อนอื่นต้องเข้าสู่ Docker Container ก่อน ***
docker exec -it esp32-lab4 bash

# *** สำคัญ: Setup ESP-IDF environment (ทุกครั้งที่เข้า container ใหม่) ***
. $IDF_PATH/export.sh

# จากนั้นเข้าสู่โปรเจคที่ต้องการ
cd projects/01_addition_eggs/

# Build โค้ด
idf.py build

# รันบน QEMU และดูผลลัพธ์
idf.py qemu monitor
```

### 🚪 การออกจาก QEMU Monitor
```
กด Ctrl+] เพื่อออกจาก QEMU monitor
```

### 🚪 การออกจาก Docker Container

**วิธีออกจาก Container:**
```bash
exit
```
หรือกด `Ctrl+D` ใน terminal

**เมื่อออกจาก Container แล้ว:**
- จะกลับมาสู่ shell ของเครื่องหลัก (Windows/Mac/Linux) ทันที
- Container ยังคงทำงานอยู่ (ไม่หยุด)
- สามารถเข้าไปใหม่ได้ด้วยคำสั่ง `docker exec -it esp32-lab4 bash`

**หยุด Container (เมื่อเสร็จงาน):**
```bash
docker-compose down
```


## 📚 แนวทางการเรียนรู้

### สำหรับผู้เริ่มต้น:
1. อ่าน [BEGINNER_GUIDE.md](BEGINNER_GUIDE.md) ก่อน
2. เริ่มจากโปรเจค 01 → 02 → 03 → 04
3. ฝึกแก้ไขโค้ดตามที่โจทย์ท้าทาย

### สำหรับผู้ที่มีพื้นฐาน:
1. เริ่มจากโปรเจค 05 → 06 → 07 → 08
2. ศึกษาเทคนิคขั้นสูงในแต่ละโปรเจค
3. ประยุกต์ใช้ในงานจริง

## 🎯 ผลลัพธ์การเรียนรู้

หลังจากทำโปรเจคครบทั้ง 8 ขั้นตอน นักศึกษาจะสามารถ:

### ทักษะการเขียนโปรแกรม:
- ✅ เขียนโปรแกรม C สำหรับ ESP32 ได้
- ✅ ใช้ ESP-IDF framework ได้
- ✅ จัดการข้อผิดพลาดอย่างมืออาชีพ
- ✅ สร้างโปรแกรมที่มีโครงสร้างดี

### ทักษะการคำนวณ:
- ✅ การคำนวณทางคณิตศาสตร์พื้นฐานและขั้นสูง
- ✅ การประยุกต์ใช้ในงานจริง (ระบบ POS, การเงิน)
- ✅ การจัดการข้อมูลแบบ struct
- ✅ การใช้ฟังก์ชันคณิตศาสตร์

### ทักษะการพัฒนา:
- ✅ การใช้ Docker ในการพัฒนา
- ✅ การทดสอบด้วย QEMU
- ✅ การ debug และแก้ไขปัญหา
- ✅ การเขียนโค้ดที่ปลอดภัยและมีประสิทธิภาพ

## 📝 หมายเหตุสำคัญ

### สำหรับผู้สอน:
- แต่ละโปรเจคควรสอนแยกเป็นสัปดาห์
- ให้นักศึกษาลองแก้ไขโค้ดตามโจทย์ท้าทาย
- ตรวจสอบความเข้าใจก่อนไปโปรเจคถัดไป

### สำหรับผู้เรียน:  
- **ไม่ต้องรีบร้อน** - เรียนทีละโปรเจค
- **ลองทำเอง** - อย่าแค่ copy code
- **ถามเมื่อติดขัด** - มีโจทย์ท้าทายสำหรับฝึกฝน
- **สนุกกับการเรียน** - ทุกโปรเจคมีเรื่องราวน่าสนใจ

## 🚨 การแก้ไขปัญหาพื้นฐาน

### Docker ไม่ทำงาน:
```bash
# ตรวจสอบสถานะ Docker
docker ps

# ตรวจสอบว่า container ทำงานอยู่หรือไม่
docker-compose ps

# Restart Docker service
docker-compose down
docker-compose up -d

# เข้าสู่ container
docker exec -it esp32-lab4 bash
```

### ไม่สามารถเข้า Container ได้:
```bash
# ตรวจสอบชื่อ container ที่ถูกต้อง
docker ps

# ลองใช้ container ID แทน (copy จาก docker ps)
docker exec -it <container_id> bash

# หรือเข้าแบบ interactive ผ่าน docker-compose
docker-compose exec esp32-dev bash

# ถ้า container ไม่มี bash ลองใช้ sh
docker exec -it esp32-lab4 sh
```

**💡 เคล็ดลับ:**
- ใช้ `docker ps` เพื่อดูชื่อ container ที่ถูกต้อง
- บาง container อาจชื่อ `esp32-dev` แทน `esp32-lab4`
- ถ้าไม่มี bash ให้ลองใช้ `sh` แทน

### Build ไม่สำเร็จ:
```bash
# ถ้าพบ "idf.py: command not found"
. $IDF_PATH/export.sh

# ลบ build cache
rm -rf build/
idf.py clean
idf.py build
```

### คำสั่ง idf.py ไม่รู้จัก:
```bash
# Setup ESP-IDF environment (ต้องทำทุกครั้งที่เข้า container ใหม่)
. $IDF_PATH/export.sh

# หรือ
source $IDF_PATH/export.sh

# ตรวจสอบว่า setup สำเร็จ
idf.py --version
```

### QEMU ไม่รัน:
```bash
# ตรวจสอบว่า build สำเร็จแล้ว
idf.py build
# แล้วค่อยรัน qemu
idf.py qemu monitor
```

---

## 🎉 ขอให้สนุกกับการเรียนรู้!

เริ่มต้นจากโปรเจคแรก: **[01_addition_eggs](projects/01_addition_eggs/README.md)**
