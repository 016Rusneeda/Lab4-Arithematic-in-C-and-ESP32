#!/bin/bash

# สคริปท์สำหรับรันโปรเจคทั้งหมดตามลำดับ

echo "🚀 เริ่มต้นการเรียนรู้ Lab4 ทีละโปรเจค"
echo "========================================"

# ตรวจสอบว่าอยู่ในไดเรกทอรีที่ถูกต้อง
if [ ! -d "projects" ]; then
    echo "❌ ไม่พบโฟลเดอร์ projects"
    echo "กรุณารันจากไดเรกทอรีหลักของ Lab4"
    exit 1
fi

# รายการโปรเจค
projects=(
    "01_addition_eggs"
    "02_subtraction_toys" 
    "03_multiplication_candies"
    "04_division_cookies"
)

# ฟังก์ชันรันโปรเจค
run_project() {
    local project_name=$1
    local project_path="projects/$project_name"
    
    echo ""
    echo "📁 โปรเจค: $project_name"
    echo "========================"
    
    if [ ! -d "$project_path" ]; then
        echo "❌ ไม่พบโฟลเดอร์ $project_path"
        return 1
    fi
    
    # เข้าไปในโฟลเดอร์โปรเจค
    cd "$project_path"
    
    echo "🔨 กำลัง build โปรเจค..."
    if docker exec esp32-lab4 bash -c "cd /project/$project_path && . \$IDF_PATH/export.sh && idf.py build" > /dev/null 2>&1; then
        echo "✅ Build สำเร็จ"
        echo "🚀 กำลังรันโปรเจค..."
        echo "📝 กด Ctrl+] เพื่อหยุดและไปโปรเจคถัดไป"
        echo ""
        
        # รันโปรเจค
        docker exec -it esp32-lab4 bash -c "cd /project/$project_path && . \$IDF_PATH/export.sh && idf.py qemu monitor"
        
    else
        echo "❌ Build ไม่สำเร็จ"
        echo "กรุณาตรวจสอบโค้ดในโปรเจค $project_name"
    fi
    
    # กลับไปไดเรกทอรีหลัก
    cd - > /dev/null
    
    echo ""
    echo "⏸️  หยุดชั่วคราว 3 วินาที..."
    sleep 3
}

# แสดงเมนู
show_menu() {
    echo ""
    echo "📋 เลือกโหมดการเรียนรู้:"
    echo "1. รันทุกโปรเจคตามลำดับ (แนะนำ)"
    echo "2. เลือกโปรเจคที่ต้องการ"
    echo "3. แสดงรายการโปรเจค"
    echo "4. ออกจากโปรแกรม"
    echo ""
    read -p "เลือก (1-4): " choice
}

# แสดงรายการโปรเจค
show_project_list() {
    echo ""
    echo "📋 รายการโปรเจครทั้งหมด:"
    echo "========================"
    for i in "${!projects[@]}"; do
        local num=$((i + 1))
        local project=${projects[$i]}
        echo "$num. $project"
        
        # อ่านชื่อโปรเจคจาก README
        local readme_path="projects/$project/README.md"
        if [ -f "$readme_path" ]; then
            local title=$(head -1 "$readme_path" | sed 's/^# //')
            echo "   $title"
        fi
        echo ""
    done
}

# เลือกโปรเจคเฉพาะ
select_project() {
    show_project_list
    echo "0. กลับไปเมนูหลัก"
    echo ""
    read -p "เลือกโปรเจค (0-${#projects[@]}): " project_choice
    
    if [ "$project_choice" = "0" ]; then
        return
    elif [ "$project_choice" -ge 1 ] && [ "$project_choice" -le "${#projects[@]}" ]; then
        local selected_project=${projects[$((project_choice - 1))]}
        run_project "$selected_project"
    else
        echo "❌ ตัวเลือกไม่ถูกต้อง"
    fi
}

# ตรวจสอบ Docker
check_docker() {
    if ! docker ps | grep -q esp32-lab4; then
        echo "⚠️  ไม่พบ Container esp32-lab4 กำลังทำงาน"
        echo "🔧 กำลังเริ่ม Container..."
        docker-compose up -d
        sleep 5
        
        if ! docker ps | grep -q esp32-lab4; then
            echo "❌ ไม่สามารถเริ่ม Container ได้"
            echo "กรุณาตรวจสอบ Docker และ docker-compose.yml"
            exit 1
        fi
    fi
    echo "✅ Container esp32-lab4 พร้อมใช้งาน"
}

# เริ่มต้นโปรแกรม
main() {
    # ตรวจสอบ Docker
    check_docker
    
    while true; do
        show_menu
        
        case $choice in
            1)
                echo ""
                echo "🎓 เริ่มเรียนรู้ทุกโปรเจคตามลำดับ"
                echo "=================================="
                for project in "${projects[@]}"; do
                    run_project "$project"
                done
                echo ""
                echo "🎉 เรียนจบทุกโปรเจคแล้ว!"
                echo "ยินดีด้วย! คุณได้เรียนรู้การคำนวณพื้นฐานทั้งหมดแล้ว"
                break
                ;;
            2)
                select_project
                ;;
            3)
                show_project_list
                read -p "กด Enter เพื่อกลับไปเมนู..." 
                ;;
            4)
                echo "👋 ขอบคุณที่ใช้งาน Lab4!"
                break
                ;;
            *)
                echo "❌ ตัวเลือกไม่ถูกต้อง กรุณาเลือก 1-4"
                ;;
        esac
    done
}

# เรียกใช้ฟังก์ชันหลัก
main
