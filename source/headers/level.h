//
//  level.h
//  cavestory_demo
//
//  Created by Christian Jarani on 10/23/19.
//  Copyright © 2019 majula. All rights reserved.
//

#ifndef level_h
#define level_h

#include <string>

#include "globals.h"

class Graphics;
struct SDL_Texture;

class Level {
public:
	Level();
	Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);
	~Level();
	void update(int elapsedTime);
	void draw (Graphics &graphics);
	
private:
	std::string _mapName;
	Vector2 _spawnPoint;
	Vector2 _size;
	SDL_Texture* _backgroundTexture;
	
	/* void loadMap
	 * Loads a map
	 */
	void loadMap(std::string mapName, Graphics &graphics);
};


#endif /* level_h */
