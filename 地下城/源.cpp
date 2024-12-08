#include <iostream>
#include <string>
#include <easyx.h>
#include <graphics.h>

using namespace std;

// 定义窗口大小
const double WIDTH = 1024.0;
const double HEIGHT = 683.0;

// 初始化图片素材元素
IMAGE loading_bk;
IMAGE bk;

// 文本相关常量
const char* START_GAME_TEXT = "开始游戏";
const char* GAME_NAME_TEXT = "至冬地下城";

// 颜色常量
const COLORREF BUTTON_COLOR_NORMAL = RGB(139, 129, 76);
const COLORREF BUTTON_COLOR_HOVER = RGB(255, 185, 15);

// 字体相关常量
const int TEXT_HEIGHT = 60;
const int TITLE_HEIGHT = 80;
const int TITLE_X_OFFSET = 300;

void setupGraphics() {
    initgraph((int)WIDTH, (int)HEIGHT);
    setbkmode(TRANSPARENT);
    loadimage(&loading_bk, "images/loading-bk.png", getwidth(), getheight());
    loadimage(&bk, "images/a.png", 170, 100);
}

void drawBackground() {
    cleardevice();
    putimage(0, 0, &loading_bk);
    putimage(100, 300, &bk, SRCAND);
}

void drawText(const char* text, double x, double y, COLORREF color) {
    settextcolor(color);
    settextstyle(TEXT_HEIGHT, 0, "华文行楷", 0, 0, 0, false, false, false);
    outtextxy(x, y, text);
}

void drawTitle() {
    settextcolor(RGB(82, 139, 139));
    settextstyle(TITLE_HEIGHT, 0, "宋体", 0, 0, TITLE_X_OFFSET, false, false, false);
    outtextxy(WIDTH / 2 - textwidth(GAME_NAME_TEXT) / 2, 80, GAME_NAME_TEXT);
}

bool checkButtonHover(double mouseX, double mouseY) {
    return mouseX > WIDTH / 2 - textwidth(START_GAME_TEXT) / 2 &&
        mouseX < WIDTH / 2 + textwidth(START_GAME_TEXT) / 2 &&
        mouseY > 570.0 &&
        mouseY < 570.0 + textheight(START_GAME_TEXT);
}

int main() {
    setupGraphics();

    BeginBatchDraw();

    while (true) {
        MOUSEMSG msg = GetMouseMsg();

        if (msg.uMsg == WM_MOUSEMOVE || msg.uMsg == WM_LBUTTONDOWN || msg.uMsg == WM_LBUTTONUP) {
            bool isButtonHover = checkButtonHover(msg.x, msg.y);
            drawBackground();
            drawText(START_GAME_TEXT, WIDTH / 2 - textwidth(START_GAME_TEXT) / 2, 570, isButtonHover ? BUTTON_COLOR_HOVER : BUTTON_COLOR_NORMAL);
            drawTitle();
            FlushBatchDraw();
        }

        Sleep(15);
    }

    EndBatchDraw();
    return 0;
}