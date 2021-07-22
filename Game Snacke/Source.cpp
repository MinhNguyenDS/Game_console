﻿#include <stdio.h>
#include <iostream>
#include "console.h"
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>



# define consoleWidth 117
# define consoleHeight 30 
# define consoleRoad 45 


enum trangthai {UP, DOWN, LEFT, RIGHT};

class ToaDo
{
public:
	
	int x;
	int y;
	// tọa độ hoa quả 2
	int a;
	int b;
	// tọa độ hoa quả 3
	int c;
	int d;

};

class HoaQua:ToaDo
{
public:
	ToaDo td;

};



class Snake:ToaDo
{

public :
	int n = 0;
	ToaDo dot[1000];
	trangthai tt;

};

struct Mot0 {

	char kitu;
	int mau;
};

Mot0 BUFFER[consoleHeight][consoleRoad + 1];

void VeMot0(int dong, int cot, int kitu, int mau)
{
	BUFFER[dong][cot].kitu = kitu;
	BUFFER[dong][cot].mau = mau;

}

void KhoiTao(Snake &snake, HoaQua &hq, int VCx[5][4], int VCy[5][4])
{
	/*snake.n = 1; // con rắn có 'n' đốt
	snake.dot[0].x = 0;
	snake.dot[0].y = 0;*/
	

	for (int i = 0; i < consoleHeight; i++)			// khởi tạo buffer
	{
		for (int j = 0; j <= consoleRoad; j++)
		{
			BUFFER[i][j].kitu = ' '; 
			BUFFER[i][j].mau = 7;
		}
	}



	snake.n = 2; // con rắn có 'n' đốt
	snake.dot[1].x = 1;
	snake.dot[1].y = 1;
	snake.dot[0].x = 2;
	snake.dot[0].y = 1;
	snake.tt = RIGHT;
	/*TextColor(ColorCode_Pink);
	for (int i = 0; i < snake.n; i++)
	{
		gotoXY(snake.dot[i].x, snake.dot[i].y);
		putchar(111);

	}
	gotoXY(snake.dot[0].x, snake.dot[0].y);
	putchar(148);*/



	// hoa quả	
	hq.td.x = 25; 
	hq.td.y = 10;

	hq.td.a = 35;
	hq.td.b = 24;

	hq.td.c = 4;
	hq.td.d = 17;

	
	// Vật cản 

		// toa do x
	for (int i = 0; i <= 3; i++)
	{

		for (int j = 0; j <= 4; j++)
		{
			if (i == 0)
			{
				VCx[j][i] = 14;
			}

			if (i == 1)
			{
				VCx[j][i] = 30;
			}

			if (i == 2)
			{
				VCx[j][i] = 20 + j;
			}

			if (i == 3)
			{
				VCx[j][i] = 20 + j;
			}

		}

	}

		// toa do y
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (i == 0)
			{
				VCy[j][i] = 12+j;
			}

			if (i == 1)
			{
				VCy[j][i] = 12+j;
			}

			if (i == 2)
			{
				VCy[j][i] = 6 ;
			}

			if (i == 3)
			{
				VCy[j][i] = 23;
			}

		}

	}


}

void HienThi(Snake snake, HoaQua &hq, int diem, char key1, int VCx [5][4], int VCy [5][4])
{
	// snake
		//clrscr();
	    //TextColor(ColorCo	de_Pink);
	for (int i = 0; i < snake.n; i++)
	{

		VeMot0(snake.dot[i].y, snake.dot [i].x, 111, 13);

		//gotoXY(snake.dot[i].x, snake.dot[i].y);
		//putchar (111);

	}
	VeMot0(snake.dot[0].y, snake.dot[0].x, 148, 13); // in đầu con rắn vào tờ giấy nháp

	//gotoXY(snake.dot[0].x, snake.dot[0].y);
	//putchar(148);



	// vật cản
			//TextColor(ColorCode_Red);
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 4; j++)
		{

			VeMot0(VCy[j][i], VCx[j][i], 177, 12);
			//gotoXY(VCx[j][i], VCy[j][i]);
			//putchar(177);

		}
	}


	// hoa quả
	VeMot0(hq.td.y, hq.td.x, 149, 14);
	VeMot0(hq.td.b, hq.td.a, 149, 14);
	VeMot0(hq.td.d, hq.td.c, 149, 14);


			// TextColor(ColorCode_Yellow);
			// gotoXY(hq.td.x, hq.td.y);
			// putchar(149);
			// gotoXY(hq.td.a, hq.td.b);
			// putchar(149);
			// gotoXY(hq.td.c, hq.td.d);
			// putchar(149);


	 // tường
	   //TextColor(ColorCode_Red);
	 for (int i = 0; i <= consoleHeight -2 ; i++) //  tường lề phải , trái  
	 {

		 VeMot0(i, consoleRoad,178, 12);
		 VeMot0(i, 0, 178, 12);

		 //gotoXY(consoleRoad , i);
		 //putchar(178);
	 }


	 for (int i = 0; i <= 45 ; i++) // tường lề trên , dưới
	 {

		 VeMot0(0, i , 254, 12);
		 VeMot0(consoleHeight - 2, i, 254, 12);
		

		 //gotoXY(i+1, 0);
		 // putchar(254);
	 }



	 gotoXY(0, 0);
	 // in ra console từ giấy nháp

	 for (int i = 0; i < consoleHeight; i++)
	 {
		 for (int j = 0; j <= consoleRoad ; j++)
		 {
			 TextColor(BUFFER[i][j].mau);
			 putchar(BUFFER[i][j].kitu);

			 BUFFER[i][j].kitu = ' ';
		 }

		 if (i < consoleHeight - 1)
		 {
			 std::cout << std::endl;

		 }
	 }



	// điểm
	 TextColor(ColorCode_Yellow);
	 gotoXY(47,8);
	 std::cout << "--DIEM cua ban la : ";
	 std::cout << diem  ;
	 if (key1 == '2')
	 {
		 std::cout << "/20";
		 gotoXY(57, 10);
	     std::cout << "CO LEN!! CO LEN !! @_@";
	 }
	 if (key1 == '1')
	 {
		 std::cout << "/995";
		 gotoXY(57, 10);
		 std::cout << "CHOI GAME MA` CHOI THUONG` AK !! ^_^";
	 }


	 // hướng dẫn điều khiển
	 {
	 gotoXY(47, 0);
	 std::cout << "--DIEU KHIEN :";
	 gotoXY(64, 3);
	 std::cout << "W";
	 gotoXY(62, 4);
	 std::cout << "A";
	 gotoXY(64, 4);
	 std::cout << "S";
	 gotoXY(66, 4);
	 std::cout << "D";
	 gotoXY(62, 1);
	 std::cout << "Di len";
	 gotoXY(64, 2);
	 std::cout << "^";
	 gotoXY(47, 4);
	 std::cout << "Di sang trai <";
	 gotoXY(68, 4);
	 std::cout << "> Di sang phai";
	 gotoXY(64, 5);
	 std::cout << "v";
	 gotoXY(62, 6);
	 std::cout << "Di xuong";
	 }


	 // dong` luu niem
	 gotoXY(56, 26);
	 std::cout << "CHOI GAME VUI VE? ^_^. !!!! ";
	 gotoXY(46, 27);
	 std::cout << "The game is written By HOANG MINH- k97 - QHQN(Minimax)";
}


void DieuKhien_Dichuyen(Snake &snake)
{
	// cái đuôi luôn theo sau cái đầu 
	for (int i = snake.n - 1; i > 0; i--)
		snake.dot[i] = snake.dot[i - 1];
	// điểu khiển cái đầu
	if (_kbhit())
	{
		char key = _getch();
		if (key == 'a' || key == 'A')
			snake.tt = LEFT;
		else if (key == 'd' || key == 'D')
			snake.tt = RIGHT;
		else if (key == 's' || key == 'S')
			snake.tt = DOWN;
		else if (key == 'w' || key == 'W')
			snake.tt = UP;



	}
	if (snake.tt == LEFT)
		snake.dot[0].x--;
	else if (snake.tt == RIGHT)
		snake.dot[0].x++;
	else if (snake.tt == UP)
		snake.dot[0].y--;
	else if (snake.tt == DOWN)
		snake.dot[0].y++;

}


void XuLy(Snake &snake, HoaQua &hq, int &thoigianSleep, int &diem, char key1)
{
	if (snake.dot[0].x == hq.td.x && snake.dot[0].y == hq.td.y || snake.dot[0].x == hq.td.a && snake.dot[0].y == hq.td.b || snake.dot[0].x == hq.td.c && snake.dot[0].y == hq.td.d) // ăn được hoa quả 
	{ 

		// hoa quả
			//hoa quả 1
		if (snake.dot[0].x == hq.td.x && snake.dot[0].y == hq.td.y)
		{
			hq.td.x = 1 + rand() % 43 ;
			hq.td.y = 1 + rand() % 27;
		}
			//hoa quả 2
		else if (snake.dot[0].x == hq.td.a && snake.dot[0].y == hq.td.b)
		{
			hq.td.a = 1 + rand() % 43;
			hq.td.b = 1 + rand() % 27;
		}
			//hoa quả 3
		else if (snake.dot[0].x == hq.td.c && snake.dot[0].y == hq.td.d)
		{
			hq.td.c = 1 + rand() % 43;
			hq.td.d = 1 + rand() % 27;
		}



		// rắn ăn được hoa quả 
		for (int i = snake.n; i > 0; i--)
			snake.dot[i] = snake.dot[i - 1];
		snake.n++;
		if (snake.tt == LEFT)
			snake.dot[0].x--;
		else if (snake.tt == RIGHT)
			snake.dot[0].x++;
		else if (snake.tt == UP)
			snake.dot[0].y--;
		else if (snake.tt == DOWN)
			snake.dot[0].y++;


		// Chế độ chơi 
		if (key1 == '2') {
			thoigianSleep -= 8;
		}


		// điểm 
		
		diem++;
	}


}



int	ThangGame_ThuaGame(Snake snake, char key1, int VCx[5][4], int VCy[5][4])
{
	// thua game 
	if (snake.dot[0].y == consoleHeight-2|| snake.dot[0].y == 0|| snake.dot[0].x == 0 || snake.dot[0].x == consoleRoad )
	{
		
		return -1;
	}
	for (int i = 1; i <= snake.n; i++)

	{
		if (snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y)
		{
			return -2;
		}

	}
						// rắn đụng vật cản 
		
	for (int i = 0; i < 4 ;  i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (snake.dot[0].x == VCx[j][i] && snake.dot[0].y == VCy[j][i])
			{
				return -2;
			}
		}
	}
	


	// thang game

	if (snake.n == 22 && key1=='2')
	{

		return 1;
	}
	if (snake.n == 997 && key1 == '1')
	{

		return 1;
	}


}



int main()
{
	srand(time(NULL));
	Snake snake;
	HoaQua hq;
	int VCx[5][4];
	int VCy[5][4];


	char a = '1';

	while (a == '1') // xử lý quay lại game
	{
		char key1;
		char Ten[40];
		char Tuoi[3];
		int ChoiLai = 0;
		int diem1;


		//tạo lời thoại lúc kết thúc game (thực hành với sâu kí tự)
		char loithoai1[] = "Dap dau` vo tuong` roi` !! ^^";
		char loithoai2[] = "Choi do? qua, can duoi roi` !! ^^";
		char DanhGia[50];
		// giao diện
		{

			TextColor(ColorCode_Pink);
			std::cout << "***********yyyyyyyyyyyyyyyyyyyyooooooyooyyyyooyyooooooyyooyyyooyyooooooyyyyyyyyyyyyyyyy***********" << std::endl;
			std::cout << "*        yyyyyyyyyyyyyyyyyyys:://////s-:ooys-:yo:////-os:-syo:/yo://///syyyyyyyyyyyyyyyyy        *" << std::endl;
			std::cout << "*      yyyyyyyyyyyyyyyyyyyyys-:yyyyyys--/-oy-:s:-syyy:-s:-so-/yy::syyyyyyyyyyyyyyyyyyyyyyyy      *" << std::endl;
			std::cout << "*    yyyyyyyyyyyyyyyyyyyyyyys-:ooooyys-:s/-o-:s:-oooo:-s:-o-/yyy::ooooyyyyyyyyyyyyyyyyyyyyyyyy   *" << std::endl;
			std::cout << "*  yyyyyyyyyyyyyyyyyyyyyyyyyyso////:/s-:ys//-:s:-////--s:-/-oyyy:-////yyyyyyyyyyyyyyyyyyyyyyyyy  *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys-:s-:yyyy-:s:-syyy:-s:-s/-oyy::syyyyyyyyyyyyyyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys-:s-:yyyy-:s:-syyy:-s:-s/-oyy::syyyyyyyyyyyyyyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyys:----:syyyys/////+sss/+yyyy/+y//syyy//s//yyy//yy//////yyyyyyyyyyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyy+::oyyyyyyyyyyyyyyyyyyyysysyyyyyyyysysyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyysyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysyyyyyyyysyyyyyyyyyyyyyyyyyyyyyy/:////:oyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysyyyyyysysysyyyysysysyyyyyyyyysooooooosyy/:/++/:/oooooooooooo *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysyyyyyyyyyysyyyysssyys-:/-/:-oyy:-oyy/-/::/-/:-/::/- *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysysysyyyysysy+-::.:::sys-:oys:-oyy:-+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+:+ys/:+//+:+sy+::os+::sys::syy::oyy:-+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo+oyy++++++:/yy+:/yyo::sys:/sys::oyy/:+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo+oyy++++++:/yy+:/yyo::sys:/sys::oyy/:+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysysyyyyy+.:ss+.:yyo::sys::sys:-oyy:-+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+-::-:-:yyo::sys-:oys:-oyy:-+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyssssssssyyo::/:/::syy::oyy:-oyyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "* yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooo++++sys::/++/:+yyyyyyyyyyyyyyyyy *" << std::endl;
			std::cout << "*  yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys::/://:oyyyyyyyyyyyyyyyy  *" << std::endl;
			std::cout << "*   yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy   *" << std::endl;
			std::cout << "*     yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy      *" << std::endl;
			std::cout << "*      yyyyyyyyyyyyyyyyyyyyyyyyyyyyyo+oo+oo+syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy       *" << std::endl;
			std::cout << "*        yyyyyyyyyyyyyyyyyyyyyyyyyyyy//y//s+syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy          *" << std::endl;
			std::cout << "**************************************************************************************************" << std::endl;
			std::cout << "                                              The game is written By HOANG MINH-k97-QHQN (Minimax)" << std::endl;




			gotoXY(14, 14);
			TextColor(ColorCode_Red);
			std::cout << "***GAME SNAKE***2017";
			gotoXY(9, 18);
			TextColor(ColorCode_Green);
			std::cout << "I.Nhan 1 de bat dau` game (Binh Thuong)";
			gotoXY(9, 19);
			TextColor(ColorCode_Green);
			std::cout << "II.Nhan 2 de bat dau` game (Thu Thach)";
			gotoXY(9, 20);
			TextColor(ColorCode_Green);
			std::cout << "III.Nhan 3 de thoat ";
			while (1)
			{
				if (_kbhit())
				{
					key1 = _getch();

					if (key1 == '1')
					{
						break;
					}
					else if (key1 == '2')
					{
						clrscr();
						TextColor(ColorCode_Red);
						gotoXY(0, 13);
						std::cout << "**************************************************************************************************";
						gotoXY(0, 14);
						std::cout << "*                                                                                                *";
						gotoXY(0, 15);
						std::cout << "*                                                                                                *";
						gotoXY(0, 16);
						std::cout << "*                                                                                                *";
						gotoXY(0, 17);
						std::cout << "*                                                                                                *";
						gotoXY(0, 18);
						std::cout << "**************************************************************************************************";
						gotoXY(15, 15);
						std::cout << "LUU Y : Con ran se nhanh dan` khi moi lan` ban an hoa qua!!";
						std::cout << " NHAN Enter !!!";
						while (_getch() != 13);
						break;
					}
					else if (key1 == '3')
					{
						ChoiLai = 1;
						a = '2';
						break;

					}
				}
			}
			clrscr();
		}



		// main game
		while (ChoiLai == 0) //  xử lý khi chơi lại game ; 
		{
			
			KhoiTao(snake, hq, VCx, VCy);
			int ma;
			int thoigianSleep = 150;
			int diem = 0;



			while (key1 == '1' || key1 == '2')
			{


				// hiển thị 
				HienThi(snake, hq, diem, key1, VCx, VCy);

				// điều khiển 
				DieuKhien_Dichuyen(snake);


				// xử lý 
				XuLy(snake, hq, thoigianSleep, diem, key1);


				// thua game , thắng game 

				ma = ThangGame_ThuaGame(snake, key1, VCx, VCy);
				diem1= diem;
				if (ma == -1 || ma == -2)
				{
					int a = 0;
					gotoXY(55, 14);
					if (ma == -1)
					{
						std::cout << loithoai1;
					}
					if (ma == -2)
					{
						std::cout << loithoai2;
					}
					gotoXY(55, 15);
					std::cout << "*****THUA GAME ROI ,HI HI ^^ *****";
					gotoXY(60, 16);
					std::cout << "--NHAN 'z' DE CHOI LAI. ";
					gotoXY(60, 17);
					std::cout << "--NHAN 'x' DE THOAT !!";


					char key2;						// lấy mã
					for (int i = 0; i == a; i++)
					{
						key2 = _getch();
						if (key2 == 'z'|| key2 == 'Z')
						{
							a++;
						}	
						else if (key2 == 'x' || key2 == 'X')
						{
							a++;
						}
						a++;
					}
					if (key2 == 'z' || key2 == 'Z')
					{
						// chơi lại game
						ChoiLai = 0;
						break;

					}
					if (key2 == 'x' || key2 == 'X')
					{
						// thoát game
						ChoiLai = 1;
						break;
					}


				}

				if (ma == 1)
				{
					gotoXY(55, 15);
					std::cout << "*****HEHEHE THANG ROI ,HI HI ^^ *****";
					gotoXY(60, 16);
					std::cout << "NHAN Enter DE THOAT !!";
					while (_getch() != 13);
					ChoiLai = 1;
					break;
				}

				Sleep(thoigianSleep); // là 1 nhịp game
			}

		}

		clrscr();

		// giao diện kết thúc game
		while (key1 == '1' || key1 == '2')
		{
			TextColor(ColorCode_Green);
			gotoXY(40, 2);
			std::cout << "*__SNAKE_2017__*";
			// in con rắn có độ dài n 
			gotoXY(35, 4);
			putchar(148);
			for (int i = 1; i < snake.n; i++)
			{
				gotoXY(35 + i, 4);
				std::cout << "o";
			}
			gotoXY(30, 8);
			std::cout << "%_________HET GAME ROI` ~.~ !!! ^^_________%";

			gotoXY(4, 11);
			std::cout << "--NHAP TEN (lam cho hoan` thien game 1 chut ^^) : ";
			fflush(stdin);
			std::cin.getline(Ten, 40);
			gotoXY(4, 12);
			std::cout << "--NHAP TUOI (ghi bang so ) : ";
			fflush(stdin);
			std::cin.getline(Tuoi, 3);
			gotoXY(4, 13);
			std::cout << "note : game hoi cui`, thay vui thi` cmt cho tui co dong luc ^^";
			gotoXY(22, 16);
			std::cout << "***************************************************";
			gotoXY(22, 17);
			std::cout << "*                                                 *";
			gotoXY(22, 18);
			std::cout << "*                                                 *";
			gotoXY(22, 19);
			std::cout << "*                                                 *";
			gotoXY(22, 20);
			std::cout << "*                                                 *";
			gotoXY(22, 21);
			std::cout << "***************************************************";


			if (snake.n <= 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 && key1 == '1') strcpy_s(DanhGia, "GA` VAI~~~ !! nghi? game di !! ^^ ");
			else if (snake.n == 20, 21, 222, 23, 24, 25, 26, 27, 28, 29 && key1 == '1') strcpy_s(DanhGia, "RANH~ DAY !! ^^ ");
			else if (snake.n >= 30 && key1 == '1') strcpy_s(DanhGia, "DU THOI` GIAN VAY ^^ !!");

			if (key1 == '2' && snake.n <= 7) strcpy_s(DanhGia, "GA` lam !!! ^^");
			else if (snake.n == 12, 13, 14, 15, 16 && key1 == '2') strcpy_s(DanhGia, "Chua gi ma thua roi` ak ^^ ");
			else if (snake.n == 17, 18, 19, 20, 21 && key1 == '2') strcpy_s(DanhGia, "Nhanh chua ^^!! ");
			else if (snake.n == 22 && key1 == '2') strcpy_s(DanhGia, "DUOC DAY !!!");





			gotoXY(24, 17);
			std::cout << "TEN CUA BAN LA :            " << Ten;
			gotoXY(24, 18);
			std::cout << "TUOI CUA BAN   :                            " << Tuoi;
			gotoXY(24, 19);
			std::cout << "DIEM           :                            " << diem1;
			gotoXY(24, 20);
			std::cout << "NHAN XET : " << DanhGia;


			gotoXY(10, 24);
			std::cout << "Ban co muon quay lai menu chinh khong ??";
			gotoXY(10, 25);
			std::cout << "--1. Co ";
			gotoXY(10, 26);
			std::cout << "--2. Khong va thoat ";
			gotoXY(10, 27);
			std::cout << "( Nhan phim so '1' '2' de chon )";
			while (true) {
			char key = _getch();
			if (key == '1') { a = '1'; break; }
			if (key == '2') { a = '2'; break; }


		}
			if (a == '1')
			{
				gotoXY(45, 25);
				std::cout << "Nhan enter !!";
			}
			if (a == '2')
			{
				gotoXY(45, 26);
				std::cout << "Nhan enter !!";
			}
			while (_getch() != 13);
			clrscr();
			break;
		}
	}


	return 0;
}


