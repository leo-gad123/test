#include <windows.h>
#include <string>

// Global handles to input fields
HWND hInput1, hInput2;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // First input
            CreateWindow("STATIC", "Number 1:", WS_VISIBLE | WS_CHILD,
                         20, 20, 80, 20, hwnd, NULL, NULL, NULL);
            hInput1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   100, 20, 100, 20, hwnd, NULL, NULL, NULL);

            // Second input
            CreateWindow("STATIC", "Number 2:", WS_VISIBLE | WS_CHILD,
                         20, 60, 80, 20, hwnd, NULL, NULL, NULL);
            hInput2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                   100, 60, 100, 20, hwnd, NULL, NULL, NULL);

            // Add button
            CreateWindow("BUTTON", "Add", WS_VISIBLE | WS_CHILD,
                         100, 100, 100, 30, hwnd, (HMENU)1, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == 1) { // Add button clicked
                char buf1[100], buf2[100];
                GetWindowText(hInput1, buf1, 100);
                GetWindowText(hInput2, buf2, 100);

                int num1 = atoi(buf1);
                int num2 = atoi(buf2);
                int sum = num1 + num2;

                std::string result = "Result: " + std::to_string(sum);
                MessageBox(hwnd, result.c_str(), "Sum", MB_OK);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {
    const char* CLASS_NAME = "CalcWindow";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(CLASS_NAME, "LeoGad Calculator", WS_OVERLAPPEDWINDOW,
                             100, 100, 300, 200, NULL, NULL, hInst, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
