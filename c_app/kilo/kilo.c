#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
    // 現在のターミナルの状態を取得
    tcgetattr(STDIN_FILENO, &orig_termios);
    // プログラム終了時に呼ばれる関数を登録(以前のターミナル状態を戻す)
    atexit(disableRawMode);

    // Rawモードに設定
    struct termios raw = orig_termios;
    // ビットを反転させてAND演算で代入する
    raw.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
    enableRawMode();
    char c;
    // ファイルを1byteずつよむ
    while (read(STDERR_FILENO, &c, 1) == 1 && c != 'q')
        ;
    return 0;
}