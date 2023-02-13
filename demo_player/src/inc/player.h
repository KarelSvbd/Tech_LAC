typedef struct Player_s {
    int x;
    int y;
    int width;
    int height;
    int color;
    int windowWidth;
    int windowHeight;
    int upDirection;
    int downDirection;
    int leftDirection;
    int rightDirection;
    float moveSpeedPxPerS; 

    void (*ProcessInput)(struct Player_s *p, SDL_Event pEvent);
    void (*Update)(struct Player_s *p, float deltaTime);
    void (*Render)(struct Player_s *p, SDL_Renderer *renderer);
    void (*Free)(struct Player_s *p);
} Player;

Player* new_Player(int x, int y, int pWindowWidth, int pWindowHeight);