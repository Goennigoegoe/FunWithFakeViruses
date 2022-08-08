#include <iostream>
#include <Windows.h>
 
#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920
 
HICON icons[] = {
	LoadIcon(NULL, IDI_ERROR),
	LoadIcon(NULL, IDI_WARNING),
	LoadIcon(NULL, IDI_INFORMATION),
	LoadIcon(NULL, IDI_QUESTION)
};
 
size_t s_icons = sizeof(icons);
 
void DrawIcons() {
	HWND hWnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hWnd);
 
	DrawIcon(hdc, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, icons[rand() % s_icons]);
 
	ReleaseDC(hWnd, hdc);
}

bool check = false;
bool enabled = false;
 
int main() {
 
	/*while (1) {
		DrawIcons();
	}*/

    if(MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Are You Sure\nThat You Want To Run\nThis Software?\nIt Is Considered Malware And Can\nCause Your System To Crash.", "Carbon Dioxide", MB_YESNO | MB_ICONWARNING) == IDYES) {
        check = true;
    } else {
        return 0;
    }
    if(check == true) {
        if(MessageBox(NULL, "ARE YOU 100 PERCENT SURE YOU WANT TO RUN THIS PROGRAM\nIT IS CONSIDERED MALWARE\nAND CAN CAUSE YOUR SYSTEM TO CRASH.\n", "Carbon Dioxide", MB_YESNO | MB_ICONWARNING) == IDYES) {
            enabled = true;
        } else {
            return 0;
        }
    }

    MessageBox(NULL, "You Can Press F1 To Stop The Virus", "Carbon Dioxide", MB_OK | MB_ICONINFORMATION);

    while (1) {
        if(GetAsyncKeyState(VK_F1)) {
            enabled = false;
            return 0;
        }
        if(enabled == true && check == true) {
            DrawIcons();
            Sleep(250);
        }
    }
	return 0;
}