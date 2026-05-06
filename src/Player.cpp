#include "raylib.h"
#include "Include/Player.hpp"

Player::Player(float x, float y, int rad, int speed) 
{
    pos = Vector2{x, y};
    Radius = rad;
    Speed = speed;
}

void Player::Init()
{
    sprite = LoadImageAnim("Assets/Images/Dave.gif", &animFrames);
    texture = LoadTextureFromImage(sprite);
}

void Player::Draw() 
{
    Rectangle source = { 0, 0, (float)texture.width, (float)texture.height };
    Rectangle dest = { pos.x, pos.y, (float)texture.width, (float)texture.height };
    Vector2 origin = { 0, 0 };

    if (!facingRight) source.width = -(float)texture.width;

    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}

void Player::Update()
{
    if (IsKeyDown(KEY_W)) pos.y -= Speed;
    if (IsKeyDown(KEY_S)) pos.y += Speed;
    if (IsKeyDown(KEY_A)) { pos.x -= Speed; facingRight = false; }
    if (IsKeyDown(KEY_D)) { pos.x += Speed; facingRight = true; }

    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D))
    {
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames) currentAnimFrame = 0;
            frameCounter = 0;

            UpdateTexture(texture, (unsigned char*)sprite.data + 
                currentAnimFrame * sprite.width * sprite.height * 4);
        }
    }
}