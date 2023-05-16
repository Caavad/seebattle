#include<iostream>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<Windows.h>

using namespace std;
enum controllers { LEFT = 0, RIGHT, UP, DOWN };
int main() {
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    int masiv[10][10];
    int iimasiv[10][10];
    int dlina;
    int shirina;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            masiv[i][j] = 0;
            iimasiv[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; i++) {
        dlina = _getch() - 48;
        shirina = _getch() - 48;
        masiv[dlina][shirina] = 1;
        system("cls");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (masiv[i][j] == 1) {
                    SetConsoleTextAttribute(h, 4);
                    cout << char(220) << ' ';
                }
                else {
                    SetConsoleTextAttribute(h, 7);
                    cout << char(220) << ' ';
                }
            }
            cout << '\n';
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (masiv[i][j] == 1) {
                if (masiv[i - 1][j] == 0) {
                    masiv[i - 1][j] = 2;
                }
                if (masiv[i + 1][j] == 0) {
                    masiv[i + 1][j] = 2;
                }
                if (masiv[i][j + 1] == 0) {
                    masiv[i][j + 1] = 2;
                }
                if (masiv[i][j - 1] == 0) {
                    masiv[i][j - 1] = 2;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        do {
            dlina = rand() % 10;
            shirina = rand() % 10;
        } while (iimasiv[dlina][shirina] != 0);
        iimasiv[dlina][shirina] = 1;
        for (int k = 0; k < 10; k++) {
            for (int q = 0; q < 10; q++) {
                if (iimasiv[k][q] == 1) {
                    if (iimasiv[k - 1][q] == 0) {
                        iimasiv[k - 1][q] = 2;
                    }
                    if (iimasiv[k + 1][q] == 0) {
                        iimasiv[k + 1][q] = 2;
                    }
                    if (iimasiv[k][q + 1] == 0) {
                        iimasiv[k][q + 1] = 2;
                    }
                    if (iimasiv[k][q - 1] == 0) {
                        iimasiv[k][q - 1] = 2;
                    }
                }
            }
        }
    }
    int direction;
    bool work = true;

    for (int i = 0; i < 2; i++) {
        do
        {
            do
            {
                dlina = rand() % 10;
                shirina = rand() % 10;
                if (iimasiv[dlina][shirina] == 0) {
                    break;
                }
            } while (true);
            work = true;
            direction = rand() % 4;
            switch (direction) {
            case LEFT:
                if (iimasiv[dlina][shirina + 1] == 0) {
                    if (iimasiv[dlina][shirina + 2] == 0) {
                        work = false;
                    }
                }
                break;
            case RIGHT:
                if (iimasiv[dlina][shirina - 1] == 0) {
                    if (iimasiv[dlina][shirina - 2] == 0) {
                        work = false;
                    }
                }
                break;
            case DOWN:
                if (iimasiv[dlina - 1][shirina] == 0) {
                    if (iimasiv[dlina - 2][shirina] == 0) {
                        work = false;

                    }
                }
                break;
            case UP:
                if (iimasiv[dlina + 1][shirina] == 0) {
                    if (iimasiv[dlina + 2][shirina] == 0) {
                        work = false;
                    }
                }
                break;
            }
        } while (work);
        for (int j = 0; j < 2; j++) {
            iimasiv[dlina][shirina] = 1;
            switch (direction) {
            case LEFT:
                iimasiv[dlina][shirina + 1] = 1;
                iimasiv[dlina][shirina + 2] = 1;
                break;
            case RIGHT:
                iimasiv[dlina][shirina - 1] = 1;
                iimasiv[dlina][shirina - 2] = 1;
                break;
            case DOWN:
                iimasiv[dlina - 1][shirina] = 1;
                iimasiv[dlina - 2][shirina] = 1;
                break;
            case UP:
                iimasiv[dlina + 1][shirina] = 1;
                iimasiv[dlina + 2][shirina] = 1;
                break;

            }
        }
        for (int k = 0; k < 10; k++) {
            for (int q = 0; q < 10; q++) {
                if (iimasiv[k][q] == 1) {
                    if (iimasiv[k - 1][q] == 0) {
                        iimasiv[k - 1][q] = 2;
                    }
                    if (iimasiv[k + 1][q] == 0) {
                        iimasiv[k + 1][q] = 2;
                    }
                    if (iimasiv[k][q + 1] == 0) {
                        iimasiv[k][q + 1] = 2;
                    }
                    if (iimasiv[k][q - 1] == 0) {
                        iimasiv[k][q - 1] = 2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {

        do
        {
            do
            {
                dlina = rand() % 10;
                shirina = rand() % 10;
                if (iimasiv[dlina][shirina] == 0) {
                    break;
                }
            } while (true);
            work = true;
            direction = rand() % 4;
            switch (direction) {
            case LEFT:
                if (iimasiv[dlina][shirina + 1] == 0) {
                    work = false;
                }
                break;
            case RIGHT:
                if (iimasiv[dlina][shirina - 1] == 0) {
                    work = false;
                }
                break;
            case DOWN:
                if (iimasiv[dlina - 1][shirina] == 0) {
                    work = false;
                }
                break;
            case UP:
                if (iimasiv[dlina + 1][shirina] == 0) {
                    work = false;
                }
                break;
            }
        } while (work);
        for (int j = 0; j < 1; j++) {
            iimasiv[dlina][shirina] = 1;
            switch (direction) {
            case LEFT:
                iimasiv[dlina][shirina + 1] = 1;
                break;
            case RIGHT:
                iimasiv[dlina][shirina - 1] = 1;
                break;
            case DOWN:
                iimasiv[dlina - 1][shirina] = 1;
                break;
            case UP:
                iimasiv[dlina + 1][shirina] = 1;
                break;

            }
        }
        for (int k = 0; k < 10; k++) {
            for (int q = 0; q < 10; q++) {
                if (iimasiv[k][q] == 1) {
                    if (iimasiv[k - 1][q] == 0) {
                        iimasiv[k - 1][q] = 2;
                    }
                    if (iimasiv[k + 1][q] == 0) {
                        iimasiv[k + 1][q] = 2;
                    }
                    if (iimasiv[k][q + 1] == 0) {
                        iimasiv[k][q + 1] = 2;
                    }
                    if (iimasiv[k][q - 1] == 0) {
                        iimasiv[k][q - 1] = 2;
                    }
                }
            }
        }
    }
    do
    {
        do
        {
            dlina = rand() % 10;
            shirina = rand() % 10;
            if (iimasiv[dlina][shirina] == 0) {
                break;
            }
        } while (true);
        work = true;
        direction = rand() % 4;
        switch (direction) {
        case LEFT:
            if (iimasiv[dlina][shirina + 1] == 0) {
                if (iimasiv[dlina][shirina + 2] == 0) {
                    if (iimasiv[dlina][shirina + 3] == 0) {
                        work = false;
                    }
                }
            }
            break;
        case RIGHT:
            if (iimasiv[dlina][shirina - 1] == 0) {
                if (iimasiv[dlina][shirina - 2] == 0) {
                    if (iimasiv[dlina][shirina - 3] == 0) {
                        work = false;
                    }
                }
            }
            break;
        case DOWN:
            if (iimasiv[dlina - 1][shirina] == 0) {
                if (iimasiv[dlina - 2][shirina] == 0) {
                    if (iimasiv[dlina - 3][shirina] == 0) {
                        work = false;
                    }
                }
            }
            break;
        case UP:
            if (iimasiv[dlina + 1][shirina] == 0) {
                if (iimasiv[dlina + 2][shirina] == 0) {
                    if (iimasiv[dlina + 3][shirina] == 0) {
                        work = false;
                    }
                }
            }
            break;
        }
    } while (work);
    iimasiv[dlina][shirina] = 1;
    switch (direction)
    {
    case LEFT:
        iimasiv[dlina][shirina + 1] = 1;
        iimasiv[dlina][shirina + 2] = 1;
        iimasiv[dlina][shirina + 3] = 1;
        break;
    case RIGHT:
        iimasiv[dlina][shirina - 1] = 1;
        iimasiv[dlina][shirina - 2] = 1;
        iimasiv[dlina][shirina - 3] = 1;
        break;
    case DOWN:
        iimasiv[dlina + 1][shirina] = 1;
        iimasiv[dlina + 2][shirina] = 1;
        iimasiv[dlina + 3][shirina] = 1;
        break;
    case UP:
        iimasiv[dlina - 1][shirina] = 1;
        iimasiv[dlina - 2][shirina] = 1;
        iimasiv[dlina - 3][shirina] = 1;
        break;
    }

    int floodedmy = 20;
    int floodedii = 20;
    int a = 0;
    int backdlina;
    int q = 0;
    int backshirina;
    system("cls");
    do
    {
        do
        {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (iimasiv[i][j] == 4) {
                        SetConsoleTextAttribute(h, 4);
                        cout << char(220) << ' ';
                    }
                    else {
                        if (iimasiv[i][j] == 5) {
                            SetConsoleTextAttribute(h, 1);
                            cout << char(220) << ' ';
                        }
                        else {
                            if (iimasiv[i][j] == 3) {
                                SetConsoleTextAttribute(h, 2);
                                cout << char(220) << ' ';
                            }
                            else {
                                SetConsoleTextAttribute(h, 7);
                                cout << char(220) << ' ';
                            }

                        }
                    }
                }
                cout << '\n';
            }
            dlina = _getch() - 48;
            shirina = _getch() - 48;
            system("cls");
            if (iimasiv[dlina][shirina] == 1) {
                cout << 'y' << '\n';
                iimasiv[dlina][shirina] = 4;
                floodedii--;
            }
            else {
                cout << 'n' << '\n';
                iimasiv[dlina][shirina] = 3;
                break;
            }
            if (iimasiv[dlina + 1][shirina] != 1 && iimasiv[dlina - 1][shirina] != 1 && iimasiv[dlina][shirina + 1] != 1 && iimasiv[dlina][shirina - 1] != 1) {
                iimasiv[dlina + 1][shirina] = 5;
                iimasiv[dlina - 1][shirina] = 5;
                iimasiv[dlina][shirina - 1] = 5;
                iimasiv[dlina][shirina + 1] = 5;
                iimasiv[dlina - 1][shirina - 1] = 5;
                iimasiv[dlina + 1][shirina + 1] = 5;
                iimasiv[dlina - 1][shirina + 1] = 5;
                iimasiv[dlina + 1][shirina - 1] = 5;
            }
        } while (true);
        do
        {
            system("cls");
            if (a == 0) {
                do
                {
                    dlina = rand() % 10;
                    shirina = rand() % 10;
                } while (masiv[dlina][shirina] == 4 && masiv[dlina][shirina] == 5);
            }
            switch (a - 1) {
            case LEFT:
                backdlina = dlina;
                backshirina = shirina;
                if (shirina != 0) {
                    shirina--;
                    break;
                }
                else {
                    a++;
                }
            case RIGHT:
                if (shirina != 9) {
                    dlina = backdlina;
                    shirina = backshirina;
                    shirina++;
                    break;
                }
                else {
                    a++;
                }
            case DOWN:
                if (dlina != 9) {
                    dlina = backdlina;
                    shirina = backshirina;
                    dlina++;
                    break;
                }
            case UP:
                if (dlina != 0) {
                    dlina = backdlina;
                    shirina = backshirina;
                    dlina--;
                    break;
                }
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (masiv[i][j] == 4) {
                        SetConsoleTextAttribute(h, 4);
                        cout << char(220) << ' ';
                    }
                    else {
                        if (masiv[i][j] == 5) {
                            SetConsoleTextAttribute(h, 1);
                            cout << char(220) << ' ';
                        }
                        else {
                            if (masiv[i][j] == 3) {
                                SetConsoleTextAttribute(h, 2);
                                cout << char(220) << ' ';
                            }
                            else {
                                SetConsoleTextAttribute(h, 7);
                                cout << char(220) << ' ';
                            }

                        }
                    }
                }
                cout << '\n';
            }
            cout << "\n\n";
            if (masiv[dlina][shirina] == 1) {
                masiv[dlina][shirina] = 4;
                if (a == 0) {
                    a++;
                }
                floodedmy--;
                if (masiv[dlina + 1][shirina] != 1 && masiv[dlina - 1][shirina] != 1 && masiv[dlina][shirina + 1] != 1 && masiv[dlina][shirina - 1] != 1) {
                    masiv[dlina + 1][shirina] = 5;
                    masiv[dlina - 1][shirina] = 5;
                    masiv[dlina][shirina - 1] = 5;
                    masiv[dlina][shirina + 1] = 5;
                    masiv[dlina - 1][shirina - 1] = 5;
                    masiv[dlina + 1][shirina + 1] = 5;
                    masiv[dlina - 1][shirina + 1] = 5;
                    masiv[dlina + 1][shirina - 1] = 5;
                    a = 0;
                }
            }
            else {
                masiv[dlina][shirina] = 3;
                a++;
                break;
            }
            cout << "\n\n\n";
        } while (true);
    } while (floodedmy != 0 || floodedii != 0);
}
