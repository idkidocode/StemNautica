#include <raylib.h>

class Player
{
public:
    Player(float x, float y, int rad, int speed);
    void Draw();
    void Update();
    void Init();
private:
    Vector2 pos;
    int Radius;

    int Speed;

    Image sprite;

    int animFrames = 0;

    int currentAnimFrame = 0;
    int frameDelay = 8;
    int frameCounter = 0;

    Texture2D texture = {0};

    bool facingRight = true;
};