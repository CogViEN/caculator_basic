#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<queue>
#include<cmath>


stack<float> st;
int solan = 0;
string copy_xu_li_dau;

void check_xu_li_dau(string &s)
{
	// đã thực hiện tính toán trên 1 lần và chỉ được nhập dữ liệu 1 lần
	if (!st.empty() && s.empty())
	{
		s = copy_xu_li_dau;
		return;
	}
	// sao chép dữ liệu cũ sau mỗi lần nhập
	if (!st.empty() && !s.empty())
	{
		int dem_toan_tu = 0;
		int vt_toan_tu;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
			{
				dem_toan_tu++;
				vt_toan_tu = i;
			}
		}
		if (dem_toan_tu == 1)
		{
			string cpy = s;
			copy_xu_li_dau = cpy.substr(vt_toan_tu);
		}
	}
	// chưa tính toán lần nào
	if (st.empty() && (s[s.length() - 1] == '+' || s[s.length() - 1] == '-' || s[s.length() - 1] == '*' || s[s.length() - 1] == '/'))
	{
		copy_xu_li_dau = s;
		string cpy = s;
		string temp = cpy.substr(0, cpy.length() - 1);
		s.insert(s.length(), temp);
	}
	// chưa tính toán lần nào
	if (st.empty() && s[s.length() - 1] != '+' && s[s.length() - 1] != '-' && s[s.length() - 1] != '*' && s[s.length() - 1] != '/' && s[s.length() - 1] != '^')
	{
		int dem_toan_tu = 0;
		int vt_toan_tu;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
			{
				dem_toan_tu++;
				vt_toan_tu = i;
			}
		}
		if (dem_toan_tu == 1)
		{
			string cpy = s;
			copy_xu_li_dau = cpy.substr(vt_toan_tu);
		}
	}
}
int Do_uu_tien_toan_tu(string a, string b)
{
	int do_uu_tien_a;
	int do_uu_tien_b;
	if (a == "^")
	{
		do_uu_tien_a = 3;
	}
	if (b == "^")
	{
		do_uu_tien_b = 3;
	}
	if (a == "*" || a == "/" || a == "%")
	{
		do_uu_tien_a = 2;
	}
	if (b == "*" || b == "/" || b == "%")
	{
		do_uu_tien_b = 2;
	}
	if (a == "+" || a == "-")
	{
		do_uu_tien_a = 1;
	}
	if (b == "+" || b == "-")
	{
		do_uu_tien_b = 1;
	}
	// so sanh toan tu
	if (do_uu_tien_a == do_uu_tien_b || do_uu_tien_a < do_uu_tien_b)
	{
		return -1;
	}
	else if (do_uu_tien_a > do_uu_tien_b)
	{
		return 1;
	}
}
int Chuyen_Chuoi_Thanh_So_Nguyen(string s)
{
	int x = 0;
	int mu = 0;
	int len = s.length();
	if (s.at(0) == '-')
	{
		for (int i = len - 1; i > 0; i--)
		{
			x = x + (s[i] - 48) * pow(10, mu);
			mu++;
		}
		return -x;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		x = x + (s[i] - 48) * pow(10, mu);
		mu++;
	}
	return x;
}
void Quy_Uoc_Ki_Phap_Nghich_Dao_Ba_Lan(string s, queue<string> &q)
{
	stack<string> st;
	int dem_toan_hang = 0;
	int vt_toan_hang_ban_dau; // gi? v? trí toán h?ng lúc ban d?u
	for (int i = 0; i < s.length(); i++)
	{
		// dau - dat o dau chuoi
		if (s[i] == '-' && i == 0 && solan == 0)
		{
			vt_toan_hang_ban_dau = i;
			dem_toan_hang++;
			i++;
		}
		if (s[i] == '-' && i == 0 && solan != 0)
		{
			string cpy = s;
			st.push(cpy.substr(i, 1));
			i++;
		}
		if (s[i] == '-' && s[i - 1] == '(' && i >= 1)
		{
			vt_toan_hang_ban_dau = i;
			dem_toan_hang++;
			i++;
		}
		// phan tu am
		if (s[i] == '-' &&  i >= 1  && (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '%' || s[i - 1] == '^'))
		{
			vt_toan_hang_ban_dau = i;
			dem_toan_hang++;
			i++;
		}
		if (s[i] >= 48 && s[i] <= 57 && dem_toan_hang == 0)
		{
			vt_toan_hang_ban_dau = i;
			dem_toan_hang++;
			// tru?ng h?p n?u ph?n t? cu?i là 1 s? don v?
			if (i + 1 == s.length())
			{
				string cpy = s;
				string temp = cpy.substr(vt_toan_hang_ban_dau, dem_toan_hang);
				q.push(temp);
				break;
			}
		}
		else if ((s[i] >= 48 && s[i] <= 57) && dem_toan_hang != 0 && vt_toan_hang_ban_dau != i)
		{
			dem_toan_hang++;
			// tru?ng h?p s? cu?i l?n hon s?  hàng don v?
			if (i + 1 == s.length())
			{
				string cpy = s;
				string temp = cpy.substr(vt_toan_hang_ban_dau, dem_toan_hang);
				q.push(temp);
				break;
			}
		}
		else if (!(s[i] >= 48 && s[i] <= 57))
		{
			if (dem_toan_hang != 0)
			{
				string cpy = s;
				string temp = cpy.substr(vt_toan_hang_ban_dau, dem_toan_hang);
				q.push(temp);
				
				dem_toan_hang = 0;
				vt_toan_hang_ban_dau = -9999;
			}
			// neu toan tu dang xet la phep tinh
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^')
			{
				// neu stack rong thi them vao stack
				if (st.empty())
				{
					string cpy = s;
					st.push(cpy.substr(i, 1));
				}
				// neu toan tu ngoai cung la ( thi them toan tu vao stack
				else if (st.top() == "(")
				{
					string cpy = s;
					st.push(cpy.substr(i, 1));
				}
				// neu toan tu ngoai cung stack la phep tinh
				else
				{
					string cpy = s;
					string toan_tu_xet = cpy.substr(i, 1);
					// neu toan tu dang xet ma lon hon toan tu ngoai cung stack
					if (Do_uu_tien_toan_tu(toan_tu_xet, st.top()) == 1)
					{
						st.push(toan_tu_xet);
					}
					// neu toan tu dang xet ma nho hon bang toan tu ngoai cung stack 
					else if (Do_uu_tien_toan_tu(toan_tu_xet, st.top()) != 1)
					{
						// them toan  tt ngoai cung stack vao queue 
						while (!st.empty())
						{
							// sau do quay lai kt dieu kien dung
							q.push(st.top());
							
							st.pop();
							if (st.empty())
							{
								break;
							}
							if (Do_uu_tien_toan_tu(toan_tu_xet, st.top()) == 1 || st.top() == "(")
							{
								break;
							}
						}
						st.push(toan_tu_xet);
					}
				}
			}
			// neu toan tu dang xet la 
			if (s[i] == '(')
			{
				string cpy = s;
				st.push(cpy.substr(i, 1));
			}
			if (s[i] == ')')
			{
				// vong lap dung neu gap dau (
				while (st.top() != "(")
				{
					q.push(st.top());
					
					st.pop();
				}
				// xoa dau (
				st.pop();
			}
		}
	}
	// neu het phan tu thi chuyen lan luot cac phan tu trong stack vao queue
	while (!st.empty())
	{
		q.push(st.top());
		st.pop();
	}
	/*while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}*/
}
void xuat(string s)
{
	if (solan == 0)
	{
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i];
		}
		cout << "\n= ";
	}
	else
	{
		cout << st.top() << s;
		cout << "\n= ";
	}
}
void tinh_bt_hau_to(queue<string> &q,string &s)
{
	Quy_Uoc_Ki_Phap_Nghich_Dao_Ba_Lan(s, q);
	while (!q.empty())
	{
		// bat gap toan hang
		if (q.front() != "+" && q.front() != "-" && q.front() != "*" && q.front() != "/" && q.front() != "%" && q.front() != "^" )
		{
			float temp = (float)Chuyen_Chuoi_Thanh_So_Nguyen(q.front());
			st.push(temp);
			q.pop();
		}
		// bat gap toan tu
		if(q.front() == "+" || q.front() == "-" || q.front() == "*" || q.front() == "/" || q.front() == "%" || q.front() == "^" )
		{
			// lấy ra toán hạng thứ nhất
			float a = st.top();
			st.pop(); // xoá đi toán hạng đó trong stack
			// lấy ra toán hạng thứ hai
			float b = st.top();
			st.pop(); // xoá đi toán hạng đó trong stack

			// xử lí toán tử
			if (q.front() == "+")
			{
				// đưa kết quả đã tính vào trong stack
				st.push(b + a);
			}
			else if (q.front() == "-")
			{
				st.push(b - a);
			}
			else if (q.front() == "*")
			{
				if (b == 0 || a == 0)
				{
					st.push(0);
				}
				else
				{
					st.push(b * a);
				}
			}
			else if (q.front() == "/")
			{
				if (a == 0)
				{
					st.push(b / a);
					cout << "Chuong trinh loi vui long resert lai chuong trinh" << endl;
				}
				else
				{
					st.push(b / a);
				}
			}
			else if (q.front() == "^")
			{
				st.push(pow(b,a));
			}
			q.pop();
		}
	}
	cout << st.top();
	solan++;
}
int main()
{
	while (true)
	{
		string s;
		getline(cin, s);
		check_xu_li_dau(s);
		xuat(s);
		queue<string> q;
		tinh_bt_hau_to(q, s);
	}
	/*string s;
	getline(cin, s);
	check_xu_li_dau(s);
	cout << s << endl;
	cout << copy_xu_li_dau;*/

	return 0;
}
