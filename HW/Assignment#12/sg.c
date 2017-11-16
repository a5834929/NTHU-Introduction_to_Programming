#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
/*
  Dev C++: In [Project Options]->[Parameters]->[Linker] add the parameter -lwinmm
  Code::Blocks: In [Settings]->[Compiler and debugger]->[Linker settings] add the parameter -lwinmm
*/

#include "console_draw2.h"
#include "kb_input2.h"

#define WIDTH     17
#define HEIGHT    12
#define MAX_GNUM 7
#define OFFSET_X  3
#define OFFSET_Y  3
void delay(float sec);
void putString(int x, int y, char *p, int fg_color, int bg_color);
void sound(int select);


/* global 陣列    用來記錄地圖的內容 */
char a[HEIGHT][WIDTH]={
'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
'#','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','E','#',
'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'};

int main(void)
{
   FILE *fp;
   int IsEnding = 0;
   char logo[] = "SAMPLE PROGRAM PROVIDED BY I2P11";
   int i, j, vk;
   char icon[] = {'G', ' ', '#', '@'};  /* 顯示的字元 */
   int px = 1, py = 2; /* 用來畫圖的游標的目前座標 */
   int sx = 1, sy = 1; /* 用來記錄移動中的 S 的座標 */
   int status = 0;
   int whole_font = 0;
   char c;


   /* 試著開啟目錄下的 map.txt 檔 */
   fp = fopen("sample.txt", "r");
   /* 假如檔案不存在 就會跳過底下的程式碼  直接用這個程式碼裡宣告的 a[][] 當作預設的地圖陣列
      假如檔案存在 就讀取檔案內容 把陣列的元素依照位置一個一個設定好 */
   if (fp != NULL) {
      /*for (i = 0; i < HEIGHT; i++) {      /* 由於地圖的長寬是固定的  所以就直接用兩個迴圈來讀取 
         for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%c", &a[i][j]);
         }
         fscanf(fp, "%*c");  /* 這一步是為了把每一行結尾的  '\n' 吃掉   "%*c" 的意思是讀取一個字元並且丟掉 
      }*/
      while (fscanf(fp, "(%d,%d): %c%*c", &i, &j, &c) != EOF)
        {
            a[j][i] = c;
        }
      fclose(fp);
   }

   /* 啟動鍵盤控制 */
   initializeKeyInput();


	/* 無窮迴圈  裡面包含了這個程式的主要工作
   而且每次迴圈會不斷把最新的畫面顯示到螢幕上  像是播動畫一樣 每次迴圈更新一次畫面 */
   while (!IsEnding) {

      /* 填上空白 清除整個畫面 */
      for (i = 0; i < 25; i++) {
         for (j = 0; j < 80; j++) {
            putASCII2(j, i, ' ', 0, 0);
         }
      }

      /* 要用半形或全形顯示 */
      if (!whole_font) {
         /* 用 putASCII2() 把地圖畫出來   */
         /* putASCII2() 有十六色而且可以設定背景顏色*/
         for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
               putASCII2(j + OFFSET_X, i + OFFSET_Y, a[i][j] , 13, 0);
            }
         }
         /* current location */
         if (status == 3) {
            putASCII2(sx + OFFSET_X, sy + OFFSET_Y, icon[status], 9, 0);
         } else {
            putASCII2(px + OFFSET_X, py + OFFSET_Y, icon[status], rand()%16, 1);
         }

      } else {

      }



      /*  把 logo 用 putString() 顯示出來
         putString() 是自定的 function    它能在特定位置顯示字串
         這個 function 的程式碼也放在這個檔案裡  在 main() 之後
         程式碼其實很簡短  只是在迴圈裡呼叫 putASCII2() 而已       */
      putString(OFFSET_X, OFFSET_Y-2, logo, 14, 3);
      putString(OFFSET_X, OFFSET_Y+13, "'S': Start to move                                    ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+14, "' ': Place a block                                    ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+15, "'1': Switch to G block                                ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+16, "'2': Switch to empty block for erasing                ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+17, "'3': Switch to # block                                ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+18, "Use Up, Down, Right, Left keys to change position     ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+19, "'W': Save the current map in map.txt                  ", 14, 2);
      putString(OFFSET_X, OFFSET_Y+20, "'Ctrl': Switch to full/half font (not implemented yet)", 14, 2);
      putString(OFFSET_X, OFFSET_Y+21, "'Esc': Quit                                           ", 14, 2);

      /* 為了要讓一連串 putASCII2() 的動作產生效果
         必須要呼叫一次 drawCmdWindow() 把之前畫的全部內容一次顯示到螢幕上 */
      drawCmdWindow();


      /* 鍵盤控制 */
      if(waitForKeyDown(0.1)) {
         vk=getKeyEventVirtual();	/* read a virtual key */

         switch(vk) {
            case VK_ESCAPE:  /* 按下 ESC 鍵 就結束 */
               IsEnding = 1; break;
            case VK_UP:
               py--; break;
            case VK_DOWN:
               py++; break;
            case VK_LEFT:
               px--; break;
            case VK_RIGHT:
               px++; break;
            case VK_SPACE:    /* 按下空白鍵 放置物品 */
               a[py][px] = icon[status];
               if (icon[status]=='G')
                  sound(0);   /* 發出一些聲音   sound() 是自定的 function()  程式碼在下面 */
               break;
            case VK_1:        /* 按下數字鍵 1  把狀態切換成 'G' */
               status = 0;
               break;
            case VK_2:        /* 按下數字鍵 2  把狀態切換成 ' ' */
               status = 1;
               break;
            case VK_3:        /* 按下數字鍵 3  把狀態切換成 '#' */
               status = 2;
               break;
            case VK_W:        /* 按下 W 鍵  把地圖存檔 */
               /* 底下的程式碼是寫檔的標準做法
                  先開啟檔案 檔名是 "map.txt"     格式 "w" 表示 write 也就是要寫檔
                  如果檔案不存在 則會產生一個新檔 如果檔案已經存在 則原本的內容會被蓋掉
                  假如開檔成功 fp 就不會是 NULL (NULL 其實就是 0   表示是空的指標)
                  用 fprintf(fp, "...", ...); 把陣列輸出到檔案裡
                  最後再用 fclose(fp); 把檔案關閉
                  做完之後目錄下應該會多一個 map.txt 檔  用記事本打開來就會看到地圖 */
               fp = fopen("map.txt", "w");
               if (fp != NULL) {
                  for (i = 0; i < HEIGHT; i++) {
                     for (j = 0; j < WIDTH; j++) {
                        fprintf(fp, "%c", a[i][j]);
                     }
                     fprintf(fp, "\n");
                  }
                  fclose(fp);
               }

               sound(1);
               break;

            case VK_S:        /* 按下 S 鍵  地圖中的 S 要開始移動  把 G 吃掉 走到終點 E 就結束 */
               status = 3;
               px = 1;
               py = 1;
               break;
            case VK_CONTROL:  /* 按下 Ctrl 鍵  切換 全形 <-->半形 */
               whole_font = !whole_font;
               break;
         }
      }



      if (status == 3) {
         /*  在這裡加入你寫的程式碼  讓 S 能夠移動   */
         /*  目前的程式碼 只能一路朝著右下角前進    */
         /*  請把它改成可以吃掉所有的 G 然後走到終點 E 結束 */

         if (sx < WIDTH-2)
            sx++;
         else
            sy++;

         if (sx == WIDTH-2 && sy == HEIGHT-2)
            break; /* 結束 跳出無窮迴圈 while */

         delay(0.2);
      }


      /* 邊界的判斷 不能超出地圖範圍之外 */
      if (py < 1) py = 1;
      if (py > HEIGHT-2) py = HEIGHT - 2;
      if (px < 1) px = 1;
      if (px > WIDTH-2) px = WIDTH - 2;

      if (px == 1 && py == 1) { /* 起始位置不能放其他東西 游標移到這裡必須跳過這個位置 */
         px = 2;
         py = 2;
      }
      if (px == WIDTH-2 && py == HEIGHT-2) { /* 終點位置也不能改變 */
         px = WIDTH-3;
         py = HEIGHT-3;
      }



   } /* while (1) */

   sound(2);
   delay(0.5);
   return 0;
}


/***********************
底下是自定的 functions
包含 dalay(), putString(), sound()
***********************/

/* 讓程式暫停 sec 秒 */
void delay(float sec)
{
   clock_t startc;
   startc = clock();
   for ( ; ; ) {
	  if ((float)(clock()-startc)/CLOCKS_PER_SEC > sec) break;
   }
}
/* 在 (x, y) 座標的位置顯示字串 p 的內容  fg_color 是前景的顏色  bg_color 則是背景的顏色 */
void putString(int x, int y, char *p, int fg_color, int bg_color)
{
   int i;
   for(i=0; i<strlen(p); i++) {
      putASCII2(x+i, y, p[i], fg_color, bg_color);
   }
}


void sound(int select)
{

   int i, pitch, duration;


   if (select == 0) {
   /*
      第一種方式 使用 Beep() 發出聲音
      第一個參數指定發音頻率 第二個參數指定時間長短
      Sleep() 則是用來暫停
      時間長度都是以千分之一秒為單位
   */
      duration = 5;
      for (i=0; i<2; i++) {
         for (pitch=200; pitch<400; pitch+=40) {
            Beep(pitch, duration);
         }
         for (pitch=400; pitch>200; pitch-=40) {
            Beep(pitch, duration);
         }
      }
   }
   else if (select == 1) {
   /*
      第二種方法是用 PlaySound() 播放 wav 檔案
      假設 "recycle.wav" 聲音檔和程式碼放在相同目錄
      PlaySound("recycle.wav", NULL, SND_ASYNC|SND_FILENAME);
      會在背景開啟並播放 recycle.wav (播放時 其他鍵盤動作仍可以繼續)

      PlaySound("SystemStart", NULL, SND_ASYNC|SND_ALIAS);
      則是播放已經註冊的系統音效 (直接指名內建的音效名稱)

      要使用 PlaySound() 這個 function
      必須要先到 Project --> Project Options 設定 (在 Dev-C++ 裡面按下  Alt+P)
      選到 Parameters 那一頁  然後在 Linker 裡面加上下面那一行
       -lwinmm

      再 compile 就可以產生執行檔
   */
      PlaySound(TEXT("recycle.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(1000);
   }
   else if (select == 2) {
      PlaySound(TEXT("chimes.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(1000);
   }

}
