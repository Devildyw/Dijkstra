#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
typedef struct zb{
	int x, y,r;
	//char* name;
}zb;


//路径
typedef struct path{
	int k=0,path[9];
}Ph;

#define MAX_INT 10000
void paint(zb[]);
void initplace(zb zb[]);
void paintline(zb zb[]);
void initGraph(int graph[][9]);
void Dijkstra(int matrix[][9], int start,zb zb[]);
void ptline(zb zb[], int start, int end);
void initweight(int graph[][9], zb zb[]);
int Graph[9][9];

int main() {
	zb zb[9];
	initGraph(Graph);
	initplace(zb);
	paint(zb);
	return 0;
}

void paint(zb a[]) {
	//设置窗口标题
	int i;
	initgraph(1000, 710, 1);
	setbkcolor(WHITE);
	HWND hnd = GetHWnd();
	SetWindowText(hnd, L"单源最短路的查找");
	cleardevice();
	
	
	cleardevice();//2.清屏
	IMAGE image;
	loadimage(&image, L"E:\\tu1.jpg", 1000, 700);
	putimage(0, 0, &image);
	setlinecolor(YELLOW);//设置线条颜色
	setlinestyle(PS_SOLID, 1);//设置线条样式
	setfillcolor(CYAN);//设置填充颜色
	for (i = 0; i < 9; i++) {
		fillcircle(a[i].x, a[i].y, a[i].r);
		settextcolor(YELLOW);
		settextstyle(30, 0, L"宋体");
		setbkmode(TRANSPARENT);//透明
		char c = '0' + i;
		outtextxy(a[i].x-8, a[i].y-12, c);
	}
	setlinecolor(DARKGRAY);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 15);
	line(0,700,1000,700);
	initweight(Graph, a);
	settextcolor(GREEN);
	settextstyle(0, 0, L"宋体");
	paintline(a);
	wchar_t s[10];
	InputBox(s, 10, L"请输入起点");
	int x = _wtoi(s);
	Dijkstra(Graph, x,a);
	system("pause");
	closegraph();
	
}

void initplace(zb zb[]) {
	zb[6].x = 50, zb[6].y = 50, zb[6].r = 30;
	zb[7].x = 275, zb[7].y = 50, zb[7].r = 30;
	zb[5].x = 475, zb[5].y = 150, zb[5].r = 30;
	zb[8].x = 900, zb[8].y = 100, zb[8].r = 30;
	zb[3].x = 900, zb[3].y = 600, zb[3].r = 30;
	zb[0].x = 475, zb[0].y = 600, zb[0].r = 30;
	zb[4].x = 50, zb[4].y = 600, zb[4].r = 30;
	zb[1].x = 275, zb[1].y = 350, zb[1].r = 30;
	zb[2].x = 675, zb[2].y = 350, zb[2].r = 30;
}

void paintline(zb zb[]) {
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 8);
	line(880,580,695,370);
	line(495,580,655,370);
	line(455,170,295,330);
	line(880,120,695,330);
	line(495,170,655,330);
	line(305,350,645,350);
	line(475,180,475,570);
	line(455,580,295,370);
	line(275, 80, 275, 330);
	line(70,70,255,330);
	line(70,580,255,370);
	line(50, 80, 50, 570);
	line(445,600,80,600); 
	line(870,600,505,600);
	line(900,130,900,570);
	line(505, 130, 880, 120);
	line(80,50,245,50);
	line(295, 70, 455, 130);
}

void initGraph(int graph[][9]) {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			graph[i][j] = MAX_INT;
		}
	}
	graph[8][2] = 300;
	graph[8][3] = 600;
	graph[8][5] = 700;
	
	graph[7][1] = 200;
	graph[7][5] = 200;
	graph[7][6] = 100;
	
	graph[6][1] = 300;
	graph[6][4] = 400;
	graph[6][7] = 100;
	
	graph[5][0] = 600;
	graph[5][1] = 250;
	graph[5][2] = 250;
	graph[5][7] = 200;
	graph[5][8] = 600;
	
	graph[4][0] = 400;
	graph[4][1] = 300;
	graph[4][6] = 400;
	
	graph[3][0] = 400;
	graph[3][2] = 300;
	graph[3][8] = 700;
	
	graph[2][0] = 300;
	graph[2][1] = 200;
	graph[2][3] = 300;
	graph[2][5] = 250;
	graph[2][8] = 300;
	
	graph[1][0] = 300;
	graph[1][2] = 200;
	graph[1][4] = 300;
	graph[1][5] = 200;
	graph[1][6] = 300;
	graph[1][7] = 200;
	
	graph[0][1] = 300;
	graph[0][2] = 300;
	graph[0][3] = 400;
	graph[0][4] = 400;
	graph[0][5] = 600;


}

void initweight(int graph[][9],zb zb[]) {
	settextcolor(BROWN);
	settextstyle(30, 0, L"楷体");
	setbkmode(TRANSPARENT);
	outtextxy(150,20,L"100");
	outtextxy(350,65,L"200");
	outtextxy(700,95,L"600");
	outtextxy(65,325,L"400");
	outtextxy(175,180,L"300");
	outtextxy(280,200,L"200");
	outtextxy(375,180,L"600");
	outtextxy(550, 200, L"250");
	outtextxy(750, 200, L"300");
	outtextxy(150, 400, L"300");
	outtextxy(350, 320, L"200");
	outtextxy(350, 400, L"300");
	outtextxy(495, 300, L"600");
	outtextxy(535, 425, L"300");
	outtextxy(780, 425, L"300");
	outtextxy(910, 350, L"700");
	outtextxy(275, 570, L"400");
}

void Dijkstra(int matrix[][9],int start,zb zb[]) {
	setfillcolor(RED);
	fillcircle(zb[start].x, zb[start].y, zb[start].r);
	outtextxy(zb[start].x-8, zb[start].y-10,(char)(start+'0'));
	int i, j;
	//初始化数组
	int shortest[9];
	//判断该点的最短路径是否求出 0标识未求出 1表示求出
	int visited[9];
	//存储输出路径 最短路径
	Ph path[9];
	//初始化输出路径
	for (int i = 0; i < 9; i++) {
		path[i].path[path[i].k++] = start;
		path[i].path[path[i].k++] = i;
		/*if (matrix[start][i] < MAX_INT) {
			Sleep(500);
			ptline(zb, start, i);
		}*/
		visited[i] = 0;
	}
	
	//初始化源节点
	//规定原节点到它本身的距离为0 并设置为已找到源节点到达该节点的最短路径
	shortest[start] = 0;
	visited[start] = 1;

	for (int i = 1; i < 9; i++) {
		//设置一个较大的数
		int min = 33333;
		int index = -1;

		for (int j = 0; j < 9; j++) {
			//visited[j] == 0表示只关系那些还没有找到最短路径的结点 通过此循环可以找到更新路径后的原节点能到达的最短路径的结点
			//即index对应的结点
			if (visited[j] == 0 && matrix[start][j] < min) {
				min = matrix[start][j];
				index = j;
			}
		}

		//更新最短路径结点
		shortest[index] = min;
		visited[index] = 1;

		//更新从index跳到其它节点的较短路径
		for (int m = 0; m < 9; m++) {
			if (visited[m] == 0 && matrix[start][index] + matrix[index][m] < matrix[start][m]) {
				matrix[start][m] = matrix[start][index] + matrix[index][m];
				path[m] = path[index];
				path[m].path[path[m].k++] = m;
			}
		}
	}
	//打印最短路径
	for (i = 0; i < 9; i++) {
		if (i != start) {
			if (shortest[i] == start) {
				printf("%d 到 %d 不可达 \n",start, i);
			}
			else {
				printf("%d 到 %d 的最短路径为： ",start,i);
				printf("%d->", start);
				for (j = 1; j < path[i].k; j++) {
					printf("%d",path[i].path[j]);
					Sleep(500);
					ptline(zb, path[i].path[j - 1], path[i].path[j]);
					if (j != path[i].k - 1) {
						printf("->");
					}
				}
				printf("  最短距离是：%d\n", shortest[i]);
			}
		}
	}
}

void ptline(zb zb[], int start, int end) {
	int x1 = zb[start].x, y1 = zb[start].y;
	int x2 = zb[end].x, y2 = zb[end].y;
	setlinecolor(RED);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	//x1 zai x2的左下角
	if (x1 < x2 && y1 < y2) {
		x1 = x1 + 20;
		y1 = y1 + 20;
		x2 = x2 - 20;
		y2 = y2 - 20;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
		
	}
	//x1 zai x2的左上角
	else if(x1<x2&&y1>y2) {
		x1 = x1 + 20;
		y1 = y1 - 20;
		x2 = x2 - 20;
		y2 = y2 + 20;
		int num = 10;
		double xlen = (x1 - x2)/num;
		double ylen = (y1 - y2)/num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
		
	}
	//x1 zai x2的右下角
	else if (x1 > x2 && y1 < y2) {
		x1 = x1 - 20;
		y1 = y1 + 20;
		x2 = x2 + 20;
		y2 = y2 - 20;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
	}
	//x1 zai x2的右上角
	else if (x1 > x2 && y1 > y2) {
		x1 = x1 - 20;
		y1 = y1 - 20;
		x2 = x2 + 20;
		y2 = y2 + 20;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
	}
	//x1 zai x2的正上方
	else if (x1 == x2 && y1 > y2) {
		//x1 = x1 + 20;
		y1 = y1 - 30;
		//x2 = x2 - 20;
		y2 = y2 + 30;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
	}
	//x1 zai x2的正下方
	else if (x1==x2&&y1<y2) {
		//x1 = x1 + 20;
		y1 = y1 + 30;
		//x2 = x2 - 20;
		y2 = y2 - 30;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
	}
	//x1 zai x2的正右方
	else if(x1>x2&&y1==y2) {
		x1 = x1 - 30;
		//y1 = y1 - 30;
		x2 = x2 + 30;
		//y2 = y2 + 30;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
	}
	//x1 zai x2的正左方
	else if (x1<x2&& y1==y2) {
		x1 = x1 + 30;
		//y1 = y1 - 30;
		x2 = x2 - 30;
		//y2 = y2 + 30;
		int num = 10;
		double xlen = (x1 - x2) / num;
		double ylen = (y1 - y2) / num;
		while (num--) {
			line(x1, y1, x1 - xlen, y1 - ylen);
			x1 = x1 - xlen;
			y1 = y1 - ylen;
			Sleep(10);
		}
	}
}