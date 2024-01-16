#include <iostream>
#include <graphics.h>
#include <math.h>
#include <windows.h>
#include <MMsystem.h>
#include <stdlib.h>
#include <cstdio>
#include <dos.h>

using namespace std;

struct Circle {
    int x;
    int y;
    int value;
    struct Circle* next;
};
Circle* tail = nullptr;

void Nhap(int &m, int &n){

	settextstyle( DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(10, 10, "Nhap so m binh si (1<m<90):");
    while (1) {
       if (kbhit()) {
        char ch = getch();
        if (ch == '\r') { // Khi nhấn Enter
           break;
        } else if (ch >= '0' && ch <= '9') { // Chỉ nhận các ký tự từ '0' đến '9'
           m = m * 10 + (ch - '0');
           cleardevice();
           char mStr[10];
           sprintf(mStr, "%d", m);
           outtextxy(30, 10, mStr);
        }
    }
}
	
	cleardevice();
    while(m<=1 || m>=90)
    {
   	    m=0;
   		outtextxy(10, 10, "So m binh si nhap vao khong nam trong mien gioi han!!!!");
   		outtextxy(20,30, "Moi nhap lai so m binh si (1<m<90): ");
	    while (1) {
	      if (kbhit()) {
	         char ch = getch();
	         if (ch == '\r') { // Khi nhấn Enter
	            break;
	         } else if (ch >= '0' && ch <= '9') { // Chỉ nhận các ký tự từ '0' đến '9'
	            m = m * 10 + (ch - '0');
	            cleardevice();
	            char mStr[10];
				sprintf(mStr, "%d", m);
	            outtextxy(30, 15, mStr);
	         }
	      }
	    }
    }
	
   cleardevice();
   outtextxy(10, 10, "Nhap buoc nhay n (1<n<=m):");
   while (1) {
      if (kbhit()) {
         char ch = getch();
         if (ch == '\r') { // Khi nhấn Enter
            break;
         } else if (ch >= '0' && ch <= '9') { // Chỉ nhận các ký tự từ '0' đến '9'
            n = n * 10 + (ch - '0');
            cleardevice();
            char nStr[10];
			sprintf(nStr, "%d", n);
            outtextxy(30, 15, nStr);
         }
      }
   }
   
   cleardevice();
   while(n<=1 || n>m)
   {
   	    n=0;
   		outtextxy(10, 10, "Buoc nhay n nhap vao khong nam trong mien gioi han!!!!");
   		outtextxy(20,30, "Moi nhap lai buoc nhay n: ");
	    while (1) {
	      if (kbhit()) {
	         char ch = getch();
	         if (ch == '\r') { // Khi nhấn Enter
	            break;
	         } else if (ch >= '0' && ch <= '9') { // Chỉ nhận các ký tự từ '0' đến '9'
	            n = n * 10 + (ch - '0');
	            cleardevice();
	            char nStr[10];
				sprintf(nStr, "%d", n);
	            outtextxy(30, 15, nStr);
	         }
	      }
	    }
   }

   cleardevice();
   char resultStr[50];
   sprintf(resultStr, "Binh si: %d", m);
   outtextxy(10, 10, resultStr);
   sprintf(resultStr, "Buoc nhay: %d", n);
   outtextxy(10, 30, resultStr);
}
//Hàm đổi màu
void changeCircleColor(Circle* circle, int newColor)
{	
    // Thay đổi màu
    setfillstyle(SOLID_FILL, newColor);
    
    // Tô màu cho khung hình tròn
    floodfill(circle->x, circle->y, BLACK);
}

// Kiểm tra xem phím "C" đã được nhấn hay chưa
void stop()
{
	setbkcolor(WHITE);
	settextstyle( DEFAULT_FONT, HORIZ_DIR, 2);
    if (kbhit()) {
        char ch = getch();
        if (ch == 'C' || ch == 'c') 
		{
			setcolor(BLUE);
			outtextxy(600,10,"CHUONG TRINH DANG DUNG!!!");
			setcolor(BLACK);
            while (1) 
			{
                // Kiểm tra xem phím "V" đã được nhấn hay chưa
                if (kbhit()) 
				{
                    char ch2 = getch();
                    if (ch2 == 'V' || ch2 == 'v') 
					{
						outtextxy(600,10,"CHUONG TRINH DANG CHAY!!!");
                        break; // Thoát khỏi vòng lặp và tiếp tục chương trình
                    }
                }
            }
       }
    }  
}

// Hàm thêm một hình tròn mới vào danh sách
void Play(int m, int n, int radius, float *r)
{
    
    
    // Đặt kích thước màn hình
    int width = getmaxx();
    int height = getmaxy();
    
    
    // Đặt tâm của hình tròn
    int center_x = 800 ;
    int center_y = 430 ;

    // Tính góc giữa các điểm
    double angle = 2 * M_PI / m;
    
    
    // Khởi tạo danh sách liên kết đơn và thêm hình tròn vào danh sách
    Circle* head = nullptr;
    //Circle* tail = nullptr;
    for (int i = 0; i < m; i++) {
        // Tính tọa độ của điểm
        int x = center_x + radius * cos(i * angle);
        int y = center_y + radius * sin(i * angle);

        // Tạo nút mới cho hình tròn
        Circle* newCircle = new Circle;
        newCircle->x = x;
        newCircle->y = y;
        newCircle->value = i + 1;
        newCircle->next = nullptr;

        // Thêm nút mới vào danh sách
        // Nếu danh sách chưa có phần tử nào
        if (head == nullptr) {
            head = newCircle;
            tail = newCircle;
            tail->next = head; // Tạo vòng liên kết
        }
        // Nếu danh sách đã có phần tử, thêm nút mới vào cuối danh sách
        else {
            tail->next = newCircle;
            tail = newCircle;
            tail->next = head; // Tạo vòng liên kết
        }
    } 
	
	stop(); 
    
    settextstyle( DEFAULT_FONT, HORIZ_DIR, 1);
    // Lặp lại từng phần tử và vẽ chúng trên hình tròn
    for (int i = 0; i < m; i++) {
        // Tính tọa độ của điểm
        int x = center_x + radius * cos(i * angle);
        int y = center_y + radius * sin(i * angle); 
        // Vẽ hình tròn ở tọa độ (x, y)
        circle(x, y, *r);
        // Tô màu cho hình tròn
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(x, y, BLACK);
        // Hiển thị số trên hình tròn
        setbkcolor(YELLOW);
        char str[10];
        sprintf(str, "%d", i + 1);
        outtextxy(x - 7, y - 7, str);
        
    }
    setbkcolor(15);
    
    stop(); 
    // Josephus
    while (m > 1) {
    	settextstyle( DEFAULT_FONT, HORIZ_DIR, 2);
		outtextxy(600,10,"CHUONG TRINH DANG CHAY!!!");
        
    stop();   
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    for (int i = 0; i < n - 1; ++i) {    	
        tail = tail->next;
        changeCircleColor(tail, RED);
        delay(500);
        stop();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); 
        changeCircleColor(tail, YELLOW);
        // Hiển thị lại số trên hình tròn
        setbkcolor(YELLOW);
        char str[10];
        sprintf(str, "%d", tail->value);
        outtextxy(tail->x - 7, tail->y - 7, str);
    }
    setbkcolor(15);
    
    
    stop();
	Circle* pL = tail->next;
    changeCircleColor(pL, RED);
    delay(50);
    stop();
    PlaySound(TEXT("C:\\Users\\ACER\Music\\pbl1-audio.wav"), NULL, SND_SYNC);
    stop();
    for (int j = 0; j < 3; j++) {
    	stop();
        changeCircleColor(pL, YELLOW);
        stop();
        delay(100);
        stop();
        changeCircleColor(pL, WHITE);
        stop();
        delay(100);
        stop();
        changeCircleColor(pL, YELLOW);
        stop();
		delay(100);
        stop();
        changeCircleColor(pL, WHITE);
        stop();
    }  
	setcolor(15); 
    circle(pL->x, pL->y, *r);
    setcolor(0); 
    tail->next = tail->next->next;
    delay(2000);
	m--; 
	stop();    
}

	delay(1000);
	stop();
	char s[100];
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	setcolor(RED);
	outtextxy(600,10,"CHUONG TRINH DA DUNG!!!!!");
	sprintf(s,"=> Binh si duoc chon la binh si so %d", tail->value);
    outtextxy(10, 790, s);  
    setcolor(BLACK);

}



int main(){
	int gd = DETECT, gm;
    initwindow(1920, 1080);
    setbkcolor(15);
    setcolor(0);
    
    char ch;
    do {
      	int m=0;
        int n=0;
        int radius;
        float r;
        cleardevice(); // Xóa nội dung trên màn hình đồ họa

        Nhap(m, n); // Gọi hàm để nhập dữ liệu
        
        if(m<30){
        	r=17;
        	radius=220;
		}else if(m>=30&&m<60){
			r=15;
			radius=300;
		}else if(m>=60&&m<90){
			r=13;
			radius=380;
		}
        
        settextstyle( DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(10, 400, "Bam c de tam dung!");
	    outtextxy(10, 420, "Bam v de tiep tuc!");
	    
        //ve vong trong va thuc hien thuat toan
	    Play(m, n, radius, &r);
			    
	    
        outtextxy(10, 810, "Nhap B de nhap du lieu khac hoac Enter de thoat");
        ch = getch();
    } while (ch == 'B' || ch == 'b');

    closegraph(); // Đóng cửa sổ đồ họa
    return 0;
}