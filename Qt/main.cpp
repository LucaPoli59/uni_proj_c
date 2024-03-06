#include "word_counter.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WordCounter w;

    w.show();

    return a.exec();
}
