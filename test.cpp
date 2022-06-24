#include"Do_Hoa.h"
#include"Xu_Li_Trong.h"
#include<vector>;
// ma tran may tinh
int tinh_toan_lan = 0;
float kq_cu;
int mx_dang_o_dau_bang;
char mx[10][10];
int w = 8;
int h = 2;
int x = 53; int y = 15;
void Ve_Nut_Bam(int x, int y, int w, int h, string nd);
void n_box(int x, int y, int w, int h, int sl, vector<string> nd);
void Ve_Nut()
{
	Ve_Nut_Bam(x, y - 3, w + 27, h, "0");
	// cot thu 1
	vector<string> nd1;
	nd1.push_back("?");
	nd1.push_back("(");
	nd1.push_back("1");
	nd1.push_back("4");
	nd1.push_back("7");
	nd1.push_back("♫");
	n_box(x, y, w, h, 6, nd1);
	// cot thu 2
	vector<string> nd2;
	nd2.push_back("?");
	nd2.push_back(")");
	nd2.push_back("2");
	nd2.push_back("5");
	nd2.push_back("8");
	nd2.push_back("0");
	n_box(x + 9, y, w, h, 6, nd2);
	// cot thu 3
	vector<string> nd3;
	nd3.push_back("C");
	nd3.push_back("^");
	nd3.push_back("3");
	nd3.push_back("6");
	nd3.push_back("9");
	nd3.push_back("?");
	n_box(x + 18, y, w, h, 6, nd3);
	// cot thu 4
	vector<string> nd4;
	nd4.push_back("B");
	nd4.push_back("/");
	nd4.push_back("*");
	nd4.push_back("-");
	nd4.push_back("+");
	nd4.push_back("=");
	n_box(x + 27, y, w, h, 6, nd4);
}
void KhoiTaoMaTran(char mx[10][10])
{
	mx[0][0] = '?';
	mx[0][1] = '?';
	mx[0][2] = 'C';
	mx[0][3] = 'B';
	mx[1][0] = '(';
	mx[1][1] = ')';
	mx[1][2] = '^';
	mx[1][3] = '/';
	mx[2][0] = '1';
	mx[2][1] = '2';
	mx[2][2] = '3';
	mx[2][3] = '*';
	mx[3][0] = '4';
	mx[3][1] = '5';
	mx[3][2] = '6';
	mx[3][3] = '-';
	mx[4][0] = '7';
	mx[4][1] = '8';
	mx[4][2] = '9';
	mx[4][3] = '+';
	mx[5][0] = char(14);
	mx[5][1] = '0';
	mx[5][2] = '?';
	mx[5][3] = '=';
}
void test_1()
{
	string s;
	char key_press;
	int ascii_value;
	cout << "\n\t\tNhap phim bat ky de kiem tra ma ASCII\n\t\t\An ESC de thoat\n\n\n";
	while (1)
	{
		key_press = _getch();
		ascii_value = key_press;
		if (ascii_value == 27) // For ESC
			break;
		if ((ascii_value >= 48 && ascii_value <= 57) || ascii_value == 43 || ascii_value == 45 || ascii_value == 47 || ascii_value == 42 || ascii_value == 94 || ascii_value == 40 || ascii_value == 41 || ascii_value == 46)
		{
			cout << "Ban nhap phim-> \" " << key_press << " \" Gia tri ASCII =  " << ascii_value << "\n";
			s.push_back(key_press);
		}
		if (ascii_value == 13)
		{
			// đưa dữ liêu vào bộ xử lí tính toán
			// trước khi cout thì đưa qua hàm check_xu_li_dau để chuẩn hoá dữ liệu
			cout << s;
			s.clear();
		}
	}
}
// nút bấm (
void Ve_Nut_Bam(int x, int y, int w, int h,string nd)
{
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x + 4, y + 1);
	cout << nd;
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);

}
void n_box(int x, int y, int w, int h,  int sl,vector<string> nd)
{
	for (int i = 0; i < sl; i++)
	{
		Ve_Nut_Bam(x, y + (i * 2), w, h,nd[i]);//i = 0 => x,y, i = 1: x,y+2
		if (i != 0)
		{
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}
int main()
{
	Nocursortype();
	string s; // kết quả tính
	//test
	KhoiTaoMaTran(mx);
	Ve_Nut();
	int i = 0, j = 0; // toạ độ của nút bấm trong ma trận
	int yp = 15;
	int xp = 53;
	gotoXY(xp + 4, yp + 1);
	SetColor(2);
	cout << mx[i][j];
	while (true)
	{
		int xcu = xp;
		int ycu = yp;
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				// lên
				if (c == 72)
				{
					if (i != 0)
					{
						gotoXY(xcu + 4, ycu + 1);
						SetColor(7);
						cout << mx[i][j];
						yp -= 2;
						i--;
						gotoXY(xp + 4, yp + 1);
						SetColor(2);
						cout << mx[i][j];
					}
				}
				// xuống
				if (c == 80)
				{
					if (i != 5)
					{
						gotoXY(xcu + 4, ycu + 1);
						SetColor(7);
						cout << mx[i][j];
						yp += 2;
						i++;
						if (mx[i][j] == 'ANS')
						{
							gotoXY(xp, yp + 1);
							cout << "   ";
						}
						gotoXY(xp + 4, yp + 1);
						SetColor(2);
						cout << mx[i][j];
					}	
				}
				// sang phải
				else if (c == 77)
				{
					if (j != 3)
					{
						gotoXY(xcu + 4, ycu + 1);
						SetColor(7);
						cout << mx[i][j];
						xp += 9;
						j++;
						gotoXY(xp + 4, yp + 1);
						SetColor(2);
						cout << mx[i][j];
					}	
				}
				// sang trái
				else if (c == 75)
				{
					if (j != 0)
					{
						gotoXY(xcu + 4, ycu + 1);
						SetColor(7);
						cout << mx[i][j];
						xp -= 9;
						j--;
						gotoXY(xp + 4, yp + 1);
						SetColor(2);
						cout << mx[i][j];
					}	
				}
			}
			//enter
			if (c == 13)
			{
				mx_dang_o_dau_bang = 0;
				if (mx[i][j] == '1')
				{
					s.push_back('1');
				}
				else if(mx[i][j] == '2')
				{
					s.push_back('2');
				}
				else if(mx[i][j] == '3')
				{
					s.push_back('3');
				}
				else if (mx[i][j] == '4')
				{
					s.push_back('4');
				}
				else if (mx[i][j] == '5')
				{
					s.push_back('5');
				}
				else if (mx[i][j] == '6')
				{
					s.push_back('6');
				}
				else if (mx[i][j] == '7')
				{
					s.push_back('7');
				}
				else if (mx[i][j] == '8')
				{
					s.push_back('8');
				}
				else if (mx[i][j] == '9')
				{
					s.push_back('9');
				}
				else if (mx[i][j] == '0')
				{
					s.push_back('0');
				}
				else if (mx[i][j] == '+')
				{
					s.push_back('+');
				}
				else if (mx[i][j] == '-')
				{
					s.push_back('-');
				}
				else if (mx[i][j] == '*')
				{
					s.push_back('*');
				}
				else if (mx[i][j] == '/')
				{
					s.push_back('/');
				}
				else if (mx[i][j] == '^')
				{
					s.push_back('^');
				}
				else if (mx[i][j] == '(')
				{
					s.push_back('(');
				}
				else if (mx[i][j] == ')')
				{
					s.push_back(')');
				}
				else if (mx[i][j] == 'C')
				{
					if (!s.empty())
					{
						s.clear();
					}
				}
				else if (mx[i][j] == 'B')
				{
					
					if (!s.empty())
					{
						s.pop_back();
					}
				}
				else if (mx[i][j] == '=')
				{
					tinh_toan_lan++;
					gotoXY(x + 1, y - 2);
					cout << "                  ";
					check_xu_li_dau(s);
					gotoXY(x, y - 1);
					
					
					if (tinh_toan_lan == 1)
					{
						gotoXY(x + 2, y - 2);
						SetColor(13);
						cout << s << " = ";
					}
					else
					{
						gotoXY(x + 2, y - 2);
						SetColor(13);
						cout << kq_cu << " " << s << " = ";
					}
					float kq = tinh_bt_hau_to(s);
					SetColor(13);
					cout << kq;
					kq_cu = kq;
					mx_dang_o_dau_bang = 1;
					s.clear();
				}
				if (mx_dang_o_dau_bang == 0)
				{
					// xoá dữ liệu cũ trước đó
					gotoXY(x + 1, y - 2);
					cout << "                  ";
					if (!st.empty())
					{
						SetColor(13);
						gotoXY(x + 2, y - 2);
						cout << st.top();
						cout << s;
					}
					else
					{
						gotoXY(x + 2, y - 2);
						SetColor(13);
						cout << s;
					}	
				}		
	
			}
		}
	}
	_getch();
	return 0;
}
