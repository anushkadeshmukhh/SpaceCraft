#include <iostream>
#include <vector>

using namespace std;

class Spacecraft
{
private:
    int x, y, z;    // Galactic coordinates (x for east/west, y for north/south, z for above/below)
    char direction; // N, S, E, W, U, D

public:
    Spacecraft(int startX, int startY, int startZ, char startDirection)
    {
        x = startX;
        y = startY;
        z = startZ;
        direction = startDirection;
    }

    void move(char command)
    {
        switch (command)
        {
        case 'f':
            moveForward();
            break;
        case 'b':
            moveBackward();
            break;
        case 'l':
            turnLeft();
            break;
        case 'r':
            turnRight();
            break;
        case 'u':
            turnUp();
            break;
        case 'd':
            turnDown();
            break;
        default:
            cout << "Invalid command: " << command << endl;
            break;
        }
    }

    void moveForward()
    {
        switch (direction)
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        case 'U':
            z++;
            break;
        case 'D':
            z--;
            break;
        }
    }

    void moveBackward()
    {
        switch (direction)
        {
        case 'N':
            y--;
            break;
        case 'S':
            y++;
            break;
        case 'E':
            x--;
            break;
        case 'W':
            x++;
            break;
        case 'U':
            z--;
            break;
        case 'D':
            z++;
            break;
        }
    }

    void turnLeft()
    {
        switch (direction)
        {
        case 'N':
            direction = 'W';
            break;
        case 'S':
            direction = 'E';
            break;
        case 'E':
            direction = 'N';
            break;
        case 'W':
            direction = 'S';
            break;
        default:
            cout << "Invalid command: " << 'l' << endl;
            break;
        }
    }

    void turnRight()
    {
        switch (direction)
        {
        case 'N':
            direction = 'E';
            break;
        case 'S':
            direction = 'W';
            break;
        case 'E':
            direction = 'S';
            break;
        case 'W':
            direction = 'N';
            break;
        default:
            cout << "Invalid command: " << 'r' << endl;
            break;
        }
    }

    void turnUp()
    {
        if (direction != 'U')
        {
            direction = 'U';
        }
    }

    void turnDown()
    {
        if (direction != 'D')
        {
            direction = 'D';
        }
    }

    void printPositionAndDirection()
    {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Final Direction: " << direction << endl;
    }
};

int main()
{
    int startX = 0, startY = 0, startZ = 0;
    char startDirection = 'N';
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    Spacecraft chandrayaan(startX, startY, startZ, startDirection);

    for (char command : commands)
    {
        chandrayaan.move(command);
    }

    chandrayaan.printPositionAndDirection();

    return 0;
}
