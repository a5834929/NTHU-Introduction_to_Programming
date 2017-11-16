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


/* global �}�C    �ΨӰO���a�Ϫ����e */
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
   char icon[] = {'G', ' ', '#', '@'};  /* ��ܪ��r�� */
   int px = 1, py = 2; /* �Ψӵe�Ϫ���Ъ��ثe�y�� */
   int sx = 1, sy = 1; /* �ΨӰO�����ʤ��� S ���y�� */
   int status = 0;
   int whole_font = 0;
   char c;


   /* �յ۶}�ҥؿ��U�� map.txt �� */
   fp = fopen("sample.txt", "r");
   /* ���p�ɮפ��s�b �N�|���L���U���{���X  �����γo�ӵ{���X�̫ŧi�� a[][] ��@�w�]���a�ϰ}�C
      ���p�ɮצs�b �NŪ���ɮפ��e ��}�C�������̷Ӧ�m�@�Ӥ@�ӳ]�w�n */
   if (fp != NULL) {
      /*for (i = 0; i < HEIGHT; i++) {      /* �ѩ�a�Ϫ����e�O�T�w��  �ҥH�N�����Ψ�Ӱj���Ū�� 
         for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%c", &a[i][j]);
         }
         fscanf(fp, "%*c");  /* �o�@�B�O���F��C�@�浲����  '\n' �Y��   "%*c" ���N��OŪ���@�Ӧr���åB�ᱼ 
      }*/
      while (fscanf(fp, "(%d,%d): %c%*c", &i, &j, &c) != EOF)
        {
            a[j][i] = c;
        }
      fclose(fp);
   }

   /* �Ұ���L���� */
   initializeKeyInput();


	/* �L�a�j��  �̭��]�t�F�o�ӵ{�����D�n�u�@
   �ӥB�C���j��|���_��̷s���e����ܨ�ù��W  ���O���ʵe�@�� �C���j���s�@���e�� */
   while (!IsEnding) {

      /* ��W�ť� �M����ӵe�� */
      for (i = 0; i < 25; i++) {
         for (j = 0; j < 80; j++) {
            putASCII2(j, i, ' ', 0, 0);
         }
      }

      /* �n�Υb�ΩΥ������ */
      if (!whole_font) {
         /* �� putASCII2() ��a�ϵe�X��   */
         /* putASCII2() ���Q����ӥB�i�H�]�w�I���C��*/
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



      /*  �� logo �� putString() ��ܥX��
         putString() �O�۩w�� function    ����b�S�w��m��ܦr��
         �o�� function ���{���X�]��b�o���ɮ׸�  �b main() ����
         �{���X����²�u  �u�O�b�j��̩I�s putASCII2() �Ӥw       */
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

      /* ���F�n���@�s�� putASCII2() ���ʧ@���ͮĪG
         �����n�I�s�@�� drawCmdWindow() �⤧�e�e���������e�@����ܨ�ù��W */
      drawCmdWindow();


      /* ��L���� */
      if(waitForKeyDown(0.1)) {
         vk=getKeyEventVirtual();	/* read a virtual key */

         switch(vk) {
            case VK_ESCAPE:  /* ���U ESC �� �N���� */
               IsEnding = 1; break;
            case VK_UP:
               py--; break;
            case VK_DOWN:
               py++; break;
            case VK_LEFT:
               px--; break;
            case VK_RIGHT:
               px++; break;
            case VK_SPACE:    /* ���U�ť��� ��m���~ */
               a[py][px] = icon[status];
               if (icon[status]=='G')
                  sound(0);   /* �o�X�@���n��   sound() �O�۩w�� function()  �{���X�b�U�� */
               break;
            case VK_1:        /* ���U�Ʀr�� 1  �⪬�A������ 'G' */
               status = 0;
               break;
            case VK_2:        /* ���U�Ʀr�� 2  �⪬�A������ ' ' */
               status = 1;
               break;
            case VK_3:        /* ���U�Ʀr�� 3  �⪬�A������ '#' */
               status = 2;
               break;
            case VK_W:        /* ���U W ��  ��a�Ϧs�� */
               /* ���U���{���X�O�g�ɪ��зǰ��k
                  ���}���ɮ� �ɦW�O "map.txt"     �榡 "w" ��� write �]�N�O�n�g��
                  �p�G�ɮפ��s�b �h�|���ͤ@�ӷs�� �p�G�ɮפw�g�s�b �h�쥻�����e�|�Q�\��
                  ���p�}�ɦ��\ fp �N���|�O NULL (NULL ���N�O 0   ��ܬO�Ū�����)
                  �� fprintf(fp, "...", ...); ��}�C��X���ɮ׸�
                  �̫�A�� fclose(fp); ���ɮ�����
                  ��������ؿ��U���ӷ|�h�@�� map.txt ��  �ΰO�ƥ����}�ӴN�|�ݨ�a�� */
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

            case VK_S:        /* ���U S ��  �a�Ϥ��� S �n�}�l����  �� G �Y�� ������I E �N���� */
               status = 3;
               px = 1;
               py = 1;
               break;
            case VK_CONTROL:  /* ���U Ctrl ��  ���� ���� <-->�b�� */
               whole_font = !whole_font;
               break;
         }
      }



      if (status == 3) {
         /*  �b�o�̥[�J�A�g���{���X  �� S �������   */
         /*  �ثe���{���X �u��@���µۥk�U���e�i    */
         /*  �Ч⥦�令�i�H�Y���Ҧ��� G �M�ᨫ����I E ���� */

         if (sx < WIDTH-2)
            sx++;
         else
            sy++;

         if (sx == WIDTH-2 && sy == HEIGHT-2)
            break; /* ���� ���X�L�a�j�� while */

         delay(0.2);
      }


      /* ��ɪ��P�_ ����W�X�a�Ͻd�򤧥~ */
      if (py < 1) py = 1;
      if (py > HEIGHT-2) py = HEIGHT - 2;
      if (px < 1) px = 1;
      if (px > WIDTH-2) px = WIDTH - 2;

      if (px == 1 && py == 1) { /* �_�l��m������L�F�� ��в���o�̥������L�o�Ӧ�m */
         px = 2;
         py = 2;
      }
      if (px == WIDTH-2 && py == HEIGHT-2) { /* ���I��m�]������� */
         px = WIDTH-3;
         py = HEIGHT-3;
      }



   } /* while (1) */

   sound(2);
   delay(0.5);
   return 0;
}


/***********************
���U�O�۩w�� functions
�]�t dalay(), putString(), sound()
***********************/

/* ���{���Ȱ� sec �� */
void delay(float sec)
{
   clock_t startc;
   startc = clock();
   for ( ; ; ) {
	  if ((float)(clock()-startc)/CLOCKS_PER_SEC > sec) break;
   }
}
/* �b (x, y) �y�Ъ���m��ܦr�� p �����e  fg_color �O�e�����C��  bg_color �h�O�I�����C�� */
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
      �Ĥ@�ؤ覡 �ϥ� Beep() �o�X�n��
      �Ĥ@�ӰѼƫ��w�o���W�v �ĤG�ӰѼƫ��w�ɶ����u
      Sleep() �h�O�ΨӼȰ�
      �ɶ����׳��O�H�d�����@�����
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
      �ĤG�ؤ�k�O�� PlaySound() ���� wav �ɮ�
      ���] "recycle.wav" �n���ɩM�{���X��b�ۦP�ؿ�
      PlaySound("recycle.wav", NULL, SND_ASYNC|SND_FILENAME);
      �|�b�I���}�Ҩü��� recycle.wav (����� ��L��L�ʧ@���i�H�~��)

      PlaySound("SystemStart", NULL, SND_ASYNC|SND_ALIAS);
      �h�O����w�g���U���t�έ��� (�������W���ت����ĦW��)

      �n�ϥ� PlaySound() �o�� function
      �����n���� Project --> Project Options �]�w (�b Dev-C++ �̭����U  Alt+P)
      ��� Parameters ���@��  �M��b Linker �̭��[�W�U�����@��
       -lwinmm

      �A compile �N�i�H���Ͱ�����
   */
      PlaySound(TEXT("recycle.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(1000);
   }
   else if (select == 2) {
      PlaySound(TEXT("chimes.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(1000);
   }

}
