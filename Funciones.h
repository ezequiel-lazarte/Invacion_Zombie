#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <map>
#include <string>

typedef sf::Texture texture;
typedef sf::SoundBuffer sound;
typedef sf::Font font;
typedef int key;

texture &getTexture_or_insert(std::map<key, texture> &M, texture &t, int &k) {
	if(M.find(k) == M.end()) M[k] = t;
	return M.find(k)->second;
}

sound &getBuffer_or_insert(std::map<key, sound> &M, sound &s, int &k) {
	if(M.find(k) == M.end()) M[k] = s;
	return M.find(k)->second;
}

font &getFont_or_insert(std::map<key, font> &M, font &f, int &k) {
	if(M.find(k) == M.end()) M[k] = f;
	return M.find(k)->second;
}

#endif
