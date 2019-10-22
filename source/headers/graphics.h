#ifndef graphics_h
#define graphics_h

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
private:
	SDL_Window* _window;
	SDL_Renderer* _render;
};

#endif /* graphics_h */
