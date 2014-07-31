#include <glib.h>

G_BEGIN_DECLS

using namespace qqwing;
using namespace std;

class QQwingWrapper {
    public:
        QQwingWrapper();
        void generatePuzzle (SudokuBoard::Difficulty difficulty);
        void printStats ();
        void destroy ();

    private:
        SudokuBoard* board;
};

G_END_DECLS
