typedef struct Ray_s {
    int x;
    int y;
    int width;
    int height;
    int color;
    int length;
    Player *player;

    void (*Update)(struct Ray_s *r, struct Player_s *p);
    void (*Render)(struct Ray_s *r, SDL_Renderer *renderer, Player *p);
    void (*Free)(struct Ray_s *r);
} Ray;

Ray* new_Ray(Player *player);